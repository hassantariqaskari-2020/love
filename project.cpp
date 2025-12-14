#include<iostream>
#include<fstream>
using namespace std;
void roleSelection();
void admin();
void adminMENUE();
void userMenu();
void userLogin();
void login();
void registration();
void forgot();
void fuelSystem();
void recordFuelSale();
void generateEReceipt();
void updateFuelPrices();
void staffManagement();
void dailyFuelSummary();
void systemLogs();
void logoutFunction();
void exitProgram();
int main()
{
    roleSelection();
    return 0;
}
void roleSelection()
{
    int role;
    system("cls");
    cout<<"|===============================================|\n";
    cout<<"|          FUEL STATION MANAGEMENT SYSTEM       |\n";
    cout<<"|===============================================|\n";
    cout<<"|               SELECT ROLE                    |\n";
    cout<<"|===============================================|\n";
    cout<<"1) Admin\n";
    cout<<"2) User\n";
    cout<<"3) Exit\n";
    cout<<"Enter choice: ";
    cin>>role;
    switch(role)
    {
        case 1:
            adminMENUE();  
            break;
        case 2:
            userLogin();  
            break;
        case 3:
            exitProgram();
            break;
        default:
            cout<<"Invalid choice.\n";
            roleSelection();
    }
}
void adminMENUE()
{
    int c;
    cout<<"|===============================================|\n";
    cout<<"|          FUEL STATION MANAGEMENT SYSTEM       |\n";
    cout<<"|===============================================|\n";
    cout<<"|-------------------ADMIN MENU------------------|\n";
    cout<<"|===============================================|\n";
    cout<<"|[1]Login [2]Register [3]Forgot Password [4]Exit|\n";
    cout<<"|===============================================|\n";
    cout<<"\t\tEnter choice:";
    cin>>c;
    cout<<endl;
    switch(c)
    {
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
            cout<<"\t\t\t THANK YOU\n\n";
            break;
        default:
            cout<<"\t\t\tPlease select from the options given below\n"<<endl;
            main();
            break;
    }
}
void userLogin()
{
    string user, pass, u, p;
    int found = 0;
    system("cls");
    cout<<"|===============================================|\n";
    cout<<"|               USER LOGIN                     |\n";
    cout<<"|===============================================|\n";
    cout<<"Username: ";
    cin>>user;
    cout<<"Password: ";
    cin>>pass;
    ifstream fin("records.txt");
    while(fin >> u >> p)
    {
        if(u == user && p == pass)
        {
            found = 1;
            break;
        }
    }
    fin.close();
    if(found)
    {
        cout<<"\nLogin Successful!\n";
        userMenu();
    }
    else
    {
        cout<<"\nInvalid Username or Password!\n";
        roleSelection();
    }
}

void userMenu()
{
    int choice;
    while(true)
    {
        system("cls");
        cout<<"|===============================================|\n";
        cout<<"|               USER PANEL                     |\n";
        cout<<"|===============================================|\n";
        cout<<"1) Generate e-Receipt\n";
        cout<<"2) Back\n";
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice == 1)
        {
            generateEReceipt();  
        }
        else if(choice == 2)
        {
            roleSelection();
            break;
        }
        else
        {
            cout<<"Invalid choice.\n";
        }
    }
}

void admin()
{
        cout<<"|===============================================|\n";
        cout<<"|              ADMIN DASHBOARD                 |\n";
        cout<<"|===============================================|\n";
        int option;
        cout<<"1) Fuel Inventory Status\n";
        cout<<"2) Record Fuel Sale\n";
        cout<<"3) Generate e-Receipt (Text)\n";
        cout<<"4) Update Fuel Prices\n";
        cout<<"5) Staff Management\n";
        cout<<"6) Daily Summary Report\n";
        cout<<"7) System Logs\n";
        cout<<"8) Logout\n";
        cout<<"9) Exit Program\n";
        cin>>option;
        switch(option)
        {
            case 1:
                fuelSystem();
                break;
            case 2:
                recordFuelSale();
                break;
            case 3:
                generateEReceipt();
                break;
            case 4:
                updateFuelPrices();
                break;
                break;
            case 5:
                staffManagement();
                break;
            case 6:
                dailyFuelSummary();
                break;
            case 7:
                systemLogs();
                break;
            case 8:
                logoutFunction();
                break;
            case 9:
                exitProgram();
                break;
        }
    }
void login()
{
    int count=0;
    string userID,password,id,pass;
    system("cls");
    cout<<"|===============================================|\n";
    cout<<"|          FUEL STATION MANAGEMENT SYSTEM       |\n";
    cout<<"|===============================================|\n";
    cout<<"|-------------WELCOME TO LOGIN PAGE-------------|\n";
    cout<<"|===============================================|\n";
    cout<<"Please enter the user name and password:"<<endl;
    cout<<"USERNAME______________:";
    cin>>userID;
    cout<<"PASSWORD______________:";
    cin>>password;
    ifstream file("records.txt");
    while(file>>id>>pass)
    {
        if(id==userID && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    file.close();
    if(count==1)
    {
        cout<<userID<<"\n YOUR login is successful\n Thanks for logging in\n";
        admin();
    }
    else
    {
        cout<<"\n LOGIN ERROR \n Please check Your username and password\n";
        main();
    }
}
void registration()
{
    string ruserId,rpassword;
    system("cls");
    cout<<"|===============================================|\n";
    cout<<"|          FUEL STATION MANAGEMENT SYSTEM       |\n";
    cout<<"|===============================================|\n";
    cout<<"|----------WELCOME TO Registration PAGE---------|\n";
    cout<<"|===============================================|\n";
    cout<<"Please register user name and password:"<<endl;
    cout<<"Username______________:";
    cin>>ruserId;
    cout<<"\nPassword______________:";
    cin>>rpassword;
    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<"\n"<<rpassword<<"\n";
    f1.close();
    system("cls");
    cout<<"\n\t Registration is successful!\n";
    main();
}
void forgot()
{
    int option;
    system("cls");
    cout<<"|===============================================|\n";
    cout<<"|          FUEL STATION MANAGEMENT SYSTEM       |\n";
    cout<<"|===============================================|\n";
    cout<<"|----------WELCOME TO Forgot PAGE---------------|\n";
    cout<<"|===============================================|\n";
    cout<<"\tYou forgot the password? No worries\n";
    cout<<"Press 1 to search your id by username:"<<endl;
    cout<<"Press 2 to go back to the MAIN MENU"<<endl;
    cout<<"\t\t Enter Choice:";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserID,sID,sPASS;
            cout<<"\nEnter the username which you have remembered:";
            cin>>suserID;
            ifstream f2("records.txt");
            while(f2>>sID>>sPASS)
            {
                if(sID==suserID)
                {
                    count=1;
                    break;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\nYour Account is found!\n";
                cout<<"Your PASSWORD IS:"<<sPASS<<endl;
                main();
            }
            else
            {
                cout<<"\n\tSorry! your account is not found!\n";
                main();
            }
        }
        break;
        case 2:
            main();
            break;
        default:
            cout<<"\t\t\t Wrong choice ! please try again..\n";
            forgot();
    }
}
class list
{
public:
    string fuel_type;
    int stock;
    float price;
};
void fuelSystem()
{
    int choice;
    while(true)
    {
        cout<<"|===============================================|\n";
        cout<<"              FUEL INVENTORY\n";
        cout<<"|===============================================|\n";
        cout<<"\n1. Add New Fuel Records\n";
        cout<<"2. View All Records\n";
        cout<<"3. Change/Update a Record\n";
        cout<<"4. back to main menue\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        system("cls");
        if(choice==1)
        {
            int Prices;
            list l[100];
            cout<<"How many records you want to add: ";
            cin>>Prices;
            ofstream fout("foul.txt",ios::app);
            for(int i=0;i<Prices;i++)
            {
                cout<<"Enter Fuel Type: ";
                cin>>l[i].fuel_type;
                cout<<"Enter Price: ";
                cin>>l[i].price;
                cout<<"Enter Stock: ";
                cin>>l[i].stock;
                fout<<l[i].fuel_type<<" "<<l[i].price<<" "<<l[i].stock<<"\n";
            }
            fout.close();
            system("cls");
            cout<<"Records Added Successfully.\n\n";
        }
        else if(choice==2)
        {
            ifstream fin("foul.txt");
            list l;
            cout<<"|===============================================|\n";
            cout<<"              FUEL INVENTORY\n";
            cout<<"|===============================================|\n";
            cout<<"Fuel Type | Price(PKR/L) | Stock(L)\n";
            cout<<"-----------------------------------------------\n";
            int totalPrice=0;
            int totalStock=0;
            while(fin>>l.fuel_type>>l.price>>l.stock)
            {
                cout<<l.fuel_type<<"\t | "<<l.price<<"\t | "<<l.stock<<"L\n";
                totalPrice += l.price;
                totalStock += l.stock;
            }
            fin.close();
            cout<<"-----------------------------------------------\n";
            cout<<"Totals: "<<totalPrice<<"   "<<totalStock<<"L\n";
            cout<<"Operator: Admin\n";
            cout<<"|-----------------------------------------------|\n";
        }
        else if(choice==3)
        {
            updateFuelPrices();
        }
        else if(choice==4)
        {
            admin();
        }
        else
        {
            break;
        }
    }
}
class Staff
{
public:
    int id;
    string name;
    string position;
};
void staffManagement()
{
    int choice;
    while (true)
    {
        cout << "\n\n==============================\n";
        cout << "       STAFF MANAGEMENT\n";
        cout << "==============================\n";
        cout << "1. Add Staff\n";
        cout << "2. View Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        if (choice == 1)
        {
            ofstream fout("staff.txt", ios::app);
            Staff s;
            cout << "\nEnter Staff ID: ";
            cin >> s.id;
            cin.ignore();
            cout << "Enter Staff Name: ";
            getline(cin, s.name);
            cout << "Enter Position: ";
            getline(cin, s.position);
            // Safe 3-line write
            fout << s.id << "\n"
            << s.name << "\n"
            << s.position << "\n"
            << "---\n";
            fout.close();
            cout << "\nStaff added successfully!\n";
        }
        else if (choice == 2)
        {
            ifstream fin("staff.txt");
            Staff s;
            string separator;
            cout << "\n\n|===============================================|\n";
            cout << "                STAFF RECORDS\n";
            cout << "|===============================================|\n";
            cout << "ID\tName\t\tPosition\n";
            cout << "-----------------------------------------------\n";
            while (fin >> s.id)
            {
                fin.ignore();
                getline(fin, s.name);
                getline(fin, s.position);
                getline(fin, separator);
                cout << s.id << "\t" << s.name << "\t\t" << s.position << endl;
            }
            fin.close();
        }
        else if (choice == 3)
        {
            ifstream fin("staff.txt");
            Staff s;
            int searchID;
            bool found = false;
            string separator;
            cout << "\nEnter Staff ID to search: ";
            cin >> searchID;
            while (fin >> s.id)
            {
                fin.ignore();
                getline(fin, s.name);
                getline(fin, s.position);
                getline(fin, separator);
                if (s.id == searchID)
                {
                    cout << "\nRecord Found:\n";
                    cout << "ID: " << s.id << endl;
                    cout << "Name: " << s.name << endl;
                    cout << "Position: " << s.position << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No staff found with this ID.\n";
            fin.close();
        }
        else if (choice == 4)
        {
            cout << "Returning to main menu...\n";
            return; 
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
class Fuel
{
public:
    string fuel_type;
    float price;
    int stock;
};
void dailyFuelSummary()
{
    Fuel f;
    int totalFuelTypes=0;
    float totalPrice=0;
    int totalStock=0;
    ifstream fin("foul.txt");
    cout<<"\n==============================================\n";
    cout<<"          DAILY FUEL SUMMARY REPORT\n";
    cout<<"==============================================\n\n";
    cout<<"Fuel Type | Price | Stock\n";
    cout<<"----------------------------------------------\n";
    while(fin>>f.fuel_type>>f.price>>f.stock)
    {
        cout<<f.fuel_type<<"   | "<<f.price<<"   | "<<f.stock<<"L\n";
        totalFuelTypes++;
        totalPrice += f.price;
        totalStock += f.stock;
    }
    fin.close();
    cout<<"----------------------------------------------\n";
    cout<<"Total Fuel Types : "<<totalFuelTypes<<endl;
    cout<<"Total Price Sum  : "<<totalPrice<<" PKR\n";
    cout<<"Total Stock      : "<<totalStock<<" Litres\n";
    cout<<"==============================================\n\n";
}
void systemLogs()
{
    int choice;
    string logText;
    while(true)
    {
        cout<<"\n===== SYSTEM LOGS =====\n";
        cout<<"1. Add Log Entry\n";
        cout<<"2. View System Logs\n";
        cout<<"3. Clear Log File\n";
        cout<<"0. Back to Menu\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            cin.ignore();
            getline(cin,logText);
            ofstream fout("system_logs.txt",ios::app);
            fout<<logText<<"\n";
            fout.close();
            cout<<"\nLog Added Successfully.\n\n";
        }
        else if(choice==2)
        {
            ifstream fin("system_logs.txt");
            if(!fin)
            {
                cout<<"No logs found.\n";
                continue;
            }
            cout<<"\n=========== SYSTEM LOGS ===========\n";
            while(getline(fin,logText))
            {
                cout<<logText<<endl;
            }
            cout<<"===================================\n\n";
            fin.close();
        }
        else if(choice==3)
        {
            ofstream fout("system_logs.txt",ios::trunc);
            fout.close();
            cout<<"\nLog File Cleared Successfully.\n\n";
        }
        else if(choice==0)
        {
            admin();
        }
        else
        {
            cout<<"Invalid Choice.\n";
        }
    }
}
void logoutFunction()
{
    ofstream fout("system_logs.txt",ios::app);
    fout<<"[LOGOUT] User logged out successfully.\n";
    fout.close();
    cout<<"\n==============================================\n";
    cout<<"              USER LOGGED OUT\n";
    cout<<"==============================================\n";
    cout<<"Your session has been terminated safely.\n";
    cout<<"Please close the program or login again.\n";
    cout<<"==============================================\n\n";
    exit(0);
}
void exitProgram()
{
    ofstream fout("system_logs.txt",ios::app);
    fout<<"[EXIT] Program terminated by user.\n";
    fout.close();
    cout<<"\n==============================================\n";
    cout<<"                PROGRAM CLOSED\n";
    cout<<"==============================================\n";
    cout<<"Thank you for using the system.\n";
    cout<<"Exiting safely...\n";
    cout<<"==============================================\n\n";
    exit(0);
}
void recordFuelSale()
{
    Fuel f[100];
    int count=0;
    ifstream fin("foul.txt");
    while(fin>>f[count].fuel_type>>f[count].price>>f[count].stock)
        count++;
    fin.close();
    if(count==0)
    {
        cout<<"No fuel records found.\n";
        return;
    }
    cout<<"\n=========== AVAILABLE FUEL TYPES ===========\n";
    for(int i=0;i<count;i++)
    {
        cout<<f[i].fuel_type<<" | Price: "<<f[i].price<<" | Stock: "<<f[i].stock<<"L\n";
    }
    cout<<"=============================================\n\n";
    string ft;
    int qty;
    cout<<"Enter Fuel Type to Sell: ";
    cin>>ft;
    cout<<"Enter Litres to Sell: ";
    cin>>qty;
    bool found=false;
    for(int i=0;i<count;i++)
    {
        if(f[i].fuel_type==ft)
        {
            found=true;
            if(qty>f[i].stock)
            {
                cout<<"\nNot enough stock available.\n";
                return;
            }
            float total=f[i].price*qty;
            f[i].stock -= qty;
            ofstream fout("foul.txt");
            for(int j=0;j<count;j++)
            {
                fout<<f[j].fuel_type<<" "<<f[j].price<<" "<<f[j].stock<<"\n";
            }
            fout.close();
            ofstream log("system_logs.txt",ios::app);
            log<<"[SALE] Fuel: "<<ft<<" | Litres: "<<qty<<" | Total: "<<total<<"\n";
            log.close();
            cout<<"\n=========== SALE RECORDED SUCCESSFULLY ===========\n";
            cout<<"Fuel Type : "<<ft<<endl;
            cout<<"Litres Sold: "<<qty<<endl;
            cout<<"Total Amount: "<<total<<" PKR\n";
            cout<<"Remaining Stock: "<<f[i].stock<<"L\n";
            cout<<"=================================================\n\n";
        }
    }
    if(!found)
    {
    cout<<"Fuel type not found.\n";
    
    }  
}
void generateEReceipt()
{
    string fuel;
    int qty=0;
    float total=0;
    ofstream receipt("e_receipt.txt");
    receipt<<"=====================================\n";
    receipt<<"        DIGITAL FUEL RECEIPT\n";
    receipt<<"=====================================\n";
    receipt<<"Fuel Type      : "<<fuel<<"\n";
    receipt<<"Litres Sold    : "<<qty<<" L\n";
    receipt<<"Total Amount   : "<<total<<" PKR\n";
    receipt<<"-------------------------------------\n";
    receipt<<"Thank you for your purchase.\n";
    receipt<<"=====================================\n";
    receipt.close();
    recordFuelSale();
    cout<<"\nReceipt generated successfully in 'e_receipt.txt'.\n\n";
}
void updateFuelPrices()
{
            list l[100];
            int count=0;
            ifstream fin("foul.txt");
            while(fin>>l[count].fuel_type>>l[count].price>>l[count].stock)
                count++;
            fin.close();
            string fName;
            cout<<"|===============================================|\n";
            cout<<"              FUEL INVENTORY\n";
            cout<<"|===============================================|\n";
            cout<<"Available Records:\n";
            for(int i=0;i<count;i++)
            {
                cout<<l[i].fuel_type<<" "<<l[i].price<<" "<<l[i].stock<<endl;
            }
            cout<<"\nWhich fuel type you want to update? ";
            cin>>fName;
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(l[i].fuel_type==fName)
                {
                    found=true;
                    cout<<"Enter New Price: ";
                    cin>>l[i].price;
                    cout<<"Enter New Stock: ";
                    cin>>l[i].stock;
                    break;
                }
            }
            if(!found)
            {
                cout<<"Fuel type not found.\n";
                cout<<"Try again...";
                fuelSystem();
            }
            ofstream fout("foul.txt");
            for(int i=0;i<count;i++)
            {
                fout<<l[i].fuel_type<<" "<<l[i].price<<" "<<l[i].stock<<"\n";
            }
            fout.close();
            cout<<"\nRecord Updated Successfully.\n\n";
}
