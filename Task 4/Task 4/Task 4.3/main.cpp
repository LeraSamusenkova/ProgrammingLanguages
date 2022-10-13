#include <iostream>
#include <random>

using namespace std;

/*
*\brief Выбор способа заполнение массива
*\param random случайное заполнение массива
*\param manual ручное заполнение массива
*/
enum class fill_array 
{
	random,
	manual
 };

/*
*\brief Функция считывает размер массива
*\param message выводит сообщение для пользователя
*\return возвращает размеры массива
*/
size_t get_size(const string& message);

/*
*\brief Функция заполняет массив случайными элементами
*\param rows количество строк массива
*\param columns количество столбцов массива
*\param min_value минимальное значение генерируемого элемента
*\param max_value максимальное значение генерируемого элемента
*\return возвращает указатель на массив заполненный случайными элементами
*/
int** fill_random_array(const size_t rows, const size_t columns, const int min_value, const int max_value);

/*
*\brief Функция заполняет массив элементами введенными пользователем
*\param rows количество строк массива
*\param columns количество столбцов массива
*\return возвращает указатель на массив заполненный пользователем
*/
int** fill_manual_array(const size_t rows, const size_t columns);

/*
*\brief Функция создающая массив 
*\param rows количество строк массива
*\param columns количество столбцов массива
*\return возвращает указатель на созданный массив
*/
int** create_array(const size_t rows, const size_t columns);

/*
*\brief Функция выводящая массив на экран
*\param array указатель на массив
*\param rows количество строк массива
*\param columns количество столбцов массива
*/
void print_array(int** array, const size_t rows, const size_t columns);

/*
*\brief Функция возвращающая максимальный элемент одномерного массива
*\param array указатель на массив
*\param columns количество столбцов массива
*\return возвращает максимальный элемент
*/
int get_max_element(int* array, const size_t columns);

/*
*\brief Функция для подсчета первого задания
*\param array исходный массив
*\param rows количество строк массива
*\param columns количество столбцов массива
*\return возвращает указатель на массив для задания 1
*/
int** task_1(int** array, const size_t rows, const size_t columns);

/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	int rows = get_size("Введите количество строк: \n");
	int columns = get_size("Введите количество столбцов: \n");;
	const int min_value = -100;
	const int max_value = 100;
	int** array = create_array(rows, columns);
	

	cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fill_array::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fill_array::manual) << '\t' << "Пользовательский ввод" << endl;
	int input = 0;
	cin >> input;
	const auto choice = static_cast<fill_array>(input);

	switch (choice)
	{
		case(fill_array::random): 
		{
			array = fill_random_array(rows, columns, min_value, max_value);
			break;
		}
		case(fill_array::manual): 
		{
			array = fill_manual_array(rows, columns);
			break;
		}
		default: 
		{
			cout << "error" << endl;
		}
	}
	int** array_task_1 = task_1(array, rows, columns);
	print_array(array, rows, columns);
	cout << "________________Заменим максимальный элемент строки на 0________________" << endl;
	print_array(array_task_1, rows, columns);

	return 0;
}

size_t get_size(const string& message)
{
	int size = -1;
	cout << message;
	cin >> size;

	if (size < 0)
	{
		throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
	}

	return size;
}

int** fill_manual_array( const size_t rows,const size_t columns) 
{
	int** array = create_array(rows, columns);
	for (size_t i = 0; i < rows; i++) 
	{
		for (size_t j = 0; j < columns; j++) 
		{
			int l = 0;
			cin >> l;
			array[i][j] = l;
		}
	}
	return array;
}


int** fill_random_array(const size_t rows, const size_t columns, const int min_value, const int max_value)
{
	int** array = create_array(rows, columns);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> uniformIntDistribution(min_value, max_value);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++) 
		{
			array[i][j] = uniformIntDistribution(gen);
		}
	}

	return array;
}

int** create_array( const size_t rows, const size_t columns) 
{
	int** array = new int* [rows];

	for (size_t i = 0; i < rows; i++) 
	{
		array[i] = new int[columns];
	}
	return array;
}

void print_array(int** array, const size_t rows, const size_t columns) 
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
}

int get_max_element(int* array, const size_t columns)
{
	int max = array[0];
	for (size_t i = 0; i < columns; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int** task_1(int** array, const size_t rows, const size_t columns)
{
	int** array_new = create_array(rows, columns);
	int max = 0;
	for (size_t i = 0; i < rows; i++)
	{
		max = get_max_element(array[i], columns);
		for (size_t c = 0; c < columns; c++)
		{
			if (array[i][c] == max)
			{
				array_new[i][c] = 0;
			}
			else
			{
				array_new[i][c] = array[i][c];
			}
		}
	}
	return array_new;
}