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


void processPayment() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer customer = customerQueue.front();
    customerQueue.pop();
    cout << "Pembayaran selesai untuk pelanggan " << customer.name << " (No. Antrian " << customer.queueNumber << ").\n";
}