class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int sumMax = 0, sumMin = 0;
        int max_sum = nums[0], min_sum = nums[0];

        for(int x : nums){
            sumMax = max(sumMax + x, x);
            max_sum = max(sumMax, max_sum);

            sumMin = min(sumMin + x, x);
            min_sum = min(sumMin, min_sum);
        } 

        if(abs(min_sum) > max_sum){
            return abs(min_sum);
        }
        return max_sum;

    }
};