class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);

        res[0] = 1;

        for(int i = 1; i<n ; i++){
            res[i] = res[i-1] * nums[i-1]; 
        }

        int right_product = 1;

        for(int r = n-1; r >= 0; r--){
            res[r] = res[r] * right_product;
            right_product *= nums[r];
        }
        return res;
    }
};