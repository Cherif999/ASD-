double vector_distance(int a[], int b[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    return sqrt(sum);
}
