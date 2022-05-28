class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorVal = 0;
        int xorValMissing = nums[0];
        
        for(int i=1; i<=nums.size(); i++){
            xorVal ^= i;
            if(i < nums.size()) xorValMissing ^= nums[i];
            
        }
        
        return xorVal ^ xorValMissing;
    }
};