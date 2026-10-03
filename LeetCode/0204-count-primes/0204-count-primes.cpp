class Solution {
public:

    int countPrimes(int n) {
        
        if(n<=2)
        return 0;

        vector<char> chae(n+1,1);
        
        // chae[0] = chae[1] = false;
        for(int i = 3; i*i<n; i+=2)
        {
            if(chae[i] == 0)continue;

            for(int j = i*i; j<n; j+=i*2)
            {
                chae[j] = 0;
            }
        }

        int cnt = 1; // about 2

        for(int i =3; i<n;i+=2)
        {
            if(chae[i])
            cnt++;
        }
        return cnt;
    }
};