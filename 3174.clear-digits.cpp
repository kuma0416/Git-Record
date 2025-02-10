// TC, SC: O(N)
class Solution {
public:
    string clearDigits(string s) {
        unordered_set<char> numset={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        deque<char> last;
        for(char c: s){
            if(numset.contains(c)){
                last.pop_back();
            } else {
                last.push_back(c);
            }
        }
        string ans(last.begin(), last.end());
        return ans;
    }
};
// other solution
class Solution {
public:
    string clearDigits(string s) {
        string stack;
        for (char c : s) {
            if (isdigit(c)) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }
};