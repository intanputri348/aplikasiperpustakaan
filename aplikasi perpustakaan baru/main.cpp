#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string kodeBuku;
    string judul;
    string penulis;
    string penerbit;
    string jumlah_stok_buku;
};

const int MAX_BUKU = 10;
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

bool cariBuku(string kode, int &posisi) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].kodeBuku == kode) {
            posisi = i;
            return true;
        }
    }
    return false;
}

void tambahBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "Perpustakaan penuh. Tidak bisa menambah buku baru." << endl;
        return;
    }

    Buku bukuBaru;
    cout << "Masukkan Kode Buku: "; cin >> bukuBaru.kodeBuku;
    int posisi;

    if (cariBuku(bukuBaru.kodeBuku, posisi)) {
        cout << "Kode buku sudah ada. Gagal menambahkan buku." << endl;
        return;
    }

    cin.ignore();
    cout << "Masukkan Judul Buku: "; getline(cin, bukuBaru.judul);
    cout << "Masukkan Penulis Buku: "; getline(cin, bukuBaru.penulis);
    cout << "Masukkan Penerbit Buku: "; getline(cin, bukuBaru.penerbit);
    cout << "Masukkan Jumlah Stok Buku: "; getline(cin, bukuBaru.jumlah_stok_buku);

    daftarBuku[jumlahBuku] = bukuBaru;
    jumlahBuku++;
    cout << "Buku '" << bukuBaru.judul << "' berhasil ditambahkan." << endl;
}

void ubahBuku() {
    string kode;
    cout << "Masukkan kode buku yang ingin diubah: "; cin >> kode;

    int posisi;
    if (!cariBuku(kode, posisi)) {
        cout << "Buku dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    string judulLama = daftarBuku[posisi].judul;
    cin.ignore();
    cout << "Masukkan Judul Buku Baru: "; getline(cin, daftarBuku[posisi].judul);
    cout << "Masukkan Penulis Buku Baru: "; getline(cin, daftarBuku[posisi].penulis);
    cout << "Masukkan Penerbit Buku Baru: "; getline(cin, daftarBuku[posisi].penerbit);
    cout << "Masukkan Jumlah Stok Buku Baru: "; getline(cin, daftarBuku[posisi].jumlah_stok_buku);

    cout << "Data buku '" << judulLama << "' berhasil diubah menjadi '" << daftarBuku[posisi].judul << "'." << endl; // Fixed: missing closing bracket
}

void hapusBuku() {
    string kode;
    cout << "Masukkan kode buku yang ingin dihapus: "; cin >> kode;

    int posisi;
    if (!cariBuku(kode, posisi)) {
        cout << "Buku dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    string hapusJudulBuku = daftarBuku[posisi].judul;

    for (int i = posisi; i < jumlahBuku - 1; i++) {
        daftarBuku[i] = daftarBuku[i + 1];
    }
    jumlahBuku--;

    cout << "Buku '" << hapusJudulBuku << "' berhasil dihapus." << endl;
}

void tampilkanBuku(int posisi = 0) {
    if (posisi == jumlahBuku) {
        return;
    }

    cout << "\nBuku " << posisi + 1 << ":" << endl;
    cout << "Kode Buku   : " << daftarBuku[posisi].kodeBuku << endl;
    cout << "Judul       : " << daftarBuku[posisi].judul << endl;
    cout << "Penulis     : " << daftarBuku[posisi].penulis << endl;
    cout << "Penerbit    : " << daftarBuku[posisi].penerbit << endl;
    cout << "Jumlah Stok : " << daftarBuku[posisi].jumlah_stok_buku << endl;

    tampilkanBuku(posisi + 1);
}

int main() {
    int pilihan;

    cout << "=============================================" << endl;
    cout << "|                                           |" << endl;
    cout << "|   SELAMAT DATANG DI PERPUSTAKAAN ONLINE   |" << endl;
    cout << "|                                           |" << endl;
    cout << "|       P U S T A K A   P E L A N G I       |" << endl;
    cout << "|                                           |" << endl;
    cout << "=============================================" << endl;

    do {
        cout << "\n=== Menu Perpustakaan ===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Ubah Buku" << endl;
        cout << "3. Hapus Buku" << endl;
        cout << "4. Tampilkan Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                ubahBuku();
                break;
            case 3:
                hapusBuku();
                break;
            case 4:
                if (jumlahBuku == 0) {
                    cout << "Tidak ada buku dalam perpustakaan." << endl;
                } else {
                    tampilkanBuku();
                }
                break;
            case 5:
                cout << "---------------------------------------------" << endl;
                cout << "|                                           |" << endl;
                cout << "|   Terima kasih telah mengunjungi sistem   |" << endl;
                cout << "|       perpustakaan Pustaka Pelangi.       |" << endl;
                cout << "|                                           |" << endl;
                cout << "|               See You Soon!               |" << endl;
                cout << "|                                           |" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            default:
                cout << " Opsi Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
