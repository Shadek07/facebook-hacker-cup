
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include <fstream>
#include<ctime>

using namespace std;

#define MAX 100005
#define eps 1e-6
#define pi acos(-1)

typedef pair<double,double> point;

bool dy(double x,double y)  {   return x > y + eps;} // x > y
bool xy(double x,double y)  {   return x < y - eps;} // x < y
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool eq(double x,double y) {   return fabs( x - y ) < eps;} //x==y
int p,x,y;

point getPair(double percentage){
    double angle = percentage*360/100.0;
    return point(50*cos(angle*pi/180.0), 50*sin(angle*pi/180.0));
}
double getAngle(double percentage){
    return percentage*360/100.0;
}
bool isInside(point p){
    if(xyd( (p.first-50)*(p.first-50) + (p.second-50)*(p.second-50), 50*50 )){
        return true;
    }else
        return false;

}
int cross_product(point a, point b, point c)
{
        double * AB = new double[2];
        double * AC = new double[2];
        AB[0] = b.first-a.first;
        AB[1] = b.second-a.second;
        AC[0] = c.first-a.first;
        AC[1] = c.second-a.second;
        double cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(xy(cross,0.0))
            return -1;
        else if(dy(cross,0.0))
            return 1;
        else
            return 0;
}

int main(void)
{
    freopen("progress_pie.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int ca=1;
    point P, c, d, Q, tmp;
    double angle;
    while(t--){
        cin >> p >> x >> y;
        cout << "Case #" << ca++ << ": ";
        Q = point(x,y);
        if(p == 0){ //empty bar
            cout << "white\n";
            continue;
        }
        if(!isInside(Q)){ //in the four corner areas
            cout << "white\n";
            continue;
        }
        if(x==50 && y >= 50){
            cout << "black\n";
            continue;
        }
        if(p == 100){
            cout << "black\n";
            continue;
        }

        tmp = getPair(p);
        angle = getAngle(p);

        if(xyd(angle,90.0)){
            P = point(50.0, 100.0);
            P.first += tmp.second;
            P.second -= 50-tmp.first;
            if(eq(angle,90.0)){
                P = point(100.0,50.0);
            }

        }else if(dy(angle, 90.0) && xyd(angle, 180.0)){
            P = point(100.0, 50.0);
            P.first -= (50-tmp.second);
            P.second += tmp.first;
            if(eq(angle,180.0)){
                P = point(50.0,0.0);
            }
        }else if(dy(angle, 180.0) && xyd(angle, 270.0)){
            P = point(50.0, 0.0);
            P.first += tmp.second;
            P.second = 50 - (-tmp.first);
            if(eq(angle,270.0)){
                P = point(0.0,50.0);
            }
        }else{
            P = point(0.0, 50.0);
            P.first += (50.0+tmp.second);
            P.second += tmp.first;
        }
        //cout << P.first << " " << P.second << endl;
        c = point(50,50);
        d = point(50,100);

        if(xyd(angle, 180.0)){
            if(cross_product(c, d, Q) <= 0 && cross_product(c, P, Q ) >= 0 ){
                cout << "black\n";
            }else{
                cout << "white\n";
            }
        }else{
            if(cross_product(c, d, Q) > 0 && cross_product(c, P, Q ) < 0 ){
                cout << "white\n";
            }else{
                cout << "black\n";
            }
        }
    }
    return 0;
}
