// Source File Header
// homework.cpp
// Md. Fahim Alam, CISP 400
// 06/11/22

#include<iostream>
#include <ctime>

using namespace std;

//This is the structure class of the inventory system.
class TodoList
{
public:
    int taskIdNumber;
    static int countItem;

    string task, date;
    //set added date
    int currentDay, currentMonth, currentYear;
    double wholesaleCost;
    double retailCost;
    TodoList* next;

    TodoList* head;

    //Default Constructor
    TodoList()
    {
        head = NULL;
        next = NULL;
        //countItem = 1;
    }

    //creating function that Overload the stream extraction operator and give the output
    friend ostream &operator << (ostream &output, const TodoList &d)
    {
        //cout<<"Task Id :"

        output<<"Task Id :"<<d.taskIdNumber<<"\n";
        output<<"Date Added: "<<d.date<<"\n";
        output<<"Task to Do: "<<d.task<<"\n";
       // output<<d.retailCost<<"            "<<d.addedDay<<"/"<<d.addedMonth<<"/"<<d.addedYear<<endl;
        return output;
    }

    //creating function that Overload the stream insertion operator and scan the input
    friend istream & operator >> (istream &input, TodoList &d)
    {
        cin.ignore();
        d.getDate();
        countItem ++;
        d.taskIdNumber = d.countItem;
        cout<<"\nWrite task details:"<<endl;
        string ss="";
        ss+=to_string(d.currentDay);
        d.date = to_string(d.currentDay) + "/" + to_string(d.currentMonth) + "/" + to_string(d.currentYear);
        getline(cin,d.task);
        return input;
    }
    //Function Prototype
    void ProgramGreeting();

    //Function Prototype
    void AlphaMenu();
    // Output Main Menu to console
    void addInventory();
    //Add new item to inventory at the last, selected from Main Menu
    void showInventory();
    //Displays current items in inventory
    void getDate();
    //Calculating Date
    void editInventory();
    //Update any item from inventory
    void deleteInventory();
    //Delete the last item from the inventory, decrease array by 1



};
/*
//Specification B1 - Date class
class Date
{
private:
    //Specification C2 - Dynamic Array of link list
    dataDictionary *head;

    //set due date
    int dueDay=16, dueMonth=10, dueYear=2022;

    //set added date
    int addedDay=9, addedMonth=9, addedYear=99;

    //initialize variable for counting total item.
    int countItem=0;

public:
    //Default Constructor
    Date()
    {
        head = NULL;
    }

    //Function Prototype
    //void ProgramGreeting();

    //Specification B2 - ComponentTest method in Date
    void Due_Date_is_valid()
    {
        if(dueDay == 16 && dueMonth == 10 && dueYear == 2022)
        {
            cout<<"\nDue date is fine!\n"<<endl;
        }
    }
    //Specification B2 - ComponentTest method in Date
    void Added_Date_is_valid()
    {
        if(addedDay == 9 && addedMonth == 9 && addedYear == 99)
        {
            cout<<"\nAdded date is also fine! Lets start.\n"<<endl;
        }
    }


};

*/

int main ()
{
    //creating an Date type object
    TodoList todoList;

    todoList.getDate();
    //Showing welcome message
    todoList.ProgramGreeting();

    //Specification A4 - UnitTest() method in main()
    //date.Due_Date_is_valid();
    //date.Added_Date_is_valid();

    //Showing the main menu
    todoList.AlphaMenu();
    return 0;
}

void  TodoList:: ProgramGreeting()
{
    cout<<"********************************************************************************\n                                 ProgramGreetings\n"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"Welcome to our TodoList management system.";
    cout<<"This system is designed for adding new\ntasks, delete any task from the system. ";
    cout<<"It also allow you to show all the task\n list any time."<<endl;
    cout<<"Author Name: Md. Fahim Alam"<<endl;
    cout<<"Assignment Due Date: November 06, 2022\n";
    cout<<"Current Date(day-month-year): "<<currentDay<<"-"<<currentMonth<<"-"<<currentYear<<endl;
    cout<<"********************************************************************************\n                                 ProgramGreetings\n"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<""<<endl;
}

void TodoList:: AlphaMenu()
{
    while(1)
    {
        cout<<"\nDo you want to go Main Menu? (y/n)"<<endl;
        //Variable to get user input
        char userInput;
        cin>>userInput;
        //checking user input
        if(userInput=='y' || userInput == 'Y')
        {
            //Specification C1 - Alpha Menu
            cout<<"\nMain Menu.\n--------------------------------"<<endl;
            cout<<"[+] Add a ToDo Item\n[-] Delete a ToDo Item\n[?] Display all ToDo Items\n[x] Exit Program"<<endl;
            cin>>userInput;
            //Specification B3 - Menu Input Validation
            if(userInput == '+')
            {
                addInventory();
            }
            else if(userInput == '?')
            {
                showInventory();
            }
            else if (userInput == 'X' || userInput == 'x')
            {
                cout<<"\nThanks for visiting!\n"<<endl;
                return;
            }
            else if (userInput == '-')
            {
                deleteInventory();
            }
            else
            {
                cout<<"\nPlease enter valid input.\n"<<endl;
            }
        }
        else if(userInput=='n' || userInput == 'N')
        {
            cout<<"\nThanks for visiting!\n"<<endl;
            return;
        }
        else
        {
            cout<<"\nPlease enter valid input.\n"<<endl;
        }
    }
}

int TodoList:: countItem=0;

void TodoList:: addInventory()
{
    //increasing number of item by 1
    //countItem++;

    //create the new node with data
    TodoList* newNode = new TodoList ();

    //Specification A3 - Overload operator >>
    cin>>*newNode;

    //Assigning to head
    if(head == NULL)
    {
        head = newNode;
        cout<<"\nSuccessfully added new task!!\n"<<endl;
        return;
    }

    //cout<<"Antor"<<endl;

    //Traverse Till end of list
    TodoList* temp = head;
    while(temp->next != NULL)
    {
        //update temp
        temp = temp->next;
    }

    //Specification C3 - Resize Array - add to end
    temp->next = newNode;

    cout<<"\nSuccessfully added new task!!\n"<<endl;
}

void TodoList:: showInventory()
{
    TodoList* temp = head;

    //check if the list is empty
    if(head == NULL)
    {
        cout<<"\nList is Empty. Nothing to show.\n"<<endl;
        return;
    }

    //Column Name
    //cout<<"\nTask Id Number | Date Added to List | Wholesale Cost | Retail Cost | Added Date"<<endl;

    //Traverse the List
    while(temp != NULL)
    {
        //Specification A2 - Overload operator <<
        cout<<"\n-----------------------------------------------------------------------\n"<<endl;
        cout<<*temp;
        temp = temp->next;
    }
    cout<<"\n-----------------------------------------------------------------------\n"<<endl;
}

void TodoList:: getDate()
{
    time_t now = time(0);
    tm *dateTime = localtime(&now);
    //int day,month,year;
    currentDay = dateTime->tm_mday;
    currentMonth = 1 + dateTime->tm_mon;
    currentYear = 1900 + dateTime->tm_year;
}


void TodoList:: deleteInventory()
{
    //check if the list is empty
    if(head == NULL)
    {
        cout<<"\nList is Empty. Nothing to delete."<<endl;
        return;
    }

    //Traverse Till end of list
    TodoList* temp = head;
    while(1)
    {
        //check whether the list have only one item
        if(temp->next == NULL)
        {
            head = head->next;
            break;
        }

        //check whether the list have more than one item
        if(temp->next->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    //Specification C4 - Resize Array - subtract from end
    temp->next = NULL;

    cout<<"\nSuccessfully deleted last item."<<endl;
}
