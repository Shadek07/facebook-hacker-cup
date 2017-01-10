
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

#define MAX 100005

int main(void)
{
    freopen("lazy_loading.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    int ca=1;
    vector<int> v;
    int n;
    cin >> t;
    int i,a,j;
    while(t--){
        cin >> n;

        v.clear();
        forl(i,0,n){
            cin >> a;
            v.pb(a);
        }
        sort(all(v));
        int ans = 0;
        i = 0;
        j = n-1;
        while(j>=0 && v[j] >= 50){
            ans++;
            j--;
        }
        while(i<j){
            int a = v[j];
            while(i < j && a < 50){
                i++;
                a += v[j];
            }
            if(a>=50){
                ans++;
                j--;
            }else{
                break;
            }
        }
        cout << "Case #" << ca++ << ": ";
        cout << ans << endl;
    }
    return 0;
}
