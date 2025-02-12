class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pLen=part.size();
        int idx=s.find(part);
        while(idx != string::npos){
            s = s.replace(idx, pLen, "");
            idx=s.find(part);
        }
        return s;
    }
};