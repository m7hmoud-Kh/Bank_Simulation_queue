#ifndef BANK_H
#define BANK_H

class Bank
{
    public:
        static const int number_of_tellers = 3;
        int current_time=0;
        Teller tellerArray[number_of_tellers];
        int totalCustomer = 0;
        int totalServiceTime = 0;

        Bank() {
            for(int i=0; i<number_of_tellers;i++){
            int id = i+1;
            tellerArray[i] = Teller(id);
            }
        }


        void runBank(priority_queue<Customer> &customerPq){
                int smallestIndex;
                int waitingTime;
                int index = 0;
                this->totalCustomer = customerPq.size();
              while (!customerPq.empty()) {

                    Customer custom = customerPq.top();

                    smallestIndex = this->getIndexofNearsetTimeForTeller();

                    if(this->getFreeTeller()){
                        this->getObjectOfFreeTeller().setAvailable(false);
                        if(index < number_of_tellers){
                            tellerArray[smallestIndex].setFinishWork(custom.getArrivalTime() + custom.getSeriveTime());
                            index++;
                        }else if (waitingTime > 0){
                            tellerArray[smallestIndex].setFinishWork(tellerArray[smallestIndex].getFinishWork()+custom.getSeriveTime());

                        }else if (waitingTime < 0){
                            tellerArray[smallestIndex].setFinishWork(custom.getArrivalTime() + custom.getSeriveTime());
                        }
                        this->totalServiceTime += custom.getSeriveTime();
                        tellerArray[smallestIndex].IncrementCustomer();
                        tellerArray[smallestIndex].IncreaseTotalServiceTime(custom.getSeriveTime());
                        custom.display();
                        customerPq.pop();

                    }else{

                        waitingTime = tellerArray[smallestIndex].getFinishWork() - custom.getArrivalTime();

                        if(waitingTime > 0 ){
                            custom.setWaitingTime(waitingTime);
                        }else{
                            custom.setWaitingTime(0);

                        }

                        tellerArray[smallestIndex].setAvailable(true);
                        customerPq.pop();
                        customerPq.push(Customer(custom.getName(),custom.getArrivalTime(),custom.getSeriveTime(),custom.getPriority(),custom.getWaitingTime()));

                    }


            }
                this->showReportOfDay();
                this->displayAllteller();

        }


        bool getFreeTeller()
        {
            for(int i=0;i < number_of_tellers;i++){

                if(tellerArray[i].getAvailable() == "Free"){
                    return true;
                }
            }
            return false;
        }

        Teller &getObjectOfFreeTeller()
        {
             for(int i=0;i < number_of_tellers;i++){
                if(tellerArray[i].getAvailable() == "Free"){
                    return tellerArray[i];
                }
            }
        }

        int getIndexofNearsetTimeForTeller(){
            int smallest = tellerArray[0].getFinishWork();
            int smallestIndex = 0;
            for(int i=0;i < number_of_tellers; i++){
                if(smallest > tellerArray[i].getFinishWork()){
                    smallest = tellerArray[i].getFinishWork();
                    smallestIndex = i;
                }
            }
            return smallestIndex;
        }

        void showReportOfDay(){


            cout << "==========================================" << endl
                 << "Total Customer Serviced In Bank: " << this->totalCustomer
                 << " Total Time Serviced In Bank: " << this->totalServiceTime
                 << endl << "========================================================="
                 << endl;
        }

        void displayAllteller(){
            float percentageService, percentageCustomerService;
            for(int i=0; i<number_of_tellers; i++){
                percentageService = ((float)tellerArray[i].getTotalTimeService() / this->totalServiceTime) * 100;
                percentageCustomerService = ( (float)tellerArray[i].getTotalCustomerSerive() / this->totalCustomer) * 100;
                cout << "Name: " << "Teller" << tellerArray[i].getId()
                << " Id: " << tellerArray[i].getId()
                << " Total Customer Serivce: " << tellerArray[i].getTotalCustomerSerive() << " In Percentage: " << percentageService << "% "
                << " Total Time Serivced: " << tellerArray[i].getTotalTimeService() << " In Percentage : " << percentageCustomerService << "% "
                << endl << "===================================================================" << endl;

                percentageCustomerService = 0;
                percentageService = 0;
            }

        }

    protected:

    private:


};

#endif // BANK_H
