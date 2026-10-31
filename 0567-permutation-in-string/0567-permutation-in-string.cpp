class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> f1(26,0), f2(26,0);
        int l = 0;
        for(char c : s1){
            f1[c-'a']++;
        }
        for(int r = 0; r < s2.size(); r++){
            f2[s2[r]-'a']++;
            if(r-l+1 > s1.size()){
                f2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1 == s1.size()){
                if(f1 == f2){
                    return true;
                }
            }
        }
        return false;
    }
};