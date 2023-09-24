// https://atcoder.jp/contests/abc197/tasks/abc197_d
#include <bits/stdc++.h>
using namespace std;

vector<double> matrix_prod(vector<vector<double>> &A, vector<double> &B) {
    int l = A.size();
    int m = B.size();

    vector<double> V(l, 0);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] += A[i][k] * B[k];
        }
    }

    return V;
}

int main() {
    int N;
    cin >> N;
    double x0, y0, v, w;
    cin >> x0 >> y0 >> v >> w;

    double theta = 2*M_PI / N;
    double a = (x0 + v) / 2, b = (y0 + w) / 2;

    vector<vector<double>> A(2, vector<double>(2));
    A[0][0] = cos(theta);
    A[0][1] = -sin(theta);
    A[1][0] = sin(theta);
    A[1][1] = cos(theta);

    vector<double> B(2);
    B[0] = x0 - a;
    B[1] = y0 - b;

    vector<double> C = matrix_prod(A, B);

    cout << fixed << setprecision(15) << C[0] + a << " " << C[1] + b << endl;
}
