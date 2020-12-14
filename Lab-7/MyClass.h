#pragma once
#include "MyString.h"
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
public:
	MyClass();
	MyClass(int, const MyString&, const MyString&);
	MyClass(const MyClass&);
	~MyClass();

	MyClass operator+ (const MyClass&);
	bool operator< (int& value);
	bool operator< (MyString& string);
	MyClass& operator= (const MyClass& other);
	MyClass& operator++ (); //префиксная форма
	
	MyString& getFullDriverName();
	MyString& getStateRegistrationSign();
	int getNumberRoute();
	int getRegion();

	void setStateRegistrationSign(const MyString&);
	void setNumberRoute(int);
	void setFullDriverName(const MyString&);

	friend bool operator== (MyClass& valueFirst, MyClass& valueSecond);
	friend std::istream& operator>> (std::istream& in, MyClass& value);
	friend std::ostream& operator<< (std::ostream& out, MyClass& value);
	friend bool operator> (const MyClass& valueFirst, int& valueSecond);
	friend bool operator> (const MyClass& valueFirst, const MyClass& valueSecond);
	friend MyClass operator++ (MyClass&, int); //постфиксная форма

private:
	MyString stateRegistrationSign_;
	MyString fullDriverName_;
	int numberRoute_;
};
#endif