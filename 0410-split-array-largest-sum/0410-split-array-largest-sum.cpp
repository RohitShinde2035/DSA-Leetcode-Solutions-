class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canSplit(mid, nums, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    bool canSplit(int maxSum, vector<int>& nums, int k){
        int count = 1;
        int sum = 0;
        for(int num : nums){
            if(sum + num <= maxSum){
                sum += num;
            }
            else{
                count ++;
                sum = num;
            }
        }
        if(count<=k){
            return true;
        }
        return false;
    }
};