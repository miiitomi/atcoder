#include <bits/stdc++.h>
using namespace std;

double left(vector<int> &A, vector<int> &B, double x) {
    double res = 0;
    double now = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (now + A[i] < x) {
            res += (double)A[i] / (double)B[i];
            now += A[i];
        } else {
            res += (x - now) / (double)B[i];
            break;
        }
    }
    return res;
}

double right(vector<int> &A, vector<int> &B, int S, double x) {
    double res = 0;
    double now = 0;
    for (int i = (int)A.size() - 1; i >= 0; i--) {
        if (now + A[i] < S - x) {
            res += (double)A[i] / (double)B[i];
            now += A[i];
        } else {
            res += (S - x - now) / (double)B[i];
            break;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    int S = 0;
    for (int i = 0; i < N; i++) S += A[i];
    double l = 0;
    double r = S;
    double mid = (l + r) / 2;
    while (r - l > 1e-7) {
        mid = (l + r) / 2;
        if (left(A, B, mid) < right(A, B, S, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(7) << mid << endl;
}
