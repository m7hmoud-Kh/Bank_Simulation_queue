#include <iostream>
#include <queue>
using namespace std;

#include <Customer.h>
#include <Teller.h>
#include <Bank.h>

int main() {
    priority_queue<Customer> customerPq;

    customerPq.push(Customer("Mahmoud",1,5,1));
    customerPq.push(Customer("Khairy",1,6,1));
    customerPq.push(Customer("ahmed",2,3,1));
    customerPq.push(Customer("hello",3,6,1));
    customerPq.push(Customer("Kamal",4,4,1));
    //customerPq.push(Customer("Kamal2",4,4,3));
    //customerPq.push(Customer("Kamal3",4,4,4));

    Bank b1;
    b1.runBank(customerPq);
    //b1.displayAllteller();
    return 0;
}




