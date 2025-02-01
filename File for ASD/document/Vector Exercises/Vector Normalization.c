void vector_normalization(int a[], double res[], int n) {
    double mag = vector_magnitude(a, n);
    for (int i = 0; i < n; i++)
        res[i] = a[i] / mag;
}
