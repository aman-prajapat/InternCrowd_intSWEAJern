#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>

class Birthday
{
    string name;
    int date, month, year;
    Birthday *next = NULL;

public:
    Birthday()
    {
        cin.clear();
        cin.ignore(1000, '\n'); // used to get mutiple words as inpute
        cout << "Enter Name of Family member or Friend: \n";
        getline(cin, name);

        cout << "Enter Date of birth of that person (Formate = -date- -month- -year-): \n";
        cin >> date >> month >> year;
    }
    void assign(Birthday *temp); // this is use to assing addres of next node to previous node
    void display();              // this funtion show all birthday entries
    void DisplayByMonth(int);    // this funtion display all birthday in a selected month
    void save();                 // this funtion will save all entries in a file with append mode
    void SearchByName();
};

void Birthday::SearchByName()
{
    int counter = 0;

    cin.clear();
    cin.ignore(1000, '\n');
    string SearchName;
    cout << "Enter name to search: ";
    getline(cin, SearchName);

    Birthday *temp = this;
    cout << setw(17) << "Name" << setw(20) << "DOB" << endl;

    do
    {
        if (temp == NULL)
        {
            cout << "No Birthday Records Found" << endl;
            break;
        }
        if (temp->name == SearchName)
        {
            cout << setw(20) << temp->name; // setw is use to create table template
            cout << setw(10) << temp->date << "/" << temp->month << "/" << temp->year << "\n";
            counter++;
        }

        temp = temp->next;

        if (temp == NULL && counter == 0)
        {
            cout << "No Birthday Records Found" << endl;
        }
    } while (temp != NULL);
    cout << "***********************************************************\n\n";
}

void Birthday ::save()
{
    ofstream fout;

    fout.open("Birthday.txt", ios::app);
    Birthday *temp = this;
    fout << "List of all DOB entries" << endl;
    fout << setw(15) << "Name" << setw(18) << "DOB" << endl;
    do
    {
        fout << setw(20) << temp->name;
        fout << setw(10) << temp->date << "/" << temp->month << "/" << temp->year << "\n";
        temp = temp->next;
    } while (temp != NULL);
    // fout << "***********************************************************\n";
}
void Birthday::assign(Birthday *temp)
{
    next = temp;
}

void Birthday::DisplayByMonth(int months)
{
    int counter = 0;
    Birthday *temp = this;
    cout << "List of all DOB entries" << endl;
    cout << setw(17) << "Name" << setw(20) << "DOB" << endl;
    do
    {
        if (temp == NULL)
        {
            cout << "No Birthday Records Found" << endl;
            break;
        }
        if (temp->month == months)
        {
            cout << setw(20) << temp->name; // setw is use to create table template
            cout << setw(10) << temp->date << "/" << temp->month << "/" << temp->year << "\n";
            counter++;
        }
        temp = temp->next;
        if (temp == NULL)
        {
            if (counter == 0)
                cout << "No Birthday Records Found" << endl;
            else
                cout << "Total Record found are: " << counter << endl;
        }
    } while (temp != NULL);
    cout << "***********************************************************\n";
}

void Birthday::display()
{
    Birthday *temp = this;
    cout << "List of all DOB entries" << endl;
    cout << setw(15) << "Name" << setw(18) << "DOB" << endl;
    do
    {
        cout << setw(20) << temp->name;
        cout << setw(10) << temp->date << "/" << temp->month << "/" << temp->year << "\n";
        temp = temp->next;
    } while (temp != NULL);
    cout << "***********************************************************\n";
}
int main()
{
    Birthday *instant;
    Birthday *last;
    int total_entries = 0;
    int choice;
label:

    cout << "----------------------------------------------" << endl;
    cout << "         -------BIRTHDAY LIST---------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1 for Birthday entry: \n2 to show all data: \n";
    cout << "3 to get Birthday list accourding to Months : \n";
    cout << "4 to search friend by name: \n5 for exit" << endl;
    cout << "----------------------------------------------" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        if (total_entries == 0)
        {
            instant = new Birthday;
            last = instant;
            total_entries++;
        }
        else
        {
            Birthday temp;
            last->assign(&temp);
            last = &temp;
            total_entries++;
        }
        break;
    case 2:
        instant->display();
        break;
    case 3:
        cout << "Enter which Month data do you want (select from 1-12): " << endl;
        cin >> choice;
        instant->DisplayByMonth(choice);
        break;
    case 4:
        instant->SearchByName();
        break;
    case 5:
        instant->save();
        cout << "Your Data hass been recorded and saved \n";
        abort();
        break;

    default:
        cout << "Enter a vaild selection" << endl;
        break;
    }

    goto label;

    return 0;
}