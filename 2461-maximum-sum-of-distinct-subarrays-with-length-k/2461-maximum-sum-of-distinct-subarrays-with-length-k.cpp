class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long result = 0;
        long long w_sum = 0;

        unordered_set<int> st;
        int i = 0, j = 0;

        while(j < nums.size()){
            while(st.count(nums[j])){
                w_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            w_sum += nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                result = max(result, w_sum);
                w_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
    return result;  
    }
};