class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();
        vector<int> ans(2*n);

        while(i<n){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
            i++;
        }
        return ans;
    }
};