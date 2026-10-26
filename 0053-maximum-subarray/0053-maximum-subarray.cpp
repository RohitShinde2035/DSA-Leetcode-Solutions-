class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sum = nums[0];
        int sumMax = 0;
        for(int x : nums){
            sumMax = max(sumMax + x, x);
            max_sum = max(sumMax, max_sum);
        }
        return max_sum;
        
    }
};