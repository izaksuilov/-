//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> 
#include <conio.h>
using namespace std;

//Важное примечание!
//Для компилятора g++ указать атрибут -std=c++11

pair<vector<int>, map<string, int> > LZW(string);
string DecodeLZW(pair<vector<int>, map<string, int> >);
bool Test();

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    pair<vector<int>, map<string, int> > result = LZW(input);
    cout << "The code is:" << endl << "[";
    for (int i = 0; i < result.first.size(); i++)
        cout << result.first[i] << " ";
    cout << "\b]";
    string decoded = DecodeLZW(result);
    cout << "\n\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм LZW
pair<vector<int>, map<string, int> > LZW(string input)
{
    vector<int> letters;
    map<string, int> buffer;
    string match = "";
    //заполняем массив всеми символами
    for (int p = 0; p < input.length(); p++)
        if (!buffer.count(string(1, input[p])))
            buffer.insert(make_pair(string(1, input[p]), buffer.size()));
    //формируем словарь
    match = "";
    int i = 0;
    while (i < input.length())
    {
        do match += input[i];
        while (++i < input.length() && buffer.count(match + input[i]));
        if (i < input.length())
            buffer.insert(make_pair(match + input[i], buffer.size()));
        letters.push_back(buffer[match]);
        match = "";
    }

    vector<pair<string, int>> vec;
    for (map<string, int> ::iterator it = buffer.begin(); it != buffer.end(); it++)
        vec.push_back(make_pair(it->first, it->second));
    sort(vec.begin(), vec.end(), [](pair<string, int> a, pair<string, int> b) { return (a.second < b.second); });

    cout << endl << "The dictionary is: " << endl;
    for (int i = 0; i < vec.size(); i++)
        if (buffer.count(vec[i].first) < 2)
            cout << "(" << vec[i].second << ",\"" << vec[i].first << "\") ";
    cout << endl;
    return make_pair(letters, buffer);
}

string DecodeLZW(pair<vector<int>, map<string, int> > input)
{
    string result = "";
    for (int i = 0; i < input.first.size(); i++)
        for (map<string, int> ::iterator it = input.second.begin(); it != input.second.end(); it++)
            if (it->second == input.first[i])
            {
                result += it->first;
                break;
            }
    return result;
}

bool Test()
{
    cout << "\nTesting..." << endl;
    for (int i = 0; i < 100; i++)
    {
        //генерируем случайную строку
        string randInput = "";
        for (int j = rand() % 100; j >= 0; j--)
            randInput += 33 + rand() % 90;

        string decoded = DecodeLZW(LZW(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!\n" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}