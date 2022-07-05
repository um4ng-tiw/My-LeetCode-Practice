class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        int maxLen = 1;
        int currLen = 1;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            
            if(s.find(num - 1) == s.end()){
                num = num + 1;
                 while(true){
                if(s.find(num) != s.end()) {
                    num++;
                    currLen++;
                }
                else {
                    maxLen = max(maxLen, currLen);
                    currLen = 1;
                    break;
                }
            }   
            }
           
        }
        
        return maxLen;
    }
};