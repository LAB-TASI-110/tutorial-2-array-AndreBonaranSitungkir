#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Untuk menggunakan INT_MAX dan INT_MIN
#include <float.h>   // Untuk menggunakan FLT_MIN (nilai float terkecil)

int main() {
    // Variabel yang akan kita pakai, kita inisialisasi biar aman:
    int n;           // Jumlah bilangan yang akan dimasukkan
    int bilangan;    // Untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan angka terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan angka terkecil yang mungkin

    // Variabel untuk menghitung rata-rata dua nilai pertama dan rata-rata tertinggi berturut
    int input_pertama = 0;
    int input_kedua = 0;
    int hitung_input_data = 0; // Untuk melacak sudah berapa input data (selain n) yang diterima
    int previous_bilangan = 0; // Untuk menyimpan bilangan sebelumnya saat iterasi
    float max_rata_rata_berturut = -FLT_MAX; // Inisialisasi dengan nilai float negatif terkecil

    // 1. Meminta input untuk jumlah bilangan (n)
    scanf("%d", &n);

    // 2. Memastikan n adalah angka positif
    if (n <= 0) {
        return 1; // Keluar dengan kode error
    }

    // 3. Melakukan perulangan sebanyak n kali untuk membaca setiap bilangan
    for (int i = 0; i < n; i++) {
        scanf("%d", &bilangan);

        // 4. Validasi batasan bilangan (-100 sampai 100)
        if (bilangan < -100 || bilangan > 100) {
            i--; // Mengulang iterasi saat ini agar user input lagi untuk bilangan yang sama
            continue; // Lanjut ke iterasi berikutnya (yang akan mengulang yang sama karena i--)
        }

        // 5. Menyimpan dua input pertama untuk perhitungan rata-rata terendah
        if (hitung_input_data == 0) {
            input_pertama = bilangan;
        } else if (hitung_input_data == 1) {
            input_kedua = bilangan;
        }
        
        // 6. Menghitung rata-rata tertinggi dari dua nilai berturut-turut
        // Kita mulai menghitungnya setelah ada minimal 2 bilangan terinput
        if (i > 0) { // Jika ini bukan bilangan pertama (sudah ada previous_bilangan)
            float current_avg = (float)(previous_bilangan + bilangan) / 2.0;
            if (current_avg > max_rata_rata_berturut) {
                max_rata_rata_berturut = current_avg;
            }
        }
        
        // 7. Memperbarui nilai minimum dan maksimum
        if (bilangan < min_val) {
            min_val = bilangan;
        }
        if (bilangan > max_val) {
            max_val = bilangan;
        }

        // Simpan bilangan saat ini sebagai 'previous_bilangan' untuk iterasi berikutnya
        previous_bilangan = bilangan;
        hitung_input_data++; // Increment counter setelah input berhasil divalidasi dan disimpan
    }

    // 8. Menampilkan hasil keluaran sesuai spesifikasi
    // Sesuai contoh output: nilai minimum, nilai maksimum, rata-rata terendah dua pertama, lalu rata-rata tertinggi berturut

    printf("%d\n", min_val); // Output nilai minimum
    printf("%d\n", max_val); // Output nilai maksimum
    
    // Menghitung dan menampilkan rata-rata terendah dari dua nilai pertama jika n cukup
    if (n >= 2) {
        float rata_rata_dua_pertama = (float)(input_pertama + input_kedua) / 2.0;
        printf("%.2f\n", rata_rata_dua_pertama); // Output rata-rata dengan 2 digit presisi
    } else {
        // Jika n kurang dari 2, rata-rata tidak dapat dihitung.
        // Berdasarkan contoh output yang selalu ada 4 baris, kita tampilkan default.
        printf("0.00\n"); 
    }

    // Menampilkan rata-rata tertinggi dari dua nilai berturut jika n cukup
    if (n >= 2) {
        printf("%.2f\n", max_rata_rata_berturut); // Output rata-rata tertinggi berturut dengan 2 digit presisi
    } else {
        // Jika n kurang dari 2, tidak ada rata-rata berturut. Tampilkan default.
        printf("0.00\n");
    }
    
    return 0; // Mengindikasikan program berjalan sukses
}