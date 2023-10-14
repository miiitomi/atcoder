// https://atcoder.jp/contests/abc178/tasks/abc178_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> s(N), t(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = x+y;
        t[i] = x-y;
    }
    int a = *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
    int b = *max_element(t.begin(), t.end()) - *min_element(t.begin(), t.end());
    cout << max(a, b) << endl;
}
