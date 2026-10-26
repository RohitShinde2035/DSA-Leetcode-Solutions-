class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prodMax = nums[0], prodMin = nums[0];
        int max_prod = nums[0];

        for(int i = 1; i<nums.size(); i++){
            // if(x == nums[0]){
            //     continue;
            // }

            int x = nums[i];
            int temp = prodMax;

            prodMax = max({temp*x, prodMin*x, x});
            prodMin = min({temp*x, prodMin*x, x});

            max_prod = max(prodMax, max_prod);
        }
        return max_prod;

    }
};