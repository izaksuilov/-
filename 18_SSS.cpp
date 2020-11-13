//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

bool SSS();
vector<bool> ToBinary(unsigned num);
//массив кодовых слов
vector<string> words; vector<int> minvalues;
int main()
{
    SSS();
    char answer;
    cout << "Show words? [y|n] ";
    cin >> answer;
    if (answer == 'Y' || answer == 'y')
        for (int i = 0; i < words.size(); i++)
        {
            int n = 0, q = 0; long f = 0; long long decode = 0, code = 0, z = 1;
            while (n++, words[i][q++] != '0');
            string h = words[i].substr(n);
            for (int k = h.length() - 1; k >= 0; k--, z *= 10)
                code += z * (int) (h[k] - '0');
            do decode += (code % 10) * pow(2, f++);
            while ((code /= 10) > 0);
            cout << "Word number " << i + 1 << " is: " << words[i] 
                 << " -- Decode: " << decode + minvalues[n - 1] << endl;
        }
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения старт-шаг-стоп кодов
bool SSS()
{
    unsigned i, j, k, l = 0;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    cout << "Enter k: ";
    cin >> k;
    if (k < i)
    {
        cout << "Parameter k should be greater than i" << endl;
        return false;
    }
    int maxvalue = 0;
    for (i; i <= k; i += j, l++)
    {
        //красивый вывод
        string output = "\n";
        for (int u = 0; u < l; u++)
            output += "1";
        output += "0";
        for (int u = 0; u < i; u++)
            output += "x";
        output += " -- [";
        string number = "";
        int minvalue = maxvalue + 1;
        minvalues.push_back(minvalue);
        while (minvalue)
        {
            number += (minvalue % 10) + '0';
            minvalue /= 10;
        }
        for (int z = number.length() - 1; z >= 0; z--)
            output += number[z];

        //непосресдственно вычисления
        for (int o = 0; o < pow(2, i); o++)
        {
            vector<bool> bin, result;
            bin = ToBinary(o);
            bin.resize(i);
            for (int u = 0; u < l; u++)
                result.push_back(1);
            result.push_back(0);
            for (int i = bin.size() - 1; i >= 0; i--)
                result.push_back(bin[i]);
            //переводим в строку
            string s = "";
            for (int i = 0; i < result.size(); i++)
                s += (int) result[i] + '0';
            words.push_back(s);
            maxvalue++;
        }
        //красивый вывод
        output += "..";
        number = "";
        int temp = maxvalue;
        while (temp)
        {
            number += (temp % 10) + '0';
            temp /= 10;
        }
        for (int l = number.length() - 1; l >= 0; l--)
            output += number[l];
        output += "]";
        cout << output << endl;
    }
    return true;
}
//Функция возвращает перевод числа 
//в двоичную систему
vector<bool> ToBinary(unsigned num)
{
    vector<bool> result;
    while (num)
    {
        result.push_back(num % 2);
        num /= 2;
    }
    return result;
}