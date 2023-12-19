// https://atcoder.jp/contests/abc088/tasks/abc088_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int a=0, b=0;

    while (!A.empty()) {
        a += A.back();
        A.pop_back();
        if (A.empty()) break;
        b += A.back();
        A.pop_back();
    }

    cout << a - b << endl;
}
