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

void processPayment() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer customer = customerQueue.front();
    customerQueue.pop();
    cout << "Pembayaran selesai untuk pelanggan " << customer.name << " (No. Antrian " << customer.queueNumber << ").\n";
}