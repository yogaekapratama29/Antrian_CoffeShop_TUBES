#include <iostream>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

struct Customer {
    int queueNumber;
    string name;
    map<string, int> orders; 
};

map<string, double> menu;

void initializeMenu() {
    menu["kopi_susu"] = 15000;
    menu["latte"] = 20000;
    menu["americano"] = 18000;
    menu["croissant"] = 25000;
    menu["brownies"] = 30000;
}

queue<Customer> customerQueue; 
int queueCounter = 1; 

// ADD CUSTOMER
void addCustomer() {
    Customer customer;
    customer.queueNumber = queueCounter++;
    cout << "Masukkan nama pelanggan: ";
    cin >> customer.name;
    customerQueue.push(customer);
    cout << "Pelanggan " << customer.name << " dengan No. Antrian " << customer.queueNumber << " telah ditambahkan ke antrian.\n";
}

// DISPLAY MENU
void displayMenu() {
    cout << "\n=== Daftar Menu ===\n";
    cout << left << setw(15) << "Produk" << "Harga" << endl;
    cout << "-------------------------\n";
    for (map<string, double>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
        cout << left << setw(15) << it->first << "Rp " << it->second << endl;
    }
}

// ADD ORDER
void addOrder() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    displayMenu();

    string product;
    int quantity;
    cout << "Masukkan nama produk: ";
    cin >> product;

    if (menu.find(product) == menu.end()) {
        cout << "Produk tidak tersedia di menu.\n";
        return;
    }

    cout << "Masukkan jumlah: ";
    cin >> quantity;
    customerQueue.front().orders[product] += quantity;
    cout << "Pesanan " << quantity << " " << product << " telah ditambahkan untuk pelanggan " << customerQueue.front().name << ".\n";
}

// DETAIL ORDER
void showOrderDetails() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer& customer = customerQueue.front();
    cout << "\nDetail Pesanan untuk Pelanggan " << customer.name << " (No. Antrian " << customer.queueNumber << "):\n";
    if (customer.orders.empty()) {
        cout << "Belum ada pesanan.\n";
    } else {
        double total = 0;
        cout << left << setw(15) << "Produk" << setw(10) << "Jumlah" << "Harga Total" << endl;
        cout << "-------------------------------------\n";
        for (map<string, int>::const_iterator it = customer.orders.begin(); it != customer.orders.end(); ++it) {
            double subtotal = it->second * menu[it->first];
            total += subtotal;
            cout << left << setw(15) << it->first << setw(10) << it->second << "Rp " << subtotal << endl;
        }
        cout << "-------------------------------------\n";
        cout << "Total Pembayaran: Rp " << total << endl;
    }
}

// UPDATE ORDER
void updateOrder() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    
    string product;
    cout << "Masukkan nama produk yang ingin diupdate: ";
    cin >> product;
    
    map<string, int>& orders = customerQueue.front().orders;

    if (orders.find(product) == orders.end()) {
        cout << "Produk tidak ditemukan dalam pesanan.\n";
        return;
    }
    
    int newQuantity;
    cout << "Masukkan jumlah baru untuk " << product << ": ";
    cin >> newQuantity;

    if (newQuantity == 0) {
        orders.erase(product);
        cout << "Pesanan " << product << " telah dihapus.\n";
    } else {
        orders[product] = newQuantity;
        cout << "Pesanan " << product << " telah diupdate menjadi " << newQuantity << ".\n";
    }
}

// PAYMENT
void processPayment() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer customer = customerQueue.front();
    customerQueue.pop();
    cout << "Pembayaran selesai untuk pelanggan " << customer.name << " (No. Antrian " << customer.queueNumber << ").\n";
}

int main() {
    return 0;
}
