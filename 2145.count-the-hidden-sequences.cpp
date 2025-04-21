// TC: O(N), SC: O(1)
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int dLen=differences.size();
            long long int minn=0, maxn=0, cur=0;
    
            for(int i=0; i<dLen; ++i){
                cur+=differences[i];
                minn=min(minn, cur);
                maxn=max(maxn, cur);
            }
    
            return upper-maxn+minn-lower+1>0? upper-maxn+minn-lower+1: 0;
        }
    };