class Solution {
public:
    bool check(vector<int>& nums) {
        int nLen = nums.size();
        deque<int> q1(1, nums[0]);
        deque<int> q2;
        int switchChance=1;
        for(int i=1; i<nLen; ++i){
            if(switchChance==1){
                if(nums[i]>=q1.back()){
                    q1.push_back(nums[i]);
                } else {
                    switchChance--;
                    q2.push_back(nums[i]);
                }
            } else if(switchChance==0){
                if(nums[i]>=q2.back()){
                    q2.push_back(nums[i]);
                } else {
                    return false;
                }
            }
        }
        return switchChance==1 || q2.back()<=q1.front();
    }
};