//c
int getSum(int a, int b) {
    if(0 == b)
        return a;
    return getSum(a^b, (a&b)<<1);
}

//c++
class Solution {
public:
    int getSum(int a, int b) {
        if(0 == b)
            return a;
        return getSum(a^b, (a&b)<<1);
    }
};
