#include <iostream>

using namespace std;

//Fungsi untuk login
bool login() {
    string nama, nim;
    string namasaya = "niky jenita putri";
    string nimsaya = "2409106019";

    int attempts = 0;
    while (attempts < 3) {
        cout << "\nMasukkan Nama : ";
        getline(cin, nama);
        cout << "Masukkan Nim : ";
        cin >> nim;
        cin.ignore();

        if (nama == namasaya && nim == nimsaya) {
            return true;
        }

        cout << "Login gagal! Coba lagi. (Percobaan " << (attempts + 1) << "/3)" << endl;
        attempts++;
    }
    return false;
}

//Fungsi konversi
void konversi() {
    int pilihan;
    double nilai;

    do{
        cout << "\n=============================================="<< endl;
        cout << "|                MENU KONVERSI               |" << endl;
        cout << "=============================================="<< endl;
        cout << "|    1. Meter ke (Centimeter, Mile, Foot)    |" << endl;
        cout << "|    2. Centimeter ke (Meter, Mile, Foot)    |" << endl;
        cout << "|    3. Mile ke (Meter, Centimeter, Foot)    |" << endl;
        cout << "|    4. Foot ke (Meter, Centimeter, Mile)    |" << endl;
        cout << "|    5. Keluar                               |" << endl;
        cout << "=============================================="<< endl;

        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;

        if (pilihan == 5) break;
        if (pilihan < 1 || pilihan > 5) {
            cout << "Pilihan tidak valid" << endl;
            continue;
        }

        cout << "Masukkan nilai yang akan dikonversi : ";
        cin >> nilai;
        cout << "-------------------------------------------------"<< endl;

        switch (pilihan) {
            case 1:
                cout << nilai << " meter = " << nilai * 100 << " cm" << endl;
                cout << nilai << " meter = " << nilai / 1609.344 << " mile" << endl;
                cout << nilai << " meter = " << nilai * 3.28084 << " foot" << endl;
                break;
            case 2:
                cout << nilai << " cm = " << nilai / 100 << " meter" << endl;
                cout << nilai << " cm = " << nilai / 160934.4 << " mile" << endl;
                cout << nilai << " cm = " << nilai / 30.48 << " foot" << endl;
                break;
            case 3:
                cout << nilai << " mile = " << nilai * 1609 << " meter" << endl;
                cout << nilai << " mile = " << nilai * 160934 << " cm" << endl;
                cout << nilai << " mile = " << nilai * 5280 << " foot" << endl;
                break;
            case 4:
                cout << nilai << " foot = " << nilai / 3.281 << " meter" << endl;
                cout << nilai << " foot = " << nilai * 30.48 << " cm" << endl;
                cout << nilai << " foot = " << nilai / 5280 << " mile" << endl;
                break;
        }
    } while (true);
}
int main() {
    cout << "=============================================="<< endl;
    cout << "|      PROGRAM KONVERSI SATUAN PANJANG       |" << endl;
    cout << "=============================================="<< endl;

    if (!login()) {
        cout << "Kesempatan habis! Program berhenti." << endl;
        return 0;
    }

    while (true) {
        konversi();
        char ulang;
        cout << "Ingin mengulangi program? (y/n) : ";
        cin >> ulang;
        if (ulang == 'n' || ulang == 'N') break;
    }

    cout << "Program selesai." << endl;
    return 0;
}