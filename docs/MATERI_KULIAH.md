# Pemetaan Implementasi ke Materi Kuliah

Sumber acuan adalah tiga PDF yang diberikan: **Presentasi_dasar-c (1).pdf**, **Presentasi_perulangan-flowrunio.pdf**, dan **Presentasi_vector.pdf**. File materi kuliah tetap menjadi bahan belajar kelompok; repository berisi program serta penjelasan penerapannya.

| Konsep | Lokasi dalam Program | Penerapan |
|---|---|---|
| Struktur `main()` | Seluruh file C++ | Titik mulai program; setiap file uji dikompilasi sendiri. |
| Tipe data dasar | Deklarasi dan input | `string` untuk kode/nama; `char` untuk pemeriksaan digit; `bool` untuk status validasi; `int` untuk stok; `long long` untuk harga dan total. |
| Input/output | Semua fitur | `getline(cin, ...)` membaca satu baris, `cout` menampilkan pertanyaan dan hasil. |
| Operator | Transaksi dan laporan | Penambahan/pengurangan stok; perbandingan jumlah; harga dikalikan stok. |
| Kondisi | Menu dan pemeriksaan input | `if` / `else if` / `else` memilih proses dan menolak nilai yang tidak memenuhi aturan. |
| `do-while` | Menu dan input | Menu muncul minimal sekali; nilai salah diminta ulang. |
| `for` | Daftar, pencarian, laporan | Membaca elemen dari indeks awal sampai jumlah barang. |
| Perulangan rentang | Pemeriksaan karakter input | `for (char karakter : teksAngka)` menerapkan bentuk perulangan rentang yang dicontohkan pada slide pengurutan vector. |
| Vector | Penyimpanan tujuh kolom | `push_back()`, `size()`, `empty()`, dan `[]`; operasi dasar yang tercakup pada PDF vector. |

## Pemeriksaan Input Angka

Seluruh input dibaca sebagai satu baris. Program memeriksa karakter menggunakan kondisi dan perulangan. Digit berikutnya dimasukkan ke nilai dengan rumus:

```cpp
nilai = nilai * 10 + (karakter - '0');
```

Sebagai contoh, teks `123` diproses menjadi 1, kemudian 12, lalu 123. Karakter selain digit atau nilai yang melewati batas membuat input tidak valid. Setelah tidak valid, program menghentikan perhitungan untuk sisa digit, sehingga angka yang sangat panjang tidak terus dikalikan.

Ini merupakan penerapan operator dan perulangan pada persoalan input. Konversi menggunakan `stoi`, exception, serta parser eksternal tidak digunakan.

## Vector Sejajar

`kodeBarang[i]`, `namaBarang[i]`, `hargaBarang[i]`, dan kolom stok dengan indeks `i` menunjuk barang yang sama. Semua kolom ditambahkan bersamaan setelah data valid. Bagian input menaikkan `jumlahBarang` satu kali setelah penyimpanan.

Kapasitas lima barang tetap dipakai sesuai rencana proyek. Walaupun vector dapat tumbuh, aplikasi membatasi banyak barang agar demonstrasi serta cakupan pengujian tetap sederhana.

## Pemisahan Tugas

Laundream digunakan sebagai contoh kerapian dokumentasi dan penanda tanggung jawab. Stokara memakai satu `main()` pada hasil integrasi. Tiap anggota mendapat program uji terpisah dan mengirimkan blok fiturnya untuk digabungkan oleh ketua.

Fungsi buatan sendiri, struct, class buatan sendiri, database, serta penyimpanan berkas belum menjadi bagian rancangan ini. Materi tambahan dapat dievaluasi bersama kelompok jika nanti diberikan oleh dosen.
