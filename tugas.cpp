#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string DB_CUSTOMERS = "customers.csv";
const string DB_SERVICES = "services.csv";

struct Customer
{
    string id_customer;
    string nama;
    int umur;
    char gender;
    string nomor_telepon;
    string alamat;
    Customer *prev = NULL;
    Customer *next = NULL;
};

struct Service
{
    string id_service;
    string id_customer;
    string model_mobil;
    string merek_mobil;
    string deskripsi_kendala;
    string nama_montir;
    Service *prev = NULL;
    Service *next = NULL;
};

Customer *headCust = NULL, *tailCust = NULL;
Service *headServ = NULL, *tailServ = NULL;

// Fungsi sederhana untuk memecah teks berdasarkan koma (CSV)
string getCSVColumn(string line, int colIndex)
{
    string currentWord = "";
    int currentCol = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            if (currentCol == colIndex)
                return currentWord;
            currentCol++;
            currentWord = "";
        }
        else
        {
            currentWord += line[i];
        }
    }
    return (currentCol == colIndex) ? currentWord : "";
}

void insertCustomer(Customer c)
{
    Customer *baru = new Customer(c);
    baru->next = NULL;
    baru->prev = NULL;

    if (headCust == NULL)
    {
        headCust = tailCust = baru;
    }
    else
    {
        tailCust->next = baru;
        baru->prev = tailCust;
        tailCust = baru;
    }
}

void insertService(Service s)
{
    Service *baru = new Service(s);
    baru->next = NULL;
    baru->prev = NULL;

    if (headServ == NULL)
    {
        headServ = tailServ = baru;
    }
    else
    {
        tailServ->next = baru;
        baru->prev = tailServ;
        tailServ = baru;
    }
}

// Muat data dari CSV ke Linked List
void loadAllCustomers()
{
    ifstream file(DB_CUSTOMERS);
    if (!file.is_open())
        return;

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        Customer c;
        c.id_customer = getCSVColumn(line, 0);
        c.nama = getCSVColumn(line, 1);
        string umurStr = getCSVColumn(line, 2);
        c.umur = umurStr.empty() ? 0 : stoi(umurStr);
        string genderStr = getCSVColumn(line, 3);
        c.gender = genderStr.empty() ? '-' : genderStr[0];
        c.nomor_telepon = getCSVColumn(line, 4);
        c.alamat = getCSVColumn(line, 5);

        insertCustomer(c);
    }
    file.close();
}

void loadAllServices()
{
    ifstream file(DB_SERVICES);
    if (!file.is_open())
        return;

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        Service s;
        s.id_service = getCSVColumn(line, 0);
        s.id_customer = getCSVColumn(line, 1);
        s.model_mobil = getCSVColumn(line, 2);
        s.merek_mobil = getCSVColumn(line, 3);
        s.deskripsi_kendala = getCSVColumn(line, 4);
        s.nama_montir = getCSVColumn(line, 5);

        insertService(s); // Masukkan ke RAM (Pointer)
    }
    file.close();
}

// Simpan data baru dari Linked List ke CSV
void saveCustomerCSV(Customer c)
{
    ofstream file(DB_CUSTOMERS, ios::app);
    if (file.is_open())
    {
        file << endl
             << c.id_customer << "," << c.nama << "," << c.umur << ","
             << c.gender << "," << c.nomor_telepon << "," << c.alamat;
        file.close();
    }
}

void saveServiceCSV(Service s)
{
    ofstream file(DB_SERVICES, ios::app);
    if (file.is_open())
    {
        file << endl
             << s.id_service << "," << s.id_customer << "," << s.model_mobil << ","
             << s.merek_mobil << "," << s.deskripsi_kendala << "," << s.nama_montir;
        file.close();
    }
}

int countServices()
{
    int count = 0;
    Service *bantu = headServ;
    while (bantu != NULL)
    {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int countCustomers()
{
    int count = 0;
    Customer *bantu = headCust;
    while (bantu != NULL)
    {
        count++;
        bantu = bantu->next;
    }
    return count;
}

Customer *findCustomerById(string id)
{
    Customer *bantu = headCust;
    while (bantu != NULL)
    {
        if (bantu->id_customer == id)
            return bantu;
        bantu = bantu->next;
    }
    return NULL;
}

string findCustomerIdByName(string nama)
{
    Customer *bantu = headCust;
    while (bantu != NULL)
    {
        if (bantu->nama == nama)
            return bantu->id_customer;
        bantu = bantu->next;
    }
    return "";
}

int choice = 0;

void main_menu();
void menu_services();
void all_services();
void new_service();
void mechanic_job_history();
void all_customers();
void customer_data();

void main_menu()
{
    cout << "\nWelcome To Lognuts\n";
    cout << "1. Servis\n";
    cout << "2. Semua Data Pelanggan\n";
    cout << "3. Data Pelanggan\n";
    cout << "4. Keluar\n";
    cout << "Masukkan Pilihan : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        menu_services();
        break;
    case 2:
        all_customers();
        break;
    case 3:
        customer_data();
        break;
    case 4:
        exit(0);
    default:
        cout << "Pilihan tidak valid!\n";
        break;
    }
}

void menu_services()
{
    cout << "\nServices\n";
    cout << "1. Semua Servis Singkat\n";
    cout << "2. Servis Baru\n";
    cout << "3. Riwayat Kerja Montir\n";
    cout << "Masukkan Pilihan : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        all_services();
        break;
    case 2:
        new_service();
        break;
    case 3:
        mechanic_job_history();
        break;
    default:
        cout << "Pilihan tidak valid!\n";
        break;
    }
}

void all_services()
{
    cout << "\nAll Services\n\n";
    Service *s = headServ;
    if (s == NULL)
        cout << "Data service kosong.\n";

    int index = 0;

    while (s != NULL && index < 3)
    {

        cout << "Model Mobil        : " << s->model_mobil << endl;
        cout << "Merek Mobil        : " << s->merek_mobil << endl;
        cout << "Deskripsi Kendala  : " << s->deskripsi_kendala << endl;
        cout << "Nama Montir        : " << s->nama_montir << endl;

        Customer *c = findCustomerById(s->id_customer);
        if (c != NULL)
        {
            cout << "Nama Customer      : " << c->nama << endl;
            cout << "No Telepon         : " << c->nomor_telepon << endl;
        }
        cout << "-----------------------------" << endl;
        s = s->next;

        index++;
    }
}

void all_customers()
{
    cout << "\nAll Customers\n\n";
    Customer *c = headCust;
    if (c == NULL)
    {
        cout << "Data customer kosong.\n";
        return;
    }

    while (c != NULL)
    {
        cout << "ID          : " << c->id_customer << endl;
        cout << "Nama        : " << c->nama << endl;
        cout << "Umur        : " << c->umur << endl;
        cout << "Gender      : " << c->gender << endl;
        cout << "Telepon     : " << c->nomor_telepon << endl;
        cout << "Alamat      : " << c->alamat << endl;

        // Pemanfaatan 'prev' dan 'tail' Doubly Linked List!
        Service *s = tailServ;
        bool found = false;
        while (s != NULL)
        {
            if (s->id_customer == c->id_customer)
            {
                cout << "Servis Terakhir: " << s->model_mobil << " (" << s->merek_mobil << ")" << endl;
                found = true;
                break;
            }
            s = s->prev; // Mundur ke belakang
        }
        if (!found)
            cout << "Servis Terakhir: Belum ada" << endl;

        cout << "-----------------------------" << endl;
        c = c->next;
    }
}

void customer_data()
{
    string id;
    cout << "\nMasukkan ID Customer: ";
    cin >> id;

    Customer *c = findCustomerById(id);
    if (c == NULL)
    {
        cout << "Customer tidak ditemukan.\n";
        return;
    }

    cout << "Nama          : " << c->nama << endl;
    cout << "Nomor Telepon : " << c->nomor_telepon << endl;
    cout << "Umur          : " << c->umur << endl;
    cout << "Gender        : " << c->gender << endl;
    cout << "Alamat        : " << c->alamat << endl;

    cout << "\n___ Riwayat Service ___\n";
    Service *s = headServ;
    bool found = false;
    while (s != NULL)
    {
        if (s->id_customer == c->id_customer)
        {
            cout << "- " << s->id_service << " | " << s->model_mobil << " | "
                 << s->merek_mobil << " | " << s->deskripsi_kendala << " | "
                 << s->nama_montir << endl;
            found = true;
        }
        s = s->next;
    }
    if (!found)
        cout << "Belum ada service.\n";
}

void new_service()
{
    cout << "\nInput Service Baru\n";
    Service s;
    string namaCust;

    cin.ignore();
    cout << "Model Mobil       : ";
    getline(cin, s.model_mobil);
    cout << "Merek Mobil       : ";
    getline(cin, s.merek_mobil);
    cout << "Deskripsi Kendala : ";
    getline(cin, s.deskripsi_kendala);
    cout << "Nama Montir       : ";
    getline(cin, s.nama_montir);
    cout << "Nama Customer     : ";
    getline(cin, namaCust);

    s.id_customer = findCustomerIdByName(namaCust);
    if (s.id_customer == "")
    {
        Customer newCust;
        cout << "Customer belum terdaftar\n";
        cout << "Model Mobil       : ";
        getline(cin, s.model_mobil);
        cout << "Merek Mobil       : ";
        getline(cin, s.merek_mobil);
        cout << "Deskripsi Kendala : ";
        getline(cin, s.deskripsi_kendala);
        cout << "Nama Montir       : ";
        getline(cin, s.nama_montir);

        cout << "Nama Customer     : ";
        getline(cin, newCust.nama);

        cout << "Nomor Telepon     : ";
        getline(cin, newCust.nomor_telepon);

        cout << "Alamat            : ";
        getline(cin, newCust.alamat);

        cout << "Umur Customer     : ";
        string umurStr;
        getline(cin, umurStr);
        newCust.umur = stoi(umurStr);
        cout << "Gender Customer   : ";
        char genderStr;
        cin >> genderStr;
        newCust.gender = genderStr; 

        int newCustNumber = countCustomers();
        newCust.id_customer = "C" + string(newCustNumber < 10 ? "0" : "") + to_string(newCustNumber);

        s.id_customer = newCust.id_customer; 

        insertCustomer(newCust);  
        saveCustomerCSV(newCust); 

        insertService(s);
        saveServiceCSV(s);

        cout << "Customer baru dan service berhasil ditambahkan.\n";

        return;
    }

    int newNumber = countServices();
    s.id_service = "S" + string(newNumber < 10 ? "0" : "") + to_string(newNumber);

    insertService(s);  // 1. Simpan ke Memori (Pointer)
    saveServiceCSV(s); // 2. Simpan permanen ke CSV

    cout << "Service berhasil ditambahkan.\n";
}

void mechanic_job_history()
{
    string namaMontir;
    cout << "\nMasukkan nama montir: ";
    cin.ignore();
    getline(cin, namaMontir);

    Service *s = headServ;
    bool found = false;

    while (s != NULL)
    {
        if (s->nama_montir == namaMontir)
        {
            Customer *c = findCustomerById(s->id_customer);
            string namaCust = (c != NULL) ? c->nama : "Unknown";

            cout << s->id_service << " | " << s->model_mobil << " | "
                 << s->merek_mobil << " | " << s->deskripsi_kendala
                 << " | Customer: " << namaCust << endl;
            found = true;
        }
        s = s->next;
    }

    if (!found)
        cout << "Tidak ada riwayat untuk montir tersebut.\n";
}

int main()
{
    // Muat data dari CSV ke memori saat program pertama kali berjalan
    loadAllCustomers();
    loadAllServices();

    while (true)
    {
        main_menu();
    }
    return 0;
}