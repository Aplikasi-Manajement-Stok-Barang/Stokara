/*
 * UJI MANDIRI ROLE 4
 * Dua barang contoh disediakan di main() untuk mencoba fitur role ini.
 * Untuk integrasi: salin hanya isi di antara MULAI_BLOK_FITUR_ROLE_4
 * dan AKHIR_BLOK_FITUR_ROLE_4 ke penanda role pada file Zukrup.
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
        cout << "4. Catat Barang Masuk\n";
        cout << "5. Catat Barang Keluar\n";
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

        if (pilihan != 0 && pilihan != 4 && pilihan != 5) {
            cout << "Menu tersebut tidak tersedia pada uji role ini.\n";
            continue;
        }

        if (pilihan == 0) {
            cout << "\nProgram selesai. Data sesi ini tidak disimpan ke berkas.\n";
        }

// MULAI_BLOK_FITUR_ROLE_4
        // =========================================================
        // ROLE 4 - DEVI: TRANSAKSI BARANG MASUK DAN KELUAR
        // Penanggung jawab : DEVI ANGGUN NOVIANI (2604130117)
        // Materi kuliah    : for, kondisi, operator += / -=, indeks vector
        // TUGAS            : Memvalidasi transaksi lalu memperbarui stok serta akumulasi masuk/keluar.
        // =========================================================
        else if (pilihan == 4 || pilihan == 5) {
            if (pilihan == 4) {
                cout << "\n=== BARANG MASUK ===\n";
            } else {
                cout << "\n=== BARANG KELUAR ===\n";
            }
            if (kodeBarang.empty()) {
                cout << "Belum ada data barang.\n";
                continue;
            }

            string kodeTransaksi;
            cout << "Kode barang: ";
            if (!getline(cin, kodeTransaksi)) {
                cout << "\nInput berakhir. Transaksi belum dicatat.\n";
                return 0;
            }

            int indeksBarang = -1;
            for (int i = 0; i < jumlahBarang; i++) {
                if (kodeBarang[i] == kodeTransaksi) {
                    indeksBarang = i;
                    break;
                }
            }
            if (indeksBarang == -1) {
                cout << "Barang tidak ditemukan. Transaksi ditolak.\n";
                continue;
            }

            cout << "Nama        : " << namaBarang[indeksBarang] << "\n";
            cout << "Stok saat ini: " << stokBarang[indeksBarang] << " unit\n";
            int jumlahTransaksi = 0;
            {
                bool inputValid = false;
                do {
                    cout << "Jumlah unit (1-1000000): ";
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

                    if (semuaDigit && nilai >= 1) {
                        jumlahTransaksi = nilai;
                        inputValid = true;
                    } else {
                        cout << "Input tidak valid. Isi digit bulat dari "
                             << 1 << " sampai " << BATAS_STOK
                             << " tanpa spasi, tanda, atau desimal.\n";
                    }
                } while (!inputValid);
            }

            int stokSebelum = stokBarang[indeksBarang];
            if (pilihan == 4) {
                if (jumlahTransaksi > BATAS_STOK - stokBarang[indeksBarang]) {
                    cout << "Transaksi ditolak. Stok maksimal " << BATAS_STOK
                         << " unit per barang.\n";
                    continue;
                }
                if (jumlahTransaksi > BATAS_REKAP - totalMasuk[indeksBarang]) {
                    cout << "Transaksi ditolak. Batas rekap masuk tercapai.\n";
                    continue;
                }
                stokBarang[indeksBarang] += jumlahTransaksi;
                totalMasuk[indeksBarang] += jumlahTransaksi;
                cout << "Transaksi barang masuk berhasil.\n";
            } else {
                if (jumlahTransaksi > stokBarang[indeksBarang]) {
                    cout << "Stok tidak mencukupi. Stok tersedia: "
                         << stokBarang[indeksBarang] << " unit.\n";
                    cout << "Transaksi ditolak; stok dan rekap tetap.\n";
                    continue;
                }
                if (jumlahTransaksi > BATAS_REKAP - totalKeluar[indeksBarang]) {
                    cout << "Transaksi ditolak. Batas rekap keluar tercapai.\n";
                    continue;
                }
                stokBarang[indeksBarang] -= jumlahTransaksi;
                totalKeluar[indeksBarang] += jumlahTransaksi;
                cout << "Transaksi barang keluar berhasil.\n";
            }

            cout << "Kode         : " << kodeBarang[indeksBarang] << "\n";
            cout << "Jumlah       : " << jumlahTransaksi << " unit\n";
            cout << "Stok sebelum : " << stokSebelum << " unit\n";
            cout << "Stok sesudah : " << stokBarang[indeksBarang] << " unit\n";
        }
// AKHIR_BLOK_FITUR_ROLE_4
    } while (pilihan != 0);

    return 0;
}
