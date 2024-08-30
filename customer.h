#include<iostream>
#include<cstring>

class Customer
{
    public:
        std::string name;
        std::string phnum;
        int idno;
        char RoomType;
        std::string address;
        struct ChechInDate
        {
            int date;
            int month;
            int year;
        };
        ChechInDate checkin;
        struct ChechOutDate
        {
            int date;
            int month;
            int year;
        };
        ChechOutDate checkout;
        int RoomNo;
        int BookingId;
        float AdvncePay;

        Customer();
        // void DisplayData(void);
};