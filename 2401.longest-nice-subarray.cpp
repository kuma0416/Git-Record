// TC: O(N), SC: O(1)
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int left=0, right=0, ans=1;
            int nLen=nums.size();
            long long bitmask=0;
            while(left<nLen){
                while(right<nLen){
                    long long leftval=bitmask|nums[right], rightval=bitmask+nums[right];
                    if(leftval!=rightval){
                        bitmask-=nums[left];
                        break;
                    } else {
                        bitmask+=nums[right];
                        ++right;
                    }
                }
                ans=max(ans, right-left);
                ++left;
            }
            return max(ans, nLen-left);
        }
    };
// other solution
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, usedBits = 0, maxLength = 0;

        for (int r = 0; r < nums.size(); r++) {
            while ((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l];
                l++;
            }

            usedBits |= nums[r];
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};