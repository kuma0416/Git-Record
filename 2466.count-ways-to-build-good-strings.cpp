class Solution {
public:
    int MOD = 1000000007;
    map<long long, long long> visited;
    int countGoodStrings(int low, int high, int zero, int one) {
        int tot=0;
        int smallLen = min(zero, one);
        for(int i=0; i<smallLen; ++i){
            visited.insert({i, 0});
        }
        if(zero==one){
            visited.insert({smallLen, 2});
        } else {
            visited.insert({smallLen, 1});
        }
        for(int i=smallLen+1; i<=high; ++i){
            int zs=0;
            int os=0;
            if(i>zero){
                zs=visited[(i-zero)];
            } else if(i==zero){
                ++zs;
            }
            if(i>one){
                os=visited[(i-one)];
            } else if(i==one){
                ++os;
            }
            visited.insert({i, (os+zs)%MOD});
        }
        for(int i=low; i<=high; ++i){
            tot=(tot+visited[i])%MOD;
        }
        return tot;
    }
};
// other person solution
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod=1e9+7;
        int dp[100001]={0};
        dp[0]=1;
        for(int i=1; i<=high; i++){
            long long ans=1;
            if (i>=zero) ans+=dp[i-zero];
            if (i>=one) ans+=dp[i-one];
            dp[i]=ans%mod;
        }
        return (dp[high]-dp[low-1]+mod)%mod;
    }
};