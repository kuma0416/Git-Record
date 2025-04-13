// TC: O(LogN); SC: O(1)
class Solution {
    public:
        long long mod = 1e9 + 7;
    
        long long modpow(long long a, long long b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) res = res * a % mod;
                a = a * a % mod;
                b >>= 1;
            }
            return res;
        }
    
        int countGoodNumbers(long long n) {
            long long evenCount = (n + 1) / 2;
            long long oddCount = n / 2;
            return modpow(5, evenCount) * modpow(4, oddCount) % mod;
        }
    };
    