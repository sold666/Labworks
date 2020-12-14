#include "MyClass.h"
#include "MyString.h"

MyClass::MyClass() 
{
	stateRegistrationSign_ = MyString();
	fullDriverName_ = MyString();
	numberRoute_ = 0;
}

MyClass::MyClass(int numberRoute, const MyString& stateRegistrationSign, const MyString& fullDriverName)
{
	setStateRegistrationSign(stateRegistrationSign);
	setNumberRoute(numberRoute);
	setFullDriverName(fullDriverName);
}

MyClass::MyClass(const MyClass& copyValue) 
{
	fullDriverName_ = copyValue.fullDriverName_;
	numberRoute_ = copyValue.numberRoute_;
	stateRegistrationSign_ = copyValue.stateRegistrationSign_;
}

MyClass::~MyClass() 
{

}

bool MyClass::operator< (int& value)
{
	if (this->numberRoute_ < value)
		return true;
	return false;
}

bool MyClass::operator<(MyString& string)
{
	return false;
}

MyClass MyClass:: operator+ (const MyClass& other)
{
	MyClass temp;
	temp.numberRoute_ = this->numberRoute_ + other.numberRoute_;
	temp.fullDriverName_ = this->fullDriverName_ + other.fullDriverName_;
	temp.stateRegistrationSign_ = this->stateRegistrationSign_ + other.stateRegistrationSign_;
	return temp;
}

MyClass& MyClass:: operator++() 
{
	this->numberRoute_++;
	return *this;
}

MyClass operator++(MyClass& value, int indicator)
{
	MyClass temp = value;
	value.numberRoute_++;
	return temp;
}

MyClass& MyClass::operator= (const MyClass& other) 
{
	fullDriverName_ = other.fullDriverName_;
	numberRoute_ = other.numberRoute_;
	stateRegistrationSign_ = other.stateRegistrationSign_;
	return *this;
}

bool operator==(MyClass& valueFirst, MyClass& valueSecond)
{
	if (valueFirst.numberRoute_ == valueSecond.numberRoute_ 
		&& valueFirst.fullDriverName_ == valueSecond.fullDriverName_ 
		&& valueFirst.stateRegistrationSign_ == valueSecond.stateRegistrationSign_)
		return true;
	return false;
}

std::istream& operator>> (std::istream& in, MyClass& value)
{
	in >> value.stateRegistrationSign_;
	in >> value.fullDriverName_;
	in >> value.numberRoute_;

	return in;
}

std::ostream& operator<< (std::ostream& out, MyClass& value)
{
	out << value.getNumberRoute();
	out << value.getFullDriverName();
	out << value.getStateRegistrationSign();
	return out;
}

bool operator>(const MyClass& valueFirst, int& valueSecond)
{
	if (valueFirst.numberRoute_ > valueSecond)
		return true;
	return false;
}

bool operator>(const MyClass& valueFirst, const MyClass& valueSecond)
{
	if (valueFirst.numberRoute_ > valueSecond.numberRoute_)
		return true;
	return false;
}

void MyClass::setStateRegistrationSign(const MyString& stateRegist)
{
	stateRegistrationSign_ = stateRegist;
}

void MyClass::setNumberRoute(int numberRoute)
{
	numberRoute_ = numberRoute;
}

void MyClass::setFullDriverName(const MyString& fullName)
{
	fullDriverName_ = fullName;
}

MyString& MyClass::getStateRegistrationSign()
{
	return stateRegistrationSign_;
}

int MyClass::getNumberRoute()
{
	return numberRoute_;
}

int MyClass::getRegion()
{
	int region = 0;
	MyString ob;
	if (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 3]) > 0 &&
		ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 3]) < 10)
	{
		
		region += (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 3]) * 100);
	}
	if (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 2]) > 0 &&
		ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 2]) < 10)
	{

		region += (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 2]) * 10);
	}
	if (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 1]) > 0 &&
		ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 1]) < 10)
	{
		region += (ob.atoiMy(stateRegistrationSign_[stateRegistrationSign_.getSizeString() - 1]));
	}
	return region;
}

MyString& MyClass::getFullDriverName()
{
	return fullDriverName_;
}
