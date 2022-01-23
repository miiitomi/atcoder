// 解説AC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool mean_is_greater_than_k(int N, vector<int> &A, double K) {
    vector<double> B(N);
    for (int i = 0; i < N; i++) B[i] = (double)A[i] - K;

    vector<double> f(N+1, 0.0), g(N+1, 0.0);

    for (int i = 0; i < N; i++) {
        f[i+1] = max(f[i], g[i]) + B[i];
        g[i+1] = f[i];
    }

    if (max(f[N], g[N]) >= 0.0) return true;
    else return false;
}

bool median_is_greater_than_k(int N, vector<int> &A, int K) {
    vector<int> B(N, -1);
    for (int i = 0; i < N; i++) {
        if ((A[i] >= K)) B[i] = 1;
    }

    vector<int> f(N+1, 0), g(N+1, 0);

    for (int i = 0; i < N; i++) {
        f[i+1] = max(f[i], g[i]) + B[i];
        g[i+1] = f[i];
    }

    if (max(f[N], g[N]) > 0) return true;
    else return false;
}


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    double left = 0;
    double right = 1e+9 + 1;
    double mid;
    while (right - left > 1e-6) {
        mid = (left + right) / 2.0;
        if (mean_is_greater_than_k(N, A, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;

    int left1 = 0;
    int right1 = 1e+9 + 1;
    int mid1;
    while (right1 - left1 > 1) {
        mid1 = (left1 + right1) / 2;
        if (median_is_greater_than_k(N, A, mid1)) {
            left1 = mid1;
        } else {
            right1 = mid1;
        }
    }
    cout << left1 << endl;
}
