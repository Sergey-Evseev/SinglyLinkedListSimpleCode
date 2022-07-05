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
	cout << "Destructor" << endl;
};

//����� ���������� ������, ��� ������ �� ���� ��� � ����������� �����������//
template<typename T> 
void List<T>::push_back(T data) 
{
	if (head == nullptr) //���� ��������� ������ //global space :: �������� ����
	{
		head = new Node<T>(data); //������� ����� ��-� Node � �������� ��� � ����������� ������
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

template<typename T>
void List<T>::clear()
{
	while (Size) //���� ���-�� ��������� �� �������
	{
		pop_front();
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