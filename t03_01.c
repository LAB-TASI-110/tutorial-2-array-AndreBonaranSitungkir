#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk menggunakan INT_MAX dan INT_MIN

int main() {
    // Sebagai mahasiswa semester 2, kita pakai variabel yang mudah dimengerti:
    int n;          // Untuk menyimpan jumlah bilangan yang akan dimasukkan
    int bilangan;   // Untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan angka terbesar yang mungkin (dari <limits.h>)
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan angka terkecil yang mungkin (dari <limits.h>)

    // 1. Meminta input untuk jumlah bilangan (n)
    scanf("%d", &n); // Membaca nilai n dari keyboard

    // 2. Memastikan n adalah angka positif, kalau tidak, mungkin ada yang salah input
    if (n <= 0) {
        return 1; // Mengindikasikan program berakhir dengan error
    }

    // 3. Melakukan perulangan sebanyak n kali untuk membaca setiap bilangan
    for (int i = 0; i < n; i++) {
        scanf("%d", &bilangan);

        // 4. Validasi batasan bilangan (-100 sampai 100)
        if (bilangan < -100 || bilangan > 100) {
            i--; // Mengulang iterasi saat ini agar user input lagi untuk bilangan yang sama
            continue; // Lanjut ke iterasi berikutnya (tapi karena i-- akan mengulang yang sama)
        }

        // 5. Memperbarui nilai minimum dan maksimum
        if (bilangan < min_val) {
            min_val = bilangan; // Jika bilangan saat ini lebih kecil, update min_val
        }
        if (bilangan > max_val) {
            max_val = bilangan; // Jika bilangan saat ini lebih besar, update max_val
        }
    }

    // 6. Menampilkan hasil keluaran sesuai spesifikasi (minimum dan maksimum)
    // Sesuai contoh output: nilai minimum dulu, lalu nilai maksimum
    printf("%d\n", min_val); // Output nilai minimum
    printf("%d\n", max_val); // Output nilai maksimum

    return 0; // Mengindikasikan program berjalan sukses
}