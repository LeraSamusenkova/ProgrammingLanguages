#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Расчет а по заданной формуле
* \param x Первый аргумент функции
* \param y Второй аргумент функции
* \param z Третий аргумент функции
* \return значение а
*/
double get_a(const double x, const double y, const double z);

/**
* \brief Расчет b по заданной формуле
* \param x Первый аргумент функции
* \param y Второй аргумент функции
* \param z Третий аргумент функции
* \return значение b
*/
double get_b(const double x, const double y, const double z);

/**
* \brief Вхождение в программу
* \return Возвращает 0 в случае успеха
*/
int main()
{
	const double x = 0.61;
	const double y = 3.4;
	const double z = 16.5;
	const double a = get_a(x, y, z);
	const double b = get_b(x, y, z);
	std::cout << "x =" << x << " y =" << y << " z =" << z << "\n";
	std::cout << "a =" << a << " b = " << b << std::endl;
	return 0;
}

double get_a(const double x, const double y, const double z)
{
	return x * x * x * (pow(tan((x + y) * (x + y)), 2)) + (z / (sqrt(x + y)));
}

double get_b(const double x, const double y, const double z)
{
	return ((y * x * x - z) / (pow(M_E, z * x) - 1));
}