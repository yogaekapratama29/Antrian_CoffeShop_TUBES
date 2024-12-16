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

void addCustomer() {
    Customer customer;
    customer.queueNumber = queueCounter++;
    cout << "Masukkan nama pelanggan: ";
    cin >> customer.name;
    customerQueue.push(customer);
    cout << "Pelanggan " << customer.name << " dengan No. Antrian " << customer.queueNumber << " telah ditambahkan ke antrian.\n";
}

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

void processPayment() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer customer = customerQueue.front();
    customerQueue.pop();
    cout << "Pembayaran selesai untuk pelanggan " << customer.name << " (No. Antrian " << customer.queueNumber << ").\n";
}