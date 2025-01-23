// TC: O(mn), SC: O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        set<int> ans;
        vector<int> rowstorage(rows, -1);
        vector<int> colstorage(cols, -1);
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j] == 1){
                    if(rowstorage[i] == -1){
                        rowstorage[i]=i*cols+j;
                    } else {
                        ans.insert(rowstorage[i]);
                        ans.insert(i*cols+j);
                    }
                    if(colstorage[j] == -1){
                        colstorage[j]=i*cols+j;
                    } else {
                        ans.insert(colstorage[j]);
                        ans.insert(i*cols+j);
                    }
                }
            }
        }
        return ans.size();
    }
};
// other solution, TC: O(mn), SC: (250)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m=grid.size(), n=grid[0].size();
        int row[250]={0}, col[250]={0}, cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]){
                    cnt++;
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]&& row[i]==1 && col[j]==1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};