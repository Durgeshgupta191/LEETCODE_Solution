// program to print the factorial number

#include <iostream>
using namespace std;

int factorial(int n){     //Recursive funtion
    
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);    //function calling itself
    }
}

int main(){
    
    cout<<factorial(4);
    return 0;
}