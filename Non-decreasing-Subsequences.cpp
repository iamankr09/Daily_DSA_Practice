1class Solution {
2public:
3    void find(vector<int>& nums , int idx , vector<int> &output , vector<vector<int>> &ans){
4
5        if(output.size() >= 2){
6            ans.push_back(output);
7        }
8
9       if(idx >= nums.size()){
10           return;
11       }
12
13       
14
15         unordered_set<int> st;
16        for(int i = idx ; i < nums.size() ; i++){
17            if(st.find(nums[i]) != st.end()) continue;
18            // increasing condition
19            if (!output.empty() && nums[i] < output.back()) continue;
20
21            st.insert(nums[i]);
22            output.push_back(nums[i]);
23            find(nums , i+1 , output , ans);
24            output.pop_back();
25        }
26
27
28        
29    }
30    vector<vector<int>> findSubsequences(vector<int>& nums) {
31        vector<vector<int>> ans;
32        vector<int> output;
33        find(nums , 0 , output , ans);
34        return ans;
35    }
36};