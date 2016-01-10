
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

int len;
char in[30];
char out[51];
long double  n;
long double  sz;

void recur(int ind, int start,  long double value)
{
     if(ind == len)
     {
          return;  
     }
     
     int tmp = len-1-ind;
     
      long double  pw = pow(sz*1.0,tmp);
     
     if(value + pw < n)
     {
              recur(ind, start+1, value+pw);
     }
     else
     {
             out[ind] = in[start];
             recur(ind+1,0,value);
     } 
     
}
int main(void)
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
	int t;
	 long long  i,j,k;
	cin >> t;
	getchar();
	
	int ca=1;
	string ans;
	
     long double  sum;

    
     long double  remaining;
	while(t--)
	{
		cin >> in >> n;
		sz = strlen(in);
		double T = 1 - (1-sz*1.0)*n*1.0/sz;
		double l = log(T)/ log(sz);
		len = (int)ceil(l);
		//cout << len << endl;
		
		sum = sz*(1 - pow(sz*1.0, len-1))/(1-sz);
		//cout << sum << endl;
		recur(0, 0, sum);
		out[len] = '\0';
		cout << "Case #" << ca++ << ": ";
		cout << out << endl;
	}
    return 0;
}
