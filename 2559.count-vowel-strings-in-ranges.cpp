class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int qLen = queries.size();
        int wLen = words.size();
        vector<int> ans;
        int* preSum = new int[wLen]{};
        bool* ct = new bool[wLen]{};
        set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        int wordLen = words[0].size();
        if(vowelSet.contains(words[0][0]) && vowelSet.contains(words[0][wordLen-1])){
            ct[0] = true;
            preSum[0]=1;
        }
        for(int i=1; i<wLen; ++i){
            wordLen = words[i].size();
            if(vowelSet.contains(words[i][0]) && vowelSet.contains(words[i][wordLen-1])){
                ct[i] = true;
                preSum[i] = preSum[i-1]+1;
            } else {
                ct[i] = false;
                preSum[i] = preSum[i-1];
            }
        }
        for(int i=0; i<qLen; ++i){
            ans.push_back(preSum[queries[i][1]]-preSum[queries[i][0]]+1);
            if(ct[queries[i][0]] == false){
                ans[i] -= 1;
            }
        }
        return ans;
    }
};
// other solutions
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> Prefix(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 
        for (int i = 0; i < n; i++) {
            Prefix[i + 1] = Prefix[i];
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                Prefix[i + 1]++;  
            }
        }
        vector<int> ANS; 
        for (auto& query : queries) {
            int L = query[0], R = query[1];  
            ANS.push_back(Prefix[R + 1] - Prefix[L]);  
        }

        return ANS;  
    }
};