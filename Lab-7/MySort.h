#pragma once
#ifndef MYSORT_H
#define MYSORT_H

template <class T> 
void sort(MyArray<MyClass>& arr, T useless)
{
	int size = arr.getSize();
	MyClass temp; // ��������� ���������� ��� �������� �������� �������� ������������ �������
	int lastIndex; // ������ ����������� ��������
	for (int value = 1; value < size; value++)
	{
		temp = arr[value]; // �������������� ��������� ���������� ������� ��������� �������� �������
		lastIndex = value - 1; // ���������� ������ ����������� �������� �������
		while (lastIndex >= 0 && arr[lastIndex].getRegion() > temp.getRegion()) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arr[lastIndex + 1] = arr[lastIndex]; // ������������ ��������� �������
			arr[lastIndex] = temp;
			lastIndex--;
		}
	}
}
#endif