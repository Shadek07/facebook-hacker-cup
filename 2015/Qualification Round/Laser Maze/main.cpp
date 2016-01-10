
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

int n,m;
vector<string> grid;
set<int> row_block[101];
set<int> col_block[101];

bool turret(char c)
{
	if(c == '>' || c == 'v' || c == '<' || c == '^')
		return true;
	return false;
}

map<vector<string>,bool> state_cond;

struct state
{
	vector<string> grid;
	int x,y;
	int steps;
};

char trs[] = {'>' , 'v' ,'<' ,'^'};
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

map<char,int> init_pos;

void change_grid(vector<string> &gr, vector<string> grid, int mov)
{
	int i,j;
	forl(i,0,n)
	{
		
		forl(j,0,m)
		{
			if(turret(grid[i][j]))
			{
				int pos = (init_pos[grid[i][j]] + mov)%4;
				gr[i][j] = trs[pos];
			}
			else
			{
				gr[i][j] = grid[i][j];
			}
			
		}
	}
}

bool safe_check(int posx, int posy, int mov)
{
	set<int>::iterator it;
	int r,c;
	int pos;
	it = lower_bound(row_block[posx].begin(),row_block[posx].end(),posy+1);
	
	if( it != row_block[posx].end())
	{
		c = *it;
		if(grid[posx][c] != '#')
		{
			pos = (init_pos[grid[posx][c]] + mov)%4;
			if(trs[pos] == '<')
				return false;
		}
		
	}
	
	std::set<int>::const_iterator lb(row_block[posx].lower_bound(posy));
    int a = lb == row_block[posx].begin() ? -1 : *--lb;
    if(a != -1)
	{
		if(grid[posx][a] != '#')
		{
			pos = (init_pos[grid[posx][a]] + mov)%4;
			if(trs[pos] == '>')
				return false;
		}
	}
	
	it = lower_bound(col_block[posy].begin(),col_block[posy].end(),posx+1);
	if(it != col_block[posy].end())
	{
		r = *it;
		if(grid[r][posy] != '#')
		{
			pos = (init_pos[grid[r][posy]] + mov)%4;
			if(trs[pos] == '^')
				return false;
		}
	}
	
	std::set<int>::const_iterator lb1(col_block[posy].lower_bound(posx));
    a = lb1 == col_block[posy].begin() ? -1 : *--lb1;
    if(a != -1)
	{
		if(grid[a][posy] != '#')
		{
			pos = (init_pos[grid[a][posy]] + mov)%4;
			if(trs[pos] == 'v')
				return false;
		}
	}
	
	
	return true;
	
}

int main(void)
{
    freopen("laser_maze.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ca=1;
    int t;
    int i,j,k;
    cin >> t;
    int srcx,srcy,destx,desty;
    char in[102];
    bool found;
    while(t--)
	{
		
		cin >> n >> m;
		getchar();
		grid.clear();
		forl(i,0,n)
		{
			gets(in);
			grid.push_back(in);
		}
		
		init_pos['>']  =0;
		init_pos['v']  =1;
		init_pos['<']  =2;
		init_pos['^']  =3;
		
		forl(i,0,n)
		{
			forl(j,0,m)
			{
				if(grid[i][j] == '#' || turret(grid[i][j]))
				{
					row_block[i].insert(j);
					col_block[j].insert(i);
				}
				else if(grid[i][j] == 'S')
				{
					srcx = i;
					srcy = j;
				}
				else if(grid[i][j] == 'G')
				{
					destx = i;
					desty = j;
				}
			}
		}
		
		found = false;
		int ans;
		queue<state> pq;
		struct state stcnd, stcnd1;
		
		stcnd.grid = grid;
		stcnd.steps = 0;
		stcnd.x = srcx;
		stcnd.y = srcy;
		//cout << destx << ' ' << desty << endl;
		pq.push(stcnd);
		while(!pq.empty())
		{
			stcnd = pq.front();
			//cout << stcnd.x << " " << stcnd.y << endl;
			//cout << stcnd.grid[0] << endl;
			//cout << stcnd.grid[1] << endl;
			
			if(stcnd.x == destx && stcnd.y == desty)
			{
				ans = stcnd.steps;
				found = true;
				break;
			}
			pq.pop();
			forl(k,0,4)
			{
				int a = stcnd.x + dx[k];
				int b = stcnd.y + dy[k];
				
				if(a>= 0 && a < n && b >= 0 && b < m && (stcnd.grid[a][b] == '.' || stcnd.grid[a][b] == 'G'))
				{
					if(safe_check(a,b,stcnd.steps+1))
					{
						vector<string> tmp;
						
						tmp = grid;
						change_grid(tmp, grid, stcnd.steps+1);
						tmp[a][b] = 'S';
						tmp[stcnd.x][stcnd.y] = '.';
						
						if(!state_cond[tmp])
						{
							state_cond[tmp] = true;
							stcnd1.x = a;
							stcnd1.y = b;
							stcnd1.steps = stcnd.steps+1;
							
							stcnd1.grid = tmp;
							pq.push(stcnd1);
						}
					}
					
				}
			}
		}
		
		cout << "Case #" << ca++ << ":";
		if(found)
			cout << " " << ans << endl;
		else
			cout << " " << "impossible" << endl;
			
	    forl(i,0,n)
	       row_block[i].clear();
	    
	    forl(i,0,m)
			col_block[i].clear();
		
		state_cond.clear();
		
	}
	
    return 0;
}
