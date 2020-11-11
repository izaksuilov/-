//�����: ��������� ����� �����������
//������ �����������: mingw-5.2.0 g++ 
//C������� c++98
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <cmath> 
#include <conio.h>
using namespace std;

vector<vector<bool> > Shennon(vector<int>);
bool Test(vector<vector<bool> >);
//������ ������� ����

int main()
{
    int wordsCount;
    cout << "Enter the count of the words: ";
    cin >> wordsCount;
    if (wordsCount < 1)
    {
        cout << "The word's count should be greater than 0" << endl;
        return -1;
    }
    int counter = 1, max = -1, curLen;
    vector<int> lenghts;
    double kraft = 0;
    //������ ����� ����
    while (wordsCount--)
    {
        cout << "Enter the length of the word number " << counter++ << ": ";
        cin >> curLen;
        lenghts.push_back(curLen);
        if (curLen < 1)
        {
            cout << "The word's length should be greater than 1" << endl;
            return -1;
        }
        if (max <= curLen)
            max = curLen;
        else
        {
            cout << "Doesn't satisfy the Shennon's condition" << endl;
            return -1;
        }
        kraft += pow(2, -curLen);
    }
    //��������� ����������� ������
    if (kraft > 1)
    {
        cout << "Doesn't satisfy the Kraft's inequality" << endl;
        return -1;
    }
    vector<vector<bool> > words = Shennon(lenghts);
    for (int i = 0; i < words.size(); i++)
    {
        cout << "\nWord number " << i + 1 << " is ";
        for (int j = 0; j < words[i].size(); j++)
            cout << words[i][j];
    }
    Test(words);
    _getch();
    return 1;
}
//����� ������� ��������������� �������� ����������  �����  �� �������� ������ ������� ����
vector<vector<bool> > Shennon(vector<int> lenghts)
{
    vector<vector<bool> > words;
    //������ �����
    words.push_back(vector<bool>(lenghts[0]));
    vector<bool> prev;
    for (int i = 1; i < lenghts.size(); i++)
    {
        int length = lenghts[i], reminder = 0;
        prev.resize(length);
        //�������� ������� �������� 
        vector<bool> value(length), sum;
        value[lenghts[i - 1] - 1] = 1;
        //���������� �������� ����� � ��������� ������
        while (length--)
        {
            sum.insert(sum.begin(), (value.back() + prev.back() + reminder) % 2);
            reminder = value.back() + prev.back() + reminder > 1 ? 1 : 0;
            value.pop_back();
            prev.pop_back();
        }
        prev = sum;
        words.push_back(sum);
    }
    return words;
}
bool Test(vector<vector<bool> > words)
{
    //���������� ������� �����
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            //���������� ���� �����������
            bool test = false;
            for (int k = 0; k < words[i].size(); k++)
            {
                if (words[i][k] != words[j][k])
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