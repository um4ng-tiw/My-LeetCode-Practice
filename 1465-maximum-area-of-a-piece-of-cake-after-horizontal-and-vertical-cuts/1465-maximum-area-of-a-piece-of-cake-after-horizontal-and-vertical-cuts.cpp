class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCut, vector<int>& vCut) {
        
        int mod = 1e9 + 7;
        
        sort(hCut.begin(), hCut.end());
        sort(vCut.begin(), vCut.end());
        
        long long maxHCut = abs(hCut[0]);
        long long maxVCut = abs(vCut[0]);
        
        for(int i=0; i<hCut.size() - 1; i++){
            maxHCut = max(maxHCut, (long long)abs(hCut[i] - hCut[i+1]));
        }
        
        maxHCut = max(maxHCut, (long long)abs(hCut[hCut.size() - 1] - h));
        
        for(int i=0; i<vCut.size() - 1; i++){
            maxVCut = max(maxVCut, (long long)abs(vCut[i] - vCut[i+1]));
        }
        
        maxVCut = max(maxVCut,(long long)abs(vCut[vCut.size() - 1] - w));
        
        
        return ((maxHCut % mod) * (maxVCut % mod))%mod;

        
    
        
        
    }
};