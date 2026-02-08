1class Solution {
2public:
3  
4    void combinationSumIII(int idx , int n , int k , vector<int> &output , vector<vector<int>> &ans){
5        if(n < 0 ) return ; 
6        if(k == 0){
7            if(n == 0) {
8                ans.push_back(output);
9                return;
10            }
11            else return ;
12        }
13
14        if(idx > 9) return ;
15        
16        // pick
17        output.push_back(idx);
18        combinationSumIII(idx+1 , n-idx , k - 1 , output , ans);
19
20        // backtrack
21        output.pop_back();
22        combinationSumIII(idx+1 , n , k , output , ans);
23
24    }  
25    vector<vector<int>> combinationSum3(int k, int n) {
26         vector<vector<int>>  ans;
27         vector<int> output;
28         combinationSumIII(1 , n , k , output , ans);
29         return ans;
30    }
31};