class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        int LCS_n = LCS(word1, word2, n1-1, n2-1, dp);
        
        return ((n1 + n2) - (2*LCS_n));
        
    }
    
    int LCS(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1 + LCS(s1, s2, ind1-1, ind2-1, dp);
        
        return dp[ind1][ind2] = max(LCS(s1, s2, ind1-1, ind2, dp), LCS(s1, s2, ind1, ind2-1, dp));
    }
};