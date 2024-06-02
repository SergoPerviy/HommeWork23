#include <iostream>

void print_arr(int arr[], int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b }\n";
}

void three_max(int& num1, int& num2, int& num3) {
	int max_num = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

	num1 = max_num;
	num2 = max_num;
	num3 = max_num;
}

void NegativeIndex(int arr1[], int length1, int& index) {
	index = -1;
	for (int i = 0; i < length1; i++) {
		if (arr1[i] < 0) {
			index = i;
			break;
		}
	}
}

void ZeroFunc(int* arr2, int length2, int* arr3, int length3) {
	for (int i = 0; i < length2; i++) {
		for (int j = 0; j < length3; j++) {
			if (arr2[i] == arr3[j]) {
				arr3[j] = 0;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a = 1, b = 2, c = 3;

	/*
	Задача 1
	Создайте функцию, которая принимает три переменные (не их адреса, а именно переменные). Функция находит
	максимальную из них, после чего меняет значения остальных переменных на значение максимальной.
	*/

	std::cout << "Задача №1\nИзначальные числа -> " << a << ", " << b << ", " << c << std::endl;
	three_max(a, b, c);
	std::cout << "Измененные  числа -> " << a << ", " << b << ", " << c << "\n\n";

	/*
	Задача 2
	Создайте функцию, которая принимает массив, его длину и переменную. Функция записывает в переданную 
	переменную индекс первого отрицательного элемент массива. Если отрицательных элементов нет в массиве, 
	то в переменную записывается -1.
	*/

	std::cout << "Задача №2\nИзначальный массив:\n";
	const int size1 = 10;
	int arr1[size1] = { 1, 2, 3, 4, 5, -5, 6, 7, 8, 9 };
	int index{};

	print_arr(arr1, size1);

	NegativeIndex(arr1, size1, index);

	if (index != -1)
		std::cout << "Индекс первого отрицательного элимента массива = " << index << "\n\n";
	else
		std::cout << "В массиве отсутствуют отрицательные елименты" << "\n\n";

	/*
	Задача 3
	Напишите функцию, которая принимает два массива и их длины. Функция должна обнулить все элементы второго
	массива, которые встречаются в первом. В теле функции необходимо использовать синтаксис указателей для 
	перебора элементов обоих массивов.
	*/

	std::cout << "Задача №3\nMассив №1:\n";
	const int size2 = 7;
	int arr2[size2] = { 3, 6, 4, 1, 4, 8, 2 };
	print_arr(arr2, size2);

	std::cout << "Массив №2:\n";
	const int size3 = 6;
	int arr3[size3] = { 5, 3, 1, 5, 10, 8 };
	print_arr(arr3, size3);

	ZeroFunc(arr2, size2, arr3, size3);

	std::cout << "Измененный массив №3:\n";
	print_arr(arr3, size3);

	return 0;
}