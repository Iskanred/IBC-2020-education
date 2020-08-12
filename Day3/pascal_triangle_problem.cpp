#include <iostream>
using namespace std;
typedef unsigned long long ull;

/*
 * Build Pascal Triangle output number of combinations C(n, k)
 *
 * Input: n, k
 * Output: Pascal Triangle, C(n, k)
 */

ull get_combinations_build_pascal_triangle(const ull n, const ull k) {
    if (k > n)
        return 0ll;

    ull** C = new ull*[n + 1]; // answer will be in C[n][k] cell

    for (ull i = 0; i <= n; i++)
    {
        C[i] = new ull[i + 1];
        C[i][0] = 1;
        C[i][i] = 1;

        if (i < 2)
            continue;

        for (ull j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    cout << endl << "Pascal Triangle:" << endl;
    for (ull i = 0; i <= n; i++) {
        for (ull j = 0; j <= i; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return C[n][k];
}

int main()
{
    ull n, k; cin >> n >> k;
    ull C = get_combinations_build_pascal_triangle(n, k);

    if (C == 0)
        cout << endl << "incorrect input" << endl;
    else
        cout << endl << "Answer: " << C << endl;

    return 0;
}