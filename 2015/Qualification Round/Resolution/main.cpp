
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


#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int nutri[21][3];

int protein, carbo, fat;
int n;
int main(void)
{
    freopen("new_years_resolution.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ca=1;
    int t;
    int i,j,k;
    cin >> t;
    while(t--)
	{
		cin >> protein >> carbo >> fat;
		cin >> n;
		forl(i,0,n)
		{
			cin >> nutri[i][0] >> nutri[i][1] >> nutri[i][2];
		}
		int mx = 1<<n;
		bool found=false;
		int a,b,c;
		
		forl(i,1,mx)
		{
			a = b = c = 0;
			forl(j,0,n)
			{
				if((i & (1<<j)) != 0)
				{
					a += nutri[j][0];
					b += nutri[j][1];
					c += nutri[j][2];
				}
			}
			if(a == protein && b == carbo && c == fat)
			{
				found = true;
				break;
			}
		}
		cout << "Case #" << ca++ << ":";
		if(found)
			cout << " " << "yes" << endl;
		else
			cout << " " << "no" << endl;
	}
    return 0;
}
