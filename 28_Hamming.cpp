//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <conio.h>
using namespace std;

string Hamming(string);
string DecodeHamming(string);
bool Test();

int main()
{
    string input;
    cout << "Enter the string(0, 1): ";
    cin >> input;
    string result = Hamming(input);
    cout << endl << "Hamming code is: " << result << endl;
    string decoded = DecodeHamming(result);
    cout << "\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм Хэмминга
string Hamming(string input)
{
    int i = 0;
    for (i; (1 << i) <= input.length(); i++)//заполняем контрольными битами
        input = input.substr(0, (1 << i) - 1) + string(1, '0') + input.substr((1 << i) - 1);
    for (int j = 0; j < i; j++)//выставляем контрольные биты
    {
        int pow = (1 << j), x = 0;
        for (int k = pow - 1; k < input.length(); k += pow * 2)//контрольный бит с номером N через каждые N бит
            for (int y = 0; y < pow && y + k < input.length(); y++)//контролирует все N бит 
                x += input[k + y] - '0';
        input[pow - 1] = (x % 2) + '0';
    }
    return input;
}

string DecodeHamming(string input)
{
    string decoded = input;
    int j = 0, err = 0;
    while ((1 << j) < input.length())
    {
        int pow = (1 << j), x = 0;
        decoded[pow - 1 - j] = '0';
        for (int k = pow - 1 - j; k < decoded.length(); k += pow * 2)
            for (int y = 0; y < pow && y + k < decoded.length(); y++)
                x += decoded[k + y] - '0';
        err += (x % 2) + '0' == input[pow - 1] ? 0 : pow;
        decoded = decoded.substr(0, pow - 1 - j <= 0 ? 0 : pow - 1 - j) + decoded.substr(pow - j);
        j++;
    }
    if ((err & (err - 1)) && err)// если ошибки нет или ошибка в контрольном бите
        decoded[err - ceil(log2(err)) - 1] = decoded[err - ceil(log2(err)) - 1] == '1' ? '0' : '1';
    return decoded;
}

bool Test()
{
    string randInput = "", encode, err;
    for (int i = 0; i < 1000; i++)
    {
        int j = 0;
        for (j; j < 1 + rand() % 10; j++)
            randInput += (rand() % 2) + '0';
        encode = Hamming(randInput); err = encode;
        if (DecodeHamming(encode) == randInput)
        {
            err[rand() % j] = err[rand() % j] == '1' ? '0' : '1';
            if (DecodeHamming(err) == randInput)
                goto next;
        }
        cout << "\nTest failed." << endl;
        return false;
    next:;
    }
    cout << "Test completed sucessfully!" << endl;
    return true;
}