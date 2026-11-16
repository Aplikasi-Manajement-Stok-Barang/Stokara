/*
 * UJI MANDIRI ROLE 2
 * Data dimulai dari kosong; gunakan menu 1 untuk menambah barang.
 * Untuk integrasi: salin hanya isi di antara MULAI_BLOK_FITUR_ROLE_2
 * dan AKHIR_BLOK_FITUR_ROLE_2 ke penanda role pada file Zukrup.
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

        if (pilihan != 0 && pilihan != 1) {
            cout << "Menu tersebut tidak tersedia pada uji role ini.\n";
            continue;
        }

        if (pilihan == 0) {
            cout << "\nProgram selesai. Data sesi ini tidak disimpan ke berkas.\n";
        }

// MULAI_BLOK_FITUR_ROLE_2
        // =========================================================
        // ROLE 2 - RAYKHAN: INPUT DATA BARANG
        // Penanggung jawab : MUKHAMAD RAYKHAN NUR ZAKY (2604130080)
        // Materi kuliah    : getline, string, kondisi, for, vector.push_back()
        // TUGAS            : Memvalidasi kode/nama/harga/stok dan menambah seluruh kolom barang bersamaan.
        // =========================================================
        else if (pilihan == 1) {
            cout << "\n=== TAMBAH DATA BARANG ===\n";
            if (jumlahBarang >= KAPASITAS) {
                cout << "Kapasitas penuh. Maksimal " << KAPASITAS
                     << " jenis barang.\n";
                continue;
            }

            string kodeBaru;
            bool kodeValid = false;
            do {
                cout << "Kode barang (tanpa spasi): ";
                if (!getline(cin, kodeBaru)) {
                    cout << "\nInput berakhir. Barang belum disimpan.\n";
                    return 0;
                }
                kodeValid = (kodeBaru != "");
                for (char karakter : kodeBaru) {
                    if (karakter == ' ' || karakter == '\t' || karakter == '\r') {
                        kodeValid = false;
                    }
                }
                if (!kodeValid) {
                    cout << "Kode wajib diisi dan tidak boleh mengandung spasi.\n";
                }
            } while (!kodeValid);

            bool kodeSudahAda = false;
            for (int i = 0; i < jumlahBarang; i++) {
                if (kodeBarang[i] == kodeBaru) {
                    kodeSudahAda = true;
                    break;
                }
            }
            if (kodeSudahAda) {
                cout << "Kode sudah digunakan. Barang tidak ditambahkan.\n";
                continue;
            }

            string namaBaru;
            bool namaValid = false;
            do {
                cout << "Nama barang: ";
                if (!getline(cin, namaBaru)) {
                    cout << "\nInput berakhir. Barang belum disimpan.\n";
                    return 0;
                }
                namaValid = false;
                for (char karakter : namaBaru) {
                    if (karakter != ' ' && karakter != '\t' && karakter != '\r') {
                        namaValid = true;
                    }
                }
                if (!namaValid) {
                    cout << "Nama barang wajib diisi.\n";
                }
            } while (!namaValid);

            long long hargaBaru = 0;
            {
                bool inputValid = false;
                do {
                    cout << "Harga satuan (rupiah bulat, 1-1000000000): ";
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
                            if (nilai > BATAS_HARGA) {
                                semuaDigit = false;
                            }
                        }
                    }

                    if (semuaDigit && nilai >= 1) {
                        hargaBaru = nilai;
                        inputValid = true;
                    } else {
                        cout << "Input tidak valid. Isi digit bulat dari "
                             << 1 << " sampai " << BATAS_HARGA
                             << " tanpa spasi, tanda, atau desimal.\n";
                    }
                } while (!inputValid);
            }

            int stokBaru = 0;
            {
                bool inputValid = false;
                do {
                    cout << "Stok awal (0-1000000): ";
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
                            if (nilai > BATAS_STOK) {
                                semuaDigit = false;
                            }
                        }
                    }

                    if (semuaDigit && nilai >= 0) {
                        stokBaru = nilai;
                        inputValid = true;
                    } else {
                        cout << "Input tidak valid. Isi digit bulat dari "
                             << 0 << " sampai " << BATAS_STOK
                             << " tanpa spasi, tanda, atau desimal.\n";
                    }
                } while (!inputValid);
            }

            // Simpan hanya setelah semua kolom valid. Stok awal
            // bukan transaksi masuk, sehingga kedua rekap mulai dari nol.
            kodeBarang.push_back(kodeBaru);
            namaBarang.push_back(namaBaru);
            hargaBarang.push_back(hargaBaru);
            stokAwal.push_back(stokBaru);
            stokBarang.push_back(stokBaru);
            totalMasuk.push_back(0);
            totalKeluar.push_back(0);
            jumlahBarang++;

            cout << "Barang berhasil ditambahkan.\n";
            cout << "Kode        : " << kodeBaru << "\n";
            cout << "Nama        : " << namaBaru << "\n";
            cout << "Harga       : Rp" << hargaBaru << "\n";
            cout << "Stok awal   : " << stokBaru << " unit\n";
        }
// AKHIR_BLOK_FITUR_ROLE_2
    } while (pilihan != 0);

    return 0;
}
