// TC: O(1), SC: O(N)
class ProductOfNumbers {
    public:
        int count=0;
        deque<long long int> cross;
        int zeroidx = 0;
        ProductOfNumbers() {
            cross = {1};
        }
        
        void add(int num) {
            count++;
            long long int tmp=cross.back();
            if(num==0){
                cross.push_back(1);
                zeroidx=count;
            } else {
                cross.push_back(num*tmp);
            }
        }
        
        int getProduct(int k) {
            if(count-k+1 <= zeroidx){
                return 0;
            } else {
                return cross[count]/cross[count-k];
            }
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */