#include"hotel.h"
using namespace std;

Hotel::Hotel()
{
    income=0;
    for(int i=0;i<30;i++)
    {
        rooms[i].type='L';
        rooms[i].ac='A';
        rooms[i].rent=8000;
        rooms[i].roomno=i+1;
        rooms[i].status=0;
    }

    for(int i=30;i<60;i++)
    {
        rooms[i].type='E';
        rooms[i].ac='A';
        rooms[i].rent=5000;
        rooms[i].roomno=i+1;
        rooms[i].status=0;
    }

    for(int i=60;i<100;i++)
    {
        rooms[i].type='N';
        rooms[i].ac='F';
        rooms[i].rent=3000;
        rooms[i].roomno=i+1;
        rooms[i].status=0;
    }
}

void Hotel::Free(list<int> brooms,char type,Hotel h)
{
    cout<<"\n\n\t\t\tAvailable rooms no : \n";
    int j=1,total,i;
    
    if(type=='L')
    {
        i=0;
        total=30;
    }
    else if(type=='E')
    {
        i=30;
        total=60;
    }
    else
    {
        i=60;
        total=100;
    }

    i++;
    while(i<total+1)
    {
        if(!h.find(brooms,i))
        {
            cout<<"\t\t\t"<<j<<" . "<<i<<endl;
            j++;
        }
        i++;
    }

    if(j==1)
    {
        cout<<"[INFO] No available rooms"<<endl;
    }
}

void Hotel::SearchRoom(int i)
{
    cout<<"\n\t\t\tRoom Details - ";
    if(rooms[i].type=='L')
    {
        cout<<"\n\n\t\tRoom Type : LUXURY";
    }
    else if(rooms[i].type=='E')
    {
        cout<<"\n\n\t\tRoom Type : ELITE";
    }
    else
    {
        cout<<"\n\n\t\tRoom Type : NORMAL";
    }
    if(rooms[i].ac=='A')
    {
        cout<<"\n\t\tAC/FAN : AC";
    }
    else
    {
        cout<<"\n\t\tAC/FAN : FAN";
    }
    cout<<"\n\t\tRent : "<<rooms[i].rent;
}

int Hotel::CountDays(int date1,int date2,int month1,int month2)
{
    const int monthdays[12]={31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int total=0;
    if(date1<date2)
    {
        total+=date2-date1;
    }
    else
    {
        total+=date1-date2;
    }
    total+=monthdays[month2]-monthdays[month1];
    return total;
}

int Hotel::CheckOut(int no)
{
    int days=0;

    if(rooms[no-1].status==0)
    {
        return -1;
    }

    cout<<"\n\t\t\tEnter Check-Out Date : ";
    cout<<"\n\t\t\t\tEnter date : ";
    cin>>this->cust.checkout.date;
    cout<<"\t\t\t\tEnter month : ";
    cin>>this->cust.checkout.month;
    cout<<"\t\t\t\tEnter year : ";
    cin>>this->cust.checkout.year;

    days=CountDays(this->cust.checkin.date,this->cust.checkout.date,this->cust.checkin.month,this->cust.checkout.month);

    cout<<"\n\t\t\tCustomer Name : "<<this->cust.name;
    cout<<"\n\t\t\tCustomer Address : "<<this->cust.address;
    cout<<"\n\t\t\tCustomer Phone no : "<<this->cust.phnum;
    cout<<"\n\t\t\tTotal Days Stayed : "<<days;
    if(this->cust.AdvncePay<(rooms[no-1].rent*days))
    {
        cout<<"\n\n\t\tTotal Amount : "<<rooms[no-1].rent*days;
        cout<<"\n\t\tAdvance Payment : "<<this->cust.AdvncePay;
        cout<<"\n\t\t\tYour remaining amount is : "<<rooms[no-1].rent*days-this->cust.AdvncePay<<endl;
        cout<<"\t\t\tPlease complete your payment"<<endl;
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tTHANKS FOR VISITING"<<endl;
    }
    rooms[no-1].status=0;
    cout<<"\n\t\t\tCheck Out Successful"<<endl;
    return rooms[no-1].rent*days;
}

void Hotel::SearchCust(string cname)
{
    bool found=false;
    for(int i=0;i<TOTAL_ROOMS;i++)
    {
        if(rooms[i].cust.name==cname)
        {
            found=true;
            cout<<"\n\n\t\t\tCustomer Room No : "<<rooms[i].cust.RoomNo;
            cout<<"\n\t\t\tCustomer Name : "<<rooms[i].cust.name;
            cout<<"\n\t\t\tCheck In Date : "<<rooms[i].cust.checkin.date<<"/"<<rooms[i].cust.checkin.month<<"/"<<rooms[i].cust.checkin.year;
        }
    }
    if(!found)
    {
        cout<<"\n\n\t\t\tThere is No such Customer"<<endl;
    }
}

void Hotel::DisplayData(void)
{
    cout<<"\n\t\t\tName of Customer : "<<this->cust.name<<endl;
    cout<<"\t\t\tAddress : "<<this->cust.address<<endl;
    cout<<"\t\t\tPhone number : "<<this->cust.phnum<<endl;
    cout<<"\t\t\tCheck-In Date : "<<this->cust.checkin.date<<"/"<<this->cust.checkin.month<<"/"<<this->cust.checkin.year<<endl;
    cout<<"\t\t\tRoom no : "<<this->cust.RoomNo<<endl;
}

void Hotel::CheckIn(int no)
{
    system("cls");
    cout<<"\n\t\t\tEnter customer name : ";
    cin>>this->cust.name;
    cout<<"\n\t\t\tEnter phone number : ";
    cin>>this->cust.phnum;
    cout<<"\n\t\t\tEnter ID number : ";
    cin>>this->cust.idno;
    cout<<"\n\t\t\tEnter address(only city) : ";
    cin>>this->cust.address;
    cout<<"\n\t\t\tEnter Check-In Date : ";
    cout<<"\n\t\t\t\tEnter date : ";
    cin>>this->cust.checkin.date;
    cout<<"\t\t\t\tEnter month : ";
    cin>>this->cust.checkin.month;
    cout<<"\t\t\t\tEnter year : ";
    cin>>this->cust.checkin.year;
    cout<<"\n\t\t\tAdvance payment : ";
    cin>>this->cust.AdvncePay;
    cout<<"\n\n\t\t\t\tCustomer Bookind ID is : "<<this->cust.idno;
    this->cust.BookingId=this->cust.idno;
    cout<<"\n\t\t\t\tCustomer room no : "<<no;
    this->cust.RoomNo=no;
    rooms[no-1].status=1;
    this->cust.RoomType=rooms[no-1].type;
    cout<<"\n\t\t\tRecord Saved Successfully..";
}

bool Hotel::CheckStatus(int no)
{
    if(rooms[no-1].status==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string Hotel::RetName(void)
{
    return this->cust.name;
}

void Hotel::Display(void)
{
    cout<<"\n\n\t\t\tCustomer Room No : "<<this->cust.RoomNo;
    cout<<"\n\t\t\tCustomer Name : "<<this->cust.name;
    cout<<"\n\t\t\tCheck In Date : "<<this->cust.checkin.date<<"/"<<this->cust.checkin.month<<"/"<<this->cust.checkin.year;
}

int Hotel::RetRoomNo(void)
{
    return this->cust.RoomNo;
}

char Hotel::RetType(void)
{
    return this->cust.RoomType;
}

bool Hotel::find(list<int> brooms,int no)
{
    bool found=false;
    list<int>::iterator itr;
    for(itr=brooms.begin();itr!=brooms.end();++itr)
    {
        if(*itr==no)
        {
            found=true;
            return true;
        }   
    }
    if(!found)
    {
        return false;
    }
}

int Hotel::RetInc(void)
{
    return income;
}