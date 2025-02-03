// TC: O(N), SC: O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int nLen=nums.size();
        int inc=nums[0], dec=nums[0];
        int incl=1, decl=1;
        int longestl=0;
        for(int i=1; i<nLen; ++i){
            if(nums[i]>inc){
                incl++;
            } else {
                longestl=max(longestl, incl);
                incl=1;
            }
            inc=nums[i];
            if(nums[i]<dec){
                decl++;
            } else {
                longestl=max(longestl, decl);
                decl=1;
            }
            dec=nums[i];
        }
        return max(longestl, max(incl, decl));
    }
};