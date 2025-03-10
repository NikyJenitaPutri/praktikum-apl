#include <iostream>

using namespace std;

int main() {
    cout << "=============================================="<< endl;
    cout << "|      PROGRAM KONVERSI SATUAN PANJANG       |" << endl;
    cout << "=============================================="<< endl;

    string nama, nim;
    string username = "niky jenita putri";
    string password = "2409106019";

    int attempts = 0;
    bool login = false;
    while (attempts < 3) {
        cout << "\nMasukkan Nama : ";
        getline(cin, nama);
        cout << "Masukkan Nim : ";
        cin >> nim;
        cin.ignore();

        if (nama == username && nim == password) {
            login = true;
            break;
        }

        cout << "Login gagal! Coba lagi. (Percobaan " << (attempts + 1) << "/3)" << endl;
        attempts++;
    }

    if (!login) {
        cout << "=============================================="<< endl;
        cout << "|     Kesempatan habis! Program berhenti.    |" << endl;
        cout << "=============================================="<< endl;
        return 0;
    }

    int pilihan;
    double nilai;
    char ulang;
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

        if (pilihan == 5) {
            cout << "Ingin mengulangi program? (y/n) : ";
            cin >> ulang;
            if (ulang == 'n' || ulang == 'N') break;
            else continue;
        }
        if (pilihan < 1 || pilihan > 5) {
            cout << "Pilihan tidak valid" << endl;
            continue;
        }

        cout << "Masukkan nilai yang akan dikonversi : ";
        cin >> nilai;
        cout << "-------------------------------------------------"<< endl;

        if (pilihan == 1){
            cout << nilai << " meter = " << nilai * 100 << " cm" << endl;
            cout << nilai << " meter = " << nilai * 0.000621371 << " mile" << endl;
            cout << nilai << " meter = " << nilai * 3.28084 << " foot" << endl;
        } else if (pilihan == 2) {
            cout << nilai << " cm = " << nilai / 100 << " meter" << endl;
            cout << nilai << " cm = " << nilai * 0.00000621371 << " mile" << endl;
            cout << nilai << " cm = " << nilai * 0.0328084 << " foot" << endl;
        } else if (pilihan == 3){
            cout << nilai << " mile = " << nilai / 0.000621371 << " meter" << endl;
            cout << nilai << " mile = " << nilai / 0.00000621371 << " cm" << endl;
            cout << nilai << " mile = " << nilai * 5280 << " foot" << endl;
        } else if (pilihan == 4){
            cout << nilai << " foot = " << nilai / 3.28084 << " meter" << endl;
            cout << nilai << " foot = " << nilai / 0.0328084 << " cm" << endl;
            cout << nilai << " foot = " << nilai / 5280 << " mile" << endl;      
        }

        
    } while (true);

    cout << "==============================="<< endl;
    cout << "|      Program selesai.       |" << endl;
    cout << "==============================="<< endl;
    return 0;
}

