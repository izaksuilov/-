//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h> 
using namespace std;

vector<bool> Lev(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result is: ";
    vector<bool> result = Lev(num);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм 
//построения кода Левенштейна
vector<bool> Lev(unsigned num)
{
    if (!num) return vector <bool>(1);
    vector<bool> bin = ToBinary(num), result;
    int c = 1;
    //последовательно приписываем слева слова Bin'(└log2x┘)
    while (bin.size())
    {
        for (int i = 0; i < bin.size(); i++)
            result.insert(result.begin(), bin[i]);
        num = floor(log2(num));
        bin = ToBinary(num);
        c++;
    }
    //припысываем слева ноль
    result.insert(result.begin(), 0);
    //припысываем слева единицы
    for (int i = c; i > 0; i--)
        result.insert(result.begin(), 1);
    return result;
}
//Функция возвращает перевод числа 
//в двоичную систему без последнего бита
vector<bool> ToBinary(unsigned num)
{
    vector<bool> result;
    while (num)
    {
        result.push_back(num % 2);
        num /= 2;
    }
    result.pop_back();
    return result;
}
//Чтобы запустить тест нужен стандарт c++11 из-за инициализации векторов
//Можно было сделать по-другому или декодер, но мне лень
bool Test()
{
    if (
        Lev(0) == vector<bool>{0}&&
        Lev(1) == vector<bool>{1, 0}&&
        Lev(2) == vector<bool>{1, 1, 0, 0}&&
        Lev(3) == vector<bool>{1, 1, 0, 1}&&
        Lev(4) == vector<bool>{1, 1, 1, 0, 0, 0, 0}&&
        Lev(5) == vector<bool>{1, 1, 1, 0, 0, 0, 1}&&
        Lev(6) == vector<bool>{1, 1, 1, 0, 0, 1, 0}&&
        Lev(7) == vector<bool>{1, 1, 1, 0, 0, 1, 1}&&
        Lev(8) == vector<bool>{1, 1, 1, 0, 1, 0, 0, 0}&&
        Lev(9) == vector<bool>{1, 1, 1, 0, 1, 0, 0, 1}&&
        Lev(10) == vector<bool>{1, 1, 1, 0, 1, 0, 1, 0}&&
        Lev(11) == vector<bool>{1, 1, 1, 0, 1, 0, 1, 1}&&
        Lev(12) == vector<bool>{1, 1, 1, 0, 1, 1, 0, 0}&&
        Lev(13) == vector<bool>{1, 1, 1, 0, 1, 1, 0, 1}&&
        Lev(14) == vector<bool>{1, 1, 1, 0, 1, 1, 1, 0}&&
        Lev(15) == vector<bool>{1, 1, 1, 0, 1, 1, 1, 1}&&
        Lev(16) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}&&
        Lev(17) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1}&&
        Lev(18) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}&&
        Lev(19) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1}&&
        Lev(20) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0}&&
        Lev(21) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1}&&
        Lev(22) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0}&&
        Lev(23) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1}&&
        Lev(24) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0}&&
        Lev(31) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1}&&
        Lev(37) == vector<bool>{1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
    )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}