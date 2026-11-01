#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> tMap;
        for(char c : t){
            tMap[c]++;
        }

        int l = 0, count = t.size();
        int minlen = INT_MAX;
        int lans = 0, rans = 0;

        for(int r = 0; r < s.size(); r++){
            char ch = s[r];

            if(tMap.count(ch)){
                if(tMap[ch] > 0) count --;
                tMap[ch]--;
            }
            while(count == 0){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    lans = l;
                    rans = r;
                }
                char lchar = s[l];
                if(tMap.count(lchar)){
                    tMap[lchar]++;
                    if(tMap[lchar] > 0) count ++;
                }
                l++;
            }
        }
        if(minlen == INT_MAX) return "";

        return s.substr(lans, rans-lans+1);


    }
};