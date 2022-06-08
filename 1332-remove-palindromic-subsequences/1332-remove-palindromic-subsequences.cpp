class Solution {
public:
    int removePalindromeSub(string s) {
        
        string original = s;
        
        reverse(original.begin(), original.end());
        
        if(original == s) return 1;
        
        return 2;
    }
};

