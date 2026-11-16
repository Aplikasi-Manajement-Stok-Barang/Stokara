# Stokara: Aplikasi Manajemen Stok Barang & Rekapitulasi Persediaan (C++)

Program terminal berbasis C++ untuk pencatatan data barang, pencarian persediaan, transaksi barang masuk dan keluar, serta penyusunan laporan total stok dan nilai persediaan secara terpadu.

Proyek ini disusun untuk memenuhi tugas akhir mata kuliah **Dasar Pemrograman** tahun 2026.

---

## 👥 Tim Pengembang & Pembagian Tugas (Berbasis Function & Vector)

Program menggunakan fungsi utama `main()` dan struktur data dinamis `std::vector` sesuai materi dasar C++, perulangan, serta **Pertemuan 11 (Vector STL)**. Pada implementasi saat ini, setiap modul pekerjaan berupa blok fitur bertanda di dalam `main()`, dengan file uji terpisah untuk tiap anggota:

| No | Nama Lengkap | NIM | Tanggung Jawab & Modul Fungsi | Materi C++ yang Digunakan |
|---|---|---|---|---|
| 1 | **Zukhruf Gustdika Cahyatullah** | `2604130037` *(Ketua)* | Fungsi `int main()`: deklarasi vector bersama, tampilan menu utama, validasi `pilihan`, perulangan `do-while`, penggabungan blok kode anggota, dan manajemen Git. | *Struktur main(), Vector, Looping & If-Else* |
| 2 | **Mukhamad Raykhan Nur Zaky** | `2604130080` | Blok **Tambah Data Barang** (`pilihan == 1`): input `kodeBaru`, `namaBaru`, `hargaBaru`, dan `stokBaru` dengan `getline`; pemeriksaan kode ganda dan kapasitas; penyimpanan tujuh kolom barang melalui `push_back()`. | *I/O Stream, String, Validasi, Looping & Vector push_back()* |
| 3 | **Maulana Yusuf Alajami** | `2604130031` | Blok **Daftar Barang** (`pilihan == 2`) & **Cari Barang** (`pilihan == 3`): tampilkan kode, nama, harga, dan stok; cek `empty()`; cari kecocokan `kataCari` dengan `kodeBarang[i]` atau `namaBarang[i]` menggunakan `for`. | *Vector 1D, empty(), size(), For Loop & Perbandingan String* |
| 4 | **Devi Anggun Noviani** | `2604130117` | Blok **Barang Masuk/Keluar** (`pilihan == 4` / `5`): cari `indeksBarang`, validasi `jumlahTransaksi`, periksa kecukupan stok, perbarui `stokBarang` serta `totalMasuk` / `totalKeluar`, lalu tampilkan stok sebelum dan sesudah transaksi. | *If-Else, Aritmatika, Assignment += / -= & Indeks Vector* |
| 5 | **Muhammad Azka Hilmy** | `2604130034` | Blok **Laporan & Rekap** (`pilihan == 6`): hitung `nilaiStok = hargaBarang[i] * stokBarang[i]`; akumulasikan `jumlahStok`, `jumlahMasuk`, `jumlahKeluar`, dan `nilaiPersediaan`; tampilkan rincian per barang serta jumlah jenis dari `size()`. | *Long long, Vector Operations, For Loop & Akumulasi* |

---

## 💡 Fitur Utama Program

1. **Tambah Data Barang (Menu 1)**:
   - Input kode unik, nama lengkap, harga satuan, dan jumlah stok awal.
   - Nama barang mendukung spasi, misalnya `Buku Tulis`.
   - Pemeriksaan kode ganda, kolom kosong, harga positif, serta stok awal tidak negatif.
   - Data disimpan ke vector menggunakan `.push_back()` setelah seluruh input valid.
   - Kapasitas maksimal **5 jenis barang**, sesuai ruang lingkup proyek.
2. **Lihat Daftar Barang (Menu 2)**:
   - Menampilkan kode, nama, harga satuan, dan stok setiap barang.
   - Menampilkan status **HABIS** jika stok nol.
   - Menggunakan `.empty()`, `.size()`, dan perulangan `for`.
3. **Pencarian Barang (Menu 3)**:
   - Pencarian berdasarkan kode atau nama lengkap.
   - Pencocokan persis menggunakan perbandingan string pada vector.
   - Menampilkan seluruh hasil dengan nama yang sama atau pesan tidak ditemukan.
4. **Transaksi Barang Masuk (Menu 4)**:
   - Input kode barang dan jumlah unit yang datang.
   - Menambah stok serta akumulasi barang masuk pada indeks yang sesuai.
   - Menampilkan stok sebelum dan sesudah transaksi.
5. **Transaksi Barang Keluar (Menu 5)**:
   - Input kode barang dan jumlah unit yang keluar.
   - Memeriksa kecukupan stok sebelum mengurangi persediaan.
   - Menambah akumulasi barang keluar hanya ketika transaksi berhasil.
   - Transaksi yang ditolak menjaga stok dan rekap tetap seperti semula.
6. **Laporan & Rekapitulasi Persediaan (Menu 6)**:
   - Rincian stok awal, total masuk, total keluar, stok akhir, dan nilai stok per barang.
   - Ringkasan jumlah jenis barang, total unit tersedia, dan nilai persediaan.
   - Perhitungan `stok akhir = stok awal + masuk - keluar`.
   - Perhitungan `nilai stok = harga satuan × stok akhir`.
7. **Keluar (Menu 0)**:
   - Menutup program dengan pesan penutup.
   - Data hanya berlaku selama sesi program berjalan.

---

## 🛠️ Konsep Pemrograman C++ yang Digunakan (Sesuai Materi Kuliah)

- **Vector C++ (STL)**: `#include <vector>`, `push_back()`, `.size()`, `.empty()`, inisialisasi `{...}` pada data uji, dan akses indeks `[]`.
- **Struktur Program**: fungsi utama `int main()` sebagai tempat integrasi blok fitur anggota.
- **Input / Output Stream**: `#include <iostream>`, `cout`, dan `getline(cin, ...)`.
- **Tipe Data & Variabel**: `int`, `long long`, `string`, `char`, dan `bool`.
- **Operator Aritmatika & Logika**: `*`, `+`, `-`, `>`, `>=`, `==`, `&&`, dan `||`.
- **Operator Assignment**: `+=` dan `-=` untuk pembaruan stok serta akumulasi.
- **Percabangan**: `if-else` untuk pilihan menu, pemeriksaan input, kode ganda, dan kecukupan stok.
- **Perulangan**: `do-while` untuk menu dan input berulang; `for` untuk daftar, pencarian, rekap, dan pemeriksaan digit.

Acuan: **Presentasi_dasar-c (1).pdf**, **Presentasi_perulangan-flowrunio.pdf**, serta **Presentasi_vector.pdf**. Rincian penerapannya ada pada [Pemetaan Materi Kuliah](docs/MATERI_KULIAH.md).

---

## 🚀 Panduan Kompilasi & Menjalankan

### Kompilasi Program Utama

Gunakan compiler `g++` yang mendukung C++11 atau lebih baru. Dari folder repository:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -o stokara main.cpp
```

### Menjalankan Program

- **Windows PowerShell**:

  ```powershell
  g++ -std=c++11 -o stokara.exe main.cpp
  .\stokara.exe
  ```

- **Linux / WSL**:

  ```bash
  ./stokara
  ```

### Contoh Hasil Laporan

Daftarkan Buku Tulis (`BRG001`, harga `5000`, stok awal `20`) dan Pulpen (`BRG002`, harga `3000`, stok awal `15`). Setelah 10 Buku Tulis masuk dan 5 keluar, laporan menampilkan:

```text
Jumlah jenis barang    : 2
Total stok awal        : 35 unit
Total stok tersedia    : 40 unit
Total barang masuk     : 10 unit
Total barang keluar    : 5 unit
Total nilai persediaan : Rp170000
```

Versi lengkap telah lulus **20 skenario pengujian**, termasuk pengujian 1.000 transaksi acak. Rincian tersedia pada [Hasil Pengujian](docs/PENGUJIAN.md).

---

## 📖 PANDUAN KOLABORASI GIT (METODE BRANCH & PULL REQUEST)

Agar setiap anggota dapat mengerjakan bagiannya secara mandiri, kelompok menggunakan **BRANCH & PULL REQUEST** pada repository organisasi yang sama. Stokara berstatus **private**; ketua memberikan akses **Write** kepada anggota yang berkontribusi.

---

### 1. Akses Repositori Kelompok (WAJIB di Awal)

1. Buka repositori proyek: **[Aplikasi-Manajement-Stok-Barang/Stokara](https://github.com/Aplikasi-Manajement-Stok-Barang/Stokara)**.
2. Pastikan akun GitHub yang dipakai sudah diberi akses oleh Zukrup sebagai ketua.
3. Jika ada undangan akses repository atau organisasi, terima undangan tersebut menggunakan akun masing-masing.
4. Pastikan halaman repository dapat dibuka sebelum melakukan clone.

---

### 2. Download (Clone) dari Repositori Kelompok

Buka terminal/CMD di laptop, lalu jalankan:

```bash
git clone https://github.com/Aplikasi-Manajement-Stok-Barang/Stokara.git
cd Stokara
```

Jika diminta autentikasi, masuk menggunakan akun GitHub sendiri yang telah diberi akses.

---

### 3. Buat Branch Baru Sebelum Ngoding

Mulai dari `main` terbaru:

```bash
git switch main
git pull --ff-only origin main
```

Pilih **salah satu** perintah sesuai bagian tugasmu:

```bash
# Untuk Zukrup (Menu Utama & Integrasi):
git switch -c fitur/integrasi-zukrup

# Untuk Raykhan (Input Data Barang):
git switch -c fitur/input-raykhan

# Untuk Maulana (Daftar & Pencarian Barang):
git switch -c fitur/pengelolaan-maulana

# Untuk Devi (Transaksi Barang Masuk/Keluar):
git switch -c fitur/transaksi-devi

# Untuk Azka (Laporan & Rekap):
git switch -c fitur/laporan-azka
```

Jika branch sudah pernah dibuat, gunakan `git switch nama-branch` untuk kembali ke branch tersebut.

---

### 4. Cara Mengerjakan Kode di File Masing-Masing

1. Buka folder `Stokara` di **VS Code**.
2. Buka folder **`roles`**, kemudian pilih file sesuai nama anggota:

   | Anggota | File Kerja |
   |---|---|
   | Zukrup | [`role_1_zukrup_integrasi.cpp`](roles/role_1_zukrup_integrasi.cpp) |
   | Raykhan | [`role_2_raykhan_input.cpp`](roles/role_2_raykhan_input.cpp) |
   | Maulana | [`role_3_maulana_pengelolaan.cpp`](roles/role_3_maulana_pengelolaan.cpp) |
   | Devi | [`role_4_devi_transaksi.cpp`](roles/role_4_devi_transaksi.cpp) |
   | Azka | [`role_5_azka_laporan.cpp`](roles/role_5_azka_laporan.cpp) |

3. Cari nama kamu pada komentar **`Penanggung jawab`**, lalu baca bagian **`TUGAS`**.
4. Untuk role 2–5, kerjakan bagian di antara komentar **`MULAI_BLOK_FITUR_ROLE_...`** dan **`AKHIR_BLOK_FITUR_ROLE_...`**.
5. Pertahankan nama vector bersama agar kode anggota dapat diintegrasikan dengan benar.
6. Zukrup menyatukan blok fitur yang selesai ke **`main.cpp`** mengikuti [Panduan Integrasi](docs/INTEGRASI.md).

Setiap file role mempunyai `main()` untuk uji mandiri. Program gabungan menggunakan satu `main()`; bagian yang dipindahkan adalah blok fitur bertandanya.

---

### 5. Uji Coba Kodingan di Terminal

Contoh untuk menguji bagian Raykhan:

```bash
g++ -std=c++11 roles/role_2_raykhan_input.cpp -o uji_raykhan
./uji_raykhan
```

Di PowerShell Windows:

```powershell
g++ -std=c++11 roles/role_2_raykhan_input.cpp -o uji_raykhan.exe
.\uji_raykhan.exe
```

Ganti nama file sesuai role yang dikerjakan. Role 3–5 memiliki data contoh untuk pengujian. Setelah seluruh blok digabungkan, uji program lengkap melalui `main.cpp`.

---

### 6. Simpan & Push ke Branch Kamu

Setelah kode berhasil dikompilasi dan diuji, simpan perubahan ke Git. Contoh untuk Raykhan:

```bash
git status
git add roles/role_2_raykhan_input.cpp
git commit -m "feat: perbarui input data barang Raykhan"
git push -u origin fitur/input-raykhan
```

Anggota lain mengganti file dan branch sesuai bagiannya. Hasil kompilasi diabaikan oleh `.gitignore`.

---

### 7. Kirim Kodingan ke Repo Utama (Buka Pull Request)

1. Buka [repository Stokara](https://github.com/Aplikasi-Manajement-Stok-Barang/Stokara) di GitHub.
2. Buka tab **Pull requests**, lalu klik **New pull request**.
3. Pilih **base: `main`** dan **compare: branch tugasmu**.
4. Klik **Create pull request**, lalu tulis fitur yang dikerjakan, perubahan kode, dan hasil pengujian.
5. Zukrup meninjau perubahan dan melakukan **Merge pull request** setelah pemeriksaan selesai.
6. Zukrup memperbarui blok terkait pada `main.cpp`, menguji ulang program lengkap, dan menyimpan hasil integrasi.

Setelah pekerjaan digabungkan dan perubahan lokal sudah disimpan dalam commit:

```bash
git switch main
git pull --ff-only origin main
```

---

### 💡 KHUSUS UNTUK YANG SUDAH TERLANJUR NGODING

Jika sudah mengetik kode atau membuat commit di folder lokal tetapi gagal push:

1. Periksa alamat remote dan nama branch:

   ```bash
   git remote -v
   git branch --show-current
   ```

2. Jika remote menunjuk repository yang berbeda, sesuaikan:

   ```bash
   git remote set-url origin https://github.com/Aplikasi-Manajement-Stok-Barang/Stokara.git
   ```

3. Jika push masih mendapat error **403** atau **Repository not found**, minta Zukrup memeriksa izin **Write**, akun autentikasi, dan akses repository private.
4. Setelah akses benar, push branch yang berisi pekerjaanmu. Contoh:

   ```bash
   git push -u origin fitur/input-raykhan
   ```

5. Lanjutkan membuka pull request sesuai **Langkah 7**.

---

### 🆘 Solusi Darurat (Kalau Laptop Error Git)

1. Buka repository menggunakan akun yang sudah diberi akses.
2. Klik **Code > Download ZIP**, lalu ekstrak.
3. Kerjakan dan uji file role sendiri di VS Code.
4. Serahkan file role yang diperbarui beserta contoh hasil uji kepada Zukrup untuk dibantu integrasinya.

---

Pemetaan tugas lengkap: [Tugas Anggota](docs/TUGAS_ANGGOTA.md) · Panduan fitur: [Panduan Program](docs/PANDUAN_PROGRAM.md) · Acuan susunan README: [Laundream](https://github.com/hanmeini/Laundream).
