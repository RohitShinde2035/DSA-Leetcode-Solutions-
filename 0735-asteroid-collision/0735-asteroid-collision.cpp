class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            while(!st.empty() && a<0 && st.top()>0 && st.top() < -a){
                st.pop();
            }
            if(!st.empty() && a<0 && st.top() > 0){
                if(st.top() == -a){
                    st.pop();
                }
            }
            else{
                st.push(a);
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};