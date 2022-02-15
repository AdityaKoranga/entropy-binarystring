#include <bits/stdc++.h>
using namespace std;

double calculateEntropy(string str, int size,int start,int end)
{   
    int count=0;
    for(int i=start;i<end;i++){
        if(str[i]=='1')
        count++;
    }
    double probability=(double)count/size;
    double p=probability/size;
    return -((p) * log2f(p));
    
}
int main()
{
    string str;
    cout << "enter a binary string : ";
    cin >> str;

    int  window_size;
    cout<<"enter the window size : ";
    cin>>window_size;
    int no_ofWindows=0;
    for(int i=0;i<str.size();i++){
        if((i+window_size)>str.size())
            break;

        no_ofWindows++;
    }
    int end=window_size;
    for(int i=0;i<no_ofWindows;i++){
        cout<<"entropy "<<i+1<<": " <<calculateEntropy(str,str.size(),i,end)<<endl;
        end++;
    }


    return 0;
}