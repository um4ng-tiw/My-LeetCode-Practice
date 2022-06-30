class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int median = 0;
        
        if(nums.size() % 2 == 0){
            median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2])/2;
        }else median = nums[nums.size() / 2];
        
        
        int minMoves = 0;
        
        for(int i=0; i<nums.size(); i++){
            minMoves += abs(nums[i] - median);            
        }
        
        return minMoves;
    }
};