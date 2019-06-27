#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    char ap=s[8];
    s.pop_back();
    s.pop_back();
    string hour={s[0],s[1]};
    int h=atoi(hour.c_str());
    if(ap=='A')
    {
        if(h==12)
            {
                s[0]='0';
                s[1]='0';
            }
        return s;
    }

    h+=12;
    s[0]=h/10+'0';
    s[1]=h%10+'0';

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
