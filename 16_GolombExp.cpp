//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

vector<bool> GolombExp(unsigned num, unsigned k);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num, k;
    cout << "Enter N: ";
    cin >> num;
    cout << "Enter K: ";
    cin >> k;
    cout << "Result is: ";
    vector<bool> result = GolombExp(num, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения экспоненициального кода Голомба
vector<bool> GolombExp(unsigned num, unsigned k)
{
    vector<bool> bin, result;
    int w = 1 + floor(num / pow(2, k)), f = floor(log2(1 + num / pow(2, k)));
    //приписываем слева унарный код f
    for (int i = 0; i < f; i++)
        result.push_back(1);
    result.push_back(0);
    //приписываем справа бинарный код w
    //который занимает f бит
    bin = ToBinary(w);
    bin.resize(f);
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);
    //приписываем справа бинарный код num
    //который занимает k бит
    bin = ToBinary(num);
    bin.resize(k);
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);
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
        GolombExp(0, 0) == vector<bool>{0}&&
        GolombExp(0, 1) == vector<bool>{0, 0}&&
        GolombExp(0, 2) == vector<bool>{0, 0, 0}&&
        GolombExp(0, 3) == vector<bool>{0, 0, 0, 0}&&
        GolombExp(0, 4) == vector<bool>{0, 0, 0, 0, 0}&&
        GolombExp(0, 5) == vector<bool>{0, 0, 0, 0, 0, 0}&&
        GolombExp(0, 6) == vector<bool>{0, 0, 0, 0, 0, 0, 0}&&

        GolombExp(1, 0) == vector<bool>{1, 0, 0}&&
        GolombExp(1, 1) == vector<bool>{0, 1}&&
        GolombExp(1, 2) == vector<bool>{0, 0, 1}&&
        GolombExp(1, 3) == vector<bool>{0, 0, 0, 1}&&
        GolombExp(1, 4) == vector<bool>{0, 0, 0, 0, 1}&&
        GolombExp(1, 5) == vector<bool>{0, 0, 0, 0, 0, 1}&&
        GolombExp(1, 6) == vector<bool>{0, 0, 0, 0, 0, 0, 1}&&

        GolombExp(2, 0) == vector<bool>{1, 0, 1}&&
        GolombExp(2, 1) == vector<bool>{1, 0, 0, 0}&&
        GolombExp(2, 2) == vector<bool>{0, 1, 0}&&
        GolombExp(2, 3) == vector<bool>{0, 0, 1, 0}&&
        GolombExp(2, 4) == vector<bool>{0, 0, 0, 1, 0}&&
        GolombExp(2, 5) == vector<bool>{0, 0, 0, 0, 1, 0}&&
        GolombExp(2, 6) == vector<bool>{0, 0, 0, 0, 0, 1, 0}&&

        GolombExp(3, 0) == vector<bool>{1, 1, 0, 0, 0}&&
        GolombExp(3, 1) == vector<bool>{1, 0, 0, 1}&&
        GolombExp(3, 2) == vector<bool>{0, 1, 1}&&
        GolombExp(3, 3) == vector<bool>{0, 0, 1, 1}&&
        GolombExp(3, 4) == vector<bool>{0, 0, 0, 1, 1}&&
        GolombExp(3, 5) == vector<bool>{0, 0, 0, 0, 1, 1}&&
        GolombExp(3, 6) == vector<bool>{0, 0, 0, 0, 0, 1, 1}&&

        GolombExp(4, 0) == vector<bool>{1, 1, 0, 0, 1}&&
        GolombExp(4, 1) == vector<bool>{1, 0, 1, 0}&&
        GolombExp(4, 2) == vector<bool>{1, 0, 0, 0, 0}&&
        GolombExp(4, 3) == vector<bool>{0, 1, 0, 0}&&
        GolombExp(4, 4) == vector<bool>{0, 0, 1, 0, 0}&&
        GolombExp(4, 5) == vector<bool>{0, 0, 0, 1, 0, 0}&&
        GolombExp(4, 6) == vector<bool>{0, 0, 0, 0, 1, 0, 0}&&

        GolombExp(5, 0) == vector<bool>{1, 1, 0, 1, 0}&&
        GolombExp(5, 1) == vector<bool>{1, 0, 1, 1}&&
        GolombExp(5, 2) == vector<bool>{1, 0, 0, 0, 1}&&
        GolombExp(5, 3) == vector<bool>{0, 1, 0, 1}&&
        GolombExp(5, 4) == vector<bool>{0, 0, 1, 0, 1}&&
        GolombExp(5, 5) == vector<bool>{0, 0, 0, 1, 0, 1}&&
        GolombExp(5, 6) == vector<bool>{0, 0, 0, 0, 1, 0, 1}&&

        GolombExp(6, 0) == vector<bool>{1, 1, 0, 1, 1}&&
        GolombExp(6, 1) == vector<bool>{1, 1, 0, 0, 0, 0}&&
        GolombExp(6, 2) == vector<bool>{1, 0, 0, 1, 0}&&
        GolombExp(6, 3) == vector<bool>{0, 1, 1, 0}&&
        GolombExp(6, 4) == vector<bool>{0, 0, 1, 1, 0}&&
        GolombExp(6, 5) == vector<bool>{0, 0, 0, 1, 1, 0}&&
        GolombExp(6, 6) == vector<bool>{0, 0, 0, 0, 1, 1, 0}&&

        GolombExp(7, 0) == vector<bool>{1, 1, 1, 0, 0, 0, 0}&&
        GolombExp(7, 1) == vector<bool>{1, 1, 0, 0, 0, 1}&&
        GolombExp(7, 2) == vector<bool>{1, 0, 0, 1, 1}&&
        GolombExp(7, 3) == vector<bool>{0, 1, 1, 1}&&
        GolombExp(7, 4) == vector<bool>{0, 0, 1, 1, 1}&&
        GolombExp(7, 5) == vector<bool>{0, 0, 0, 1, 1, 1}&&
        GolombExp(7, 6) == vector<bool>{0, 0, 0, 0, 1, 1, 1}&&

        GolombExp(8, 0) == vector<bool>{1, 1, 1, 0, 0, 0, 1}&&
        GolombExp(8, 1) == vector<bool>{1, 1, 0, 0, 1, 0}&&
        GolombExp(8, 2) == vector<bool>{1, 0, 1, 0, 0}&&
        GolombExp(8, 3) == vector<bool>{1, 0, 0, 0, 0, 0}&&
        GolombExp(8, 4) == vector<bool>{0, 1, 0, 0, 0}&&
        GolombExp(8, 5) == vector<bool>{0, 0, 1, 0, 0, 0}&&
        GolombExp(8, 6) == vector<bool>{0, 0, 0, 1, 0, 0, 0}&&

        GolombExp(9, 0) == vector<bool>{1, 1, 1, 0, 0, 1, 0}&&
        GolombExp(9, 1) == vector<bool>{1, 1, 0, 0, 1, 1}&&
        GolombExp(9, 2) == vector<bool>{1, 0, 1, 0, 1}&&
        GolombExp(9, 3) == vector<bool>{1, 0, 0, 0, 0, 1}&&
        GolombExp(9, 4) == vector<bool>{0, 1, 0, 0, 1}&&
        GolombExp(9, 5) == vector<bool>{0, 0, 1, 0, 0, 1}&&
        GolombExp(9, 6) == vector<bool>{0, 0, 0, 1, 0, 0, 1}&&

        GolombExp(10, 0) == vector<bool>{1, 1, 1, 0, 0, 1, 1}&&
        GolombExp(10, 1) == vector<bool>{1, 1, 0, 1, 0, 0}&&
        GolombExp(10, 2) == vector<bool>{1, 0, 1, 1, 0}&&
        GolombExp(10, 3) == vector<bool>{1, 0, 0, 0, 1, 0}&&
        GolombExp(10, 4) == vector<bool>{0, 1, 0, 1, 0}&&
        GolombExp(10, 5) == vector<bool>{0, 0, 1, 0, 1, 0}&&
        GolombExp(10, 6) == vector<bool>{0, 0, 0, 1, 0, 1, 0}&&

        GolombExp(11, 0) == vector<bool>{1, 1, 1, 0, 1, 0, 0}&&
        GolombExp(11, 1) == vector<bool>{1, 1, 0, 1, 0, 1}&&
        GolombExp(11, 2) == vector<bool>{1, 0, 1, 1, 1}&&
        GolombExp(11, 3) == vector<bool>{1, 0, 0, 0, 1, 1}&&
        GolombExp(11, 4) == vector<bool>{0, 1, 0, 1, 1}&&
        GolombExp(11, 5) == vector<bool>{0, 0, 1, 0, 1, 1}&&
        GolombExp(11, 6) == vector<bool>{0, 0, 0, 1, 0, 1, 1}&&

        GolombExp(12, 0) == vector<bool>{1, 1, 1, 0, 1, 0, 1}&&
        GolombExp(12, 1) == vector<bool>{1, 1, 0, 1, 1, 0}&&
        GolombExp(12, 2) == vector<bool>{1, 1, 0, 0, 0, 0, 0}&&
        GolombExp(12, 3) == vector<bool>{1, 0, 0, 1, 0, 0}&&
        GolombExp(12, 4) == vector<bool>{0, 1, 1, 0, 0}&&
        GolombExp(12, 5) == vector<bool>{0, 0, 1, 1, 0, 0}&&
        GolombExp(12, 6) == vector<bool>{0, 0, 0, 1, 1, 0, 0}&&

        GolombExp(13, 0) == vector<bool>{1, 1, 1, 0, 1, 1, 0}&&
        GolombExp(13, 1) == vector<bool>{1, 1, 0, 1, 1, 1}&&
        GolombExp(13, 2) == vector<bool>{1, 1, 0, 0, 0, 0, 1}&&
        GolombExp(13, 3) == vector<bool>{1, 0, 0, 1, 0, 1}&&
        GolombExp(13, 4) == vector<bool>{0, 1, 1, 0, 1}&&
        GolombExp(13, 5) == vector<bool>{0, 0, 1, 1, 0, 1}&&
        GolombExp(13, 6) == vector<bool>{0, 0, 0, 1, 1, 0, 1}&&

        GolombExp(14, 0) == vector<bool>{1, 1, 1, 0, 1, 1, 1}&&
        GolombExp(14, 1) == vector<bool>{1, 1, 1, 0, 0, 0, 0, 0}&&
        GolombExp(14, 2) == vector<bool>{1, 1, 0, 0, 0, 1, 0}&&
        GolombExp(14, 3) == vector<bool>{1, 0, 0, 1, 1, 0}&&
        GolombExp(14, 4) == vector<bool>{0, 1, 1, 1, 0}&&
        GolombExp(14, 5) == vector<bool>{0, 0, 1, 1, 1, 0}&&
        GolombExp(14, 6) == vector<bool>{0, 0, 0, 1, 1, 1, 0}&&

        GolombExp(15, 0) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0}&&
        GolombExp(15, 1) == vector<bool>{1, 1, 1, 0, 0, 0, 0, 1}&&
        GolombExp(15, 2) == vector<bool>{1, 1, 0, 0, 0, 1, 1}&&
        GolombExp(15, 3) == vector<bool>{1, 0, 0, 1, 1, 1}&&
        GolombExp(15, 4) == vector<bool>{0, 1, 1, 1, 1}&&
        GolombExp(15, 5) == vector<bool>{0, 0, 1, 1, 1, 1}&&
        GolombExp(15, 6) == vector<bool>{0, 0, 0, 1, 1, 1, 1}&&

        GolombExp(16, 0) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 1}&&
        GolombExp(16, 1) == vector<bool>{1, 1, 1, 0, 0, 0, 1, 0}&&
        GolombExp(16, 2) == vector<bool>{1, 1, 0, 0, 1, 0, 0}&&
        GolombExp(16, 3) == vector<bool>{1, 0, 1, 0, 0, 0}&&
        GolombExp(16, 4) == vector<bool>{1, 0, 0, 0, 0, 0, 0}&&
        GolombExp(16, 5) == vector<bool>{0, 1, 0, 0, 0, 0}&&
        GolombExp(16, 6) == vector<bool>{0, 0, 1, 0, 0, 0, 0}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}