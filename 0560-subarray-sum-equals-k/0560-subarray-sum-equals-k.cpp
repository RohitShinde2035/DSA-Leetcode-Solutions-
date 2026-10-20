class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0, sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i : nums){
            sum += i;
            // int target = sum - k;
            count += mp[sum-k];
            
            mp[sum]++;
        }
        return count;
    }
};