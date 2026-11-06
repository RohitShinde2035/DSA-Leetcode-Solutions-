class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canReach(dist, hour, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    bool canReach(vector<int>& dist, double hour, int speed){
        double time = 0.0;
        for(int i = 0; i < dist.size(); i++){
            double t = (double)dist[i]/speed;
            if(i!=dist.size()-1){
                time += ceil(t);
            }
            else{
                time += t;
            }
        }
        return time<=hour;
    }
};