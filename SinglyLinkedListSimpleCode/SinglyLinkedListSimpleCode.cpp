#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	List<int> lst; //объект типа List,передаем тип данных в шаблон конструктора класса  
	lst.push_back(5);
	lst.push_back(10); //повторный вызов для создания второго элемента
	lst.push_back(20); //добавляем третий элемент	
	
	for (int i = 0; i < lst.GetSize(); i++) //вывод всех элементов списка с помощью цикла и метода at 
	{
		cout << lst[i] << " ";
	} 
	
	cout << "Кол-во элементов: " << lst.GetSize() << endl; //у списка можем вызвать геттер и посмотреть кол-во элементов
	cout << "Вывод элемента № 3: " << lst[2] << endl; //вывод значения элемента по его индексу через перегруженный оператор []
	cout << "Метод pop_front - удаление одного первого элемента" << endl;
	lst.pop_front(); //удаление первого элемента списка

	int numbersCount; //переменная размеров списка для заполнения случай. значениями
	cout << "Введите количество элементов списка:" << endl;
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)//заполнение (добавление к существующим элементам) списка на numbersCount элементов 
	{
		lst.push_back(rand()%10);
	}
	
	for (int i = 0; i < lst.GetSize(); i++)//вывод всех элементов списка
	{
		cout << lst[i] << " ";
	} cout << endl;
	
	cout << "Добавление элемента с помощью insert" << endl;
	lst.insert(99, 1);
	cout << lst.GetSize() << endl;
	lst.printList(); //вывод списка с помощью функции
		
	lst.clear(); //удаление всех элементов списка, либо включаем вызов clear() в деструктор и он будет удалять автоматически
	
	return 0;
};