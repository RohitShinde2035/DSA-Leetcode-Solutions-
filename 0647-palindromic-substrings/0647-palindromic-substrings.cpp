class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        // int strt = 0, end = 0;
        for(int i = 0; i<n; i++){
            // int len1 = expand(s, i, i);
            // int len2 = expand(s, i, i+1);
            // int len = max(len1, len2);
            // if(len>(end-strt)){
            //     strt = i - (len-1)/2;
            //     end = i + len/2;
            // }
            count += expand(s, i, i);
            count += expand(s, i, i+1);
        }
        return count;
    }
private:
    int expand(string& s, int l, int r){
        int count = 0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        return count;
    }
};