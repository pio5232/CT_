class Solution {
public:

int lcm(int a, int b)
{
    return a*b / gcd(a,b);
}
int gcd(int a,int b)
{
    if(a == 0)
    return b;
    
    return gcd(b%a, a);
}
    int mirrorReflection(int p, int q) {

        // 나눠지면
        int lcm_v = lcm(p,q);
        int y = (lcm_v / p);
        int x = (lcm_v / q);

        if(y % 2 == 0) 
            return 0;
        
        return (x % 2 == 0) ? 2 : 1;
    }
};