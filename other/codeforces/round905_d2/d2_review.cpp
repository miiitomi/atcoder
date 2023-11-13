#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int res(int N, int i, vector<int> A, vector<int> &B) {
    A[0] = i;
    sort(A.begin(), A.end());

    int k = 0;
    for (int i = 0; i + k < N; i++) {
        while (A[i] >= B[i+k]) {
            k++;
            if (i + k > N-1) break;
        }
    }
    return k;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0), B(N);
    for (int i = 1; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(B.begin(), B.end());

    ll x = res(N, 1, A, B);
    ll left = 1;
    ll right = M+1;

    while (right - left > 1) {
        ll mid = (right + left) / 2;
        if (res(N, mid, A, B) > x) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << left*x + (x+1)*(M - left) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
