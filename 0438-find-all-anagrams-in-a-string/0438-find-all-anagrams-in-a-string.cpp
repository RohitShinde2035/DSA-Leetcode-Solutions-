class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        if(s.size() < p.size()){
            return res;
        }
        unordered_map<char, int> mp;
        for(char c : p){
            mp[c]++;
        }
        int l = 0, count = p.size();
        for(int r = 0; r < s.size(); r++){
            char ch = s[r];
            int val = mp[ch];
            if(val > 0){
                count--;
            }
            mp[ch]--;
            if(r-l+1 > p.size()){
                char lchar = s[l];
                int lval = mp[lchar];
                if(lval >= 0){
                    count++;
                }
                mp[lchar]++;
                l++;
            }
            if(count == 0){
                res.push_back(l);
            }
        }
        return res;

    }
};