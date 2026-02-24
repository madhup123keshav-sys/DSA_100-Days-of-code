#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0, count = 0;
    long long *sum = (long long *)malloc((n + 1) * sizeof(long long));
    long long *freq = (long long *)malloc((n + 1) * sizeof(long long));

    int size = 1;
    sum[0] = 0;
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (sum[j] == prefixSum) {
                count += freq[j];
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            sum[size] = prefixSum;
            freq[size] = 1;
            size++;
        }
    }

    printf("%lld", count);

    free(arr);
    free(sum);
    free(freq);
    return 0;
}
