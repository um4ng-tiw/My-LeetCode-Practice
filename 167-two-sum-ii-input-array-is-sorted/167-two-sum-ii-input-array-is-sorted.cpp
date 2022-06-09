class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int leftPtr = 0;
        int rightPtr = numbers.size() - 1;
        vector<int> ans;
        
        while(leftPtr < rightPtr){
            int currSum = numbers[leftPtr] + numbers[rightPtr];
            if(currSum == target){ ans = {leftPtr + 1, rightPtr + 1}; break;}
            if(currSum > target) rightPtr--;
            else leftPtr++;
            
        }
        
        return ans;
    }
};