#include <unordered_map>
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
	
	int minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.empty()) return 0;
		
		vector<int>st(intervals.size());
		vector<int>ed(intervals.size());
		for (int i = 0 ; i < intervals.size(); i++) {
			st[i] = intervals[i].start;
			ed[i] = intervals[i].end;
		}
		sort(st.begin(), st.end());
		sort(ed.begin(), ed.end());
		
		int ans = 0;
		
		for (int st_ptr = 0, ed_ptr = 0; st_ptr < intervals.size(); st_ptr++) {
			if (st[st_ptr] < ed[ed_ptr]) 
				ans++;
			else 
				ed_ptr++;
		}
		
		return ans;
	}
};

//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
