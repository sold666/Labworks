#pragma once
#include <iostream>
#include <cctype>
#include <cstring>
#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	MyString operator+ (const MyString&);
	MyString operator+= (char symbol);
	MyString& operator= (const MyString&);
	bool operator== (const  MyString&);
	bool operator!= (const MyString&);
	const char& operator[] (int);

	char* getStr();
	int getSizeString();
	int translateNum(MyString num);
	int atoiMy(const char c);
	bool checkDriverName(MyString value);
	bool checkStateRegSign(MyString value);

	friend std::istream& operator>> (std::istream& in, MyString& string);
	friend std::ostream& operator<< (std::ostream& out, MyString& string);

private:
	char* str_;
	int size_;
	static const int SIZE_IN = 255;
};

#endif