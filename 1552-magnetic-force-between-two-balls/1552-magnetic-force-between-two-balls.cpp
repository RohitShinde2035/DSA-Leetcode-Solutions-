class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n-1]-position[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isvalid(mid, position, m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    bool isvalid(int dist, vector<int>& pos, int m){
        int count = 1, last = pos[0];
        for(int i = 1; i<pos.size(); i++){
            if(pos[i] - last >= dist){
                count ++;
                last = pos[i];
            }
            if(count >= m ) return true;
        }
        return false;
    }
};