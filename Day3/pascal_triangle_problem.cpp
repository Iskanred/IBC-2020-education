#include <iostream>
using namespace std;
typedef unsigned long long ull;

/*
 * Build Pascal Triangle of N rows and output Q numbers of combinations C(n, k) 
 *
 * Input: N - number of rows, Q - number of queries, Q rows of (n, k)
 * Output: Pascal Triangle, Q rows of C(n, k)
 */

ull** get_and_build_pascal_triangle(const int n) {
    ull** C = new ull*[n + 1];

    for (int i = 0; i <= n; i++)
    {
        C[i] = new ull[i + 1];
        C[i][0] = 1;
        C[i][i] = 1;

        if (i < 2)
            continue;

        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    cout << endl << "Pascal Triangle:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j <= i; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return C;
}

int main()
{
    int N; cin >> N;
    ull** C = get_and_build_pascal_triangle(N);

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int n, k; cin >> n >> k;

        if (k < 0 || n < 0 || n < k || n > N) {
            cout << endl << "incorrect input" << endl;
            return 0;
        }

        cout << "\t" << C[n][k] << endl;
    }

    return 0;
}
