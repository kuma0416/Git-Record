// TC: O(N), SC: O(1)
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int res=0;
            int nmax=0, nmin=0;
            for(int n: nums){
                res+=n;
                nmax=max(res, nmax);
                nmin=min(res, nmin);
            }
            return nmax-nmin;
        }
    };