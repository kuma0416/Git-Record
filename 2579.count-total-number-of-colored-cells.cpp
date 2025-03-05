class Solution {
    public:
        long long coloredCells(int n) {
            long long h=n;
            return 4*(h*(h-1)/2)+1;
        }
    };