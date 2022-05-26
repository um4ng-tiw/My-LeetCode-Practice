class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        stack<pair<int, int>> st;
        
        for(int i=0; i<intervals.size(); i++){
            
            if(!st.empty()){
                int newX, newY;
                
                int x1 = st.top().first;
                int y1 = st.top().second;
                
                int x2 = intervals[i][0];
                int y2 = intervals[i][1];
            
                // This means the all numbers of second interval come inside the first interval
                if(x2 <= y1 && y2 <= y1){
                    st.pop();
                    st.push({x1, y1});
                    continue;
                }
                
                if(x2 <= y1 && y2 >= y1){
                    st.pop();
                    st.push({x1, y2});
                    continue;
                }
            }
            
            st.push({intervals[i][0], intervals[i][1]});
            
            
            
        }
        
        vector<vector<int>> res;
        
        while(!st.empty()){
            vector<int> arr(2);
            arr[0] = st.top().first;
            arr[1] = st.top().second;
            res.push_back(arr);
            st.pop();
            
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};