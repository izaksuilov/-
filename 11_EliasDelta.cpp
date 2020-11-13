//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

vector<bool> EliasDelta(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = EliasDelta(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения дельта-кода Элайеса
vector<bool> EliasDelta(unsigned num)
{
    vector<bool> n = ToBinary(num), bin = ToBinary(n.size()), result;
    //приписываем нули справа
    for (int i = 0; i < bin.size() - 1; i++)
        result.push_back(0);
    //приписываем двоичное представление длины числа справа
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);
    //приписываем двоичное представление без старшего бита числа справа
    for (int i = n.size() - 2; i >= 0; i--)
        result.push_back(n[i]);
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
//bool Test()
//{
//    if (
//        EliasDelta(1) == vector<bool>{1}&&
//        EliasDelta(2) == vector<bool>{0, 1, 0, 0}&&
//        EliasDelta(3) == vector<bool>{0, 1, 0, 1}&&
//        EliasDelta(4) == vector<bool>{0, 1, 1, 0, 0}&&
//        EliasDelta(5) == vector<bool>{0, 1, 1, 0, 1}&&
//        EliasDelta(6) == vector<bool>{0, 1, 1, 1, 0}&&
//        EliasDelta(7) == vector<bool>{0, 1, 1, 1, 1}&&
//        EliasDelta(8) == vector<bool>{0, 0, 1, 0, 0, 0, 0, 0}&&
//        EliasDelta(9) == vector<bool>{0, 0, 1, 0, 0, 0, 0, 1}&&
//        EliasDelta(10) == vector<bool>{0, 0, 1, 0, 0, 0, 1, 0}&&
//        EliasDelta(11) == vector<bool>{0, 0, 1, 0, 0, 0, 1, 1}&&
//        EliasDelta(12) == vector<bool>{0, 0, 1, 0, 0, 1, 0, 0}&&
//        EliasDelta(13) == vector<bool>{0, 0, 1, 0, 0, 1, 0, 1}&&
//        EliasDelta(14) == vector<bool>{0, 0, 1, 0, 0, 1, 1, 0}&&
//        EliasDelta(15) == vector<bool>{0, 0, 1, 0, 0, 1, 1, 1}&&
//        EliasDelta(16) == vector<bool>{0, 0, 1, 0, 1, 0, 0, 0, 0}&&
//        EliasDelta(17) == vector<bool>{0, 0, 1, 0, 1, 0, 0, 0, 1}
//    )
//    {
//        cout << "Test completed successfully" << endl;
//        return true;
//    }
//    else cout << "Test failed" << endl;
//    return false;
//}