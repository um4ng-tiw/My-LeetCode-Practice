/*
Solution Approach:
Check how many numbers have the same bit set. Return the max count.


*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        unordered_map<int, int> m;
        
        for(int i=0; i<candidates.size(); i++){
            int num = candidates[i];
            int bitCount = 1;
            while(num){
                if(num & 1) m[bitCount]++;
                bitCount++;
                num>>=1;
            }
        }
        
        int largest = INT_MIN;
        
        for(auto &it: m){
            largest = max(largest, it.second);
        }
        
        return largest;
        
    }
};