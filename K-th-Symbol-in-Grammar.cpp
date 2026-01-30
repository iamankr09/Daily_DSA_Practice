1class Solution {
2public:
3    int kthGrammar(int n, int k) {
4        // Base Case
5        if(n == 1) return 0;
6
7        int totalCols = pow(2 , n-1);
8        if(k <= totalCols/2){
9            return kthGrammar(n-1 , k);
10        }
11        else{
12            int ans = kthGrammar(n-1 , k - totalCols/2);
13            return !ans;
14        }
15    }
16};