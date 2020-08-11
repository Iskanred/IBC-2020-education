#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

/* 
 * We have 'x' of 5-rub coins, 'y' of 2-rub coins and 'z' of of 1-rub coins.
 * We need to collect 'A' rubbles by minimal number of these coins
 * 
 * Input: x, y, z, A
 * Output: minimal number of coins to collect A rubbles and these coins
 */

const int X_TYPE = 5, Y_TYPE = 2, Z_TYPE = 1;

// Solving task for 3 type of coins (5, 2, 1) with help of Brutforce
int solve_bruforce_for_3_coins_type(int x, int y, int z, int reqSum) {
    int minCoinsNum = INF;

    for (int xi = 0; xi <= x; ++xi) {
        for (int yi = 0; yi <= y; ++yi) {
            for (int zi = 0; zi <= z; ++zi) 
            {
                int curSum = xi * X_TYPE + yi * Y_TYPE + zi * Z_TYPE;
                int curCoinsNum = xi + yi + zi;

                if (curSum == reqSum && curCoinsNum < minCoinsNum)
                    minCoinsNum = curCoinsNum;
            }
        }
    }

    return (minCoinsNum == INF) ? (-1) : minCoinsNum;
}

int main () {
    int x, y, z, A; cin >> x >> y >> z >> A;
    
    int ans = solve_bruforce_for_3_coins_type(x, y, z, A);

    if (ans == -1)
        cout << endl << "NO" << endl;
    else {
        cout << endl << "YES" << endl;
        cout << ans << endl;
    }

    return 0;
}