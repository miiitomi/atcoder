#include <bits/stdc++.h>
using namespace std;

int N;
vector<double> X, Y;
vector<int> V;
double current_score;

int rand_int(int a, int b) {
    return a + rand() % (b - a);
}

double rand_double() {
    return 1.0 * rand() / RAND_MAX;
}

double compute_distance(int i, int j) {
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}

double compute_score() {
    double ans = 0;
    for (int i = 0; i < N; i++) {
        int p = V[i];
        int q = V[i+1];
        ans += compute_distance(p, q);
    }
    return ans;
}

void one_step(int &t) {
    int i = rand_int(1, N);
    int j = rand_int(1, N);

    if (i == j) {
        return;
    } else if (i > j) {
        swap(i, j);
    }

    reverse(V.begin()+i, V.begin()+j);
    double new_score = compute_score();

    double T = 30.0 - 28.0 * t / 2e+5;
    double prob = exp(min(0.0, (current_score - new_score) / T));

    if (rand_double() < prob) {
        current_score = new_score;
        return;
    } else {
        reverse(V.begin()+i, V.begin()+j);
        return;
    }
}

int main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);
    V.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        V[i] = i;
    }
    V[N] = 0;
    current_score = compute_score();

    for (int t = 0; t < 2e+5; t++) {
        one_step(t);
    }

    for (int i : V) {
        cout << i + 1 << endl;
    }
}
