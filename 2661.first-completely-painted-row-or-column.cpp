class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows=mat.size(), cols=mat[0].size(), arrLen=arr.size();
        map<int, int> valmap;
        map<int, set<int>> rowmap;
        map<int, set<int>> colmap;
        int ans=0;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                valmap.insert({mat[i][j], i*cols+j});
            }
        }
        for(ans=0; ans<arrLen; ++ans){
            int idx=valmap[arr[ans]];
            int curx=idx/cols, cury=idx%cols;
            if(!rowmap.contains(curx)){
                set<int> s(mat[curx].begin(), mat[curx].end());
                rowmap[curx]=s;
                
            }
            rowmap[curx].erase(arr[ans]);
            if(rowmap[curx].size()==0){
                break;
            }
            if(!colmap.contains(cury)){
                set<int> s;
                for(int i=0; i<rows; ++i){
                    s.insert(mat[i][cury]);
                }
                colmap[cury]=s;
            }
            colmap[cury].erase(arr[ans]);
            if(colmap[cury].size()==0){
                break;
            }
        }
        return ans;
    }
};
// other solutions
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        vector<int> rowCount(rows, cols), colCount(cols, rows);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx) {
            int val = arr[idx];
            auto [row, col] = positionMap[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return idx;
            }
        }

        return -1;
    }
};