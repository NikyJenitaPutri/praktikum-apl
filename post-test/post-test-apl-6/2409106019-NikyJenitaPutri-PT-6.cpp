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

// Struct Data sebagai wadah utama (gabungan)
struct Data {
    User users[MAX_USER];
    Produk produk[MAX_PRODUK];
    int jumlahUser = 0;
    int jumlahProduk = 0; 
};

//Deklarasi fungsi
void tampilkanMenu(); //Prosedur untuk menampilkan menu utama
int registrasiUser(Data *data); // Fungsi untuk registrasi user
int loginUser(Data *data, int attempt = 0); //Fungsi rekursif untuk login
void menuUser (Data *data, int userIndex); //Prosedur untuk menu user
bool tambahProduk(Data &data); //Fungsi untuk menambah produk (overloading)
bool tambahProduk(Data &data, string nama, int stok, int harga, Warna warna); //Fungsi overloading untuk menambah produk
bool tampilkanProduk(Data &data); //Fungsi untuk menampilkan produk (overloading)
bool tampilkanProduk(Data &data, int minHarga); //Fungsi overloading untuk menampilkan produk berdasarkan harga
void ubahProduk(Data *data); //Prosedur untuk mengubah produk
void hapusProduk(Data *data); //Prosedur untuk menghapus produk
void sortingNamaProduk(Data& data);
void sortingStokProduk(Data& data);
void sortingHargaProduk(Data& data);
void menusorting(Data &data);

int main() {
    Data data;
    int pilihan;
    bool running = true;
    int userIndex = -1;

    while (running) {
        tampilkanMenu();
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            int hasil = registrasiUser(&data); //Address-of
            if (hasil!= 1){
                cout << "Registrasi berhasil" << endl;
            }   
        } else if (pilihan == 2) {
            userIndex = loginUser(&data); //Address-of
            if (userIndex != -1) {
                menuUser(&data, userIndex); //Address-of
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
//Parameter Dereference
int registrasiUser(Data *data) {
    if (data ->jumlahUser < MAX_USER) {
        cout << "Masukkan Nama : ";
        getline(cin, data ->users[data ->jumlahUser].nama);
        cout << "Masukkan NIM : ";
        getline(cin, data ->users[data ->jumlahUser].nim);
        data ->jumlahUser++;
        return data ->jumlahUser - 1;
        cout << "Registrasi berhasil" << endl;
    } else {
        cout << "Jumlah user sudah penuh!\n";
        return -1;
    }
}

//Fungsi rekursif
//Parameter Dereference
int loginUser(Data *data, int loginAttempts) {
    if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
        cout << "Login gagal 3 kali. Program berhenti.\n";
        exit(0);
    }
    
    string inputNama, inputNIM;
    cout << "Masukkan Nama : ";
    getline(cin, inputNama);
    cout << "Masukkan NIM : ";
    getline(cin, inputNIM);
    
    for (int i = 0; i < data ->jumlahUser; i++) {
        if(data ->users[i].nama == inputNama && data ->users[i].nim == inputNIM) {
        cout << "Login berhasil\n";
        return i;
        }
    } 

    cout << "Login gagal. Coba Lagi,\n";
    return loginUser(data, loginAttempts + 1); 
}

//Prosedur menu utama untuk user setelah login
//Parameter Dereference
void menuUser (Data *data, int userIndex) {
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
            tambahProduk(*data);
        } else if (pilihan == 2) {
            tampilkanProduk(*data);
            menusorting(*data);
        } else if (pilihan == 3) {
            ubahProduk(data);
        } else if (pilihan == 4) {
            hapusProduk(data);
        } else if (pilihan == 5) {
            userIndex = -1;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

//Fungsi untuk menambah produk
//Parameter Address-Of
bool tambahProduk(Data &data) {
    if (data.jumlahProduk < MAX_PRODUK) {
        Produk &p = data.produk[data.jumlahProduk];
        cout << "Masukkan nama produk : ";
        getline(cin, p.nama);
        cout << "Masukkan stok : ";
        cin >> p.stok;
        cout << "Masukkan harga : ";
        cin >> p.harga;
        cin.ignore();
        for (int i = 0; i < 3; i++) {
            cout << "Warna standar ke-" << i+1 << ": ";
            getline(cin, p.warna.standar[i]);
            cout << "Warna premium ke-" << i+1 << ": ";
            getline(cin, p.warna.premium[i]);
        }
        data.jumlahProduk++;
        cout << "Produk berhasil ditambahkan.\n";
        return true;
    } else {
        cout << "Data penuh!\n";
        return false;
    }
}

//Fungsi overloading
//Parameter Address-Of
bool tambahProduk(Data &data, string nama, int stok, int harga, Warna warna) {
    if (data.jumlahProduk < MAX_PRODUK) {
        data.produk[data.jumlahProduk++] = {nama, stok, harga, warna};
        cout << "Produk berhasil ditambahkan.\n";
        return true;
    } 
    cout << "Data penuh!\n";
    return false;
    
}

//Fungsi overloading
//Parameter Address-Of
bool tampilkanProduk(Data &data) {
    if (data.jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return false;
    } else {
        cout << "\n======================================================================================\n";
        cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
        cout << "\n======================================================================================\n";
        for (int i = 0; i < data.jumlahProduk; i++) {
            Produk &p = data.produk[i];
            cout << "| " << setw(2) << i+1 << " |"
                 << setw(12) << p.nama << " |"
                 << setw(6) << p.stok << " |"
                 << setw(7) << p.harga << " |"
                 << setw(20) << p.warna.standar[0] +", " + p.warna.standar[1] + ", " + p.warna.standar[2] << " |" 
                 << setw(25) << p.warna.premium[0] +", " + p.warna.premium[1] + ", " + p.warna.premium[2] << " |\n";   
        }
        cout << "\n======================================================================================\n";
        return true;
    }
}

//Fungsi overloading
bool tampilkanProduk(Data &data, int minHarga) {
    bool found = false;
    if (data.jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return false;
    } else {
        cout << "\n======================================================================================\n";
        cout << "| No | Nama        | Stok | Harga  |    Warna Standar    |          Warna Premium    |\n";
        cout << "\n======================================================================================\n";
        for (int i = 0; i < data.jumlahProduk; i++) {
            Produk &p = data.produk[i];
            if (p.harga >= minHarga) {
                cout << "| " << setw(2) << i+1 << " |"
                     << setw(12) << p.nama << " |"
                     << setw(6) << p.stok << " |"
                     << setw(7) << p.harga << " |"
                     << setw(20) << p.warna.standar[0] +", " + p.warna.standar[1] + ", " + p.warna.standar[2] << " |" 
                     << setw(25) << p.warna.premium[0] +", " + p.warna.premium[1] + ", " + p.warna.premium[2] << " |\n";  
                found = true; 
            }
        }
        cout << "\n======================================================================================\n";
        if (!found) cout << "\nTidak ada produk dengan harga lebih dari " << minHarga << endl;
        return found;
    }
}

//Prosedur
//Parameter Dereference
void ubahProduk(Data *data) {
    if (data->jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return;
    } else {
        tampilkanProduk(*data);
        int nomorProduk;

        //Meminta input nomor produk yang valid
        do {
            cout << "Masukkan nomor produk yang ingin diubah : ";
            cin >> nomorProduk;
            cin.ignore();

            if (nomorProduk < 1 || nomorProduk > data->jumlahProduk) {
                cout << "Nomor produk tidak valid\n";
            }
        } while (nomorProduk < 1 || nomorProduk > data->jumlahProduk);

        Produk &p = data->produk[nomorProduk - 1];
        cout << "Masukkan nama baru : ";
        getline(cin, p.nama);
        cout << "Masukkan stok baru : ";
        cin >> p.stok;
        cout << "Masukkan harga baru : ";
        cin >> p.harga;
        cin.ignore();
        
        for (int i = 0; i < 3; i++) {
            cout << "Warna standar ke-" << i+1 << ": ";
            getline(cin, p.warna.standar[i]);
            cout << "Warna premium ke-" << i+1 << ": ";
            getline(cin, p.warna.premium[i]);
        }
        cout << "Produk berhasil diubah.\n";
    }
}

//Prosedur
//Parameter Dereference
void hapusProduk(Data *data) {
    if (data->jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return;
    } else {
        tampilkanProduk(*data);
        int nomorProduk;

        //Meminta input nomor produk yang valid
        do {
            cout << "Masukkan nomor produk yang ingin dihapus : ";
            cin >> nomorProduk;
            cin.ignore();

            if (nomorProduk < 1 || nomorProduk > data->jumlahProduk) {
                cout << "Nomor produk tidak valid\n";
            }
        } while (nomorProduk < 1 || nomorProduk > data->jumlahProduk); //Loop jika nomor tidak valid

        for (int i = nomorProduk - 1; i < data->jumlahProduk - 1; i++) {
            data->produk[i] = data->produk[i + 1];
        }
        data->jumlahProduk--;
        cout << "Produk berhasil dihapus.\n";
    }
}

void sortingNamaProduk(Data& data) {
    for (int i = 0; i < data.jumlahProduk - 1; i++) {
        for (int j = 0; j < data.jumlahProduk - i - 1; j++) {
            if (data.produk[j].nama > data.produk[j+1].nama) {
                Produk temp = data.produk[j];
                data.produk[j] = data.produk[j+1];
                data.produk[j+1] = temp;
            }
        }
    }
}

void sortingStokProduk(Data& data) {
    for (int i = 0; i < data.jumlahProduk - 1; i++) {
        for (int j = 0; j < data.jumlahProduk - i - 1; j++) {
            if (data.produk[j].stok < data.produk[j+1].stok) {
                Produk temp = data.produk[j];
                data.produk[j] = data.produk[j+1];
                data.produk[j+1] = temp;
            }
        }
    }
}

void sortingHargaProduk(Data& data) {
    for (int i = 0; i < data.jumlahProduk - 1; i++) {
        for (int j = 0; j < data.jumlahProduk - i - 1; j++) {
            if (data.produk[j].harga > data.produk[j+1].harga) {
                Produk temp = data.produk[j];
                data.produk[j] = data.produk[j+1];
                data.produk[j+1] = temp;
            }
        }
    }
}

void menusorting(Data &data) {
    int pilihanSorting;
    if (data.jumlahProduk == 0) {
        cout << "\nTidak ada produk tersedia.\n";
        return ;
    } else {
        do{
            cout << "=======================================" << endl;
            cout << "|                SORTING              |" << endl;
            cout << "=======================================" << endl;
            cout << "|    1. Nama Produk (Ascending)       |" << endl;
            cout << "|    2. Stok Produk (Descending)      |" << endl;
            cout << "|    3. Harga Produk (Ascending)      |" << endl;
            cout << "|    4. Keluar                        |" << endl;
            cout << "=======================================" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihanSorting;
            cin.ignore();

            switch (pilihanSorting) {
                case 1:
                    sortingNamaProduk(data);
                    cout << "Produk berhasil diurutkan berdasarkan Nama Produk (Ascending)" << endl;
                    tampilkanProduk(data);
                    break;
                case 2:
                    sortingStokProduk(data);
                    cout << "Produk berhasil diurutkan berdasarkan Stok Produk (descending)" << endl;
                    tampilkanProduk(data);
                    break;
                case 3:
                    sortingHargaProduk(data);
                    cout << "Produk berhasil diurutkan berdasarkan Harga Produk (Ascending)" << endl;
                    tampilkanProduk(data);
                    break;
                case 4:
                    cout << "Kembali ke menu" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid" << endl;
            }
        } while (pilihanSorting!=4 );
    }        
}
