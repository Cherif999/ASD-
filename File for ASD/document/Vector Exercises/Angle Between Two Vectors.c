double angle_between_vectors(int a[], int b[], int n) {
    return acos(dot_product(a, b, n) / (vector_magnitude(a, n) * vector_magnitude(b, n)));
}
