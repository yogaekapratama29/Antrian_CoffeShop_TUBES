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

// DELETE ORDER (COMING SOON
// { CODE }

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