#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_LOGIN_ATTEMPTS 3
#define MAX_USER 10
#define MAX_PRODUK 100

// Struct untuk menyimpan warna
struct Warna {
    string standar[3];
    string premium[3];
};

// Struct untuk menyimpan produk
struct Produk {
    string nama;
    int stok;
    int harga;
    Warna warna; //Nested struct
};

// Struct untuk menyimpan user
struct User {
    string nama;
    string nim;
};

User users[MAX_USER]; //Array of struct untuk menyimpan user
Produk produk[MAX_PRODUK]; //Array of struct untuk menyimpan produk
int jumlahUser = 0, jumlahProduk = 0;

int main() {
    int pilihan;
    bool running = true;
    string inputNama, inputNIM;
    int loginAttempts;
    int userIndex = -1;

    while (running) {
        cout << "=======================================" << endl;
        cout << "|         MANAJEMEN TOKO HIJAB        |" << endl;
        cout << "=======================================" << endl;
        cout << "|            1. Registrasi            |" << endl;
        cout << "|            2. Login                 |" << endl;
        cout << "|            3. Keluar                |" << endl;
        cout << "=======================================" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            //Registrasi user baru
            if (jumlahUser < MAX_USER) {
                cout << "Masukkan Nama : ";
                getline(cin, users[jumlahUser].nama);
                cout << "Masukkan NIM : ";
                getline(cin, users[jumlahUser].nim);
                jumlahUser++;
                cout << "Registrasi berhasil!\n";

            }else {
                cout << "Jumlah user sudah penuh!\n";
            }
        } else if (pilihan == 2) {
            loginAttempts = 0;
            userIndex = -1;
            while (loginAttempts < MAX_LOGIN_ATTEMPTS) {
                cout << "Masukkan Nama : ";
                getline(cin, inputNama);
                cout << "Masukkan NIM : ";
                getline(cin, inputNIM);
                for (int i = 0; i < jumlahUser; i++) {
                    if(users[i].nama == inputNama && users[i].nim == inputNIM) {
                        userIndex = i;
                        break;
                    }
                }
                if (userIndex != -1) {
                    cout << "Login berhasil1\n";
                    break;
                } else {
                    cout << "Login gagal. Coba Lagi,\n";
                    loginAttempts++;
                }
            }
            if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
                cout << "Login gagal 3 kali. Program berhenti.\n";
                return 0;
            }
        } else if (pilihan == 3) {
            cout << "Program berhenti.\n";
            running = false;
        }
        while (userIndex != -1) {
            cout << "=======================================" << endl;
            cout << "|         MANAJEMEN TOKO HIJAB        |" << endl;
            cout << "=======================================" << endl;
            cout << "|          1. Tambah Produk           |" << endl;
            cout << "|          2. Tampilkan Produk        |" << endl;
            cout << "|          3. Ubah Produk             |" << endl;
            cout << "|          4. Hapus Produk            |" << endl;
            cout << "|          5. Keluar                  |" << endl;
            cout << "=======================================" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihan;
            cin.ignore();

            if (pilihan == 1) {
                if (jumlahProduk < MAX_PRODUK) {
                    cout << "Masukkan nama produk : ";
                    getline(cin, produk[jumlahProduk].nama);
                    cout << "Masukkan stok : ";
                    cin >> produk[jumlahProduk].stok;
                    cout << "Masukkan harga : ";
                    cin >> produk[jumlahProduk].harga;
                    cin.ignore();
                    for (int k = 0; k < 3; k++) {
                        cout << "Warna standar ke-" << k+1 << ": ";
                        getline(cin, produk[jumlahProduk].warna.standar[k]);
                        cout << "Warna premium ke-" << k+1 << ": ";
                        getline(cin, produk[jumlahProduk].warna.premium[k]);
                    }
                    jumlahProduk++;
                    cout << "Produk berhasil ditambahkan.\n";
                } else {
                    cout << "Data penuh!\n";
                }
            } else if (pilihan == 2) {
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                } else {
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << produk[i].nama << " |"
                             << setw(6) << produk[i].stok << " |"
                             << setw(7) << produk[i].harga << " |"
                             << setw(20) << produk[i].warna.standar[0] +", " + produk[i].warna.standar[1] + ", " + produk[i].warna.standar[2] << " |" 
                             << setw(25) << produk[i].warna.premium[0] +", " + produk[i].warna.premium[1] + ", " + produk[i].warna.premium[2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                }
            } else if (pilihan == 3) {
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                } else {
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << produk[i].nama << " |"
                             << setw(6) << produk[i].stok << " |"
                             << setw(7) << produk[i].harga << " |"
                             << setw(20) << produk[i].warna.standar[0] +", " + produk[i].warna.standar[1] + ", " + produk[i].warna.standar[2] << " |" 
                             << setw(25) << produk[i].warna.premium[0] +", " + produk[i].warna.premium[1] + ", " + produk[i].warna.premium[2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                    int nomorProduk;
                    while (true) {
                        cout << "Masukkan nomor produk yang ingin diubah : ";
                        cin >> nomorProduk;
                        cin.ignore();
                        if (nomorProduk >= 1 && nomorProduk <= jumlahProduk) {
                            nomorProduk--;
                            cout << "Masukkan nama baru : ";
                            getline(cin, produk[nomorProduk].nama);
                            cout << "Masukkan stok baru : ";
                            cin >> produk[nomorProduk].stok;
                            cout << "Masukkan harga baru : ";
                            cin >> produk[nomorProduk].harga;
                            cin.ignore();
                            for (int k = 0; k < 3; k++) {
                                cout << "Warna standar ke-" << k+1 << ": ";
                                getline(cin, produk[nomorProduk].warna.standar[k]);
                                cout << "Warna premium ke-" << k+1 << ": ";
                                getline(cin, produk[nomorProduk].warna.premium[k]);
                            }
                            cout << "Produk berhasil diubah.\n";
                            break;
                   
                        } else {
                            cout << "Nomor produk tidak valid\n";
                        }
                    }
                }
            } else if (pilihan == 4) {
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                } else {
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << produk[i].nama << " |"
                             << setw(6) << produk[i].stok << " |"
                             << setw(7) << produk[i].harga << " |"
                             << setw(20) << produk[i].warna.standar[0] +", " + produk[i].warna.standar[1] + ", " + produk[i].warna.standar[2] << " |" 
                             << setw(25) << produk[i].warna.premium[0] +", " + produk[i].warna.premium[1] + ", " + produk[i].warna.premium[2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                    int nomorProduk;
                    while (true) {
                        cout << "Masukkan nomor produk yang ingin diubah : ";
                        cin >> nomorProduk;
                        cin.ignore();
                        if (nomorProduk >= 1 && nomorProduk <= jumlahProduk) {
                            for (int i = nomorProduk - 1; i < jumlahProduk - 1; i++) {
                                produk[i] = produk[i + 1];
                            }
                            jumlahProduk--;
                            cout << "Produk berhasil dihapus.\n";
                            break;
                        } else {
                            cout << "Nomor produk tidak valid\n";
                        }
                    }
                }
            } else if (pilihan == 5) {
                userIndex = -1;
            }
        }
    }
    return 0;
}