class Solution {
public:
    static bool cmp(vector<int> &el1, vector<int>&el2){
        return el1[1] > el2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int maxUnits = 0;
        
        
        for(auto it: boxTypes){
           int nUnits = min(it[0], truckSize);
           maxUnits += nUnits * it[1];
           truckSize -= nUnits;
           if(!truckSize) break;
        }
        
        return maxUnits;
        
    }
};