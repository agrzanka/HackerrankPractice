#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    //making obstacles unique
    vector<vector<int>>::iterator iter;
    iter=unique(obstacles.begin(),obstacles.end());
    obstacles.resize(distance(obstacles.begin(),iter));
    
    int output=0;

   // k=obstacles.size();
    vector<int> upper;
    vector<int>bottom;
    vector<int>left;
    vector<int> right;
    vector<int> upperLeftDiagonal;
    vector<int> upperRightDiagonal;
    vector<int>bottomLeftDiagonal;
    vector<int> bottomRightDiagonal;
    if(k!=0)
    {
        /*vector<int>upDown;
        vector<int>leftRight;
        vector<int>upperDiagonals;
        vector<int>bottomDiagonals;
        for(int i=0;i<k;i++)
        {
            if(obstacles[i][0]==r_q)
                leftRight.push_back(i);
            else if(obstacles[i][1]==c_q)
                upDown.push_back(i);
            else if(obstacles[i][0]<r_q&&abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
                upperDiagonals.push_back(i);
            else if(obstacles[i][0]>r_q&&abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
                bottomDiagonals.push_back(i);
            
        }*/
        
        for(int i=0;i<k;i++)
        {
            if(obstacles[i][0]==r_q)
            {
                if(obstacles[i][1]<c_q)
                    left.push_back(i);
                else {
                    right.push_back(i);
                }
            }
                
            else if(obstacles[i][1]==c_q)
                {
                    if(obstacles[i][0]<r_q)
                        upper.push_back(i);
                    else {
                        bottom.push_back(i);
                    }
                }
            else if(obstacles[i][0]<r_q&&abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
            {
                if(obstacles[i][1]<c_q)
                    upperLeftDiagonal.push_back(i);
                else {
                    upperRightDiagonal.push_back(i);
                }
            }
            else if(obstacles[i][0]>r_q&&abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
            {
                if(obstacles[i][1]<c_q)
                    bottomLeftDiagonal.push_back(i);
                else
                    bottomRightDiagonal.push_back(i);
            }
    }
    }
    if(left.size()>0)
    {
        int leftObst=1;
        for(auto&o:left)
        {
            if(obstacles[o][1]>leftObst)
                leftObst=obstacles[o][1];
        }
        output+=(c_q-leftObst-1);
    }
    else
        output+=(c_q-1);
    
    
    if(right.size()>0)
    {
        int rightObst=n;
        for(auto&o:right)
        {
            if(obstacles[o][1]<rightObst)
                rightObst=obstacles[o][1];
        }
        output+=(rightObst-c_q-1);
    }
    else {
        output+=(n-c_q);
    }



    if(upper.size()>0)
    {
        int u=1;
        for(auto&o:upper)
        {
            if(obstacles[o][0]>u)
                u=obstacles[o][0];
        }
        output+=(r_q-u-1);
    }
    else
        output+=(r_q-1);

    if(bottom.size()>0)
    {
        int b=n;
        for(auto&o:bottom)
        {
            if(obstacles[o][0]<b)
                b=obstacles[o][0];
        }
        output+=(b-r_q-1);
    }
    else
        output+=(n-r_q);

        
//problem with diagonals!!!

    if(upperLeftDiagonal.size()>0)
    {
        int r=1;
        int c=1;
        for(auto&o:upperLeftDiagonal)
        {
            if(obstacles[o][0]>r)
                r=obstacles[o][0];
            if(obstacles[o][1]>c)
                c=obstacles[o][1];
        }
        output+=min(c_q-c-1,r_q-r-1);
    }
    else
        output+=(min(c_q-1,r_q-1));

    if(upperRightDiagonal.size()>0)
    {
        int r=1;
        int c=n;
        for(auto&o:upperRightDiagonal)
        {
            if(obstacles[o][0]>r)
                r=obstacles[o][0];
            if(obstacles[o][1]<c)
                c=obstacles[o][1];
        }
        output+=min(r_q-r-1,n-c-c_q-1);
    }
    else
        output+=(min(r_q-1,n-c_q));


    if(bottomLeftDiagonal.size()>0)
    {
        int r=r_q;
        int c=c_q;
        for(auto&o:bottomLeftDiagonal)
        {
            if(obstacles[o][0]>r)
                r=obstacles[o][0];
            if(obstacles[o][1]>c)
                c=obstacles[o][1];
        }
        output+=min(c_q-c-1,r-r_q-1);
    }
    else
        output+=(min(c_q-1,n-r_q));

    if(bottomRightDiagonal.size()>0)
    {
        int r=n;
        int c=n;
        for(auto&o:bottomRightDiagonal)
        {
            if(obstacles[o][0]<r)
                r=obstacles[o][0];
            if(obstacles[o][1]>c)
                c=obstacles[o][1];
        }
        output+=min(r-r_q-1,n-c-c_q-1);
    }
    else
        output+=(min(n-c_q,n-r_q));

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
