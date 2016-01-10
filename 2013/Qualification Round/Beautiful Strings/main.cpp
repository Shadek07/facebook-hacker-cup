
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
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>a?a:b))
#define min(a,b) ((a>b?b:a))

int main(void)
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int m,i,j,k;
    char in[505];
    int len;
    cin >> m;
    getchar();
    int ca=1;
    int cnt[27];
    vector<int> v;
    while(m--)
    {
              gets(in);
              len = strlen(in);
              memset(cnt,0,sizeof(cnt));
              for(i = 0;i<len;i++)
              {
                    if(in[i] >= 'A' && in[i] <= 'Z')
                    {
                             cnt[in[i]-'A']++;
                    }
                    else if(in[i] >= 'a' && in[i] <= 'z')
                    {
                         cnt[in[i]-'a']++;
                         
                    }
              }
              
              for(i = 0;i<26;i++)
              {
                    if(cnt[i] > 0)
                    {
                              v.push_back(cnt[i]);
                    }
              }
              
              k = 26;
              j = v.size();
              sort(v.begin(),v.end(),greater<int>());
              long int sum = 0;
              for(i = 0;i<j;i++)
              {
                    sum += k*v[i];
                    //cout << k << endl;
                    k--;
              }
              
              cout << "Case #" << ca++ << ": " << sum << endl;
              v.clear();
    }
    
     return 0;
}
