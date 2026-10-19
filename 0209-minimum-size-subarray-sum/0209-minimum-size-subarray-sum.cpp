class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        long long sum = 0, l = 0;
        long long ans = INT_MAX;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum>=target){
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        if ( ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};