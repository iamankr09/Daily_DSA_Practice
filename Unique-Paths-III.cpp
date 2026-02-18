1class Solution {
2public:
3    int totalWays = 0;
4    vector<vector<int>> directions{{1,0} , {-1 , 0} , {0 , 1} , {0 ,-1}};
5    void dfs(vector<vector<int>>& grid , int row , int col , int countOfCells , int totalCells , int m , int n){
6        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == -1 || grid[row][col] == '$') return;
7        if(grid[row][col] == 2){
8            countOfCells++;
9            if(countOfCells == totalCells) totalWays++;
10            return;
11        }
12
13        countOfCells++;
14        int temp = grid[row][col];
15        grid[row][col] = '$';
16
17        for(auto &dir : directions){
18            int new_row = row + dir[0];
19            int new_col = col + dir[1];
20
21            dfs(grid , new_row , new_col , countOfCells , totalCells , m , n);
22        }    
23
24        countOfCells--;
25        grid[row][col] = temp;
26
27
28
29    }
30    int uniquePathsIII(vector<vector<int>>& grid) {
31         int m = grid.size();
32         int n = grid[0].size();
33
34         int totalCells = 0;
35
36         int startRow = 0;
37         int startCol = 0;
38
39         for(int i = 0 ; i < m ; i++){
40            for(int j = 0 ; j < n ; j++){
41                if(grid[i][j] != -1) totalCells++;
42
43                if(grid[i][j] == 1){
44                     startRow = i;
45                     startCol = j;
46                } 
47            }
48         }
49
50         dfs(grid , startRow , startCol , 0 , totalCells , m , n);
51
52         return totalWays;
53    }
54};