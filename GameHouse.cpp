#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

int login();
void homepage();
void customer_Access();
void after_login();
// Gamehouse Class
class gamehouse {
public:
    void main_control();
    void customer_control();
    void add_game();
    void show_game();
    void check_game();
    int check_id(string game_idd);
    void update_game();
    void del_game();
    
};

// Function to display the gamehouse options
void gamehouse::main_control()
{
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t*************************************************WELCOME TO GAMEHOUSE***********************************************************";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t1. ADD GAME";
    cout << "\n\n\t\t\t\t\t\t\t\t\t2. DISPLAY GAMES AVAILABLE";
    cout << "\n\n\t\t\t\t\t\t\t\t\t3. CHECK FOR PARTICULAR GAME";
    cout << "\n\n\t\t\t\t\t\t\t\t\t4. UPDATE GAME LIST";
    cout << "\n\n\t\t\t\t\t\t\t\t\t5. DELETE GAME FROM LIST";
    cout << "\n\n\t\t\t\t\t\t\t\t\t6. BACK";
    cout << "\n\n\t\t\t\t\t\t\t\t\t7. GO TO HOME PAGE";
    cout << "\n\n\t\t\t\t\t\t\t\t\t8. EXIT";
}

// Function to add game
void gamehouse::add_game()
{
    system("cls");
    fstream file;
    int no_copy;
    string game_name, dev_name, game_id;
    cout << "\n\n\t\t\t\tADD GAME";
    cout << "\n\nGAME ID : ";
    cin >> game_id;
    int flag = check_id(game_id);
    if(flag == 1)
    {
    	cout << "\nGAME NAME : ";
    	cin >> game_name;
    	cout << "\nGAME DEVELOPER NAME : ";
    	cin >> dev_name;
    	cout << "\nNO. OF COPIES OF THIS GAME : ";
    	cin >> no_copy;
    	
    	file.open("E:// game.txt",
    	          ios::out | ios::app);
    	file << " " << game_id << " "
    	     << game_name << " " << dev_name
    	     << " " << no_copy << "\n";
    	file.close();
	}
	else
	{
		add_game();
	}
}

// Function to display game
void gamehouse::show_game()
{
    system("cls");
    fstream file;
    int no_copy;
    string game_name, game_id, dev_name;
    cout << "\n\n\t\t\t\t\tTHE GAMES AVAILABLE";

    file.open("E:// game.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        
        file >> game_id >> game_name;
        file >> dev_name >> no_copy;

        while (!file.eof()) {

                cout << "\n\nGAME ID : "
                     << game_id;
                cout << "\nGAME NAME : "
                     << game_name;
                cout << "\nGAME DEVELOPER NAME : "
                     << dev_name;
                cout << "\nNo. of copies of GAME : "
                     << no_copy;
                cout << endl
                     << endl;
            file >> game_id >> game_name;
            file >> dev_name >> no_copy;
        }

        system("pause");

        file.close();
    }
}

// Function to check the a particular game details
void gamehouse::check_game()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string game_id, game_name, dev_name, game_idd;

    cout << "\n\n\t\t\t\tCHECK FOR PARTICULAR GAME ";
        
    file.open("E:// game.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nGAME ID : ";
        cin >> game_idd;
        file >> game_id >> game_name;
        file >> dev_name >> no_copy;

        while (!file.eof()) {

            if (game_idd == game_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "THE GAME DETAILS PROVIDED BELOW";
                cout << "\n\nGAME ID : "
                     << game_id;
                cout << "\nGAME NAME : "
                     << game_name;
                cout << "\nGAME DEVELOPER NAME : "
                     << dev_name;
                cout << "\nNo. of copies of GAME : "
                     << no_copy;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> game_id >> game_name;
            file >> dev_name >> no_copy;
        } 
        file.close();
        if (count == 0){
            cout << "\n\nGAME ID Not"
                 << " Found...\n"; 
		}
		system("pause");		       
    }
}

// Function to check the a particular game details
int gamehouse::check_id(string game_idd)
{
    fstream file;
    int count = 0;
    string game_id;
        
    file.open("E:// game.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        file >> game_id;

        while (!file.eof()) {

            if (game_idd == game_id) {

                cout << "\n\nGAME ID ALREADY PRESENT\n";
                count++;
                break;
            }
            file >> game_id ;
        } 
        file.close();
        if (count == 0){
            return 1;
		}
		else
		{
			cout << "\n\nPLEASE ADD GAME WITH A NEW ID\n\n";
			system("pause");
			return 0;
		}
		       
    }
}

// Function to update the gamelist
void gamehouse::update_game()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string game_name, game_na, dev_name;
    string dev_na, game_idd, game_id;

    cout << "\n\n\t\t\t\tUPDATE GAME LIST";
    file1.open("D:// game1.txt",
               ios::app | ios::out);
    file.open("E:// game.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nGAME ID : ";
        cin >> game_id;
        file >> game_idd >> game_name;
        file >> dev_name >> no_copy;

        while (!file.eof()) {
            if (game_id == game_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "UPGDATE GAME LIST";
                cout << "\n\nNew GAME Name : ";
                cin >> game_na;
                cout << "\nDEVELOPER Name : ";
                cin >> dev_na;
                cout << "\nNo. of copies of GAME : ";
                cin >> no_co;
                file1 << " " << game_id << " "
                      << game_na << " "
                      << dev_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << game_idd
                      << " " << game_name
                      << " " << dev_name
                      << " " << no_copy
                      << "\n\n";
            file >> game_idd >> game_name;
            file >> dev_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nGAME ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    file.close();
    file1.close();
    remove("E:// game.txt");
    rename("E:// game1.txt",
           "E:// game.txt");
}

// Function to delete game from list
void gamehouse::del_game()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string game_id, game_idd, game_name, dev_name;
    cout << "\n\n\t\t\t\tDelete a Book";

    file1.open("E:// game1.txt",
               ios::app | ios::out);
    file.open("E:// game.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nGAME ID : ";
        cin >> game_id;
        file >> game_idd >> game_name;
        file >> dev_name >> no_copy;
        while (!file.eof()) {

            if (game_id == game_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a GAME";
                cout << "\n\nGAME is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << game_idd
                      << " " << game_name
                      << " " << dev_name
                      << " " << no_copy
                      << "\n\n";
            file >> game_idd >> game_name;
            file >> dev_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nGAME ID "
                 << "Not Found...\n";
    }
    system("pause");

    file.close();
    file1.close();
    remove("E:// game.txt");
    rename("E:// game1.txt",
           "E:// game.txt");
}

// Function for gamehouse shop record
void gameHouseRecord()
{
    int choice;
    char x;
    gamehouse b;

    while (1) {

        b.main_control();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_game();
                cout << "\n\nWant to add"
                     << " another game? "
                        "(y/n) : ";
                cin >> x;
            } while (tolower(x)== 'y');
            break;

        case 2:
            b.show_game();
            break;

        case 3:
            b.check_game();
            break;
        case 4:
            b.update_game();
            break;

        case 5:
            b.del_game();
            break;
		case 6:
			after_login();
			break;
		case 7:
			homepage();
			break;
        case 8:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
            system("pause");
            gameHouseRecord();
        }
    }
}
class gamehouse_employee {
public:
    void employee_control();
    void add_employee();
    void show_employee();
    void check_employee();
    int check_employeeid(string game_idd);
    void update_employee();
    void del_employee();
};

// Function to display the employee options
void gamehouse_employee::employee_control()
{
    system("cls");
    cout << "\n\n\n\n\n\n\t\t*************************************************GAMEHOUSE EMPLOYEE SECTION*************************************************************************";
    cout << "\n\n\n\t\t\t\t\t\t\t1. ADD EMPLOYEE";
    cout << "\n\n\t\t\t\t\t\t\t2. EMPLOYEE WORKING IN GAMEHOUSE";
    cout << "\n\n\t\t\t\t\t\t\t3. CHECK FOR PARTICULAR EMPLOYEE DETAILS";
    cout << "\n\n\t\t\t\t\t\t\t4. UPDATE EMPLOYEE LIST";
    cout << "\n\n\t\t\t\t\t\t\t5. DELETE EMPLOYEE FROM LIST";
    cout << "\n\n\t\t\t\t\t\t\t6. BACK";
    cout << "\n\n\t\t\t\t\t\t\t7. GO TO HOME PAGE";
    cout << "\n\n\t\t\t\t\t\t\t8. EXIT";
}

// Function to add employee details
void gamehouse_employee::add_employee()
{
    system("cls");
    fstream file;
    int emp_age;
    string emp_id,emp_name,emp_address,emp_contact,emp_gender;
    cout << "\n\n\t\t\t\tADD EMLOYEE";
    cout << "\n\nEMPLOYEE ID : ";
    cin >> emp_id;
    int flag1 = check_employeeid(emp_id);
    if (flag1 == 1)
    {
    	cout << "\nEMPLOYEE NAME : ";
    	cin >> emp_name;
    	cout << "\nEMPLOYEE ADDRESS : ";
    	cin >> emp_address;
    	cout << "\nEMPLOYEE PHONE NO. : ";
    	cin >> emp_contact;
    	cout << "\nEMPLOYEE GENDER : ";
    	cin>> emp_gender;
    	cout << "\nEMPLOYEE AGE : ";
    	cin >> emp_age;
	
    	file.open("E:// employee.txt",
    	          ios::out | ios::app);
    	file << " " << emp_id << " "
    	     << emp_name << " " << emp_address
    	     << " " << emp_contact << " " << emp_gender << " " << emp_age << " \n";
    	file.close();
	}
	else
	{
		add_employee();
	}
}

// Function to employee details
void gamehouse_employee::show_employee()
{
    system("cls");
    fstream file;
    int emp_age;
    string emp_name, emp_id, emp_address,emp_contact,emp_gender;
    cout << "\n\n\t\t\t\t\tTHE EMPLOYEE WORKING IN GAMESHOP";

    file.open("E:// employee.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        file >> emp_id >> emp_name;
        file >> emp_address >> emp_contact >> emp_gender;
        file>> emp_age;
        while (!file.eof()) {

            cout << "\n\nEMPLOYEE ID : "
                     << emp_id;
                cout << "\nEMPLOYEE NAME : "
                     << emp_name;
                cout << "\nEMPLOYEE ADRRESS : "
                     << emp_address;
                cout << "\nEMPLOYEE CONTACT NO. : "
                     << emp_contact;
                cout << "\nGENDER : "
                    <<emp_gender;
                cout << "\nAGE : "
                     <<emp_age;
                cout << endl
                     << endl;
            file >> emp_id >> emp_name;
            file >> emp_address >> emp_contact >> emp_gender;
            file>> emp_age;
        }
        system("pause");

        file.close();
    }
}

// Function to check a particular employee details
void gamehouse_employee::check_employee()
{
    system("cls");
    fstream file;
    int emp_age, count = 0;
    string emp_id, emp_name, emp_contact, emp_address,emp_gender, emp_idd;

    cout << "\n\n\t\t\t\tCHECK FOR PARTICULAR EMPLOYEE DETAILS ";
        
    file.open("E:// employee.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nEMPLOYEE ID : ";
        cin >> emp_idd;
        file >> emp_id >> emp_name;
        file >> emp_address >> emp_contact >> emp_gender;
        file>> emp_age;
        
        while (!file.eof()) {

            if (emp_idd == emp_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "THE EMPLOYEE DETAILS PROVIDED BELOW";
                cout << "\n\nEMPLOYEE ID : "
                     << emp_id;
                cout << "\nEMPLOYEE NAME : "
                     << emp_name;
                cout << "\nEMPLOYEE ADRRESS : "
                     << emp_address;
                cout << "\nEMPLOYEE CONTACT NO. : "
                     << emp_contact;
                cout << "\nGENDER : "
                    <<emp_gender;
                cout << "\nAGE : "
                     <<emp_age;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> emp_id >> emp_name;
            file >> emp_address >> emp_contact >> emp_gender;
            file>> emp_age;
        }
        
        file.close();
        if (count == 0){
            cout << "\n\n Employee ID Not"
                 << " Found...\n";
            
		}
		system("pause");
    }
}

int gamehouse_employee::check_employeeid(string emp_idd)
{
    fstream file;
    int count = 0;
    string emp_id;

    file.open("E:// employee.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        file >> emp_id;
        
        while (!file.eof()) {

            if (emp_idd == emp_id) {

                system("cls");
                cout << "\n\nEMPLOYEE ID ALREADY PRESENT\n";
                count++;
                break;
            }
            file >> emp_id;
        }
        
        file.close();
        if (count == 0){
            return 1;
		}
		else
		{
			cout << "\n\nPLEASE ADD EMPLOYEE WITH A NEW ID\n\n";
			system("pause");
			return 0;
		}
    }
}

// Function to update the employee details
void gamehouse_employee::update_employee()
{
    system("cls");
    fstream file, file1;
    int emp_age, new_age, count = 0;
    string emp_name, new_name, emp_address;
    string new_address, new_id, emp_id ,emp_contact, new_contact ,emp_gender , new_gender;

    cout << "\n\n\t\t\t\tUPDATE GAME LIST";
    file1.open("E:// employee1.txt",
               ios::app | ios::out);
    file.open("E:// employee.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nEMPLOYEE ID : ";
        cin >> emp_id;
        file >> new_id >> emp_name;
        file >> emp_address >> emp_contact >> emp_gender;
        file>> emp_age;
        
        while (!file.eof()) {
            if (emp_id == new_id) {
                system("cls");
                cout << "\t\t\t\t"
                     << "UPDATE EMPLOYEE LIST";
                cout << "\n\nNEW EMPLOYEE NAME : ";
                cin >> new_name;
                cout << "\nEMLOYEE ADRESS : ";
                cin >> new_address;
                cout << "\nCONTACT NO. : ";
                cin >> new_contact;
                cout<< "\n GENDER : ";
                cin >> new_gender;
                cout << "\n AGE :";
                cin >> new_age;
                file1 << " " << emp_id << " "
                      << new_name << " "
                      << new_address << " " << new_contact << " "<< new_gender<< " " << new_age
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << new_id
                      << " " << emp_name
                      << " " << emp_address
                      << " " << emp_contact
                      << " " << emp_gender
                      << " " << emp_age
                      << "\n\n";
            file >> new_id >> emp_name;
            file >> emp_address >> emp_contact >> emp_gender;
            file >> emp_age;
        }
        if (count == 0)
            cout << "\n\nEMPLOYEE ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    file.close();
    file1.close();
    remove("E:// employee.txt");
    rename("E:// employee1.txt",
           "E:// employee.txt");
}

// Function to delete employee details
void gamehouse_employee::del_employee()
{
    system("cls");
    fstream file, file1;
    int emp_age, count = 0;
    string emp_id, emp_idd, emp_name, emp_address, emp_contact, emp_gender;
    cout << "\n\n\t\t\t\tDelete details of EPMPLOYEE";

    file1.open("E:// employee1.txt",
               ios::app | ios::out);
    file.open("E:// employee.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nEMPLOYEE ID : ";
        cin >> emp_id;
        file >> emp_idd >> emp_name;
        file >> emp_address >> emp_contact >> emp_gender;
        file >> emp_age;
        while (!file.eof()) {

            if (emp_id == emp_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete Employee Details";
                cout << "\n\Employee details is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << emp_idd
                      << " " << emp_name
                      << " " << emp_address
                      << " " << emp_contact
                      << " " << emp_gender
                      << " " << emp_age
                      << "\n\n";
            file >> emp_idd >> emp_name;
            file >> emp_address >> emp_contact >> emp_gender;
            file >> emp_age;
        }
        if (count == 0)
            cout << "\n\nEMPLOYEE ID "
                 << "Not Found...";
    }
    system("pause");

    file.close();
    file1.close();
    remove("E:// employee.txt");
    rename("E:// employee1.txt",
           "E:// employee.txt");
}

// Function for employee details record
void employee_Record()
{
    int choice;
    char x;
    gamehouse_employee b;

    while (1) {

        b.employee_control();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_employee();
                cout << "\n\nWant to add"
                     << " another employee details? "
                        "(y/n) : ";
                cin >> x;
            } while (tolower(x)== 'y');
            break;

        case 2:
            b.show_employee();
            break;

        case 3:
            b.check_employee();
            break;
        case 4:
            b.update_employee();
            break;

        case 5:
            b.del_employee();
            break;
        case 6:  
			after_login();
			break;    
		case 7:  
			homepage();
			break;
        case 8:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
            system("pause");
            employee_Record();
        }
    }
}


void gamehouse::customer_control()
{
    system("cls");
    cout << "\n\n\n\n\n\n\t\t*************************************************WELCOME TO GAMEHOUSE*************************************************************";
    cout << "\n\n\t\t\t\t\t\t\t1. DISPLAY GAMES AVAILABLE";
    cout << "\n\n\t\t\t\t\t\t\t2. CHECK FOR PARTICULAR GAME";
    cout << "\n\n\t\t\t\t\t\t\t3. BACK TO HOMPAGE";
    cout << "\n\n\t\t\t\t\t\t\t4. EXIT";
}

void homepage()
{ 
    system("cls");
	int ch,k=0;
    cout<<"\n\n\n\n\t\t\t***************************************   WELCOME TO GAME HOUSE   ****************************************\n";
    cout<<"\n\n\t\t\t\t\t\t\t\tPRESS 1 FOR CUSTOMER USE\n\n";
    cout<<"\n\n\t\t\t\t\t\t\t\tPRESS 2 FOR ADMINISTRATOR LOGIN\n\n";
    cout<<"\n\n\t\t\t\t\t\t\t\tPRESS 3 TO EXIT\n\n";
    cout<<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE:  ";
    cin>>ch;
    switch(ch)
    {
    	case 1: customer_Access();
    	        break;
    	case 2: login();
			   break;
        case 3:	cout<<"\n\n\t\t\t\tEXIT  ";				
		        exit(0);
				break;
		default:cout << "\n\nINVALID CHOICE\n";
				system("pause");
				homepage();
				
   }  
    
}

void customer_Access()
{
    int choice;
    char x;
    gamehouse c;

    while (1) {

        c.customer_control();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice)
		{
        case 1:
            c.show_game();
            break;

        case 2:
            c.check_game();
            break;
        case 3:
             homepage();
             break;
        case 4:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
            system("pause");
        }
    }
}

int login()
{
	system("cls");
	cout<<"\n\n\n\n\t\t\t***************************************   WELCOME TO ADMIN LOGIN   ****************************************\n";
    string userName;
    char c;
    string pass;
    int loginAttempt = 5;

    while (loginAttempt > 0)
    {
        cout << "\n\tPlease enter your user name: ";
        cin >> userName;
        cout << "\tPlease enter your user password: ";
        pass.clear();
		while(1)
		{
			c = getch();
			if(c =='\r')
        	{
            	break;
       		}
			if(c == '\b')
			{	if ( pass.size()>0 )
					{
						cout << '\b' << " " << '\b';
						pass.resize(pass.size() - 1);
					}
			}
			else
			{
				cout << "*";
				pass += c;
			}
		}
        
        if (userName == "Abhinav" && pass == "abhi123")
        {
            after_login();
            break;
        }
        else if (userName == "Abhishek" && pass == "abhi123")
        {
            after_login();
            break;
        }
        else
        {
            cout << "\n\tInvalid login attempt. Please try again." << '\n';
            loginAttempt--;
            cout << "\n\tLogin Attempts left " << loginAttempt << endl;
        }
    }
    if (loginAttempt == 0)
    {
            cout << "\n\tToo many login attempts! The program will now terminate.";
            exit(0);
    }
	return 0;
}

void after_login()
{
	system("cls");
				int choice; 
    			cout<<"\n\n\n\n\t\t\t***************************************        HELLO ADMIN        ****************************************\n";
    			cout<<"\n\n\n\n\t\t\t***************************************   WELCOME TO GAME HOUSE   ****************************************\n";
    			cout<<"\n\n\t\t\t\t\t\t1. ENTER FOR GAMEHOUSE STORE STOCK MANAGEMENT\n\n";
    			cout<<"\n\n\t\t\t\t\t\t2. ENTER FOR EMPLOYEE MANAGEMENT OF GAMEHOUSE\n\n";
    			cout<<"\n\n\t\t\t\t\t\t3. GO TO HOME PAGE\n\n";
    			cout<<"\n\n\t\t\t\tENTER YOUR CHOICE:  ";
    			cin>>choice;
			    switch(choice)
			        {
			        	 case 1:gameHouseRecord();
			        	        break;
			        	        
			        	case 2:employee_Record();
			        			break;
			        			
			        	case 3:homepage();
			        			break;
			        			
			        	default:cout<<"\n\nINVALID CHOICE .......PLEASE ENTER A VALID OPTION\n\n";
			        		    system("pause");
			        		    after_login();
			        			
					}
}

int main()
{
    homepage();
}



