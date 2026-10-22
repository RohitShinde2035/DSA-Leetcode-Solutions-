class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        long long count = 0, sum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int num : nums){
            sum += num;
            int rem = sum % k;
            if(rem<0){
                rem += k;
            }
            if(mp.count(rem)){
                count += mp[rem];
            }
            mp[rem] ++;
        }
        return count;
    }
};