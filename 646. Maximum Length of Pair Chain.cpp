class Solution {
public:

    bool static compare(const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int ans = 0;
        if(n==0){
            return ans;
        }
        ans = 1;

        sort(pairs.begin(),pairs.end(), compare);
        int last_time = pairs[0][1];
        for(int i = 1; i<n;i++){
            if(pairs[i][0]>last_time){
                last_time = pairs[i][1];
                ans++;
            }
        }

        return ans;
        
    }
};
