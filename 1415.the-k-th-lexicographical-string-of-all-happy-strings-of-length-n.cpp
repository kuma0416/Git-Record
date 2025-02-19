// TC: O(N), SC: O(1)
class Solution {
    public:
        vector<char> h={'a', 'b', 'c'};
        vector<char> ap={'b', 'c'};
        vector<char> bp={'a', 'c'};
        vector<char> cp={'a', 'b'};
        string getHappyString(int n, int k) {
            if(k>3*pow(2, (n-1))){
                return "";
            }
            string ans="";
            int idx=0;
            char last='0';
            while(n>0){
                idx=(k-1)/pow(2, (n-1));
                switch(last){
                    case 'a':
                        last=ap[idx];
                        break;
                    case 'b':
                        last=bp[idx];
                        break;
                    case 'c':
                        last=cp[idx];
                        break;
                    default:
                        last=h[idx];
                        break;
                }
                ans+=last;
                k-=pow(2, (n-1))*idx;
                --n;
            }
            return ans;
        }
    };