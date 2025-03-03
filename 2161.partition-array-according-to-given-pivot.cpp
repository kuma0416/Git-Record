// TC: O(N), SC: O(N)
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> s, m, l;
            for(int n: nums){
                if(n<pivot){
                    s.push_back(n);
                } else if(n==pivot){
                    m.push_back(n);
                } else {
                    l.push_back(n);
                }
            }
            s.insert(s.end(), m.begin(), m.end());
            s.insert(s.end(), l.begin(), l.end());
            return s;
        }
    };