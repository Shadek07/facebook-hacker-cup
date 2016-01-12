
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

#define MAX 2005
#define INF 9999999

long long pnts[MAX][2];
long long dis[MAX][MAX];
bool isEqual(int i, int j, int k){ //i-j, i-k
    long long a,b;
    a = pow((pnts[i][0]-pnts[j][0])*1.0,2) + pow((pnts[i][1]-pnts[j][1])*1.0,2);
    b = pow((pnts[i][0]-pnts[k][0])*1.0,2) + pow((pnts[i][1]-pnts[k][1])*1.0,2);
    return a==b;
}

long long getDist(int i, int j){
  long long c = pnts[i][0]-pnts[j][0];
  long long d = pnts[i][1]-pnts[j][1];
  return c*c + d*d;
}

map<long long, int> mp;
int main(void)
{
    freopen("boomerang_constellations.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n,i,j,k;
    set<pii> st;
    set<pii>::iterator it;
    pii p1;
    /*while(true){
        
        i = rand()%5000;
        j = rand()%5000;
        p1 = make_pair(i,j);
        st.insert(p1);
        if(st.size() ==2000)
            break;
    }
    cout << 50 << endl;
    forl(i,0,50){
        cout << 2000 << endl;
        for(it = st.begin(); it != st.end(); it++){
            //p1 = *it;
            cout << (*it).first << " " << (*it).second << endl;
        }
    }
    return 0;*/
    cin >> t;
    int ca=1;
    long long cnt;
    long long a,b,c,d;
    map<long long, int> ::iterator it1;
    while(t--){
        scanf("%d",&n);
        forl(i,0,n){
            scanf("%lld %lld",&pnts[i][0], &pnts[i][1]);
        }
        cnt=0;
        forl(i,0,n){
            forl(j,i+1,n){
                c = pnts[i][0]-pnts[j][0];
                d = pnts[i][1]-pnts[j][1];
                a = c*c + d*d;
                dis[i][j] = dis[j][i] = a;
            }
        }
        forl(i,0,n){
            mp.clear();
            forl(j,0,n){
                if(i == j)
                    continue;
                a = dis[i][j];
                int c1 = mp[a]++;
                cnt += c1;
            }
            /*for(it1 = mp.begin(); it1 != mp.end(); it1++){
                long long b = it1->second;
                cnt += ((b)*(b-1))/2;
            }*/
        }
        printf("Case #%d: %lld\n",ca,cnt);
        ca++;
    }
    return 0;
}
