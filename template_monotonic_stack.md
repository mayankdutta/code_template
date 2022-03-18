```cpp
  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  vector<int> next_less(n, -1);
  vector<int> previous_less(n, -1);

  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() and arr[st.top()] > arr[i]) {
      st.pop();
    }

    previous_less[i] = (st.empty() ? -1 : st.top());
    st.push(i);
  }

  for (int i = 0; i < n; i++) {
    while (!st.empty() and arr[st.top()] > arr[i]) {
      auto x = st.top();
      st.pop();
      next_less[x] = i;
    }
    st.push(i);
  }

  cout << '\n';

  for (const auto &i : previous_less)
    cout << i << ' ';
  cout << '\n';

  for (const auto &i : next_less)
    cout << i << ' ';
  cout << '\n';

```


leetcode [blog](https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step)
