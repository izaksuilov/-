//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

vector<bool> EliasOmega(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = EliasOmega(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения омега-кода Элайеса
vector<bool> EliasOmega(unsigned num)
{
    vector<bool> bin = ToBinary(num), result;
    result.push_back(0);
    while (num != 1)
    {
        //приписываем двоичное предаствление числа слева
        for (int i = 0; i < bin.size(); i++)
            result.insert(result.begin(), bin[i]);
        num = bin.size() - 1;
        bin = ToBinary(num);
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
        EliasOmega(1) == vector<bool>{0}&&
        EliasOmega(2) == vector<bool>{1, 0, 0}&&
        EliasOmega(3) == vector<bool>{1, 1, 0}&&
        EliasOmega(4) == vector<bool>{1, 0, 1, 0, 0, 0}&&
        EliasOmega(5) == vector<bool>{1, 0, 1, 0, 1, 0}&&
        EliasOmega(6) == vector<bool>{1, 0, 1, 1, 0, 0}&&
        EliasOmega(7) == vector<bool>{1, 0, 1, 1, 1, 0}&&
        EliasOmega(8) == vector<bool>{1, 1, 1, 0, 0, 0, 0}&&
        EliasOmega(9) == vector<bool>{1, 1, 1, 0, 0, 1, 0}&&
        EliasOmega(10) == vector<bool>{1, 1, 1, 0, 1, 0, 0}&&
        EliasOmega(11) == vector<bool>{1, 1, 1, 0, 1, 1, 0}&&
        EliasOmega(12) == vector<bool>{1, 1, 1, 1, 0, 0, 0}&&
        EliasOmega(13) == vector<bool>{1, 1, 1, 1, 0, 1, 0}&&
        EliasOmega(14) == vector<bool>{1, 1, 1, 1, 1, 0, 0}&&
        EliasOmega(15) == vector<bool>{1, 1, 1, 1, 1, 1, 0}&&
        EliasOmega(16) == vector<bool>{1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}&&
        EliasOmega(17) == vector<bool>{1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0}&&
        EliasOmega(32) == vector<bool>{1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}&&
        EliasOmega(100) == vector<bool>{1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0}&&
        EliasOmega(127) == vector<bool>{1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}