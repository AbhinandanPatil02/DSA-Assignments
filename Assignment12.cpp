#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class Hashtable
{
public:
int addr;
Hashtable();
}HT[10];
Hashtable :: Hashtable()
{
for(int i=0; i<10; i++)
HT[i].addr = -1;
}



class Employee : public Hashtable
{
int emp_id;
char salary[10];
char name[10];
char exp[10];
public:
void add_Rec();
void display_Rec();
void search_Rec();
void delete_Rec();
};



void Employee :: add_Rec()
{
int index, count, tablesize = 10;

int location;
cout<<"\n\n How many records..? : ";
cin>>count;
ofstream fout;
fout.open("FileDAF.txt", ios::out);
for (int i = 0; i < count; i++)
{
cout << "\n Enter Employee id: ";
cin >> emp_id;
cout << "\n Enter Employee name: ";
cin >> name;
cout << "\n Enter Employee salary: ";
cin >> salary;
cout << "\n Enter Experience: ";
cin >> exp;
location = fout.tellp(); //...Return location
index = emp_id % tablesize; //....Find index of Hashtable
HT[index].addr = location; //...Store location in Hashtable
//.........Write the Record in File
fout<<emp_id<<" "<<name<<" "<<""<<exp<<" "<<salary<<endl;
}
fout.close();
}
//..........Display records from the file
void Employee :: display_Rec()
{
char buffer[40];
int cnt = 1;
ifstream fin;
//.....Open File for Reading
fin.open("FileDAF.txt", ios::in);
//........Read till End of the File
while(! fin.eof())
{
fin.getline(buffer,40);
cout<<"\n\n Record "<<cnt<<" : "<<buffer;
cnt++;

}
}
//.........Search A Record Randomly
//.....using Emp_No of Employee
void Employee :: search_Rec()
{
int id;
int tablesize = 10;
//.......Accept Emp_id to search
cout<<"\n\t Enter Emp_id to search record: ";
cin>>id;
//......Find index to get the address of record
int index = id % tablesize;
//......read and store the address
int location = HT[index].addr;
//....Open the file for reading
ifstream fin;
fin.open("FileDAF.txt", ios::in);
//.....go to the location
fin.seekg(location, ios::beg);
//.....Read from location
char buffer[40];
fin.getline(buffer, 40);
cout<<"\n\t Found Record : "<<buffer;
}

//........To delete A Record from File.
void Employee ::delete_Rec()
{
int i, id;
int tablesize = 10;
cout<<"\n\t Enter the Emp_id to delete: ";
cin>>id;
int index = id % tablesize;
int location = HT[index].addr;
//....Open the file for reading
ifstream fin;

fin.open("FileDAF.txt", ios::in);
//.....go to the location
fin.seekg(location, ios::beg);
//.....Read from location
char buffer[40];
fin.getline(buffer, 40);
cout<<"\n\t Deleted Record : "<<buffer;
fin.close();
cout<<"\n\t Remaining Records:- ";
//....Open the file for reading
fin.open("FileDAF.txt", ios::in);
for(i=0; i<10; i++)
{
if(HT[i].addr != -1 && HT[i].addr != location)
{
//.....Read from location
fin.seekg(HT[i].addr, ios::beg);
fin.getline(buffer, 40);
cout<<"\n\t Record : "<<buffer;
}
}
fin.close();
}
int main()
{
Employee E;
while(true){
	cout<<"\n\n .......1] Write Records in Direct Access File........";
	cout<<"\n\n .......2] Read Records from Direct Access File........";
	cout<<"\n\n .......3] Search Record in Direct Access File........";
	cout<<"\n\n .......4] Delete Record from Direct Access File........";
	cout<<"\n\n .......5] Exit..........";
	cout<<"\n\n..........Enter your choice : ";
	int res;
	cin>>res;
	if(res==1) E.add_Rec();
	else if(res==2) E.display_Rec();
	else if(res==3) E.search_Rec();
	else if(res==4) E.delete_Rec();
	else if(res==5) break;
	else continue;
}
return 0;
}
