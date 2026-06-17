class Solution{
    public:

    int searchInsert(vector<int>&nums, int target){

        for(int i =0;i<nums.size();i++){
            if(nums[i]>=target){     //if target is equal or greater than nums[i];
                return i;   
            }

        }
        return nums.size();   // it run when target is bigger than other number so need to put in last
    }
};  