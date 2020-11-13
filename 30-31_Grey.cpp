//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#define MAX_VALUE 100
#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
using namespace std;
unsigned BinToGrey(unsigned num);
unsigned GreyToBin(unsigned num);
string ToBinary(unsigned num);
bool Test();

int main()
{
    cout.setf(ios_base::boolalpha);
    unsigned value;
    cout << "Enter the value: ";
    cin >> value;
    cout << "Binary code: " << ToBinary(value) << endl;
    cout << "Grey code: " << ToBinary(BinToGrey(value)) << endl;
    if (ToBinary(GreyToBin(BinToGrey(value))) != ToBinary(value))
        cout << "Test failed!" << endl;
    cout << "Test completed succesfully!\n" << endl;
    cout << "Global test completed with result: " << Test() << endl;
    _getch();
    return 0;
}

unsigned BinToGrey(unsigned num)
{
    return num ^ (num >> 1);
}

unsigned GreyToBin(unsigned num)
{
    for (int i = 0; (1 << i) < floor(log2(num)) + 1; i++)
        num ^= num >> (1 << i);
    return num;
}
//Функция возвращает перевод числа 
//в двоичную систему
string ToBinary(unsigned num)
{
    vector<bool> result;
    while (num)
    {
        result.insert(result.begin(), num % 2);
        num /= 2;
    }
    //переводим в строку
    string s = "";
    for (int i = 0; i < result.size(); i++)
        s += (int) result[i] + '0';
    return s;
}

bool Test()
{
    for (unsigned i = 0; i < MAX_VALUE; i++)
        if (ToBinary(GreyToBin(BinToGrey(i))) != ToBinary(i))
            return false;
    return true;
}
