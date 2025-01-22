// TC: O(N∗M∗Log(N∗M)), SC: O(N∗M)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows=isWater.size(), cols=isWater[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(isWater[i][j] == 1){
                    pq.push({0, i*cols+j});
                    visited[i][j]=true;
                }
            }
        }
        vector<int> dx={-1, 1, 0, 0};
        vector<int> dy={0, 0, -1, 1};
        while(!pq.empty()){
            int val=pq.top().first;
            int place=pq.top().second;
            int curx=place/cols;
            int cury=place%cols;
            for(int i=0; i<4; ++i){
                int afterx=curx+dx[i];
                int aftery=cury+dy[i];
                if(afterx>=0 && afterx<rows && aftery>=0 && aftery<cols && isWater[afterx][aftery]==0 && ans[afterx][aftery]<val+1 && visited[afterx][aftery]==false){
                    ans[afterx][aftery]=val+1;
                    pq.push({val+1, (afterx)*cols+aftery});
                    visited[afterx][aftery]=true;
                }
            }
            pq.pop();
        }
        return ans;
    }
};
// other solution, TC & SC: O(N∗M)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, -1)); // 初始化為 -1
        deque<pair<int, int>> q;

        // 初始化水域格子
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isWater[i][j] == 1) {
                    q.push_back({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        // 定義方向向量
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // BFS 填充高度
        while (!q.empty()) {
            auto [curX, curY] = q.front();
            q.pop_front();

            for (int k = 0; k < 4; ++k) {
                int newX = curX + dx[k];
                int newY = curY + dy[k];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && ans[newX][newY] == -1) {
                    ans[newX][newY] = ans[curX][curY] + 1;
                    q.push_back({newX, newY});
                }
            }
        }

        return ans;
    }
};
