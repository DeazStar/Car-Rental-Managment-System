#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <stdbool.h>
#include <ctime>

using namespace std;

char nowuser[50];

struct Car
{
    char manufacture[40];
    char model[40];
    int price, quantity, reg_no;
};

struct Customer
{
    char user_name[50];
    char first_name[50];
    char last_name[50];
    char email[50];
    char password[50];
};

struct temp
{
    char usremail[50];
    char usrpassword[50];
    char usrname[50];
};

struct tmpcar
{
    char tmpmanufacture[40];
    char tmpmodel[40];
};

int convert(char *);
void signup_user();
void login_user(bool &access);
void addcar();
void showcar();
void deletecar();
void deleteblock(int num);
void updatecar();
void current_time();
void rentcar();
void searchcar();
void rent();

int idx = 0;
string usrfirstname, usrlastname, usremail;
string username_admin = "admin", admin_password = "1234";
int main()
{
    fstream logsfile;

    bool access = false;

    int age, user_input;

    char input;

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
                case 4:
                    updatecar();
                    goto adminmenu;
                    break;
                case 5:
                    askagain:
                    cout << "\n\t\tAre you sure you want to exit the program(y/n)... ";
                    cin >> input;
                    if(input == 'Y' || input == 'y' )
                    {
                        exit(1);
                    }
                    else if (input == 'N' || input == 'n')
                    {
                        goto adminmenu;
                    }
                    else
                    {
                        cout << "\n\t\tEnter the correct input... " << endl;
                        goto askagain;
                    }

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
                cout << "\t\t************************************"<< endl;
                cout << setw(40) << "Welcom to DeadStar Car Rental" << endl;
                cout << "\t\t************************************"<< endl;
                cout <<"\t\t-------------------------------------"<<endl;
                cout <<"\t\t|"<<setw(33)<<"1. Rent Cars               |"<<endl;
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
                        rentcar();
                }
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


int convert(char *str)
{
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        
        sum += int(str[i]);
    }

    return sum;
}

void signup_user()
{
    Customer user_info;

    temp tmp;

    fstream signups;

    int length;

    int input;
    signups.open("logsfile.dat", ios::binary|ios::in|ios::out);
    
    cout <<'\n';
    cout << "\t\t************************************"<< endl;
    cout << setw(32) << "Sign Up" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n"; 
    cout << "\n";
    cout << "\t\tEnter your first name: ";
    cin >> user_info.first_name;
    cout << "\n";
    cout << "\t\tEnter your last name: ";
    cin >> user_info.last_name;
    cout << "\n";
    retry: 
    cout << "\t\tEnter your Email: ";
    cin >>tmp.usremail;
    cout << "\n";
    usrretry:
    cout << "\t\tEnter user name: ";
    cin >>  tmp.usrname;
    cout << "\n";
    cout <<"\t\tEnter password: ";
    cin >> user_info.password;

    

    signups.seekg(0, ios::end);
    length = signups.tellg();

    if(length == -1 || length == 0)
    {
        signups.close();
        goto finish;
    }
    else
    {
        signups.seekg(ios::beg);
    }
    if(signups.is_open() == false)
    {
        cout << "\t\t Unable to access the file at the moment please try again later! " << endl;
    }
    else
    {
        while(signups.read(reinterpret_cast<char *>(&user_info), sizeof(Customer)))
        {
            if(convert(user_info.email) == convert(tmp.usremail))
            {
                cout << "\n";
                cout << "\t\tThis email is already registered\n"<<endl;
                cout << "\t\tPress 1 to try again. press any other key to go back... ";
                cin >> input;
                cout << "\n";

                if(input == 1)
                {
                    goto retry;
                }
                else
                {
                    goto exit;
                }
            }
            else if(convert(user_info.user_name)== convert(tmp.usrname))
            {
                cout << "\n";
                cout << "\t\tThis username is already taken!\n"<<endl;
                cout << "\t\tPress 1 to try again. press any other key to go back... ";
                cin >> input;

                if(input == 1)
                {
                    goto usrretry;
                }
                else
                {
                    goto exit;
                }
            }
            else
            {   signups.close();
                goto finish;
            }
        }
    }

    

    finish:

    signups.open("logsfile.dat", ios::binary|ios::app);
    for(int i = 0; i < strlen(tmp.usrname); i++)
    {
        user_info.user_name[i] = tmp.usrname[i];
    }
    for(int i = 0; i < strlen(tmp.usremail); i++)
    {
        user_info.email[i] = tmp.usremail[i];
    }
    signups.write(reinterpret_cast<char *>(&user_info), sizeof(Customer));
    exit:
    signups.close();  

}


void login_user(bool &access)
{
    fstream logs;

    int input;

    int length;

    temp tmp;

    Customer user_info;
    
    logs.open("logsfile.dat", ios::binary|ios::in);

    cout << "\t\t************************************"<< endl;
    cout << setw(32) << "Login" << endl;
    cout << "\t\t************************************"<< endl;
    cout << "\n";
    retry:
    if(logs.tellp() == -1)
    {
        logs.close();
        logs.open("logsfile.dat", ios::binary|ios::in);
    }
    cout << "\t\tEnter username: ";
    cin >> tmp.usrname;
    cout << "\n\t\tEnter Password: ";
    cin >> tmp.usrpassword;

    if(logs.is_open() == false)
    {
        cout << "\t\t Unable to access the file at the moment please try again later! " << endl;
    }
    else
    {
        while(logs.read(reinterpret_cast<char *>(&user_info), sizeof(Customer)))
        {
            if(convert(tmp.usrname) == convert(user_info.user_name))
            {
                if(convert(tmp.usrpassword) == convert(user_info.password))
                {
                    access = true;
                    for(int i = 0; i < strlen(user_info.password); i++)
                    {
                        user_info.user_name[i] = nowuser[i];
                    }
                    logs.close();
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
        cin >> input;
        cout << '\n';

        if(input == 1)
        {
            goto retry;
        } 
        else
        {
            goto exit;
        }
    }

    exit:
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

    if(length == -1 || length == 0)
    {
        carfile.close();
        goto addinfo;
    }
    else
    {
        carfile.seekg(ios::beg);
        length = carfile.tellg();
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
                carfile.close();
                goto addinfo;
            }
        }
    }

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

void updatecar()
{
    int no;

    Car car_info;

    char user_input[20];

    int input;

    int position;

    fstream car_update;

    cout << "\t\t------------------------------------"<< endl;
    cout << setw(32) << "Update Cars" << endl;
    cout << "\t\t------------------------------------"<< endl;
    cout << "\n\t\tEnter RegNo: ";
    cin >> no;

    car_update.open("cars.dat", ios::binary|ios::in|ios::out);

    if(car_update.is_open() == false)
    {
        cout << "\n\t\tUnable to access the file at the moment... ";
        cin >> user_input;
    }
    else
    {
        while(car_update.read(reinterpret_cast<char *> (&car_info), sizeof(Car)))
        {
            if(no == car_info.reg_no)
            {
                cout <<"\n\t\tWhat do you want to edit:- " << endl;
                cout << "\n\t\t  1. RegNo"<<endl;
                cout << "\t\t  2. Manufacturer Name " << endl;
                cout << "\t\t  3. Model" << endl;
                cout << "\t\t  4. Quantity " << endl;
                cout << "\t\t  5. Price " << endl;
                cout << "\t\t  6. all " << endl;

                cout << "\n\t\t Enter your choice:-> " << endl;
                cin >> input;

                switch(input)
                {
                    case 1:
                        cout << "\n\t\t Enter the new RegNo: ";
                        cin >> car_info.reg_no;
                        position = (-1) * static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                        break;
                    case 2:
                        cout << "\n\t\t Enter the the new Manufacturer Name: ";
                        cin >> car_info.manufacture;
                        position = (-1) * static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                        break;
                    case 3:
                        cout << "\n\t\t Enter the new Model: ";
                        cin >> car_info.model;
                        position = (-1)*static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                        break;
                    case 4:
                        cout << "\n\t\t Enter the new Quantity: ";
                        cin>> car_info.quantity;
                        position = (-1)*static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                        break;
                    case 5:
                        cout << "\n\t\t Enter the new Price: ";
                        cin >> car_info.price;
                        position = (-1)*static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                        break;
                    case 6:
                        cout << "\n\t\t Enter the new RegNo: ";
                        cin >> car_info.reg_no;
                        cout << "\n\t\t Enter the the new Manufacturer Name: ";
                        cin >> car_info.manufacture;
                        cout << "\n\t\t Enter the new Model: ";
                        cin >> car_info.model;
                        cout << "\n\t\t Enter the new Quantity: ";
                        cin>> car_info.quantity;
                        cout << "\n\t\t Enter the new Price: ";
                        cin >> car_info.price;
                        position = (-1)*static_cast<int> (sizeof(car_info));
                        car_update.seekp(position, ios::cur);
                        car_update.write(reinterpret_cast<char *>(&car_info), sizeof(Car));
                    default:
                        cout << "\n\t\t Enter the correct input... ";
                        exit(1); // to be edited;


                }
            }
        }
    }
}

void current_time()
{
    time_t t= time(NULL);
    tm* tPtr = localtime(&t);
    cout << (tPtr->tm_mday) << "/" <<(tPtr->tm_mon)+1 <<"/"<<(tPtr->tm_year)+1900<<endl;
}

void searchcar()
{
    tmpcar car;
    Car car_list;
    fstream carfile;

    cout << "\n\t\tEnter car manufacturer: ";
    cin.ignore();
    cin.getline(car.tmpmanufacture, 40);
    cout << "\n\t\tEnter car model: ";
    cin.getline(car.tmpmodel, 40);

    carfile.open("cars.dat", ios::binary|ios::in);

    if(!carfile.is_open())
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
        while(carfile.read(reinterpret_cast<char *>(&car_list), sizeof(Car)))
        {
            if(convert(car_list.manufacture) == convert(car.tmpmanufacture) && convert(car_list.model) == convert(car.tmpmodel))
            {
                cout << "\t\t      " <<car_list.reg_no << setw(15) << car_list.manufacture << setw(25) << car_list.model << setw(15) << car_list.quantity << setw(15) << car_list.price << endl;
            }
        }
        cout <<"\t\t----------------------------------------------------------------------------------" << endl;
    }

}

void rent()
{
    cout << "\n\t\tEnter the RegNo: ";
}

void rentcar()
{
    int input;

    cout << "\t\t------------------------------------"<< endl;
    cout << setw(32) << "Rent a car" << endl;
    cout << "\t\t------------------------------------"<< endl;
    cout << "\n\t\tPress 1 to search for a car and rent it"<<endl;
    cout << "\n\t\tPress 2 to display the available cars and rent one"<<endl;
    cout << "\n\t\tEnter your choice -> ";
    cin >> input;

    switch (input)
    {
    case 1:
        searchcar();
        break;
    
    case 2:
        showcar();
        rent();
        break;
    }

}