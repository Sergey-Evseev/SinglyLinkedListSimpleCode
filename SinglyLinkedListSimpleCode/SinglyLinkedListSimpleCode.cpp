#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	List<int> lst; //объект типа List,передаем тип данных в шаблон конструктора класса  
	lst.push_back(5);
	lst.push_back(10); //повторный вызов для создания второго элемента
	lst.push_back(20); //добавляем третий элемент
	for (int i = 0; i < lst.GetSize(); i++) {cout << lst[i] << " ";} //вывод всех элементов списка


	cout << "Кол-во элементов: " << lst.GetSize() << endl; //у списка можем вызвать геттер и посмотреть кол-во элементов
	cout << lst[2] << endl; //вывод значения элемента по его индексу через перегруженный оператор []
	cout << "Метод pop_front" << endl;
	lst.pop_front(); //удаление первого элемента списка

	int numbersCount; //переменная размеров списка для заполнения случай. значениями
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)//заполнение списка на numbersCount элементов 
	{
		lst.push_back(rand()%10);
	}

	for (int i = 0; i < lst.GetSize(); i++)//вывод всех элементов списка
	{
		cout << lst[i] << endl;
	}

	lst.clear(); //удаление всех элемениов списка

	return 0;
};