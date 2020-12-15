#include <iostream>
#include <string>
#include <cctype>

#pragma warning(disable : 4996)

std::string stringFunction(std::string &source, std::string &source_2);
char* cstringFunction(char* destination, char* source, char* source_2, int size, int size_2, int count);
void countFunction(const char* pcStringOne, const char* pcStringTwo, int size, int size_2, int& count);

int main()
{
	setlocale(LC_ALL, "ru");

	freopen("input.txt", "r", stdin);

	int sizeOne;
	int sizeTwo;
	int count = 0;

	std::cin >> sizeOne;
	if (std::cin.fail())
	{
		std::cerr << "Ошибка. Попробуйте ещё раз";
	}
	sizeOne++;
	char* pcStringOne = new char[sizeOne];
	getc(stdin);	// getc() - функция возвращает символ из потока ввода.
	gets_s(pcStringOne, sizeOne); //gets_s() - функция считывает символы из стандартного потока ввода до символа новой строки.

	std::cin >> sizeTwo;
	if (std::cin.fail())
	{
		std::cerr << "Ошибка. Попробуйте ещё раз";
	}
	sizeTwo++;
	char* pcStringTwo = new char[sizeTwo];
	getc(stdin);
	gets_s(pcStringTwo, sizeTwo);

	countFunction(pcStringOne, pcStringTwo, sizeOne, sizeTwo, count);
	char* result = new char[count];
	result = cstringFunction(result, pcStringOne, pcStringTwo, sizeOne, sizeTwo, count);
	fclose(stdin);

	freopen("input2.txt", "r", stdin);
	std::string pcOne;
	std::string pcTwo;
	std::string resultString;

	std::getline(std::cin, pcOne); //getline() - функция для ввода данных из потока с типом string
	std::getline(std::cin, pcTwo);
	resultString = stringFunction(pcOne, pcTwo);
	fclose(stdin);

	freopen("output.txt", "w", stdout);

	for (int i = 0; i < count; i++)
	{
		std::cout << result[i];
	}

	std::cout <<'\n'<< resultString;

	fclose(stdout);

	delete[]pcStringOne;
	delete[]pcStringTwo;
	return 0;
}

char* cstringFunction(char* destination, char* source, char* source_2, int size, int size_2, int count)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		bool flag = true;
		for (int j = 0; j < size_2; j++)
		{
			if (source[i] == source_2[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			destination[temp] = source[i];
			temp++;
		}
	}
	for (int i = 0; i < size_2; i++)
	{
		bool flag = true;
		for (int j = 0; j < size; j++)
		{
			if (source_2[i] == source[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			destination[temp] = source_2[i];
			temp++;
		}
	}
	return destination;
}


std::string stringFunction(std::string &source, std::string &source_2)
{
	std::string destination;
	int temp = 0;
	for (int i = 0; i < (int)source.length(); i++)
	{
		bool flag = true;
		for (int j = 0; j < (int)source_2.length(); j++)
		{
			if (source[i] == source_2[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			destination.push_back(source[i]); //push_back() - функция, добавляющая ячейку в стек(обычно используется с vector).
			temp++;
		}
	}
	for (int i = 0; i < (int)source_2.length(); i++)
	{
		bool flag = true;
		for (int j = 0; j < (int)source.length(); j++)
		{
			if (source_2[i] == source[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			destination.push_back(source_2[i]);
			temp++;
		}
	}
	return destination;
	
}

void countFunction(const char* pcStringOne, const char* pcStringTwo, int size, int size_2, int& count)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = true;
		for (int j = 0; j < size_2; j++)
		{
			if (pcStringOne[i] == pcStringTwo[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			count++;
		}
	}
	for (int i = 0; i < size_2; i++)
	{
		bool flag = true;
		for (int j = 0; j < size; j++)
		{
			if (pcStringTwo[i] == pcStringOne[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			count++;
		}
	}
}