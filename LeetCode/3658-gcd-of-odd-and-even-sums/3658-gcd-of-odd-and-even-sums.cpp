class Solution {
public:

    int gcd(int a,int b)
    {
        if(a == 0)
        return b;
 
        return gcd(b%a, a);
    }
    int gcdOfOddEvenSums(int n) {
        
        // odd => n*n
        // even => n*n+1

        int a = n*n;
        int b = n*(n+1);

        return gcd(a,b);
    }
};