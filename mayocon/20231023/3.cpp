// https://atcoder.jp/contests/abc167/tasks/abc167_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    
    unordered_set<int> S;
    S.insert(0);
    int now = 0;
    vector<int> V(1, now);
    while (!S.count(A[now])) {
        K--;
        now = A[now];
        S.insert(now);
        V.push_back(now);
        if (K == 0) {
            cout << now+1 << endl;
            return 0;
        }
    }

    now = A[now];
    K--;
    if (K == 0) {
        cout << now+1 << endl;
        return 0;
    }

    ll l = distance(find(V.begin(), V.end(), now), V.end());
    K = (K % l);

    while (K > 0) {
        now = A[now];
        K--;
    }

    cout << now+1 << endl;
}
