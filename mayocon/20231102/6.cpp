// https://atcoder.jp/contests/abc281/tasks/abc281_f
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

int f(int i, vector<int> &S) {
    vector<int> x, y;
    for (int s : S) {
        if (s & (1 << i)) x.push_back(s);
        else y.push_back(s);
    }

    if (i == 0) {
        if (x.empty() || y.empty()) return 0;
        else return 1;
    }

    if (x.empty()) return f(i-1, y);
    else if (y.empty()) return f(i-1, x);
    else return (1 << i) + min(f(i-1, x), f(i-1, y));
}

int main() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << f(30, a) << endl;
}
