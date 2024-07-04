template<typename T> vector<vector<T>> matrix_prod(vector<vector<T>> &A, vector<vector<T>> &B) {
    int l = A.size();
    int m = B.size();
    int n = B[0].size();
    vector<vector<T>> V(l, vector<T>(n, 0));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                V[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return V;
}
template<typename T> vector<T> matrix_prod(vector<vector<T>> &A, vector<T> &B) {
    int l = A.size();
    int m = B.size();
    vector<T> V(l, 0);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] += A[i][k] * B[k];
        }
    }
    return V;
}
template<typename T> vector<vector<T>> matrix_pow(vector<vector<T>> &A, ll p) {
    if (p == 1) return A;
    int a_size = A.size();
    if (p == 0) {
        vector<vector<T>> V(a_size, vector<T>(a_size, 0));
        for (int i = 0; i < a_size; i++) V[i][i] = 1;
        return V;
    }
    vector<vector<T>> A_p_half = matrix_pow(A, p/2);
    vector<vector<T>> V = matrix_prod(A_p_half, A_p_half);
    if (p % 2 == 0) return V;
    return matrix_prod(V, A);
}