#include "MyString.h"

MyString::MyString()
{
	size_ = 0;
	str_ = nullptr;
}

MyString::MyString(const char* string)
{
	this->size_ = strlen(string);
	this->str_ = new char[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		this->str_[i] = string[i];
	}
	this->str_[this->size_] = '\0';
}

MyString::MyString(const MyString& other)
{
	if (this->size_ != 0) 
	{
		this->str_ = nullptr;
		this->size_ = 0;
	}
	this->size_ = other.size_;
	this->str_ = new char[size_ + 1];
	for (int i = 0; i < size_; i++) {
		str_[i] = other.str_[i];
	}
	this->str_[this->size_] = '\0';
}

MyString::~MyString()
{
	delete[] this->str_;
}

MyString& MyString::operator= (const MyString& assignmentStr)
{

	size_ = assignmentStr.size_;
	str_ = new char[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		this->str_[i] = assignmentStr.str_[i];
	}
	this->str_[size_] = '\0';
	return *this;
}

bool MyString:: operator!= (const MyString& other)
{
	return !(this->operator==(other));
}

MyString MyString::operator+ (const MyString& other)
{
	MyString temp;
	temp.size_ = size_ + other.size_;
	temp.str_ = new char[temp.size_ + 1];

	int  i = 0;
	for (; i < size_; i++)
	{
		temp.str_[i] = this->str_[i];
	}
	for (int j = 0; j < size_; j++, i++)
	{
		temp.str_[i] = other.str_[j];
	}
	temp.str_[temp.size_] = '\0';

	return temp;
}

bool MyString:: operator== (const MyString& other)
{
	if (size_ != other.size_)
	{
		return false;
	}

	for (int i = 0; i < size_; i++)
	{
		if (str_[i] != other.str_[i])
		{
			return false;
		}
	}
	return true;
}

MyString MyString::operator+= (char symbol)
{
	MyString temp(*this);
	if (size_ != 0)
	{
		this->str_ = nullptr;
	}
	this->size_++;
	this->str_ = new char[temp.size_ + 1];
	for (int i = 0; i < this->size_ - 1; i++) {
		this->str_[i] = temp[i];
	}
	this->str_[size_ - 1] = symbol;
	this->str_[size_] = '\0';
	return *this;
}

const char& MyString:: operator[](int index)
{
	if (this->str_ == nullptr) 
	{
		throw "Ошибка ваша строка пустая.";
	}
	if (index < 0 || index > (int)strlen(this->str_))
	{
		throw "Неверный индекс элемента";
	}
	return this->str_[index];
}

std::istream& operator>> (std::istream& in, MyString& string)
{
	{
		char temp[MyString::SIZE_IN];
		in.get(temp, MyString::SIZE_IN);
		if (in)
			string = temp;
		while (in && in.get() != '\n' && in.get() != '\0')
			continue;
		return in;
	}
}

std::ostream& operator<< (std::ostream& out, MyString& string)
{
	for (int i = 0; i < string.size_; i++)
	{
		out << string.str_[i];
	}
	return out;
}

char* MyString::getStr()
{
	return this->str_;
}
int  MyString::getSizeString()
{
	return size_;
}

int MyString::translateNum(MyString num)
{
	int len = num.getSizeString();
	long long number = 0;
	for (int i = 0; i < len; i++) {
		if (num[i] >= 48 && num[i] <= 57) 
		{
			number += (static_cast<int>(num.getStr()[i]) - 48) * pow(10, len - i - 1);
		}
		else 
		{
			return 0;
		}
	}
	return number;
}

int MyString::atoiMy(const char c)
{
	int i = static_cast<int>(c) - 48;
	return i;
}

bool MyString::checkDriverName(MyString value)
{
	char* name = value.getStr();
	int len = value.getSizeString();

	if (name[0] < 65 || name[0] > 90 )
	{
		return false;
	}
	int i = 1;
	while (name[i] != ' ' || name[i] != '-') 
	{
		if (name[i] < 97 || name[i] > 122)
		{
			return false;
		}
		i++;
	}
	i++;
	if (name[i] < 65 || name[i] > 90)
	{
		return false;
	}
	i++;
	for (i; i < len; i++) 
	{
		if (name[i] < 97 || name[i] > 122)
		{
			return false;
		}
	}
	if (name[len] != '\0')
	{
		return false;
	}
	return true;
}

bool MyString::checkStateRegSign(MyString value)
{
	char* name = value.getStr();
	int len = value.getSizeString();
	int i = 0;
	if (len > 10)
	{
		return false;
	}
	if (i == 0 && name[i] > 64 && name[i] < 91
		&& name[i + 4] > 64 && name[i + 4] < 91
		&& name[i + 5] > 64 && name[i + 5] < 91)
	{
		return true;
	}
	else
	{
		return false;
	}
		
	if (name[len] != '\0')
	{
		return false;
	}
}
