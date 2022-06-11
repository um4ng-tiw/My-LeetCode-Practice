class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int deletionSum = totalSum - x;
        
        int left = 0;
        int right = 0;
        
        int maxSize = INT_MIN;
        int currSum = 0;
        
        while(right < nums.size()){
            currSum += nums[right];
            
            while(left <= right && currSum > deletionSum) currSum -= nums[left++];
            
            if(currSum == deletionSum){
                maxSize = max(maxSize, right - left + 1);
            }
            
            right++;
        }
        
        if(maxSize == INT_MIN) return -1;
        
        return nums.size() - maxSize;
    }
};