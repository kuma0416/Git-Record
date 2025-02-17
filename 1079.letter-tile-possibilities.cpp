// TC: O(2^N*N), SC: O(N)
class Solution {
    public:
        bitset<26> headv=0;
        unordered_set<string> ans;
        int numTilePossibilities(string tiles) {
            bt("", tiles);
            return ans.size();
        }
        void bt(string base, string source){
            if(source.size()==0){
                ans.insert(base);
                return;
            }
            for(int i=0; i<source.size(); ++i){
                if(base.size()==0){
                    if(headv[source[i]-'A']==1){
                        continue;
                    } else {
                        headv[source[i]-'A']=1;
                    }
                }
                char ctmp=source[i];
                string s(1, ctmp);
                ans.insert(base+ctmp);
                bt(base+ctmp, source.erase(i, 1));
                source.insert(source.begin() + i, ctmp);
            }
            return;
        }
    };
// other solution, TC: O(2^N), SC: O(1)
class Solution {
    public:
        // choose n chars with freq info to permute
        int Perm(int n, vector<int>& freq, int fz){
            if (n==1) // base case
               return fz-count(freq.begin(), freq.end(), 0);
            int ans=0;
            for (int i=0; i<fz; i++) {
                if (freq[i]>0) {
                    freq[i]--; 
                    ans+= Perm(n-1, freq, fz);// recursion
                    freq[i]++; // backtracking
                }
            }
            return ans;
        }
        int numTilePossibilities(string& tiles) {
            int sz=0, tz=tiles.size();
            vector<int> freq(26, 0);
            for (char c: tiles)
                if (++freq[c-'A']==1) sz++;
            sort(freq.begin(), freq.end(), greater<int>());
            freq.resize(sz);
        
            int cnt=0;
            for (int len=1; len<=tz; len++) 
                cnt+= Perm(len, freq, sz);
    
            return cnt;
        }
    };