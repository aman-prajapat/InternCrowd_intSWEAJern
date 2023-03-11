#include <iostream>
using namespace std;
#include <fstream>

int check(string username, string password)
{
    ifstream fin("Data.txt");
    string tusernmae, tpassword;

    // if(is_empty(fin)){
    // if (fin.tellg() == 0)
    // {
        while (!fin.eof())
        {
            fin >> tusernmae >> tpassword;
            if (username == tusernmae)
            {
                if (password == tpassword)
                {
                    cout << "Login Successfully\n"
                         << endl;
                    fin.close();
                    return 0;
                }
                cout << "Password is incorrect\n"
                     << endl;
                fin.close();
                return 0;
            }
        }
        cout << "           No usernmae found\nACCESS DENIED\n";

        fin.close();
}

void saveDetails(string username, string password)
{
    ofstream fout("Data.txt", ios::app);
    fout << username << " " << password << endl;
    fout.close();
}
int main()
{
    int choice;
    string username, password;
lable:
    cout << "\n---------WELCOM TO LOGIN AND REGISTRATION SYSTEM-------\n\n";
    cout << "1 for Login\n2 for Registration\n3 for exit\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        check(username, password);

        break;
    case 2:
        cout << "\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        saveDetails(username, password);
        break;

    case 3:
        abort();
        break;

    default:
        cout << "Enter a valid choice" << endl;
        break;
    }
    goto lable;
    return 0;
}