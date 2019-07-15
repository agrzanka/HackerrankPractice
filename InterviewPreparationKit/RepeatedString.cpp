#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long a=0;
    
    if(s.size()>n)
    {
        for(int i=0;i<n;i++)
            if(s[i]=='a')
                a++;
        return a;
    }

    for(auto&c:s)
        if(c=='a')
            a++;

    long counter=n/s.size();
    a*=counter;

    long rest=n%s.size();
    for(int i=0;i<rest;i++)
            if(s[i]=='a')
                a++;


    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
