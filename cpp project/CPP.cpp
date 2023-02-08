#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void page2();
void staff();
void tourist();
void page3();
bool checkpoint(string x);
class passenger
{
    string result;
    string name, password;

public:
    void getdata()
    {
        cout << "Enter user name:" << endl;
        cin >> name;
        cout << "Enter password:" << endl;
        cin >> password;
    }
    void newdata()
    {
        fstream file;
        file.open("pass.txt", ios::app);
        file << name << " " << password << endl;
        file.close();
        cout << "Added successfully" << endl;
        cout << "Login for further benefits" << endl;
    }
    bool checkdata()
    {
        int count = 0;
        fstream file;
        file.open("pass.txt", ios::in);
        string x;
        result = name + " " + password;
        while (getline(file, x))
        {
            if (x == result)
                count += 1;
        }
        file.close();
        if (count == 0)
            return 0;
        else
            return 1;
    }
};

class Staff
{
    string result;
    string name, password;

public:
    void getdata()
    {
        cout << "Enter user name:" << endl;
        cin >> name;
        cout << "Enter password:" << endl;
        cin >> password;
    }
    void newdata()
    {
        fstream file;
        file.open("staff.txt", ios::app);
        file << name << " " << password << endl;
        file.close();
        cout << "Added successfully" << endl;
        cout << "Login for further benifits" << endl;
    }
    bool checkdata()
    {
        int count = 0;
        fstream file;
        file.open("staff.txt", ios::in);
        string x;
        result = name + " " + password;
        while (getline(file, x))
        {
            if (x == result)
                count += 1;
        }
        file.close();
        if (count == 0)
            return 0;
        else
            return 1;
    }
};
int page1()
{
    int ch;
    cout << "1.Staff" << endl;
    cout << "2.Tourist" << endl;
    cout << "3.Exit" << endl;
    cout << "Enter your choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
        staff();
        break;
    case 2:
        tourist();
        break;
    case 3:
        cout <<endl<< "Visit again.........." << endl;
        cout<<"............Thank you"<<endl;
        return 0;
        break;
    default:
        cout << "Invalid choice " << endl;
        page1();
        break;
    }
}

void staff()
{
    int ch;
    cout << endl;
    cout << "1.Create new account" << endl;
    cout << "2.Login" << endl;
    cout << "3.Back to page1" << endl;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    Staff s;
    switch (ch)
    {
    case 1:
        s.getdata();
        if (!s.checkdata())
            s.newdata();
        else
            cout << "User account is already in use" << endl;
        staff();
        break;
    case 2:
        s.getdata();
        if (s.checkdata())
        {
            cout << "Login successfull..." << endl;
            page2();
        }
        else
        {
            cout << "Invalid username or password." << endl;
            staff();
        }
        break;
    case 3:
        page1();
        break;
    default:
        cout << "Invalid choice" << endl;
        staff();
        break;
    }
}
void showbr()
{
    fstream file;
    string x;
    file.open("b_route.txt", ios::in);
    cout << endl
         << "...................................." << endl;
    cout << "Starting\tEnding\t\tSeats" << endl;
    cout << "...................................." << endl;
    while (getline(file, x))
    {
        cout << x << endl;
    }
    cout << "...................................." << endl;
    file.close();
}
void page2()
{
    int ch;
    fstream file;
    string name, num, bs, x;
    cout << endl;
    cout << "1.Add Bus Driver" << endl;
    cout << "2.Show driver list" << endl;
    cout << "3.Add Bus route" << endl;
    cout << "4.Show Bus routes" << endl;
    cout << "5.Back to login page" << endl;
    cout << "Enter your choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
        file.open("dlist.txt", ios::app);
        cout << "Enter driver name:";
        cin >> name;
        cout << "Enter mobile number:";
        cin >> num;
        cout << "Enter bus route:";
        cin >> bs;
        if (!checkpoint(bs))
        {
            cout << "Bus route is not available" << endl;
            page2();
        }
        file << name << "\t\t" << num << "\t" << bs << endl;
        file.close();
        cout << "Driver details added sucessfully" << endl;
        page2();
        break;

    case 2:
        file.open("dlist.txt", ios::in);
        cout << endl
             << ".........................................." << endl;
        cout << "Driver\t\tMoblie\t\tBus route" << endl;
        cout << ".........................................." << endl;
        while (getline(file, x))
        {
            cout << x << endl;
        }
        cout << ".........................................." << endl;
        file.close();
        page2();
        break;

    case 3:
        int seats;
        char fcity[50], tcity[50];
        file.open("b_route.txt", ios::app);
        cout << "Enter Bus starting point:" << endl;
        cin >> fcity;
        cout << "Enter Bus ending point:" << endl;
        cin >> tcity;
        cout << "Enter Number of seats:" << endl;
        cin >> seats;
        file << fcity << "\t\t" << tcity << "\t\t" << seats << endl;
        file.close();
        page2();
        break;

    case 4:
        showbr();
        page2();
        break;
    case 5:
        staff();
        break;
    default:
        cout << "Invalid choice" << endl;
        page2();
        break;
    }
}

void tourist()
{
    int ch;
    cout << endl;
    cout << "1.Create new account" << endl;
    cout << "2.Login" << endl;
    cout << "3.Back to page1" << endl;
    cout << "Enter your choice:" << endl;
    fflush(stdin);
    cin >> ch;
    passenger y;
    switch (ch)
    {
    case 1:
        y.getdata();
        if (!y.checkdata())
            y.newdata();
        else
            cout << "User account is already in use" << endl;
        tourist();
        break;

    case 2:
        y.getdata();
        if (y.checkdata())
        {
            cout << "Login Successful..." << endl;
            page3();
            break;
        }
        else
        {
            cout << "Invalid username or password." << endl;
            tourist();
        }
        break;

    case 3:
        page1();
        break;

    default:
        cout << "Invalid choice" << endl;
        tourist();
        break;
    }
}
bool checkpoint(string y)
{
    fstream d;
    string x;
    int count = 0;
    d.open("b_route.txt", ios::in);
    while (1)
    {
        d >> x;
        if (d.eof())
            break;
        if (x == y)
            count += 1;
    }
    if (count == 0)
        return 0;
    else
        return 1;
}
void page3()
{
    int ch;
    fstream file;
    string x, name, num;
    string bp, de;
    cout << endl;
    cout << "1.Show bus routes" << endl;
    cout << "2.Book a seat" << endl;
    cout << "3.Show bookings" << endl;
    cout << "4.Back to login page" << endl;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        showbr();
        page3();
        break;
    case 2:
        showbr();
        file.open("register.txt", ios::app);
        cout << "Enter name to book a seat:" << endl;
        cin >> name;
        cout << "Enter mobile number:" << endl;
        cin >> num;
        cout << "Enter boarding point:" << endl;
        cin >> bp;
        if (!checkpoint(bp))
        {
            cout << "Entered boarding point is not available" << endl;
            page3();
        }
        cout << "Enter destination:" << endl;
        cin >> de;
        if (!checkpoint(de))
        {
            cout << "Entered destination point is not available" << endl;
            page3();
        }
        file << name << "\t" << num << "\t" << bp << "\t" << de << endl;
        cout << endl
             << "........................................." << endl;
        cout << "Name\t Mobile\t\tFrom\t To" << endl;
        cout << endl
             << "........................................." << endl;
        cout << name << "\t " << num << "\t" << bp << "\t " << de << endl;
        cout << endl
             << "........................................." << endl;
        cout << "Ticket Booked Sucessfully...." << endl;
        file.close();
        page3();
        break;
    case 3:
        file.open("register.txt", ios::in);
        cout << endl
             << "........................................." << endl;
        cout << "Name\t Mobile\t\tFrom\t To" << endl;
        cout << endl
             << "........................................." << endl;
        while (getline(file, x))
        {
            cout << x << endl;
        }
        cout << endl
             << "........................................." << endl;
        file.close();
        page3();
        break;
    case 4:
        tourist();
        break;
    default:
        cout << "Invalid choice" << endl;
        page3();
        break;
    }
}
int main()
{
    cout << "\t\t\t WELCOME TO TOURISM MANAGEMENT\t\t\t" << endl;
    page1();

    return 0;
}