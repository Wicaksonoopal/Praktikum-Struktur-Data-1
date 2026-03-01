#include <iostream>
using namespace std;

void welcome();
void servis();
void semua_servis();
void servis_baru();
void servis_baru_tidak_terdaftar();
void riwayat_kerja_montir();
void riwayat_kerja_montir_lanjutan();
void semua_data_pelanggan();
void data_pelanggan();

struct Customer {
    string nama;
    int umur;
    char gender;
    string nomor_telepon;
    string alamat;
    string data_servis;
};

struct Service {
    string model_mobil;
    string merek_mobil;
    string deskripsi_kendala;
    string nama_montir;
    string data_customer;
}; 

void welcome() {
    cout << "Welcome to Lognuts!" << endl;
    cout << "Pilih Menu:" << endl;
    cout << " " << endl;
    cout << "1. Servis" << endl;
    cout << "2. Semua Data Pelanggan" << endl;
    cout << "3. Data Pelanggan" << endl;
    cout << "4. Keluar" << endl;
    cout << " " << endl;
    cout << "Masukkan Pilihan Anda: " << endl;
}

void servis() {
    cout << "=== Servis ===" << endl;
    cout << "Pilih Menu?" << endl;
    cout << " " << endl;
    cout << "1. Semua Servis Singkat" << endl;
    cout << "2. Servis Baru" << endl;
    cout << "3. Riwayat Kerja Montir" << endl;
    cout << " " << endl;
    cout << "Masukkan Pilihan Anda: " << endl;
}

void semua_servis() {
    cout << "=== Semua Servis ===" << endl;
    cout << " " << endl;
    cout << "--------------------" << endl;
    cout << "Model Mobil: " << endl;
    cout << "Merek Mobil: " << endl;
    cout << "Deskripsi Kendala: " << endl;
    cout << "Nama Montir: " << endl;
    cout << "Nama Customer: " << endl;
    cout << "Nomor Telepon Customer: " << endl;
    cout << "--------------------" << endl;
}

void servis_baru() {
    cout << "=== Servis Baru ===" << endl;
    cout << "Masukkan Model Mobil: " << endl;
    cout << "Masukkan Merek Mobil: " << endl;
    cout << "Masukkan Deskripsi Kendala: " << endl;
    cout << "Masukkan Nama Montir: " << endl;
    cout << "Masukkan Nama Customer: " << endl;
    cout << " " << endl;
    cout << "*Pelanggan sudah terdaftar dan servis berhasil dicatat*" << endl;
}

void servis_baru_tidak_terdaftar() {
    cout << "=== Servis Baru ===" << endl;
    cout << "Masukkan Model Mobil: " << endl;
    cout << "Masukkan Merek Mobil: " << endl;
    cout << "Masukkan Deskripsi Kendala: " << endl;
    cout << "Masukkan Nama Montir: " << endl;
    cout << "Masukkan Nama Customer: " << endl;
    cout << "Masukkan Nomor Telepon Customer: " << endl;
    cout << "Masukkan Alamat Customer: " << endl;
    cout << "Masukkan Umur Customer: " << endl;
    cout << "Masukkan Gender Customer: " << endl;
    cout << " " << endl;
    cout << "*Pelanggan baru telah terdaftar, data servis berhasil dicatat*" << endl;
}

void riwayat_kerja_montir() {
    cout << "=== Riwayat Kerja Montir ===" << endl;
    cout << "Pilih Montir: " << endl;
    cout << "1. Montir A" << endl;
    cout << "2. Montir B" << endl;
    cout << "3. Montir C" << endl;
}

void riwayat_kerja_montir_lanjutan() {
    cout << "=== Riwayat Montir A ===" << endl;
    cout << " " << endl;
    cout << "--------------------" << endl;
    cout << "Model Mobil: " << endl;
    cout << "Merek Mobil: " << endl;
    cout << "Deskripsi Kendala: " << endl;
    cout << "Nama Montir:" << endl;
    cout << "Nama Customer: " << endl;
    cout << "Nomor Telepon Customer: " << endl;
    cout << "--------------------" << endl;
}

void semua_data_pelanggan() {
    cout << "=== Semua Data Pelanggan ===" << endl;
    cout << " " << endl;
    cout << "--------------------" << endl;
    cout << "Nama Customer: " << endl;
    cout << "Nomor Telepon Customer: " << endl;
    cout << "Alamat Customer: " << endl;
    cout << "--- Servis Terakhir ---" << endl;
    cout << "Model Mobil: " << endl;
    cout << "Deskripsi Kendala: " << endl;
    cout << "Nama Montir: " << endl;
    cout << "--------------------" << endl;
}

void data_pelanggan() {
    cout << "=== Data Pelanggan ===" << endl;
    cout << "Nama Customer: " << endl;
    cout << "Nomor Telepon Customer: " << endl;
    cout << "Umur Customer: " << endl;
    cout << "Gender Customer: " << endl;
    cout << "Alamat Customer: " << endl;
    cout << " " << endl;
    cout << "--- 3 Servis Terakhir ---" << endl;
    cout << "--------------------" << endl;
    cout << "Model Mobil: " << endl;
    cout << "Deskripsi Kendala: " << endl;
    cout << "Nama Montir: " << endl;
    cout << "--------------------" << endl;
}

