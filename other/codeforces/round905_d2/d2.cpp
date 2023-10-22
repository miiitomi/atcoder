#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int i, vector<int> A, vector<int> &B) {
    int N = (int)A.size();
    A[0] = i;
    sort(A.begin(), A.end());
    int ans = 0;
    int cur = 0;

    while (ans + cur < N) {
        while (A[cur] >= B[ans+cur] && ans + cur < N) ans++;
        cur++;
    }

    return ans;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 1; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(B.begin(), B.end());

    int mv = f(1, A, B);
    int left=1, right=M+1;

    while (right-left>1) {
        int mid = (left+right)/2;
        if (f(mid, A, B) > mv) right = mid;
        else left = mid;
    }

    ll ans = (ll)M*mv + (M-left);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
