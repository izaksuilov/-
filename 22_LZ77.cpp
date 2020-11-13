//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;

vector<vector<int> > LZ77(string);
string DecodeLZ77(vector<vector<int> >);
bool Test();

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    vector<vector<int> > result = LZ77(input);
    for (int i = 0; i < result.size(); i++)
        cout << "[" << result[i][0] << "," << result[i][1] << ",\'" << (char) result[i][2] << "\'] ";
    string decoded = DecodeLZ77(result);
    cout << "\n\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм LZ77
vector<vector<int> > LZ77(string input)
{
    vector<vector<int> > letters;
    string buffer = "";
    input += '\0';
    for (int i = 0; i < input.length(); i++)
    {
        size_t found = buffer.rfind(input[i]);
        //если нет сивола, то добавляем в буфер
        while (found == std::string::npos && input[i] != '\0')
        {
            vector <int> letter(2); letter.push_back(input[i]);
            letters.push_back(letter);
            buffer += input[i];
            found = buffer.rfind(input[++i]);
        }
        //если конец строки
        if (input[i] == '\0') return letters;
        //если символ есть, то считываем до тех пор, пока совпадает подстрока
        string match = "";
        do
        {
            match += input[i];
            found = buffer.rfind(match + input[++i]);
        } while (found != std::string::npos && input[i] != '\0');

        found = buffer.rfind(match);
        vector <int> letter;
        letter.push_back(i - (int) match.length() - (int) found);//вернуться на столько символов
        letter.push_back((int) match.length());//взять столько символов
        letter.push_back(input[i]);//следующая буква
        letters.push_back(letter);
        buffer += match + input[i];
    }
    return letters;
}

string DecodeLZ77(vector<vector<int> > letters)
{
    string result = "";
    for (int i = 0; i < letters.size(); i++)
    {
        result += result.substr(result.length() - letters[i][0], letters[i][1]);
        result += letters[i][2];
    }
    return result[result.length() - 1] == '\0' ? result.substr(0, result.length() - 1) : result;
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

        string decoded = DecodeLZ77(LZ77(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}