class Solution {
public:
	static bool comparator(string a, string b){
		//if equal size 
		if (a.size() == b.size())
			return a > b;

		return a.size() > b.size();
	}


int minimumLengthEncoding(vector<string>& words) {
    string reference;
    sort(words.begin(), words.end(), comparator);
    for (auto word : words){
        if (reference.find(word + "#") == string::npos){
            reference += word + "#";
        }
    }
    
    return reference.size();
}
};