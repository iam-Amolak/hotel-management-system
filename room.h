#include<vector>
#include"customer.h"

class Room:public Customer
{
    public:
        Customer cust;
        int roomno;
        char type;                  // L(luxury) , E(elite) , N(normal)
        int status;                 // 0 for empty , 1 for full
        char ac;                    // A for AC , F for FAN
        float rent;
};