
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
#include<cstring>
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

char grid[21][21];
int prefix[21][21];
int main(void)
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
	int n,i,j;
	int cnt;
	int t;
	int ca=1;
	cin >> t;
	while(t--)
	{
		cin >> n;
		getchar();

		
		for(i = 0;i<n;i++)
		{
			gets(grid[i]);
		}

		cout << "Case #" << ca++ << ": ";
		cnt=0;
		memset(prefix,0,sizeof(prefix));
		string ans = "YES";
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<n;j++)
			{
				if(j == 0)
				{
					if(grid[i][j] == '#')
					{
						cnt++;
						prefix[i][0] = 1;
					}
					else
					{
						prefix[i][0] = 0;
					}
				}
				else
				{
					if(grid[i][j] == '#')
					{
						cnt++;
						prefix[i][j] = prefix[i][j-1] + 1;
					}
					else
					{
						prefix[i][j] = 0;
					}
				}
			}
		}

		if(cnt == 0)
		{
			cout << "YES" << endl;
			continue;
		}

		double sqt = sqrt(cnt*1.0);
		if((sqt - int(sqt)) != 0)
		{
			ans = "NO";
			cout << ans << endl;
			continue;
		}

		int least_Index=n-1;
		int least_row;
		for(j = 0;j<n && ans.compare("NO") != 0;j++)
		{
			for(i = n-1;i>=0;i--)
			{
				if(prefix[j][i] > 0)
				{
					least_Index = i;
					least_row = j;
					j = n;
					i = -1;
					break;
				}
			}
			
			
		}

		int num = prefix[least_row][least_Index];
		bool ok = true;
		if(n-least_row < num)
		{
			ans = "NO";
			cout << ans << endl;
			continue;
		}
		if(num*num != cnt)
		{
			ans = "NO";
			cout << ans << endl;
			continue;
		}
		
		for(i = least_row;i<least_row+num && ans.compare("NO") != 0;i++)
		{
			if(!(prefix[i][least_Index] == num && prefix[i][least_Index-num+1] == 1))
			{
				ok = false;
				break;
			}
		}

		if(ok == true)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
		
	}

    return 0;
}
