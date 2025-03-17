// TC: O(N), SC: O(n)
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> mapping;
            int c=0;
            for(int n: nums){
                mapping[n]++;
            }
            for(auto a: mapping){
                if(a.second%2==1){
                    return false;
                } else {
                    c+=a.second/2;
                }
            }
            return c==nums.size()/2;
        }
    };
// other solution
class Solution {
    public:
        static bool divideArray(vector<int>& nums) {
            bitset<501> parity=0;
            for(int x: nums) parity.flip(x);
            return parity.none();
        }
    };