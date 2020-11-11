//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <cmath> 
#include <conio.h> 
using namespace std;

vector<pair<char, vector<bool> > > GilbertMoore(string);
bool Test(vector<pair<char, vector<bool> > > words);

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    vector<pair<char, vector<bool> > > words = GilbertMoore(input);

    for (int i = 0; i < words.size(); i++)
    {
        cout << "\nThe letter \"" << words[i].first << "\" is ";
        for (int j = 0; j < words[i].second.size(); j++)
            cout << words[i].second[j];
    }
    cout << endl << endl;
    //красивый вывод
    string s1 = "", s2 = "", s3 = "";
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (words[j].first == input[i])
            {
                string s = string(words[j].second.size(), ' ');
                string ss = string(words[j].second.size(), ' ');
                s[0] = '|'; s[s.length() - 1] = '|';
                ss[(ss.length() - 1) / 2] = words[j].first;
                s3 += ss; s2 += s;
                for (int o = 0; o < words[j].second.size(); o++)
                    s1 += words[j].second[o] + '0';
                break;
            }
        }

    }
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    Test(words);
    _getch();
    return 1;
}
//Функция, реализующая алгоритм построения кода Гилберта-Мура
vector<pair<char, vector<bool> > > GilbertMoore(string input)
{
    vector<pair<char, vector<bool> > > words;
    vector<pair<char, double> > dictionary;
    for (int i = 0; i < input.length(); i++)
    {
        //считаем количество букв
        for (int j = 0; j < dictionary.size(); j++)
        {
            if (dictionary[j].first == input[i])
            {
                //высчитываем частоты
                dictionary[j].second += 1.0 / input.length();
                goto outer;
            }
        }
        dictionary.push_back(pair<char, double>(input[i], 1.0 / input.length()));
    outer:;
    }
    //Образуем суммы частот
    vector<double> q, d;
    q.push_back(0);
    d.push_back(dictionary[0].second / 2);
    for (int i = 0; i < dictionary.size() - 1; i++)
    {
        q.push_back(q[i] + dictionary[i].second);
        d.push_back(q.back() + (dictionary[i + 1].second) / 2);
    }
    //строим слова
    for (int i = 0; i < dictionary.size(); i++)
    {
        vector<bool> word;
        //переводим вещественные числа в двоичную систему
        int digit = 1 + ceil(-log2(dictionary[i].second));
        d[i] *= 2;
        for (int j = 1; j < digit; j++)
        {
            word.push_back(floor(d[i]));
            if (d[i] >= 1) d[i]--;
            d[i] *= 2;
        }
        word.push_back(floor(d[i]));
        words.push_back(make_pair(dictionary[i].first, word));
    }
    return words;
}
bool Test(vector<pair<char, vector<bool> > > words)
{
    //сравниваем попарно слова
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            //сравниваем пары посимвольно
            bool test = false;
            for (int k = 0; k < words[i].second.size() && k < words[j].second.size(); k++)
            {
                if (words[i].second[k] != words[j].second[k])
                    test = true;
            }
            if (!test)
            {
                cout << "\nTest failed. The code is not prefixed" << endl;
                return false;
            }
        }
    }
    cout << "\nTest completed successfully! The code is prefixed" << endl;
    return true;
}