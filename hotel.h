#include"room.h"
#include<fstream>
#include<unistd.h>
#include<limits>
#include<ctime>
#include<time.h>
#include<list>
#include<cstdio>
#include<conio.h>
#define TOTAL_ROOMS 100

class Hotel:public Room
{
    public:
        int income;
        Room rooms[TOTAL_ROOMS];
        Hotel();
        void AddInc(int);
        void Free(std::list<int>,char,Hotel);
        void SearchRoom(int);
        void CheckIn(int);
        int CheckOut(int);
        void SearchCust(std::string);
        int CountDays(int,int,int,int);
        void DisplayData(void);
        std::string RetName(void);
        void Display(void);
        int RetRoomNo(void);
        char RetType(void);
        bool find(std::list<int>,int);
        int RetInc(void);
        bool CheckStatus(int);
};