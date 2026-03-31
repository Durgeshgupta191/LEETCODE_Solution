//Merge Interval

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // If the input list is empty, return empty result
        if (intervals.size() == 0)
            return {};

        // Step 1: Sort intervals based on their starting time
        // Example: [[1,3],[2,6],[8,10]] → sorted automatically by start
        sort(intervals.begin(), intervals.end());

        // This vector will store the final merged intervals
        vector<vector<int>> result;

        // Step 2: Add the first interval to the result
        // It becomes the reference for merging
        result.push_back(intervals[0]);

        // Step 3: Traverse remaining intervals one by one
        for (int i = 1; i < intervals.size(); i++) {

            // Last interval already present in result
            int lastStart = result.back()[0]; // start of last merged interval
            int lastEnd = result.back()[1];   // end of last merged interval

            // Current interval from the input list
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // Step 4: Check if current interval overlaps with last interval
            // Overlap condition: current start <= last end
            if (currStart <= lastEnd) {

                // Merge intervals by extending the end
                result.back()[1] = max(lastEnd, currEnd);

            } else {
                // If no overlap, add current interval as a new interval
                result.push_back(intervals[i]);
            }
        }

        // Return all merged non-overlapping intervals
        return result;
    }
};
