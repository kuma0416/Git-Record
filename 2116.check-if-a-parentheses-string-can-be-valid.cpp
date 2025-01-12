class Solution {
public:
    bool canBeValid(string s, string locked) {
        int sLen=s.size();
        if(sLen%2==1){
            return false;
        }
        int frb=0, buffer=0, bkb=0;
        for(int i=0; i<sLen; ++i){
            if(locked[i] == '0'){
                buffer++;
            } else {
                if(s[i] == '('){
                    frb++;
                } else if(s[i] == ')'){
                    if(frb > 0){
                        frb--;
                    } else if(buffer > 0) {
                        buffer--;
                    } else {
                        return false;
                    }
                }
            }
        }
        int frb1=0, buffer1=0, bkb1=0;
        for(int i=sLen-1; i>=0; --i){
            if(locked[i] == '0'){
                buffer1++;
            } else {
                if(s[i] == ')'){
                    bkb1++;
                } else if(s[i] == '('){
                    if(bkb1 > 0){
                        bkb1--;
                    } else if(buffer1 > 0) {
                        buffer1--;
                    } else {
                        return false;
                    }
                }
            }
        }
        return (frb==0 || frb1==0) && (bkb==0 || bkb1==0);
    }
};