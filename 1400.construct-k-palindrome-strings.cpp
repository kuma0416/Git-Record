class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> scCount(26, 0);
        for(char c: s){
            scCount[c-'a']++;
        }
        int countSingle=0;
        int totalCount=0;
        for(int i: scCount){
            if(i%2!=0){
                countSingle++;
            }
            if(i!=0){
                totalCount+=i;
            }
        }
        return countSingle<=k && totalCount>=k;
    }
};