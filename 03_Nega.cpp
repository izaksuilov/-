//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#define DEC_MAX_VALUE 349525
#define DEC_MIN_VALUE -699050
#define NEG_MAX_VALUE 1111111111111111111
#define NEG_MIN_VALUE 0
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

unsigned long long DecToNeg(long long);
long long NegToDec(unsigned long long);
bool CorrectArgument(unsigned long long);
bool Test();

int main()
{
    unsigned long long num, decoded, result;
    cout << "Enter the number: ";
    cin >> num;
    result = DecToNeg(num);
    cout << "\nThe code is: " << result << endl;
    decoded = NegToDec(result);
    cout << "\nInput number: " << num << "\nDecoded:      " << decoded << endl
        << (decoded == num ? "The numbers are equal!" : "The numbers are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}

//Функция проверяющая, что введено корректное значение
bool CorrectArgument(unsigned long long arg)
{
    while (arg)
    {
        if (arg % 10 != 0 && arg % 10 != 1)
            return false;
        arg /= 10;
    }
    return true;
}

//Функция перевода из нега-двоичной в десятичную систему счисления.
//Функция работает от 0 до 1111111111111111111 включительно.
long long NegToDec(unsigned long long negNum)
{
    if (!CorrectArgument(negNum))
        return -1;

    long i = 0; long long result = 0;
    do result += (negNum % 10) * pow(-2, i++);
    while ((negNum /= 10) > 0);
    return result;
}

//Функция перевода из нега-двоичной в десятичную систему счисления.
//Функция работает при значениях от -699050 до 349525 включительно.
unsigned long long DecToNeg(long long decNum)
{
    short reminder; unsigned long long result = 0, i = 1;
    while (decNum != 0)
    {
        result += i * abs(reminder = decNum % -2);
        i *= 10;
        decNum /= -2;
        if (reminder < 0)
            decNum += 1;
    }
    return result;
}
bool Test()
{
    cout << "Testing...\n";
    for (long long i = NEG_MIN_VALUE; i <= DEC_MAX_VALUE; i++)
        if (NegToDec(DecToNeg(i)) != i)
        {
            cout << "Something went wrong at value: " << i << endl;
            return false;
        }
    cout << "Test completed successfully!" << endl;
    return true;
}

