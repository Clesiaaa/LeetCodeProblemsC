int xorOperation(int n, int start) {
    int s = 0;
    for (int k = 0; k < n; k++) s ^= start + 2 * k;
    return s;
}