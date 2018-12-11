/***
Bresenham line - drawing algorithm.

***/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

class Point{
public:
    int x,y;
    Point(){x=0;y=0;}
    Point(int x0,int y0){x=x0;y=y0;}
};

void lineBres(int x0,int y0,int xEnd,int yEnd,vector<Point> &P)
{
	float m = (float)(yEnd - y0)/(float)(xEnd - x0);
	int flag = ( m > 0 ) ? 1 : 0;
	if(fabs(m)>1){
		int temp = x0;
		x0 = y0;
		y0 = temp;
		temp = xEnd;
		xEnd = yEnd;
		yEnd = temp;
	}
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);

	int p = 2 * dy - flag * dx;
	int x, y;

	if(x0 > xEnd){
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}

	else{
		x = x0;
		y = y0;
	}

	if(fabs(m)<1)
    {
        Point point(x,y);
		P.push_back(point);
    }
	else
    {
        Point point(y,x);
		P.push_back(point);
    }

	while(x <= xEnd){
		x++;
		if(p * flag > 0){
			y += flag;
			p += 2 * dy - flag * 2 * dx;
		}
		else
			p += 2 * dy;

        if(fabs(m)<1)
        {
            Point point(x,y);
            P.push_back(point);
        }
        else
        {
            Point point(y,x);
            P.push_back(point);
        }
	}
}

int main(){
	int x0,y0,xEnd,yEnd;
	cout<<"please input x0,y0,xEnd,yEnd"<<endl;
	cin>>x0>>y0>>xEnd>>yEnd;
    vector<Point> Points;
    lineBres(x0,y0,xEnd,yEnd,Points);
    cout<<"µãÎª"<<endl;
    for(int i=0;i<=max(fabs(xEnd-x0),fabs(yEnd-y0));i++)
        cout<<Points[i].x<<"  "<<Points[i].y<<endl;
	return 0;
}
