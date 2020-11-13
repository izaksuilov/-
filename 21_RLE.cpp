//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
using namespace std;
string RLE();

int main()
{
    cout << "Result: " << RLE() << endl;
    return 1;
}

string RLE()
{
    string value, result;
    cout << "Enter the string: ";
    cin >> value;
    if (value.length() < 1)
        return "The string's length should be greater than 0";
    value += '\0';
    char cur = value[0], next;
    int i = 0, rep = 1;
    while (i < value.length() - 1)
    {
        while (cur == (next = value[++i]))
        {
            cur = next;
            rep++;
        }
        if (rep > 1)
        {
            result += "(";
            string number = "";
            while (rep)
            {
                number += (rep % 10) + '0';
                rep /= 10;
            }
            for (int l = number.length() - 1; l >= 0; l--)
                result += number[l];
            result += ", ";
            result += cur;
            result += ")";
        }
        else
            result += cur;
        cur = next;
        rep = 1;
    }
    return result;
}