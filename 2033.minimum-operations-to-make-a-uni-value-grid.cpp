// TC: O(M∗N∗Log(M∗N)), SC: O(M∗N)
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m=grid.size(), n=grid[0].size();
            priority_queue<int, vector<int>, greater<int>> pq;
            vector<long long int> prefix(m*n+1, 0);
            for(int i=0; i<m; ++i){
                for(int j=0; j<n; ++j){
                    pq.push(grid[i][j]);
                }
            }
    
            int idx=1;
            while(!pq.empty()){
                prefix[idx]=prefix[idx-1]+pq.top();
                if((pq.top()-prefix[1])%x!=0){
                    return -1;
                }
                idx++;
                pq.pop();
            }
            int ans=INT_MAX;
            for(int i=1; i<m*n+1; ++i){
                int cur=prefix[i]-prefix[i-1];
                long long int left=abs(prefix[i]-i*cur);
                long long int right=(prefix[m*n]-prefix[i]-(m*n-i)*cur);
                // printf("i: %d, left: %d, right: %d\n", i, left, right);
                if(left%x==0 && right%x==0){
                    ans=min(ans, (int)((left+right)/x));
                } else {
                    return -1;
                }
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        static int minOperations(vector<vector<int>>& grid, int x) {
            const int  m=grid.size(), n=grid[0].size(), N = m*n;
            vector<int> val(N, 0);
    
            // Check modulo consistency and flatten grid
            int r=grid[0][0]%x, i = 0;
            for (const auto& row : grid) {
                for (int num : row) {
                    auto [q, rr] = div(num, x);
                    if (rr != r)
                        return -1; // If not consistent, return -1
                    val[i++]=q;
                }
            }
    
            // Sort values to find median
            sort(val.begin(), val.end());
            int med=(N&1)?val[N/2] : (val[N/2-1] + val[N/2])/2;
    
            // Compute min operations
            int op = 0;
            for (int num : val)
                op+=abs(num-med);
    
            return op;
        }
    };