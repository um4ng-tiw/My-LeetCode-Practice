class Solution {
public:
    int minPartitions(string n) {
        
        int maxEl = INT_MIN;
        for(int i=0; i<n.size(); i++){
            if(n[i] == '9') return 9;
            maxEl = max(maxEl, n[i] - '0');
        }
        
        return maxEl;
        
    }
};