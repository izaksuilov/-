//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;
pair<string, int> BWT(string);
string DecodeBWT(pair<string, int>);
string LShift(string, int);
bool Test();

int main(void)
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    pair<string, int> result = BWT(input);
    cout << endl << "BWT code is: (\"" << result.first << "\", " << result.second << ")" << endl;
    string decoded = DecodeBWT(result);
    cout << "\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    Test();
    _getch();
    return 1;
}

pair<string, int> BWT(string input)
{
    vector<string> comb; pair<string, int> result = make_pair("", 0);
    //создаем словарь сдвинутых слов
    for (int i = 0; i < input.length(); i++)
        comb.push_back(LShift(input, i));
    //сортируем и берем последнюю букву каждого слова
    sort(comb.begin(), comb.end());
    for (int i = 0; i < comb.size(); i++)
    {
        result.first += comb[i][comb[i].length() - 1];
        if (comb[i] == input)
            result.second = i;
    }
    return result;
}
string DecodeBWT(pair<string, int> in)
{
    string input = in.first;
    vector<string> comb;
    if (input.length() == 1) return input;
    //создаем словарь букв
    for (int i = 0; i < input.length(); i++)
        comb.push_back(string(1, input[i]));
    sort(comb.begin(), comb.end());
    if (input.length() == 2) goto end;
    //воссоздаем слово
    for (int i = 0; i < input.length() - 2; i++)
    {
        for (int j = 0; j < input.length(); j++)
            comb[j] = input[j] + comb[j];
        sort(comb.begin(), comb.end());
    }
end:;
    for (int j = 0; j < input.length(); j++)
        comb[j] += input[j];
    return comb[in.second];
}
string LShift(string input, int shift)
{
    string result = input.substr(input.length() - shift);//берем символы с конца
    result += input.substr(0, input.length() - shift);//берем символы с начала
    return result;
}

bool Test()
{
    cout << "\nTesting..." << endl;
    for (int i = 0; i < 10000; i++)
    {
        //генерируем случайную строку
        string randInput = "";
        for (int j = rand() % 100; j >= 0; j--)
            randInput += 33 + rand() % 90;

        string decoded = DecodeBWT(BWT(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!\n" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}