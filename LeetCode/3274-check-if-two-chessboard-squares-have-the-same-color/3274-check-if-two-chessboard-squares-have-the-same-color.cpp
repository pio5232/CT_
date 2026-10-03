class Solution {
public:

    bool chk(int a, int b)
    {
        return (a%2) == (b%2);
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        
        int c1 = coordinate1[0] - 'a';
        int c11 = coordinate1[1] - '0';

        int c2 = coordinate2[0] - 'a';
        int c22 = coordinate2[1] - '0';

        return chk(c1,c11) == chk(c2,c22);
    }
};