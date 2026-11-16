/*
 * ROLE 1 - ZUKRUP: KERANGKA INTEGRASI
 * File ini menyediakan main(), variabel bersama, dan menu.
 * Ganti setiap penanda TEMPEL_ROLE dengan BLOK_FITUR dari file anggota.
 * main() dan data contoh file anggota tidak ikut ditempel.
 * File ini dapat dikompilasi sendiri untuk menguji menu dan keluar.
 */
/*
 * STOKARA - MANAJEMEN STOK BARANG - TERMINAL C++
 *
 * Pembagian bagian program sesuai role kelompok:
 * 1. Zukrup  : kerangka, menu, dan integrasi.
 * 2. Raykhan : tambah data barang.
 * 3. Maulana : daftar dan pencarian barang.
 * 4. Devi    : transaksi masuk/keluar.
 * 5. Azka    : laporan dan rekap.
 *
 * Konsep: variabel, string/char, operator, kondisi, perulangan,
 * serta vector (push_back, size, empty, dan akses indeks).
 * Semua logika berada di main(); tidak ada fungsi buatan sendiri.
 * Data berlaku selama satu sesi. Kapasitas: 5 jenis barang.
 *
 * Kompilasi: g++ -std=c++11 -Wall -Wextra -pedantic manajemen_stok.cpp -o manajemen_stok
 * Jalankan Linux/WSL: ./manajemen_stok
 * Jalankan Windows : .\manajemen_stok.exe
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // =============================================================
    // ROLE 1 - ZUKRUP: DATA BERSAMA, MENU, DAN INTEGRASI
    // Penanggung jawab : ZUKHRUF GUSTDIKA CAHYATULLAH / ZUKRUP (2604130037)
    // Materi kuliah    : main(), variabel, vector, kondisi, do-while
    // TUGAS            : Menyediakan data bersama, menu, validasi pilihan, dan integrasi seluruh blok.
    // =============================================================
    const int KAPASITAS = 5;
    const int BATAS_STOK = 1000000;
    const int BATAS_REKAP = 1000000000;
    const long long BATAS_HARGA = 1000000000;

    // Indeks yang sama menunjuk barang yang sama pada semua vector.
    // Contoh: kodeBarang[0], namaBarang[0], dan stokBarang[0] milik
    // barang pertama. Semua vector ditambah bersamaan saat menyimpan.
    vector<string> kodeBarang;
    vector<string> namaBarang;
    vector<long long> hargaBarang;
    vector<int> stokAwal;
    vector<int> stokBarang;
    vector<int> totalMasuk;
    vector<int> totalKeluar;

    int jumlahBarang = 0;
    int pilihan = 0;

    cout << "STOKARA - MANAJEMEN STOK BARANG\n";
    cout << "Data tersimpan selama program berjalan.\n";
    cout << "Kapasitas: " << KAPASITAS << " jenis barang.\n";

    do {
        cout << "\n========================================\n";
        cout << "              MENU UTAMA\n";
        cout << "========================================\n";
        cout << "1. Tambah Data Barang\n";
        cout << "2. Lihat Daftar Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Catat Barang Masuk\n";
        cout << "5. Catat Barang Keluar\n";
        cout << "6. Laporan dan Rekap\n";
        cout << "0. Keluar\n";

        {
            bool inputValid = false;
            do {
                cout << "Pilih menu (0-6): ";
                string teksAngka;
                if (!getline(cin, teksAngka)) {
                    cout << "\nInput berakhir. Program ditutup.\n";
                    return 0;
                }

                // Baca digit dengan char, operator hitung, dan perulangan.
                // Setelah tidak valid, perhitungan berhenti agar angka tidak meluap.
                bool semuaDigit = (teksAngka != "");
                long long nilai = 0;
                for (char karakter : teksAngka) {
                    if (karakter < '0' || karakter > '9') {
                        semuaDigit = false;
                    } else if (semuaDigit) {
                        nilai = nilai * 10 + (karakter - '0');
                        if (nilai > 6) {
                            semuaDigit = false;
                        }
                    }
                }

                if (semuaDigit && nilai >= 0) {
                    pilihan = nilai;
                    inputValid = true;
                } else {
                    cout << "Input tidak valid. Isi digit bulat dari "
                         << 0 << " sampai " << 6
                         << " tanpa spasi, tanda, atau desimal.\n";
                }
            } while (!inputValid);
        }

        if (pilihan == 0) {
            cout << "\nProgram selesai. Data sesi ini tidak disimpan ke berkas.\n";
        }

// TEMPEL_ROLE_2_DI_SINI

// TEMPEL_ROLE_3_DI_SINI

// TEMPEL_ROLE_4_DI_SINI

// TEMPEL_ROLE_5_DI_SINI

        else {
            cout << "Fitur ini belum diintegrasikan. Tempel blok role terkait.\n";
        }
    } while (pilihan != 0);

    return 0;
}
