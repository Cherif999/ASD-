double vector_magnitude(int a[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];
    return sqrt(sum);
}
