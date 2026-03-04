#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int n, bilangan, prev_bilangan;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    float min_avg = FLT_MAX;
    float max_avg = -FLT_MAX; // Inisialisasi dengan nilai float terkecil
    int valid_count = 0;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &bilangan);

        if (bilangan < -100 || bilangan > 100) {
            i--;
            continue;
        }

        if (bilangan < min_val) min_val = bilangan;
        if (bilangan > max_val) max_val = bilangan;

        if (valid_count > 0) {
            float current_avg = (float)(prev_bilangan + bilangan) / 2.0;
            // Update rata-rata terendah
            if (current_avg < min_avg) min_avg = current_avg;
            // Update rata-rata tertinggi
            if (current_avg > max_avg) max_avg = current_avg;
        }

        prev_bilangan = bilangan;
        valid_count++;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    if (valid_count >= 2) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    }

    return 0;
}