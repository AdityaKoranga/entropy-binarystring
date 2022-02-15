#include<bits/stdc++.h>
using namespace std;

void counting_single_bits(string str,int size){
    int count0=0 , count1=0 ;
    int i=0;
    while( i<size){
        if( str[i]=='0'){
            count0+=1;
            i++;
        }
        else{
            count1 +=1;
            i++;
        
        }
    }
    cout<<"no. of 0 are"<<count0<<endl;
    cout<<"no. of 1 are"<<count1<<endl;
}

void counting_double_bits(string str,int size){
    int count00=0, count10=0, count01=0, count11=0;
    int i=0;
    while(i<size && i+1<size ){
        if(str[i]=='0' && str[i+1]=='0'){
            count00+=1;
            i++;
        }
        else if(str[i]=='0' && str[i+1]=='1'){
            count01+=1;
            i++;
        }
        else if(str[i]=='1' && str[i+1]=='0'){
            count10+=1;
            i++;
        }
        else {
            count11+=1;
            i++;
        }
    }
    cout<<"no. of 00 pairs are"<<count00<<endl;
    cout<<"no. of 01 pairs are"<<count01<<endl;
    cout<<"no. of 10 pairs are"<<count10<<endl;
    cout<<"no. of 11 pairs are"<<count11<<endl;
}

void counting_triple_bits(string str,int size){
    int count100=0, count101=0, count110=0, count001=0, count011=0, count111=0, count010=0, count000=0;
    int i=0;
    while(i<size && i+2<size ){
        if(str[i]=='1' && str[i+1]=='0' && str[i+2]=='0'){
            count100+=1;
            i++;
        }
        else if(str[i]=='1' && str[i+1]=='0' && str[i+2]=='1'){
            count101+=1;
            i++;
        }
        else if(str[i]=='1' && str[i+1]=='1' && str[i+2]=='0'){
            count110+=1;
            i++;
        }
        else if(str[i]=='0' && str[i+1]=='0' && str[i+2]=='0'){
            count001+=1;
            i++;
        }
        else if(str[i]=='0' && str[i+1]=='1' && str[i+2]=='1'){
            count011+=1;
            i++;
        }
        else if(str[i]=='1' && str[i+1]=='1' && str[i+2]=='1'){
            count111+=1;
            i++;
        }
        else if(str[i]=='0' && str[i+1]=='1' && str[i+2]=='0'){
            count010+=1;
            i++;
        }
        else {
            count000+=1;
            i++;
        }
    }
    cout<<"no. of 100 pairs are"<<count100<<endl;
    cout<<"no. of 101 pairs are"<<count101<<endl;
    cout<<"no. of 110 pairs are"<<count110<<endl;
    cout<<"no. of 001 pairs are"<<count001<<endl;
    cout<<"no. of 011 pairs are"<<count011<<endl;
    cout<<"no. of 111 pairs are"<<count111<<endl;
    cout<<"no. of 010 pairs are"<<count010<<endl;
    cout<<"no. of 000 pairs are"<<count000<<endl;
}
int main(){
    string str;
    cout<<"enter a binary string:";
    cin>>str;
    
    int size=str.length();
    
    counting_single_bits(str,size);
    counting_double_bits(str,size);
    counting_triple_bits(str,size);
return 0;
}