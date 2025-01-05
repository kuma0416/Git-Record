class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int sLen = s.size();
        int shLen = shifts.size();
        vector<int> diff(sLen+1, 0);
        for(int i=0; i<shLen; ++i){
            int t=1;
            if(shifts[i][2] == 0){
                t = -1;
            }
            diff[shifts[i][0]] += t;
            diff[shifts[i][1]+1] -= t;
        }
        int acc = 0;
        for(int i = 0; i < sLen; ++i){
            acc += diff[i];
            int d = ((s[i] - 'a') + acc%26 + 26) % 26;
            s[i] = 'a' + d;
        }
        return s;
    }
};