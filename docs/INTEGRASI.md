# Panduan Integrasi Lima Role

`main.cpp` adalah versi lengkap yang siap dijalankan. Folder `roles` menyediakan program uji setiap anggota, termasuk kerangka integrasi milik ketua. Integrasi dilakukan dengan memindahkan blok fitur ke satu `main()`.

## File dan Penanda

| Anggota | File Sumber | Blok yang Diambil | Tujuan pada Kerangka |
|---|---|---|---|
| Raykhan | `roles/role_2_raykhan_input.cpp` | Antara `MULAI_BLOK_FITUR_ROLE_2` dan `AKHIR_BLOK_FITUR_ROLE_2`. | `TEMPEL_ROLE_2_DI_SINI` |
| Maulana | `roles/role_3_maulana_pengelolaan.cpp` | Antara penanda role 3. | `TEMPEL_ROLE_3_DI_SINI` |
| Devi | `roles/role_4_devi_transaksi.cpp` | Antara penanda role 4. | `TEMPEL_ROLE_4_DI_SINI` |
| Azka | `roles/role_5_azka_laporan.cpp` | Antara penanda role 5. | `TEMPEL_ROLE_5_DI_SINI` |

## Menggabungkan dari Kerangka

1. Buat salinan `roles/role_1_zukrup_integrasi.cpp` sebagai file kerja integrasi.
2. Buka file Raykhan dan salin seluruh kode di antara dua penanda blok role 2, termasuk `else if` dan kurung penutup.
3. Ganti baris komentar `// TEMPEL_ROLE_2_DI_SINI` pada kerangka dengan kode yang disalin.
4. Lakukan langkah yang sama untuk role 3, 4, dan 5; pertahankan urutannya.
5. Simpan hasil gabungan sebagai `main.cpp`, kemudian kompilasi dan uji.

Contoh penanda sumber:

```cpp
// MULAI_BLOK_FITUR_ROLE_2
// Seluruh blok fitur di antara kedua penanda inilah yang diambil.
// AKHIR_BLOK_FITUR_ROLE_2
```

Header, menu uji, deklarasi data contoh, dan `main()` dari file role 2-5 tetap berada pada file uji. Hasil gabungan menggunakan deklarasi bersama dan `main()` dari kerangka ketua.

## Memperbarui Program Gabungan yang Sudah Ada

Pada `main.cpp`, setiap bagian ditandai komentar `ROLE 1` sampai `ROLE 5`, beserta nama, NIM, materi, dan tugas. Jika anggota memperbarui file uji, ketua memperbarui blok role yang bersangkutan pada program utama. Gunakan perbandingan perubahan Git agar blok lama diganti secara utuh.

## Data Uji per Role

| Role | Kondisi Awal |
|---|---|
| 1 | Kosong; fitur selain keluar memberi pesan belum diintegrasikan. |
| 2 | Kosong; tambah barang melalui menu 1. |
| 3 | Buku Tulis 20 unit dan Pulpen 15 unit. |
| 4 | Buku Tulis 20 unit dan Pulpen 15 unit; rekap masuk/keluar nol. |
| 5 | Buku Tulis: awal 20, masuk 10, keluar 5, akhir 25. Pulpen: awal/akhir 15. |

Harga Buku Tulis Rp5.000 dan Pulpen Rp3.000. Masing-masing file uji memiliki sesi sendiri; barang yang ditambahkan ketika menjalankan role 2 tidak otomatis masuk ke program uji role 3.

## Pemeriksaan Setelah Integrasi

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara
./stokara
```

Pastikan seluruh menu tersedia, data awal kosong, nama berspasi dapat dimasukkan, transaksi memperbarui rekap, dan contoh pada README menghasilkan 40 unit serta Rp170.000. Keluar dari aplikasi lalu menjalankannya kembali harus menghasilkan sesi kosong.
