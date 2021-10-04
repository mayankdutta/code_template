#include <bits/stdc++.h>
using namespace std;

void print_array(const char *s, const vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    if (i)
      printf(", ");
    else
      printf("%s: [", s);
    printf("%d", arr[i]);
  }
  printf("]\n");
}

void reconstruct_print(int lis_end, const vector<int> &arr,
                       const vector<int> &parent) {
  int x = lis_end;
  stack<int> st;
  for (; parent[x] >= 0; x = parent[x])
    st.push(arr[x]);

  printf("[%d", arr[x]);

  for (; !st.empty(); st.pop())
    printf(", %d", st.top());

  printf("]\n");
}

void lis() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  vector<int> trackNum, trackIndex, parent(2 * arr.size(), 0);

  for (int i = 0; i < n; ++i) {
    int pos = upper_bound(trackNum.begin(), trackNum.end(), arr[i]) -
              trackNum.begin();
    if (pos >= trackNum.size()) {
      trackNum.push_back(arr[i]);
      trackIndex.push_back(i);
    } else {
      trackNum[pos] = arr[i];
      trackIndex[pos] = i;
    }

    parent[i] = pos ? trackIndex[pos - 1] : -1;

    /* printf("Considering element A[%d] = %d\n", i, arr[i]); */
    /* printf("LIS ending at A[%d] is of length %d: ", i, pos + 1); */
    /* reconstruct_print(i, arr, parent); */
    /* print_array("L is now", trackNum); */
    /* printf("\n"); */
  }

  /* printf("Final LIS is of length %d: ", trackNum.size()); */
  cout << trackNum.size() << '\n';
  /* reconstruct_print(arr.size() - 1, arr, parent); */
}

int main() { 
  lis();
}
