class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int dLen = derived.size();
        vector<int> z(dLen, 0);
        vector<int> o(dLen, 1);
        for(int i=1; i<dLen; ++i){
            z[i] = z[i-1]^derived[i-1];
            o[i] = o[i-1]^derived[i-1];
        }
        return z[0]^z[dLen-1]==derived[dLen-1] || o[0]^o[dLen-1]==derived[dLen-1];
    }
};
// other solutions
class Solution {
public:
    static bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<>())==0;
    }
};