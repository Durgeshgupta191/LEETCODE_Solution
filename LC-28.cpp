
class Solution{
    public:
    int strStr(string haystack , string needle){

        int n =haystack.length();
        int m = needle.length();

        if(n==0 || m==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }
        return -1;
    }
};