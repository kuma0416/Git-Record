// TC: O(N), SC: O(N)
class Solution {
    public:
        string smallestNumber(string pattern) {
            string ans;
            string rev;
            int plen=pattern.size();
            int idx=1;
            for(int i=0; i<plen; ++i){
                rev=to_string(idx)+rev;
                if(pattern[i]=='I'){
                    ans+=rev;
                    rev="";
                }
                ++idx;
            }
            rev=to_string(idx)+rev;
            ans+=rev;
            rev="";
            return ans;
        }
    };