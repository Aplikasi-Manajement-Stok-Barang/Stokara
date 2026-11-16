# Panduan Penggunaan Stokara

Program terminal C++ lengkap untuk mencatat barang, melakukan transaksi stok, dan membuat rekap persediaan. Seluruh fitur berada dalam satu file `main.cpp`.

## 1. Dasar Materi dan Ruang Lingkup

Implementasi memakai materi dari tiga PDF yang diberikan:

| Materi | Penerapan |
|---|---|
| Dasar C++ | `main()`, variabel, `int`, `long long`, `bool`, `char`, `string`, input/output, operator, dan kondisi. |
| Perulangan | `do-while` untuk menu dan pengulangan input; `for` untuk pencarian, daftar barang, validasi digit, dan laporan. |
| Vector | `vector`, `push_back()`, `size()`, `empty()`, dan akses elemen menggunakan indeks `[]`. Bentuk `for (char karakter : teksAngka)` mengikuti perulangan rentang seperti contoh pada materi vector. |

Materi vector yang diberikan belakangan menjadi dasar penggunaan vector dalam program ini. Rencana awal menggunakan variabel per slot; implementasi sekarang menyimpan setiap kolom pada vector agar pengolahan lima barang lebih mudah dibaca. Kapasitas tetap **lima jenis barang** sesuai rencana proyek.

Semua logika berada dalam `main()`. Cakupan fitur tetap tambah barang, daftar/pencarian, transaksi masuk/keluar, dan laporan. Program tidak memerlukan fungsi buatan sendiri, struct, class buatan sendiri, framework, database, atau pengelolaan berkas.

## 2. Cara Kompilasi dan Menjalankan

Perintah berikut digunakan dari folder tempat `main.cpp` disimpan, pada terminal yang sudah menyediakan compiler `g++`.

### Linux / Kali WSL / Ubuntu

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara
./stokara
```

### Windows PowerShell dengan g++

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara.exe
.\stokara.exe
```

Jika menggunakan IDE, buat proyek console C++, buka file tersebut, lalu gunakan compiler yang mendukung C++11 atau yang lebih baru. Kompilasi dan pengujian otomatis yang dilaporkan di panduan ini dilakukan menggunakan `g++` pada Linux.

## 3. Menu Program

```text
1. Tambah Data Barang
2. Lihat Daftar Barang
3. Cari Barang
4. Catat Barang Masuk
5. Catat Barang Keluar
6. Laporan dan Rekap
0. Keluar
```

Masukkan satu nilai lalu tekan Enter untuk setiap pertanyaan. Program kembali ke menu setelah fitur selesai; tidak ada langkah tambahan untuk menekan Enter sebagai jeda.

### Tambah Data Barang

Pilih menu `1`, kemudian isi kode, nama lengkap, harga satuan, dan stok awal. Contoh:

```text
Kode barang : BRG001
Nama barang : Buku Tulis
Harga satuan: 5000
Stok awal   : 20
```

Kode wajib diisi, tidak boleh mengandung spasi, dan harus berbeda dari kode yang sudah terdaftar. Nama boleh mengandung spasi. Penambahan kode ganda dibatalkan sebelum meminta nama dan harga, kemudian program kembali ke menu. Barang keenam juga ditolak sebelum meminta data tambahan.

### Lihat Daftar Barang

Pilih menu `2`. Program menampilkan kode, nama, harga, dan stok setiap barang. Stok nol ditandai dengan status `HABIS`. Barang yang stoknya habis tetap terdaftar dan dapat menerima barang masuk.

### Cari Barang

Pilih menu `3`, lalu pilih `1` untuk pencarian kode atau `2` untuk pencarian nama lengkap. Pencarian memakai kecocokan persis, termasuk huruf besar/kecil dan spasi pada nama. Contoh: `Buku Tulis` cocok dengan nama tersebut, sedangkan `Buku` tidak cocok. Jika beberapa kode memiliki nama sama, seluruh hasil dengan nama tersebut ditampilkan.

### Barang Masuk dan Keluar

Pilih menu `4` atau `5`, isi kode barang, kemudian isi jumlah unit. Program menampilkan stok sebelum dan sesudah transaksi yang berhasil. Kode yang tidak terdaftar menyebabkan transaksi dibatalkan sebelum program meminta jumlah.

Jumlah keluar tidak boleh melebihi stok. Transaksi yang ditolak tidak mengubah stok maupun rekap. Ketika jumlah keluar sama dengan stok tersedia, transaksi berhasil dan stok menjadi nol.

### Laporan dan Rekap

Pilih menu `6`. Program menampilkan rincian setiap barang, kemudian ringkasan seluruh barang: jumlah jenis, total stok awal, stok tersedia, jumlah masuk, jumlah keluar, dan nilai persediaan.

## 4. Contoh Demonstrasi

1. Tambahkan `BRG001`, nama `Buku Tulis`, harga `5000`, stok awal `20`.
2. Tambahkan `BRG002`, nama `Pulpen`, harga `3000`, stok awal `15`.
3. Pilih Barang Masuk untuk `BRG001`, sebanyak `10` unit.
4. Pilih Barang Keluar untuk `BRG001`, sebanyak `5` unit.
5. Pilih Laporan dan Rekap.

Hasil yang sudah diverifikasi:

| Barang | Awal | Masuk | Keluar | Akhir | Nilai Stok |
|---|---|---|---|---|---|
| Buku Tulis | 20 | 10 | 5 | 25 | Rp125.000 |
| Pulpen | 15 | 0 | 0 | 15 | Rp45.000 |

```text
Jumlah jenis barang    : 2
Total stok awal        : 35 unit
Total stok tersedia    : 40 unit
Total barang masuk     : 10 unit
Total barang keluar    : 5 unit
Total nilai persediaan : Rp170000
```

Nominal pada terminal ditampilkan sebagai angka rupiah bulat tanpa pemisah ribuan. Setelah demonstrasi, coba keluarkan `26` Buku Tulis: program menolak transaksi dan stok tetap `25`.

## 5. Penjelasan Penyimpanan Data

Data disimpan dalam tujuh vector yang sejajar:

| Vector | Isi |
|---|---|
| `kodeBarang` | Kode unik setiap barang. |
| `namaBarang` | Nama lengkap. |
| `hargaBarang` | Harga satuan, bertipe `long long`. |
| `stokAwal` | Stok ketika barang didaftarkan. |
| `stokBarang` | Stok setelah transaksi. |
| `totalMasuk` | Akumulasi transaksi masuk per barang. |
| `totalKeluar` | Akumulasi transaksi keluar per barang. |

Indeks yang sama selalu menunjuk barang yang sama. Misalnya, `kodeBarang[0]`, `namaBarang[0]`, dan `stokBarang[0]` adalah data barang pertama. Semua vector menerima `push_back()` setelah seluruh input barang valid; jumlah barang baru kemudian bertambah satu.

Saat mencari kode transaksi, `indeksBarang` dimulai dari `-1`. Perulangan menggantinya dengan indeks barang yang cocok. Program memeriksa bahwa nilainya sudah ditemukan sebelum mengakses vector, sehingga kode yang tidak terdaftar tidak dipakai sebagai indeks.

Rumus utama:

```text
Stok akhir = stok awal + total masuk - total keluar
Nilai stok = harga satuan x stok akhir
Total nilai persediaan = penjumlahan nilai stok seluruh barang
```

Stok awal tidak termasuk transaksi masuk. Nilai persediaan merupakan nilai barang yang masih tersedia, bukan omzet atau keuntungan.

## 6. Validasi Input

Input dibaca dengan `getline(cin, ...)`, termasuk isian angka. Karena itu, nama dengan spasi dapat dibaca utuh dan tidak ada masalah sisa Enter antara angka dan nama.

Untuk angka, program memeriksa karakter satu per satu menggunakan `for`. Karakter harus berada di antara `'0'` dan `'9'`. Nilainya dihitung dengan `nilai = nilai * 10 + (karakter - '0')`. Jika sudah tidak valid atau melewati batas, perhitungan dihentikan untuk sisa karakter. Cara ini menolak teks, angka desimal, nilai negatif, angka yang terlalu panjang, dan isian kosong menggunakan konsep kondisi, perulangan, serta operator dasar.

Masukkan angka tanpa `Rp`, tanda titik/koma, tanda tambah, atau spasi. Contoh: gunakan `5000`, bukan `Rp5.000`. Nilai yang salah akan diminta ulang pada pertanyaan yang sama. Blok validasi angka diulang pada beberapa bagian agar program tetap berada dalam satu `main()`.

Batas nilai:

| Data | Batas |
|---|---|
| Jumlah jenis barang | 5. |
| Harga satuan | Rp1 sampai Rp1.000.000.000. |
| Stok tersedia per barang | 0 sampai 1.000.000 unit. |
| Jumlah per transaksi | 1 sampai 1.000.000 unit, dengan pemeriksaan stok. |
| Akumulasi masuk/keluar per barang | Maksimal 1.000.000.000 unit untuk masing-masing rekap. |

Batas nilai menjaga penjumlahan stok dan rekap tetap aman untuk tipe datanya. Harga dan total persediaan memakai `long long` karena perkalian dapat melebihi kapasitas `int`.

## 7. Pemetaan Lima Role dalam Kode

Komentar `ROLE 1` sampai `ROLE 5` menandai pembagian tanggung jawab dan bagian untuk dipelajari serta dijelaskan saat presentasi.

| Anggota | Bagian | Penjelasan yang Perlu Dikuasai |
|---|---|---|
| Zukhruf Gustdika Cahyatullah / Zukrup | Menu, data bersama, dan integrasi | Perulangan menu; hubungan antarvector; alur pemanggilan fitur. |
| Mukhamad Raykhan Nur Zaky | Input barang | Validasi kode; pencegahan kode ganda; penyimpanan tujuh kolom bersamaan. |
| Maulana Yusuf Alajami | Daftar dan pencarian | Perulangan data; indeks; perbandingan kode/nama; hasil kosong atau beberapa kecocokan. |
| Devi Anggun Noviani | Transaksi | Pencarian indeks; pemeriksaan stok; pembaruan stok dan rekap setelah transaksi valid. |
| Muhammad Azka Hilmy | Laporan dan rekap | Akumulasi angka; perkalian harga dan stok; perbedaan stok awal dan transaksi masuk. |

## 8. Hasil Pengujian

Program berhasil dikompilasi dengan C++11, `-Wall -Wextra -Werror -pedantic` tanpa peringatan. Sebanyak **20 skenario otomatis lulus**, meliputi:

- Menu dan laporan ketika belum ada barang.
- Contoh dua barang dengan hasil 40 unit serta Rp170.000.
- Kode ganda dan batas lima barang.
- Pencarian kode, nama lengkap, dan beberapa nama yang sama.
- Kode transaksi tidak ditemukan, stok kurang, stok habis, serta stok awal nol.
- Input kosong, teks, negatif, desimal, pilihan salah, dan angka yang sangat panjang.
- Batas harga, stok, rekap masuk, serta rekap keluar.
- Nilai persediaan besar untuk memeriksa penggunaan `long long`.
- Sebanyak 1.000 transaksi acak yang hasilnya cocok dengan model perhitungan terpisah.
- Akhir input pada beberapa tahap tidak membuat program menggantung.
- Penggunaan berikutnya dimulai dari data kosong.


## 9. Batas Penggunaan

Data hanya berada di memori selama aplikasi berjalan. Memilih `0`, menutup terminal, atau berakhirnya input mengakhiri sesi; data tidak dapat dimuat kembali. Rekap juga hanya berlaku untuk sesi tersebut. Harga tetap sejak barang didaftarkan, dan kapasitas tetap lima jenis barang. Fitur ini sesuai ruang lingkup versi proyek yang dikerjakan.
