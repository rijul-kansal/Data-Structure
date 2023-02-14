#include <bits/stdc++.h>
using namespace std;

int Length(string s);
void Changing_case(string &s);
void Counting_vowals(string s);
int Counting_words(string s);
int Counting_words(string s);
int Validation(string s);
void Reversing_1(string &s);
void Reversing_2(string &s);
void Comparing(string s1, string s2);
void Duplicate_1(string s);
void Duplicate_2(string s);
int Anagram(string s1, string s2);
// TC will be O(N)
int Length(string s)
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        c++;
    }
    return c;
}
// TC will be O(N)
void Changing_case(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
}
// Tc will be o(N)
void Counting_vowals(string s)
{
    int v = 0;
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'U' || s[i] == 'O' || s[i] == 'I' || s[i] == 'E' || s[i] == 'A')
        {
            v++;
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            c++;
        }
    }
    cout << v << " " << c;
}
// Tc will be O(N)
int Counting_words(string s)
{
    int c = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
            c++;
    }
    return c;
}
// Tc will be o(N)
int Validation(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 'a' && s[i] <= 'z') &&
            !(s[i] >= 'A' && s[i] <= 'Z') &&
            !(s[i] >= '0' && s[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}
// Tc will be O(N)
void Reversing_1(string &s)
{
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        temp += s[s.length() - 1 - i];
    }
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = temp[i];
    }
}
// Tc will be O(N)
void Reversing_2(string &s)
{

    for (int i = 0; i < s.length() / 2; i++)
    {
        swap(s[i], s[s.length() - 1 - i]);
    }
}
// Tc will be O(N)
void Comparing(string s1, string s2)
{
    int i = 0;
    while (i < s1.length() && i < s2.length())
    {
        if (s1[i] != s2[i])
            break;
        i++;
    }
    if (s1[i] == s2[i])
        cout << "Equal";
    else if (s1[i] > s2[i])
        cout << "1ST";
    else if (s1[i] < s2[i])
        cout << "2ST";
}
// Tc will be o(N)
void Duplicate_1(string s)
{
    int hash[26]{0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 97]++;
    }
    for (int i = 0; i < 26 ; i++)
    {
        if (hash[i] > 1)
        {
            cout << (char)(i + 97) << " " << hash[i] << endl;
        }
    }
}
// Tc will be o(N)
void Duplicate_2(string s)
{
    int x = 0;
    int h = 0;
    for (int i = 0; i < s.length(); i++)
    {
        x = 1;
        x = 1 << (s[i] - 97);
        if ((h & x))
        {
            cout << s[i] << " ";
        }
        else
        {
            h = (h | x);
        }
    }
}
// Tc will be O(N)
int Anagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return 0;
    int hash[26]{0};
    for (int i = 0; i < s1.length(); i++)
    {
        hash[s1[i] - 97]++;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        hash[s2[i] - 97]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
            return 0;
    }
    return 1;
}
int main()
{
    string s1 = "painting";
    string s2 = "painter";
    cin >> s1 >> s2;
    cout << Anagram(s1, s2);

    return 0;
}