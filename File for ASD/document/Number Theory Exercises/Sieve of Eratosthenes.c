
int mod_exponentiation(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b % 2) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return res;
}
