// TC: O(N), SC: O(N)
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_set<int> visited;
            int nLen=nums.size();
            int nl=nums[0].size();
            int maxv=pow(2, nl+1);
            int ans=0;
            for(int i=0; i<nLen; ++i){
                visited.insert(stoi(nums[i], nullptr, 2));
            }
            for(int i=0; i<maxv; ++i){
                if(!visited.contains(i)){
                    ans=i;
                    break;
                }
            }
            string s=bitset<16>(ans).to_string();
            return s.substr(16-nl, nl);
        }
    };
// other solution
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string result;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i][i] == '0') {
                    result += '1';
                } else {
                    result += '0';
                }
            }
            return result;
        }
    };