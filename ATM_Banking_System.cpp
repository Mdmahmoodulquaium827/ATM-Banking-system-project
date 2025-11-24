#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

class registration
{
    public:
    vector<pair<string,string>>data;
    vector<vector<string>>statement;
    string userName;
    string pin;
    string temp;
    vector<double>balance;
    int lock=0;
    void get_user_info()
    {
        cout<<"Enter UserName: ";
        cin>>userName;
        cout<<"Enter Pin: ";
        cin>>pin;
        cout<<"\033[32mRegistration complete!!!!!\033[0m\n";
        data.emplace_back(userName,pin);
        temp="\033[36mUser has registered for\033[0m \033[33mSTAMFORD BANK\033[0m\n";
        statement.push_back({temp,"Balance 0.0 has been assigned for user"});

        balance.push_back(0.0);
    }

    void login()
    {

        double amount;
        int choice;
        string newPin;
        string input;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        cout<<"Enter User Name: ";
        cin>>userName;
        cout<<"Enter Pin: ";
        cin>>pin;

        for(int i=0; i<data.size(); i++)
        {

            if(userName==data[i].first&&pin==data[i].second)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout<<"Log in Success"<<endl;
                while(1)
                {
                    lock=0;

                    cout << "\033[35m\n--- ATM Menu ---\n\033[0m\n";
                    cout <<"\033[33m1. Balance Inquiry\n2. Deposit\n3. Withdraw\n4. Change PIN\n5. Mini Statement\n6. Logout\n\033[0m\n" ;
                    cout << "\033[37mEnter choice\033[0m: ";
                    cin >> choice;


                    switch(choice)
                    {

                    case 1:
                        cout<< "Total Balance is :"<<balance[i]<<endl;
                        break;

                    case 2:
                        cout<< "Enter your Deposit amount : ";
                        cin>> amount;

                        temp="Deposited ";
                        temp=temp+to_string(amount);
                        statement[i].push_back({temp});

                        try
                        {
                            if(amount<=0)
                            {

                                throw string("\033[31mInvalid Amount\033[0m");
                            }
                            balance[i]=balance[i]+amount;
                            cout<<"\033[32mYour Deposit is successful\033[0m";
                        }
                        catch(string s)
                        {
                            cout<<s<<endl;
                        }

                        break;
                    case 3:
                        cout<< "Enter your Withdraw amount : ";
                        cin>> amount;
                        temp="Withdrew ";
                        temp=temp+to_string(amount);
                        statement[i].push_back({temp});
                        try
                        {
                            if(amount<=0 || balance[i]<amount)
                            {
                                throw string("\033[31mInvalid Amount\033[0m");
                            }
                            balance[i]-=amount;
                            cout<<"\033[32mYour Withdraw is successful\033[0m";
                        }
                        catch (string s)
                        {
                            cout<<s<<endl;
                        }
                        break;
                    case 4:
                        cout<< "Do you want to change your PIN Number ?"<<endl;
                        cout<< "\033[36mYes or No\033[0m\n"<<endl;
                        cin>> input;
                        if(input=="yes"||input=="YES"||input=="Yes")
                        {
                            cout<< "Enter your Old pin :";
                            cin>>pin;
                            if(pin==data[i].second)
                            {
                                cout<< "Enter a new pin:";
                                cin>>newPin;
                                data[i].second=newPin;
                                cout<< "\033[32mPIN has been changed\033[0m\n"<<endl;

                            }
                            else
                            {
                                cout<< "\033[31mPin has not matched\033[0m\n"<<endl;
                            }

                        }
                        else
                        {
                            cout<<"\033[45mThank you\033[0m\n"<<endl;
                        }
                        break;
                    case 5:
                        cout<< "\033[36mPrinting statements----\033[0m\n"<<endl;
                        for(int j=0; j<statement[i].size(); j++)
                        {
                            cout<<statement[i][j]<<endl;
                        }
                        break;
                    case 6:
                        cout<<"\033[32mLog out successful\033[0m\n";
                        lock=1;
                        goto endLoop;
                        break;

                    }
                    if(lock==1)
                    {
                        endLoop:
                        break;
                    }
                }

            }
            else if(userName!=data[i].first && pin==data[i].second)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout<<"Wrong User Name "<<endl;

            }
            else if(userName==data[i].first && pin!=data[i].second)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout<<"Wrong User PIn "<<endl;

            }

        }

    }


    void adminView()
    {
        cout<<"\033[33mThe Registered users are.....\033[0m\n"<<endl;

        for(int i=0;i<data.size();i++)
        {

                cout<<"\033[33mUSER--\033[0m "<<i+1<<" "<<data[i].first<<" " <<"\t\033[33mBalance--\033[0m "<<balance[i]<<endl;
        }

    }

};




int main()
{

    registration r1;

    char ch;

    while (true)
    {

        cout << "\033[35m\n--- Welcome to C++ ATM ---\n\033[0m\n";

        cout << "\033[36m1. Register\n2. Login\n3. Admin View\n4. Exit\n \033[0m\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
            case '1':
                r1.get_user_info();

                break;
            case '2':
                r1.login();
                break;
            case '3':
                r1.adminView();
                break;
            case '4':
                exit(0);
            default:
                cout << "Invalid input.\n";
                break;
        }
    }
}
