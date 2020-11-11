//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#define DEC_MAX_VALUE 10945
#define DEC_MIN_VALUE 0
#define FIB_MAX_VALUE 10101010101010101010
#define FIB_MIN_VALUE 0
#include <iostream>
#include <conio.h>
using namespace std;

unsigned long long DecToFib(unsigned long long);
unsigned long long FibToDec(unsigned long long);
bool CorrectArgument(unsigned long long);
bool Test();

int main()
{
    unsigned long long num, decoded, result;
    cout << "Enter the number: ";
    cin >> num;
    result = DecToFib(num);
    cout << "\nThe code is: " << result << endl;
    decoded = FibToDec(result);
    cout << "\nInput number: " << num << "\nDecoded:      " << decoded << endl
        << (decoded == num ? "The numbers are equal!" : "The numbers are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}

//Функция перевода из фибоначчивой в десятичную систему счисления.
//Функция работает от 0 до 10101010101010101010 включительно.
unsigned long long FibToDec(unsigned long long fibNum)
{
    if (!CorrectArgument(fibNum))
        return -1;
    unsigned long long a = 1, b = 1, c, result = 0;
    do result += (fibNum % 10) * a;
    while (c = a, a += b, b = c, (fibNum /= 10) > 0);
    return result;
}

//Функция перевода из десятичной в фибоначчиву систему счисления.
//Функция работает от 0 до 10945 включительно.
unsigned long long DecToFib(unsigned long long num)
{
    unsigned long long result = 0;
    while (num != 0)
    {
        unsigned long long i = 1, a = 1, b = 1, c;
        while (a <= num) { c = a, a += b, b = c; i *= 10; }
        num -= b;
        result += i == 1 ? 1 : i / 10;
    }
    return result;
}

//Функция проверяющая, что введено корректное значение.
bool CorrectArgument(unsigned long long arg)
{
    short prev = -1;
    while (arg)
    {
        if ((arg % 10 != 0 && arg % 10 != 1) || (prev == 1 && arg % 10 == prev))
            return false;
        prev = arg % 10;
        arg /= 10;
    }
    return true;
}

bool Test()
{
    cout << "Testing...\n";
    for (long long i = DEC_MIN_VALUE; i < DEC_MAX_VALUE; i++)
        if (FibToDec(DecToFib(i)) != i)
        {
            cout << "Something went wrong at value: " << i << endl;
            return false;
        }
    cout << "Test completed successfully!" << endl;
    return true;
}