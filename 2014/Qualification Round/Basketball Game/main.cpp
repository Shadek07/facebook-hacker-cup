
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
#include <functional> 
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); } 
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))


vector<string> player_name;
struct player
{
	string name;
	int shot;
	int height;
}pl[31];

struct field
{
	int played;
	int draft;
	string name;
};

struct bench
{
	int played;
	int draft;
	string name;
};


int n,m,p;

int cmp(player a, player b)
{
	if(a.shot > b.shot)
		return 1;
	else if(a.shot == b.shot && a.height > b.height)
		return 1;
	return 0;
}

int cmp1(field a, field b)
{
	if(a.played < b.played)
		return 1;
	else if(a.played == b.played && a.draft < b.draft)
		return 1;
	return 0;
}

int cmp2(bench a, bench b)
{
	if(a.played > b.played)
		return 1;
	else if(a.played == b.played && a.draft > b.draft)
		return 1;
	return 0;
}

int main(void)
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
	int t;
	int ca=1;
	cin >> t;
	int i,j,k;
	vector<field> f1,f2;
	vector<bench> b1,b2;
	struct field fi;
	struct bench be;
	while(t--)
	{
		cin >> n >> m >> p;
		getchar();
		for(i = 0;i<n;i++)
		{
			cin >> pl[i].name >> pl[i].shot >> pl[i].height;
		}

		sort(pl,pl+n,cmp);
		int cnt1,cnt2;
		cnt1 = cnt2 = 0;
		for(i = 0;i<n;i++)
		{
			if(i%2==0) //first team
			{
				if(cnt1<p)
				{
					fi.draft = i+1;
					fi.name = pl[i].name;
					fi.played = 0;
					f1.push_back(fi);
					cnt1++;
				}
				else
				{
					be.draft = i+1;
					be.name = pl[i].name;
					be.played = 0;
					b1.push_back(be);
				}

			}
			else   //second team
			{
				if(cnt2<p)
				{
					fi.draft = i+1;
					fi.name = pl[i].name;
					fi.played = 0;
					f2.push_back(fi);
					cnt2++;
				}
				else
				{
					be.draft = i+1;
					be.name = pl[i].name;
					be.played = 0;
					b2.push_back(be);
				}
			}
		}

		cout << "Case #" << ca++ << ":";
		for(i = 0;i<m;i++)
		{

			struct field fld,fld1;
			struct bench ben,ben1;

			for(j = 0;j<p;j++)
			{
				f1[j].played++;
				f2[j].played++;
			}

			sort(f1.begin(), f1.end(),cmp1);
			sort(f2.begin(), f2.end(),cmp1);

			sort(b1.begin(), b1.end(), cmp2);
			sort(b2.begin(), b2.end(), cmp2);

			if(b1.size() > 0)
			{
				ben.name = f1[p-1].name;
				ben.draft = f1[p-1].draft;
				ben.played = f1[p-1].played;

				int sz = b1.size();
				fld.name = b1[sz-1].name;
				fld.draft = b1[sz-1].draft;
				fld.played = b1[sz-1].played;

				f1.pop_back();
				b1.pop_back();
				
				f1.push_back(fld);
				b1.push_back(ben);
			}
			if(b2.size() > 0)
			{
				ben.name = f2[p-1].name;
				ben.draft = f2[p-1].draft;
				ben.played = f2[p-1].played;

				int sz = b2.size();
				fld.name = b2[sz-1].name;
				fld.draft = b2[sz-1].draft;
				fld.played = b2[sz-1].played;

				f2.pop_back();
				b2.pop_back();
				
				f2.push_back(fld);
				b2.push_back(ben);
			}

		}

		for(i = 0;i<p;i++)
		{
			player_name.push_back(f1[i].name);
			player_name.push_back(f2[i].name);
		}

		sort(player_name.begin(), player_name.end());

		for(i = 0;i<2*p;i++)
		{
			cout << " " << player_name[i];
		}
		cout << endl;
		
		f1.clear();
		f2.clear();
		b1.clear();
		b2.clear();

		player_name.clear();

	}
    return 0;
}
