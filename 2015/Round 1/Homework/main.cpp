
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

bitset<(unsigned int)(1e7 + 1)> bit;

#define N 1e7+1
vector <int> primeList;

map<long long, int> mp;

void sieve()
{
	bit.set();
	bit.set(0,0);
	bit.set(1,0);
	int i,j;
	for(i=4;i<N;i+=2)
	{
		bit.set(i,0);
	}
	for(i =3 ; i*i < N; i+=2)
	{
		if(bit.test(i))
		{
			for(j = i*i; j<N; j += 2*i)
				bit.set(j,0);
		}
	}
	
	primeList.clear ();
	primeList.push_back (2);

	for ( i = 3; i < N; i += 2 ) {
		if ( bit.test(i) ) primeList.push_back (i);
	}
}

int main(void)
{
    freopen("homework.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    long long int i,j;
    //cout << primeList.size() << endl;
    //cout << primeList[primeList.size()-1] << endl;
    int sz = primeList.size();
    int ca=1;
    
    long long int a,b,k;
    int mx = 0;
    short *cnt = new short[10000001];
    int **prefix = new int*[9];
    for(i=0; i<9;i++)
	{
		prefix[i] = new int[10000001];
	}
	
	for(i = 0;i<9;i++)
	{
		prefix[i][0] = 0;
	}
	
	for(i=0;i<10000001;i++)
		cnt[i] = 0;
    
    for(i=0;i<sz;i++)
	{
		long long int mx = i;
		long long int pr = primeList[i];
		long long int val;
		for(j = 1; (val = j*pr) <= 1e7; j++)
		{
			cnt[val]++;
			//cout << cnt[val] << endl;
		}
	}
	
	forl(j,1,(1e7+1))
	{
		int a1 = cnt[j];
		forl(i,0,9)
		{
			if(a1 == i)
			prefix[i][j] = prefix[i][j-1] + 1;
			else
				prefix[i][j] = prefix[i][j-1];
			//cout << prefix[i][j] << endl;
		}
	}
    //cout << mx << endl;
    int t;
    cin >> t;
    while(t--)
	{
		cin >> a >> b >> k;
		cout << "Case #" << ca++ << ":";
		long long int cnt = 0;
		if(k > 8)
		{
			cout << " " << 0 << endl;
			continue;
		}
		 
		cout <<" " << prefix[k][b] - prefix[k][a-1] << endl;
	}
	
    return 0;
}

