/*


Solution Reference:
https://leetcode.com/problems/merge-intervals/discuss/1644017/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-Friendly-with-Detailed-Explanations

Check if the coming interval lies within the previous interval or extends the previous interval
and push inside the resultant vector

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        int j = 0;
        
        for(int i=1; i<intervals.size(); i++){
            
            if(res[j][1] >= intervals[i][0]) res[j][1] = max(res[j][1], intervals[i][1]);
            else{
                j++;
                res.push_back(intervals[i]);
            }
        }
        
        return res;
        
    }
};