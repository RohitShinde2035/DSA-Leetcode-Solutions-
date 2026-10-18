class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1) return 0;

        int  l = 0, r = 0, count = 0, product = 1;

        for(int r = 0; r < nums.size(); r++){
            product *= nums[r];
            while(product>=k){
                product = product / nums[l];
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
};