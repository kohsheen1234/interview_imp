//https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  public:
  
  int helper(vector<int>& ans, vector<int>& arr, int n,int index, int sum){
      //generate alll subsets
      if(index==n){
          ans.push_back(sum);
          return sum;
      }
      
      helper(ans, arr, n, index+1,sum+arr[index]);
      sum = sum - arr[index];
      helper(ans, arr, n, index+1,sum);
      return sum;
      
  }
  
  
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        helper(ans, arr,n,0,0);
        return ans;
    }
};
