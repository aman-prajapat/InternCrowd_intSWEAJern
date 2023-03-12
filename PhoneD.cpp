#include<iostream>
using namespace std;
#include<fstream>

void writeInFile(string name,string mobileNumber){
    ofstream fout("PhoneNumber.txt",ios::app);

    fout<<name<<" "<<mobileNumber<<"\n";

    fout.close();
}

void entryNewNumber(){
    string name;
    string mobileNumber;

    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"Enter name:"<<endl;
    getline(cin, name);
    cout<<"Enter mobile number:"<<endl;
    getline(cin, mobileNumber);

    writeInFile(name, mobileNumber);

}

void searchNumber(){

    string name,name1,no;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Enter Name: "<<endl;
    getline(cin,name);

    ifstream fin("PhoneNumber.txt");

    do{
        fin>>name1>>no;
        if(name1 == name)
        break;
    }while(!fin.eof());

    if(name1 == name)
    cout<<"No of that person: "<<no<<endl;

    fin.close();
}

void UpdateFile(){
    string name,name1,no,line,find;
    cout<<"Enter name which no. to be updated: "<<endl;
    cin>>find;

    fstream fin("PhoneNumber.txt");

 
}

int main()
{
    int choice ;
 lable:
    cout<<"1 : Add new\n2 : Search\n3: Delete\n4 : Update\n5 : Exit";
    cin>>choice;
    
    switch (choice){
    case 1:
       entryNewNumber();
        break;
    case 2:
       searchNumber();
        break;
    case 3:
       
        break;
    case 4:
        UpdateFile();
        break;
    case 5:
        abort();
        break;

    default:
        cout << "Enter a vaild selection" << endl;
        break;
    }

goto lable;
    return 0;
}