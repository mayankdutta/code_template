#include <iostream>
#include <vector>

class UnionFind {
public:
  std::vector<int> Parent;
  std::vector<int> Size;

  void init(int n) {
    /* You may want to change the size. */
    Size.resize(int(3e5) + 5, 1);
    Parent.resize(int(3e5) + 5, 0);

    for (int i = 0; i < n; i++)
      Parent[i] = i;
  }

  void makeSet(int n) {
    Parent[n] = n;
    Size[n] = 1;
  }

  int findSet(int i) {
    return (Parent[i] == i) ? i : (Parent[i] = findSet(Parent[i]));
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b)
      return;
    if (Size[a] < Size[b])
      std::swap(a, b);

    Parent[b] = a;
    Size[a] += Size[b];
  }
} dsu;

class UnionFindSlow {
public:
  std::vector<int> Parent;
  std::vector<int> Size;

  void init(int n) {
    /* You may want to change the size. */
    Size.resize(int(3e5) + 5, 1);
    Parent.resize(int(3e5) + 5, 0);

    for (int i = 0; i < n; i++)
      Parent[i] = i;
  }

  void makeSet(int n) {
    Parent[n] = n;
    Size[n] = 1;
  }

  int findSet(int v) {
    if (v == Parent[v])
      return v;
    return findSet(Parent[v]);
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b)
      return;
    if (Size[a] < Size[b])
      std::swap(a, b);

    Parent[b] = a;
    Size[a] += Size[b];
  }
} sdsu;
