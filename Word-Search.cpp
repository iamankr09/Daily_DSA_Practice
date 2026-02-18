1class Solution {
2public:
3    vector<vector<int>> directions{{1,0} , {-1,0} , {0 , 1} , {0 ,-1}};
4    bool find(vector<vector<char>>& board , int row , int col , string &word , int idx , int m , int n){
5        if(idx >= word.length()) return true;
6        if(row < 0 || col < 0 || row >= m || col >= n || board[row][col] == '$') return false;
7
8        if(board[row][col] != word[idx]) return false;
9
10        char temp = board[row][col];
11        board[row][col] = '$'; // mark visited
12
13       // explore
14       for(auto &dir : directions){
15            int new_row = row + dir[0];
16            int new_col = col + dir[1];
17
18            bool ans = find(board , new_row , new_col , word , idx+1 , m , n);
19            if(ans) return true;
20       }
21
22
23       // undo
24       board[row][col] = temp;
25
26       return false;
27
28
29    }
30    bool exist(vector<vector<char>>& board, string word) {
31        int m  = board.size();
32        int n  = board[0].size();
33
34
35        for(int i = 0 ; i < m ; i++){
36            for(int j = 0 ; j < n ; j++){
37                if(board[i][j] == word[0]){
38                    bool ans = find(board , i , j , word , 0 , m , n);
39                    if(ans) return true;
40                }
41            }
42        }
43
44        return false;
45    }
46};