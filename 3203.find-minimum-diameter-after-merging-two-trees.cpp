class Solution {
public:
    int countTreeMaxCumulativeHit(vector<vector<int>>& edges){
        map<int, set<int>> mapping;
        for(vector<int> e: edges){
            if(mapping.count(e[0])){
                mapping[e[0]].insert(e[1]);
            } else {
                mapping[e[0]] = set<int>({e[1]});
            }
            if(mapping.count(e[1])){
                mapping[e[1]].insert(e[0]);
            } else {
                mapping[e[1]] = set<int>({e[0]});
            }
        }

        vector<int> cumucount(mapping.size());
        int wholeMax = 0;
        while(mapping.size() != 0){
            set<int> wantedDel;
            for(auto pair: mapping){
                if(pair.second.size() == 1){
                    for(int targetVal: pair.second){
                        if(wantedDel.contains(targetVal)){
                            continue;
                        }
                        cumucount[targetVal] = max(cumucount[targetVal], cumucount[pair.first]+1);
                        wantedDel.insert(pair.first);
                    }
                }
            }
            // need to add judge odd or even system
            for(int del: wantedDel){
                for(int targetNode: mapping[del]){
                    mapping[targetNode].erase(del);
                    if(mapping[targetNode].size() == 0){
                        mapping.erase(targetNode);
                    }
                }
                mapping.erase(del);
            }
        }
        return *max_element(cumucount.begin(), cumucount.end());
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int e1 = countTreeMaxCumulativeHit(edges1);
        int e2 = countTreeMaxCumulativeHit(edges2);
        int t1=e1*2;
        int t2=e2*2;
        if(edges1.size()%2==1){
            t1=(e1-1)*2;
        }
        if(edges2.size()%2==1){
            t2=(e2-1)*2;
        }
        cout << e1 << e2 << t2 << t2;
        return max(max(e1+e2+1, t1), t2);
    }
};

const int N=100000;
int deg[N]={0};
vector<int> adj[N];
class Solution {
public:
    // modify Kahn's algorithm for undirected graph
    static int diameter(vector<vector<int>>& edges) {
        const int n=edges.size()+1;
        fill(deg, deg+n, 0);
        fill(adj, adj+n, vector<int>());
        for (auto& e : edges) {
            const int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++, deg[w]++;// degree count
        }
        int q[N];
        int front=0, back=0;
        for (int i=0; i < n; i++)
            if (deg[i] == 1)// Push leaves to q
                q[back++]=i;

        int level=0, left=n;
        //inward toward center
        for (; left>2; level++) { //may only 2 leaf nodes
            int qz=back-front;
            left-=qz;
            for (int i=0; i<qz; i++) {
                int v=q[front++];
                for (int w : adj[v]) {
                    // remove edge (v, w) s.t. w being a leaf
                    if (--deg[w]==1) q[back++]=w;
                }
            }
        }
    //    cout<<"left="<< left<<",level="<<level<<endl;
        return (left==2)?2*level+1:2*level;

    }

    static int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                         vector<vector<int>>& edges2) {
        int d1=diameter(edges1), d2=diameter(edges2);
        return max({d1, d2, (d1+1)/2+(d2+1)/2+1});
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();