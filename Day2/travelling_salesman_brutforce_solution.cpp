#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/* BRUTE FORCE */
/*
  6 0
0   25   37   19   20    7
25   0   31   17    6   15
37  31    0   44   35   13
19  17   44    0   34   14
20   6   35   34    0   31
7   31   13   14   31    0
 */

void input_dists(int size, int** dists) {
    for (int i = 0; i < size; ++i) {
        dists[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            cin >> dists[i][j];
        }
    }
}

pair<int, int*> get_min_dist(int size, int** const dists, int start) {
    int lengthOfPath = size + 1;
    int minDist = INT_MAX;
    int* minDistOrderInPath = new int[lengthOfPath]{};
    int* orderInPath = new int[lengthOfPath]{};

    for (int i = 0; i < lengthOfPath - 1; ++i) {
        orderInPath[i] = i; // indices correspond values
    }

    swap(orderInPath[0], orderInPath[start]);
    orderInPath[lengthOfPath - 1] = start; // the last vertex is the start vertex

    do {
        int currentDist = 0;

        for (int i = 0; i < lengthOfPath - 1; ++i) {
            currentDist += dists[orderInPath[i]][orderInPath[i + 1]];
        }

        if (currentDist < minDist)
        {
            minDist = currentDist;
            for (int i = 0; i < lengthOfPath; ++i) {
                minDistOrderInPath[i] = orderInPath[i];
            }
        }

    } while (next_permutation(orderInPath + 1, orderInPath + lengthOfPath - 1));

    return {minDist, minDistOrderInPath};
}

int main()
{
    int N, start; cin >> N >> start;
    int** dists = new int*[N];
    input_dists(N, dists);

    auto minDistAns = get_min_dist(N, dists, start);
    int minDist = minDistAns.first;
    int* minDistPath = minDistAns.second;

    cout << endl << minDist << endl;
    for (int i = 0; i < N + 1; ++i) {
        cout << minDistPath[i] << " ";
    }



    return 0;
}