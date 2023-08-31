#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    double mean = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mean += A[i];
    }
    mean /= (double)N;

    ll num_minus=0, num_plus=0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < mean) num_plus += ((int)mean - A[i]);
        else if (A[i] > mean) num_minus += (A[i] - ((int)mean + 1));
    }
    ans = max(num_plus, num_minus);
    cout << ans << endl;
}
