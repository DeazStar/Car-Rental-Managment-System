#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <stdbool.h>

using namespace std;

struct Car
{
    char manufacture[40];
    char model[40];
    int price, quantity, reg_no;
};

void signup_user();
void login_user(bool &access);
void addcar();
void showcar();
void deletecar();
void deleteblock(int num);

int idx = 0;
string usrfirstname, usrlastname, usremail;
string username_admin = "admin", admin_password = "1234";
int main()
{
    fstream logsfile;

    bool access = false;

    int age, user_input;
     cout << "\n\n" ;
    cout << "\t\t Welcome to DeadStar Car Rental" << endl;
    cout << "\t\t************************************"<< endl;
    cout << setw(30) << "         1. Admin Login " << endl;
    cout << setw(39) << "2. User Log in / Sign up" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n";
    cout << "\t\t\t Enter your choice -> ";
    cin >> user_input;

    if(user_input == 1)
    {
        string username_input, input_password;
        retry:
        cout << "\t\t************************************"<< endl;
        cout << setw(32) << "Login" << endl;
        cout << "\t\t************************************"<< endl;
        cout << "\n";
        cout << "\t\tEnter your Username: ";
        cin >> username_input;
        cout << "\n";
        cout << "\t\tEnter Password: ";
        cin >> input_password;

        if(username_input == username_admin && input_password == admin_password)
        {
            adminmenu:
            cout << "\t\t************************************"<< endl;
            cout << setw(40) << "Welcom Admin" << endl;
            cout << "\t\t************************************"<< endl;
            cout <<"\t\t-------------------------------------"<<endl;
            cout <<"\t\t|"<<setw(33)<<"1. Add Cars                |"<<endl;
            cout <<"\t\t|"<<setw(33)<<"2. View Cars               |"<<endl;
            cout <<"\t\t|"<<setw(33)<<"3. Delete Cars             |"<<endl;
            cout <<"\t\t|"<<setw(33)<<"4. Update Cars             |"<<endl;
            cout <<"\t\t|"<<setw(33)<<"5. Exit                    |"<<endl;
            cout <<"\t\t-------------------------------------"<<endl;
            cout << "\n\t\tEnter your choice -> ";
            cin >> user_input;

            switch(user_input)
            {
                case 1:
                    addcar();
                    goto adminmenu;
                    break;
                case 2:
                    showcar();
                    goto adminmenu;
                    break;
                case 3:
                    deletecar();
                    goto adminmenu;
                    break;
                    
            }

        }
        else
        {
            cout << "\t\tAccess Denied" << endl;
            cout << "\n\t\tPress 1 to retry, Press any key to exit... ";
            cin >> user_input;

            if(user_input == 1)
            {
                goto retry;
            }
            else
            {
                exit(1);
            }
        }
    }

    manu:
    cout << "\n\n" ;
    cout << "\t\t Welcome to DeadStar Car Rental" << endl;
    cout << "\t\t************************************"<< endl;
    cout << setw(30) << "1. Log in " << endl;
    cout << setw(30) << "2. Sign up" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n";
    cout << "\t\t\t Enter your choice -> ";
    cin >> user_input;

    switch(user_input)
    {
        case 1:
           login_user(access);

           if(access == true)
           {
                cout << "Access Granted " << endl;
           }
           else
           {
                goto manu;
           }
            break;
        case 2:
            signup_user();
            break;
        default:
            cout << "\t\tPlease Enter the correct input... "<<endl;
    }

    return 0;

}

void signup_user()
{
    int user_input;

    fstream signups;

    string first_name, last_name, username, email, password;
    
    int age;

    string usr;

    cout <<'\n';
    cout << "\t\t************************************"<< endl;
    cout << setw(32) << "Sign Up" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n";
    cout << "\t\tEnter your first name: ";
    cin >> first_name;
    cout << "\n";
    cout << "\t\tEnter your last name: ";
    cin >> last_name;
    cout << "\n";
    cout << "\t\tEnter your Email: ";
    cin >> email;
    cout << "\n";
    retry:
    cout << "\t\tEnter user name: ";
    cin >> username;
    cout << "\n";
    cout <<"\t\tEnter password: ";
    cin >> password;

    signups.open("logsfile.txt", ios::in);

    if(signups.is_open() == false)
    {
        cout << "\t\t Unable to access the file at the moment please try again later! " << endl;

    }
    else
    {
        while(getline(signups, usr))
        {
            if(username == usr)
            {
                cout << "\n";
                cout << "\t\tThis username is already taken!" << endl;
                cout << "\n";
                cout << "\t\ttry anoter username" << endl;
                cout << "\n";
                cout << "\t\tpress 1 to try again. press anyother key to exit... ";
                cin >> user_input;

                if(user_input == 1)
                {
                    goto retry;
                    cout << "\n";
                }
                else
                {

                }
            }
            else
            {
                idx++;
            }
        }
        
    }

    idx++;

    signups.close();

    signups.open("logsfile.txt", ios::app);

    if(!signups.is_open())
    {
        cout << "\t\t Unable to access the file at the moment please try again later! " << endl;

    }
    else
    {
        signups << username << " " << first_name << " "<< last_name << " "<< email << " " << password << " " << idx << "\n";
    }
  
    signups.close();


}

void login_user(bool &access)
{
    string username, password,usr, usrname ,usrpassword;

    int user_input;

    int k = 0;

    fstream logs;

    cout << "\t\t************************************"<< endl;
    cout << setw(32) << "Login" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n";
    retry: 
    cout << "\t\tEnter your Username: ";
    cin >> username;
    cout << "\n";
    cout << "\t\tEnter Password: ";
    cin >> password;

    logs.open("logsfile.txt", ios::in);

    if(!logs.is_open())
    {
        cout << "\t\t Unable to access the file at the moment please try again later! " << endl;
    }
    else
    {
        while(logs.eof() == false)
        {
            logs >> usrname;
            if(usrname == username)
            {   
                logs >> usrfirstname;
                logs >> usrlastname;
                logs >> usremail;
                logs >> usrpassword;
                logs >> idx;

                if(password == usrpassword)
                {
                    access = true;
                }
            }
        }
    }

    if(access == false)
    {
        cout << '\n';
        cout << "\t\tpassword or username incorrect" << endl;
        cout << '\n';
        cout << "\t\tPress 1 to try again, Press any key to exit... ";
        cin >> user_input;
        cout << '\n';

        if(user_input == 1)
        {
            goto retry;
        }
    }

    logs.close();

}

void addcar()
{
    char user_input[20];

    Car car_info;

    fstream carfile;

    int no, length;

    int additional, position;
    cout << "\t\t------------------------------------"<< endl;
    cout << setw(32) << "Add Cars" << endl;
    cout << "\t\t------------------------------------"<< endl;
    cout << "\n\t\tEnter RegNo: ";
    cin >> no;

    carfile.open("cars.dat", ios::binary|ios::in|ios::out);

    carfile.seekg(0, ios::end);
    length = carfile.tellg();

    if(length == 0)
    {
        carfile.close();
        goto addinfo;
    }
    else
    {
        carfile.seekg(0, ios::beg);
    }

    if(carfile.is_open() == false)
    {
        cout << "Unable to access the file!... ";
        
    }
    else
    {
        while(carfile.read(reinterpret_cast<char *>(&car_info), sizeof(Car)))
        {
            if (no == car_info.reg_no)
            {
                cout << "\t\tCar aleady exit... " << endl;
                cout <<"\t\tDo you want to increase the qunatity(y/n).... ";
                cin >> user_input;
                char yes[2] = "y";
                if(strcasecmp(user_input, yes) == 0)
                {
                    cout << "\n\t\tEnter Quantity: ";
                    cin >> additional;
                    car_info.quantity +=  additional;
                    position = (-1) * static_cast<int> (sizeof(car_info));
                    carfile.seekp(position, ios::cur);
                    carfile.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                goto addinfo;
            }
        }
    }

    carfile.close();

    goto end;

    addinfo:
    carfile.open("cars.dat", ios::binary|ios::app);
    
    car_info.reg_no = no;
    cin.ignore();
    cout << "\n\t\tEnter Manufacturer: ";
    cin.getline(car_info.manufacture, 40);
    cout << "\n\t\tEnter Mode: ";
    cin.getline(car_info.model, 40);
    cout << "\n\t\tEnter Quantity: ";
    cin >> car_info.quantity;
    cout << "\n\t\tEnter Price: ";
    cin >> car_info.price;

    carfile.write(reinterpret_cast<char *>(&car_info), sizeof(Car));

    carfile.close();

    end:
    cout << "\n" << endl;


}

void showcar()
{
    char user_input[20];
    Car car_view;
    fstream view_cars;
    cout << "\t\t------------------------------------"<< endl;
    cout << setw(32) << "View Cars" << endl;
    cout << "\t\t------------------------------------"<< endl;

    view_cars.open("cars.dat", ios::binary|ios::in);

 if(!view_cars.is_open())
    {
        cout << "\n\t\tUnable to access the file at the moment...!";
        exit(1);
    }
    else
    { 
        cout << "\n";
        cout <<"\t\t----------------------------------------------------------------------------------" << endl;
        cout << "\t\t   RegNo  |    Manufacture      |       Model       |     quantity   |   Price   |" << endl;
        cout <<"\t\t----------------------------------------------------------------------------------" << endl;
        while(view_cars.read(reinterpret_cast<char *>(&car_view), sizeof(Car)))
        {  
            cout << "\t\t      " <<car_view.reg_no << setw(15) << car_view.manufacture << setw(25) << car_view.model << setw(15) << car_view.quantity << setw(15) << car_view.price << endl;

        }
        cout <<"\t\t----------------------------------------------------------------------------------" << endl;

    }

    view_cars.close();

    cout << "\n\t\tPress any key to continue... ";
    cin >> user_input;
}

void deletecar()
{
    int no, decrement, position;
    char user_input[20];
    fstream car_delete;
    Car car_info;

    cout << "\t\t------------------------------------"<< endl;
    cout << setw(32) << "Delete Cars" << endl;
    cout << "\t\t------------------------------------"<< endl;
    cout << "\n\t\tEnter RegNo: ";
    cin >> no;

    car_delete.open("cars.dat", ios::binary|ios::in|ios::out);

    if(car_delete.is_open() == false)
    {
        cout << "\t\tUnable to access the file at the moment... "<<endl;
        cin >> user_input;
    }
    else
    {
        while(car_delete.read(reinterpret_cast<char *>(&car_info), sizeof(Car)))
        {
            if(no == car_info.reg_no)
            {
                cout << "\n\t\tEnter Quantity: ";
                cin >> decrement;
                car_info.quantity -= decrement;
                if(car_info.quantity == 0)
                {
                    deleteblock(car_info.reg_no);
                }
                else
                {
                    position = -1 * static_cast<int>(sizeof(car_info));
                    car_delete.seekg(position, ios::cur);
                    car_delete.write(reinterpret_cast<char *>(&car_info), sizeof(Car));  
                }

            }
        }
    }


}

void deleteblock(int num)
{
    fstream transfer, temp;
    Car car_info;

    transfer.open("cars.dat", ios::binary|ios::in);
    temp.open("temp.dat", ios::binary|ios::app);

    if(transfer.is_open() == false && temp.is_open() == false)
    {
        cout << "\n\t\tError Deleting a file.... " << endl;
        exit(1);
    }
    else
    {
        while(transfer.read(reinterpret_cast<char *>(&car_info), sizeof(Car)))
        {
            if(car_info.reg_no == num)
            {
                continue;
            }
            else
            {
              temp.write(reinterpret_cast<char *>(&car_info), sizeof(Car));  
            }
        }
    }
    transfer.close();
    remove("cars.dat");
    temp.close();
    rename("temp.dat", "cars.dat");
}