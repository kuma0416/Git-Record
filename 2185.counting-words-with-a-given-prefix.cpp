class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pLen = pref.size();
        int ans=0;
        for(string s: words){
            if(s.substr(0, pLen) == pref){
                ans++;
            }
        }
        return ans;
    }
};