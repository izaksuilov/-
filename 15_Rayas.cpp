//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

vector<bool> Rayas(unsigned num, unsigned m);
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
    vector<bool> result = Rayas(num, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения кода Райса
vector<bool> Rayas(unsigned num, unsigned k)
{
    vector<bool> bin = ToBinary(num), result;
    int m = pow(2, k);
    //приписываем слева унарный код num / m
    for (int i = 0; i < num / m; i++)
        result.push_back(1);
    result.push_back(0);
    //приписываем справа бинарный код num % m
    //который занимает floor(num/m)+k+1 бит
    bin = ToBinary(num % m);
    bin.resize(floor(num / m) + k + 1 - result.size());
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
        Rayas(0, 0) == vector<bool>{0}&&
        Rayas(0, 1) == vector<bool>{0, 0}&&
        Rayas(0, 2) == vector<bool>{0, 0, 0}&&
        Rayas(0, 3) == vector<bool>{0, 0, 0, 0}&&
        Rayas(0, 4) == vector<bool>{0, 0, 0, 0, 0}&&

        Rayas(1, 0) == vector<bool>{1, 0}&&
        Rayas(1, 1) == vector<bool>{0, 1}&&
        Rayas(1, 2) == vector<bool>{0, 0, 1}&&
        Rayas(1, 3) == vector<bool>{0, 0, 0, 1}&&
        Rayas(1, 4) == vector<bool>{0, 0, 0, 0, 1}&&

        Rayas(2, 0) == vector<bool>{1, 1, 0}&&
        Rayas(2, 1) == vector<bool>{1, 0, 0}&&
        Rayas(2, 2) == vector<bool>{0, 1, 0}&&
        Rayas(2, 3) == vector<bool>{0, 0, 1, 0}&&
        Rayas(2, 4) == vector<bool>{0, 0, 0, 1, 0}&&

        Rayas(3, 0) == vector<bool>{1, 1, 1, 0}&&
        Rayas(3, 1) == vector<bool>{1, 0, 1}&&
        Rayas(3, 2) == vector<bool>{0, 1, 1}&&
        Rayas(3, 3) == vector<bool>{0, 0, 1, 1}&&
        Rayas(3, 4) == vector<bool>{0, 0, 0, 1, 1}&&

        Rayas(4, 0) == vector<bool>{1, 1, 1, 1, 0}&&
        Rayas(4, 1) == vector<bool>{1, 1, 0, 0}&&
        Rayas(4, 2) == vector<bool>{1, 0, 0, 0}&&
        Rayas(4, 3) == vector<bool>{0, 1, 0, 0}&&
        Rayas(4, 4) == vector<bool>{0, 0, 1, 0, 0}&&

        Rayas(5, 0) == vector<bool>{1, 1, 1, 1, 1, 0}&&
        Rayas(5, 1) == vector<bool>{1, 1, 0, 1}&&
        Rayas(5, 2) == vector<bool>{1, 0, 0, 1}&&
        Rayas(5, 3) == vector<bool>{0, 1, 0, 1}&&
        Rayas(5, 4) == vector<bool>{0, 0, 1, 0, 1}&&

        Rayas(6, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 0}&&
        Rayas(6, 1) == vector<bool>{1, 1, 1, 0, 0}&&
        Rayas(6, 2) == vector<bool>{1, 0, 1, 0}&&
        Rayas(6, 3) == vector<bool>{0, 1, 1, 0}&&
        Rayas(6, 4) == vector<bool>{0, 0, 1, 1, 0}&&

        Rayas(7, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(7, 1) == vector<bool>{1, 1, 1, 0, 1}&&
        Rayas(7, 2) == vector<bool>{1, 0, 1, 1}&&
        Rayas(7, 3) == vector<bool>{0, 1, 1, 1}&&
        Rayas(7, 4) == vector<bool>{0, 0, 1, 1, 1}&&

        Rayas(8, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(8, 1) == vector<bool>{1, 1, 1, 1, 0, 0}&&
        Rayas(8, 2) == vector<bool>{1, 1, 0, 0, 0}&&
        Rayas(8, 3) == vector<bool>{1, 0, 0, 0, 0}&&
        Rayas(8, 4) == vector<bool>{0, 1, 0, 0, 0}&&

        Rayas(9, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(9, 1) == vector<bool>{1, 1, 1, 1, 0, 1}&&
        Rayas(9, 2) == vector<bool>{1, 1, 0, 0, 1}&&
        Rayas(9, 3) == vector<bool>{1, 0, 0, 0, 1}&&
        Rayas(9, 4) == vector<bool>{0, 1, 0, 0, 1}&&

        Rayas(10, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(10, 1) == vector<bool>{1, 1, 1, 1, 1, 0, 0}&&
        Rayas(10, 2) == vector<bool>{1, 1, 0, 1, 0}&&
        Rayas(10, 3) == vector<bool>{1, 0, 0, 1, 0}&&
        Rayas(10, 4) == vector<bool>{0, 1, 0, 1, 0}&&

        Rayas(11, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(11, 1) == vector<bool>{1, 1, 1, 1, 1, 0, 1}&&
        Rayas(11, 2) == vector<bool>{1, 1, 0, 1, 1}&&
        Rayas(11, 3) == vector<bool>{1, 0, 0, 1, 1}&&
        Rayas(11, 4) == vector<bool>{0, 1, 0, 1, 1}&&

        Rayas(12, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(12, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 0, 0}&&
        Rayas(12, 2) == vector<bool>{1, 1, 1, 0, 0, 0}&&
        Rayas(12, 3) == vector<bool>{1, 0, 1, 0, 0}&&
        Rayas(12, 4) == vector<bool>{0, 1, 1, 0, 0}&&

        Rayas(13, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(13, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 0, 1}&&
        Rayas(13, 2) == vector<bool>{1, 1, 1, 0, 0, 1}&&
        Rayas(13, 3) == vector<bool>{1, 0, 1, 0, 1}&&
        Rayas(13, 4) == vector<bool>{0, 1, 1, 0, 1}&&

        Rayas(14, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(14, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 0, 0}&&
        Rayas(14, 2) == vector<bool>{1, 1, 1, 0, 1, 0}&&
        Rayas(14, 3) == vector<bool>{1, 0, 1, 1, 0}&&
        Rayas(14, 4) == vector<bool>{0, 1, 1, 1, 0}&&

        Rayas(15, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(15, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 0, 1}&&
        Rayas(15, 2) == vector<bool>{1, 1, 1, 0, 1, 1}&&
        Rayas(15, 3) == vector<bool>{1, 0, 1, 1, 1}&&
        Rayas(15, 4) == vector<bool>{0, 1, 1, 1, 1}&&

        Rayas(16, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(16, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 0, 0}&&
        Rayas(16, 2) == vector<bool>{1, 1, 1, 1, 0, 0, 0}&&
        Rayas(16, 3) == vector<bool>{1, 1, 0, 0, 0, 0}&&
        Rayas(16, 4) == vector<bool>{1, 0, 0, 0, 0, 0}&&

        Rayas(17, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(17, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 0, 1}&&
        Rayas(17, 2) == vector<bool>{1, 1, 1, 1, 0, 0, 1}&&
        Rayas(17, 3) == vector<bool>{1, 1, 0, 0, 0, 1}&&
        Rayas(17, 4) == vector<bool>{1, 0, 0, 0, 0, 1}&&

        Rayas(18, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(18, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}&&
        Rayas(18, 2) == vector<bool>{1, 1, 1, 1, 0, 1, 0}&&
        Rayas(18, 3) == vector<bool>{1, 1, 0, 0, 1, 0}&&
        Rayas(18, 4) == vector<bool>{1, 0, 0, 0, 1, 0}&&

        Rayas(19, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(19, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}&&
        Rayas(19, 2) == vector<bool>{1, 1, 1, 1, 0, 1, 1}&&
        Rayas(19, 3) == vector<bool>{1, 1, 0, 0, 1, 1}&&
        Rayas(19, 4) == vector<bool>{1, 0, 0, 0, 1, 1}&&

        Rayas(20, 0) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        Rayas(20, 1) == vector<bool>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}&&
        Rayas(20, 2) == vector<bool>{1, 1, 1, 1, 1, 0, 0, 0}&&
        Rayas(20, 3) == vector<bool>{1, 1, 0, 1, 0, 0}&&
        Rayas(20, 4) == vector<bool>{1, 0, 0, 1, 0, 0}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}