#include <iostream>
#include <string>
#include <fstream>

bool floatingPointNumber(std::string str, std::string mant, std::string ord);
bool isMantissa(std::string mant);
bool isNumber(std::string& str);
bool isSign(std::string& str);
bool noSignInteger(std::string str);
bool isOrder(std::string ord);

int main() 
{
	setlocale(LC_ALL, "Russian");

	std::ifstream fin;
	std::string str;
	std::string mant = "";
	std::string ord = "";
	fin.open("input.txt");
	if (!fin)
	{
		std::cout << "Файл не открылся для чтения.";
	}
	while (!fin.eof()) 
	{
		fin >> str;

		bool flag1 = true;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == 'E')
			{
				ord += str[i];
			}
			else
			{
				mant += str[i];
			}
		}
		
		std::cout << str << " | ";
		std::cout << (floatingPointNumber(str, mant, ord) ? "ДА" : "НЕТ") << std::endl;
		mant = "";
		ord = "";
	}
	fin.close();
	return 0;
}

bool floatingPointNumber(std::string str, std::string mant, std::string ord)
{
	if (isOrder(ord) && isMantissa(mant) && isSign(str) || isMantissa(mant) && isOrder(ord))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool isMantissa(std::string mant)
{
	std::string beforePoint = "";
	std::string afterPoint = "";
	bool flag = true;
	for (int i = 0; i < mant.length(); i++)
	{
		if (mant[i] == '.')
		{
			flag = false;
		}

		if (flag)
		{
			beforePoint += mant[i];
		}
		else
		{
			if (mant[i] != '.')
			{
				afterPoint += mant[i];
			}
		}
	}
	if ((noSignInteger(afterPoint)) || noSignInteger(beforePoint) && noSignInteger(afterPoint))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isOrder(std::string ord)
{
	if (ord[0] == 'E')
	{
		ord.erase(0, 1);
		if ((isSign(ord) && noSignInteger(ord)) || noSignInteger(ord))
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	return false;
}

bool noSignInteger(std::string str)
{
	if (isNumber(str))
	{
		noSignInteger(str);
		return true;
	}
	else
	{
		return false;
	}
}

bool isNumber(std::string& str)
{
	if (str[0] >= '0' && str[0] <= '9')
	{
		str.erase(0, 1);

		return true;
	}
	return false;
}

bool isSign(std::string& str)
{
	if (str[0] == '+' || str[0] == '-')
	{
		str.erase(0, 1);

		return true;
	}
	else
	{
		return false;
	}
}