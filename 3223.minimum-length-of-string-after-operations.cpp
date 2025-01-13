class Solution {
public:
    int minimumLength(string s) {
        vector<int> cr(26, 0);
        int res=0;
        for(char c: s){
            cr[c-'a']++;
        }
        for(int i: cr){
            if(i>0 && i%2==0){
                res+=2;
            } else if(i>0 && i%2==1){
                res++;
            }
        }
        return res;
    }
};