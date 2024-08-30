#include"hotel.h"

using namespace std;

void printmsg(void);
void printdate(void);
int login(void);

double income=0;

int main()
{
    Hotel h;
    fstream file1;
    fstream file3;
    fstream file4;
    fstream file5;
    int inc=0;
    string cname;
    list<int> BookedRooms;

    file1.open("DATA.DAT",ios::out|ios::app|ios::binary);
    if(!file1)
    {
        cout<<"errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }

    file3.open("TEMPDATA.DAT",ios::out|ios::app|ios::binary);
    if(!file3)
    {
        cout<<"errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }

    file4.open("COPYDATA.DAT",ios::out|ios::app|ios::binary);
    if(!file4)
    {
        cout<<"errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }

    file5.open("INCOME.TXT",ios::out|ios::app);
    if(!file5)
    {
        cout<<"errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }

    file1.close();
    file3.close();
    file4.close();
    file5.close();

    printmsg();
    int opt,no,days,a,status;
    char t;
    bool found;
    usleep(5000000);
    cout<<"\n\n\t\t\tPress ENTER to continue..";
    getch();
    
    while(1)
    {
        printmsg();
        printdate();
        cout<<"\n\n\t\t\t1. Search Available Rooms";
        cout<<"\n\t\t\t2. Book a room";
        cout<<"\n\t\t\t3. Check Out";
        cout<<"\n\t\t\t4. Search Customer";
        cout<<"\n\t\t\t5. Guest Summary Report";
        cout<<"\n\t\t\t6. ADMIN LogIn";
        cout<<"\n\t\t\t7. EXIT";
        cout<<"\n\n\t\tEnter Option : ";
        cin>>opt;
        switch(opt)
        {
            case 1:
                cout<<"\n\t\t\tEnter desired Room Type(N(Normal) /E(Elite) /L(Luxury)) : ";
                cin>>t;
                file3.open("TEMPDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
                h.Free(BookedRooms,t,h);
                file3.close();
                getch();
                break;

            case 2:
                cout<<"\n\t\t\tEnter room no : ";
                cin>>no;
                if(h.CheckStatus(no))
                {
                    BookedRooms.push_back(no);
                    file3.open("TEMPDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
                    h.CheckIn(no);
                    file3.write(reinterpret_cast<char*>(&h),sizeof(Hotel));
                    file3.close();
                }
                else
                {
                    cout<<"\n\n\t\t\tRoom is already Booked";
                }
                getch();
                break;

            case 3:
                cout<<"\n\t\t\tEnter room no : ";
                cin>>no;
                BookedRooms.remove(no);
                file1.open("DATA.DAT",ios::out|ios::app|ios::out|ios::binary);
                file3.open("TEMPDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
                file4.open("COPYDATA.DAT",ios::out|ios::app|ios::out|ios::binary);
                file3.seekg(0,ios::beg);
                file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                while(!file3.eof())
                {
                    if(h.RetRoomNo()==no)
                    {
                        a = h.CheckOut(no);
                        if(a==-1)
                        {
                            cout<<"\n\t\t\tRoom is not booked"<<endl;
                        }
                        else
                        {
                            inc+=a;
                            file5.open("INCOME.TXT",ios::out|ios::ate);
                            file5<<inc;
                            file5.close();
                        }
                        file1.write(reinterpret_cast<char*>(&h),sizeof(Hotel));                 // DATA.DAT
                        file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                        continue;
                    }
                    file4.write(reinterpret_cast<char*>(&h),sizeof(Hotel));                     // COPYDATA.DAT
                    file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));                      // TEMPDATA.DAT
                }
                file1.close();
                file3.close();
                file4.close();
                remove("TEMPDATA.DAT");
                rename("COPYDATA.DAT","TEMPDATA.DAT");
                getch();
                break;

            case 4:
                found=false;
                cout<<"\n\t\t\tEnter Customer Name : ";
                cin>>cname;
                file3.open("TEMPDATA.DAT",ios::in|ios::binary);
                file3.seekg(0,ios::beg);
                file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                while(!file3.eof())
                {
                    if(cname.compare(h.RetName())==0)
                    {
                        found=true;
                        h.Display();
                        break;
                    }
                    file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                }
                file3.close();
                if(!found)
                {
                    cout<<"\n\n\t\t\tThere is No such Customer"<<endl;
                }
                cout<<"\n\n\t\t\t\t\tPress ENTER...";
                getch();
                break;

            case 5:
                cout<<"\n\t\t\t1. Current Customer Data";
                cout<<"\n\t\t\t2. All Data";
                int choice;
                cout<<"\n\t\t\t\tEnter option : ";
                cin>>choice;
                system("cls");
                if(choice==1)
                {
                    file3.open("TEMPDATA.DAT",ios::in|ios::binary);
                    file3.seekg(0,ios::beg);
                    file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                    while(!file3.eof())
                    {
                        h.DisplayData();
                        file3.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                    }
                    file3.close();
                    cout<<"\n\n\t\t\t\t\tPress ENTER...";
                    getch();
                }
                if(choice==2)
                {
                    file1.open("DATA.DAT",ios::in|ios::binary);
                    file1.seekg(0,ios::beg);
                    file1.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                    while(!file1.eof())
                    {
                        h.DisplayData();
                        file1.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                    }
                    file1.close();
                    cout<<"\n\n\t\t\t\t\tSelect your option : ";
                    cout<<"\n\t\t\t1. Search Data";
                    cout<<"\n\t\t\t2. Back to Main Menu";
                    cout<<"\n\t\t\t\tEnter : ";
                    cin>>opt;
                    if(opt==1)
                    {
                        system("cls");
                        cout<<"\n\t\t\tEnter Customer Name : ";
                        cin>>cname;
                        file1.open("DATA.DAT",ios::in|ios::binary);
                        file1.seekg(0,ios::beg);
                        file1.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                        while(!file1.eof())
                        {
                            if(cname.compare(h.RetName())==0)
                            {
                                h.DisplayData();
                            }
                            file1.read(reinterpret_cast<char*>(&h),sizeof(Hotel));
                        }
                        file1.close();
                        cout<<endl<<endl<<"\t\t\t\t\tPress ENTER...";
                        getch();
                    }
                }
                break;

            case 6:
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
                if(login())
                {
                    file5.open("INCOME.TXT",ios::in|ios::out|ios::app);
                    cout<<"\n\n\t\t\t\t\tTotal Income : ";
                    file5>>a;
                    cout<<a;
                    file5.close();
                }
                else
                {
                    cout<<"\n\n\t\t\t\t\t[WARNING] You entered wrong credentials"<<endl;
                }
                getch();
                break;

            case 7:
                system("cls");
                cout<<"\n\n\n\t\t\t\t\t_THANK YOU FOR USING SOFTWARE_";
                getch();
                remove("COPYDATA.DAT");
                exit(0);

            case 10:
                system("cls");
                cout<<"\n\n\t\t\t\t\tSECRET PORTAL";
                cout<<"\n\n\t\t\t1. Clear CURRENT Data";
                cout<<"\n\t\t\t2. Clear ALL Data";
                cout<<"\n\t\t\t3. Clear INCOME Data";
                cout<<"\n\t\tEnter Option : ";
                cin>>opt;
                if(opt==1)
                {
                    cout<<"[WARNING] ARE YOU SURE (Y/N) ?";
                    cin>>t;
                    if(t=='Y')
                    {
                        file3.open("TEMPDATA.DAT",ios::out|ios::trunc);
                        file3.close();
                        cout<<"[INFO] DATA Successfully Deleted";
                        getch();
                    }
                    else
                    {
                        break;
                    }
                }
                else if(opt==2)
                {
                    cout<<"[WARNING] ARE YOU SURE (Y/N) ?";
                    cin>>t;
                    if(t=='Y')
                    {
                        file3.open("DATA.DAT",ios::out|ios::trunc);
                        file3.close();
                        cout<<"[INFO] DATA Successfully Deleted";
                        getch();
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    cout<<"[WARNING] ARE YOU SURE (Y/N) ?";
                    cin>>t;
                    if(t=='Y')
                    {
                        file3.open("INCOME.TXT",ios::out|ios::trunc);
                        file3.close();
                        cout<<"[INFO] DATA Successfully Deleted";
                        getch();
                    }
                    else
                    {
                        break;
                    }
                }
                break;

            default:
                cout<<"\n\n[WARNING] You entered wrong option..";
                getch();
                break;
        }
    }
    getch();
    return 0;
}

void printmsg(void)
{
    system("cls");
    cout<<endl<<endl;
    cout<<"\n\t\t\t\t\t|********************************|";
    cout<<"\n\t\t\t\t\t| TREE HOTEL MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t\t\t\t|********************************|";
}

void printdate(void)
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    printf("\t\t\tLast LOGIN Time : %s", asctime(ptr));
}

int login(void)
{
    char user[20];
    char pass[20];
    cout<<"\n\n\n\t\t\t\t\tWelcome to ADMIN Portal";
    cout<<"\n\n\t\t\t\t\tEnter username : ";
    gets(user);
    cout<<"\t\t\t\t\tEnter password : ";
    int z;
    pass[5]={0};
    for(z=0;z<5;z++)
    {
        pass[z]=getch();
        cout<<"*";
    }
    getch();
    if(strcmp(user,"admin")==0&&strcmp(pass,"12345")==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}