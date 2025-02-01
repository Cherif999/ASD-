void vector_projection(int a[], int b[], double res[], int n) {
    double factor = dot_product(a, b, n) / dot_product(b, b, n);
    for (int i = 0; i < n; i++)
        res[i] = factor * b[i];
}
