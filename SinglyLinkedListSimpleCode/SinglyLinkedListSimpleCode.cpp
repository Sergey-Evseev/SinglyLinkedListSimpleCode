#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	List<int> lst; //������ ���� List,�������� ��� ������ � ������ ������������ ������  
	lst.push_back(5);
	lst.push_back(10); //��������� ����� ��� �������� ������� ��������
	lst.push_back(20); //��������� ������ �������
	for (int i = 0; i < lst.GetSize(); i++) {cout << lst[i] << " ";} //����� ���� ��������� ������


	cout << "���-�� ���������: " << lst.GetSize() << endl; //� ������ ����� ������� ������ � ���������� ���-�� ���������
	cout << lst[2] << endl; //����� �������� �������� �� ��� ������� ����� ������������� �������� []
	cout << "����� pop_front" << endl;
	lst.pop_front(); //�������� ������� �������� ������

	int numbersCount; //���������� �������� ������ ��� ���������� ������. ����������
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)//���������� ������ �� numbersCount ��������� 
	{
		lst.push_back(rand()%10);
	}

	for (int i = 0; i < lst.GetSize(); i++)//����� ���� ��������� ������
	{
		cout << lst[i] << endl;
	}

	lst.clear(); //�������� ���� ��������� ������

	return 0;
};