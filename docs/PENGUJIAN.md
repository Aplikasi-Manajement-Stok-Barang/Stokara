# Pengujian Stokara

Validasi dilakukan pada 16 November 2026 menggunakan g++ di Linux.

## Kompilasi Program Lengkap

```bash
g++ -std=c++11 -Wall -Wextra -Werror -pedantic main.cpp -o stokara
```

Hasil: berhasil tanpa peringatan. Pengujian runtime menggunakan input terminal terkontrol dan pemeriksaan keluaran serta perhitungan stok.

## Hasil Skenario

| No. | Skenario | Status |
|---|---|---|
| 1 | Data kosong: daftar, cari, kedua transaksi, laporan nol | Lulus |
| 2 | Contoh rencana: 40 unit dan Rp170000; nama mengandung spasi | Lulus |
| 3 | Kode ganda ditolak tanpa menimpa data | Lulus |
| 4 | Lima barang, penambahan keenam ditolak, transaksi indeks akhir | Lulus |
| 5 | Pencarian kode/nama, nama sama, kecocokan persis dan peka huruf | Lulus |
| 6 | Kode transaksi tidak dikenal tidak mengubah stok/rekap | Lulus |
| 7 | Stok keluar berlebih ditolak, rekap tetap | Lulus |
| 8 | Pengeluaran tepat menghabiskan stok, barang tetap terdaftar | Lulus |
| 9 | Stok awal nol, keluar ditolak lalu masuk berhasil | Lulus |
| 10 | Validasi kode/nama kosong dan harga/stok salah | Lulus |
| 11 | Jumlah transaksi salah diminta ulang sebelum memperbarui data | Lulus |
| 12 | Menu kosong, negatif, teks, desimal, gabungan, dan angka sangat panjang | Lulus |
| 13 | Pilihan cara pencarian tidak valid diminta ulang | Lulus |
| 14 | Batas stok dan harga; hitungan persediaan memakai long long | Lulus |
| 15 | Total lima barang bernilai Rp5000000000000000 tanpa overflow | Lulus |
| 16 | 2000 transaksi: batas rekap tercapai tanpa merusak stok | Lulus |
| 17 | Batas rekap keluar ditolak sebelum pengurangan stok | Lulus |
| 18 | 1000 transaksi acak cocok dengan model stok independen | Lulus |
| 19 | Akhir input pada menu/formulir/transaksi tidak menggantung | Lulus |
| 20 | Sesi baru dimulai dari data kosong | Lulus |

## Pengujian Per Role dan Integrasi

Kelima file dalam `roles` berhasil dikompilasi serta dicoba secara mandiri:

| Role | Uji Singkat | Hasil |
|---|---|---|
| Zukrup | Menu dan keluar; fitur belum digabungkan memberi pemberitahuan. | Lulus |
| Raykhan | Menambahkan kode, nama, harga, dan stok awal. | Lulus |
| Maulana | Daftar data contoh dan pencarian BRG001. | Lulus |
| Devi | Barang masuk 10 lalu keluar 5 pada stok awal 20 menjadi 25. | Lulus |
| Azka | Data contoh menghasilkan 40 unit dan Rp170.000. | Lulus |

Blok fitur diambil ulang dari file role 2-5, disisipkan pada kerangka role 1 mengikuti `INTEGRASI.md`, lalu dikompilasi. Hasil perakitan juga lulus seluruh 20 skenario. Dengan demikian, file utama dan bahan integrasi yang dibagikan sama-sama telah diperiksa.

## Uji Manual untuk Presentasi

1. Jalankan program baru dan buka laporan: semua total nol.
2. Tambah BRG001 / Buku Tulis / 5000 / 20.
3. Tambah BRG002 / Pulpen / 3000 / 15.
4. Catat 10 Buku Tulis masuk dan 5 keluar.
5. Periksa laporan: 2 jenis, 40 unit, nilai persediaan Rp170.000.
6. Coba keluarkan 26 Buku Tulis: ditolak, stok tetap 25.
7. Cari BRG001 dan nama lengkap Buku Tulis: barang ditemukan.
8. Keluar lalu jalankan kembali: data kembali kosong sesuai rancangan sesi.

Pemeriksaan baru dilakukan di Linux. Perintah Windows disediakan pada README; jalankan kembali uji singkat ketika menggunakan compiler Windows kelompok.
