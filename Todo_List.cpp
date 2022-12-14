// Source File Header
// TodoList.cpp
// Md Fahim Alam, CISP 400
// 11/6/22

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

//This is the structure class of the Todo List system.
class TodoList
{
public:
    int taskIdNumber;
    static int countItem;

    string task, date, allTask;
    //set added date
    int currentDay, currentMonth, currentYear;

    TodoList* next;

    //Specification C4 - TODO array
    //Creating link list as dynamic array
    TodoList* head;

    //Default Constructor
    TodoList()
    {
        head = NULL;
        next = NULL;
    }

    //Overload Constructor
    TodoList(TodoList *newNode)
    {
        this->taskIdNumber = newNode->taskIdNumber;
        this->date = newNode->date;
        this->task = newNode->task;
    }

    //Specification A1 - Overload Copy Constructor
    TodoList(const TodoList& t)
    {
    }

    //Specification A2 - Overload Assignment Operator
    TodoList& operator=(const TodoList& t)
    {
        return *this;
    }

    //creating function that Overload the stream extraction operator and give the output
    friend ostream &operator << (ostream &output, const TodoList &d)
    {
        output<<"Task Id :"<<d.taskIdNumber<<"\n";
        output<<"Date Added: "<<d.date<<"\n";
        output<<"Task to Do: "<<d.task<<"\n";
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
        d.date = to_string(d.currentMonth) + "/" + to_string(d.currentDay) + "/" + to_string(d.currentYear);
        getline(cin,d.task);
        return input;
    }

    //Function Prototype
		//Program Greeting
    void ProgramGreeting();

    void componentTesting();
    //Testing component and generate 5 To do tasks

    void AlphaMenu();
    //Output Main Menu to console

    void addTask();
    //Add new item to the list at the last, selected from Main Menu

    void showTask();
    //Displays all the task in the list

    void getDate();
    //Calculating Date

    void saveTask();
    //Save task in the list

    void deleteTask(int idNum);
    //Delete the specific tast

    void loadDataFromFile();
    // load data from file while starting the program
};

int main ()
{

    //creating an TodoList type object
    TodoList todoList;

    //Loading previous data from file
    //Specification B4 - Persistence
    todoList.loadDataFromFile();

    ofstream outputFile("TDL.txt", ios_base::app);

    //get current date
    todoList.getDate();

    //Showing welcome message
    todoList.ProgramGreeting();

    //Testing Component
    todoList.componentTesting();

    //Showing the main menu
    todoList.AlphaMenu();

    //saving the task
    todoList.saveTask();

    //save all task into the file
    outputFile<<todoList.allTask;

    //closing the file
    outputFile.close();
    return 0;
}

//Program Greeting
void  TodoList:: ProgramGreeting()
{
    cout<<"********************************************************************************\n                                 ProgramGreetings\n"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"Welcome to our TodoList management system.";
    cout<<"This system is designed for adding new\ntasks, delete any task from the system. ";
    cout<<"It also allow you to show all the task\n list any time."<<endl;
    cout<<"Author Name: Md Fahim Alam"<<endl;
    cout<<"Assignment Due Date: November 06, 2022\n";
    cout<<"Current Date(month-day-year): "<<currentMonth<<"-"<<currentDay<<"-"<<currentYear<<endl;
    cout<<"********************************************************************************\n                                 ProgramGreetings\n"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<""<<endl;
}

//Specification C3 - Test TODO's
void TodoList:: componentTesting()
{
    TodoList tl1,tl2;

    printf("Starting Component Testing.\n");

    TodoList* newNode;
    newNode = new TodoList ();

    countItem++;
    newNode->task = "Component testing :" + to_string(countItem);
    newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);

    newNode->taskIdNumber = countItem;
    if(head == NULL)
    {
        head = newNode;
    }

    else
    {
        TodoList* temp = head;
        while(temp->next != NULL)
        {
            //update temp
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //Implementing Overload Copy Constructor and Overload Assignment Operator
    tl1 = new TodoList(newNode);
    TodoList tl3 = tl1;
    tl1 = tl2;

    newNode = new TodoList ();
    countItem++;
    newNode->task = "Component testing :" + to_string(countItem);
    newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
    newNode->taskIdNumber = countItem;
    TodoList* temp = head;
    while(temp->next != NULL)
    {
        //update temp
        temp = temp->next;
    }
    temp->next = newNode;

    newNode = new TodoList ();
    countItem++;
    newNode->task = "Component testing :" + to_string(countItem);
    newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
    newNode->taskIdNumber = countItem;
    temp = head;
    while(temp->next != NULL)
    {
        //update temp
        temp = temp->next;
    }
    temp->next = newNode;

    newNode = new TodoList ();
    countItem++;
    newNode->task = "Component testing :" + to_string(countItem);
    newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
    newNode->taskIdNumber = countItem;
    temp = head;
    while(temp->next != NULL)
    {
        //update temp
        temp = temp->next;
    }
    temp->next = newNode;

    newNode = new TodoList ();
    countItem++;
    newNode->task = "Component testing :" + to_string(countItem);
    newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
    newNode->taskIdNumber = countItem;
    temp = head;
    while(temp->next != NULL)
    {
        //update temp
        temp = temp->next;
    }
    temp->next = newNode;

    printf("Todo List Component Testing Done. Generated 5 to do Tasks Successfully.");
}


void TodoList:: AlphaMenu()
{
	char userInput;
	int delTaskId;

	for(int i = 0; i >= 0; i++){
		cout<<"\nMain Menu.\n--------------------------------"<<endl;
		cout<<"[+] Add a ToDo Item\n[-] Delete a ToDo Item\n[?] Display all ToDo Items\n[x] Exit Program"<<endl;
		cin>>userInput;

		if(userInput == '+')
		{
				//Specification B1 - + Symbol
				addTask();
		}
		else if(userInput == '?')
		{
				//Specification B2 - ? Symbol
				showTask();
		}
		else if (userInput == 'X' || userInput == 'x')
		{
				cout<<"\nThanks for visiting!\n"<<endl;
				return;
		}
		else if (userInput == '-')
		{
				cout<<"Please enter the task id number that you want to delete"<<endl;
				cin>>delTaskId;
				//Specification B3 - - symbol
				deleteTask(delTaskId);
		}
		else
		{
				cout<<"\nPlease enter valid input.\n"<<endl;
		}
	}
}

int TodoList:: countItem = 0;

void TodoList:: addTask()
{
    //create the new node
    TodoList* newNode = new TodoList ();

    //Specification C2 - Overload >>
    cin>>*newNode;
    int flag = 0;
    if(newNode->task=="")
    {
        flag = 1;
        newNode->task = "Dummy Task!";
        newNode->date = to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
        newNode->taskIdNumber = countItem;
    }

    //Specification A4 - Overload Constructor
    TodoList tl1 = new TodoList(newNode);
    if(head == NULL)
    {
        head = newNode;
        cout<<"\nSuccessfully added new task!!\n"<<endl;
    }

    else
    {
        //Traverse Till end of list
        TodoList* temp = head;
        while(temp->next != NULL)
        {
            //update temp
            temp = temp->next;
        }
        temp->next = newNode;
    }

    if(flag == 1)
    {
        cout<<"\nSuccessfully added dummy task!!\n"<<endl;
    }
    else
    {
        cout<<"\nSuccessfully added new task!!\n"<<endl;
    }

}

void TodoList:: showTask()
{
    TodoList* temp = head;

    //check if the list is empty
    if(head == NULL)
    {
        cout<<"\nList is Empty. Nothing to show.\n"<<endl;
        return;
    }

    //Traverse the List
    while(temp != NULL)
    {
        //Specification C1 - Overload <<
        cout<<"\n-----------------------------------------------------------------------\n"<<endl;
        cout<<*temp;
        temp = temp->next;
    }
    cout<<"\n-----------------------------------------------------------------------\n"<<endl;
}

void TodoList:: getDate()
{
    time_t now = time(0);

    //Specification A3 - System Date
    tm *dateTime = localtime(&now);
    currentDay = dateTime->tm_mday;
    currentMonth = 1 + dateTime->tm_mon;
    currentYear = 1900 + dateTime->tm_year;
}


void TodoList:: deleteTask(int idNum)
{
    //check if the list is empty
    int flag = 0;
    if(head == NULL)
    {
        cout<<"\nList is Empty. Nothing to delete."<<endl;
        return;
    }

    TodoList *temp;

    //key found on the head node.
    //move to head node to the next and free the head.
    if(head->taskIdNumber == idNum)
    {
        flag = 1;
        temp = head;    //backup to free the memory
        head = head->next;
        free(temp);
    }
    else
    {
        TodoList *current  = head;
        while(current->next != NULL)
        {
            //if yes, we need to delete the current->next node
            if(current->next->taskIdNumber == idNum)
            {
                temp = current->next;
                //node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp);
                flag = 1;
                break;
            }
            //Otherwise, move the current node and proceed
            else
                current = current->next;
        }
    }

    if(flag)
    {
        cout<<"\nSuccessfully Deleted Task Id: "<< idNum<<endl;
    }
    else
    {
        cout<<"\nGiven Task ID Is Not Exist in the Task List: "<< idNum<<endl;
    }
}


void TodoList:: saveTask()
{
    TodoList* newNode = head;
    allTask = "";
    while(newNode != NULL)
    {
        allTask += to_string(newNode->taskIdNumber);
        allTask += ' ';
        allTask += newNode->date;
        allTask += ' ';
        allTask += newNode->task;
        allTask+='\n';
        newNode = newNode->next;
    }
}
void TodoList:: loadDataFromFile()
{
    ifstream infile;
    string line;

    infile.open("TDL.txt",ios_base::in);
    while (getline(infile, line))
    {
        int len = line.length(),i;
        string idNum="", tmpDate="", tmpTask="";
        for( i = 0; i<len; i++)
        {
            if(line[i]==' ')
            {
                break;
            }
            idNum += line[i];
        }
        i++;
        for(; i<len; i++)
        {
            if(line[i]==' ')
            {
                break;
            }
            tmpDate += line[i];
        }
        i++;
        for(; i<len; i++)
        {
            tmpTask += line[i];
        }
        TodoList *newNode = new TodoList ();
        newNode->task = tmpTask;
        newNode->date = tmpDate;
        newNode->taskIdNumber = stoi (idNum);
        countItem = newNode->taskIdNumber;

        if(head == NULL)
        {
            head = newNode;
        }

        else
        {
            TodoList* temp = head;
            while(temp->next != NULL)
            {
                //update temp
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    infile.close();
    remove("TDL.txt");
}
