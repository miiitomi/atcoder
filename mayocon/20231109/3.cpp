// https://atcoder.jp/contests/abc308/tasks/abc308_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> A, B;

bool cmp(int &i, int &j) {
    ll s = A[i] * (A[j] + B[j]), t = A[j] * (A[i] + B[i]);
    if (s > t) return true;
    else if (s < t) return false;
    else return i < j;
}

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), cmp);

    for (int i : v) cout << i + 1 << " ";
    cout << endl;
}
