#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int valleys=0;
    bool valley=false;
    int sea_lvl=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='D')
            sea_lvl--;
        else if(s[i]=='U')
            sea_lvl++;
        
        if(valley==false&&sea_lvl<0)
        {
            valleys++;
            valley=true;
        }
        if(sea_lvl>=0)
            valley=false;
    }

    return valleys;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
