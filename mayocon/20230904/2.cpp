// https://atcoder.jp/contests/abc273/tasks/abc273_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;
    map<int,int> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        M[a]++;
        if (M[a] == 1) A.push_back(a);
    }

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    for (int k= 0; k < N; k++) {
        if (k >= (int)A.size()) cout << 0 << endl;
        else {
            int a = A[k];
            if (k == 0 || A[k-1] > A[k]) cout << M[a] << endl;
            else cout << 0;
        }
    }
}
