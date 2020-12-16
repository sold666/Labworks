#include <fstream>
#include <iomanip>
#include "MyClass.h"
#include "MyString.h"
#include "MyArray.h"
#include "MySort.h"

void printMyArray(MyArray<MyClass>& arr);
void workWithFileAndArray(MyArray<MyClass>& arr);
int maxNumberRoute(MyArray<MyClass>& arr);

int maxNameSize(MyArray<MyClass>& arr);
int maxNumberRouteSize(MyArray<MyClass>& arr);
int maxStateRegSize(MyArray<MyClass>& arr);
int lenNumberRoute(int numb);

int main()
{
    setlocale(LC_ALL, "ru");
    
    MyArray<MyClass> array;
    workWithFileAndArray(array);
    maxNumberRoute(array);
    sort(array, 0);
    printMyArray(array);
}

void workWithFileAndArray(MyArray<MyClass>& arr)
{
    std::ifstream fin;
    MyString nameDriver;
    MyString stateRegSign;
    MyString number;
    MyString fileName;

    while (!fin.is_open())
    {
        do {
            std::cout << "Введите название файла (example.txt): ";
            std::cin >> fileName;
        } while (std::cin.fail());

        fin.open(fileName.getStr());
        if (!fin.is_open())
            std::cerr << "Файл " << fileName << " не открылся. Попробуйте ввести другое имя." << std::endl;
        else
        {
            std::cout << "Файл " << fileName << " открыт!" << std::endl;
        }
    }

    while (!fin.eof())
    {
        fin >> nameDriver;
        fin >> stateRegSign;
        fin >> number;
        
        int rightNumber = number.translateNum(number);
        try
        {
            if (!nameDriver.checkDriverName(nameDriver))
            {
                std::cout << "Имя и фамилия водителя введена неправильно! " << nameDriver << std::endl;
                exit(1);
            }
        }
        catch (char a)
        {
            std::cerr << "Поймано исключение типа char: " << a << '\n';
        }
        try
        {
            if (!(stateRegSign.checkStateRegSign(stateRegSign)))
            {
                std::cout << "Государственный регистрационный номер должен иметь заглавные буквы! " << stateRegSign << std::endl;
                exit(1);
            }
        }
        catch (char a)
        {
            std::cerr << "Поймано исключение типа char: " << a << '\n';
        }

        try
        {
            if (rightNumber < 0)
            {
                std::cout << "Номер маршрута не может быть отрицательным! " << rightNumber << std::endl;
                exit(1);
            }
        }
        catch (int a)
        {
            std::cerr << "Поймано исключение типа int: " << a << '\n';
        }

        MyClass object(rightNumber, stateRegSign.getStr(), nameDriver.getStr());
        arr.push_back(object);
    }
}


int maxNumberRoute(MyArray<MyClass>& arr)
{
    if (arr.isEmpty())
        throw "Массив пуст";
    MyClass maxNumberRoute = arr[arr.getSize() - 1];
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr[i] > maxNumberRoute)
        {
            maxNumberRoute = arr[i];
        }
    }
    return maxNumberRoute.getNumberRoute();
}

void printMyArray(MyArray<MyClass>& arr)
{
    setlocale(LC_ALL, "ru");

    std::cout << "Работа программы была записана в файл: output.txt" << std::endl;
    std::ofstream fout;
    fout.open("output.txt");
    int temp = maxNumberRoute(arr);
    fout << "Максимальный номер маршрута: " << temp << '\n' << std::endl;
    
    int numberRouteSize = (lenNumberRoute(maxNumberRouteSize(arr)) > 17) ? lenNumberRoute(maxNumberRouteSize(arr)) : 17;
    int nameDriverSize = (maxNameSize(arr) > 25) ? maxNameSize(arr) : 25;
    int stateRegistrationSize = (maxStateRegSize(arr) > 29) ? maxStateRegSize(arr) : 29;

    fout << "| Номер маршрута ";

    for (int i = 0; i < numberRouteSize - 17; i++)
    {
        fout << " ";
    }

    fout << "| Фамилия и имя водителя ";
    for (int i = 0; i < nameDriverSize - 25; i++)
    {
        fout << " ";
    }

    fout << "| Гос. регистрационный знак |";
    fout << std::endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
        fout << " ";
        fout << arr[i].getNumberRoute();
        for (int j = 0; j < numberRouteSize - lenNumberRoute(arr[i].getNumberRoute()); j++)
        {
            fout << " ";
        }
        fout << arr[i].getFullDriverName();
        for (int j = 0; j < (nameDriverSize - arr[i].getFullDriverName().getSizeString()); j++)
        {
            fout << " ";
        }
        fout << arr[i].getStateRegistrationSign();
        fout << '\n';
    }
    fout.close();
}

int maxNameSize(MyArray<MyClass>& arr)
{
    int maxValue = 0;
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr[i].getFullDriverName().getSizeString() > maxValue)
        {
            maxValue = arr[i].getFullDriverName().getSizeString();
        }
    }
    return maxValue;
}

int maxStateRegSize(MyArray<MyClass>& arr)
{
    int maxValue = 0;
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr[i].getStateRegistrationSign().getSizeString() > maxValue)
        {
            maxValue = arr[i].getStateRegistrationSign().getSizeString();
        }
    }
    return maxValue;
}

int lenNumberRoute(int numb)
{
    int count = 0;
    while (numb)
    {
        numb /= 10;
        count++;
    }
    return count;
}

int maxNumberRouteSize(MyArray<MyClass>& arr)
{
    int maxValue = 0;
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr[i].getNumberRoute() > maxValue)
        {
            maxValue = arr[i].getNumberRoute();
        }
    }
    return maxValue;
}
