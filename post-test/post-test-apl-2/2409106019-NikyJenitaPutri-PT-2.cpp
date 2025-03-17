#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define max_login_attempts 3
#define max_produk 100

int main() {
    cout << "=============================================="<< endl;
    cout << "|           MANAJEMEN PRODUK HIJAB           |" << endl;
    cout << "=============================================="<< endl;

    string username = "niky jenita putri", password = "2409106019";
    string inputNama, inputNIM;
    int loginAttempts = 0;

    string namaProduk[max_produk];
    string warnaProduk[max_produk][2][3];
    int stokProduk[max_produk];
    int hargaProduk[max_produk];
    int jumlahProduk = 0;

    //login
    while (loginAttempts < max_login_attempts) {
        cout << "Masukkan Nama : ";
        getline(cin, inputNama);
        cout << "Masukkan NIM : ";
        getline(cin, inputNIM);

        if (inputNama == username && inputNIM == password){
            cout << "Login berhasil!!\n";
            break;
        }else {
            cout << "Login gagal. Coba lagi.\n";
            loginAttempts++;
        }
    }

    if (loginAttempts == max_login_attempts) {
        cout << "Login gagal 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do{
        cout << "\n====================================================\n";
        cout << "|               MANAJEMEN PRODUK HIJAB               |\n";
        cout << "\n====================================================\n";
        cout << "|               1. Tambah Produk                     |\n";
        cout << "|               2. Tampilkan Produk                  |\n";
        cout << "|               3. Ubah Produk                       |\n";
        cout << "|               4. Hapus Produk                      |\n";
        cout << "|               5. Keluar                            |\n";
        cout << "====================================================\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlahProduk < max_produk) {
                    cout << "Masukkan Nama Produk : ";
                    getline(cin,namaProduk[jumlahProduk]);
                    cout << "Masukkan Stok : ";
                    cin >> stokProduk[jumlahProduk];
                    cout << "Masukkan Harga : ";
                    cin >> hargaProduk[jumlahProduk];
                    cin.ignore();

                    for (int k = 0; k < 2; k++) {
                        string kategori = (k == 0) ? "Standar" : "Premium";
                        cout << "\nMasukkan Warna untuk Kategori " << kategori << ":\n";
                        for (int i = 0; i < 3; i++) {
                            cout << "Warna ke-" << i+1 << " : ";
                            getline(cin, warnaProduk[jumlahProduk][k][i]);
                        }
                    }
                    jumlahProduk++;
                    cout << "Produk berhasil ditambahkan";
                } else {
                    cout << "Data penuh!!\n";
                }
                break;

            case 2:
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                } else {
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << namaProduk[i] << " |"
                             << setw(6) << stokProduk[i] << " |"
                             << setw(7) << hargaProduk[i] << " |"
                             << setw(20) << warnaProduk[i][0][0] +", " + warnaProduk[i][0][1] + ", " + warnaProduk[i][0][2] << " |" 
                             << setw(25) << warnaProduk[i][1][0] +", " + warnaProduk[i][1][1] + ", " + warnaProduk[i][1][2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                }
                break;
            
            case 3:
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                    break;
                }

                int nomorProduk;
                do {
                    cout << "Daftar Produk : \n";
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << namaProduk[i] << " |"
                             << setw(6) << stokProduk[i] << " |"
                             << setw(7) << hargaProduk[i] << " |"
                             << setw(20) << warnaProduk[i][0][0] +", " + warnaProduk[i][0][1] + ", " + warnaProduk[i][0][2] << " |" 
                             << setw(25) << warnaProduk[i][1][0] +", " + warnaProduk[i][1][1] + ", " + warnaProduk[i][1][2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                    cout << "\nMasukkan nomor produk yang ingin diubah : ";
                    cin >> nomorProduk;
                    if (nomorProduk < 1 || nomorProduk > jumlahProduk) {
                        cout << "Nomor produk tidak valid!!\n";
                    }
                } while (nomorProduk < 1 || nomorProduk > jumlahProduk);

                nomorProduk--;
                

                cout << "Masukkan Nama Baru : ";
                cin.ignore();
                getline(cin, namaProduk[nomorProduk]);
                cout << "Masukkan Stok Baru : ";
                cin >> stokProduk[nomorProduk];
                cout << "Masukkan Harga Baru : ";
                cin >> hargaProduk[nomorProduk];
                cin.ignore();

                for (int k = 0; k < 2; k++) {
                    string kategori = (k == 0) ? "Standar" : "Premium";
                    cout << "\nMasukkan Warna Baru untuk Kategori " << kategori << ":\n";
                    for (int i = 0; i < 3; i++) {
                        cout << "Warna ke-" << i+1 << " : ";
                        getline(cin, warnaProduk[nomorProduk][k][i]);
                    }
                }
                cout << "produk berhasil diubah";
                break;
                
            case 4:
                if (jumlahProduk == 0) {
                    cout << "\nTidak ada produk tersedia.\n";
                    break;
                }

                do {
                    cout << "\n======================================================================================\n";
                    cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
                    cout << "\n======================================================================================\n";
                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << "| " << setw(2) << i+1 << " |"
                             << setw(12) << namaProduk[i] << " |"
                             << setw(6) << stokProduk[i] << " |"
                             << setw(7) << hargaProduk[i] << " |"
                             << setw(20) << warnaProduk[i][0][0] +", " + warnaProduk[i][0][1] + ", " + warnaProduk[i][0][2] << " |" 
                             << setw(25) << warnaProduk[i][1][0] +", " + warnaProduk[i][1][1] + ", " + warnaProduk[i][1][2] << " |\n";   
                    }
                    cout << "\n======================================================================================\n";
                    cout << "\nMasukkan nomor produk yang ingin diubah : ";
                    cin >> nomorProduk;
                    if (nomorProduk < 1 || nomorProduk > jumlahProduk) {
                        cout << "Nomor produk tidak valid!!\n";
                    }
                } while (nomorProduk < 1 || nomorProduk > jumlahProduk);

                nomorProduk--;

                for (int i = nomorProduk; i < jumlahProduk - 1; i++) {
                    namaProduk[i] = namaProduk[i + 1];
                    stokProduk[i] = stokProduk[i + 1];
                    hargaProduk[i] = hargaProduk[i + 1];
                }
                jumlahProduk--;
                cout << "Produk berhasil dihapus.\n";
                break;
                
            case 5:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid!!\n";
        }
    }while (pilihan != 5);

    return 0;   
}