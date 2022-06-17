/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int cameraCount = 0;
    
    int NEEDS_CAMERA = 0;
    int HAS_CAMERA = 1;
    int COVERED = 2;
    int NOT_NEEDED = 3;
    
    int minCameraCover(TreeNode* root) {
        cameraCount = solve(root) == NEEDS_CAMERA ? cameraCount+1 : cameraCount;
        return cameraCount;
    }
    
    int solve(TreeNode* root){
        if(root == NULL) return NOT_NEEDED;
        
        if(root->left == NULL && root->right == NULL){
            return NEEDS_CAMERA;
        }
        
        int leftStatus = solve(root->left);
        int rightStatus = solve(root->right);
        
        if(leftStatus == NEEDS_CAMERA || rightStatus == NEEDS_CAMERA){
            cameraCount+=1;
            return HAS_CAMERA;
        }
        
        if(leftStatus == HAS_CAMERA || rightStatus == HAS_CAMERA){
            return COVERED;
        }
        
        return NEEDS_CAMERA;
    }
};