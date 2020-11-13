//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

vector<bool> EliasGamma(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    vector<bool> result = EliasGamma(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения гамма-кода Элайеса
vector<bool> EliasGamma(unsigned num)
{
    vector<bool> bin = ToBinary(num), result;
    //приписываем справа нули
    for (int i = 0; i < bin.size() - 1; i++)
        result.push_back(0);
    //приписываем справа двоичное представление числа
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
        EliasGamma(1) == vector <bool> {1}&&
        EliasGamma(2) == vector <bool> {0, 1, 0}&&
        EliasGamma(3) == vector <bool> {0, 1, 1}&&
        EliasGamma(4) == vector <bool> {0, 0, 1, 0, 0}&&
        EliasGamma(5) == vector <bool> {0, 0, 1, 0, 1}&&
        EliasGamma(6) == vector <bool> {0, 0, 1, 1, 0}&&
        EliasGamma(7) == vector <bool> {0, 0, 1, 1, 1}&&
        EliasGamma(8) == vector <bool> {0, 0, 0, 1, 0, 0, 0}&&
        EliasGamma(9) == vector <bool> {0, 0, 0, 1, 0, 0, 1}&&
        EliasGamma(10) == vector <bool> {0, 0, 0, 1, 0, 1, 0}&&
        EliasGamma(11) == vector <bool> {0, 0, 0, 1, 0, 1, 1}&&
        EliasGamma(12) == vector <bool> {0, 0, 0, 1, 1, 0, 0}&&
        EliasGamma(13) == vector <bool> {0, 0, 0, 1, 1, 0, 1}&&
        EliasGamma(14) == vector <bool> {0, 0, 0, 1, 1, 1, 0}&&
        EliasGamma(15) == vector <bool> {0, 0, 0, 1, 1, 1, 1}&&
        EliasGamma(16) == vector <bool> {0, 0, 0, 0, 1, 0, 0, 0, 0}&&
        EliasGamma(17) == vector <bool> {0, 0, 0, 0, 1, 0, 0, 0, 1}&&
        EliasGamma(18) == vector <bool> {0, 0, 0, 0, 1, 0, 0, 1, 0}&&
        EliasGamma(100) == vector <bool> {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}