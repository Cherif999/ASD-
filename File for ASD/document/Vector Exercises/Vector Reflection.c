void vector_reflection(int a[], int n[], int res[], int size) {
    double proj[3];
    vector_projection(a, n, proj, size);
    for (int i = 0; i < size; i++)
        res[i] = 2 * proj[i] - a[i];
}
