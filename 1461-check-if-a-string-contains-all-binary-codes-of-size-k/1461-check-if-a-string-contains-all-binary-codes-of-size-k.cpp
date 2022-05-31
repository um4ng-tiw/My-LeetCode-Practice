class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.size() < k) return false;
        unordered_set<string> st;
        
        for(int i=0; i<=s.size() - k; i++){
            st.insert(s.substr(i, k));
        }
        
        if(st.size() != (1<<k)) return false;
        
        return true;
        
        
    }
};