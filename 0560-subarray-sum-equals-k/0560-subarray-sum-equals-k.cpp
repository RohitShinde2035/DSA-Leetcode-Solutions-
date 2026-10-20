class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0, sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int x : nums){
            sum += x;
            // int target = sum - k;
            if(mp.count(sum - k)){
                count += mp[sum-k];
            }
            mp[sum] += 1;
        }
        return count;
    }
};