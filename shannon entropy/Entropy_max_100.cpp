#include <bits/stdc++.h>
using namespace std;

double calculateEntropy(string str,int start,int end,int window_size,double& sum)
{   
    
    int count=0;
    for(int i=start;i<end;i++){
        
        
        if(str[i]=='1')
        count++;
    }
    
    double probability=(double)count/double(window_size);
    
    double p=probability;
    
    if(p==1)
        return 0;
    
    double shan_entpy= -( (p) * ( log2f(p) ) );
    sum=sum+shan_entpy;
    return shan_entpy;

    
}
int main()
{
    string str="";
    ifstream Input_value;
    Input_value.open("input.csv");
    
    
    
    while(Input_value.eof()==0){
        getline(Input_value,str);
        // cout<<str<<endl;
        Input_value.close();
    }
    cout<<"size of string is "<<str.size()<<endl;

    ofstream output;
    output.open("Outputt.csv");
    double sum=0;
    
    int no_of_entropies;
    int  window_size;
    cout<<endl<<"the no.of entropies you want : ";
    cin>>no_of_entropies;
    cout<<endl;
    window_size=str.size()-(no_of_entropies-1);
    cout<<"window size will be "<<window_size<<endl;
    for(int i=0;i<no_of_entropies;i++){
        output<<"entropy "<<i+1<<"is "<<setprecision(50)<<calculateEntropy(str,i, window_size+i, window_size,sum)<<endl;
    }
    output<<endl<<"the average shannon entropy is "<< sum / no_of_entropies <<endl;
    

    
    output.close();


    return 0;
}