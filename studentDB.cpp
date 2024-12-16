/*
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program should take two operands from user and performs the operation on those two operands depending upon the operator entered by user. Use a switch statement to select the operation. Finally, display the result.

Code from Object Oriented Programming (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-content/ObjectOrientedProgramming
*/

// BEGINNING OF CODE
#include<iostream>
#include<string.h>
using namespace std;

#define max 100;
class student
{
    string lic, dob, bg;
    public:
    student();
    student(student &);
    ~student()
    {
          cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl;
		  cout<<"RECORD DELETED SUCCESSFULLY";
    }
    friend class info;
};
class info
{
    string name, address, cls;
    char div;
    int roll_no;
    long c_number,*tel;
    static int cnt;
    public:
    void create(student &);
    void display(student &);

    inline static void inccnt()

    {
      cnt++;
    }
    inline static void showcnt()

    {
      cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt;
    }
    info();
    info(info &);
    ~info()
    {
       cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl;
       cout<<"STUDENT DELETED SUCCESSFULLY";
    }
};

int info::cnt;
info::info()
{
        name="Student Name";
        cls="SE-COMP";
        address="Student Address";
        div='A';
        roll_no=0000;
        c_number=8010059559;
        tel = new long;
}
student::student()
{
       lic="LICENCE NUMBER";
       dob="dd/mm/yyyy";
       bg="A+";
}
info::info(info &obj)
{
      this->name=obj.name;
	  this->cls=obj.cls;
      this->address=obj.address;
      this->div=obj.div;
      this->roll_no=obj.roll_no;
      this->c_number=obj.c_number;
      this->tel=obj.tel;
}
student::student(student &obj)
{
     lic=obj.lic;
     dob=obj.dob;
     bg=obj.bg;
}

void info::create(student &obj)
{
cout<<"\nENTER NAME OF THE STUDENT:\t ";
cin>>name;
cout<<"\nENTER CLASS OF THE STUDENT:\t ";
cin>>cls;
cout<<"\nENTER ADDRESS OF THE STUDENT :\t ";
cin>>address;
cout<<"\nENTER DATE OF BIRTH(dd/mm/yyyy) :\t ";
cin>>obj.dob;
cout<<"\nENTER DIVISION OF STUDENT:\t ";
cin>>div;
cout<<"\nENTER ROLL NUMBER OF STUDENT :\t ";
cin>>roll_no;
cout<<"\nENTER BLOOD GROUP OF STUDENT :\t ";
cin>>obj.bg;
cout<<"\nENTER DRIVERS LICENCE NUMBER :\t ";
cin>>obj.lic;
cout<<"\nENTER PHONE NUMBER (CONTACT) :\t ";
cin>>c_number;
long no;
    int total = 0, flag = 0;
    while (flag != 1)
    {
        cout << "ENTER TELEPHONE NUMBER :\t ";
        cin >> *tel;
        no = *tel;
        while (no > 0)
        {
            total++;
            no = no / 10;
        }
        cout << "Total digits in telNo :\t " << total << " (required: 10)" << endl;
        try
        {
            if (total == 10)
            {
                cout << " Correct number....." << endl;
                flag = 1;
            }
            else
            {
                throw(*tel);
            }
        }
        catch (long n)
        {
            cout << " Incorrect number..... " << n << endl;
            total=0;
        }
    }
}


void info::display(student &obj)
{
cout<<" \n *********************** " <<endl;
cout<< "\nNAME OF STUDENT : " <<name<<endl;
cout<< "\nCLASS OF STUDENT : " <<cls<<endl;
cout<< "\nADDRESS OF STUDENT : " <<address<<endl;
cout<< "\nDATE OF BIRTH : " <<obj.dob<<endl;
cout<< "\nDIVISION : " <<div<<endl;
cout<< "\nROLL NO : " <<roll_no<<endl;
cout<< "\nBLOOD GROUP : " <<obj.bg<<endl;
cout<< "\nLICEINCE NUMBER : " <<obj.lic<<endl;
cout<< "\nPHONE NUMBER(CONTACT) : " <<c_number<<endl;
cout << "\n TELEPHONE NUMBER : " << *tel << endl;
cout<<"\n *********************** "<<endl;
}
int main()
{
 int n;
 int ch;
 char ans;

 cout<<"\nENTER NUMBER OF STUDENTS :\t";
 cin>>n;
 cout<<"\n***********************"<<endl;
 info *sobj=new info[n];
 student *pobj=new student[n];

 do
 {
	cout<<"\n #####...MENU...##### \n 1. CREATE STUDENT DATABASE \n 2. DISPLAY STUDENT DATABASE \n 3. COPY CONSTRUCTOR \n 4. DEFAULT CONSTRUCTOR \n 5. DELETE (Destructor) \n 6. EXIT";
	cout<<endl<<" Enter your Choice(1-6):\t ";
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
		for(int i=0;i<n;i++)
		{
		       sobj[i].create(pobj[i]);
		       sobj[i].inccnt();

		}
	}
		break;
 	case 2:
  		{
			sobj[0].showcnt();
			for(int i=0;i<n;i++)
			{
				sobj[i].display(pobj[i]);
			}
    	}
    	break;
	  case 3:
		{
			info obj1;
			student obj2;
			obj1.create(obj2);
			info obj3(obj1);

			student obj4(obj2);
			cout<<endl<<"\n Copy Constructor is called ";
			obj3.display(obj4);
 		}
        break;
	case 4:
 		{
			info obj1;
			student obj2;
			cout<<endl<<"\n Default Constructor is called ";
			obj1.display(obj2);
 		}
 		break;
	case 5:
		{
		delete [] sobj;
 		delete [] pobj;
	    }
	    break;
	case 6:
	    {
        // Exit the program
        cout<<" END OF THE PROGRAM ";
        //return 0;
        break;
	    }
    default:
        cout << "Invalid choice...... Please try again." << endl;
 	}
 	cout<<"\n Want to Continue(y/n): ";
 	cin>>ans;
  }while(ans=='y') 	;


 return 0;
}
// END OF CODE
