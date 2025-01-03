class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int nLen = nums.size();
        vector<long long> prefixSum={nums[0]};
        int ans=0;
        for(int i=1; i<nLen; ++i){
            prefixSum.push_back(prefixSum[i-1]+nums[i]);
        }
        for(int i=0; i<nLen-1; ++i){
            if(prefixSum[i] >= prefixSum[nLen-1]-prefixSum[i]){
                ans++;
            }
        }
        return ans;
    }
};
// gpt solution
class Solution { 
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0;
        int ans = 0;

        for (int num : nums) {
            totalSum += num;  // 計算整體的總和
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];  // 累加左半部分
            if (leftSum >= totalSum - leftSum) {
                ans++;
            }
        }

        return ans;
    }
};
