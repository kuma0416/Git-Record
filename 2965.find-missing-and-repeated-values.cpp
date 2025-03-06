class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans;
            int gLen=grid.size(), prefix=0;
            vector<bool> visited(gLen*gLen+1, false);
            for(int i=0; i<gLen; ++i){
                for(int j=0; j<gLen; ++j){
                    if(visited[grid[i][j]]==false){
                        visited[grid[i][j]]=true;
                        prefix+=grid[i][j];
                    } else {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            ans.push_back((gLen*gLen+1)*gLen*gLen/2-prefix);
            return ans;
        }
    };