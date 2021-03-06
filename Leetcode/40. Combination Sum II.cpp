#include <iostream>
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
//// header files
class Solution {
public:
	set<vector<int>> ans;
	
	void dfs(vector<int>& a, int pos, int val, int target, vector<int> tmp) {
		for(int i = pos; i >= 0; i--) {
			int vv = val + a[i];
			if (vv < target) {
				vector<int> ttmp(tmp.begin(), tmp.end());
				ttmp.push_back(a[i]);
				dfs(a, i-1, vv, target, ttmp);
			}
			else if (vv == target) {
				vector<int> ttmp(tmp.begin(), tmp.end());
				ttmp.push_back(a[i]);
				ans.insert(ttmp);
			}
		}
	}
	
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, (int)candidates.size()-1, 0, target, vector<int>());
		return vector<vector<int>>(ans.begin(), ans.end());
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
}