//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;

pair<string, vector<int> > Interval(string);
string DecodeInterval(pair<string, vector<int> >);
bool Test();

/*
Примечание:

Алфавит создаётся и сортируется автоматически.
На вход подаётся только строка, которую нужно закодировать

Пример:

"abc" -- алфавит "abc"
"cba" -- алфавит "abc"
"ccaabb" -- алфавит "abc"

*/

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    pair<string, vector<int> > result = Interval(input);
    cout << endl << "The code is: [";
    for (int i = 0; i < result.second.size(); i++)
        cout << result.second[i] << " ";
    cout << "\b]";
    string decoded = DecodeInterval(result);
    cout << "\n\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм интеравльного кодирования
pair<string, vector<int> > Interval(string input)
{
    vector<int> code;
    string alphabet = "", concat;
    //Считываем и сортируем алфавит
    for (int i = 0; i < input.length(); i++)
        if (alphabet.find(input[i]) == std::string::npos)
            alphabet += input[i];
    sort(alphabet.begin(), alphabet.end());
    //Строим код
    concat = alphabet + input;
    for (int i = alphabet.length(); i < concat.length(); i++)
        code.push_back(i - concat.substr(0, i).rfind(concat[i]) - 1);
    return make_pair(alphabet, code);
}

string DecodeInterval(pair<string, vector<int> > input)
{
    vector<int> code = input.second;
    string concat = input.first, result = "";
    for (int i = 0; i < code.size(); i++)
    {
        result += concat[concat.length() - 1 - code[i]];
        concat += result[result.length() - 1];
    }
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

        string decoded = DecodeInterval(Interval(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!\n" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}