#include <iostream>
#include <cmath>
using namespace std;

// Find an area of Triangle if it exists

struct Point
{
    double x = 0.0, y = 0.0;
};

struct Vector
{
    double x, y;
    Vector(Point p1, Point p2) {
        x = p1.x - p2.x;
        y = p1.y - p2.y;
    }
};

int main() 
{
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    Vector v1 = Vector(p2, p1), v2(p3, p1);
    double crossProduct = (v1.x * v2.y - v2.x * v1.y);

    if (crossProduct == 0.0)
        cout << endl << "Triangle doesn't exist" << endl;
    else
        cout << endl << abs(crossProduct / 2) << endl;

    return 0;
}
