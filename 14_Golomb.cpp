//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

vector<bool> Golomb(unsigned num, unsigned m);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num, m;
    cout << "Enter N: ";
    cin >> num;
    cout << "Enter M: ";
    cin >> m;
    if (m < 1)
    {
        cout << "The second paramenter should be greater than 0";
        return -1;
    }
    cout << "Result is: ";
    vector<bool> result = Golomb(num, m);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения кода Голомба
vector<bool> Golomb(unsigned num, unsigned m)
{
    vector<bool> bin = ToBinary(num), result;
    //приписываем слева унарный код num / m
    for (int i = 0; i < num / m; i++)
        result.push_back(1);
    result.push_back(0);
    //проверяем на степень двойки
    if ((m & (m - 1)) == 0)
    {
        //приписываем справа бинарный код num % m
        //который занимает log2(m) бит
        bin = ToBinary(num % m);
        bin.resize(log2(m));
        for (int i = bin.size() - 1; i >= 0; i--)
            result.push_back(bin[i]);
    }
    else
    {
        int r = num % m, b = (int) ceil(log2(m));
        if (r < pow(2, b) - m)
        {
            //приписываем справа бинарный код r
            //который занимает b-1 бит
            bin = ToBinary(r);
            bin.resize(b - 1);
            for (int i = bin.size() - 1; i >= 0; i--)
                result.push_back(bin[i]);
        }
        else
        {
            //приписываем справа бинарный код r + (pow(2, b) - m)
            //который занимает b бит
            bin = ToBinary(r + (pow(2, b) - m));
            bin.resize(b);
            for (int i = bin.size() - 1; i >= 0; i--)
                result.push_back(bin[i]);
        }
    }
    return result;
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
//Чтобы запустить тест нужен стандарт c++11 из-за инициализации векторов
//Можно было сделать по-другому или декодер, но мне лень
bool Test()
{
    if (
        Golomb(0, 1) == vector<bool>{0}&&
        Golomb(0, 2) == vector<bool>{0, 0}&&
        Golomb(0, 3) == vector<bool>{0, 0}&&
        Golomb(0, 4) == vector<bool>{0, 0, 0}&&
        Golomb(0, 5) == vector<bool>{0, 0, 0}&&
        Golomb(0, 6) == vector<bool>{0, 0, 0}&&
        Golomb(0, 8) == vector<bool>{0, 0, 0, 0}&&

        Golomb(1, 1) == vector<bool>{1, 0}&&
        Golomb(1, 2) == vector<bool>{0, 1}&&
        Golomb(1, 3) == vector<bool>{0, 1, 0}&&
        Golomb(1, 4) == vector<bool>{0, 0, 1}&&
        Golomb(1, 5) == vector<bool>{0, 0, 1}&&
        Golomb(1, 6) == vector<bool>{0, 0, 1}&&
        Golomb(1, 8) == vector<bool>{0, 0, 0, 1}&&

        Golomb(2, 1) == vector<bool>{1, 1, 0}&&
        Golomb(2, 2) == vector<bool>{1, 0, 0}&&
        Golomb(2, 3) == vector<bool>{0, 1, 1}&&
        Golomb(2, 4) == vector<bool>{0, 1, 0}&&
        Golomb(2, 5) == vector<bool>{0, 1, 0}&&
        Golomb(2, 6) == vector<bool>{0, 1, 0, 0}&&
        Golomb(2, 8) == vector<bool>{0, 0, 1, 0}&&

        Golomb(8, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Golomb(8, 2) == vector<bool>{1, 1, 1, 1, 0, 0}&&
        Golomb(8, 3) == vector<bool>{1, 1, 0, 1, 1}&&
        Golomb(8, 4) == vector<bool>{1, 1, 0, 0, 0}&&
        Golomb(8, 5) == vector<bool>{1, 0, 1, 1, 0}&&
        Golomb(8, 6) == vector<bool>{1, 0, 1, 0, 0}&&
        Golomb(8, 8) == vector<bool>{1, 0, 0, 0, 0}&&

        Golomb(17, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Golomb(17, 2) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 0, 1}&&
        Golomb(17, 3) == vector<bool>{1, 1, 1, 1, 1, 0, 1, 1}&&
        Golomb(17, 4) == vector<bool>{1, 1, 1, 1, 0, 0, 1}&&
        Golomb(17, 5) == vector<bool>{1, 1, 1, 0, 1, 0}&&
        Golomb(17, 6) == vector<bool>{1, 1, 0, 1, 1, 1}&&
        Golomb(17, 8) == vector<bool>{1, 1, 0, 0, 0, 1}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}