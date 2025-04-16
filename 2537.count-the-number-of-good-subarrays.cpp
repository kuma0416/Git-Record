// TC, SC: O(N)
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int nLen=nums.size();
            unordered_map<int, int> c;
            int l=0, r=0;
            long long int s=0, ans=0;
            for(; l<nLen; ++l){
                for(; r<nLen; ++r){
                    if(s>=k){
                        ans+=nLen-r;
                        break;
                    }
                    c[nums[r]]++;
                    s+=c[nums[r]]-1;
                }
                if(s>=k){
                    ++ans;
                }
                c[nums[l]]--;
                s-=c[nums[l]];
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            const int n=nums.size();
            unordered_map<int, int> freq;
            freq.reserve(n);
            long long ans=0, cnt=0;
    
            for (int r=0, l=0; r<n; r++) {
                // increases the pair count by freq[nums[r]]
                const int x=nums[r];
                cnt+=freq[x]++;
    
                // Try to move the left pointer to maintain at least k pairs
                while (cnt>=k) {
                    // valid subarrays among [l, r0] where r0=r...n-1
                    ans+=(n-r);
                    cnt-=--freq[nums[l]];
                    l++;
                }
            }
            return ans;
        }
    };