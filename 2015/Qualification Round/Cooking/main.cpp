
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

int main(void)
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int ca=1;
    long long int n;
    string in,mn,mx;
    int sz,i,j;
    while(t--)
	{
		cin >> n;
		cout << "Case #" << ca++ << ":";
		if(n == 0)
		{
			cout << " " << 0 << " " << 0 << endl;
			continue;
		}
		
		in = to_string(n);
		sz = in.size();
		mn = in;
		mx = in;
		int ind=-1;
		int a;
		bool done = false;
		forl(i,0,sz-1)
		{
			if(done)
				break;
			a = (mn[i] - '0');
			ind = -1;
			for(j=sz-1;j>=i+1;j--)
			{
				if(i == 0 && mn[j] == '0')
					continue;
				if((mn[j] - '0') < a)
				{
					ind = j;
					a = (mn[j] - '0');
				}
			}
			if(ind != -1)
			{
				swap(mn[i],mn[ind]);
				done = true;
				break;
			}
			
		}
		
		done = false;
		ind = -1;
		forl(i,0,sz-1)
		{
			if(done)
				break;
			a = (mx[i] - '0');
			ind = -1;
			for(j=sz-1;j>=i+1;j--)
			{
				
				if((mx[j] - '0') > a)
				{
					ind = j;
					a = (mx[j] - '0');
				}
			}
			if(ind != -1)
			{
				swap(mx[i],mx[ind]);
				done = true;
				break;
			}
			
		}
		
		cout << " " << mn << " " << mx << endl;
		
	}
	
    return 0;
}
