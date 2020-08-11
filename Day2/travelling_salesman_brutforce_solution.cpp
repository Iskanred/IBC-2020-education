#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/* There are N towns. Travelling salesman need to start from town 'start', visit all towns and come back to 'start'
 * We need to find the optimal(shortest) path from town 'start' to town 'start' through all the remaining towns
 * 
 * Number of towns: from 0 to N - 1
 * 
 * Input: N, start, matrix of distances between towns
 * Output: minimal distance, optinal path
 */

void input_dists(int size, int** dists) {
    for (int i = 0; i < size; ++i) {
        dists[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            cin >> dists[i][j];
        }
    }
}

/**
 * return a pair: -first- is min distance, -second- is path with min distance
 */
pair<int, int*> get_min_dist(int size, int** const dists, int start) {
    int lengthOfPath = size + 1;
    int minDist = INT_MAX;
    int* minDistPath = new int[lengthOfPath]{};
    int* currentPath = new int[lengthOfPath]{};
    
    currentPath[0] = start; // the first vertex is the start vertex
    currentPath[lengthOfPath - 1] = start; // the last vertex is the start vertex
    
    // Filling array 'currentOrderInPath' by some sorted permutation (perm only of elems with indices: from 1 to lengthOfPath - 1)
    // It must be sorted to get all perms by next_perm func from STL, f.e. {2, (0, 1, 3, 4,) 2} where '2' is start point
    for (int i = 1; i < lengthOfPath - 1; ++i) {
        if (i <= start)
            currentPath[i] = i - 1;
        else
            currentPath[i] = i; 
     }
     

    do {
        int currentDist = 0;

         // 'lengthOfPath- 1' cause of ( number of roads(dists) == number of towns(length of path) - 1 )
        for (int i = 0; i < lengthOfPath - 1; ++i) {
            currentDist += dists[currentPath[i]][currentPath[i + 1]]; // distance beetwen [i]-town and [i+1]-town
        }

        if (currentDist < minDist) 
        {
            minDist = currentDist;
            for (int i = 0; i < lengthOfPath; ++i)
                minDistPath[i] = currentPath[i];
        }

    } while (next_permutation(currentPath + 1, currentPath + lengthOfPath - 1));

    return {minDist, minDistPath};
}

int main()
{
    int N, start; cin >> N >> start;
    int** dists = new int*[N];
    input_dists(N, dists);

    auto minDistAns = get_min_dist(N, dists, start);
    int minDist = minDistAns.first;
    int* minDistPath = minDistAns.second;

    cout << endl << "Minimal Distance: " << minDist << endl << "Shortest path: ";
    for (int i = 0; i < N + 1; ++i) 
    {
        cout << minDistPath[i] << " ";
    }
    cout << endl;

    return 0;
}