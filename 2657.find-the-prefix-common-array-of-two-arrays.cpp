class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> as;
        set<int> bs;
        int n = A.size();
        vector<int> ans(n+1, 0);
        for(int i = 1; i < n+1; ++i){
            ans[i] = ans[i-1];
            if(A[i-1] == B[i-1]){
                ans[i]++;
            } else {
                if(as.contains(B[i-1])){
                    ans[i]++;
                }
                if(bs.contains(A[i-1])){
                    ans[i]++;
                }
            }
            as.insert(A[i-1]);
            bs.insert(B[i-1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};
// improve
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            if (++freq[A[i]] == 2) common++;
            if (++freq[B[i]] == 2) common++;
            ans.push_back(common);
        }
        return ans;
    }
};