// TC, SC: O(N^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int nLen=nums.size();
        unordered_map<int, int> crossmap;
        for(int i=0; i<nLen-1; ++i){
            for(int j=i+1; j<nLen; ++j){
                int c=nums[i]*nums[j];
                crossmap[c]++;
            }
        }

        int ans=0;
        for(auto a: crossmap){
            ans+=a.second*(a.second-1)/2;
        }
        return ans*8;
    }
};