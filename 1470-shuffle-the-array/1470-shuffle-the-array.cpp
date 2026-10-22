class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2*n);
        int i = 0;
        while(i<n){
            ans[2*i] = nums[i];
            ans[2*i+1] = nums[i+n]; 
            i ++ ;
        }
        return ans;
    }
};