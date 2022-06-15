class Solution {
public:
    static bool compare(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        
        unordered_map<string, int> dp;
        
        int res = 0;
        
        for(string w: words){
            dp[w] = 1;
            for(int i=0; i<w.size(); i++){
                string pre = w.substr(0, i) + w.substr(i+1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            
            res = max(res, dp[w]);
        }
        
        return res;
        
    }
};