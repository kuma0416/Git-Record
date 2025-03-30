// TC: O(N), SC: O(26)
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int sLen=s.size();
            unordered_map<char, int> idxmapping;
            for(int i=0; i<sLen; ++i){
                idxmapping[s[i]]=i;
            }
            vector<int> ans;
            for(int i=0; i<sLen; ++i){
                int start=i;
                int maxidx=idxmapping[s[i]];
                while(i<=maxidx && i<sLen){
                    maxidx=max(idxmapping[s[i]], maxidx);
                    ++i;
                }
                // printf("start [%c] idx: %d, end [%c] idx: %d\n", s[start], start, s[i], i);
                ans.push_back(i-start);
                --i;
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        vector<int> partitionLabels(string& s) {
            const int n=s.size();
            array<pair<int, int>, 26> P;// (start, end)
            P.fill({n, -1});
            for(int i=0; i<n; i++){
                int x=s[i]-'a';
                P[x].first=min(i, P[x].first);
                P[x].second=i;
            } 
    
            // Process the intervals
            vector<int> pLen;
            int start = 0, end = -1;
            for (int i = 0; i < n; i++) {
                int x = s[i] - 'a';
                end = max(end, P[x].second);
                if (i == end) {
                    pLen.push_back(end - start + 1);
                    start = i + 1;
                }
            }
            return pLen;
        }
       
    };