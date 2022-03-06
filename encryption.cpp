// encryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <vector> 
#include <string> 
#include <sstream>  
#include <algorithm>


using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream. 
    string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
 string flipwhole(string m)
{
    string nm = "";
    char b;
    int a = 0;
    for (int i = 0; i < m.length(); ++i)
    {
        a = m.length() - i - 1;
        b = m[a];
        nm += (char)b;
    }
    return nm;
}
 string zigzagen(string m)
{
    string nm = "";

    for (int i = 0; i < m.length(); ++i)
    {
        if (i % 2 == 0)
        {
            nm += m[i];
        }

    }
    nm += " ";
    for (int i = 0; i < m.length(); ++i)
    {
        if (i % 2 == 1)
        {
            nm += m[i];
        }

    }
    return nm;
}
 string zigzagde(string m)
{
    
    string m1, m2, nm = "";
    vector<string> arr ;
    arr = split(m, ' ');
    m1 = arr[0];
    m2 = arr[1];
    for (int i = 0; i < m1.length(); ++i)
    {
        nm += m1[i];
        if (i < m2.length())
        {
            nm += m2[i];

        }
    }
    return nm;
}
 string flipword(vector<string> arr)
{
    string m , nm = "";
    char a;
    int index;
    int size = arr.size();
    for (int j = 0; j < arr.size(); ++j)
    {
        m = arr[j];
        m = flipwhole(m);
        nm += m;
    }
    return nm;
}
 string addspace(string m)
{
    int b = 0;
    string nm = "";
    for (int i = 0; i < m.length(); ++i)
    {
        if (b == 4)
        {
            nm += " ";
            b = 0;
        }
        nm += (char)(m[i]);
        b++;
    }
    return nm;
}
int main()
{
    
    int c, s = 1,count=0;
    char a;
    string m, nm = "";
    cout << "Enter the message \n";
    getline(cin, m);
    
    cout << "Type 1 for encryption or 2 for decryption: \n";
    cin >> c;
    if (c == 1)
    {
        for (int i = 0; i < m.length(); ++i)
        {
            a = m[i];
            if (s > 0)
            {
                if (a + s > 122)
                {
                    nm += (char)(a + s - 26);
                }
                else if (a + s <= 122 || 'a' > a || 'z' < a)
                {
                    nm += (char)(a + s);
                }
                s += 1;
            }
            else if (s < 0)
            {
                if (a + s < 97)
                {
                    nm += (char)(a + s + 26);
                }
                else if (a + s >= 97 || 'a' > a || 'z' < a)
                {
                    nm += (char)(a + s);
                }
                s -= 1;
            }
            s = -s;
        }
        nm = flipwhole(nm);
        nm = addspace(nm);
        vector<string>arr;
        arr = split(nm, ' ');
        nm = flipword(arr);
        nm = zigzagen(nm);
        
    }
    if (c == 2)
    {
        

        m = zigzagde(m);
        m = addspace(m);
        vector<string> arr;
        arr = split(m, ' ');
        m = flipword(arr);
        m = flipwhole(m);
        for (int i = 0; i < m.length(); ++i)
        {
            a = m[i];
            if (s > 0)
            {
                if (a - s < 97)
                {
                    nm += (char)(a - s + 26);
                }
                else if (a - s >= 97 || 'a' > a || 'z' < a)
                {
                    nm += (char)(a - s);
                }
                s += 1;
            }
            else if (s < 0)
            {
                if (a - s > 122)
                {
                    nm += (char)(a - s - 26);
                }
                else if (a - s <= 122 || 'a' > a || 'z' < a)
                {
                    nm += (char)(a - s);
                }
                s -= 1;
            }
            s = -s;
        }
        
    }
    replace(nm.begin(), nm.end(), ':', ' ');
    
    cout << nm;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
