/*
 * UJI MANDIRI ROLE 3
 * Dua barang contoh disediakan di main() untuk mencoba fitur role ini.
 * Untuk integrasi: salin hanya isi di antara MULAI_BLOK_FITUR_ROLE_3
 * dan AKHIR_BLOK_FITUR_ROLE_3 ke penanda role pada file Zukrup.
 * Header, main(), menu uji, dan data contoh tidak ikut disalin.
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
    vector<string> kodeBarang = {"BRG001", "BRG002"};
    vector<string> namaBarang = {"Buku Tulis", "Pulpen"};
    vector<long long> hargaBarang = {5000, 3000};
    vector<int> stokAwal = {20, 15};
    vector<int> stokBarang = {20, 15};
    vector<int> totalMasuk = {0, 0};
    vector<int> totalKeluar = {0, 0};

    int jumlahBarang = 2;
    int pilihan = 0;

    cout << "STOKARA - MANAJEMEN STOK BARANG\n";
    cout << "Data tersimpan selama program berjalan.\n";
    cout << "Kapasitas: " << KAPASITAS << " jenis barang.\n";

    do {
        cout << "\n========================================\n";
        cout << "              MENU UTAMA\n";
        cout << "========================================\n";
        cout << "2. Lihat Daftar Barang\n";
        cout << "3. Cari Barang\n";
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

        if (pilihan != 0 && pilihan != 2 && pilihan != 3) {
            cout << "Menu tersebut tidak tersedia pada uji role ini.\n";
            continue;
        }

        if (pilihan == 0) {
            cout << "\nProgram selesai. Data sesi ini tidak disimpan ke berkas.\n";
        }

// MULAI_BLOK_FITUR_ROLE_3
        // =========================================================
        // ROLE 3 - MAULANA: DAFTAR DAN PENCARIAN BARANG
        // Penanggung jawab : MAULANA YUSUF ALAJAMI (2604130031)
        // Materi kuliah    : for, perbandingan string, indeks vector, empty(), size()
        // TUGAS            : Menampilkan daftar dan mencari kecocokan kode atau nama lengkap.
        // =========================================================
        else if (pilihan == 2) {
            cout << "\n=== DAFTAR BARANG ===\n";
            if (kodeBarang.empty()) {
                cout << "Belum ada data barang.\n";
            } else {
                for (int i = 0; i < jumlahBarang; i++) {
                    cout << "----------------------------------------\n";
                    cout << "No.         : " << i + 1 << "\n";
                    cout << "Kode        : " << kodeBarang[i] << "\n";
                    cout << "Nama        : " << namaBarang[i] << "\n";
                    cout << "Harga       : Rp" << hargaBarang[i] << "\n";
                    cout << "Stok        : " << stokBarang[i] << " unit\n";
                    if (stokBarang[i] == 0) {
                        cout << "Status      : HABIS\n";
                    }
                }
                cout << "Jumlah jenis barang: " << kodeBarang.size() << "\n";
            }
        } else if (pilihan == 3) {
            cout << "\n=== CARI BARANG ===\n";
            if (kodeBarang.empty()) {
                cout << "Belum ada data barang.\n";
                continue;
            }
            cout << "1. Berdasarkan kode\n2. Berdasarkan nama lengkap\n";
            int caraCari = 0;
            {
                bool inputValid = false;
                do {
                    cout << "Pilih cara pencarian (1-2): ";
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
                            if (nilai > 2) {
                                semuaDigit = false;
                            }
                        }
                    }

                    if (semuaDigit && nilai >= 1) {
                        caraCari = nilai;
                        inputValid = true;
                    } else {
                        cout << "Input tidak valid. Isi digit bulat dari "
                             << 1 << " sampai " << 2
                             << " tanpa spasi, tanda, atau desimal.\n";
                    }
                } while (!inputValid);
            }

            string kataCari;
            cout << "Masukkan kode atau nama lengkap (huruf harus sama): ";
            if (!getline(cin, kataCari)) {
                cout << "\nInput berakhir. Program ditutup.\n";
                return 0;
            }

            int jumlahDitemukan = 0;
            for (int i = 0; i < jumlahBarang; i++) {
                if ((caraCari == 1 && kodeBarang[i] == kataCari) ||
                    (caraCari == 2 && namaBarang[i] == kataCari)) {
                    cout << "----------------------------------------\n";
                    cout << "Kode        : " << kodeBarang[i] << "\n";
                    cout << "Nama        : " << namaBarang[i] << "\n";
                    cout << "Harga       : Rp" << hargaBarang[i] << "\n";
                    cout << "Stok        : " << stokBarang[i] << " unit\n";
                    jumlahDitemukan++;
                }
            }
            if (jumlahDitemukan == 0) {
                cout << "Barang tidak ditemukan.\n";
            } else {
                cout << "Hasil ditemukan: " << jumlahDitemukan << " barang.\n";
            }
        }
// AKHIR_BLOK_FITUR_ROLE_3
    } while (pilihan != 0);

    return 0;
}
