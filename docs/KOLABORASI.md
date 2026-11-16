# Panduan Kolaborasi Git untuk Stokara

Repository: **Aplikasi-Manajement-Stok-Barang/Stokara**. Alur kerja menggunakan branch anggota dan pull request ke `main` dalam repository private yang sama.

## 1. Akses Anggota

Ketua memastikan akun GitHub setiap anggota memiliki akses **Write** ke repository, melalui akses organisasi/tim atau collaborator yang sesuai. Pengaturan akses dikerjakan oleh pemilik organisasi. Akun yang belum memiliki izin perlu meminta ketua memeriksanya sebelum clone atau push.

## 2. Clone Repository

```bash
git clone https://github.com/Aplikasi-Manajement-Stok-Barang/Stokara.git
cd Stokara
```

Gunakan autentikasi GitHub milik sendiri jika diminta. Semua pekerjaan dijalankan dari folder `Stokara`.

## 3. Buat Branch Sesuai Role

Mulai dari `main` terbaru:

```bash
git switch main
git pull --ff-only origin main
```

Pilih **satu** perintah sesuai anggota:

| Anggota | Perintah |
|---|---|
| Zukrup | `git switch -c fitur/integrasi-zukrup` |
| Raykhan | `git switch -c fitur/input-raykhan` |
| Maulana | `git switch -c fitur/pengelolaan-maulana` |
| Devi | `git switch -c fitur/transaksi-devi` |
| Azka | `git switch -c fitur/laporan-azka` |

Jika branch sudah dibuat sebelumnya, gunakan `git switch nama-branch`.

## 4. Kerjakan File Sendiri

Buka file pada folder `roles`, cari komentar nama anggota, `TUGAS`, dan `MULAI_BLOK_FITUR`. Nama variabel bersama mengikuti kerangka role 1. Usahakan perubahan tetap berada pada lingkup tugas agar mudah ditinjau.

Contoh uji bagian Raykhan:

```bash
g++ -std=c++11 roles/role_2_raykhan_input.cpp -o uji_raykhan
./uji_raykhan
```

Di Windows, gunakan `-o uji_raykhan.exe` lalu `.\uji_raykhan.exe`.

## 5. Commit dan Push

Contoh untuk Raykhan:

```bash
git status
git add roles/role_2_raykhan_input.cpp
git commit -m "feat: perbaiki validasi input barang Raykhan"
git push -u origin fitur/input-raykhan
```

Anggota lain mengganti nama file dan branch sesuai tugasnya. Tambahkan hanya berkas yang terkait dengan perubahan; hasil kompilasi diabaikan oleh `.gitignore`.

## 6. Buka Pull Request

Pada GitHub, buka tab **Pull requests**, buat pull request dari branch anggota ke `main`, lalu tuliskan:

- Role dan fitur yang dikerjakan.
- Perilaku yang berubah serta alasannya.
- Input uji dan hasilnya.

Ketua meninjau perubahan, meminta perbaikan jika diperlukan, dan menggabungkan pekerjaan yang telah diuji. Setelah blok role diperbarui, ketua juga memperbarui bagian terkait pada `main.cpp` mengikuti [Panduan Integrasi](INTEGRASI.md).

## 7. Ambil Hasil Gabungan

Setelah pull request digabungkan dan perubahan lokal sudah disimpan dalam commit:

```bash
git switch main
git pull --ff-only origin main
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o stokara
./stokara
```

## 8. Kendala yang Sering Ditemui

| Kendala | Pemeriksaan |
|---|---|
| Repository not found ketika clone | Pastikan URL benar, akun yang digunakan sudah diberi akses, dan autentikasi memakai akun tersebut. |
| Permission denied / HTTP 403 ketika push | Minta ketua memeriksa izin Write dan pembatasan branch; periksa juga akun autentikasi Git. |
| Gagal karena beberapa main() | Kompilasi satu file sumber. Integrasi mengambil blok fitur, bukan seluruh file uji anggota. |
| Perubahan anggota belum terlihat di program lengkap | Pastikan blok dari file role sudah dimasukkan ke `main.cpp` dan program dikompilasi ulang. |
| main lokal tertinggal | Simpan perubahan dalam commit lalu jalankan `git pull --ff-only origin main`; konflik yang memerlukan penggabungan diperiksa bersama ketua. |

Karena repository private, penggunaan fork bergantung pada kebijakan organisasi. Panduan utama kelompok ini menggunakan akses Write, branch pada repository yang sama, dan pull request.
