//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#define MAX_VALUE 36288000
#define MIN_VALUE 0
#include <iostream>
#include <conio.h>
using namespace std;

unsigned long long FactToDec(unsigned long long);
unsigned long long DecToFact(unsigned long long);
bool Test();

int main()
{
    unsigned long long num, decoded, result;
    cout << "Enter the number: ";
    cin >> num;
    result = DecToFact(num);
    cout << "\nThe code is: " << result << endl;
    decoded = FactToDec(result);
    cout << "\nInput number: " << num << "\nDecoded:      " << decoded << endl
        << (decoded == num ? "The numbers are equal!" : "The numbers are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}

//Функция перевода из факториальной в десятичную систему счисления.
//Функция работает от 0 до 36288000 включительно.
unsigned long long FactToDec(unsigned long long factNum)
{
    long i = 1; long long result = 0; unsigned long long fact = 1;
    do result += (factNum % 10) * (fact *= i++);
    while ((factNum /= 10) > 0);
    return result;
}

//Функция перевода из десятичной в факториальную систему счисления.
//Функция работает от 0 до 36288000 включительно.
unsigned long long DecToFact(unsigned long long decNum)
{
    long x = 2; unsigned long long result = 0, i = 1;
    while (decNum != 0)
    {
        result += i * (decNum % x);
        i *= 10;
        decNum /= x++;
    }
    return result;
}

bool Test()
{
    cout << "Testing...\n";
    for (unsigned long long i = MIN_VALUE; i < MAX_VALUE; i++)
        if (FactToDec(DecToFact(i)) != i)
        {
            cout << "Something went wrong at value: " << i << endl;
            return false;
        }
    cout << "Test completed successfully!" << endl;
    return true;
}
