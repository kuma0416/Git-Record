class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int wLen = words.size();
        set<string> ans_b;
        vector<string> ans;
        if(wLen==1){
            return ans;
        }
        for(int i=0; i<wLen-1; ++i){
            for(int j=i+1; j<wLen; ++j){
                if(words[i].contains(words[j])){
                    ans_b.insert(words[j]);
                } else if (words[j].contains(words[i])){
                    ans_b.insert(words[i]);
                }
            }
        }
        ans.assign(ans_b.begin(), ans_b.end());
        return ans;
    }
};