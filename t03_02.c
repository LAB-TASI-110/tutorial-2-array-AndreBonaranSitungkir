#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Untuk menggunakan INT_MAX dan INT_MIN
#include <float.h>   // Untuk menggunakan FLT_MAX (bila butuh inisialisasi float terbesar)
#include <math.h>    // Untuk fungsi fminf jika perlu membandingkan float, tapi di sini cukup perbandingan biasa

int main() {
    // Variabel yang akan kita pakai:
    int n;           // Jumlah bilangan yang akan dimasukkan
    int bilangan;    // Untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan angka terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan angka terkecil yang mungkin

    // Variabel untuk menghitung rata-rata dua nilai pertama
    int input_pertama = 0;
    int input_kedua = 0;
    int hitung_input = 0; // Untuk melacak sudah berapa input yang diterima
    float rata_rata_dua_pertama = 0.0; // Untuk menyimpan rata-rata

    // 1. Meminta input untuk jumlah bilangan (n)
    printf("Masukkan jumlah bilangan (n): ");
    scanf("%d", &n);

    // 2. Memastikan n adalah angka positif
    if (n <= 0) {
        printf("Jumlah bilangan harus positif. Program dihentikan.\n");
        return 1; // Keluar dengan kode error
    }

    // 3. Melakukan perulangan sebanyak n kali untuk membaca setiap bilangan
    for (int i = 0; i < n; i++) {
        printf("Masukkan bilangan ke-%d (antara -100 dan 100): ", i + 1);
        scanf("%d", &bilangan);

        // 4. Validasi batasan bilangan (-100 sampai 100)
        if (bilangan < -100 || bilangan > 100) {
            printf("Bilangan di luar rentang -100 hingga 100. Mohon ulangi input untuk bilangan ini.\n");
            i--; // Mengulang iterasi saat ini
            continue; // Lanjut ke iterasi berikutnya (yang akan mengulang yang sama karena i--)
        }

        // 5. Menyimpan dua input pertama untuk perhitungan rata-rata
        if (hitung_input == 0) {
            input_pertama = bilangan;
        } else if (hitung_input == 1) {
            input_kedua = bilangan;
        }
        hitung_input++; // Increment counter setelah input berhasil divalidasi dan disimpan

        // 6. Memperbarui nilai minimum dan maksimum
        if (bilangan < min_val) {
            min_val = bilangan;
        }
        if (bilangan > max_val) {
            max_val = bilangan;
        }
    }

    // 7. Menghitung rata-rata terendah dari dua nilai pertama jika n cukup
    if (n >= 2) {
        // Karena yang diminta "rata-rata terendah dari dua nilai pertama yang dimasukkan berturut"
        // kita asumsikan yang dimaksud adalah rata-rata dari input_pertama dan input_kedua.
        // Konteks "terendah" di sini mungkin maksudnya kalau ada lebih dari satu pasang,
        // tapi karena instruksinya spesifik "dua nilai pertama", maka langsung hitung.
        rata_rata_dua_pertama = (float)(input_pertama + input_kedua) / 2.0;
    } else {
        // Jika input kurang dari 2, rata-rata tidak bisa dihitung.
        // Kita bisa set ke nilai default atau tampilkan pesan error.
        // Berdasarkan contoh output, kita asumsikan ini hanya akan terjadi jika n >= 2.
    }

    // 8. Menampilkan hasil keluaran sesuai spesifikasi
    // Sesuai contoh output: nilai minimum, nilai maksimum, lalu rata-rata
    printf("%d\n", min_val); // Output nilai minimum
    printf("%d\n", max_val); // Output nilai maksimum
    if (n >= 2) {
        printf("%.2f\n", rata_rata_dua_pertama); // Output rata-rata dengan 2 digit presisi
    } else {
        // Jika n kurang dari 2, tidak ada rata-rata dari dua nilai pertama.
        // Sesuai contoh yang selalu ada 3 baris output, kita bisa menampilkan
        // nilai default atau pesan, tapi karena contoh selalu n >= 2, kita abaikan.
        // Jika harus tampil, mungkin "0.00" atau "N/A"
    }
    
    return 0; // Mengindikasikan program berjalan sukses
}