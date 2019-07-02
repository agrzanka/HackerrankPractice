#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
//normally I would make a class Matrix contains all the functions I have created below
vector<vector<int>> matrix90leftRotation(vector<vector<int>>matrix);
vector<vector<int>>magicSquare(int n);
vector<vector<int>>matrixMirrorReflection(vector<vector<int>>matrix);
int calculateCost(vector<vector<int>>matrix, vector<vector<int>>magic);
int formingMagicSquare(vector<vector<int>> s) {

   // int cost=-1;
    int n=s.size();
    //vector<vector<vector<int>>>allMagicSquares;//this was supposed to store all possible magic squares (there are 8 of them) but for that excersize it is useless.
    vector<vector<int>>magic=magicSquare(s.size());
    vector<vector<int>>mirrorM=matrixMirrorReflection(magic);
    int c1=calculateCost(s, magic);
    int c2=calculateCost(s, mirrorM);
    int c=(c1<c2)?c1:c2;
    int cost=c;

   // vector<vector<int>>matrix1, matrix2;
    for(int i=0;i<4;i++)
    {
        magic=matrix90leftRotation(magic);
        mirrorM=matrix90leftRotation(mirrorM);
        int c1=calculateCost(s, magic);
        int c2=calculateCost(s, mirrorM);
        int c;
        if(c1<c2)
            c=c1;
        else
            c=c2;
        if(cost>c)
            cost=c;
    }

    return cost;
}
int calculateCost(vector<vector<int>>matrix, vector<vector<int>>magic){
    int cost=0;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            cost+=abs(matrix[i][j]-magic[i][j]);
        }
    }
    return cost;
}
vector<vector<int>>matrixMirrorReflection(vector<vector<int>>matrix){
    vector<vector<int>>mirrorMatrix(matrix.size());
    for(int i=0;i<matrix.size();i++)
        mirrorMatrix[i]=vector<int>(matrix.size());

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            mirrorMatrix[i][j]=matrix[i][matrix.size()-1-j];
        }
    }
    return mirrorMatrix;
}
vector<vector<int>>magicSquare(int n){
    vector<vector<int>>matrix(n);
    for(int iter=0;iter<n;iter++)
        matrix[iter]=vector<int>(n);

    int i=n/2;
    int j=n-1;
    matrix[i][j]=1;
    for(int iter=2;iter<n*n+1;iter++)
    {
        i-=1;
        j+=1;
        if(i==-1&&j==n)
        {
            i=0;
            j=n-2;
        }
        else if(j==n)
            j=0;
        else if(i==-1)
            i=n-1;

        if(matrix[i][j]>0&&matrix[i][j]<n*n+1)
        {
            i+=1;
            j-=2;
        }
        
        matrix[i][j]=iter;
    }
    return matrix;
}
vector<vector<int>> matrix90leftRotation(vector<vector<int>>matrix){
    int size=matrix.size();
    vector<vector<int>> rotatedMatrix(size);
    for(int i=0;i<size;i++)
        rotatedMatrix[i]=vector<int>(size);

    for(int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            rotatedMatrix[i][j]=matrix[size-1-j][i];
        }
    }

    return rotatedMatrix;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
