int linear_diophantine(int a, int b, int c, int *x, int *y) {
    int g = gcd(a, b);
    if (c % g != 0) return 0;
    *x = (c / g) * (b / g);
    *y = (c / g) * (a / g);
    return 1;
}
