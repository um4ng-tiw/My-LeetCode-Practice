class Solution {
public:
    static bool cmp(vector<int> &el1, vector<int>&el2){
        if(el1[1] == el2[1]) return el1[0] > el2[0];
        return el1[1] > el2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int maxUnits = 0;
        
        
        for(auto it: boxTypes){
           if(it[0] <= truckSize){
               maxUnits += (it[0] * it[1]);
               truckSize -= it[0];
           }else if(truckSize == 0) break;
            else{
                maxUnits+= truckSize * it[1];
                truckSize = 0;
            }
        }
        
        return maxUnits;
        
    }
};