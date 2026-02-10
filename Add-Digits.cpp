1class Solution {
2public:
3    int sumOfDigits(int n){
4        int sum = 0;
5        while(n > 0){
6            int lastDigit = n%10;
7            sum += lastDigit;
8            n = n/10;
9        }
10
11        return sum;
12    }
13    int addDigits(int num) {
14        int ans;
15        while(num >= 10){
16            ans = sumOfDigits(num);
17            num = ans;
18        }
19
20        return ans;
21    }
22};