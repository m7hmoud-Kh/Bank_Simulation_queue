#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer
{
    string name;
    int arrival_time;
    int service_time;
    int waiting_time = 0;
    int priority;
    bool arrival = true;

    public:
        Customer(string name, int arrival_time, int service_time, int priority) {
            this->name = name;
            this->arrival_time = arrival_time;
            this->service_time = service_time;
            this->priority = priority;
        }


          Customer(string name, int arrival_time, int service_time, int priority,int waiting_time) {
            this->name = name;
            this->arrival_time = arrival_time;
            this->service_time = service_time;
            this->priority = priority;
            this->waiting_time = waiting_time;
        }



        bool operator<(const Customer& other)  const{
            if (this->arrival_time == other.arrival_time) {
                return this->priority < other.priority; // Reverse the comparison for value2
            }
            return this->arrival_time > other.arrival_time; // Reverse the comparison for value1
        }

        string getName()
        {
            return this->name;
        }

        int getArrivalTime(){
            return this->arrival_time;
        }

        bool getArrival(){
            return this->arrival;
        }

        void setArrival(bool arrival){
            this->arrival = arrival;
        }

        void setWaitingTime(int waiting)
        {
            this->waiting_time += waiting;
        }

        int getWaitingTime()
        {
            return this->waiting_time;
        }

        int getSeriveTime()
        {
            return this->service_time;
        }

        int getPriority()
        {
            return this->priority;
        }
        void display(){
            cout << "Name: " << this->name
            << " Arrival Time: " << this->arrival_time
            << " service Time: " << this->service_time
            << " waiting Time: " << this->waiting_time
            << endl;
        }

};



#endif // CUSTOMER_H
