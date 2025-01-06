class Solution {
public:
    vector<int> minOperations(string boxes) {
        int bLen = boxes.size();
        vector<int> countPre(bLen, 0);
        vector<int> idxPre(bLen, 0);
        vector<int> ans;
        if(boxes[0] == '1'){
            countPre[0] = 1;
        }
        for(int i=1; i<bLen; ++i){
            if(boxes[i] == '1'){
                countPre[i] = countPre[i-1] + 1;
                idxPre[i] = idxPre[i-1] + i;
            } else {
                countPre[i] = countPre[i-1];
                idxPre[i] = idxPre[i-1];
            }
        }
        for(int i=0; i<bLen; ++i){
            int l = i*countPre[i] - idxPre[i];
            int r = i*(countPre[bLen-1] - countPre[i]) - (idxPre[bLen-1] - idxPre[i]);
            ans.push_back(l + abs(r));
        }
        return ans;
    }
};