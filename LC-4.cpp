
class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {

        vector<int> nums;

        int i = 0;
        int j = 0;

        // Merge both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements of nums1
        while (i < nums1.size()) {
            nums.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements of nums2
        while (j < nums2.size()) {
            nums.push_back(nums2[j]);
            j++;
        }

        int n = nums.size();

        // If total elements are odd
        if (n % 2 != 0) {
            return nums[n / 2];
        }
        else {
            // If total elements are even
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }
    }
};

