// Wrote by MenYifan on 2016-09-19 19:06:38
// Exe.Time 15ms Exe.Memory 1596K
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
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=100000+5;
int a;
int main(){
    int n,k;
    while (scanf("%d",&n)!=EOF) {
        set<int>st;
        for (int i = 0; i<n; i++) {
            scanf("%d",&a);
            st.insert(a);
        }
        scanf("%d",&k);
        int sz = st.size();
        if (n-k>=sz) {
            printf("%d\n",sz);
        }
        else{
            printf("%d\n",sz -(k - (n-sz) ));
        }
        
    }

}