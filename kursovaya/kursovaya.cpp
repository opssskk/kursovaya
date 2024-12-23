#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <Windows.h>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <string>

using namespace std;
using namespace chrono;

//Лаба 1
int main_of_laba1() {
	setlocale(LC_ALL, "RU");
	//Задача 1
	{
		cout << "Программа выводит обьем памяти, отводящийся под различные типы данных\n";
		cout << "int " << (sizeof(int)) << " байта\n";
		cout << "short int " << (sizeof(short int)) << " байта\n";
		cout << "long int " << (sizeof(long long)) << " байт\n";
		cout << "float " << (sizeof(float)) << " байта\n";
		cout << "double " << (sizeof(double)) << " байт\n";
		cout << "long double " << (sizeof(long double)) << " байт\n";
		cout << "char " << (sizeof(char)) << " байт\n";
		cout << "bool " << (sizeof(bool)) << " байт\n";
	}
	cout << endl << endl << endl;

	//Задача 2
	{
		int integerNumber;
		unsigned int mask = 1 << (sizeof(int) * 8 - 1);

		cout << "Введите число типа integer: ";
		cin >> integerNumber;
		cout << "Двоичное представление введенного числа в памяти компьютера: ";
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';
			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << endl;
		//ИДЗ 2
		int shift;

		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а) ";

		integerNumber = integerNumber << shift;
		mask = 1 << (sizeof(int) * 8 - 1);
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';

			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << integerNumber;

		cout << endl << endl << endl;


	}
	cout << '\n';

	//Задача 3
	{
		union {
			int integerNumber;
			float floatNumber;
		};
		cout << "Введите число типа float: ";
		cin >> floatNumber;
		cout << "Двоичное представление введенного числа в памяти компьютера ";

		unsigned int mask = 1 << (sizeof(float) * 8 - 1);

		for (int i = 1; i < sizeof(float) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';
			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << endl;

		//ИДЗ 2
		int shift;

		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а) ";

		integerNumber = integerNumber << shift;

		mask = 1 << (sizeof(int) * 8 - 1);
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';

			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << floatNumber;
		cout << endl << endl << endl;

	}



	//Задача 4
	{
		union {
			double numberDouble;
			unsigned int splitDouble[2];

		};
		cout << "Введите число типа double: ";
		cin >> numberDouble;
		cout << "Двоичное представление введенного числа в памяти компьютера ";

		unsigned int mask = 1 << (sizeof(int) * 8 - 1);
		for (int n = 1; n >= 0; --n) {
			for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
				if (mask & splitDouble[n])
					cout << '1';
				else
					cout << '0';
				if (i == 1 || i % 8 == 0)
					cout << ' ';
			}
			mask = 1 << (sizeof(int) * 8 - 1);
		}
		cout << endl;

		//ИДЗ 2
		int shift;
		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а): ";

		for (int n = 1; n >= 0; --n) {
			splitDouble[n] = splitDouble[n] << shift;
			mask = 1 << (sizeof(int) * 8 - 1);
			for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
				if (mask & splitDouble[n])
					cout << '1';
				else
					cout << '0';

				if (i == 1 || i % 8 == 0)
					cout << ' ';
			}

		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << numberDouble;
	}

	return 0;
}

//Лаба 2
void generateArr(int arr[], const int size) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 199 - 99;
    }
}

void printArr(int arr[], const int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], const int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }

        }

}

void insertSort(int arr[], const int size) {
    int i, j, key;

    for (i = 0; i < size; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;
    }
}

void maxMinElement(int arr[], const int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];

    }
    cout << "Максимальный элемент: " << max << endl;
    cout << "Минимальный элемент: " << min << endl;

}

void midElement(int arr[], const int size) {
    int max = arr[0];
    int min = arr[0];
    int mid;
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    mid = (max + min) / 2;
    for (int i = 0; i < size; i++) {
        if (arr[i] == mid)
        {
            count++;

        }

    }
    cout << "\nСреднее значение: " << mid << "\nКолличество элементов равных " << mid << ": " << count;
}
// во время защиты поправка:
void f(int arr[], const int size)
{
    int mid;
    int count = 0;


    mid = (arr[0] + arr[size - 1]) / 2;
    for (int i = 0; arr[i] <= mid && i < size; i++) {
        if (arr[i] == mid)
        {
            count++;

        }

    }
    cout << "\nСреднее значение: " << mid << "\nКолличество элементов равных " << mid << ": " << count;
}



int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}

void searchInArray(int arr[], const int size, int value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
        {
            cout << "\nВпервые найден на позиции " << i;
            break;
        }

}

void IDZ9(int arr[], const int size, int value) {
    int divisibleCount[10] = { 0 };


    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {

            arr[i] -= value;

            arr[i] *= (rand() % 9) + 1;


        }
    }


    for (int i = 0; i < size; ++i) {
        for (int divisor = 1; divisor <= 9; ++divisor) {
            if (arr[i] % divisor == 0) {
                divisibleCount[divisor]++;
            }
        }
    }


    for (int divisor = 1; divisor <= 9; ++divisor) {
        cout << "Количество элементов, делящихся на " << divisor << ": " << divisibleCount[divisor] << endl;
    }
}



int main_of_laba2() {
    setlocale(LC_ALL, "RU");
    const int size = 100;
    int arr[size];
    bool isSort = false;
    generateArr(arr, size);
    int choice;

    cout << "Исходный массив" << endl;
    printArr(arr, size);

    while (true) {

        cout << "\nВыберете действие" << endl;
        cout << "[1] bubble Sort" << endl;
        cout << "[2] insert Sort" << endl;
        cout << "[3] max min element" << endl;
        cout << "[4] mid element" << endl;
        cout << "[5] element > a and element < b" << endl;
        cout << "[6] бинарный поиск" << endl;
        cout << "[7] линейный поиск" << endl;
        cout << "[8] идз 9" << endl;
        cout << "[0] Завершить работу программы" << endl;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        switch (choice) {
        case 1:
        {
            auto start = high_resolution_clock::now();
            bubbleSort(arr, size);
            auto stop = high_resolution_clock::now();

            cout << "Массив после сортировки:\n";
            printArr(arr, size);

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
            isSort = true;
            break;


        }
        case 2:
        {
            auto start = high_resolution_clock::now();
            insertSort(arr, size);
            auto stop = high_resolution_clock::now();

            cout << "Массив после сортировки:\n";
            printArr(arr, size);

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
            isSort = true;
            break;
        }
        case 3:
        {
            auto start = high_resolution_clock::now();
            maxMinElement(arr, size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя поиска максимума и минимума: " << duration.count() << " нс\n";
            break;
        }
        case 4:
        {
            auto start = high_resolution_clock::now();
            midElement(arr, size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя: " << duration.count() << " нс\n";
            break;
        }
        case 5:
        {
            if (isSort)
            {
                int k = 0, a = 0, i = 0, b = 0;
                cout << "\nВведите число a\n";
                cin >> a;
                while (arr[i] < a)
                {
                    k++;
                    i++;
                }
                cout << "Количество элементов меньше a: " << k;
                i = size - 1;
                k = 0;
                cout << "\nВведите число b\n";
                cin >> b;
                while (arr[i] > b)
                {
                    k++;
                    i--;
                }
                cout << "Количество элементов больше b: " << k;
            }
            else
                cout << "\nОтсортируйте массив";
            break;
        }
        case 6:
        {
            int result, y;
            cout << "\nВведите число: ";
            cin >> y;
            auto start = high_resolution_clock::now();
            result = binarySearch(arr, y, 0, size - 1);
            if (result == -1) {
                cout << "\nЭлемент не найден" << endl;
            }
            else {
                cout << "\nЭлемент находится в позиции " << result << endl;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя бинарного поиска: " << duration.count() << " нс\n";
            break;
        }
        case 7:
        {
            int o;
            cout << "\nВведите число: ";
            cin >> o;
            auto start = high_resolution_clock::now();
            searchInArray(arr, size, o);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя обычного поиска: " << duration.count() << " нс\n";
            break;
        }
        case 8:
        {
            int value;
            std::cout << "Введите значение для уменьшения нечетных элементов: ";
            std::cin >> value;


            IDZ9(arr, size, value);
            cout << endl;
            printArr(arr, size);


        }
        }
    }

    return 0;
}

//Лаба 3
void generateMatrix(int* matrix, int size)
{

    for (int i = 0; i < size * size; i++)
    {
        matrix[i] = (rand() % (size * size) + 1);
    }
}

void setCursorPosition(HANDLE hStdout, int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdout, coord);
}


void printMatrix(int* matrix, int size)
{
    int* end = matrix + size * size - 1;

    for (int* ptr = matrix; ptr <= end; ptr++)
    {
        cout << setw(4) << *ptr;
        if ((ptr - matrix + 1) % size == 0)
            cout << '\n';
    }
}

void printMatrixZmeya(int size)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int* matrix = new int[size * size];
    generateMatrix(matrix, size);

    setCursorPosition(hStdout, 0, 0);

    int value = 0;

    for (int j = 0; j < size; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < size; i++)
            {
                setCursorPosition(hStdout, j * 5, i + 2);
                cout << setw(4) << matrix[value];
                value++;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
        else
        {
            for (int i = size - 1; i >= 0; i--)
            {
                setCursorPosition(hStdout, j * 5, i + 2);
                cout << setw(4) << matrix[value];
                value++;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
    }

    delete[] matrix;
}

void printMatrixSpiral(int size)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int* matrix = new int[size * size];
    generateMatrix(matrix, size);
    int value = 0;
    int left = 0, right = size - 1, top = 0, bottom = size - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            setCursorPosition(hStdout, i * 5, top + size + 4);
            cout << setw(4) << matrix[value++];
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(150));
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            setCursorPosition(hStdout, right * 5, i + size + 4);
            cout << setw(4) << matrix[value++];
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(150));
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                setCursorPosition(hStdout, i * 5, bottom + size + 4);
                cout << setw(4) << matrix[value++];
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                setCursorPosition(hStdout, left * 5, i + size + 4);
                cout << setw(4) << matrix[value++];
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
            left++;
        }
    }
}

void printSquareA(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке a:" << endl;


    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}
void printSquareB(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке b:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void printSquareС(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке c:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void printSquareD(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }


    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке d:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void shakerSort(int* matrix, int size) {
    bool swapped = true;
    int* start = matrix;
    int* end = matrix + size - 1;

    while (swapped) {
        swapped = false;


        for (int* ptr = start; ptr < end; ++ptr) {
            if (*ptr > *(ptr + 1)) {
                swap(*ptr, *(ptr + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int* ptr = end; ptr > start; --ptr) {
            if (*ptr < *(ptr - 1)) {
                swap(*ptr, *(ptr - 1));
                swapped = true;
            }
        }
        ++start;
    }
}

void manipulateWithMatrix(int* matrix, int size, char operation, int value)
{

    for (int i = 0; i <= size * size; i++)
    {
        switch (operation)
        {
        case '+':
        {
            *(matrix + i) += value;
        }
        break;
        case '-':
        {
            *(matrix + i) -= value;
        }
        break;
        case '*':
        {
            *(matrix + i) *= value;
        }
        break;
        case '/':
        {
            if (value != 0)
                *(matrix + i) /= value;
            else
                cout << "Ошибочка, неопределенность\n\n";
            return;
        }
        }
    }
    cout << "Измененная матрица:" << endl;
}

int main_of_laba3()
{
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "RU");
    int size;

    cout << "Выберите размер матрицы (6,8,10): ";
    cin >> size;

    if (size != 6 && size != 8 && size != 10) {
        cout << "Некорректный размер матрицы!!! Программа завершена:(" << endl;
        return 1;
    }
    printMatrixZmeya(size);
    cout << endl;
    printMatrixSpiral(size);
    cout << endl << endl << endl << endl << endl;

    int* matrix = new int[size * size];


    generateMatrix(matrix, size);

    int choice;
    do
    {
        cout << "\n\tЗадания 2, 3 и 4" << endl;
        cout << "[1] Вывести матрицу для выполнения заданий\n";
        cout << "[2] Вывод матрицы способом a\n";
        cout << "[3] Вывод матрицы способом b\n";
        cout << "[4] Вывод матрицы способом c\n";
        cout << "[5] Вывод матрицы способом d\n";
        cout << "[6] Shaker sort\n";
        cout << "[7] Арифметика над матрицей\n";
        cout << "[8] ИДЗ 1\n";
        cout << "[0] Завершить работу программы:)\n";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            printMatrix(matrix, size);
            break;
        case 2:
            printSquareA(matrix, size);
            break;
        case 3:
            printSquareB(matrix, size);
            break;
        case 4:
            printSquareС(matrix, size);
            break;
        case 5:
            printSquareD(matrix, size);
            break;
        case 6:
            shakerSort(matrix, size * size);
            printMatrix(matrix, size);
            break;
        case 7:
        {
            char operation;
            int value;
            cout << "Исходная матрица:" << endl;
            printMatrix(matrix, size);

            cout << "Пожалуйста, выберите операцию (+, -, *, /): ";
            cin >> operation;
            cout << "Введите значение для операции: ";
            cin >> value;

            manipulateWithMatrix(matrix, size, operation, value);
            printMatrix(matrix, size);
        }
        break;
        case 8:
        {
            cout << "\tИДЗ 1";
            int* firstMatrix = new int[size * size];
            int* secondMatrix = new int[size * size];
            int* resultMatrix = new int[size * size];

            generateMatrix(firstMatrix, size);
            cout << "Первая матрица: " << endl;
            printMatrix(firstMatrix, size);


            generateMatrix(secondMatrix, size);
            cout << "Вторая матрица: " << endl;
            printMatrix(secondMatrix, size);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    resultMatrix[i * size + j] = firstMatrix[i * size + j] + secondMatrix[i * size + j];
                }
            }
            cout << "Результирующая матрица:" << endl;
            printMatrix(resultMatrix, size);

            delete[] firstMatrix;
            delete[] secondMatrix;
            delete[] resultMatrix;

        }break;

        }
    } while (choice != 0);

    return 0;
}

//Лаба 4
const int maxWordCount = 50;
const int maxWordLenght = 10;
const int maxStringLenght = maxWordCount * (maxWordLenght + 1);
const int MAX_LENGTH = 1000;

void preprocessBadChar(const char* pattern, unordered_map<char, int>& badChar) {
    int patternLength = strlen(pattern);
    for (int i = 0; i < patternLength; i++) {
        badChar[pattern[i]] = i;
    }
}

void removeExtraSpaces(char* text)
{
    char cleanedText[maxStringLenght];
    int cleanedIndex = 0;
    bool lastCharWasSpace = true;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            if (!lastCharWasSpace)
            {
                cleanedText[cleanedIndex++] = ' ';
                lastCharWasSpace = true;
            }
        }
        else
        {
            cleanedText[cleanedIndex++] = text[i];
            lastCharWasSpace = false;

        }
    }
    cleanedText[cleanedIndex] = '\0';
    strcpy_s(text, maxStringLenght, cleanedText);

}

void removeExtraPunctuation(char* text)
{
    char cleanedText[maxStringLenght];
    int cleanedIndex = 0;
    bool lastCharWasPunct = false;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (ispunct(text[i]))
        {
            if (!lastCharWasPunct)
            {
                cleanedText[cleanedIndex++] = text[i];
                lastCharWasPunct = true;
            }
        }
        else
        {
            cleanedText[cleanedIndex++] = text[i];
            lastCharWasPunct = false;
        }
    }

    cleanedText[cleanedIndex] = '\0';
    strcpy_s(text, maxStringLenght, cleanedText);
}

void registerCorrection(char* text) {
    char cleanedText[maxStringLenght];
    int cleanedIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (i == 0)
        {
            cleanedText[cleanedIndex++] = toupper(text[i]);
        }
        else
        {
            cleanedText[cleanedIndex++] = tolower(text[i]);
        }
    }

    cleanedText[cleanedIndex] = '\0';
    strcpy_s(text, maxStringLenght, cleanedText);
}

void printWordsWithoutDigits(char* text)
{
    char copyText[maxStringLenght];
    strcpy_s(copyText, maxStringLenght, text);

    char word[maxWordLenght];
    int wordIndex = 0;
    bool inWord = false;

    cout << "\n[3.3] Слова, не содержащие цифры:" << endl;

    for (int i = 0; copyText[i] != '\0'; i++) {
        if (copyText[i] == ' ') {
            if (inWord) {
                word[wordIndex] = '\0';
                bool hasDigit = false;

                for (int j = 0; word[j] != '\0'; j++) {
                    if (isdigit(word[j])) {
                        hasDigit = true;
                        break;
                    }
                }

                if (!hasDigit) {
                    cout << word << endl;
                }
                wordIndex = 0;
            }
            inWord = false;
        }
        else {
            if (wordIndex < maxWordLenght - 1) {
                word[wordIndex++] = copyText[i];
            }
            inWord = true;
        }
    }

    if (inWord) {
        word[wordIndex] = '\0';
        bool hasDigit = false;

        for (int j = 0; word[j] != '\0'; j++) {
            if (isdigit(word[j])) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit) {
            cout << word << endl;
        }
    }
}

void countCharactersInWords(const char* text) {
    char copyText[maxStringLenght];
    strcpy_s(copyText, maxStringLenght, text);

    char word[maxWordLenght];
    int wordIndex = 0;
    bool inWord = false;

    cout << "[4.2] Количество символов в каждом слове:" << endl;


    for (int i = 0; copyText[i] != '\0'; i++) {
        if (copyText[i] == ' ') {
            if (inWord) {
                word[wordIndex] = '\0';
                cout << wordIndex << " символов в слове: " << word << endl;
                wordIndex = 0;
                inWord = false;
            }
        }
        else {
            if (wordIndex < maxStringLenght - 1) {
                word[wordIndex++] = copyText[i];
            }
            inWord = true;
        }
    }

    if (inWord) {
        word[wordIndex] = '\0';
        cout << wordIndex << " символов в слове: " << word << endl;
    }
}
void linearSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    bool found = false;

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Не найдено";
    }
    cout << endl;
}

void boyerMoore(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    int badChar[256];

    for (int i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < patternLength; i++) {
        badChar[(unsigned char)pattern[i]] = i;
    }

    int s = 0;
    bool found = false;

    while (s <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << s << " ";
            found = true;
            s += (s + patternLength < textLength) ? patternLength - badChar[(unsigned char)text[s + patternLength]] : 1;
        }
        else {
            s += max(1, j - badChar[(unsigned char)text[s + j]]);
        }
    }
    if (!found) {
        cout << "Не найдено";
    }
    cout << endl;
}

int searchAllSubstrings(const char* text, const char* pattern, int* positions) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            if (count < maxWordCount) {
                positions[count++] = i;
            }
        }
    }
    return count;
}

void KMPSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    int lps[MAX_LENGTH];

    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;
    bool found = false;

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == patternLength) {
            cout << i - j << " ";
            found = true;
            j = lps[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    if (!found) {
        cout << "Не найдено";
    }
    cout << endl;
}

int main_of_laba4() {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    char inputText[maxStringLenght];

    cout << "[1] Введите последовательность слов (от 1 до 50 слов, каждое до 10 символов и заканчивается точкой): ";
    cin.getline(inputText, maxStringLenght);

    removeExtraSpaces(inputText);
    removeExtraPunctuation(inputText);
    registerCorrection(inputText);

    cout << "\n[2] Отредактированный текст: " << inputText << endl;

    printWordsWithoutDigits(inputText);

    countCharactersInWords(inputText);

    string text, pattern;

    cout << "[5] Введите строку: ";
    getline(cin, text);
    cout << "Введите подстроку для поиска: ";
    getline(cin, pattern);

    cout << "Результаты линейного поиска: ";
    linearSearch(text, pattern);

    cout << "Результаты алгоритма Бойера-Мура: ";
    boyerMoore(text, pattern);

    cout << "Результаты алгоритма КМП: ";
    KMPSearch(text, pattern);
    return 0;
}

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    bool running = true;

    while (running) {
        cout << "Выберите лабораторную работу:\n" << "[1] Лабораторная работа 1\n" << "[2] Лабораторная работа 2\n[3] Лабораторная работа 3\n[4] Лабораторная работа 4\n[5] Выход\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            main_of_laba1();
            break;
        case 2:
            main_of_laba2(); 
            break;
        case 3:
            main_of_laba3();
            break;
        case 4:
            main_of_laba4();
            break;
        case 5: running = false; break;
        }
        cout << endl;

    }
    return 0;
}