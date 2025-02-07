// TC, SC: O(N)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int qLen=queries.size();
        int distinctcount=0;
        vector<int> ans(qLen, 0);
        unordered_map<int, int> nodecolor;
        unordered_map<int, int> storedcolor;
        for(int i=0; i<qLen; ++i){
            int node=queries[i][0];
            int color=queries[i][1];
            int origincolor=nodecolor[node];
            storedcolor[origincolor]--;
            if(storedcolor[origincolor]==0){
                distinctcount--;
            }
            if(storedcolor[color]==0){
                distinctcount++;
            }
            storedcolor[color]++;
            nodecolor[node]=color;
            ans[i]=distinctcount;
        }
        return ans;
    }
};