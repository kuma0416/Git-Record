class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCount(26);
        int w2Total=0;
        vector<string> ans;
        for(string s: words2){
            vector<int> ccount(26);
            for(char c: s){
                ccount[c-'a']++;
                maxCount[c-'a'] = max(maxCount[c-'a'], ccount[c-'a']);
            }
        }
        for(string s: words1){
            int idx=0; int subTotal=w2Total; int sLen=s.size();
            vector<int> subCount(26);
            for(char c: s){
                subCount[c-'a']++;
            }

            bool check=true;
            for(int i=0; i<26; ++i){
                if(maxCount[i] > subCount[i]){
                    check=false;
                    break;
                }
            }
            if(check){
                ans.push_back(s);
            }
        }
        return ans;
    }
};