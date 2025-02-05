// TC: O(N), SC: O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int sLen=s1.size();
        vector<int> rec(26, 0);
        int count=0;
        for(int i=0; i<sLen; ++i){
            if(s1[i]!=s2[i]){
                rec[s1[i]-'a']++;
                rec[s2[i]-'a']--;
                ++count;
            }
        }
        for(int i=0; i<26; ++i){
            if(rec[i]!=0){
                return false;
            }
        }
        return count<=2;
    }
};