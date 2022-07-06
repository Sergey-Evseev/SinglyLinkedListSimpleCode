#include "List.h"
#include <iostream>
#include <string>
using namespace std;

//конструктор по умолчанию//
template<typename T>
List<T>::List()
{
	Size = 0;//начальный размер списка //global space :: добавлен мной
	head = nullptr;//первоначально указывает на ноль //global space :: добавлен мной
};

//деструктор класcа List//
template<typename T>
List<T>::~List() 
{	
	clear();
	cout << "Destructor" << endl;
};

//метод добавления данных, имя метода по типу как в стандартной бибилиотеке//
template<typename T> 
void List<T>::push_back(T data) 
{
	if (head == nullptr) //если указатель пустой 
	{
		head = new Node<T>(data); //создать новый эл-т класса Node и передать ему в конструктор данные
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

//метод удаления первого элемента списка//
template<typename T>
void List<T>::pop_front()
{
	Node <T> *temp = head; //временный объект типа Node для хранения адреса головы (нулевого элемента) списка
	                       // т.к. head это указатель, то и временная переменная должна быть указателем   
	head = head->pNext; //присваиваем head адрес следующего элемента, который идет за head'ом - 2-й элемент стал хедом
	delete temp; //адрес head остался храниться в temp, поэтому мы его знаем и можем удалить элемент по этому адресу
	Size--; //декремент количества элементов
}

// метод удаления всего списка//
template<typename T>
void List<T>::clear()
{
	while (Size) //пока кол-во элементов не нулевое
	{
		pop_front();
	}
}
//добавление элемента в начало списка //
template<typename T>
void List<T>::push_front(T data)
{	
	head = new Node<T>(data, head); //создать новый эл-т класса Node и передать ему в конструктор данные
	//вторым параметром конструктора передаем адрес старого хеда - на него будет ссылаться в адресе
	//если мы создаем вообще 1-й элемент то там будет NULL - значение конструктора по умолчанию (head = nullptr;)
	Size++; //увеличивать переменную Size
}

//метод вставки по индексу//
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0) //если индекс 0 используем для добавления push_front 
	{
		push_front(data);
	}	
	else
	{
		Node <T> *previous = this->head; //созд. врем. указатель на текущий head 
		//в новом эл-те поле адрес должно указ. на след.эл-т, а предыд. эл-т на вставляемый
		for (int i = 0; i < index - 1; i++) //поэтому ищем с начала списка эл-т с индексом предшествующим добавляемому
		{
			previous = previous->pNext; //нашему указателю присваиваем указатель на следующую ноду нашего списка
		}                               //если добавляем 1 то в previous будет адрес элемента под номером 0
		Node<T> *newNode = new Node<T>(data, previous->pNext); //создаем нов. объект типа Node, передаем ему в конструктор данные 
		//и у предыд. эл-та берем (принимаем) поле pNext,теперь наш объект будет ссылаться на кот. указывал предыдущий
		previous->pNext = newNode; //предыдущему присваиваем адрес нового (newNode у нас указатель)
		Size++; //push_front уже содержит итератор Size 
	}
}

//перегрузка оператор [] для вывода значений//
template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0; //счетчик в каком элементе мы находимся
	Node<T> *current = this->head;//переменная для проверки следующего элемента
	while (current != nullptr)
	{
		if (counter == index)//если счетчик совпадает с номер запрошенного элемента 
		{ 
			return current->data; //то вернуть значение его поля data
		}
		current = current->pNext; //пока current не станет указывать на null присваивать текущему адрес следующего
		counter++;
	}
}


template<typename T>
void List<T>::printList()
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		cout << this->head->data << " ";
		head = head->pNext;

	}; //вывод всех элементов списка
}
