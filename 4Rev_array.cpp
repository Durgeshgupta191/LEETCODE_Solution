#include<iostream>
using namespace std;

//function for reverse an array............
void ReverseArr(int arr, int size){
    int start=0,end=size-1;

    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
     
     ReverseArr(arr,5);

     for(int i=0;i<5;i++){
            cout<<arr[i]<<"";
     }
    return 0;
}