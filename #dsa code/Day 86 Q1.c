#include <stdio.h>

int integer_sqrt(int n) {
    if (n < 2) return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n)
            return mid;
        else if ((long long)mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", integer_sqrt(n));
    return 0;
}
