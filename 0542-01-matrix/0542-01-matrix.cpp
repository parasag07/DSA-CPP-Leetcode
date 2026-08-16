class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(i > 0 && mat[i-1][j] == 1 && ans[i-1][j] == 0){
                ans[i-1][j] = ans[i][j] + 1;
                q.push({i-1, j});
            }

            if(i+1 < mat.size() && mat[i+1][j] == 1 && ans[i+1][j] == 0){
                ans[i+1][j] = ans[i][j] + 1;
                q.push({i+1, j});
            }

            if(j > 0 && mat[i][j-1] == 1 && ans[i][j-1] == 0){
                ans[i][j-1] = ans[i][j] + 1;
                q.push({i, j-1});
            }

            if(j+1 < mat[i].size() && mat[i][j+1] == 1 && ans[i][j+1] == 0){
                ans[i][j+1] = ans[i][j] + 1;
                q.push({i, j+1});
            }
        }

        return ans;
    }
};