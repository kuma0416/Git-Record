// TC: O(N+K), SC: O(1)
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int cLen=colors.size();
            int left=0, right=left+1;
            int ans=0;
            while(left<cLen){
                right=left+1;
                for(; right<left+k; ++right){
                    // printf("[1] - left idx: %d, right idx: %d\n", left, right);
                    if(colors[right%cLen]==colors[(right-1)%cLen]){
                        break;
                    }
                }
                if(right==left+k){
                    // printf("[2] - left idx: %d, right idx: %d\n", left, right);
                    ++ans;
                }
                while(right==left+k && left+1<cLen && ((k%2==1 && colors[left]!=colors[right%cLen]) || (k%2==0 && colors[left]==colors[right%cLen]))){
                    // printf("[3] - left idx: %d, right idx: %d\n", left, right);
                    ++ans;
                    left++;
                    right++;
                }
                if(right>=cLen){
                    right=cLen;
                }
                // printf("[4] - left idx: %d, right idx: %d\n", left, right);
                left=right;
            }
            return ans;
        }
    };
// other solution
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
            int count = 0;
            int left = 0;
            
            for (int right = 0; right < colors.size(); ++right) {
                if (right > 0 && colors[right] == colors[right - 1]) {
                    left = right;  
                }
                
                if (right - left + 1 >= k) {
                    count++;  
                }
            }
            
            return count;
        }
    };