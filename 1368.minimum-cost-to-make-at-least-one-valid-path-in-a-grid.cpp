typedef pair<int,int>P;

class Solution {
private:
    vector<int>directionsX = {0,0,0,1,-1};
    vector<int>directionsY = {0,1,-1,0,0};

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();

        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));

        deque<P>dq;
        dq.push_front({0,0});

        cost[0][0] = 0;

        while(!dq.empty()){
            int curri = dq.front().first;
            int currj = dq.front().second;
            int currCost = cost[curri][currj];

            dq.pop_front();

            if(curri==m-1 && currj==n-1 ) return currCost;

            for(int i=1;i<=4;i++){
                int newi = curri+directionsX[i];
                int newj = currj+directionsY[i];

                if(newi<0 || newj<0 || newi>=m || newj>=n) continue;

                bool sameDirection = grid[curri][currj]==i;

                int newCost = sameDirection?currCost:1+currCost;

                if(cost[newi][newj]>newCost) {
                    cost[newi][newj] = newCost;
                    if(sameDirection) dq.push_front({newi,newj});
                    else dq.push_back({newi,newj});
                }
            }
        }

        return cost[m-1][n-1];
    }
};