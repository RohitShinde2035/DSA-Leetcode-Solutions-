class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int ans = 0, l = 0;
        unordered_map<int, int> mp;
        
        for( int r = 0; r < fruits.size() ; r++){
            mp[fruits[r]]+=1;
            if(mp.size()<=2){
            }
            while(mp.size()>2){
                mp[fruits[l]]-=1;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans,  r-l+1);
        }
        return ans;
    }
};