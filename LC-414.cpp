// Find Third Maximum Number

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // Use long long so LLONG_MIN can act as a sentinel value
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {

            // Skip duplicate values
            if (num == first || num == second || num == third)
                continue;

            // Update first, second and third maximums
            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        // If third distinct maximum doesn't exist, return the maximum
        return (third == LLONG_MIN) ? first : third;
    }
};