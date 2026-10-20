class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for( int i = 0; i<m; i++){
            for( int j = 0; j<n; j++){
                int sum = 0; 
                for(int r = i-k; r <= i+k; r++){
                    for(int c = j-k; c <= j+k; c++){
                        if(r>=0 && r<m && c>=0 and c<n){
                            sum += mat[r][c];
                        }
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;


    }
};