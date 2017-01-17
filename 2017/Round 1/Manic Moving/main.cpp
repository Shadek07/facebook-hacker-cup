
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

#define MAX 101
#define MX 10000000007
LL dist[MAX][MAX];
int movs[5001][2];
LL dp[5001][2][2];
int n,m,K;

LL doit(int index, int se, int pre){
    int s1,d1,s2,d2;
    if(index == K){
        if(se == 1){ //at the end
            return 0;
        }else{
            if(pre == 1){//previous car picked
                return  dist[movs[index][0]][movs[index-1][1] ] + dist[movs[index-1][1] ][movs[index][1] ];
            }else{
                return dist[movs[index][0] ][movs[index][1] ];
            }
        }
    }
    if(dp[index][se][pre] != -1){
        return dp[index][se][pre];
    }
    LL ans = MX;
    LL cost;
    if(se == 0){//start of the route
        if(pre == 0){
            s1 = movs[index][0], d1 = movs[index][1];
            s2 = movs[index+1][0], d2 = movs[index+1][1];
            if(s1 == s2 && d1 == d2){
                ans = min(ans, dist[s1 ][d1 ] + doit(index+1, 1, 0));
            }else{
                ans = min(ans, dist[movs[index][0] ][movs[index][1] ] + doit(index, 1, 0));
                ans = min(ans, dist[movs[index][0] ][movs[index+1][0] ] + doit(index+1, 0, 1));
            }
        }else{
            LL s2d1 =  dist[movs[index][0] ][movs[index-1][1] ];
            ans = min(ans, s2d1+dist[movs[index-1][1] ][movs[index][1] ] + dist[movs[index][1] ][movs[index+1][0] ] + doit(index+1,0,0));
            ans = min(ans, s2d1+dist[movs[index-1][1] ][movs[index+1][0] ] + doit(index+1,0,1));
        }
    }else{
        ans = min(ans, dist[movs[index][1] ][movs[index+1][0] ] + doit(index+1, 0, 0));
    }

    dp[index][se][pre] = ans;
    return ans;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t,ca=1;

    int i,j,k,a,b,g;

    freopen("manic_moving.txt", "r", stdin);
    freopen("2.txt", "w", stdout);

    /*freopen("1.txt", "w", stdout);
    srand(time(NULL));
    cout << 100 << endl;
    forl(i,0,100){
        n = 2 + rand()%99;
        m = 1 + rand()%5000;
        K = 1 + rand()%5000;
        cout << n << " " << m << " " << K << endl;
        forl(k,0,m){
            a = 1 + rand()%n;
            b = 1+rand()%n;
            while(a==b){
                b = 1+rand()%n;
            }
            g = 1+rand()%1000;
            cout << a << " " << b << " " << g << endl;
        }
        forl(j,0,K){
            a = 1+rand()%n;
            b = 1+rand()%n;
            while(a==b){
                b = 1+rand()%n;
            }
            cout << a << " " << b << endl;
        }
    }
    return 0;*/

    /*
    3 2 2
    1 2 2
    2 3 3
    2 3
    2 3

    5 5 2
    1 2 1
    2 5 1
    2 3 5
    2 4 2
    3 4 2
    1 4
    1 5
    */

    cin >> t;
    while(t--){
        scanf("%d %d %d",&n,&m,&K);
        fore(i,1,n){
            fore(j,i+1,n){
                if(i==j){
                    dist[i][i] = 0;
                }else{
                    dist[i][j] = dist[j][i] = MX;
                }
            }
        }
        forl(i,0,m){
            scanf("%d %d %d",&a,&b,&g);
            if(dist[a][b] > g){
                dist[a][b] = dist[b][a] = g;
            }
        }
        fore(k,1,n){
            fore(i,1,n){
                fore(j,1,n){
                    if(i!= j && k != i && k != j){
                        if(dist[i][k] != MX && dist[k][j] != MX){
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        bool ok=true;
        fore(i,1,K){
            scanf("%d %d",&movs[i][0],&movs[i][1]);
            if(dist[movs[i][0]][movs[i][1]] == MX){
                ok=false;
            }
        }
        if(!ok){
            cout << "Case #" << ca++ << ": " << -1 << endl;
            continue;
        }
        ms(dp,-1);
        LL ans = dist[1][movs[1][0] ] + doit(1,0,0);
        cout << "Case #" << ca++ << ": " << ans << endl;
    }
    return 0;
}
