# Stokara — Aplikasi Manajemen Stok Barang (C++)

Program terminal untuk pencatatan barang, pencarian persediaan, transaksi barang masuk/keluar, serta rekap stok dan nilai persediaan. Proyek akhir **Dasar Pemrograman** ini menggunakan materi dasar C++, perulangan, dan vector yang telah diberikan dalam perkuliahan.

## Tim Pengembang & Pembagian Tugas

Program dibagi menjadi lima modul pekerjaan menggunakan vector untuk data barang. Pada versi saat ini, modul tersebut berupa **blok fitur di dalam fungsi `main()`**. Kolom “Modul Fungsi” di bawah menunjukkan lokasi dan operasi kode yang dikerjakan tiap anggota.

| No. | Nama Lengkap | NIM | Tanggung Jawab & Modul Fungsi | Materi C++ yang Digunakan |
|---|---|---|---|---|
| 1 | **Zukhruf Gustdika Cahyatullah (Zukrup)** | `2604130037` *(Ketua)* | **Menu Utama & Integrasi — fungsi `int main()`:** menyiapkan vector `kodeBarang`, `namaBarang`, `hargaBarang`, `stokAwal`, `stokBarang`, `totalMasuk`, dan `totalKeluar`; membuat menu 0–6, validasi `pilihan`, serta perulangan `do-while`; menyatukan blok anggota, meninjau pull request, dan menguji alur program. **File kerja:** [role 1](roles/role_1_zukrup_integrasi.cpp) dan [main.cpp](main.cpp). | *Struktur main(), variabel, vector, I/O, kondisi, do-while, dan manajemen Git.* |
| 2 | **Mukhamad Raykhan Nur Zaky** | `2604130080` | **Input Data Barang — blok `pilihan == 1` dalam `main()`:** input `kodeBaru`, `namaBaru`, `hargaBaru`, dan `stokBaru` menggunakan `getline`; cek kode ganda dengan `for`, batas kapasitas, harga positif, serta stok awal tidak negatif; simpan tujuh kolom menggunakan `push_back()`, isi rekap masuk/keluar dengan nol, lalu tambah `jumlahBarang`. **File kerja:** [role 2](roles/role_2_raykhan_input.cpp). | *String/char, getline(), bool, kondisi, perulangan validasi, pencarian sederhana, dan vector.push_back().* |
| 3 | **Maulana Yusuf Alajami** | `2604130031` | **Daftar Barang & Pencarian — blok `pilihan == 2` dan `pilihan == 3` dalam `main()`:** periksa `kodeBarang.empty()`; gunakan `for` untuk menampilkan kode, nama, harga, dan stok, termasuk status habis; baca `caraCari` dan `kataCari`, bandingkan dengan `kodeBarang[i]` atau `namaBarang[i]`, lalu tampilkan semua kecocokan dan `jumlahDitemukan` atau pesan tidak ditemukan. **File kerja:** [role 3](roles/role_3_maulana_pengelolaan.cpp). | *Vector 1D, empty(), size(), akses indeks [], for, perbandingan string, if-else, dan output.* |
| 4 | **Devi Anggun Noviani** | `2604130117` | **Barang Masuk & Barang Keluar — blok `pilihan == 4` dan `pilihan == 5` dalam `main()`:** cari `kodeTransaksi` untuk memperoleh `indeksBarang`; validasi `jumlahTransaksi` dan stok; barang masuk menjalankan `stokBarang[indeksBarang] += jumlahTransaksi` serta menambah `totalMasuk`; barang keluar mengurangi stok dan menambah `totalKeluar` setelah jumlah dinyatakan cukup; tampilkan stok sebelum/sesudah. **File kerja:** [role 4](roles/role_4_devi_transaksi.cpp). | *For, pencarian indeks vector, kondisi, aritmatika, operator += / -=, dan validasi stok.* |
| 5 | **Muhammad Azka Hilmy** | `2604130034` | **Laporan & Rekap Persediaan — blok `pilihan == 6` dalam `main()`:** gunakan `for` untuk menampilkan stok awal, total masuk, total keluar, dan stok akhir per barang; hitung `nilaiStok = hargaBarang[i] * stokBarang[i]`; akumulasikan `jumlahStokAwal`, `jumlahStok`, `jumlahMasuk`, `jumlahKeluar`, dan `nilaiPersediaan`; tampilkan jumlah jenis melalui `kodeBarang.size()` serta ringkasan keseluruhan. **File kerja:** [role 5](roles/role_5_azka_laporan.cpp). | *Long long, vector.size(), for, perkalian, operator penjumlahan/akumulasi, dan rekap output.* |

**Petunjuk rinci tiap anggota:** [Tugas Anggota](docs/TUGAS_ANGGOTA.md).  
**Cara menggabungkan pekerjaan:** [Panduan Integrasi](docs/INTEGRASI.md).

## Latar Belakang dan Tujuan

Toko kecil atau koperasi sekolah perlu mencatat barang yang datang dan keluar agar jumlah persediaan selalu diketahui. Pencatatan manual dapat menimbulkan selisih stok, pencarian data yang lambat, dan kesalahan perhitungan nilai persediaan.

Stokara menghubungkan data barang, transaksi, dan laporan dalam satu program. Pengeluaran yang melebihi stok ditolak, sementara transaksi yang berhasil langsung memperbarui persediaan dan rekap. Program ini membantu petugas memeriksa stok dan nilai barang yang masih tersedia.

## Fitur Utama

| Menu | Fitur | Input | Output |
|---|---|---|---|
| `1` | Tambah Data Barang | Kode unik, nama, harga satuan, stok awal. | Konfirmasi dan data barang yang berhasil ditambahkan. |
| `2` | Lihat Daftar Barang | Pilihan menu. | Kode, nama, harga, stok, serta status habis jika stok nol. |
| `3` | Cari Barang | Pilihan kode/nama dan teks pencarian lengkap. | Semua barang yang cocok atau pesan tidak ditemukan. |
| `4` | Barang Masuk | Kode dan jumlah unit. | Stok sebelum/sesudah serta pembaruan total masuk. |
| `5` | Barang Keluar | Kode dan jumlah unit. | Stok terbaru atau alasan penolakan jika stok tidak mencukupi. |
| `6` | Laporan & Rekap | Pilihan menu. | Stok awal/akhir, akumulasi masuk/keluar, nilai stok, dan ringkasan keseluruhan. |
| `0` | Keluar | Pilihan menu. | Pesan penutup. |

## Materi Kuliah yang Digunakan

| Sumber Materi | Penerapan |
|---|---|
| **Presentasi_dasar-c (1).pdf** | Struktur program, `main()`, variabel, `int`, `long long`, `bool`, `char`, `string`, input/output, dan operator. |
| **Presentasi_perulangan-flowrunio.pdf** | Kondisi pada latihan, perulangan menu, pemeriksaan nilai, traversal data, dan akumulasi. |
| **Presentasi_vector.pdf** | `#include <vector>`, deklarasi vector, `push_back()`, `size()`, `empty()`, `[]`, dan perulangan rentang seperti contoh materi vector. |

Seluruh logika program berada dalam satu `main()`. Pemisahan pekerjaan dilakukan melalui file uji per role dan blok fitur bertanda. Fungsi buatan sendiri serta parameter reference pada contoh Laundream tidak menjadi syarat implementasi karena materi fungsi belum dilampirkan untuk proyek ini.

Penjelasan input angka, vector sejajar, dan kaitannya dengan materi tersedia pada [Pemetaan Materi](docs/MATERI_KULIAH.md).

## Susunan Repository

| Lokasi | Kegunaan |
|---|---|
| [`main.cpp`](main.cpp) | Program lengkap hasil integrasi; jalankan ini untuk demonstrasi proyek. |
| [`roles/role_1_zukrup_integrasi.cpp`](roles/role_1_zukrup_integrasi.cpp) | Kerangka integrasi: menu, vector bersama, dan tempat menyisipkan fitur. |
| [`roles/role_2_raykhan_input.cpp`](roles/role_2_raykhan_input.cpp) | Uji mandiri bagian tambah barang. |
| [`roles/role_3_maulana_pengelolaan.cpp`](roles/role_3_maulana_pengelolaan.cpp) | Uji mandiri daftar dan pencarian dengan dua barang contoh. |
| [`roles/role_4_devi_transaksi.cpp`](roles/role_4_devi_transaksi.cpp) | Uji mandiri transaksi dengan dua barang contoh. |
| [`roles/role_5_azka_laporan.cpp`](roles/role_5_azka_laporan.cpp) | Uji mandiri laporan dengan hasil contoh 40 unit / Rp170.000. |
| [`docs/TUGAS_ANGGOTA.md`](docs/TUGAS_ANGGOTA.md) | Lingkup kerja, variabel, dan kriteria selesai tiap anggota. |
| [`docs/KOLABORASI.md`](docs/KOLABORASI.md) | Clone repo private, branch per anggota, commit, push, dan pull request. |
| [`docs/INTEGRASI.md`](docs/INTEGRASI.md) | Urutan penyatuan blok role ke satu program. |
| [`docs/PANDUAN_PROGRAM.md`](docs/PANDUAN_PROGRAM.md) | Penggunaan fitur dan penjelasan kode. |
| [`docs/PENGUJIAN.md`](docs/PENGUJIAN.md) | Skenario pengujian dan hasil yang diharapkan. |

## Kompilasi dan Menjalankan

Gunakan compiler yang mendukung **C++11 atau lebih baru**. Jalankan perintah dari folder repository yang telah di-clone.

**Linux / WSL:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara
./stokara
```

**Windows PowerShell dengan g++:**

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara.exe
.\stokara.exe
```

Untuk mencoba satu role, kompilasi file role tersebut sendiri. Contoh:

```bash
g++ -std=c++11 roles/role_2_raykhan_input.cpp -o uji_raykhan
./uji_raykhan
```

Setiap file role mempunyai `main()` untuk pengujian mandiri. Kompilasi **satu file sumber untuk satu program**. Tahap integrasi mengambil blok fitur yang ditandai dari file anggota.

## Contoh Demonstrasi

1. Tambahkan `BRG001`, `Buku Tulis`, harga `5000`, stok awal `20`.
2. Tambahkan `BRG002`, `Pulpen`, harga `3000`, stok awal `15`.
3. Catat `10` unit Buku Tulis masuk.
4. Catat `5` unit Buku Tulis keluar.
5. Pilih menu `6`.

```text
Jumlah jenis barang    : 2
Total stok awal        : 35 unit
Total stok tersedia    : 40 unit
Total barang masuk     : 10 unit
Total barang keluar    : 5 unit
Total nilai persediaan : Rp170000
```

Mencoba mengeluarkan 26 Buku Tulis setelah langkah tersebut menghasilkan penolakan; stok Buku Tulis tetap 25 unit.

## Alur Kolaborasi Kelompok

Repository ini **private**. Ketua memberikan akses repository kepada akun anggota yang akan berkontribusi. Setiap anggota mengerjakan branch sendiri, menguji kodenya, lalu membuka pull request ke `main`.

| Anggota | Branch yang Disarankan | File Utama yang Dikerjakan |
|---|---|---|
| Zukrup | `fitur/integrasi-zukrup` | Kerangka role 1 dan `main.cpp`. |
| Raykhan | `fitur/input-raykhan` | File role 2. |
| Maulana | `fitur/pengelolaan-maulana` | File role 3. |
| Devi | `fitur/transaksi-devi` | File role 4. |
| Azka | `fitur/laporan-azka` | File role 5. |

Perintah lengkap, alur review, dan penanganan akses tersedia pada [Panduan Kolaborasi Git](docs/KOLABORASI.md).

## Batasan dan Pengujian

- Kapasitas **5 jenis barang**, sesuai rencana proyek.
- Data berlaku selama satu sesi; penggunaan baru dimulai dari kosong.
- Pencarian memakai kecocokan persis, termasuk huruf besar/kecil.
- Harga tetap sejak pendaftaran; stok awal tidak termasuk transaksi masuk.
- Angka diinput sebagai digit bulat, misalnya `5000`, tanpa `Rp` atau pemisah ribuan.
- Versi lengkap telah lulus **20 skenario uji**, termasuk 1.000 transaksi acak yang dibandingkan dengan perhitungan terpisah. Kelima file role juga telah diuji secara mandiri.

## Referensi Penyusunan Repository

Kerapian README, pemetaan tugas ke bagian kode, dan petunjuk kolaborasi mengacu pada [Laundream](https://github.com/hanmeini/Laundream). Implementasi dan pembagian tanggung jawab Stokara mengikuti tema stok barang serta materi yang diberikan untuk kelompok ini.
