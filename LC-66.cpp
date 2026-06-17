class Solution{
    public:
    vector<int> plusOne(vector<int>&digit){
        
        int i= digit.size()-1;
        while(i>=0){
            if(digit[i]<9){
                digit[i]++;
                return digit;
            }
            else{
                digit[i]=0;
                i--;
            }
        }
        digit.insert(digit.begin(),1);   // if all element is nine then add one at begin
        return digit;
    }
};