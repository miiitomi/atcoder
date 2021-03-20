#include <bits/stdc++.h>
using namespace std;

int64_t f(int64_t &N, vector<int64_t> &a, vector<int64_t> &t, int64_t x) {
    int64_t ans = x;
    for (int i = 0; i < N; i++) {
        if (t[i] == 1) {
            ans = ans + a[i];
        } else if (t[i] == 2) {
            ans = max(ans, a[i]);
        } else {
            ans = min(ans, a[i]);
        }
    }
    return ans;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> a(N), t(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> t[i];
    int64_t Q;
    cin >> Q;
    vector<int64_t> x(Q);
    for (int i = 0; i < Q; i++) cin >> x[i];

    int64_t min_value = f(N, a, t, -1LL * pow(10, 9));
    int64_t max_value = f(N, a, t, pow(10, 9));

    int64_t begin = -1LL * pow(10, 9);
    int64_t end = pow(10, 9) + 1;
    int64_t half;
    int64_t min_x;
    int64_t max_x;

    while (end - begin > 1) {
        half = (end + begin)/2;
        if (f(N, a, t, half) == min_value) {
            begin = half;
        } else {
            end = half;
        }
    }
    min_x = begin;

    begin = (-1LL * pow(10, 9)) -1;  
    end = pow(10, 9); 
    while (end - begin > 1) {
        half = (end + begin)/2;
        if (f(N, a, t, half) == max_value) {
            end = half;
        } else {
            begin = half;
        }
    }
    max_x = end;

    for (int i = 0; i < Q; i++) {
        if (x[i] <= min_x) {
            cout << min_value << endl;
        } else if (x[i] >= max_x) {
            cout << max_value << endl;
        } else {
            cout << min_value + x[i] - min_x << endl;
        }
    }
}