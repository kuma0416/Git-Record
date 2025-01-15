class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n2c=0, n1L=0;
        deque<int> n1;
        while(num2!=0){
            if((num2 & 1) == 1){
                n2c++;
            }
            num2 = num2 >> 1;
        }
        while(num1!=0){
            if((num1 & 1) == 1){
                n1.push_front(1);
            } else {
                n1.push_front(0);
            }
            n1L++;
            num1 = num1 >> 1;
        }
        int ans=0;
        for(int i=0; i<n1L; ++i){
            if(n2c>0 && n1[i] == 1){
                n2c--;
            } else if(n2c == 0 && n1[i] == 1){
                n1[i] = 0;
            }
        }
        for(int i=n1L-1; i>=0 && n2c>0; --i){
            if(n1[i] == 0){
                n1[i]=1;
                n2c--;
            }
        }
        for(int i=0; i<n1L; ++i){
            ans = ans << 1;
            ans+=n1[i];
        }
        while(n2c!=0){
            ans = ans << 1;
            ans++;
            n2c--;
        }
        return ans;
    }
};