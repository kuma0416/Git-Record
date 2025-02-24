class Solution {
    public:
        unordered_map<int, set<int>> n2n;
        int bn=0;
        deque<int> br; // bob route from 0 to bob
        unordered_set<int> ar; // alice route from 0 to max money
        unordered_map<int, int> nodeval;
        int brsize=0;
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            bn=bob;
            int amax=INT_MIN;
            int eLen=edges.size();
            // build the node map
            for(int i=0; i<eLen; ++i){
                n2n[edges[i][0]].insert(edges[i][1]);
                n2n[edges[i][1]].insert(edges[i][0]);
            }
    
            // find the bob route
            fbr({0}, {0}, 0);
            brsize = br.size();
    
            // find the alice max and find the bob route
            amax = max(amax, findamax({0}, {br[brsize-1]}, 0, amount, 0, amount[0]));
            return amax;
        }
    
        int findamax(unordered_set<int> visited, unordered_set<int> bvisited, int currentNode, vector<int>& amount, int spaceCount, int money){
            int amax=INT_MIN;
            for(int tn: n2n[currentNode]){
                if(visited.contains(tn)){
                    continue;
                }
                visited.insert(tn);
                int bobtarget=-1;
                if(brsize-spaceCount-2 >= 0){
                    bobtarget = br[brsize-spaceCount-2];
                }
                bvisited.insert(bobtarget);
                if(tn == bobtarget){
                    amax = max(amax, findamax(visited, bvisited, tn, amount, spaceCount+1, money+amount[tn]/2));
                } else if(bvisited.contains(tn)){
                    amax = max(amax, findamax(visited, bvisited, tn, amount, spaceCount+1, money));
                } else {
                    amax = max(amax, findamax(visited, bvisited, tn, amount, spaceCount+1, money+amount[tn]));
                }
                bvisited.erase(bobtarget);
                visited.erase(tn);
            }
            if(amax == INT_MIN){
                return money;
            }
            return amax;
        }
    
        void fbr(deque<int> br_local, unordered_set<int> visited, int cn){
            if(cn == bn){
                br = br_local;
                return;
            }
            if(brsize >0){
                return;
            }
            for(int tn: n2n[cn]){
                if(visited.contains(tn)){
                    continue;
                }
                visited.insert(tn);
                br_local.push_back(tn);
                fbr(br_local, visited, tn);
                br_local.pop_back();
                visited.erase(tn);
            }
            return;
        }
    };
// other solution
vector<int> adj[100000];
int parent[100000], Bob[100000];

class Solution {
public:
    static void dfs(int i, int p) {
        parent[i]=p;
        for (int j : adj[i]) {
            if (j==p) continue;
            dfs(j, i);
        }
    }

    static int dfs_sum(int i, int dist, int prev, vector<int>& amount) {
        int alice=0;

        if (dist < Bob[i]) alice=amount[i];  // Alice gets full amount
        else if (dist == Bob[i]) alice= amount[i]/2;  // Split with Bob

        bool isLeaf=1;// set isLeaf flag
        int maxLeafSum=INT_MIN;
        [[unroll]]
        for (int j : adj[i]) {
            if (j==prev) continue;
            isLeaf=0;// has child=> no leaf
            maxLeafSum = max(maxLeafSum, dfs_sum(j, dist+1, i, amount));
        }

        return alice+(isLeaf?0:maxLeafSum);
    }

    static int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n=edges.size()+1;
        [[unroll]]
        for (int i=0; i < n; i++) adj[i].clear();
        [[unroll]]
        for (auto& e : edges) {
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        // Compute Bob's reach time
        fill(Bob, Bob+n, INT_MAX);
        [[unroll]]
        for (int x=bob, move=0; x != -1; x=parent[x]) {
            Bob[x]=move++;
        }

        return dfs_sum(0, 0, -1, amount);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();