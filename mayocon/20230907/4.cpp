// https://atcoder.jp/contests/abc194/tasks/abc194_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    set<int> Q;
    for (int x = 0; x <= N; x++) Q.insert(x);

    vector<int> V(N+1, 0);
    for (int i = 0; i < M; i++) {
        int x = A[i];
        V[x]++;
        if (Q.count(x)) Q.erase(x);
    }
    int ans = *Q.begin();
    int i = M;

    while (i < N) {
        int a = A[i - M];
        int b = A[i];

        V[a]--;
        if (V[a] == 0) Q.insert(a);
        V[b]++;
        if (V[b] == 1) Q.erase(b);
        ans = min(ans, *Q.begin());
        i++;
    }

    cout << ans << endl;
}
