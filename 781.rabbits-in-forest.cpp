// TC, SC: O(N)
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> st;
    
            int ans=0;
            for(int a: answers){
                st[a]++;
                if(st[a] == a+1){
                    ans+=st[a];
                    st.erase(a);
                }
            }
    
            for(auto a: st){
                ans+=a.first+1;
            }
            return ans;
        }
    };