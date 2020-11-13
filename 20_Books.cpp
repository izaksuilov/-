//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;

pair<string, vector<int> > Books(string, string = "");
string DecodeBooks(pair<string, vector<int> >);
bool Test();

int main()
{
    string input, alphabet = "";
    cout << "Enter the string: ";
    cin >> input;
    cout << "Do you want to use your own alphabet? [y|n] ";
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        cout << "Please, enter your alphabet: ";
        cin >> alphabet;
    }
    pair<string, vector<int> > result = Books(input, alphabet);
    cout << endl << "The code is: [";
    for (int i = 0; i < result.second.size(); i++)
        cout << result.second[i] << " ";
    cout << "\b]";
    string decoded = DecodeBooks(result);
    cout << "\n\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм
//кодирования при помощи стопки книг
pair<string, vector<int> > Books(string value, string alphabet)
{
    vector<int> code;
    //Считываем  и сортируем алфавит
    if (alphabet == "")
    {
        for (int i = 0; i < value.length(); i++)
            if (alphabet.find(value[i]) == std::string::npos)
                alphabet += value[i];
        sort(alphabet.begin(), alphabet.end());
    }
    //Строим слово
    for (int i = 0; i < value.length(); i++)
    {
        size_t found = alphabet.find(value[i]);
        code.push_back(found + 1);
        alphabet = alphabet.substr(found, 1) + alphabet.substr(0, found) + alphabet.substr(found + 1);
    }
    return make_pair(alphabet, code);
}
string DecodeBooks(pair<string, vector<int> > input)
{
    string alphabet = input.first, result = "";
    sort(alphabet.begin(), alphabet.end());
    for (int i = 0; i < input.second.size(); i++)
    {
        int letter = input.second[i] - 1;
        result += alphabet[letter];
        alphabet = alphabet.substr(letter, 1) + alphabet.substr(0, letter) + alphabet.substr(letter + 1);
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

        string decoded = DecodeBooks(Books(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!\n" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}