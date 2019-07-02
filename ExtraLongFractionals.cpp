#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
vector<unsigned long long int> bigNumberMerge(int number); //code : the first attempt
string splitBigNumber(vector<unsigned long long int>number);//code : the first attempt
void extraLongFactorials(int n) {

    int newNumber;
    int carry;
    deque<int>result={n};
    deque<int>tmp;
    for(int factor=2;factor<n;factor++)
    {
        carry=0;
        for(int i=result.size()-1;i>-1;i--)
        {
          //  if(result[i]==0)
           // {
          //      tmp.push_front(0);
          //      continue;
          //  }
            newNumber=carry+(factor*result[i]);
            tmp.push_front(newNumber%10);
            carry=newNumber/10;
        }
        while(carry!=0)
        {
            tmp.push_front(carry%10);
            carry/=10;
        }
        result.clear();
        result=tmp;
        tmp.clear();
    }
    for(int i=0;i<result.size();i++)
        cout<<result[i];


   //first attempt code: - runtime problem, too complicated
   /* string result;
    unsigned long long int max=pow(10,16);
    int j=2;
    unsigned long long int number=1;
    while(j<n+1&&number<max)
    {
        number*=j;
        j++;
    }
    if(j<n)
    {
        vector<unsigned long long int> num=bigNumberMerge(number);
        while(j<n+1)
        {
            for(auto&part:num)
            {
                if(part==0)
                    break;
                part*=j;
            }
        }
        result=splitBigNumber(num);
    }
    else {
    result=to_string(number);
    
    }

    cout<<result;*/
}
vector<unsigned long long int> bigNumberMerge(int number){
    vector<unsigned long long int> output;
    while(number>0)
    {
        output.push_back(number%100);
        number/=100;
    }
    return output;
}

string splitBigNumber(vector<unsigned long long int>number){
    string output="";
    vector<string>n;
    int iterator=0;
    int k;
    while(number.size()>0)
    {
        n.push_back(to_string(number.back()%100));
        k=number.back()/100;
        number.pop_back();
        number.back()+=k;
    }
    n.push_back(to_string(k));
    while(n.size()>0)
    {
        output+=n.back();
        n.pop_back();
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
