#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	int x = -1; //Переменная отвечающая за последовательность
	int c = 0; //Переменная отвечающая за предыдущий элемент
	int i = 1; //Счетчик
	int k = 0;
	int maxValue = INT_MIN;
	std::cout << "Введите набор чисел: \n";
	while (true)
	{
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cout << "Вы не ввели набор целых чисел!\n";
			std::cin.clear();
			std::cin.get();
			continue;
		}
		else
		{
			if (x == 0)
			{
				if (k == 0)
				{
					std::cout << "0";
					break;
				}
				maxValue = i;
				std::cout << "Наибольшая длина: " << maxValue << std::endl;
				break;
			}

			k++;
			if (k != 1)
			{
				if (x < c)
				{
					i++;
				}
				else if (x == 0 && c == 1 && x < c)
				{
					maxValue = i;
					std::cout << "Наибольшая длина: " << maxValue << std::endl;
				}
				else
				{
					if (i > maxValue)
					{
						maxValue = i;
					}
				}
			}
			c = x;
		}

	}

	return 0;
}
