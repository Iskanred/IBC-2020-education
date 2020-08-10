#include <iostream>
#include <string>
#include <map>
using namespace std;

// Convert number in Roman numeral system to Decimal

map <char, int> m;

int main() {
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    string rom; cin >> rom;
    int dec = 0;

    for (int i = rom.size() - 1; i >= 0 ; --i) {
        char rom_dig = rom[i];
        int dec_val = m[rom_dig];

        if (i + 1 < rom.size() && dec_val < m[rom[i + 1]]) {
            dec -= dec_val;
        }
        else {
            dec += dec_val;
        }
    }

    cout << endl << dec << endl;

    return 0;
}