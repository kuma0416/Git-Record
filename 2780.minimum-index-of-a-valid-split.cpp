// TC: O(N), SC: O(N)
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> ttc;
            unordered_map<int, int> cc;
            int nLen=nums.size();
            for(int n: nums){
                ttc[n]++;
            }
            for(int i=0; i<nLen; ++i){
                cc[nums[i]]++;
                int l=cc[nums[i]], r=ttc[nums[i]]-cc[nums[i]];
                // printf("num[%d] = %d - l: %d, r: %d, ttc: %d, cc: %d\n", i, nums[i], l, r, ttc[nums[i]], cc[nums[i]]);
                if(l>(i+1)/2 && r>(nLen-i-1)/2){
                    return i;
                }
            }
            return -1;
        }
    };
// other solution
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            const int n=nums.size();
            //Boyer–Moore majority vote algo
            int cnt=0, xM=0;
            for(int x: nums){
                if (cnt==0) xM=x;
                cnt+=(x==xM)?1:-1;
            }
            //Count maxF
            int maxF=count(nums.begin(), nums.end(), xM);
            // find the valid split
            int cntxM=0;
            for(int i=0; i<n; i++){
                cntxM+=nums[i]==xM;
                if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                    return i;
            }
            return -1;
        }
    };