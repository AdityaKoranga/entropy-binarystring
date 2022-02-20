#include<bits/stdc++.h>
using namespace std;



double tsallis_Entropy(double window_size,string str){
       //to find the no. of windows--->
    int no_ofWindows=0;
    for(int i=0;i<str.size();i++){
        if((i+window_size)>str.size())
            break;
        no_ofWindows++;
        
    }
    

    //to find total sum of probability
    int start=0,end=start+window_size-1;
    int count=0;
    double probability=0;
    double total_probabilty_sum=0;

    for(int i=0;i<no_ofWindows;i++){
        

        for(int j=start;j<=end;j++){
            
            if(str[j]=='1'){
                count++;
            }
        }
        
        
        probability=count/window_size;
    
            total_probabilty_sum+=probability;
            
        start++;
        end++;
        count=0;
    }
    

        return total_probabilty_sum;
}

int main(){
string str="";
ifstream input_value;
input_value.open("input.csv");
cout<<" The string is"<<" ";

//string input--------->
while(input_value.eof()==0){
    getline(input_value,str);
    cout<<str<<endl;
    input_value.close();
}
ofstream output_value;
output_value.open("Outputt.csv");
double window_size;
cout<<"enter window size ";
cin>>window_size;
double ans=tsallis_Entropy(window_size,str);

for(double q=2;q<=4;q++){
    output_value<<"tsallis entropy for q="<<q<<" is = "<<(1 / (q-1) )*(1 - ans)<<endl;

    }
output_value.close();
return 0;
}