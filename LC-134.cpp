class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0, totcost = 0;

        // Calculate total gas and total cost
        for(int val : gas){
            totgas += val;
        }
        for(int val : cost){
            totcost += val;
        }

        // If total gas is less than total cost, it's impossible to complete the circuit so return -1;
        if(totgas < totcost){
            return -1;
        }

        int start = 0;     // Start index of the gas station
        int currgas = 0;   // Current gas in the tank while traveling

        // Iterate through each gas station
        for(int i = 0; i < gas.size(); i++){
            // Calculate net gas after visiting this station
            currgas += (gas[i] - cost[i]);

            // If we can't reach the next station from here
            if(currgas < 0){
                // Reset the start point to the next station
                start = i + 1;
                // Reset current gas to 0 as we are starting fresh
                currgas = 0;
            }
        }

        // Return the valid starting index
        return start;
    }
};
