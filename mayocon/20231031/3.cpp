// https://atcoder.jp/contests/abc258/tasks/abc258_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<string> A;

vector<int> dx{0, 1, -1}, dy{0, 1, -1};

ll f(int i, int j, int x, int y) {
    ll ans = (int)(A[i][j] - '0');
    for (int k = 0; k < N-1; k++) {
        i = (i + x + N) % N;
        j = (j + y + N) % N;
        ans *= 10;
        ans += (int)(A[i][j] - '0');
    }
    return ans;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = -1;
    for (int x : dx) for (int y : dy) {
        if (x == 0 && y == 0) continue;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            ans = max(ans, f(i, j, x, y));
        }
    }
    cout << ans << endl;
}
