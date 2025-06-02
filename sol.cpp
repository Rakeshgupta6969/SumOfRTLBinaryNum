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

    void solve(vector<int> &ans,int & sum,TreeNode* root){
      
      if(root == NULL) return;
  
         ans.push_back(root -> val);
      if(root -> left == NULL && root -> right == NULL){
  
         reverse(ans.begin(),ans.end());
  
  
         int p = 0;
  
         for(int i = 0; i<ans.size(); i++){
  
  
          p +=  ans[i]* pow(2,i);
         }
       
       sum += p;
       reverse(ans.begin(),ans.end());
       ans.pop_back();
       return;
      }
     
  
      solve(ans,sum,root -> left);
      solve(ans,sum,root -> right);
  
        ans.pop_back(); // removing the present state. backtracking
  
  
  
    }
  
  
  
  public:
      int sumRootToLeaf(TreeNode* root) {
        
         // using the brute force solution.
  
         int sum = 0;
         vector<int> ans ;
  
         solve(ans,sum,root);
  
         return sum;
  
  
  
  
      }
  };