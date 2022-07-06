#include "List.h"
#include <iostream>
#include <string>
using namespace std;

//����������� �� ���������//
template<typename T>
List<T>::List()
{
	Size = 0;//��������� ������ ������ //global space :: �������� ����
	head = nullptr;//������������� ��������� �� ���� //global space :: �������� ����
};

//���������� ����c� List//
template<typename T>
List<T>::~List() 
{	
	clear();
	cout << "Destructor" << endl;
};

//����� ���������� ������, ��� ������ �� ���� ��� � ����������� �����������//
template<typename T> 
void List<T>::push_back(T data) 
{
	if (head == nullptr) //���� ��������� ������ 
	{
		head = new Node<T>(data); //������� ����� ��-� ������ Node � �������� ��� � ����������� ������
	}                             //head ����� ��������� �� ����� ���� � ������������ ������ - ������ ������ Node 
	else
	{
		Node <T> *current = this->head; //��������� �����. ���� Node, ����������� �� �������� ��������� 
		
		while (current->pNext != nullptr ) //� ����� ���� �� ����� � ���������� �� ��� ��������� ��������� �������� ��������
		{
			current = current->pNext; //���� ��������� �� ����.��-� �� ��������� �� ����, ����. ���������� (������) ����������� �������� ����������
		}
		current->pNext = new Node<T>(data);//���������� pNext ���������� (� ���. �������) �������� ����������� �������� ����� ����
	}
	Size++; //��� ������ ���������� �������� ����������� ���������� Size
}

//����� �������� ������� �������� ������//
template<typename T>
void List<T>::pop_front()
{
	Node <T> *temp = head; //��������� ������ ���� Node ��� �������� ������ ������ (�������� ��������) ������
	                       // �.�. head ��� ���������, �� � ��������� ���������� ������ ���� ����������   
	head = head->pNext; //����������� head ����� ���������� ��������, ������� ���� �� head'�� - 2-� ������� ���� �����
	delete temp; //����� head ������� ��������� � temp, ������� �� ��� ����� � ����� ������� ������� �� ����� ������
	Size--; //��������� ���������� ���������
}

// ����� �������� ����� ������//
template<typename T>
void List<T>::clear()
{
	while (Size) //���� ���-�� ��������� �� �������
	{
		pop_front();
	}
}
//���������� �������� � ������ ������ //
template<typename T>
void List<T>::push_front(T data)
{	
	head = new Node<T>(data, head); //������� ����� ��-� ������ Node � �������� ��� � ����������� ������
	//������ ���������� ������������ �������� ����� ������� ���� - �� ���� ����� ��������� � ������
	//���� �� ������� ������ 1-� ������� �� ��� ����� NULL - �������� ������������ �� ��������� (head = nullptr;)
	Size++; //����������� ���������� Size
}

//����� ������� �� �������//
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0) //���� ������ 0 ���������� ��� ���������� push_front 
	{
		push_front(data);
	}	
	else
	{
		Node <T> *previous = this->head; //����. ����. ��������� �� ������� head 
		//� ����� ��-�� ���� ����� ������ ����. �� ����.��-�, � ������. ��-� �� �����������
		for (int i = 0; i < index - 1; i++) //������� ���� � ������ ������ ��-� � �������� �������������� ������������
		{
			previous = previous->pNext; //������ ��������� ����������� ��������� �� ��������� ���� ������ ������
		}                               //���� ��������� 1 �� � previous ����� ����� �������� ��� ������� 0
		Node<T> *newNode = new Node<T>(data, previous->pNext); //������� ���. ������ ���� Node, �������� ��� � ����������� ������ 
		//� � ������. ��-�� ����� (���������) ���� pNext,������ ��� ������ ����� ��������� �� ���. �������� ����������
		previous->pNext = newNode; //����������� ����������� ����� ������ (newNode � ��� ���������)
		Size++; //push_front ��� �������� �������� Size 
	}
}

//���������� �������� [] ��� ������ ��������//
template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0; //������� � ����� �������� �� ���������
	Node<T> *current = this->head;//���������� ��� �������� ���������� ��������
	while (current != nullptr)
	{
		if (counter == index)//���� ������� ��������� � ����� ������������ �������� 
		{ 
			return current->data; //�� ������� �������� ��� ���� data
		}
		current = current->pNext; //���� current �� ������ ��������� �� null ����������� �������� ����� ����������
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

	}; //����� ���� ��������� ������
}
