/*
Solution reference: https://www.youtube.com/watch?v=voObxZxXoZw&ab_channel=CodingDecoded
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long maxSum = 0;
        
        for(auto it: target){
            pq.push(it);
            maxSum+=it;
        }
        
        while(!pq.empty()){
            int maxEl = pq.top();
            pq.pop();
            long remSum = maxSum - maxEl;
            
            if(remSum == 1 || maxEl == 1) return true;
            if(remSum == 0 || maxEl < remSum) return false;
            int difference = maxEl % remSum;
            
            if(difference == 0) return false;
            pq.push(difference);
            
            maxSum = difference + remSum; 
        }
        
        return true;
    }
};