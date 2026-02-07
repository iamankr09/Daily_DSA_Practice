1class Solution {
2public:
3void combinationSumII(vector<int> &nums , int idx , int target , vector<int> &output , vector<vector<int>> &ans){        
4         if(target < 0) return ;
5         if(target == 0){
6             ans.push_back(output);
7             return;
8         }
9
10         if(idx >= nums.size()) return;
11             
12          // pick
13          output.push_back(nums[idx]);
14          combinationSumII(nums , idx+1 , target - nums[idx] , output , ans);
15
16          // Backtrack
17          output.pop_back();
18          while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
19
20          // not pick
21          combinationSumII(nums , idx+1 , target , output , ans);
22
23
24}
25    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
26        vector<vector<int>> ans;
27        vector<int> output;
28        sort(candidates.begin() , candidates.end());
29        combinationSumII(candidates , 0 , target , output , ans);
30        return ans;
31
32    }
33};