class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0, count_zero=0, max_count = 0;

        for(int r = 0; r<nums.size(); r++){
            if(nums[r]==0){
                count_zero ++;
            }
            if(count_zero>k){
                if(nums[l]==0){
                    count_zero --;
                }
                l++;
            }
        }
        return nums.size()-l;

    }
};