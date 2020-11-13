//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

vector<bool> LevGamma(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = LevGamma(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения гамма-кода Левенштейна
vector<bool> LevGamma(unsigned num)
{
    if (!num) return vector <bool>(1);
    vector<bool> bin = ToBinary(num), result;
    int i = 0;
    //приписываем справа 0 + бит
    for (i; i < bin.size() - 1; i++)
    {
        result.push_back(0);
        result.push_back(bin[i]);
    }
    //приписываем справа старший бит
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
        LevGamma(0) == vector<bool>{0}&&
        LevGamma(1) == vector<bool>{1}&&
        LevGamma(2) == vector<bool>{0, 0, 1}&&
        LevGamma(3) == vector<bool>{0, 1, 1}&&
        LevGamma(4) == vector<bool>{0, 0, 0, 0, 1}&&
        LevGamma(5) == vector<bool>{0, 1, 0, 0, 1}&&
        LevGamma(13) == vector<bool>{0, 1, 0, 0, 0, 1, 1}&&
        LevGamma(63) == vector<bool>{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1}&&
        LevGamma(129) == vector<bool>{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}