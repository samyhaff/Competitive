class Solution {
public:
    int getSum(int a, int b) {
        int tmp;
        while (b) {
            tmp = a;
            a = a ^ b;
            b = (unsigned) (tmp & b) << 1;
        }
        return a;
    }
};
