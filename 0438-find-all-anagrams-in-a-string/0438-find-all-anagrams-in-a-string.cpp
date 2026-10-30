class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // with 2 maps

        vector<int> res;
        if(s.size() < p.size()) {
            return res;
        }
        unordered_map<char, int> pMap, sMap;
        for(char c : p){
            pMap[c]++;
        }
        int l = 0, count = p.size();
        for(int r = 0; r < s.size(); r++){
            char ch = s[r];
            sMap[ch]++;
            if(pMap.count(ch) && sMap[ch] <= pMap[ch]){ 
                count --;
            }
            if(r-l+1 > p.size()){
                char lchar = s[l];
                if(pMap.count(lchar) && sMap[lchar] <= pMap[lchar]){
                    count ++;
                }
                sMap[lchar]--;
                l++;
            }
            if(count == 0){
                res.push_back(l);
            }
        }
        return res;

    }
};