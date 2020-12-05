#include <iostream>
#include <vector>

class UnionFind {
    std::vector <int> p;
    std::vector <int> rank;
    public:

    UnionFind (int N) { 
        rank.resize (N, 0); 
        p.resize (N, 0); 

        for (int i=0; i<N; i++) p[i] = i; 
    }

    int findSet (int i) { 
        return (p[i] == i) ? i : (p[i] == findSet (p[i])); 
    }

    bool isSameSet (int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    void unionSet (int i, int j) { 
        if (!isSameSet (i, j)) {
            int x = findSet (i), y = findSet (j); 
            if (rank [x] > rank[y]) p[y] = x; 
            else { 
                p[x] = y; 
                if (rank [x] == rank[y]) rank [y] ++; 
            }
        }
    }
};
