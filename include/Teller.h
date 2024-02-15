#ifndef TELLER_H
#define TELLER_H


class Teller
{
    bool available = true;
    int id;
    int total_service_time = 0;
    int total_customer_serivce = 0;
    int finish_work = 0;

    public:
        Teller(){}
        Teller(int id) {
            this->id = id;
        }

        string getAvailable(){
            if(this->available){
                return "Free";
            }
            return "Busy";
        }

        void setAvailable(bool available){
            this->available = available;
        }

        int getId(){
            return this->id;
        }


        void setId(int id){
            this->id = id;
        }

        void IncrementCustomer()
        {
            this->total_customer_serivce++;
        }

        void IncreaseTotalServiceTime(int serivceTime)
        {
            this->total_service_time += serivceTime;
        }

        int getTotalCustomerSerive()
        {
            return this->total_customer_serivce;
        }


        int getTotalTimeService()
        {
            return this->total_service_time;
        }

        int getFinishWork()
        {
            return this->finish_work;
        }



        void setFinishWork(int finish_work){
            this->finish_work  = finish_work;
        }

    protected:

    private:
};

#endif // TELLER_H
