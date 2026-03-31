// JUMP II

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;      // total jumps made
        int currEnd = 0;    // farthest we can go in current jump
        int farthest = 0;   // farthest we can go overall

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]); // update max reach from this index

            // When we reach the end of the current jump's range,
            // we must increase jump and update the range
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};
