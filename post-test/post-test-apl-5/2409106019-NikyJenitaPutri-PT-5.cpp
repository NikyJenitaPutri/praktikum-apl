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
    Warna warna; //Nested struct untuk warna
};

// Struct untuk menyimpan user
struct User {
    string nama;
    string nim;
};

User users[MAX_USER]; //Array of struct untuk menyimpan user
Produk produk[MAX_PRODUK]; //Array of struct untuk menyimpan produk
int jumlahUser = 0, jumlahProduk = 0;

void tampilkanMenu(); //Prosedur untuk menampilkan menu utama
int registrasiUser(User *users, int &jumlahUser); // Fungsi untuk registrasi user
int loginUser(User *users, int jumlahUser, int loginAttempts); //Fungsi rekursif untuk login
void menuUser (int userIndex, Produk *produk, int &jumlahProduk); //Prosedur untuk menu user
bool tambahProduk(Produk *produk, int &jumlahProduk); //Fungsi untuk menambah produk (overloading)
bool tambahProduk(Produk *produk, int &jumlahProduk, string nama, int stok, int harga, Warna warna); //Fungsi overloading untuk menambah produk
bool tampilkanProduk(Produk *produk, int &jumlahProduk); //Fungsi untuk menampilkan produk (overloading)
bool tampilkanProduk(Produk *produk, int &jumlahProduk, int minHarga); //Fungsi overloading untuk menampilkan produk berdasarkan harga
void ubahProduk(Produk *produk, int &jumlahProduk); //Prosedur untuk mengubah produk
void hapusProduk(Produk *produk, int &jumlahProduk); //Prosedur untuk menghapus produk

int main() {
    int pilihan;
    bool running = true;
    int userIndex = -1;

    while (running) {
        tampilkanMenu();
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            int hasilRegistrasi = registrasiUser(users, jumlahUser);
            if (hasilRegistrasi!= 1){
                cout << "Registrasi berhasil" << endl;
            }   
        } else if (pilihan == 2) {
            userIndex = loginUser(users, jumlahUser, 0);
            if (userIndex != -1) {
                menuUser(userIndex, produk, jumlahProduk);
            }
        } else if (pilihan == 3) {
            cout << "=====================" << endl; 
            cout << "Program berhenti." << endl;
            cout << "=====================" << endl;
            running = false;
        }
    }

    return 0;
}

//Prosedur untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "=======================================" << endl;
    cout << "|         MANAJEMEN TOKO HIJAB        |" << endl;
    cout << "=======================================" << endl;
    cout << "|            1. Registrasi            |" << endl;
    cout << "|            2. Login                 |" << endl;
    cout << "|            3. Keluar                |" << endl;
    cout << "=======================================" << endl;
}

//Fungsi untuk registrasi
int registrasiUser(User *users, int &jumlahUser) {
    if (jumlahUser < MAX_USER) {
        cout << "Masukkan Nama : ";
        getline(cin, users[jumlahUser].nama);
        cout << "Masukkan NIM : ";
        getline(cin, users[jumlahUser].nim);
        jumlahUser++;
        return jumlahUser - 1;
    } else {
        cout << "Jumlah user sudah penuh!\n";
        return -1;
    }
}

//Fungsi rekursif
int loginUser(User *users, int jumlahUser, int loginAttempts) {
    string inputNama, inputNIM;
    int userIndex = -1;

    if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
        cout << "Login gagal 3 kali. Program berhenti.\n";
        exit(0);
    }
    
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
        cout << "Login berhasil\n";
        return userIndex;
    } else {
        cout << "Login gagal. Coba Lagi,\n";
        return loginUser(users, jumlahUser, loginAttempts + 1); //
    }
}

//Prosedur menu utama untuk user setelah login
void menuUser (int userIndex, Produk *produk, int &jumlahProduk) {
    int pilihan;
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
            tambahProduk(produk, jumlahProduk);
        } else if (pilihan == 2) {
            tampilkanProduk(produk, jumlahProduk);
        } else if (pilihan == 3) {
            ubahProduk(produk, jumlahProduk);
        } else if (pilihan == 4) {
            hapusProduk(produk, jumlahProduk);
        } else if (pilihan == 5) {
            userIndex = -1;
        }
    }
}

//Fungsi untuk menambah produk
bool tambahProduk(Produk *produk, int &jumlahProduk) {
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
        return true;
    } else {
        cout << "Data penuh!\n";
        return false;
    }
}

//Fungsi overloading
bool tambahProduk(Produk *produk, int &jumlahProduk, string nama, int stok, int harga, Warna warna) {
    if (jumlahProduk < MAX_PRODUK) {
        produk[jumlahProduk].nama = nama;
        produk[jumlahProduk].stok = stok;
        produk[jumlahProduk].harga = harga;
        produk[jumlahProduk].warna = warna;
        jumlahProduk++;
        cout << "Produk berhasil ditambahkan.\n";
        return true;
    } else {
        cout << "Data penuh!\n";
        return false;
    }
}

//Fungsi overloading
bool tampilkanProduk(Produk *produk, int &jumlahProduk) {
    if (jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return false;
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
        return true;
    }
}

//Fungsi overloading
bool tampilkanProduk(Produk *produk, int &jumlahProduk, int minHarga) {
    bool found = false;
    if (jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return false;
    } else {
        cout << "\n======================================================================================\n";
        cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
        cout << "\n======================================================================================\n";
        for (int i = 0; i < jumlahProduk; i++) {
            if (produk[i].harga >= minHarga) {
                cout << "| " << setw(2) << i+1 << " |"
                     << setw(12) << produk[i].nama << " |"
                     << setw(6) << produk[i].stok << " |"
                     << setw(7) << produk[i].harga << " |"
                     << setw(20) << produk[i].warna.standar[0] +", " + produk[i].warna.standar[1] + ", " + produk[i].warna.standar[2] << " |" 
                     << setw(25) << produk[i].warna.premium[0] +", " + produk[i].warna.premium[1] + ", " + produk[i].warna.premium[2] << " |\n";  
                found = true; 
            }
        }
        cout << "\n======================================================================================\n";
        if (!found) cout << "\nTidak ada produk dengan harga lebih dari " << minHarga << endl;
        return found;
    }
}

//Prosedur
void ubahProduk(Produk *produk, int &jumlahProduk) {
    if (jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
    } else {
        tampilkanProduk(produk, jumlahProduk);
        int nomorProduk;

        //Meminta input nomor produk yang valid
        do {
            cout << "Masukkan nomor produk yang ingin diubah : ";
            cin >> nomorProduk;
            cin.ignore();

            if (nomorProduk < 1 || nomorProduk > jumlahProduk) {
                cout << "Nomor produk tidak valid\n";
            }
        } while (nomorProduk < 1 || nomorProduk > jumlahProduk);

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
    }
}

//Prosedur
void hapusProduk(Produk *produk, int &jumlahProduk) {
    if (jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
    } else {
        tampilkanProduk(produk, jumlahProduk);
        int nomorProduk;

        //Meminta input nomor produk yang valid
        do {
            cout << "Masukkan nomor produk yang ingin dihapus : ";
            cin >> nomorProduk;
            cin.ignore();

            if (nomorProduk < 1 || nomorProduk > jumlahProduk) {
                cout << "Nomor produk tidak valid\n";
            }
        } while (nomorProduk < 1 || nomorProduk > jumlahProduk); //Loop jika nomor tidak valid

        for (int i = nomorProduk - 1; i < jumlahProduk - 1; i++) {
            produk[i] = produk[i + 1];
        }
        jumlahProduk--;
        cout << "Produk berhasil dihapus.\n";
    }
}