//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

vector<bool> Fib(unsigned num);
vector<bool> ToFib(int num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = Fib(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения кода Фибонначи
vector<bool> Fib(unsigned num)
{
    if (!num) return vector<bool>(1);
    vector<bool> fib = ToFib(num);
    fib.push_back(1);
    return fib;
}
//Функция возвращает перевод числа 
//в фибоначчиву систему задом на перед
vector<bool> ToFib(int num)
{
    vector<bool> result;
    unsigned long long fib = 0;
    while (num)
    {
        unsigned long long i = 1, a = 1, b = 1, c;
        while (a <= num) { c = a, a += b, b = c; i *= 10; }
        num -= b;
        fib += i == 1 ? 1 : i / 10;
    }
    while (fib)
    {
        result.push_back(fib % 10);
        fib /= 10;
    }
    return result;
}
//Чтобы запустить тест нужен стандарт c++11 из-за инициализации векторов
//Можно было сделать по-другому или декодер, но мне лень
bool Test()
{
    if (
        Fib(0) == vector<bool>{0}&&
        Fib(1) == vector<bool>{1, 1}&&
        Fib(2) == vector<bool>{0, 1, 1}&&
        Fib(3) == vector<bool>{0, 0, 1, 1}&&
        Fib(4) == vector<bool>{1, 0, 1, 1}&&
        Fib(5) == vector<bool>{0, 0, 0, 1, 1}&&
        Fib(6) == vector<bool>{1, 0, 0, 1, 1}&&
        Fib(7) == vector<bool>{0, 1, 0, 1, 1}&&
        Fib(8) == vector<bool>{0, 0, 0, 0, 1, 1}&&
        Fib(9) == vector<bool>{1, 0, 0, 0, 1, 1}&&
        Fib(10) == vector<bool>{0, 1, 0, 0, 1, 1}&&
        Fib(550) == vector<bool>{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}