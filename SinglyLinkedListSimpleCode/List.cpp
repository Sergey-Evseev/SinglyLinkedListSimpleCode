#include "List.h"
#include <iostream>
using namespace std;

template<typename T>
List<T>::List()
{
	Size = 0;//��������� ������ ������
	head = nullptr;//������������� ��������� �� ����
};

template<typename T>
List<T>::~List() //���������� ����c� List
{
	cout << "Destructor" << endl;
};

template<typename T> 
void List<T>:: push_back(T data)//����� ���������� ������, ��� ������ �� ���� ��� � ����������� ����������� 
{
	if (head == nullptr) //���� ��������� ������
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
template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0; //������� � ����� �������� �� ���������
	Node<T> *current = this->head;//���������� ��� �������� ���������� ��������
	while (current != nullptr)
	{
		if (counter == index)//���� ������� ��������� � ����� ������������ �������� 
		{ 
			return current->data //�� ������� �������� ��� ���� data
		}
		current = current->pNext; //���� current �� ������ ��������� �� null ����������� �������� ����� ����������
		counter++;
	}
}
