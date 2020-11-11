//Автор: Закусилов Игорь Анатольевич
//Версия компилятора: mingw-5.2.0 g++ 
//Cтандарт c++98
#include <iostream>
#include <vector>
#include <utility> 
#include <map>
#include <algorithm> 
#include <conio.h>
using namespace std;

map<char, vector<bool> > Huffman(string);
bool Test(map<char, vector<bool> >);

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    map<char, vector<bool> > words = Huffman(input);

    for (std::map<char, vector<bool> >::iterator it = words.begin(); it != words.end(); it++)
    {
        cout << "\nThe letter \"" << it->first << "\" is ";
        for (int j = 0; j < it->second.size(); j++)
            cout << it->second[j];
    }
    Test(words);
    _getch();
    return 1;
}

bool Comparer(pair<string, double> a, pair<string, double> b) { return (a.second > b.second); }

//Функция, реализующая cтатический алгоритм Хаффмана
map<char, vector<bool> > Huffman(string input)
{
    map<char, vector<bool> > words;
    vector<pair<string, double> > dictionary;
    for (int i = 0; i < input.length(); i++)
    {
        //считаем количество букв
        for (int j = 0; j < dictionary.size(); j++)
        {
            if (dictionary[j].first[0] == input[i])
            {
                //высчитываем частоты
                dictionary[j].second += 1.0 / input.length();
                goto outer;
            }
        }
        dictionary.push_back(make_pair(string(1, input[i]), 1.0 / input.length()));
    outer:;
    }
    sort(dictionary.begin(), dictionary.end(), Comparer);
    for (int i = 0; i < dictionary.size(); i++)
        words[dictionary[i].first[0]] = vector<bool>();
    //объединяем буквы и строим слова
    while (dictionary.size() > 1)
    {
        for (int k = dictionary.size() - 1; k > 0; k--)
        {
            for (int i = 0; i < dictionary[k].first.length(); i++)
                words[dictionary[k].first[i]].insert(words[dictionary[k].first[i]].begin(), 1);
            for (int i = 0; i < dictionary[k - 1].first.length(); i++)
                words[dictionary[k - 1].first[i]].insert(words[dictionary[k - 1].first[i]].begin(), 0);
            dictionary[k - 1].first += dictionary[k].first;
            dictionary[k - 1].second += dictionary[k].second;
            dictionary.erase(dictionary.begin() + k);
            sort(dictionary.begin(), dictionary.end(), Comparer);
        }
    }
    return words;
}

bool Test(map<char, vector<bool> > words)
{
    //сравниваем попарно слова
    for (std::map<char, vector<bool> >::iterator it = words.begin(), it2 = it; it != words.end(); it++, it2 = it)
    {
        for (std::map<char, vector<bool> >::iterator jt = ++it2; jt != words.end(); jt++)
        {
            //сравниваем пары посимвольно
            bool test = false;
            for (int k = 0; k < it->second.size() && k < jt->second.size(); k++)
            {
                if (it->second[k] != jt->second[k])
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