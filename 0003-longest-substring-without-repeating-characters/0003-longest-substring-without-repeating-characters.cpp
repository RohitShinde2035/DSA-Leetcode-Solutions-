class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0, l = 0;

        unordered_map<char, int> mp;
        for(int r = 0; r < s.size(); r++){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};