// TC: O(N), SC: O(1)
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int l=0, sLen=blocks.size(), ans=INT_MAX;
            int left=0, right=k;
            for(int i=0; i<k && i<sLen; ++i){
                if(blocks[i]=='W'){
                    ++l;
                }
            }
            ans=min(ans, l);
            for(; right<sLen; ++right, ++left){
                if(blocks[right]=='W'){
                    l++;
                }
                if(blocks[left]=='W'){
                    l--;
                }
                ans=min(ans, l);
            }
            return ans;
        }
    };