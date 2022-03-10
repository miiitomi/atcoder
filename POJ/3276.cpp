#include <iostream>
#include <vector>
using namespace std;

int rec(int N, vector<bool> &a, vector<bool> &f, int K, int S, int v) {
    if (v + K == N) {
        bool a_v = ((a[v] + S) % 2 == 1);
        for (int i = v + 1; i < N; i++) {
            if (i - K >= 0) S -= (int)f[i - K];
            if ((int)a_v != (a[i] + S) % 2) return 1e+8;
        }
        if (a_v) return 0;
        else return 1;
    }

    int ans = 0;
    if ((S + (int)a[v]) % 2 == 0) {
        ans++;
        S++;
        f[v] = true;
    }
    if (v - K + 1 >= 0) S -= (int)f[v - K + 1];
    ans += rec(N, a, f, K, S, v+1);
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<bool> a(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        a[i] = (c == 'F');
    }

    int ans = 1e+9;
    int ans_K = -1;
    for (int K = 1; K <= N; K++) {
        vector<bool> f(N, false);
        int tmp = rec(N, a, f, K, 0, 0);
        if (ans > tmp) {
            ans = tmp;
            ans_K = K;
        }
    }
    cout << ans_K << " " << ans << endl;
}
