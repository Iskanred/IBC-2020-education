#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x = 0, y = 0;
};

int main () {
    Point pts[8] = {};

    for (int i = 0; i < 8; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            int xi = pts[i].x, yi = pts[i].y;
            int xj = pts[j].x, yj = pts[j].y;

            if (xi == xj || yi == yj || abs(xi - xj) == abs(yi - yj)) {
                cout << endl << "YES" << endl;
                return 0;
            }
        }
    }

    cout << endl << "NO" << endl;

    return 0;
}
