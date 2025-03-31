// TC: O(N), SC: O(N)
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int wLen=weights.size();
            vector<int> st;
            for(int i=0; i<wLen-1; ++i){
                st.push_back(weights[i]+weights[i+1]);
            }
            sort(st.begin(), st.end());
            long long int max=0, min=0;
            for(int i=0; i<k-1; ++i){
                min+=st[i];
                max+=st[st.size()-1-i];
            }
            return max-min;
        }
    };
// radix sort
vector<int> bucket[256]; 
void radix_sort(vector<int>& nums) {
    auto [m, M]=minmax_element(nums.begin(), nums.end());
    unsigned xrange=*M-*m+1;
    int round = max(1, int(32-countl_zero(xrange)+7)/8), xmin=*m;
    // 0th round
    for (int& x : nums) {
        x-=xmin; //Adjust x by xmin
        bucket[x & 255].push_back(x);
    }
    int i = 0;
    for (auto& B : bucket) {
        for (auto v : B)
            nums[i++] = v+(round==1?xmin:0);
        B.clear();
    }

    // Rounds from 1st to (round-2)th round
    for (int rd=1; rd < round-1; rd++) {
        int shift=rd*8; // Bit shifting to extract the next set of 8 bits
        for (auto& x : nums)
            bucket[(x >> shift) & 255].push_back(x);

        i=0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] = v;
            B.clear(); // Clear bucket after usage
        }
    }
    // Last round
    if (round > 1) {
        int shift =8* (round-1); // Bit shifting for the last round
        for (auto& x : nums)
            bucket[x >> shift].push_back(x);

        i=0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] =v+xmin; // Adjust x back by adding xmin
            B.clear();             // Clear bucket after usage
        }
    }
}
class Solution {
public:
    static long long putMarbles(vector<int>& weights, int k) {
        const int n=weights.size();
        if (n<=2 || n==k) return 0;
        vector<int> P(n-1, 0);
        for (int i=0; i<n-1; i++)
            P[i]=weights[i]+weights[i+1];
        
        radix_sort(P);

        const long long minP=accumulate(P.begin(), P.begin()+(k-1), 0LL), 
        maxP=accumulate(P.begin()+(n-k), P.end(), 0LL);
        
        return maxP-minP;
    }
};