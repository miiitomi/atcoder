#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

void g(pair<int, int> &p) {
    if (p.first == 0) p.second = 1;
    else if (p.second == 0) p.first = 1;
    else {
        int x = gcd(abs(p.first), abs(p.second));
        p.first /= x;
        bool b = (p.second > 0);
        p.second = abs(p.second) / x;
        if (!b) p.second *= -1;
    }
}

bool f(int i, int j, int k, vector<int> &X, vector<int> &Y) {
    if (X[i] > X[j]) swap(i, j);
    if (X[i] > X[k]) swap(i, k);
    pair<int, int> p1, p2;
    p1.first = X[j] - X[i];
    p1.second = Y[j] - Y[i];
    p2.first = X[k] - X[i];
    p2.second = Y[k] - Y[i];
    g(p1);
    g(p2);
    if (p1 == p2) return false;
    else return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    int counter = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k<N; k++) {
                if (f(i, j, k, X, Y)) counter++;
            }
        }
    }
    cout << counter << endl;
}
