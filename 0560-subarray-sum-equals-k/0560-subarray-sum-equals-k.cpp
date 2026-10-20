class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0, sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            if(mp.count(target)){
                count += mp[target];
            }
            mp[sum] += 1;
        }
        return count;
    }
};