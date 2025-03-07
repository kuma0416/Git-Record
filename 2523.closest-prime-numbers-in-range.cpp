// TC: O(sqrt(N)), SC: O(1)
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int diff=INT_MAX;
            int prev=0;
            vector<int> ans(2, -1);
            for(; left<=right; ++left){
                if(isPrime(left)){
                    if(left-prev<diff && prev!=0 && prev!=1){
                        diff=left-prev;
                        ans[0]=prev;
                        ans[1]=left;
                    }
                    prev=left;
                }
            }
            if(diff==prev){
                return {-1, -1};
            } else {
                return ans;
            }
        }
        bool isPrime(int n){
            int tmp=sqrt(n);
            for(int i=2; i<=tmp; ++i){
                if(n%i==0){
                    return false;
                }
            }
            return true;
        }
    };
// other solutions
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<bool> sieve(right + 1, true);
            sieve[0] = sieve[1] = false;
            
            for (int i = 2; i * i <= right; ++i) {
                if (sieve[i]) {
                    for (int j = i * i; j <= right; j += i) {
                        sieve[j] = false;
                    }
                }
            }
            
            vector<int> primes;
            for (int i = left; i <= right; ++i) {
                if (sieve[i]) {
                    primes.push_back(i);
                }
            }
            
            if (primes.size() < 2) {
                return {-1, -1};
            }
            
            int min_gap = INT_MAX;
            vector<int> result = {-1, -1};
            
            for (int i = 1; i < primes.size(); ++i) {
                int gap = primes[i] - primes[i - 1];
                if (gap < min_gap) {
                    min_gap = gap;
                    result = {primes[i - 1], primes[i]};
                }
            }
            
            return result;
        }
    };