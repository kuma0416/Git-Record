class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int wLen = words.size();
        int total=0;
        for(int i=0; i<wLen-1; ++i){
            for(int j=i+1; j<wLen; ++j){
                if(isPrefixAndSuffix(words[i], words[j])){
                    total++;
                }
            }
        }
        return total;
    }
    bool isPrefixAndSuffix(string s1, string s2){
        if(s1.size()>s2.size()){
            return false;
        }
        int s1Len = s1.size();
        int s2Len = s2.size();
        return s2.substr(0, s1Len) == s1 && s2.substr(s2Len-s1Len, s1Len) == s1;
    }
};