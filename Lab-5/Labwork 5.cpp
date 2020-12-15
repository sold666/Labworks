#include <iostream>
#include <fstream>
#include <iomanip>

const int ROW = 4;
const int COL = 5;

void decideFunctionOne(int arr[][COL], const int row, const int col);

void decideFunctionTwo(int** arr, const int size);

int** createDynamicArray(int size);

void  outChapterOne();

void outChapterTwo();

void createRowsAndCols(int** arr, int size, int m);


int main()
{
	setlocale(LC_ALL, "ru");
	{
		outChapterOne();
	}

	{
		outChapterTwo();
	}
	return 0;
}

void decideFunctionOne(int arr[][COL], const int row, const int col)
{
	int count = 0;
	int numberСol = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (!arr[i][j]) 
			{
				++count;
				break;
			}
		}
	}
	std::cout << count;
}

void decideFunctionTwo(int** arr, const int size)
{
	std::ofstream fout;
	fout.open("output.txt");

	fout << "Ответ к второй части:" << std::endl;
	int m = 1;

	createRowsAndCols(arr, size, m);

	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - 1; j++) 
		{
			fout << std::setw(3) << arr[i][j] << " ";
		}
		fout << std::setw(3) <<  arr[i][size - 1] << std::endl;
	}
	fout.close();
}

int** createDynamicArray(int size)
{
	int** dynamicArr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dynamicArr[i][j] = 0;
		}
	}
	return dynamicArr;
}

void outChapterOne()
{
	std::ifstream fin;
	fin.open("input.txt");

	int arr[ROW][COL];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			fin >> arr[i][j];
			if (fin.fail())
			{
				std::cout << "Ошибка. Попробуйте еще раз";
				exit(1);
			}
		}
	}

	std::cout << "Ответ к первой части:" << std::endl;
	decideFunctionOne(arr, ROW, COL);
	fin.close();
}

void outChapterTwo()
{
	int size;

	std::ifstream fin;
	fin.open("input2.txt");
	std::cout << "\n";
	fin >> size;
	if (fin.fail() || size < 0)
	{
		std::cout << "Ошибка. Попробуйте еще раз";
		exit(1);
	}

	int** dynamicArr = createDynamicArray(size);
	decideFunctionTwo(dynamicArr, size);
	delete[]dynamicArr;
	fin.close();
}

void createRowsAndCols(int** arr, int size, int m)
{
	if (size % 2 != 0)
	{
		arr[(size / 2)][(size / 2)] = size * size;
		std::cout << '\n' << arr[(size / 2)][(size / 2)];     // Если число нечетное, то находим центр матрицы
	}
	for (int i = 0; i < (size / 2); i++)
	{
		for (int j = i; j < (size - i); j++)
		{
			arr[i][j] = m;
			std::cout << '\t' << arr[i][j] ;
			m++;
		}
		for (int j = 1; j < (size - i - i); j++)
		{
			arr[(j + i)][(size - i) - 1] = m;
			std::cout << '\n' << arr[(j + i)][(size - i) - 1];
			m++;
		}
		for (int j = (size - 2) - i; j >= i; j--)
		{
			arr[(size - i) - 1][j] = m;
			std::cout << '\t' << arr[(size - i) - 1][j];
			m++;
		}
		for (int j = ((size - i) - 2); j > i; j--)
		{
			arr[j][i] = m;
			std::cout << '\n' << arr[j][i];
			m++;
		}
	}
}