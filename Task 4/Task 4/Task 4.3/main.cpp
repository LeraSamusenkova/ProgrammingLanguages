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
*\brief Функция заполняет массив случайными элементами
*\param line количество строк массива
*\param column количество столбцов массива
*\param min_value минимальное значение генерируемого элемента
*\param max_value максимальное значение генерируемого элемента
*\return возвращает указатель на массив заполненный случайными элементами
*/
int** fill_random_array(const size_t line, const size_t column, const int min_value, const int max_value);

/*
*\brief Функция заполняет массив элементами введенными пользователем
*\param line количество строк массива
*\param column количество столбцов массива
*\return возвращает указатель на массив заполненный пользователем
*/
int** fill_manual_array(size_t line, size_t column);

/*
*\brief Функция создающая массив 
*\param line количество строк массива
*\param column количество столбцов массива
*\return возвращает указатель на созданный массив
*/
int** create_array(size_t line, size_t column);

/*
*\brief Функция выводящая массив на экран
*\param array указатель на массив
*\param line количество строк массива
*\param column количество столбцов массива
*/
void print_array(int** array, const size_t line, const size_t column);


/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	size_t line;
	size_t column;
	const int min_value = -100;
	const int max_value = 100;
	cout << "Введите количество строк: " << endl;
	cin >> line;
	cout << "Введите количество столбцов: " << endl;
	cin >> column;
	int** array = create_array(line, column);
	

	cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fill_array::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fill_array::manual) << '\t' << "Пользовательский ввод" << endl;
	int input = 0;
	cin >> input;
	const auto choice = static_cast<fill_array>(input);

	switch (choice)
	{
	case(fill_array::random): 
	{
		array = fill_random_array(line, column, min_value, max_value);
		break;
	}
	case(fill_array::manual): 
	{
		array = fill_manual_array(line, column);
		break;
	}
	default: 
	{
		cout << "error" << endl;
	}
	}
	print_array(array, line, column);
	return 0;
}

int** fill_manual_array( size_t line, size_t column) 
{
	int** array = create_array(line, column);
	for (size_t i = 0; i < line; i++) 
	{
		for (size_t j = 0; j < column; j++) 
		{
			int l = 0;
			cin >> l;
			array[i][j] = l;
		}
	}
	return array;
}


int** fill_random_array(const size_t line, const size_t column, const int min_value, const int max_value)
{
	int** array = create_array(line, column);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> uniformIntDistribution(min_value, max_value);
	for (size_t i = 0; i < line; i++)
	{
		for (size_t j = 0; j < column; j++) 
		{
			array[i][j] = uniformIntDistribution(gen);
		}
	}

	return array;
}

int** create_array(size_t line, size_t column) 
{
	int** array = new int* [line];

	for (size_t i = 0; i < line; i++) 
	{
		array[i] = new int[column];
	}
	return array;
}

void print_array(int** array, const size_t line, const size_t column) 
{
	for (size_t i = 0; i < line; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
}