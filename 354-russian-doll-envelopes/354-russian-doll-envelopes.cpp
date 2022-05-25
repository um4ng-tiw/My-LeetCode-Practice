/*

Solution Reference:
https://leetcode.com/problems/russian-doll-envelopes/discuss/2071459/C%2B%2B-or-O(NlogN)-approach-or-LIS-or-Explaination-with-Comments

Look for longest increasing subsequence logic using binary search.
Sort the array in increasing fashion of the width and decreasing fashion of height
*/

class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]) return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> res;
        
        for(int i=0; i<envelopes.size(); i++){
            int element = envelopes[i][1];
            
            int idx = lower_bound(res.begin(), res.end(), element) - res.begin();
            
            if(idx >= res.size()) res.push_back(element);
            else res[idx] = element;
        }
        
        
        return res.size();
    }
};