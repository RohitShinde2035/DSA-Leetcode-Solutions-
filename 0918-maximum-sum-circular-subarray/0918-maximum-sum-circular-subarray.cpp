class Solution {
public:

    int kadanes_max(vector<int>& nums, int n){
        int sum = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i<n; i++){
            sum = max(sum+nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }

    int kadanes_min(vector<int>& nums, int n){
        int sum = nums[0];
        int min_sum = nums[0];
        for(int i = 1; i<n; i++){
            sum = min(sum+nums[i], nums[i]);
            min_sum = min(min_sum, sum);
        }
        return min_sum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // total array's sum 
        int sum = accumulate(begin(nums), end(nums), 0);

        int max_sum = kadanes_max(nums, n);

        int min_sum = kadanes_min(nums, n);

        int circular_sum = sum - min_sum;

        if(max_sum > 0){
            return max(max_sum, circular_sum);
        }
        return max_sum;
    }
};