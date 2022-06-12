/*
Solution Reference: https://www.youtube.com/watch?v=2X2hGiDUmtg&ab_channel=CodingDecoded

Approach: 
Keep inserting it in the set. If its found keep removing and increasing the start pointer.

*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxSum = 0, runningSum = 0;
        
        unordered_set<int> s;
        for(int i=0, j=0; j<n; j++){
            while(s.find(nums[j]) != s.end()){
                s.erase(nums[i]);
                runningSum -= nums[i];
                i++;
            }
            
            s.insert(nums[j]);
            runningSum+=nums[j];
            maxSum = max(maxSum, runningSum);
        }
        
        return maxSum;
    }
};