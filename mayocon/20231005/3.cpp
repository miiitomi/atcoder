// https://atcoder.jp/contests/abc312/tasks/abc312_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int left = 0;
    int right = 1e+9 + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        auto iter1 = lower_bound(A.begin(), A.end(), mid+1);
        int uru = distance(A.begin(), iter1);
        auto iter2 = lower_bound(B.begin(), B.end(), mid);
        int kau = distance(iter2, B.end());
        if (uru >= kau) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
