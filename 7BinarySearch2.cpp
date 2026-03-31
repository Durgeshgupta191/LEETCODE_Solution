// By creating binary search function 

#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> arr, int tar){    //Creating Function of binary search 
    int str=0, end=arr.size()-1;

   while(str<=end){
    int mid = (str=end)/2;

    if(tar>arr[mid]){
        str=mid+1;
    }
    else if(tar<arr[mid]){
        end= mid-1;
    }
    else{
        return mid;
    }
}
    return -1;
}

int main()
{
    vector<int> arr1={11,22,33,44,55,66,77,88};
    int tar1=66;

    cout<<BinarySearch(arr1,tar1); //calling function an print

    return 0;

}