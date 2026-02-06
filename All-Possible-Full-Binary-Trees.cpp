1
2class Solution {
3public:
4  
5    vector<TreeNode*> allPossibleFBT(int n) {
6        vector<TreeNode*> result;
7        if(n%2 == 0) return result;
8
9        if(n == 1) {
10            TreeNode *root = new TreeNode(0);
11            result.push_back(root);
12            return result;
13        } 
14
15        for(int leftNodes = 1 ; leftNodes <= n-2 ; leftNodes +=2){
16            int rightNodes = n - 1 - leftNodes;
17            vector<TreeNode*> leftSubtree = allPossibleFBT(leftNodes);
18            vector<TreeNode*> rightSubtree = allPossibleFBT(rightNodes);
19
20
21            for(auto left : leftSubtree){
22                for (auto right : rightSubtree){
23                    TreeNode *root = new TreeNode(0);
24                    root->left = left;
25                    root->right = right;
26                    result.push_back(root);
27                }
28            }
29        }
30
31
32        return result;
33
34    }
35};