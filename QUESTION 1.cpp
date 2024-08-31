#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

void login();
void registration();
void forgot();
void atmOperations(double &balance);  // Function declaration for ATM operations

int main()
{
    int c;
    cout<<"\t\t\t                              NEVER GIVE UP                                                            \n\n\n";
    cout<<"                        Hi! Welcome to ATM machine   \n\n\n";
    cout<<" 1 LOGIN                         "<<endl;
    cout<<" 2 CREATE A NEW ACCOUNT                    "<<endl;
    cout<<" 3 if you forgot your PASSWORD      "<<endl;
    cout<<" 4 EXIT                          "<<endl;
    cout<<"   Please enter your choice: ";
    cin>>c;
    cout<<endl;
    

    switch(c){
        case 1:
            login();
            break;

        case 2:  
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"  Thank you! \n\n"<<endl;
            break;

        default:
            cout<<"Please select a valid option from the menu.\n";
            main();
    }

    return 0;
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    double balance = 0.0;  // Variable to keep track of the user's balance
    
    

    cout<<"\t\t\t Please enter your username and password"<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<" PASSWORD: ";
    cin>>password;

    ifstream input("records.txt");


    while(input >> id >> pass)
    {
        if(id == userId && pass == password)
        {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\nYour LOGIN is successful\nThanks for logging in!\n";
        atmOperations(balance);  // Call the ATM operations after successful login
    }
    else
    {
        cout << "\nLOGIN ERROR \nPlease check your username and password\n";
        main();  // Return to the main menu on a failed login attempt
    }
}

void atmOperations(double &balance)
{
    int option;
    double amount;

    while (true) {
        cout << "                                     Select an option:" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: // Deposit Money
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Amount deposited successfully. New balance: Ugx" << balance << endl;
                } else {
                    cout << "Please enter a positive amount." << endl;
                }
                break;
            
            case 2: // Withdraw Money
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Error: Enter the amount less than or equals the account balance." << endl;
                } else if (amount > 0) {
                    balance -= amount;
                    cout << "Amount withdrawn successfully. New balance: Ugx" << balance << endl;
                } else {
                    cout << "Please enter a positive amount." << endl;
                }
                break;

            case 3: // Exit
                cout << "Exiting the program. Thank you!" << endl;
                return;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}

void registration()
{
    string ruserId, rpassword;
    system("cls");
    cout<<" Enter the username: ";
    cin>>ruserId;
    cout<<" Enter the password: ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    if(!f1) {
        cout << "Error: Please try later.\n";
        return;
    }
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout<<"  Congratulations, Your account has been created!\n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<" You forgot your password, No worries!\n";
    cout<<" 1 Search your ID by username\n";
    cout<<" 2 Go back to the menu\n";
    cout<<" Enter your choice: ";
    cin>>option;

    switch(option){
        case 1:
        {
            int count = 0;
            string suserId, sId, spass;
            cout<<" Enter your username : ";
            cin>>suserId;

            ifstream f2("records.txt");
            if(!f2) {
                cout << "Error, please try again.\n";
                return;
            }

            while(f2 >> sId >> spass)
            {
                if(sId == suserId)
                {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if(count == 1)
            {
                cout<<"\n\nYour account is found!\n";
                cout<<"\nYour password is: " << spass << endl;
            }
            else
            {
                cout<<"\nSorry, your account is not found!\n";
            }
            main();
            break;
        }
        case 2:
        {
            main();
            break;
        }
        default:
            cout<<" Wrong choice! Please try again.\n";
            forgot();
    }
}
