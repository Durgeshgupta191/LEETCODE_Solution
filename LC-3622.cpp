class Solution{
    public:
    bool checkDivisibility(int n){

        int sum=0;
        int prod=1;
        int num = n;

        while(num>0){
            sum += num%10;
            prod*= num%10;
            num=num/10;
        }

        int total =sum+prod;

        if(n%total!=0){
            return false;
        }
       return true;
    }
};