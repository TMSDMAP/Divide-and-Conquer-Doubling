#include <iostream>
#include <cmath>
using namespace std;
struct Point {
	double x, y;
};
int n;
Point p[10005];
double dist(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)* (a.y - b.y));
}

int main()
{
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> p[i].x >> p[i].y;
	double minDist = 1e20;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double d = dist(p[i], p[j]);
			if (d < minDist)
				minDist = d;
		}
	}
	printf("%.4f\n", minDist);
	return 0;
}