// https://atcoder.jp/contests/abc112/tasks/abc112_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for (int x = 1; x*x <= M; x++) {
        if (M % x == 0) {
            v.push_back(x);
            v.push_back(M / x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto iter = v.rbegin(); iter != v.rend(); iter++) {
        int x = *iter;
        if (M / x >= N) {
            cout << x << endl;
            return 0;
        }
    }
}
