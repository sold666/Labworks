#pragma once
#ifndef MYSORT_H
#define MYSORT_H

template <class T> 
void sort(MyArray<MyClass>& arr, T useless)
{
	int size = arr.getSize();
	MyClass temp; // временная переменная для хранения значения элемента сортируемого массива
	int lastIndex; // индекс предыдущего элемента
	for (int value = 1; value < size; value++)
	{
		temp = arr[value]; // инициализируем временную переменную текущим значением элемента массива
		lastIndex = value - 1; // запоминаем индекс предыдущего элемента массива
		while (lastIndex >= 0 && arr[lastIndex].getRegion() > temp.getRegion()) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[lastIndex + 1] = arr[lastIndex]; // перестановка элементов массива
			arr[lastIndex] = temp;
			lastIndex--;
		}
	}
}
#endif