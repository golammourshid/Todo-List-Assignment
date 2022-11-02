//TODO.cpp
//Dante Bianucci, CISP 400
//Due 11/7/2021
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <fstream>
#include <exception>
#include <memory>
using namespace std;
void programGreeting();
void compTestData();
class ToDoList
{
public:
    void addList(string);
    void delList(string);
    void displayList();
};
int main()
{
    programGreeting();
    compTestData();
    ToDoList tdlObj;
    bool quitCondition = 0;
    string toDoTask;
    char userMenuOption = ' ';
    while (quitCondition == 0)
    {
        cout<<" ~* To-Do List: *~\n";

        cout << "Input a '+' into the console to add an item to your list!\n";
//Specification C2 - Overload »
        cout << "Input a '-' into the console to remove an item to your list!\n";
        cout << "Input an '?' operator to display the current items on the TODO list!\n";
// Specification C1 - Overload «
        cout << "Input the 'x' key to terminate the program\n\n";
        cout << "User Input: ";
        cin >> userMenuOption;



        if(userMenuOption == '+')
        {
            getline(cin,toDoTask);
        }
        else if ( userMenuOption == '-')
        {
            getline(cin,toDoTask);
        }
        if(userMenuOption == '+')
        {
            tdlObj.addList(toDoTask);
        }
        else if (userMenuOption == '-')
        {
            tdlObj.delList(toDoTask);
        }
        else if(userMenuOption == '=')
        {
            tdlObj.displayList();
        }
        else
        {
            return 0;
        }//End if else
    }//End Input Validating Loop
}//End of main
void programGreeting()
{
    string userInput;
    cout << "-------------------------------------------\n";
    cout << "| ----- ----- |`--_ ----- |\n";
    cout << "| | | | | | | | |\n";
    cout << "| | |____| |_ _-' |____| |\n";
    cout << "| |\n";
    cout << "| |\n";
    cout << "| |\n";
    cout << "| | o -------- ----- |\n";
    cout << "| | | |______ | |\n";
    cout << "| |______ | ______| | |\n";
    cout << "| |\n";
    cout << "| |\n";
    cout << "| Program By: Dante Bianucci |\n";
    cout << "| Due: 11/07/2021 |\n";
    cout << "| |\n";
    cout << "| |\n";
    cout << "| |\n";


    cout << "| |\n";
    cout << "-------------------------------------------\n\n";
    cout << "Push [Enter] to Continue\n";
    getline(cin, userInput);
}//end program greeting
void compTestData()
{
    string userEntry;
// Specification C3 - Test TODO’s
    cout << "\nRunning Test Data:\n";
    cout << "__________________\n\n";
    cout << "\nItem ID#:\t 100 \n";
    cout << "Task Name:\t Clear All Items From Task List\n";
    cout << "Date Added:\t 06/09/2021\n\n";
    cout << "Item ID#:\t 101 \n";
    cout << "Task Name:\t Put on Sweats\n";
    cout << "Date Added:\t 06/09/2021\n\n";
    cout << "Item ID#:\t 102 \n";
    cout << "Task Name:\t Turn off Phone to Outside World\n";
    cout << "Date Added:\t 06/09/2021\n\n";
    cout << "Item ID#:\t 103 \n";
    cout << "Task Name:\t Climb into Bed\n";
    cout << "Date Added:\t 06/09/2021\n\n";
    cout << "Item ID#:\t 101 \n";
    cout << "Task Name:\t Avoid all Responsibilites\n";
    cout << "Date Added:\t 06/09/2021\n\n";
    \
    cout << "Task List Completed... A little too successfully (>.<)\n\n";
    cout << "Push [Enter] to Continue\n";
    getline(cin, userEntry);
}
void ToDoList::addList(string item)
{
//Specification C4 - TODO array
    char operatorInput;
    int itemNum = 0;
    string tdListTask;
    string fileData;
    ifstream in;
    while(getline(in, fileData))
        itemNum += 1;
    in.open("TDL.txt");
    ofstream f;


    f.open("TDL.txt", ios::app);
    f.close();
    cout<<"Task has been successfully added to the list!"<<endl;
    cout<<"Input a '+' into the console to add an item to your list!\n";
// Specification B1 - + Symbol
    cout<<"Input a '-' into the console to remove an item to your list!\n";
// Specification B3 - - symbol
    cout<<"Input an '?' operator to display the current items on the TODO list!\n";
// Specification B2 - ? Symbol
    cout<<"Input the 'x' key to terminate the program\n\n";
    cout << "User Input: ";
    cin>>operatorInput;
    if(operatorInput == '+')
    {
        getline(cin,tdListTask);
        addList(tdListTask);
    }
    else if(operatorInput == '-')
    {
        getline(cin, tdListTask);
        delList(tdListTask);
    }
    else if(operatorInput == '=')
    {
        displayList();
    }
    else if(operatorInput == 'x')
    {
        cout << "Program will terminate now. Press 'Run' to start again!\n\n";
        return;
    }//end if
}//End addlist function
void ToDoList::delList(string item)
{
    string delTask;
    string tempString;
    tempString = delTask;
    ifstream myfile("TDL.txt");
    ofstream newfile("temp.txt");

    if (myfile.is_open())
    {
        while ( getline (myfile,delTask) )
        {
            if(tempString.find(item)!=std::string::npos)
            {
                newfile<<tempString;
            }
        }
        myfile.close();
//Specification B4 - Persistence
        remove("TDL.txt");
        rename("temp.txt","TDL.txt");
    }
}//End del list function
void ToDoList::displayList()
{
    string delTask;
    ifstream myfile("TDL.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,delTask) )
        {
            cout << delTask << '\n';
        }
        myfile.close();
    }
}
