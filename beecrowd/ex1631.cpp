#include <iostream> 
#include <math.h>
#include <iomanip>

typedef struct point{
	double x,y;
} point;

typedef struct line{
	double a,b,c;
} line;

double dist(int a,int b,int c, int x, int y){
	return ((a*x + b*y + c) / sqrt(a*a + b*b));
}

using namespace std;
int main() {
	int t, i, j, k;
	int x1, y1, x2, y2;
	double distance, pos, sum, min;
	cin >> t;	
	while (t != 0){
		min = 10000;
		point points[t];
		for(i=0; i<t; i++){
			cin >> points[i].x >> points[i].y;
		}		
		for (i=0; i<t; i++){
			for (j=i+1; j<t; j++){
				x1 = points[i].x;
				x2 = points[j].x;
				y1 = points[i].y;
				y2 = points[j].y;
				line l;
				l.a = y2 - y1;
				l.b = - x2 + x1;
				l.c = - (l.a*x1 + l.b*y1);
				sum = 0;
				for (k=0; k<t; k++){
					distance = abs(dist(l.a, l.b, l.c, points[k].x, points[k].y));
					pos = l.a * points[k].x + l.b*points[k].y + l.c;
					if ( pos > 0){
						sum += distance;
					} else{
						sum -= distance;
					}
				}
				if (abs(sum) < min) min = abs(sum);
			}
		}
		cout << fixed << setprecision(3) << min << endl;
		cin >> t;
	}
	return 0;
}
