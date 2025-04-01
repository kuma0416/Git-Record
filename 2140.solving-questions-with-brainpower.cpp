// TC, SC: O(N)
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int qLen=questions.size();
            vector<long long int> st(qLen+1, 0);
            for(int i=0; i<qLen; ++i){
                st[i+1]=max(st[i+1], st[i]);
                long long int t=st[i]+questions[i][0], idx=-1;
                if(i+questions[i][1]+1>=qLen){
                    idx=qLen;
                } else {
                    idx=i+questions[i][1]+1;
                }
                st[idx]=max(st[idx], t);
            }
            return st[qLen];
        }
    };