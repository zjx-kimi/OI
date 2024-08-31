#include <bits/stdc++.h>
using namespace std;
int n;
double a, b, r, x, y, theta;
struct Point
{
    double x, y;
} points[100005], convexHull[100005];
double crossProduct(Point a1, Point a2, Point b1, Point b2)
{
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}
double distance(Point p1, Point p2)
{
    return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}
bool compare(Point p1, Point p2)
{
    double tmp = crossProduct(points[1], p1, points[1], p2);
    if (tmp > 0)
        return true;
    if (tmp == 0 && distance(points[0], p1) < distance(points[0], p2))
        return true;
    return false;
}
Point change(Point x, Point y, double theta)
{
    double cx = x.x - y.x;
    double cy = x.y - y.y;
    return {
        cx * cos(theta) - cy * sin(theta) + y.x, cx * sin(theta) + cy * cos(theta) + y.y};
}
int main()
{
    scanf("%d", &n);
    cin >> a >> b >> r;
    swap(a, b);
    a -= 2 * r;
    b -= 2 * r;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> theta;
        points[i * 4] = change({x + a / 2, y + b / 2}, {x, y}, theta);
        points[i * 4 - 1] = change({x + a / 2, y - b / 2}, {x, y}, theta);
        points[i * 4 - 2] = change({x - a / 2, y + b / 2}, {x, y}, theta);
        points[i * 4 - 3] = change({x - a / 2, y - b / 2}, {x, y}, theta);
    }

    n *= 4;

    for (int i = 1; i <= n; i++) {

    }
    for (int i = 1; i <= n; i++)
    {
        if (i != 1 && points[i].y < points[1].y)
        {
            swap(points[1], points[i]);
        }
    }
    sort(points + 2, points + 1 + n, compare);
    convexHull[1] = points[1];
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        while (cnt > 1 && crossProduct(convexHull[cnt - 1], convexHull[cnt], convexHull[cnt], points[i]) < 0)
        {
            cnt--;
        }
        cnt++;
        convexHull[cnt] = points[i];
    }
    convexHull[cnt + 1] = points[1];

    double perimeter = 0;
    for (int i = 1; i <= cnt; i++)
    {
        perimeter += distance(convexHull[i], convexHull[i + 1]);
    }
    printf("%.2lf\n", perimeter + 3.141592653589793 * 2 * r);
    return 0;
}