#include <bits/stdc++.h>
using namespace std;
int N, L, K;
vector<int> A;

bool is_ok(int m) {
    int cnt = 0;
    int now = 0;
    for (int i = 0; i <= N; i++) {
        int a = A[i];
        if (a - now >= m) {
            cnt++;
            now = a;
        }
    }
    return cnt >= K+1;
}

int main() {
    cin >> N >> L >> K;
    A.resize(N+1);
    for (int i = 0; i < N; i++) cin >> A[i];
    A[N] = L;

    int left = 1;
    int right = 1e+9 + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (is_ok(mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
