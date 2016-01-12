
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

ull P;
ull prefix[MAX];
ull B[MAX];
int n;
int getCount(int ind){
    int low,high,mid;
    int ans=-1;
    low = ind;
    high = n;
    while(low <= high){
        mid = (low+high)/2;
        ull sum = prefix[mid]-prefix[ind-1];
        if(sum <= P){
            ans = mid;
            low=mid+1;
        }else{
            high = mid-1;
        }
    }
    if(ans == -1)
        return 0;
    return ans-ind+1;
    
}
int main(void)
{
    freopen("the_price_is_correct.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    int ca=1;
    
    
    int i,j;
    /*cout << 40 << endl;
    forl(j,0,40){
        cout << 100000 << " " << rand()%1000000001 << endl;
        forl(i,0,100000){
            int a = rand()%1000000001;
            cout << " " << a;
        }
        cout << endl;
    }
    return 0;*/
    
    cin >> t;
    ull ans;
    while(t--){
        scanf("%d %lld",&n,&P);
        forl(i,1,n+1){
            scanf("%lld",&B[i]);
        }
        prefix[0] = 0;
        forl(i,1,n+1){
            prefix[i] = prefix[i-1] + B[i];
        }
        ans = 0;
        forl(i,1,n+1){
            ans += getCount(i);
        }
        printf("Case #%d: %llu\n",ca,ans);
        ca++;
    }
    return 0;
}
