#include <vector>
class Solution {
public:
    int res = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int ns = nums.size();
        iter(0, nums, target+nums[0], ns);
        iter(0, nums, target-nums[0], ns);
        return res;
    }
    void iter(int idx, vector<int>& nums, int target, int ns){
        if(idx == ns-1){
            if(target == 0){
                ++res;
            }
            return;
        }
        iter(idx+1, nums, target+nums[idx+1], ns);
        iter(idx+1, nums, target-nums[idx+1], ns);
        return;
    }
};
// other person solution
int dp[21][1001];
class Solution {
public:
    int f(int j, int sum, vector<int>& nums){
        if (j==0) return sum==0?1:0;
        if (dp[j][sum]!=-1) return dp[j][sum];
        int x=nums[j-1];
        int ans=f(j-1, sum, nums);// without change sign 
        if (sum>=x) // sign change
            ans+=f(j-1, sum-x, nums);
        return dp[j][sum]=ans;   
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int diff=sum-target;

        // Check if it's possible to achieve the target
        if (diff<0|| diff%2!=0) return 0;

        diff/=2;
        memset(dp, -1, sizeof(dp));
        return f(n, diff, nums);
    }
};