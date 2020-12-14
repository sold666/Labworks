#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H

template <class T>
class MyArray
{
public:
	MyArray()
	{
		array_ = nullptr;
		arraySize_ = 0;
	}

	MyArray(const MyArray<T>& other)
	{
		if (other.arraySize_ == 0)
		{
			array_ = nullptr;
			arraySize_ = 0;
		}
		else 
		{
			arraySize_ = other.arraySize_;
			array_ = new T[arraySize_];
			for (int i = 0; i < arraySize_; i++)
			{
				this->array_[i] = other.array_[i];
			}
		}
	}

	~MyArray()
	{
		delete[] array_;
	}

	T& operator[](int i)
	{
		if (i < 0 || i > this->arraySize_)
		{
			throw "Неверный индекс элемента";
		}
		return array_[i];
	}

	void push_back(T& element)
	{
		if (arraySize_ == 0 || array_ == nullptr) 
		{
			array_ = new T[1];
			array_[0] = element;
			arraySize_++;
		}
		else
		{
			MyArray<T> temp(*this);
			arraySize_++;
			delete[] this->array_;
			this->array_ = new T[arraySize_];
			for (int i = 0; i < arraySize_ - 1; i++)
			{
				array_[i] = temp[i];
			}
			this->array_[this->arraySize_ - 1] = element;
		}
	}

	MyArray operator= (const MyArray& value)
	{
		if (array_ != nullptr) 
		{
			delete[] array_;
		}
		arraySize_ = value.arraySize_;
		array_ = new MyArray& [arraySize_];

		for (int i = 0; i < arraySize_; i++) 
		{
			array_[i] = value.array_[i];
		}
	}

	int getSize()
	{
		return arraySize_;
	}

	bool isEmpty()
	{
		return !arraySize_;
	}
private:
	T* array_;
	int arraySize_;
};
#endif