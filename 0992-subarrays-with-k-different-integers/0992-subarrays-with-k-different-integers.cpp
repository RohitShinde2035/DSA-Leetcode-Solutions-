class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }

private:
    int atmost(vector<int> nums, int k){
        int l = 0, count = 0;
        unordered_map<int, int> mp ;

        for(int r = 0; r<nums.size(); r++){
            mp[nums[r]] += 1;
            while(mp.size()>k){
                mp[nums[l]] -= 1;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count += r-l+1;
        }
        return count;
    }

};