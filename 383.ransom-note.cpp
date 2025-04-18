// TC: O(2^N), SC: O(N)
class Solution {
    public:
        string countAndSay(int n) {
            if(n==1){
                return "1";
            }
            int last=0, count=0;
            string ans="";
            string source=countAndSay(n-1);
            // cout << n << " - " << source << "\n";
            for(char c: source){
                if(c-'0'!=last){
                    if(last !=0){
                        ans=ans+to_string(count)+to_string(last);
                    }
                    last=c-'0';
                    count=1;
                } else if(c-'0'==last){
                    ++count;
                }
            }
            ans=ans+to_string(count)+to_string(last);
            return ans;
        }
    };
// other solution
class Solution {
    public:
        using info = pair<int, char>; // (frequency, digit)
        static string str(const vector<info>& fc) {
            string ans;
            ans.reserve(fc.size()<<1);
            for (auto& [f, c] : fc) {
                ans+= to_string(f);
                ans.push_back(c);
            }
            return ans;
        }
        static string countAndSay(int n) {
            if (n==1) return "1";
            vector<info> fc={{1, '1'}};
            string s1=str(fc);
            for (int i=3; i<=n; i++) {
                const int sz=s1.size();
                char c=s1[0];
                fc={{1, c}};
                for (int i=1; i<sz; i++) {
                    if (s1[i]==c)
                        fc.back().first++;
                    else {
                        fc.emplace_back(1, s1[i]);
                        c=s1[i];
                    }
                }
                s1=str(fc);
            }
            return s1;
        }
    };