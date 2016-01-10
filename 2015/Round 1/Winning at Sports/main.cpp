

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

map< pair<int,int>, pair<long long,long long> > mp;
map< pair<int,int>, bool > mp1;
int main(void)
{
    freopen("winning_at_sports.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int t;
    long long int M = 1000000007;
    cin >> t;
    int i,j,k;
    int ca=1;
    int a,b;
    
    long long int ** dp = new long long int*[4002];
	long long int ** dp1 = new long long int*[4002];	
	for(i = 0; i < 4002; i++)
	{
		dp[i] = new long long int[2002];
	}
    while(t--)
	{
		//cin >> a >> b;
		scanf("%d-%d",&a,&b);
		cout << "Case #" << ca++ << ":";
		if(b == 0)
		{
			cout << " " << 1 << " " << 1 << endl;
			continue;
		}
		
		pair<int,int> p1 = make_pair(a,b);
		pair<int,int> p2;
		if(mp1[p1])
		{
			p2 = mp[p1];
			cout << " " << p2.first << " " << p2.second << endl;
			continue;
		}
		
		for(i = 0; i < a+b+2; i++)
		{
			for(j = 0; j < a+2; j++)
				dp[i][j] = 0;
		}
		
		dp[0][0] = 1;
		
		
		
		int T = a+b;
		int t;
		int mn;
		forl(t,1,T+1)
		{
			mn = t/2 + 1;
			forl(i,mn,a+1)
			{
				dp[t][i] = (dp[t][i] + dp[t-1][i])%M;
    		    dp[t][i] = (dp[t][i] + dp[t-1][i-1])%M;
			}
		} 
		
		
		cout << " " << dp[T][a];
		p2.first = dp[T][a];
		
		for(i = 0; i < a+b+2; i++)
		{
			for(j = 0; j < a+2; j++)
				dp[i][j] = 0;
		}
		dp[0][0] = 1;
		
		forl(t,1,2*b)
		{
			if(t%2==1)
				mn = t/2 + 1;
			else
				mn = t/2;
			forl(i,mn,b+1)
			{
				dp[t][i] = (dp[t][i] + dp[t-1][i])%M;
    		    dp[t][i] = (dp[t][i] + dp[t-1][i-1])%M;
			}
		}
		
		
		cout << " " << dp[2*b-1][b]  << endl;
		p2.second = dp[2*b-1][b];
		mp[p1] = p2;
		mp1[p1] = true;
	}
    
    
    return 0;
}

