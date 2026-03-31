// Sum of n numbers using recursion 

#include <iostream>
using namespace std;

int sum(int n){     //Recursive funtion
    
    if(n==1){
        return 1;
    }
    else{
        return n + sum(n-1);    //function calling itself
    }
}

int main(){
    
    cout<<sum(5);
    return 0;
}