class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int res = solve(nums, 0, nums.size() -1, k);
        return res;
        
    }
    
    int solve(vector<int>&nums, int l, int r, int k){
        
        int pivot = nums[r];
        int p = l;
        for(int i=l; i<r; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[p]);
                p+=1;
            }
        }
        
        swap(nums[p], nums[r]);
        if(p < k) return solve(nums, p+1, r, k);
        else if(p > k) return solve(nums, l, p-1, k);
        
        return nums[p];
    }
};