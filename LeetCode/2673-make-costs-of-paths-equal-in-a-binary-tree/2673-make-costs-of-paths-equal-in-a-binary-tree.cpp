class Solution {
public:
    int sum = 0; 
    
    int go(const int n,int node, const vector<int>& cost)
    {
        // node => 1 indexed
        // cost => 0 indexed
        // convert [node to cost]

        // perfect binary tree => return (left or right) > n 
        if(n < node)
        {
            return 0;
        } 

        const int left = 2*node;
        const int right = 2*node + 1;

        int ret = 0;
        int l = go(n,left,cost);
        int r = go(n,right,cost);

        sum += abs(l - r);


        return max(l,r) + cost[node-1];
    }

    int minIncrements(int n, vector<int>& cost) {


        go(n, 1, cost);

        return sum;
    }
};