// TC, SC: O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        unordered_map<int, int> sumtonum;
        for(int n: nums){
            int ntmp=n;
            int nsum=0;
            while(n!=0){
                nsum+=n%10;
                n/=10;
            }
            if(sumtonum.contains(nsum)){
                ans=max(ans, sumtonum[nsum]+ntmp);
            }
            sumtonum[nsum]=max(sumtonum[nsum], ntmp);
        }
        return ans;
    }
};