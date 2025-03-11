// TC: O(N), SC: O(1)
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int sLen=s.size();
            int left=0, right=left+1, ans=0;
            unordered_set<char> d;
            vector<int> rec(3, 0);
            d.insert(s[left]);
            rec[s[left]-'a']++;
            while(left<sLen-2){
                while(right<sLen && d.size()<3){
                    d.insert(s[right]);
                    rec[s[right]-'a']++;
                    right++;
                }
                if(d.size()==3){
                    ans+=sLen-right+1;
                }
                rec[s[left]-'a']--;
                if(rec[s[left]-'a']==0){
                    d.erase(s[left]);
                }
                ++left;
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int len = s.length();
            // Track last position of a, b, c
            vector<int> lastPos = {-1, -1, -1};
            int total = 0;
    
            for (int pos = 0; pos < len; pos++) {
                // Update last position of current character
                lastPos[s[pos] - 'a'] = pos;
    
                // Add count of valid substrings ending at current position
                // If any character is missing, min will be -1
                // Else min gives leftmost required character position
                total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
            }
    
            return total;
        }
    };