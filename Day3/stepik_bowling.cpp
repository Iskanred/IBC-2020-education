#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N, K; cin >> N >> K;
    vector <bool> knocked (N, false);

    for (int i = 0; i < K; ++i) {
        int l, r; cin >> l >> r;

        for (int j = l; j <= r; ++j) {
            knocked[j - 1] = true;
        }
    }

    cout << endl;
    for (bool k : knocked) {
        if (k) 
            cout << ".";
        else 
            cout << "I";
    }
    cout << endl;

    return 0;
}
