class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = 0, sumMax = 0, sumMin = 0;
        int max_sum = nums[0], min_sum = nums[0];

        for(int x : nums){
            sumMax = max(sumMax + x, x);
            max_sum = max(sumMax, max_sum);

            sumMin = min(sumMin + x, x);
            min_sum = min(sumMin, min_sum);

            total += x;
        }

        if(max_sum > 0){
            return max(max_sum, total-min_sum);
        }
        return max_sum;
    }
};