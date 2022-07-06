#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	List<int> lst; //������ ���� List,�������� ��� ������ � ������ ������������ ������  
	lst.push_back(5);
	lst.push_back(10); //��������� ����� ��� �������� ������� ��������
	lst.push_back(20); //��������� ������ �������	
	
	for (int i = 0; i < lst.GetSize(); i++) //����� ���� ��������� ������ � ������� ����� � ������ at 
	{
		cout << lst[i] << " ";
	} 
	
	cout << "���-�� ���������: " << lst.GetSize() << endl; //� ������ ����� ������� ������ � ���������� ���-�� ���������
	cout << "����� �������� � 3: " << lst[2] << endl; //����� �������� �������� �� ��� ������� ����� ������������� �������� []
	cout << "����� pop_front - �������� ������ ������� ��������" << endl;
	lst.pop_front(); //�������� ������� �������� ������

	int numbersCount; //���������� �������� ������ ��� ���������� ������. ����������
	cout << "������� ���������� ��������� ������:" << endl;
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)//���������� (���������� � ������������ ���������) ������ �� numbersCount ��������� 
	{
		lst.push_back(rand()%10);
	}
	
	for (int i = 0; i < lst.GetSize(); i++)//����� ���� ��������� ������
	{
		cout << lst[i] << " ";
	} cout << endl;
	
	cout << "���������� �������� � ������� insert" << endl;
	lst.insert(99, 1);
	cout << lst.GetSize() << endl;
	lst.printList(); //����� ������ � ������� �������
		
	lst.clear(); //�������� ���� ��������� ������, ���� �������� ����� clear() � ���������� � �� ����� ������� �������������
	
	return 0;
};