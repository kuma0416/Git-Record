// TC: O(N), SC: O(1)
class Solution {
    public:
        int MOD = 1000000007;
        int numOfSubarrays(vector<int>& arr) {
            int aLen=arr.size();
            pair<int, int> p = {0, 0}; // first -> odd, second -> even
            int s=0;
            for(int i=0; i<aLen; ++i){
                s+=arr[i]%2;
                if(s%2==0){
                    p.second = p.second%MOD+1;
                } else {
                    p.first = p.first%MOD+1;
                }
            }
            int ans=p.first;
            for(int i=0; i<aLen; ++i){
                if(arr[i]%2==0){
                    p.second--;
                } else {
                    int tmp=p.second;
                    p.second=p.first-1;
                    p.first=tmp;
                }
                ans = ans%MOD + p.first;
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1000000007;
            int odd = 0, even = 1; 
            int result = 0;
            int sum = 0;
    
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
                if (sum % 2 == 1) {
                    result = (result + even) % MOD;
                    odd++;
                } else {
                    result = (result + odd) % MOD;
                    even++;
                }
            }
    
            return result;
        }
    };