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
        unordered_map<char, int> sMap;
        int minlen = INT_MAX;
        int lans = 0, rans = 0;

        for(int r = 0; r < s.size(); r++){
            // char ch = s[r];
            sMap[s[r]]++;

            if(tMap.count(s[r]) && tMap[s[r]] >= sMap[s[r]]){
                count --;
            }

            while(count == 0){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    // ans = s.substr(l,r-l+1);
                    lans = l;
                    rans = r;
                }
                // char lchar = s[l];
                sMap[s[l]] --;
                if(tMap.count(s[l]) && tMap[s[l]] > sMap[s[l]]){
                    count++;
                }
                l++;
            }
        }
        if(minlen == INT_MAX) return "";

        return s.substr(lans, rans-lans+1);


    }
};