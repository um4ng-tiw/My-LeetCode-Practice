class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> frequencies(26, 0);
        
        for(int i=0; i<s.size(); i++){
            frequencies[s[i] - 'a']++;
        }
        
        int deleteCount = 0;
        
        unordered_set<int> seenFrequencies;
        
        for(int i=0; i<frequencies.size(); i++){
            while(frequencies[i] && seenFrequencies.find(frequencies[i]) != seenFrequencies.end()){
                frequencies[i]--;
                deleteCount++;
            }
            
            seenFrequencies.insert(frequencies[i]);
        }
        
        return deleteCount;
        
    }
};