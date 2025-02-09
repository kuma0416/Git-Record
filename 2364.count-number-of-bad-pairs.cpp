// TC, SC: O(N)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long nLen=nums.size();
        unordered_map<long long, long long> diffcount;
        for(long long i=0; i<nLen; ++i){
            diffcount[nums[i]-i]++;
        }
        long long ans=nLen*(nLen-1)/2;
        for(auto a: diffcount){
            ans-=a.second*(a.second-1)/2;
        }
        return ans;
    }
};
// other solution
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        long long goodPairs = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }
        
        return (n * (n - 1)) / 2 - goodPairs;
    }
};