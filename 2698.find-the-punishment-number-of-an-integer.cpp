// TC: O(NlogN), SC: O(logN)
class Solution {
    public:
        int punishmentNumber(int n) {
            int ans=0;
            for(int i=1; i<=n; ++i){
                if(chkPunishment(i, i*i, to_string(i).length(), 0)){
                    // cout << "i: " << i << " is passed.\n";
                    ans+=i*i;
                }
            }
            return ans;
        }
        bool chkPunishment(int origin, int sqnum, int nlen, int sumnum){
            if(sumnum==origin && sqnum==0){
                return true;
            } else if(sumnum>origin || sqnum==0){
                return false;
            }
            bool res=false;
            for(int i=1; i<=nlen; ++i){
                int di=pow(10, i);
                // printf("[%d] - origin: %d, sqnum: %d, nlen: %d, sum num: %d, di: %d\n", i, origin, sqnum, nlen, sumnum, di);
                res = res || chkPunishment(origin, sqnum/di, nlen, sumnum+sqnum%di);
            }
            return res;
        }
    };
// other solution
class Solution {
    public:
        static inline bool partition(int x, int target) {
            if (x==target) return 1;
            if (x==0) return target==0; 
            const int m0=min(x, 1000); 
            [[unroll]] 
            for (int m=10; m<=m0; m*=10) {
                if (partition(x/m, target-x%m)) return 1;
            }
            return 0;
        }
    
        static int punishmentNumber(int n) {
            int sum=0;
            for (int i=1; i<=n; i++) {
                const int x=i*i;
                sum+=(partition(x, i))?x:0;
            }
            return sum;
        }
    };