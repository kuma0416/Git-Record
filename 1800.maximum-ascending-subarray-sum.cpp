// TC: O(N), SC: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sumup=0, lastval=0, maxsum=0;
        for(int el: nums){
            if(el>lastval){
                sumup+=el;
            } else {
                maxsum=max(sumup, maxsum);
                sumup=el;
            }
            lastval=el;
        }
        return max(maxsum, sumup);
    }
};