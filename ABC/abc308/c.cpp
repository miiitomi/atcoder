#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int N;
vector<ull> A, B;

bool cmp(const int &i, const int &j) {
    ull a1 = A[i];
    ull x1 = A[i] + B[i];
    ull a2 = A[j];
    ull x2 = A[j] + B[j];
    ull y1 = a1 * x2;
    ull y2 = a2 * x1;
    if (y1 > y2) return true;
    else if (y1 == y2 && i < j) return true;
    else return false;
}

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> P(N);
    for (int i = 0; i < N; i++) P[i] = i;

    sort(P.begin(), P.end(), cmp);
    for (int i = 0; i < N; i++) {
        if (i < N-1) cout << P[i] + 1 << " ";
        else cout << P[i] + 1 << endl;
    }
}
