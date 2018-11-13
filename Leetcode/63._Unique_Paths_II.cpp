#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class NestedInteger {
  public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
//// Answers below
typedef long long ll;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
      if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
      else break;
    }
    for(int i = 0; i < m; i++) {
      if (obstacleGrid[0][i] == 0) dp[0][i] = 1;
      else break;
    }
    for(int i = 1; i < n; i++) {
      for(int j = 1; j < m; j++) {
        if(!obstacleGrid[i][j]) 
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n - 1][m - 1];
  }
};
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  
}
  
