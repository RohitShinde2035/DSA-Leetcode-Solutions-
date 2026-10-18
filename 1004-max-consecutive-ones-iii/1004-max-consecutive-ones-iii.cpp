class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int count_zero = 0, max_count = 0, l = 0;

        for(int r = 0; r <nums.size(); r++){
            if(nums[r]==0){
                count_zero ++;
            }
            while(count_zero > k){
                if(nums[l]==0){
                    count_zero --;
                }
                l++;
            }
            max_count = max(max_count, r-l+1);
        }
        return max_count;
    }
};