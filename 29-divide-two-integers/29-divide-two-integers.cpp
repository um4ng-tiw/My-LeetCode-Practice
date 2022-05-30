class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long long num = abs(dividend);
        long long deno = abs(divisor);
        long long ans = 0;
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        while(num >= deno){
            long long temp = deno, m = 1;
            
            while(temp << 1 <= num){
                temp <<= 1;
                m <<= 1;
            }
            
            num -= temp;
            ans+=m;
        }
        
        return sign * ans;
        
        
    }
};