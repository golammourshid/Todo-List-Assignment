// Source File Header// Todo.cpp// Indiana Alder, CISP 400// 11/7/21
#include <iostream>
#include "TodoList.h"
// Function Prototypes
void programGreeting();
void toDoMenu();
string menuInput();
int main()
{
    TodoList list;
    string userInput = " ";

    programGreeting();// Display Program Greeting
    do
    {
        toDoMenu();// Display ToDo Menu
        userInput = menuInput();
        // Specification B1 - + Symbol
        if (userInput == "+")
        {
            string newItemInput;
            cout << "\n==============(NEW ITEM)==============\n";
            cout << "Enter the name of new ToDo Item: ";
            cin >> newItemInput;
            list.insertTodo(newItemInput);
            cout << "New Todo item has been added!" << endl;
            cout << "======================================\n\n";
        }
        // Specification B2 - ? Symbol
        else if (userInput== "?")
        {
            cout << "\n==============(ToDo List)==============\n";
            cout << "ToDo Item List:\n";
            cout << "DateTodo Item\n";
            cout << "----------------------\n";
            cout << list << endl;
            cout << "\n=======================================\n\n";
        }
    }
    while (!(userInput == "x" || userInput == "X"));
    return 0;
}
void programGreeting()
{
    time_t t;// t is passed as a argument in function time()
    struct tm * tt;// Declare variable for localtime()
    time (&t);// Pass argument to time()
    tt = localtime(&t);
    cout <<"=============================(programGreeting)=============================\n";
    cout << "This ToDo list program allows the user to input numerous items on toa\n";
    cout << "ToDo list menu which can be outputted onto the console.\n";
    cout << "Author Name: Indiana Alder\n";
    cout << "Assignment Due Date: Novermber 7, 2021\n";
    cout << "Current Day, Date and Time is = " << asctime(tt);// Display SystemDate
    cout <<"===========================================================================\n\n";
}
void toDoMenu()
{
    cout << "==================(TODO MENU)==================\n";
    cout << "[+] Add a ToDo Item\n";
    cout << "[?] Display all ToDo Items\n";
    cout << "[x] Exit Program\n";
    cout << "===============================================\n";
}
string menuInput()
{
    string userInput;
    while (true)
    {
        cout << "Enter the letter in the bracket as your selection: ";
        cin >> userInput;
        // Input Validation
        if (userInput == "+" || userInput == "?" || userInput == "x" || userInput =="X")break;
        cout << "********************************\n";
        cout << "*ERROR: Invalid selection.\n";
        cout << "********************************\n\n";
    }
    return userInput;
}
