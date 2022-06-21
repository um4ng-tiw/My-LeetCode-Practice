class Solution {
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

    int n = heights.size();
    priority_queue<int> diff;

    int i;
    for(i=0; i<n-1; i++){
        
        int s = heights[i+1] - heights[i];
        
        if(s <= 0){
            continue;
        }
        else{
            bricks = bricks - s;
            diff.push(s);
            
            if(bricks < 0){
                bricks = bricks + diff.top();
                diff.pop();
                ladders--;
            }
        }
        
        if(ladders < 0){
            break;
        }
    }
    
    
    return i;
}
};