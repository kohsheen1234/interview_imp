// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       sort(arr.begin(), arr.end());
       sort(dep.begin(), dep.end());
       int n = arr.size();
       
       int minPlatforms = INT_MIN;
       int platforms =0;
       
       int i = 0;
       int j = 0;
        while (i < n || j < n) { // Change here to ensure all events are processed
            if (i < n && (j == n || arr[i] <= dep[j])) {
              i++;
              platforms++;
           }
           else{
               j++;
               platforms--;
           }
           minPlatforms = max(platforms, minPlatforms);
       }
       
       return minPlatforms;
       
    }
};
