
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

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

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
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 302

vi pies[MAX];
LL dp[MAX][MAX];
int main(void)
{
    int t,ca=1;
    int n,m;
    int i,j,k,a;
    int c,e,mx,p,E,cost;

    //freopen("1.txt", "w", stdout);

    freopen("pie_progress.txt", "r", stdin);
    freopen("2.txt", "w", stdout);

    /*cout << 100 << endl;

    forl(k,0,300){
        cout << 300 << " " << 300 << endl;
        forl(i,0,300){
            forl(j,0,300){
                cout << " " << 1000000;
            }
            cout << endl;
        }
    }
    return 0;*/

    cin >> t;
    LL s = 0;
    while(t--){
        scanf("%d %d",&n,&m);
        fore(i,1,n){
            fore(j,1,m){
                scanf("%d",&a);
                pies[i].pb(a);
            }
            sort(all(pies[i]));
        }

        fore(i,0,n){
            fore(j,0,n){
                dp[i][j] = -1;
            }
        }
        fore(c,1,n){
            if(c == 1){
                s = 0;
                fore(p,1,m){
                    s += pies[c][p-1];
                    dp[c][p-1] = s + (p*p);
                }
                continue;
            }
            int mn = min(n-(c-1), (c-1)*(m-1) );
            fore(e,0,mn){
                mx = min(m,n-(c-1+e));
                s = 0;
                fore(p,0,mx){
                    E = e+(p-1);
                    if(E<0)
                        continue;
                    if(p>0)
                        s += pies[c][p-1];
                    LL total = 0;
                    if(dp[c-1][e] != -1)
                        total += dp[c-1][e];
                    total += s + (p*p);
                    if(dp[c][E] == -1)
                        dp[c][E] = total;
                    else
                        dp[c][E] = min(dp[c][E], total);
                }
            }
        }
        cout << "Case #" << ca << ": " << dp[n][0] << endl;
        ca++;
        fore(i,0,n){
            pies[i].clear();
        }
    }
    return 0;
}
