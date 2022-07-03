#include "List.h"
#include <iostream>
using namespace std;

template<typename T>
List<T>::List()
{
	Size = 0;//начальный размер списка
	head = nullptr;//первоначально указывает на ноль
};

template<typename T>
List<T>::~List() //деструктор класcа List
{
	cout << "Destructor" << endl;
};

template<typename T> 
void List<T>:: push_back(T data)//метод добавления данных, имя метода по типу как в стандартной бибилиотеке 
{
	if (head == nullptr) //если указатель пустой
	{
		head = new Node<T>(data); //создать новый эл-т Node и передать ему в конструктор данные
	}                             //head будет указывать на новую ноду в динамической памяти - объект класса Node 
	else
	{
		Node <T> *current = this->head; //временная перем. типа Node, присваиваем ей значение заголовка 
		
		while (current->pNext != nullptr ) //в цикле идем по нодам и сравниваем на что указывает заголовок текущего элемента
		{
			current = current->pNext; //если заголовок на след.эл-т не указывает на нуль, врем. переменной (адресу) присваиваем значение следующего
		}
		current->pNext = new Node<T>(data);//переменной pNext последнего (с нул. адресом) элемента присваиваем значение новой ноды
	}
	Size++; //при каждом добавлении элемента увеличивать переменную Size
}
template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0; //счетчик в каком элементе мы находимся
	Node<T> *current = this->head;//переменная для проверки следующего элемента
	while (current != nullptr)
	{
		if (counter == index)//если счетчик совпадает с номер запрошенного элемента 
		{ 
			return current->data //то вернуть значение его поля data
		}
		current = current->pNext; //пока current не станет указывать на null присваивать текущему адрес следующего
		counter++;
	}
}
