#include <iostream>
#include <queue>
using namespace std;

#include <Customer.h>
#include <Teller.h>
#include <Bank.h>

int main() {
    priority_queue<Customer> customerPq;

    customerPq.push(Customer("Mahmoud",1,10,60));
    customerPq.push(Customer("Khairy",1,10,60));
    customerPq.push(Customer("ahmed",1,5,60));
    customerPq.push(Customer("Kamal",1,4,20));
    customerPq.push(Customer("hello",1,5,20));
    customerPq.push(Customer("mai",2,5,60));
    customerPq.push(Customer("tark",2,4,20));
    customerPq.push(Customer("mostafa",2,4,70));

    Bank b1;
    b1.runBank(customerPq);
    return 0;
}




