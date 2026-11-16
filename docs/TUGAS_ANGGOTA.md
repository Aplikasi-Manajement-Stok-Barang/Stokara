# Pembagian Tugas dan Kriteria Selesai

Setiap anggota menguasai kode pada bagiannya, menguji perubahan, dan menjelaskan hasilnya saat presentasi. File per role sudah berisi implementasi awal yang dapat dijalankan; gunakan sebagai bahan belajar dan pengembangan bersama.

## 1. Zukhruf Gustdika Cahyatullah / Zukrup — Ketua & Integrasi

**NIM:** 2604130037  
**File:** `roles/role_1_zukrup_integrasi.cpp` dan `main.cpp`  
**Branch:** `fitur/integrasi-zukrup`

Tanggung jawab:

1. Menyepakati alur menu, nama variabel, tipe data, dan batas nilai bersama anggota.
2. Menyediakan tujuh vector yang saling sejajar serta penghitung `jumlahBarang`.
3. Membuat menu `0` sampai `6`, memeriksa pilihan, dan mengulang menu menggunakan `do-while`.
4. Menyatukan blok fitur role 2-5 ke satu `main()` dengan urutan yang tepat.
5. Meninjau pull request anggota, menjalankan uji akhir, dan merapikan dokumentasi.

**Materi:** struktur program, variabel, input/output, kondisi, vector, dan perulangan.

**Selesai apabila:** menu berjalan, program bisa keluar, seluruh fitur mengakses data yang sama, dan contoh transaksi menghasilkan 40 unit serta Rp170.000.

## 2. Mukhamad Raykhan Nur Zaky — Input Data Barang

**NIM:** 2604130080  
**File:** `roles/role_2_raykhan_input.cpp`  
**Penanda integrasi:** `MULAI_BLOK_FITUR_ROLE_2` sampai `AKHIR_BLOK_FITUR_ROLE_2`  
**Branch:** `fitur/input-raykhan`

Tanggung jawab:

1. Meminta kode, nama, harga satuan, dan jumlah stok awal.
2. Memastikan kode terisi tanpa spasi serta belum dipakai; nama wajib terisi.
3. Memastikan harga positif, stok awal tidak negatif, dan kapasitas belum penuh.
4. Menyimpan seluruh kolom dengan `push_back()` setelah input lengkap dan valid.
5. Mengisi `stokAwal` dan `stokBarang` dengan jumlah awal; rekap masuk/keluar dimulai dari nol.

**Materi:** `getline`, string/char, tipe data, kondisi, perulangan, dan vector.

**Data yang ditulis:** ketujuh vector barang serta `jumlahBarang`.

**Selesai apabila:** nama berspasi terbaca utuh, kode ganda ditolak, barang keenam ditolak, dan ukuran seluruh vector bertambah bersamaan saat pendaftaran berhasil.

## 3. Maulana Yusuf Alajami — Pengelolaan Barang

**NIM:** 2604130031  
**File:** `roles/role_3_maulana_pengelolaan.cpp`  
**Penanda integrasi:** `MULAI_BLOK_FITUR_ROLE_3` sampai `AKHIR_BLOK_FITUR_ROLE_3`  
**Branch:** `fitur/pengelolaan-maulana`

Tanggung jawab:

1. Menampilkan kode, nama, harga, dan stok seluruh barang melalui perulangan.
2. Menampilkan pesan jika vector kosong dan status `HABIS` untuk stok nol.
3. Menyediakan pencarian berdasarkan kode atau nama lengkap.
4. Membandingkan teks secara persis dan menampilkan semua nama yang cocok.
5. Menampilkan pesan jika pencarian tidak menghasilkan kecocokan.

**Materi:** `for`, kondisi, perbandingan string, indeks vector, `empty()`, dan `size()`.

**Data yang dibaca:** kode, nama, harga, dan stok. Bagian ini menjaga data tetap seperti semula.

**Selesai apabila:** daftar lengkap tampil, kode/nama cocok ditemukan, nama yang sama dapat menghasilkan beberapa barang, dan data kosong ditangani.

## 4. Devi Anggun Noviani — Transaksi Barang

**NIM:** 2604130117  
**File:** `roles/role_4_devi_transaksi.cpp`  
**Penanda integrasi:** `MULAI_BLOK_FITUR_ROLE_4` sampai `AKHIR_BLOK_FITUR_ROLE_4`  
**Branch:** `fitur/transaksi-devi`

Tanggung jawab:

1. Mencari kode barang dan memastikan indeks ditemukan sebelum dipakai.
2. Meminta jumlah transaksi yang positif dan berada dalam batas nilai.
3. Barang masuk menambah `stokBarang` dan `totalMasuk` pada indeks yang sama.
4. Barang keluar mengurangi `stokBarang` dan menambah `totalKeluar` setelah stok dinyatakan cukup.
5. Transaksi yang ditolak harus menjaga stok maupun rekap tetap seperti sebelum transaksi.

**Materi:** pencarian dengan `for`, kondisi, indeks vector, serta operator `+`, `-`, `+=`, dan `-=`.

**Selesai apabila:** stok 20 lalu masuk 10 dan keluar 5 menghasilkan 25; pengeluaran 26 saat stok 25 ditolak; pengeluaran tepat sebanyak stok menghasilkan nol.

## 5. Muhammad Azka Hilmy — Laporan & Rekap

**NIM:** 2604130034  
**File:** `roles/role_5_azka_laporan.cpp`  
**Penanda integrasi:** `MULAI_BLOK_FITUR_ROLE_5` sampai `AKHIR_BLOK_FITUR_ROLE_5`  
**Branch:** `fitur/laporan-azka`

Tanggung jawab:

1. Menampilkan stok awal, total masuk, total keluar, stok akhir, serta nilai stok setiap barang.
2. Menghitung nilai stok dengan `hargaBarang[i] * stokBarang[i]`.
3. Mengakumulasi total stok awal/akhir, barang masuk/keluar, dan nilai persediaan.
4. Menampilkan jumlah jenis barang berdasarkan banyaknya data dalam vector.
5. Menjelaskan bahwa stok awal berbeda dari transaksi masuk dan nilai persediaan berbeda dari keuntungan.

**Materi:** `for`, kondisi, vector, perkalian, penjumlahan, dan `long long`.

**Selesai apabila:** contoh Buku Tulis/Pulpen menghasilkan 40 unit dan Rp170.000; laporan kosong memiliki semua total nol; nilai besar tetap dihitung dengan benar.

## Ketentuan Bersama

- Nama dan tipe vector mengikuti kerangka ketua. Indeks yang sama menunjuk barang yang sama.
- Kode role 3-5 mempunyai data contoh untuk uji mandiri. Pada integrasi, salin blok fitur bertanda; data contoh tetap berada di file uji.
- Pemilik fitur menangani validasi dan pengujian bagiannya.
- Panduan dan bukti pengujian dirapikan bersama di bawah koordinasi ketua.
- Setiap pull request menyebutkan bagian yang diubah, alasan perubahan, dan hasil uji.
