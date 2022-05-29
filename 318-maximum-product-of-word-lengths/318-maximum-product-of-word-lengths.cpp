class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        bool flag = false;
        
        int maxLength = 0;
        
        for(int i=0; i<words.size(); i++){
            vector<int> charCount(26, 0);
            for(char &ch: words[i]) charCount[ch - 'a']++;
            for(int j=i+1; j<words.size(); j++){
                flag = false;

                for(char &ch: words[j]){
                    if(charCount[ch - 'a']){
                        flag = true;
                        break;
                    }
                }
                
                if(not flag){
                    int currLength = words[i].size() * words[j].size();
                    maxLength = max(maxLength, currLength);
                }
            }
        }
        
        return maxLength;
    }
};