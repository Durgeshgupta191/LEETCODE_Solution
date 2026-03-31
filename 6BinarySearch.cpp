 #include<iostream>
 #include<vector>
 using namespace std;
 
 int main(){
    int arr[6]={1,33,45,67,78,89};
    int size=6;
    int str=0, end=size-1;
    int tar=78;

    while(str<=end){
       int mid=(str+end)/2;

        if(tar>arr[mid]){
            str=mid+1;
        }
        else if(tar<arr[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;

 }