#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class UnionFind {
public:
  std::vector<int> Parent;
  std::vector<int> Size;
  int number_of_components;
  int max_size_of_component;
  int defaultSize;

  UnionFind() : defaultSize(int(3e5) + 5) {}

  UnionFind(int n)
      : defaultSize(int(3e5) + 5), number_of_components(n),
        max_size_of_component(n) {

    Size.resize(std::max(n, defaultSize), 1);
    Parent.resize(std::max(n, defaultSize), 0);
    std::iota(Parent.begin(), Parent.end(), 0);
  }

  void add(int n) {
    Parent[n] = n;
    Size[n] = 1;
  }

  int find(int n) {
    return (Parent[n] == n) ? n : (Parent[n] = find(Parent[n]));
  }

  int findSlow(int n) { return (n == Parent[n] ? n : findSlow(Parent[n])); }

  bool same(int i, int j) { return find(i) == find(j); }

  void merge(int a, int b) {
    a = find(a); // fast one
    b = find(b); // fast one
    if (a == b)
      return;

    if (Size[a] < Size[b])
      std::swap(a, b);

    Parent[b] = a;
    Size[a] += Size[b];
    number_of_components--;
    max_size_of_component = std::max(Size[a], max_size_of_component);
  }
} dsu;
