

#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
#include <fstream>
#include<ctime>
#include<climits>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
#define SZ 302
int prefix[SZ][SZ];
int len[SZ];
char in[SZ][MAX];
int dp[SZ][SZ];
int comp(int a, int b){
    if(strcmp(in[a],in[b]) < 0)
        return 1;
    else
        return 0;
}
int main(void)
{
    freopen("text_editor.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int n,t,K;
    int i,j,k,cnt,a,b;
    cin >> t;
    int ca=1;
    long ans;
    while(t--){
        scanf("%d %d",&n,&K);
        getchar();
        len[0] = 0;
        vector<int> v;
        forl(i,1,n+1){
            v.pb(i);
            gets(in[i]);
        }
        sort(all(v), comp);
        /*for(i=1;i<n;i++){
            for(j=1;j<=n-i;j++){
                if(strcmp(in[j+1],in[j]) < 0){
                    swap(in[j],in[j+1]);
                }
            }
        }*/
        
        for(i=1;i<=n;i++){
            //cout << in[i] << endl;
            len[i] = strlen(in[ v[i-1] ]);
        }
        forl(i,0,n){
            forl(j,i+1,n+1){
                prefix[i][j] = prefix[j][i] = 0;
            }
        }
        forl(i,1,n){
            forl(j,i+1,n+1){
                cnt = 0;
                while(in[v[i-1]][cnt] && in[v[j-1]][cnt] && in[v[i-1]][cnt] == in[v[j-1]][cnt])
                    cnt++;
                prefix[i][j] = prefix[j][i] = cnt;
            }
        }
        forl(i,0,n+1){
            forl(j,0,n+1){
                dp[i][j] = 9999999;
            }
        }
        dp[0][0] = 0; //last index, counter
        for(k = 1; k <= n;k++){
            for(i=0;i<k;i++){
                for(j=i;j>=0;j--){
                    int cost=len[i] - prefix[i][k] + (len[k] - prefix[i][k])+1;
                    dp[k][j+1] = min(dp[k][j+1], dp[i][j] + cost);
                }
            }
        }
        ans = 9999999;
        for(i=K;i<=n;i++){
            if(dp[i][K] != 9999999){
                ans = min(ans, dp[i][K] + len[i]);
            }
        }
        printf("Case #%d: %d\n",ca,ans);
        ca++;
    }
    return 0;
}
