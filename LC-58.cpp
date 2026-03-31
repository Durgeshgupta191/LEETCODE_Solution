class Solution {
public:
    int lengthOfLastWord(string s) {

        reverse(s.begin(),s.end());
        int count=0;

        for(char c :s){
            if( c != ' '){
                count = count+1;
            }
            else if(count>0){
                break;
            }
        }
        return count;
    }
};