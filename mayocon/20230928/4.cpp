// https://atcoder.jp/contests/abc160/tasks/abc160_d
#include <bits/stdc++.h>
using namespace std;

int N, X, Y;

int f(int i, int j) {
    return min(j - i, abs(X-i) + 1 + abs(Y - j));
}

int main() {
    cin >> N >> X >> Y;
    vector<int> A(N, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            int x = f(i, j);
            A[x]++;
        }
    }

    for (int k = 1; k <= N-1; k++) cout << A[k] << endl;
}
