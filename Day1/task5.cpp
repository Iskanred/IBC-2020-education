#include <iostream>
#include <cmath>
using namespace std;

/** Chess
 *   1 2 3 4 5 6 7 8
 * 1 - - - - - - - - 
 * 2 - - - - - - - -
 * 3 - - - - - - - -
 * 4 - - - - - - - -
 * 5 - - - - - - - -
 * 6 - - Q - - - - -
 * 7 - - - - - - - -
 * 8 K - - - - - - -
*/

struct Point
{
    int x = 0, y = 0;
};


int main() 
{
    Point pQ, pK;
    cin >> pQ.x >> pQ.y >> pK.x >> pK.y;

    if (pQ.x == pK.x || pQ.y == pK.y || abs(pQ.x - pK.x) == abs(pQ.y - pK.y))
        cout << endl << "Yes" << endl;
    else 
        cout << endl << "No" << endl;

    return 0;
}