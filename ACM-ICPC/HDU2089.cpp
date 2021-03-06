// Wrote by MenYifan on 2016-08-29 19:15:50
// Exe.Time 31ms Exe.Memory 1592K
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
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=500+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll dp[25][10][2];
ll num[25];
ll dfs(int pos,int pre,int status, bool limit){
    if (pos < 1) {
        return status;
    }
    if (!limit&&dp[pos][pre][status]!=-1) {
        return dp[pos][pre][status];
    }
    int mx = limit ? num[pos] : 9;
    ll ret = 0;
    for (int i=0; i<=mx; i++) {
        ret += dfs(pos - 1, i, status||(i==4)||(pre==6&&i==2), limit&&i==mx);
    }
    if (!limit) {
        dp[pos][pre][status] = ret;
    }
    return ret;
}
ll solve(ll n){
    Memset(dp, -1);
    int pos = 0;
    ll tmp = n;
    while (tmp) {
        num[++pos] = tmp % 10;
        tmp /= 10;
    }
    return n - dfs(pos, 0, 0, 1);
}
int main(){
    ll n,m;
    while (scanf("%lld%lld",&n,&m),n+m) {
        cout<<solve(m) - solve(n-1)<<endl;
    }
}