class Solution {
public:
    string longestPalindrome(string s) {
        
        string res = "";
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(fun(s,i,j) == true){
                    if(j-i+1 > res.size()){
                        res = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;

    }
private:
    bool fun(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }

};