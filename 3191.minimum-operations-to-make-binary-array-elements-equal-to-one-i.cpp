// TC: O(N), SC: O(1)
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int nLen=nums.size();
            int ans=0;
            for(int i=0; i<nLen-2; ++i){
                if(nums[i]==0){
                    ++ans;
                    nums[i]++;
                    nums[i+1]=(nums[i+1]+1)%2;
                    nums[i+2]=(nums[i+2]+1)%2;
                }
            }
            if(nums[nLen-1]==1 && nums[nLen-2]==1){
                return ans;
            } else {
                return -1;
            }
        }
    };