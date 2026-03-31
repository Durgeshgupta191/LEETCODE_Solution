    //WAP to print Number between (n to 1), where n is a poitive integer //
   //*******************************************************************//

#include <iostream>
using namespace std;

int PrintNumber(int n){         //Recursive funtion
    if(n==1){                   //It is used to stop the function calling itself when it reach at last value
        cout<<"1\n";
        return 1;
    }
    else{
        cout<<n<<" ";
        PrintNumber(n-1);       //Function calling itself
    }
}

int main(){
    PrintNumber(10);            //Calling function
    return 0;
}







