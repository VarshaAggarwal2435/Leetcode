class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp = matrix;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    int mn = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                    dp[i][j] = mn;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};

/*
1 0 1
1 1 0
1 1 0
*/