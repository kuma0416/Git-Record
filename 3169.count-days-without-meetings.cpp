// MLE
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            vector<int> d(days+1, 0);
            for(vector<int> m: meetings){
                int l=m[0]-1, r=m[1]-1;
                d[l]++;
                d[r+1]--;
            }
            long long int ans=0, t=0;
            for(int i=0; i<days; ++i){
                t+=d[i];
                if(t==0){
                    ans++;
                }
            }
            return ans;
        }
    };
// TC: O(NlogN), SC: O(N)
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            for(vector<int> m: meetings){
                pq.push(m);
            }
            int ans=0;
            int i=1;
            while(i<=days && !pq.empty()){
                printf("i: %d, l: %d, r:%d\n", i, pq.top()[0], pq.top()[1]);
                if(i<pq.top()[0]){
                    ans+=pq.top()[0]-i;
                    i=pq.top()[1]+1;
                } else {
                    if(i<=pq.top()[1]){
                        i=pq.top()[1]+1;
                    }
                }
                if(!pq.empty()){
                    pq.pop();
                }
            }
            return ans+days-i+1;
        }
    };
// best solution
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
    int countDays(int days, vector<vector<int>>& meetings) {
        const int n = meetings.size(), N=2*n;
        vector<int> info(N);
        int i=0;
        // Encode meeting start and end 
        for (auto& m : meetings) {
            const int s= m[0], e=m[1];
            info[i++]=(s<<1)|1;  // Start, mark with LSB=1
            info[i++]=(e+1)<<1;  // End (exclusive)
        }

        // Sort the events
        radix_sort(info);

        int overlap=0, cnt=0, last=1;
        
        // Process events in sorted order
        for (int i=0; i<N; i++) {
            const int x=info[i]>>1;    // Extract day
            const bool isStart=info[i]&1;

            // If no overlap, count the days between last and current 
            if (overlap==0 && last<x) 
                cnt+=(x-last);

            overlap+=isStart?1:-1;  // Increment on start, decrement on end
            if(overlap==0) last=x;   // Update last when no overlap
        }

        // free between last & days
        if (last<=days) 
            cnt+=(days-last+1);

        return cnt;
    }
};