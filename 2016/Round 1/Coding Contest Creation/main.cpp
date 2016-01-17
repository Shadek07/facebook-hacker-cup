
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

int getExtra(int a, int b){
    int cnt=0;
    while(a+10<b){
        cnt++;
        a = a+10;
    }
    return cnt;
}
int main(void)
{
    //freopen("1.txt", "w", stdout);
    
    //freopen("coding_contest_creation.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    
    int arr[MAX];
    int i,j,k,a,b,n;
    int ans;
    int ca=1;
    
    //---input generate start-------
    /*cout << 10 << endl;
    forl(i,0,10){
        n = 1 + rand()%6;
        cout << n << endl;
        forl(j,0,n){
            cout << " " << 1 + rand()%50;
        }
        cout << endl;
    }
    return 0;*/
    //---input generate end-------
    
    cin >> t;
    while(t--){
        scanf("%d",&n);
        forl(i,0,n){
            scanf("%d",&arr[i]);
        }
        ans = 0;
        int last = arr[0];
        int taken = 1;
        forl(i,1,n){
            a = arr[i];
            b = 4 - taken;
            if((a<= last) || (a-last > b*10)){
                ans += b;
                taken = 1;
                last = a;
                continue;
            }
            
            if(a > last+10){
                int extra = getExtra(last, a);
                ans += extra;
                taken += extra;
            }
            taken++;
            if(taken == 4){
                if(i<n-1){
                    last = arr[i+1];
                    taken = 1;
                    i++;
                }
                continue;
            }
            last = a;
        }
        if(taken>0){
            ans += (4-taken);
        }
        printf("Case #%d: %d\n",ca,ans);
        ca++;
    }
    return 0;
}
