1class Solution {
2    public int missingNumber(int[] nums) {
3         int n = nums.length;
4         Arrays.sort(nums);
5
6         for(int i = 0 ; i < n ; i++){
7              if(nums[i] != i) return i;
8         }
9       
10       return n;
11
12    }
13}