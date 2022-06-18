class WordFilter {
    unordered_map<string,int> m;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        
        for(int i=0;i<words.size();i++){
            
            string word = words[i];
            int wordsize = word.size();
            
            for(int j=1;j<=wordsize;j++){
                string p = word.substr(0,j);
                
                for(int k=0;k<wordsize;k++){
                    string s = word.substr(k,wordsize);
                    
                    m[p+"#"+s] = i + 1;
                    
                }
            }
            
            
            
        }
    }
    
    int f(string prefix, string suffix) {

            
//instead of using m.count, what we can do is store indexes +1 and while returning we can return index - 1, so even if the suffix and prefix doesnt exist in dictionary, the value in map will be 0(default value in un... map) == pre and suff combination with index 0.
            
            return m[prefix+"#"+suffix] - 1;
        
        /*
         or 
         if(m.count(prefix+"#"+suffix)!=0){
            return m[prefix+"#"+suffix];
         }else{
            return -1;
         }
        
        */
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
