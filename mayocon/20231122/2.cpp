// https://atcoder.jp/contests/abc274/tasks/abc274_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> d(2*N+2, 0);
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        d[2*i] = d[a] + 1;
        d[2*i + 1] = d[a] + 1;
    }

    for (int k = 1; k <= 2*N+1; k++) cout << d[k] << endl;
}
