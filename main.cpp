/*
 * STOKARA - MANAJEMEN STOK BARANG - TERMINAL C++
 *
 * Proyek akhir Dasar Pemrograman.
 * Petunjuk kerja tim: README.md dan docs/TUGAS_ANGGOTA.md.
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
 * Kompilasi: g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara
 * Jalankan Linux/WSL: ./stokara
 * Jalankan Windows : .\stokara.exe
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

        // =========================================================
        // ROLE 5 - AZKA: LAPORAN DAN REKAP
        // Penanggung jawab : MUHAMMAD AZKA HILMY (2604130034)
        // Materi kuliah    : for, long long, perkalian, akumulasi, indeks vector
        // TUGAS            : Menghitung total stok, nilai persediaan, dan rekap masuk/keluar.
        // =========================================================
        else if (pilihan == 6) {
            cout << "\n=== LAPORAN DAN REKAP ===\n";
            long long jumlahStokAwal = 0;
            long long jumlahStok = 0;
            long long jumlahMasuk = 0;
            long long jumlahKeluar = 0;
            long long nilaiPersediaan = 0;

            if (kodeBarang.empty()) {
                cout << "Belum ada data barang.\n";
            }

            for (int i = 0; i < jumlahBarang; i++) {
                long long nilaiStok = hargaBarang[i] * stokBarang[i];
                cout << "----------------------------------------\n";
                cout << "Kode        : " << kodeBarang[i] << "\n";
                cout << "Nama        : " << namaBarang[i] << "\n";
                cout << "Harga       : Rp" << hargaBarang[i] << "\n";
                cout << "Stok awal   : " << stokAwal[i] << " unit\n";
                cout << "Total masuk : " << totalMasuk[i] << " unit\n";
                cout << "Total keluar: " << totalKeluar[i] << " unit\n";
                cout << "Stok akhir  : " << stokBarang[i] << " unit\n";
                cout << "Nilai stok  : Rp" << nilaiStok << "\n";

                jumlahStokAwal += stokAwal[i];
                jumlahStok += stokBarang[i];
                jumlahMasuk += totalMasuk[i];
                jumlahKeluar += totalKeluar[i];
                nilaiPersediaan += nilaiStok;
            }

            cout << "\n--- RINGKASAN SELURUH BARANG ---\n";
            cout << "Jumlah jenis barang    : " << kodeBarang.size() << "\n";
            cout << "Total stok awal        : " << jumlahStokAwal << " unit\n";
            cout << "Total stok tersedia    : " << jumlahStok << " unit\n";
            cout << "Total barang masuk     : " << jumlahMasuk << " unit\n";
            cout << "Total barang keluar    : " << jumlahKeluar << " unit\n";
            cout << "Total nilai persediaan : Rp" << nilaiPersediaan << "\n";
            cout << "Stok akhir = stok awal + masuk - keluar.\n";
            cout << "Stok awal tidak dihitung sebagai transaksi masuk.\n";
        }
    } while (pilihan != 0);

    return 0;
}
