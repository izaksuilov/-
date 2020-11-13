//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <conio.h>
using namespace std;

//Важное примечание!
//Для компилятора g++ указать атрибут -std=c++11

vector<vector<int> > LZ78(string);
string DecodeLZ78(vector<vector<int> >);
bool Test();

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    vector<vector<int> > result = LZ78(input);
    cout << "The code is:" << endl;
    for (int i = 0; i < result.size(); i++)
        cout << "[" << result[i][0] << ",\'" << (char) result[i][1] << "\'] ";
    string decoded = DecodeLZ78(result);
    cout << "\n\nInput string: " << input << "\nDecoded:      " << decoded << endl
        << (decoded == input ? "The strings are equal!" : "The strings are not equal!") << endl;
    //Test();
    _getch();
    return 1;
}
//Функция, реализующая алгоритм LZ78
vector<vector<int> > LZ78(string input)
{
    vector<vector<int> > letters;
    map<string, int> buffer;
    cout << "\nThe dictionary is:\n(0,\"\") ";
    input += '\0';
    for (int i = 0; i < input.length(); i++)
    {
        size_t found = buffer.count(string(1, input[i]));
        //если нет сивола, то добавляем в буфер
        while (!found && input[i] != '\0')
        {
            letters.push_back({ 0,input[i] });
            cout << "(" << buffer.size() + 1 << ",\"" << string(1, input[i]) << "\") ";
            buffer.insert(make_pair(string(1, input[i]), buffer.size() + 1));
            found = buffer.count(string(1, input[++i]));
        }
        //если конец строки
        if (input[i] == '\0') goto end;
        //если символ есть, то считываем до тех пор, пока совпадает подстрока
        string match = "";
        do
        {
            match += input[i];
            found = buffer.count(match + input[++i]);
        } while (found && input[i] != '\0');

        letters.push_back({ buffer[match],//такая-то группа в словаре
                            input[i] });//такой-то символ
        cout << "(" << buffer.size() + 1 << ",\"" << match + input[i] << "\") ";
        buffer.insert(make_pair(match + input[i], buffer.size() + 1));
    }
end:;
    cout << endl;
    return letters;
}

string DecodeLZ78(vector<vector<int> > letters)
{
    string result = "";
    map<int, string> buffer;
    for (int i = 0; i < letters.size(); i++)
    {
        string match = "";
        if (letters[i][0])
            result += (match = buffer[letters[i][0]]);
        result += letters[i][1];
        buffer[buffer.size() + 1] = match + string(1, letters[i][1]);
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

        string decoded = DecodeLZ78(LZ78(randInput));
        if (decoded != randInput)
        {
            cout << "Test failed!\n" << decoded << " != " << randInput << endl;
            return false;
        }
    }
    cout << "Test completed successfully!" << endl;
    return true;
}