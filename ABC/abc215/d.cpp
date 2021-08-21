#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

struct Eratosthenes {
    vector<bool> isprime;

    vector<int> minfactor;

    Eratosthenes(int N) : isprime(N+1, true),
                          minfactor(N+1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for (int p = 2; p <= N; ++p) {
            if (!isprime[p]) continue;

            minfactor[p] = p;

            for (int q = p * 2; q <= N; q += p) {

                isprime[q] = false;

                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    vector<pair<int,int>> factorize(int n) {
        vector<pair<int,int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    Eratosthenes er(A[N-1]);
    unordered_set<int> S;
    for (int i = 0; i < N; i++) {
        auto pf = er.factorize(A[i]);
        for (auto p : pf) {
            S.insert(p.first);
        }
    }
    vector<int> v((int)S.size());
    int i = 0;
    for (int s : S) {
        v[i] = s;
        i++;
    }
    sort(v.begin(), v.end());

    vector<bool> ans(M+1, true);
    ans[0] = false;
    for (int x : v) {
        for (int i = x; i <= M; i += x) ans[i] = false;
    }

    int counter = 0;
    for (int i = 1; i <= M; i++) {
        counter += ans[i];
    }
    cout << counter << endl;
    for (int i = 1; i <= M; i++) {
        if (ans[i]) cout << i << endl;
    }
}
