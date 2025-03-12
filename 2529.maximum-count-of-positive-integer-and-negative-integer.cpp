// TC: O(N), SC: O(1)
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int nLen=nums.size();
            if(nums[0]>0 || nums[nLen-1]<0){
                return nLen;
            }
            if(nums[0]==0 && nums[nLen-1]==0){
                return 0;
            }
            int sl=0, bl=0, sr=nLen-1, br=nLen-1, si=0, bi=0;
            while(sl<sr){
                si=(sl+sr)/2+1;
                if(nums[si]>=0){
                    sr=si-1;
                } else {
                    sl=si;
                }
                // printf("[small] - left: %d, right: %d\n", sl, sr);
            }
            while(bl<br){
                bi=(bl+br)/2;
                if(nums[bi]<=0){
                    bl=bi+1;
                } else {
                    br=bi;
                }
                // printf("[big] left: %d, right: %d\n", bl, br);
            }
            return max(sl+1, nLen-br);
        }
    };