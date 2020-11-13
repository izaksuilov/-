//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

vector<bool> EvenRodeh(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = EvenRodeh(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения омега-кода Элайеса
vector<bool> EvenRodeh(unsigned num)
{
    vector<bool> bin = ToBinary(num), result;
    result.push_back(0);
    //первые четыре значения заданы особым образом
    if (num < 4)
    {
        result.resize(3 - bin.size());
        for (int i = bin.size() - 1; i >= 0; i--)
            result.push_back(bin[i]);
        goto end;
    }
    while (bin.size() != 3)
    {
        //приписываем двоичное представление группы битов слева
        for (int i = 0; i < bin.size(); i++)
            result.insert(result.begin(), bin[i]);
        bin = ToBinary(bin.size());
    }
    //приписываем двоичное представление первой группы битов слева
    for (int i = 0; i < bin.size(); i++)
        result.insert(result.begin(), bin[i]);
end:
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
        EvenRodeh(0) == vector<bool>{0, 0, 0}&&
        EvenRodeh(1) == vector<bool>{0, 0, 1}&&
        EvenRodeh(2) == vector<bool>{0, 1, 0}&&
        EvenRodeh(3) == vector<bool>{0, 1, 1}&&
        EvenRodeh(4) == vector<bool>{1, 0, 0, 0}&&
        EvenRodeh(5) == vector<bool>{1, 0, 1, 0}&&
        EvenRodeh(6) == vector<bool>{1, 1, 0, 0}&&
        EvenRodeh(7) == vector<bool>{1, 1, 1, 0}&&
        EvenRodeh(8) == vector<bool>{1, 0, 0, 1, 0, 0, 0, 0}&&
        EvenRodeh(9) == vector<bool>{1, 0, 0, 1, 0, 0, 1, 0}&&
        EvenRodeh(10) == vector<bool>{1, 0, 0, 1, 0, 1, 0, 0}&&
        EvenRodeh(11) == vector<bool>{1, 0, 0, 1, 0, 1, 1, 0}&&
        EvenRodeh(12) == vector<bool>{1, 0, 0, 1, 1, 0, 0, 0}&&
        EvenRodeh(13) == vector<bool>{1, 0, 0, 1, 1, 0, 1, 0}&&
        EvenRodeh(14) == vector<bool>{1, 0, 0, 1, 1, 1, 0, 0}&&
        EvenRodeh(15) == vector<bool>{1, 0, 0, 1, 1, 1, 1, 0}&&
        EvenRodeh(16) == vector<bool>{1, 0, 1, 1, 0, 0, 0, 0, 0}&&
        EvenRodeh(17) == vector<bool>{1, 0, 1, 1, 0, 0, 0, 1, 0}&&
        EvenRodeh(32) == vector<bool>{1, 1, 0, 1, 0, 0, 0, 0, 0, 0}&&
        EvenRodeh(100) == vector<bool>{1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0}&&
        EvenRodeh(512) == vector<bool>{1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}&&
        EvenRodeh(1023) == vector<bool>{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}&&
        EvenRodeh(1024) == vector<bool>{1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}&&
        EvenRodeh(2000) == vector<bool>{1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0}&&
        EvenRodeh(2500) == vector<bool>{1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}