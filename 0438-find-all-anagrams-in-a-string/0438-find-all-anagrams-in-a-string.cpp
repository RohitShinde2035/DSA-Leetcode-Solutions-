class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        int n = s.size();
        int k = p.size();

        vector<int> pcount(26,0);

        for(char c : p){
            pcount[c - 'a']++;
        }
        for(int i = 0; i<= n-k; i++){
            vector<int> scount(26,0);
            for(int j = i; j < i+k; j++){
                scount[s[j] - 'a']++;
            }
            if(pcount == scount){
                res.push_back(i);
            }
        }
        return res;

    }
};