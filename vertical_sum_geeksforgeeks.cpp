//https://www.geeksforgeeks.org/problems/vertical-sum/1

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
    
    map<int,int> mp;
    
  public:
  
  void helper(Node* root , int column){
      if(!root){
          return;
      }
      mp[column]+= root->data;
      if(root->left){
          helper(root->left, column-1);
      }
      if(root->right){
          helper(root->right, column+1);
      }
  }
    vector <int> verticalSum(Node *root) {
        // add code here.
        helper(root, 0);
        vector<int> ans;
        for ( auto element : mp){
            ans.push_back(element.second);
        }
        
        return ans;
    }
};
