class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> m;
        
        int l = 0;
        int r = 0;
        
        int maxLen = 0;
        int currLen = 0;
        
        while(r < s.size()){
            if(m.find(s[r]) != m.end())
                l = max(m[s[r]] + 1, l);
            
            m[s[r]] = r;                         
            currLen = r - l + 1;
            maxLen = max(maxLen, currLen);
            r++;
        }
        
        return maxLen;
        
    }
};