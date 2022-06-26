/*
Solution reference:
https://www.youtube.com/watch?v=TsA4vbtfCvo&ab_channel=NeetCode

Create a sliding window of n - k size
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = cardPoints.size() - k;
        int currSum = accumulate(cardPoints.begin() + r, cardPoints.end(), 0);
        int maxSum = currSum;
        
        while(r < cardPoints.size()){
            int addEl = cardPoints[l];
            int remEl = cardPoints[r];
            
            currSum = currSum - remEl + addEl;
            maxSum = max(maxSum, currSum);
            l++;
            r++;
            
        }
        
        return maxSum;
    }
};