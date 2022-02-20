#include <bits/stdc++.h>
using namespace std;

double calculateEntropy(string str, int size,int start,int end,int window_size)
{   
    int count=0;
    for(int i=start;i<end;i++){
        if(str[i]=='1')
        count++;
    }
    double probability=(double)count/window_size;
    double p=probability/size;
    return -((p) * log2f(p));
    
}
int main()
{
    string str="";
    ifstream Input_value;
    Input_value.open("input.csv");
    cout<<"the string is: ";
    
    while(Input_value.eof()==0){
        getline(Input_value,str);
        cout<<str<<endl;
        Input_value.close();
    }

    ofstream output;
    output.open("Outputt.csv");
    

    int  window_size;
    cout<<endl<<"enter the window size : ";
    cin>>window_size;
    int no_ofWindows=0;
    for(int i=0;i<str.size();i++){
        if((i+window_size)>str.size())
            break;

        no_ofWindows++;
    }
    int end=window_size;
    for(int i=0;i<no_ofWindows;i++){
        output<<"entropy "<<i+1<<": " <<calculateEntropy(str,str.size(),i,end,window_size)<<endl;
        end++;
    }
    output.close();


    return 0;
}