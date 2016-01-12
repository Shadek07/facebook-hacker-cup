
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

#define MAX 1001
#define INF 9999999

char in[2][MAX];
int n;
int ans;

bool isSingle(int row, int col){
    if(in[row][col] != '.')
        return false;
    bool left = ((col == 0) || (in[row][col-1] == 'X'));
    bool right = ((col==n-1) ||(in[row][col+1] == 'X') );
    return (left && right);
}

void doit(int row){
    int i,j,k;
    int cnt=0;
    for(i=0;i<n;i++){
        if(in[row][i] == '.'){
            for(j=i+1;j<n;j++){
                if(in[row][j] == 'X')
                    break;
            }
            cnt = j-i;
            if(cnt > 1){
               bool found=false;
               for(k=i;k<j;k++){
                    if(isSingle(1^row,k)){
                        in[1^row][k] = '-';
                        ans++;
                        found=true;
                    }
               } 
               if(found){
                   for(k=i;k<j;k++){
                        in[row][k] = '-';
                   } 
               }
            }else{ //cnt==1
               if(isSingle(1^row,i)){
                   in[row][i] = '-';
                   in[1^row][i] = '-';
                   ans++; 
               } 
            }
            i = j;
        }
    }
}
#define INPUT_GEN 0
int main(void)
{
    //freopen("high_security.txt", "r", stdin);
    //freopen("1.txt", "w", stdout);
    
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,k;
    int ca=1;
    
    ///---input generate------
    #ifdef INPUT_GEN
       /* cout << 10 << endl;
        forl(i,0,10){
            int len = 1 + rand()%10;
            cout << len << endl;
            forl(k,0,2){
                forl(j,0,len){
                    int a = rand()%2;
                    if(a==0)
                        cout << ".";
                    else
                        cout << "X";
                }
                cout << endl;
            }
            
        }
        return 0;*/
    #endif
    ///-----input generate----
    cin >> t;
    while(t--){
        scanf("%d",&n);
        getchar();
        gets(in[0]);
        gets(in[1]);
        ans = 0;
        doit(0);
        doit(1);
        //cout << ans << endl;
        forl(i,0,2){
            forl(j,0,n){
                if(in[i][j] == '.'){
                    for(k=j+1;k<n;k++){
                        if(in[i][k] != '.'){
                            ans++;
                            break;
                        }
                    }
                    if(k == n){
                        ans++;
                    }
                    j = k;
                }
            }
        }
        
        printf("Case #%d: %d\n",ca,ans);
        ca++;
    }
    return 0;
}
