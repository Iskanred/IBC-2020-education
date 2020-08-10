#include <iostream>
using namespace std;

// Find scholarship of srudent by grades

int main() {
    int N; cin >> N;
    int a[4] = {};

    for (int i = 0; i < N; ++i) {
        int grade; cin >> grade;
        ++a[grade - 2];
    }

    if (a[2 - 2] > 0)
        cout << "\ndrop\n";
    else if (a[3 - 2] > 0)
        cout << "\n12000\n";
    else if (a[4 - 2] > 2)
        cout << "\n18000\n";
    else if (a[5 - 2] != N)
        cout << "\n24000\n";
    else
        cout << "\n36000\n";

    return 0;
}