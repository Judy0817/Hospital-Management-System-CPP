//header files
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<Windows.h>

//function definition 
void AdminMenu(int t);
void UserMenu(int t);
void AdminPassword(int t);
void ChangePassword(int t);
void updatePatient(int t);
void updateDocStaff(int t,int option1);
void EmergencyyPatient(int t,int option1);

using namespace std;

//structure
struct Stay
{
	int input;
	void wait(int t)
	{
		if(t==1) //education mode
		   cout<<"\n\n\n\n\t\t\tStruct Stay : Function - wait\n";
		cout << "\n\n\t\tGo to main screen - Press 1\n\n\t\tStay another time - Press 2\n\n\t\t";
		cin >> input;
		if (input == 2)
		  Sleep(8000);
	}	
};

//classess
	
/* -----------------------------------------
   class name - UserInfo
   constructors - UserInfo()
				  UserInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~UserInfo()
   -----------------------------------------*/         
class UserInfo 
{
private:
	string all,firstName,secondName,pos,yrs, id, NIC, telNum, mail;
	char date[60], time[60];
	int age, salary;
public:
	UserInfo(); //Constructor
	UserInfo(int t); //Constructor with input parameter
	void getDetails(int t,char f1[],char f2[],char f3[]); 	// Getting Information of the nursing staff & doctors
	void showDetails(int t,char f1[]);					// Displaying information of the nursing staff & doctors
	void showList(int t,char f1[]);						// Displaying names of the nursing staff & doctors
	void availability(int t,char f1[]); 					// Displaying available times of the nursing staff & doctors
	void modifyDetails(int t,char f1[],char f2[]); 		// Updating the information of the nursing staff & doctors
    void deleteDetails(int t,char f1[],char f2[]); 		// Deleting the informations of the nursing staff & doctors
   
};
//class UserInfo
//constructor
UserInfo::UserInfo()
{
}
UserInfo::UserInfo(int t)
{
		if(t==1) //education mode
		  cout<<"\n\n\t\t\t\t\t\tClass UserInfo - Constructor\n";
}
//member functions
void UserInfo::getDetails(int t,char f1[],char f2[],char f3[]) // Getting Information of the nursing staff & doctors
{
		system("cls");
		if(t==1)
		  cout<<"\n\t\t\tClass UserInfo : Member function - getDetails\n";
	    fstream file;
	    cout << "\n\t\t ---------- Add Information ----------\n";
	    cout << "\n\t\t **** Spaces are not allowed ****\n";
		cout << "\n\tEnter first Name :";
		cin >> firstName;
		cout << "\n\tEnter second Name :";
		cin >> secondName;
		cout << "\n\tEnter Age :";
		cin >> age;
		cout << "\n\tEnter User ID :";
		cin >> id;
		cout << "\n\tEnter NIC Number :";
		cin >> NIC;
		cout << "\n\tEnter Mobile Number :";
		cin >> telNum;
		cout << "\n\tEnter Email Address :";
		cin >> mail;
		cout << "\n\tEnter Salary :";
		cin >> salary;
		cout << "\n\tEnter Working Position :";
		cin >> pos;
		cout << "\n\tEnter Working Period :";
		cin >> yrs;
		cout << "\n\tEnter Working Dates(seperated by ,) :";
		cin.get();
		cin.getline(date,60);
		cout << "\n\tEnter Working Time(seperated by -):";
		cin.getline(time,60);
		file.open(f1,ios::app|ios::out);
    	file<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<id<<" "<<NIC<<" "<<telNum<<" "<<mail<<" "<<salary<<" "<<pos<<" "<<yrs<<"\n";
    	file.close();
    	file.open(f2,ios::app|ios::out);
    	file<<" "<<firstName<<" "<<secondName<<" "<<pos<<"\n";
    	file.close();
    	file.open(f3,ios::app|ios::out);
    	file<<" "<<firstName<<" "<<secondName<<" "<<pos<<" "<<date<<" "<<time<<"\n";
    	file.close();
    	
		cout << "\n    ..... Information has been saved ..... \n";
		Sleep(1000);
	}
void UserInfo::showDetails(int t,char f1[]) // Displaying information of the nursing staff & doctors
{
	system("cls");
	if(t==1)
	  cout<<"\n\t\t\tClass UserInfo : Member function - showDetails\n";
	fstream file;
	int total=0;
	cout << "\n\t\t ---------- Display Information ----------\n";
	file.open(f1,ios::in);
	if (!file)
	{
		cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
		Sleep(1000);
		file.close();
	}
	else
	{
		file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
		while(!file.eof())
		{
			cout << "\n\n\tFull Name          -	" << firstName<<" "<<secondName;
			cout << "\n\tAge                -	" << age;
			cout << "\n\tUser ID            -	" << id;
			cout << "\n\tNIC Number         -	" << NIC;
			cout << "\n\tMobile_Number	   -	" << telNum;
			cout << "\n\tEmail Address	   -	" << mail;
			cout << "\n\tSalary             -	" << salary;
			cout << "\n\tWorking Position   -	" << pos;
			cout << "\n\tWorking Period	   -	" << yrs;
			Sleep(1000);
			file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
			total++;
		}
		 if(total==0)
        {
        	cout<<"\n\t\tNo Any Data At This Moment ........\n";
        	Sleep(1000);
		}
		else
		{
			struct Stay s;
			s.wait(t);
		}
	}
    file.close();
}
void UserInfo::showList(int t,char f1[]) 	// Displaying names of the nursing staff & doctors
{
		if(t==1)
		  cout<<"\n\t\t\tClass UserInfo : Member function - showList\n";
    	fstream file;
    	int total=0;
    	file.open(f1,ios::in);
		if (!file)
		{
			cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
			file.close();
		}
		else
		{
			file>>firstName>>secondName>>pos;
			cout << "\n\n\tFull Name          	";
			cout << "\t\tWorking Position   	";
			cout<<endl;
			while(!file.eof())
			{
				cout <<"\n\t"<<firstName<<" "<<secondName;
				cout << "\t\t				" << pos;
				Sleep(1000);
				file>>firstName>>secondName>>pos;
				total++;
			}
			 if(total==0)
	        {
	        	cout<<"\n\t\tNo Any Data At This Moment ........\n";
	        	Sleep(1000);
			}
			else
			{
				struct Stay s;
				s.wait(t);
			}
		}
	    file.close();
	}
void UserInfo::availability(int t,char f1[]) 	// Displaying available times of the nursing staff & doctors
{
		if(t==1)
		  cout<<"\n\t\t\tClass UserInfo : Member function - availability\n";
    	fstream file;
    	int total=0;
    	file.open(f1,ios::in);
		if (!file)
		{
			cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
			file.close();
		}
		else
		{
			file>>firstName>>secondName>>pos>>date>>time;
			while(!file.eof())
			{
				cout << "\n\n\tFull Name        	-	" << firstName<<" "<<secondName;
				cout <<"\n\tWorking Position  	-	" << pos;
				cout<<"\n\tAvailable Dates		-	"<<date;
				cout<<"\n\tAvailable Times		-	"<<time;
				Sleep(1000);
				file>>firstName>>secondName>>pos>>date>>time;
				total++;
			}
			 if(total==0)
	        {
	        	cout<<"\n\t\tNo Any Data At This Moment ........\n";
	        	Sleep(1000);
			}
			else
			{
				struct Stay s;
				s.wait(t);
			}
		}
	    file.close();
	}
void UserInfo::modifyDetails(int t,char f1[],char f2[]) // Updating the information of the nursing staff & doctors
{
		system("cls");
		if(t==1)
		  cout<<"\n\t\t\tClass UserInfo : Member function - modifyDetails\n";
    	fstream file,file1;
    	string iNum;
    	int found=0;
    	cout << "\n\t\t ---------- Modify Information ----------\n";
    	file.open(f1,ios::in);
    	if(!file)
    	{
    		cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
			file.close();
		}
		else
		{
			cout<<"\n\tEnter the User ID you want to modify :";
			cin>>iNum;
			file1.open(f2,ios::app|ios::out);
			file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
			while(!file.eof())
			{
				if(iNum!=id)
				{
					file1<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<id<<" "<<NIC<<" "<<telNum<<" "<<mail<<" "<<salary<<" "<<pos<<" "<<yrs<<"\n";
				}
				else
				{
					cout << "\n\tEnter first Name :";
					cin >> firstName;
					cout << "\n\tEnter second Name :";
					cin >> secondName;
					cout << "\n\tEnter Age :";
					cin >> age;
					cout << "\n\tEnter User ID :";
					cin >> id;
					cout << "\n\tEnter NIC Number :";
					cin >> NIC;
					cout << "\n\tEnter Mobile Number :";
					cin >> telNum;
					cout << "\n\tEnter Email Address :";
					cin >> mail;
					cout << "\n\tEnter Salary :";
					cin >> salary;
					cout << "\n\tEnter Working Position :";
					cin >> pos;
					cout << "\n\tEnter Working Period :";
					cin >> yrs;
					cout << "\n    ..... Information has been saved ..... \n";
					Sleep(1000);
			        file1<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<id<<" "<<NIC<<" "<<telNum<<" "<<mail<<" "<<salary<<" "<<pos<<" "<<yrs<<"\n";
			        found++;
				}
    	        file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
    	        
			}
			if(found==0)
			{
				cout << "\n\t\t........ No Any Data At This Moment ........\n";
			}
			file1.close();
			file.close();
			remove(f1);
			rename(f2,f1);	        
	    }
	}			
void UserInfo::deleteDetails(int t,char f1[],char f2[]) // Deleting the informations of the nursing staff & doctors
{
   	    system("cls");
   	    if(t==1)
		  cout<<"\n\t\t\tClass UserInfo : Member function - deleteDetails\n";
    	fstream file,file1;
    	string iNum;
    	int found=0;
    	cout << "\n\t\t ---------- Delete Information ----------\n";
    	file.open(f1,ios::in);
    	if(!file)
    	{
    		cout << "\n\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
		}
		else
		{
			cout<<"\n\tEnter the User ID you want to delete :";
			cin>>iNum;
			file1.open(f2,ios::app|ios::out);
			file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
			while(!file.eof())
			{
				if(iNum!=id)
				{
					file1<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<id<<" "<<NIC<<" "<<telNum<<" "<<mail<<" "<<salary<<" "<<pos<<" "<<yrs<<"\n";
				}
				file>>firstName>>secondName>>age>>id>>NIC>>telNum>>mail>>salary>>pos>>yrs;
				
			}
			if(found==0)
			{
				cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
				Sleep(1000);
			}
			file1.close();
			file.close();
			remove(f1);
			rename(f2,f1);
		}
    }


/* -----------------------------------------
   class name - StaffInfo
   constructors - StaffInfo()
				  StaffInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~StaffInfo()
   -----------------------------------------*/  
class StaffInfo:public UserInfo //child class of UserInfo class
{
public:
	StaffInfo(int t)
	{
		if(t==1) //education mode
		  cout<<"\n\n\t\t\t\t\t\tClass StaffInfo - Constructor\n";
	}	
};


/* -----------------------------------------
   class name - DocInfo
   constructors - DocInfo()
				  DocInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~DocInfo()
   -----------------------------------------*/ 
class DocInfo:public UserInfo //child class of UserInfo class
{
public:
	DocInfo(int t)
	{
		if(t==1) //education mode
		  cout<<"\n\n\t\t\t\t\t\tClass DocInfo - Constructor\n";
	}
};


/* -----------------------------------------
   class name - PatientInfo
   constructors - PatientInfo()
				  PatientInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~PatientInfo()
   -----------------------------------------*/ 
class PatientInfo 
{
private:
	int age,wardNo,record;
	double amount;
	string firstName,secondName,telNum,gtelNum,NIC,problem,mail,docName1,docName2,date,time,relationship;
public:
	PatientInfo(); //constructor
	PatientInfo(int t); //constructor with input parameter
	void getDetails(int t,int type, int id, char f1[]); 						//getting details of the patient
	void showDetails(int t,int type,int id, char f1[]); 						//displaying details of the patient
	void modifyDetails(int t,int type,int id, char f1[],char f2[]); 			//updating the details of the patient
    void deleteDetails(int t,int type,int id, char f1[],char f2[],char f3[]);	//deleting the details of the patient
   
};

//class PatientInfo
//constructor
PatientInfo::PatientInfo(){}
PatientInfo::PatientInfo(int t)
{
		if(t==1) //education mode
		  cout<<"\n\n\t\t\tClass PatientInfo - Constructor\n";
}
//member functions
void PatientInfo::getDetails(int t,int type, int id, char f1[]) //getting details of the patient
{
		if(t==1)
		  cout<<"\n\t\t\tClass PatientInfo : Member function - getDetails\n";
		ifstream in("recordID.txt");
		in>>record;
		in.close();
		cout<<"\nRecord ID :"<<record<<endl;
	    fstream file;
	    if(type==3)
    	  cout << "\n\t\t ---------- Emergency Patient----------";
    	else if(type==4)
    	  cout << "\n\t\t ---------- Admitted Patient ----------";
		else if(type==5)
		  cout << "\n\n\t\t ---------- Guardient ----------";
    	else{}
	    cout << "\n\n\t\t ---------- Add Information ----------\n";
	     cout << "\n\t\t **** Spaces are not allowed ****\n";
		cout << "\n\tEnter first name :";
		cin >> firstName;
		cout << "\n\tEnter second name :";
		cin >> secondName;
		cout << "\n\tEnter Age :";
		cin >> age;
		cout << "\n\tEnter Mobile Number :";
		cin >> telNum;
		file.open(f1,ios::app|ios::out);
    	file<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" ";
    	switch(type)
    	{
    		case 1:
    			{
    			    cout << "\n\tEnter Doctor's first Name :";
					cin >> docName1;
					cout << "\n\tEnter Doctor's second Name :";
					cin >> docName2;
    			    cout << "\n\tEnter Appointment Date You Want: ";
					cin >> date;
					cout << "\n\tEnter Appointment Time You Want: ";
					cin >> time;
					amount=1500;
					cout<<"\n\n\t\t\t Your Channeling Fee is "<<amount;
					cout<<"\n\n\t\t\t Your Appoinment No is "<<id;
					Sleep(2000);
				    file<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
				    
				    system("cls");
					cout << "\n\n\t\t-----Patient Details-----" << endl;
				    cout << "\n\tFull Name           -	" << firstName<<" "<<secondName;
					cout << "\n\tAge               -	" << age;
					cout << "\n\tMobile Number	  -	" << telNum;
					cout << "\n\tDoctor Full Name  -	" << docName1<<" "<<docName2;
					cout << "\n\tDate              -	" << date;
					cout << "\n\tTime Range        -	" << time;
					cout << "\n\tPayment           -	Rs. " << amount;
					cout << "\n\tUser ID           -	" << id;
					struct Stay s;
					s.wait(t);
					break;
					
				}
			case 2:
				{
					cout << "\n\tEnter Email Address :";
					cin >> mail;
					cout << "\n\tEnter Secondary Mobile Number :";
					cin >> gtelNum;
    			    cout << "\n\tEnter Doctor's first Name :";
					cin >> docName1;
					cout << "\n\tEnter Doctor's second Name :";
					cin >> docName2;
    			    cout << "\n\tEnter Appointment Date You Want: ";
					cin >> date;
					cout << "\n\tEnter Appointment Time You Want: ";
					cin >> time;
					amount=1800;
					cout<<"\n\n\t\t\t Your Channeling Fee is "<<amount;
					cout<<"\n\t\t\t Your Appoinment No is "<<id;
					cout<<"\n\n\n\t ----Channeling time, Channeling media (zoom link or phone call) and other information";
					cout<<"\n\t       about your telemedicine facility will be provided via SMS and Email ----";
					cout<<"\n\n\t\t\t    Thank You for joining our Telemedicine service !!!! \n\n";
					Sleep(2000);
				    file<<" "<<mail<<" "<<gtelNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
				    
				    system("cls");
					cout << "\n\n\t\t-----Patient Details-----" << endl;
					cout << "\n\tFull Name               -	" << firstName<<" "<<secondName;
					cout << "\n\tAge                      -	  " << age;
					cout << "\n\tMobile Number	         -	  " << telNum;
					cout << "\n\tEmail Address	         -	  " << mail;
					cout << "\n\tSecondary Mobile Number  -   " << gtelNum;
					cout << "\n\tDoctor Full Name         -	  " << docName1<<" "<<docName2;
					cout << "\n\tDate                     -	  " << date;
					cout << "\n\tTime Range               -	  " << time;
					cout << "\n\tPayment                  -	  Rs. " << amount;
					cout << "\n\tUser ID                  -	  " << id;
					struct Stay s;
					s.wait(t);
					break;
				}
			case 3:
				{
					cout << "\n\tEnter NIC Number :";
					cin >> NIC;
    			    cout << "\n\tEnter Doctor's first Name :";
					cin >> docName1;
					cout << "\n\tEnter Doctor's second Name :";
					cin >> docName2;
					cout<<"\n\n\t\t\t Your ID is "<<id;
				    file<<" "<<NIC<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
					break;
				}
				
			case 4:
				{
					cout << "\n\tEnter NIC Number :";
					cin >> NIC;
					cout << "\n\tPatient Problem  : ";
					cin >> problem;
					cout << "\n\tWard No. : ";
					cin >> wardNo;
    			    cout << "\n\tEnter Doctor's first Name :";
					cin >> docName1;
					cout << "\n\tEnter Doctor's second Name :";
					cin >> docName2;
					cout<<"\n\n\t\t\t Your ID is "<<id;
				    file<<" "<<NIC<<" "<<problem<<" "<<wardNo<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
					break;
				}
				
			case 5:
				{
					cout << "\n\tEnter NIC number :";
					cin >> NIC;
    			    cout << "\n\tEnter Your Relationship with the patient :";
					cin >> relationship;
					cout<<"\n\n\t\t\t Your ID is "<<id;
				    file<<" "<<NIC<<" "<<relationship<<" "<<id<<"\n";
					break;
				}
			default:
				{
					cout << "\n\t    ..... Invalid Input ..... \n";
						Sleep(500);
					break;
				}
				
				
		}
    	file.close();
		ofstream out("recordID.txt");
		{
			cin.sync();
		    out <<++record;
		}
		out.close();
		cout << "\n\n\t\tInformation has been saved. \n";
		Sleep(1000);
	}
void PatientInfo::showDetails(int t,int type,int id, char f1[]) //displaying details of the patient
{
		if(t==1)
		  cout<<"\n\t\t\tClass PatientInfo : Member function - showDetails\n";
    	fstream file;
    	int total=0;
    	if(type==3)
    	  cout << "\n\t\t ---------- Emergency Patient----------";
    	else if(type==4)
    	  cout << "\n\t\t ---------- Admitted Patient ----------";
		else if(type==5)
		  cout << "\n\n\t\t ---------- Guardient ----------";
    	else{}
    	cout << "\n\n\t\t ---------- Display Information ----------\n";
    	file.open(f1,ios::in);
		if (!file)
		{
			cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
			file.close();
		}
		else
		{
			switch(type)
    		{
    			case 1:
    				{
    					file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
    					while(!file.eof())
						{
							cout << "\n\n\tRecord ID         -	" << record;
							cout << "\n\tFull Name         -	" << firstName<<" "<<secondName;
							cout << "\n\tAge               -	" << age;
							cout << "\n\tMobile Number	  -	" << telNum;
							cout << "\n\tDoctor Full Name  -	" << docName1<<" "<<docName2;
							cout << "\n\tDate              -	" << date;
							cout << "\n\tTime Range        -	" << time;
							cout << "\n\tPayment           -	Rs. " << amount;
							cout << "\n\tUser ID           -	" << id;
							file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
							total++;
							Sleep(1000);	
						}
						break;
					}
				case 2:
    				{
    					file>>record>>firstName>>secondName>>age>>telNum>>mail>>gtelNum>>docName1>>docName2>>date>>time>>amount>>id;
    					while(!file.eof())
						{
							cout << "\n\n\tRecord ID                -	" << record;
							cout << "\n\tFull Name                -	" << firstName<<" "<<secondName;
							cout << "\n\tAge                      -	" << age;
							cout << "\n\tMobile Number	         -	" << telNum;
							cout << "\n\tEmail Address	         -	" << mail;
							cout << "\n\tSecondary Mobile Number  -	" << gtelNum;
							cout << "\n\tDoctor Full Name         -	" << docName1<<" "<<docName2;
							cout << "\n\tDate                     -	" << date;
							cout << "\n\tTime Range               -	" << time;
							cout << "\n\tPayment                  -	Rs.	" << amount;
							cout << "\n\tUser ID                  -	" << id;
							file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
							total++;
							Sleep(1000);	
						}
						break;
					}
				case 3:
    				{
    					file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
    					while(!file.eof())
						{
							cout << "\n\n\tRecord ID           -	" << record;
							cout << "\n\tFull Name           -	" << firstName<<" "<<secondName;
							cout << "\n\tAge                 -	" << age;
							cout << "\n\tMobile Number	    -	" << telNum;
							cout << "\n\tNIC Number	    -	" << NIC;
							cout << "\n\tDoctor Full Name    -	" << docName1<<" "<<docName2;
							cout << "\n\tUser ID             -	" << id;
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
							total++;
							Sleep(1000);
						}
						break;
					}
				case 4:
    				{
    					file>>record>>firstName>>secondName>>age>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
    					while(!file.eof())
						{
							cout << "\n\n\tRecord ID                -	" << record;
							cout << "\n\tFull Name                -	" << firstName<<" "<<secondName;
							cout << "\n\tAge                      -	" << age;
							cout << "\n\tMobile Number	         -	" << telNum;
							cout << "\n\tNIC Number	         -	" << NIC;
							cout << "\n\tProblem                  -	" << problem;
							cout << "\n\tWard Number              -	" << wardNo;
							cout << "\n\tDoctor Full Name         -	" << docName1<<" "<<docName2;
							cout << "\n\tUser ID                  -	" << id;
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
							total++;
							Sleep(1000);
						}
						break;
					}
					
				case 5:
    				{
    					file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;
    					while(!file.eof())
						{
							cout << "\n\n\tRecord ID                    -	" << record;
							cout << "\n\tFull Name                    -	" << firstName<<" "<<secondName;
							cout << "\n\tAge                          -	" << age;
							cout << "\n\tMobile Number	             -	" << telNum;
							cout << "\n\tNIC Number	             -	" << NIC;
							cout << "\n\tRelationship With Patient    -	" << relationship;
							cout << "\n\tUser ID                      -	" << id;
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;
							total++;
							Sleep(1000);	
						}
						break;
					}
			}
			if(total==0)
	        {
	        	cout<<"\n\t\tNo Any Data At This Moment ........\n";
	        	Sleep(1000);
			}
			else if(type!=3 & type!=4)
			{
				struct Stay s;
				s.wait(t);
			}
			else{}
		}
	    file.close();
	}   
void PatientInfo::modifyDetails(int t,int type,int id, char f1[],char f2[]) 	//updating the details of the patient
{
		system("cls");
		if(t==1)
		  cout<<"\n\t\t\tClass PatientInfo : Member function - modifyDetails\n";
    	fstream file,file1;
    	int iNum;
    	int found=0;
    	if(type==3)
    	  cout << "\n\t\t ---------- Emergency Patient----------";
    	else if(type==4)
    	  cout << "\n\t\t ---------- Admitted Patient ----------";
		else if(type==5)
		  cout << "\n\n\t\t ---------- Guardient ----------";
    	else{}
    	cout << "\n\n\t\t ---------- Modify Information ----------\n";
    	file.open(f1,ios::in);
    	if(!file)
    	{
    		cout << "\t\tFile Open Error !!!!\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
			file.close();
		}
		else
		{
			cout<<"\n\tEnter the Record ID you want to modify :";
			cin>>iNum;
			file1.open(f2,ios::app|ios::out);
			switch(type)
			{
				case 1:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
							}
							else
							{
								cout << "\n\tFirst Name              -	";
								cin >> firstName;
								cout << "\n\tsecondt Name              -	";
								cin >> secondName;
								cout << "\n\tAge               -	";
								cin>> age;
								cout << "\n\tMobile Number	   -	";
								cin>>telNum;
								cout << "\n\tDoctor First Name       -	";
								cin>>docName1;
								cout << "\n\tDoctor second Name       -	";
								cin>>docName2;
								cout << "\n\tDate              -	";
								cin>>date;
								cout << "\n\tTime Range        -	";
								cin>>time;
								cout << "\n\tPayment           -	Rs. ";
								cin>>amount;
								cout << "\n   ..... Information has been saved ..... \n";
								Sleep(2000);
						        file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
						        found++;
							}
							file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
							
						}
						if(found==0)
						{
							cout << "\n\t\t........ No Any Data At This Moment ........\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 2:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>mail>>gtelNum>>docName1>>docName2>>date>>time>>amount>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<mail<<" "<<gtelNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
							}
							else
							{
								cout << "\n\tFirst Name                     -	";
								cin>>firstName;
								cout << "\n\tSecond Name                     -	";
								cin>>secondName;
								cout << "\n\tAge                      -	  ";
								cin>>age;
								cout << "\n\tMobile Number	          -	  ";
								cin>>telNum;
								cout << "\n\tEmail Address	          -	  ";
								cin>>mail;
								cout << "\n\tSecondary Mobile Number  -   ";
								cin>>gtelNum;
								cout << "\n\tDoctor First Name              -	  ";
								cin>>docName1;
								cout << "\n\tDoctor Second Name              -	  ";
								cin>>docName2;
								cout << "\n\tDate                     -	  ";
								cin>>date;
								cout << "\n\tTime Range               -	  ";
								cin>>time;
								cout << "\n\tPayment                  -	  Rs. ";
								cin>>amount;
								cout << "\n   ..... Information has been saved ..... \n";
								Sleep(2000);
						        file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<mail<<" "<<gtelNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
						        found++;
							}
							file>>record>>firstName>>secondName>>age>>telNum>>mail>>gtelNum>>docName1>>docName2>>date>>time>>amount>>id;
							
						}
						if(found==0)
						{
							cout << "\n\t\t........ No Any Data At This Moment ........\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 3:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							else
							{
								cout << "\n\tFirst Name                     -	";
								cin>>firstName;
								cout << "\n\tSecond Name                     -	";
								cin>>secondName;
								cout << "\n\tAge                      -	  ";
								cin>>age;
								cout << "\n\tMobile Number	          -	  ";
								cin>>telNum;
								cout << "\n\tNIC Number	              -	  ";
								cin>>NIC;
								cout << "\n\tDoctor First Name              -	  ";
								cin>>docName1;
								cout << "\n\tDoctor Second Name              -	  ";
								cin>>docName2;
								cout << "\n   ..... Information has been saved ..... \n";
								Sleep(2000);
						        file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
						        found++;
							}
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
							
						}
						if(found==0)
						{
							cout << "\n\t\t........ No Any Data At This Moment ........\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 4:
					{
						file>>record>>firstName>>secondName>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<problem<<" "<<wardNo<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							else
							{
								cout << "\n\tFirst Name                     -	";
								cin>>firstName;
								cout << "\n\tSecond Name                     -	";
								cin>>secondName;
								cout << "\n\tAge                      -	  ";
								cin>>age;
								cout << "\n\tMobile Number	          -	  ";
								cin>>telNum;
								cout << "\n\tNIC Number	              -	  ";
								cin>>NIC;
								cout << "\n\tProblem                  -   ";
								cin>>problem;
								cout << "\n\tWard Number              -	  ";
								cin>>wardNo;
								cout << "\n\tDoctor First Name              -	  ";
								cin>>docName1;
								cout << "\n\tDoctor Second Name              -	  ";
								cin>>docName2;
								cout << "\n   ..... Information has been saved ..... \n";
								Sleep(2000);
						        	file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<problem<<" "<<wardNo<<" "<<docName1<<" "<<docName2<<" "<<"\n";
						        found++;
							}
							file>>record>>firstName>>secondName>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
							
						}
						if(found==0)
						{
							cout << "\n\t\t........ No Any Data At This Moment ........\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 5:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<relationship<<"\n";
							}
							else
							{
								cout << "\n\tFirst Name                     -	";
								cin>>firstName;
								cout << "\n\tSecond Name                     -	";
								cin>>secondName;
								cout << "\n\tAge                      -	  ";
								cin>>age;
								cout << "\n\tMobile Number	          -	  ";
								cin>>telNum;
								cout << "\n\tNIC Number	              -	  ";
								cin>>NIC;
								cout << "\n\tRelationship With Patient -   ";
								cin>>relationship;
								cout << "\n   ..... Information has been saved ..... \n";
								Sleep(2000);
						        file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<relationship<<"\n";
						        found++;
							}
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;
							
						}
						if(found==0)
						{
							cout << "\n\t\t........ No Any Data At This Moment ........\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}		
			}	
		}
	}
void PatientInfo::deleteDetails(int t,int type,int id, char f1[],char f2[],char f3[]) //deleting the details of the patient
{
   	    system("cls");
   	    if(t==1)
		  cout<<"\n\t\t\tClass PatientInfo : Member function - deleteDetails\n";
    	fstream file,file1,file2;
    	int iNum;
    	int found=0;
    	if(type==3)
    	  cout << "\n\t\t ---------- Emergency Patient----------";
    	else if(type==4)
    	  cout << "\n\t\t ---------- Admitted Patient ----------";
		else if(type==5)
		  cout << "\n\n\t\t ---------- Guardient ----------";
    	else{}
    	cout << "\n\n\t\t ---------- Delete Information ----------\n";
    	file.open(f1,ios::in);
    	if(!file)
    	{
    		cout << "\n\n\t\tNo Any Data At This Moment ........\n";
			Sleep(1000);
		}
		else
		{
			cout<<"\n\tEnter the Record ID you want to delete :";
			cin>>iNum;
			file1.open(f2,ios::app|ios::out);
			file2.open(f3,ios::app|ios::out);
			switch(type)
			{
				case 1:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
							}
								file>>record>>firstName>>secondName>>age>>telNum>>docName1>>docName2>>date>>time>>amount>>id;
							
						}
						if(found==0)
						{
							cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 2:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>mail>>gtelNum>>docName1>>docName2>>date>>time>>amount>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<mail<<" "<<gtelNum<<" "<<docName1<<" "<<docName2<<" "<<date<<" "<<time<<" "<<amount<<" "<<id<<"\n";
							}
							file>>record>>firstName>>secondName>>age>>telNum>>mail>>gtelNum>>docName1>>docName2>>date>>time>>amount>>id;
							
						}
						if(found==0)
						{
							cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
							Sleep(1000);
						}
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 3:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							else
							{
								
									file2<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>docName1>>docName2>>id;
							
						}
						if(found==0)
						{
							cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
							Sleep(1000);
						}
						file2.close();
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 4:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<problem<<" "<<wardNo<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							else
							{
								
								file2<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<problem<<" "<<wardNo<<" "<<docName1<<" "<<docName2<<" "<<id<<"\n";
							}
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>problem>>wardNo>>docName1>>docName2>>id;
						}
						if(found==0)
						{
							cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
							Sleep(1000);
						}
						file2.close();
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
				case 5:
					{
						file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;
						while(!file.eof())
						{
							if(iNum!=record)
							{
								file1<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<relationship<<" "<<id<<"\n";
							}
							else
							{
								file2<<" "<<record<<" "<<firstName<<" "<<secondName<<" "<<age<<" "<<telNum<<" "<<NIC<<" "<<relationship<<" "<<id<<"\n";
							}
							file>>record>>firstName>>secondName>>age>>telNum>>NIC>>relationship>>id;	
						}
						if(found==0)
						{
							cout<<"\n\t\t !!!! successfuly deleted !!!!\n";
							Sleep(1000);
						}
						file2.close();
						file1.close();
						file.close();
						remove(f1);
						rename(f2,f1);
						break;
					}
					default:{
						break;
					}		
			}	
		}
	}
		
			
/* -----------------------------------------
   class name - PatientAppoinment
   constructors - PatientAppoinment()
				  PatientAppoinment(int t)
   member functions - public , return type - void
   destructor - ~PatientAppoinment()
   -----------------------------------------*/ 
class PatientAppoinment:public PatientInfo //child class of PatientInfo class
{		
public:
	static int AppoinmentNo1; //static variable
	PatientAppoinment(int t);
};


/* -----------------------------------------
   class name - Telemedicine
   constructors - Telemedicine()
				  Telemedicine(int t)
   member functions - public , return type - void
   destructor - ~Telemedicine()
   -----------------------------------------*/ 
class Telemedicine:public PatientInfo //child class of PatientInfo class
{
public:
	static int tAppoinmentNo; //static variable
	Telemedicine(int t); //constructor
};


/* -----------------------------------------
   class name - EmergencyPatient
   constructors - EmergencyPatient()
				  EmergencyPatient(int t)
   member functions - public , return type - void
   destructor - ~EmergencyPatient()
   -----------------------------------------*/ 
class EmergencyPatient:public PatientInfo //child class of PatientInfo class
{	
public:
	static int AppoinmentNo2; //static variable
	EmergencyPatient(int t); //constructor
};


/* -----------------------------------------
   class name - AdmittedPatient
   constructors - AdmittedPatient()
				  AdmittedPatient(int t)
   member functions - public , return type - void
   destructor - ~AdmittedPatient()
   -----------------------------------------*/
class AdmittedPatient:public PatientInfo //child class of PatientInfo class
{
public:
	static int AppoinmentNo3; //static variable
	AdmittedPatient(int t); //constructor
};


/* -----------------------------------------
   class name - EGuardientInfo
   constructors - EGuardientInfo()
				  EGuardientInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~EGuardientInfo()
   -----------------------------------------*/ 
class EGuardientInfo:public PatientInfo //child class of PatientInfo class
{	
public:
	static int AppoinmentNo4; //static variable
	EGuardientInfo(int t); //constructor
};


/* -----------------------------------------
   class name - AGuardientInfo
   constructors - AGuardientInfo()
				  AGuardientInfo(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~AGuardientInfo()
   -----------------------------------------*/
class AGuardientInfo:public PatientInfo //child class of PatientInfo class
{	
public:
	static int AppoinmentNo5; //static variable
	AGuardientInfo(int t); //constructor
};


// child classes of PatientInfo class
//assign values to static variables
int PatientAppoinment::AppoinmentNo1=0;
int Telemedicine::tAppoinmentNo=0;
int EmergencyPatient::AppoinmentNo2=0;
int AdmittedPatient::AppoinmentNo3=0;
int EGuardientInfo::AppoinmentNo4=0;
int AGuardientInfo::AppoinmentNo5=0;

//constructors
PatientAppoinment::PatientAppoinment(int t)	//class PatientAppoinment constructor
{
	AppoinmentNo1++; //get appoinment numbers
	if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass PatientAppoinment - Constructor\n";
}
Telemedicine::Telemedicine(int t)	//class Telemedicine constructor
{
	tAppoinmentNo++; //get appoinment numbers
	if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass Telemedicine - Constructor\n";
}
EmergencyPatient::EmergencyPatient(int t)	//class EmergencyPatient constructor
{
	AppoinmentNo2++; //get appoinment numbers
	if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass EmergencyPatient - Constructor\n";
}
AdmittedPatient::AdmittedPatient(int t)	//class AdmittedPatient constructor
{
	AppoinmentNo3++; //get appoinment numbers
    if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass AdmittedPatient - Constructor\n";	
}
EGuardientInfo::EGuardientInfo(int t)	//class EGuardientInfo constructor
{
	AppoinmentNo4++; //get appoinment numbers
    if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass EGuardientInfo - Constructor\n";	
}
AGuardientInfo::AGuardientInfo(int t)	//class AGuardientInfo constructor
{
	AppoinmentNo5++; //get appoinment numbers
    if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass AGuardientInfo - Constructor\n";	
}


	
/* -----------------------------------------
   class name - Hospital
   constructors - Hospital()
				  Hospital(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~Hospital()
   -----------------------------------------*/ 
class Hospital
{
public:
	Hospital(); //constructor
	Hospital(int t); //constructor with input parameters
	void HospitalDetails(int t); //displaying hospital details
	void TreatmentPayment(int t){}	// getting treatment payment receipt
	void MedicinePayment(int t) {}  //getting medicine payment receipt
};
// class Hospital
//constructor
Hospital::Hospital()
{
}
Hospital::Hospital(int t)
{
	if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass Hospital - Constructor\n";	
}
//function HospitalDetails
void Hospital::HospitalDetails(int t) //displaying hospital details
{
		if(t==1)
		  cout<<"\n\t\t\tClass Hospital : Member function - HospitalDetails\n";
		cout << "\n\n\t\t***Hospital Details***" << endl;
		cout << "\t-----------------------------------" << endl;
		cout << "\n\tPhone number of District General Hospital....\n\tYou can try to dialing this number: +94 312 222 261 " << endl;
		cout << "\n\n\tOpening hours of District General Hospital...." << endl;
		cout << "\n\tMonday: Open 24 hours\n\tTuesday: Open 24 hours\n\tWednesday : Open 24 hours\n\tThursday : Open 24 hours\n\tFriday : Open 24 hours\n\tnSaturday : Open 24 hours\n\tSunday : Open 24 hours" << endl;
		cout << "\n\n\tSimilar Places...." << endl;
		cout << "\n\t1. Dengue Fever Unit = Centre for Clinical Management of\n\tDengue & Dengue Haemorrhagic Fever" << endl;
		cout << "\tAbesekara Lane, Negombo, Sri Lanka\n\tCoordinate: 7.2114969, 79.8489895" << endl;
		cout << "\t-------------------------------------------------------------------------------------" << endl;
		cout << "\n\t2. Medi Clinic" << endl;
		cout << "\tNegombo-Colombo Main Rd, Negombo 11500, Sri Lanka\n\tCoordinate: 7.2111191, 79.8485094" << endl;
		cout << "\t-------------------------------------------------------------------------------------" << endl;
		cout << "\n\t3. Medica" << endl;
		cout << "\tKatuwapitiya Rd, Negombo, Sri Lanka\n\tCoordinate: 7.2105336, 79.8495984" << endl;
		cout << "\t-------------------------------------------------------------------------------------" << endl;
		cout << "\n\t4. SOS Medical Centre" << endl;
		cout << "\tKundanwila, Negombo, Sri Lanka\n\tCoordinate: 7.2103048, 79.8526561" << endl;
		cout << "\t-------------------------------------------------------------------------------------" << endl;
		cout << "\n\t5. Nawaloka Hospital Negombo" << endl;
		cout << "\t169 Colombo Rd, Negombo, Sri Lanka\n\tCoordinate: 7.2093087, 79.8497481" << endl;
		cout << "\t-------------------------------------------------------------------------------------" << endl;
		Sleep(1000);
		struct Stay s;
		s.wait(t);
	}


/* -----------------------------------------
   class name - Payment
   constructors - Payment()
				  Payment(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~Payment()
   -----------------------------------------*/ 
class Payment:public Hospital //child class of Hospital class
{
public:
	string PatientName1,PatientName2, DocName1,DocName2,Problem, MedicineName,MedicineID,MedicineType;
	long int Number;
	int Age;
	double Amount;
	Payment(int t); //Constructor with input prameter
	void TreatmentPayment(int t);	// getting treatment payment receipt 
	void MedicinePayment(int t);   //getting medicine payment receipt	
};
//class Payment
//constructor
Payment::Payment(int t) //Constructor with input prameter
{
		if(t==1) //education mode
		  cout<<"\n\n\t\t\tClass Payment - Constructor\n";
}
//member function
void Payment::TreatmentPayment(int t) // getting treatment payment receipt 
{
		if(t==1)
		  cout<<"\n\t\t\tClass Payment : Member function - TreatmentPayment\n";
		cout << "\n\t\t    Treatment Payment    " << endl;
		cout << "\t-----------------------------------" << endl;
		 cout << "\n\t\t **** Spaces are not allowed ****\n";
		cout << "\n\tPatient First Name		: ";
		cin >> PatientName1;
		cout << "\n\tPatient second Name		: ";
		cin >> PatientName2;
		cout << "\n\tPatient Age			: ";
		cin >> Age;
		cout << "\n\tPatient Problem			: ";
		cin >> Problem;
		cout << "\n\tDoctor First Name		: ";
		cin >> DocName1;
		cout << "\n\tDoctor second Name		: ";
		cin >> DocName2;
		cout << "\n\tEnter Amount Of Treatment	: ";
		cin >> Amount;
		cout << "\n\tEnter your mobile no		: ";
		cin >> Number;
		Sleep(1000);
		cout << "\n\n\tPayment Successful.Thank You...!" << endl;
		system("cls");
		cout << "\n\n\t\t\t  Payment Receipt  " << endl;
		cout << "\t---------------------------------------------" << endl;
		cout << "\n\t|\tPatient Full Name	: " << PatientName1<<" "<<PatientName2 << endl;
		cout << "\n\t|\tPatient Age		: " << Age << endl;
		cout << "\n\t|\tPatient Problem		: " << Problem << endl;
		cout << "\n\t|\tDoctor Full Name	: " << DocName1<<" "<<DocName2 << endl;
		cout << "\n\t|\tPayment Amount		: Rs." << Amount << endl;
		cout << "\n\t|\tMobile No		: " << Number << endl;
		cout << "\n\t\t\tThank You!" << endl;
		Sleep(5000);
	}
void Payment::MedicinePayment(int t)  //getting medicine payment receipt
{
		if(t==1)
		  cout<<"\n\t\t\tClass Payment : Member function - MedicinePayment\n";
		cout << "\n\t\t   Medicine Payment   " << endl;
		cout << "\t-----------------------------------" << endl;
		 cout << "\n\t\t **** Spaces are not allowed ****\n";
		cout << "\n\tPatient First Name		: ";
		cin >> PatientName1;
		cout << "\n\tPatient second Name		: ";
		cin >> PatientName2;
		cout << "\n\tPatient Age			: ";
		cin >> Age;
		cout << "\n\tMedicine Name			: ";
		cin >> MedicineName;
		cout << "\n\tMedicine ID			: ";
		cin >> MedicineID;
		cout << "\n\tMedicine Type			: ";
		cin >> MedicineType;
		cout << "\n\tMedicine Price         		: ";
		cin >> Amount;
		cout << "\n\tEnter your mobile no		: ";
		cin >> Number;
		Sleep(1000);
		cout << "\n\n\tPayment Successful.Thank You...!" << endl;
		system("cls");
		cout << "\n\n\t\t\t   Payment Receipt  " << endl;
		cout << "\t---------------------------------------------" << endl;
		cout << "\n\t|\tPatient Full Name	: " << PatientName1<<" "<<PatientName2 << endl;
		cout << "\n\t|\tPatient Age		: " << Age << endl;
		cout << "\n\t|\tMedicine Name		: " << MedicineName<< endl;
		cout << "\n\t|\tMedicine ID		: " << MedicineID<< endl;
		cout << "\n\t|\tMedicine Type		: " << MedicineType<< endl;
		cout << "\n\t|\tMedicine Price		: Rs." << Amount << endl;
		cout << "\n\t|\tMobile No		: " << Number << endl;
		cout << "\n\t\t\tThank You!" << endl;
		Sleep(5000);
	}


/* -----------------------------------------
   class name - Dispensary
   constructors - Dispensary()
				  Dispensary(int t)
   attributes - private
   member functions - public , return type - void
   destructor - ~Dispensary()
   -----------------------------------------*/ 
class Dispensary
{
private:
	int ID, NoOfMedicine;
public:
	Dispensary(int t); //Constructor with input parameter
	void MedicineList(int t);	//displaying medicine list
	void GetMedicine(int t); //getting medicine	
};
//class Dispensary
//constructor
Dispensary::Dispensary(int t)
{
	if(t==1) //education mode
	  cout<<"\n\n\t\t\tClass Dispensary - Constructor\n";
}
//member functions
void Dispensary::MedicineList(int t) //displaying medicine list
{
		if(t==1)
		  cout<<"\n\t\t\tClass Dispensary : Member function - MedicineList\n";
		cout << "\n\n\tAVAILABLE MEDICINE LIST" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\n\t==================================================================================" << endl;
		cout << "\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
		cout << "\t==================================================================================" << endl;
		cout << "\n\t00001	" << setw(12) << "OTC	" << setw(25) << "Probiotics	" << setw(12) << "2.00	" << endl;
		cout << "\n\t00002	" << setw(12) << "OTC	" << setw(25) << "Vitamin C(500mg)	" << setw(12) << "3.00	" << endl;
		cout << "\n\t00003	" << setw(12) << "OTC	" << setw(25) << "Acid Free C(500mg)	" << setw(12) << "1.00	" << endl;
		cout << "\n\t00004	" << setw(12) << "OTC	" << setw(25) << "Women's Multivate	" << setw(12) << "4.00	" << endl;
		cout << "\n\t00005	" << setw(12) << "OTC	" << setw(25) << "Marino Tablet	" << setw(12) << "1.00	" << endl;
		cout << "\n\t00006	" << setw(12) << "OTC	" << setw(25) << "Maxi Cal Tablet	" << setw(12) << "5.00	" << endl;
		cout << "\n\t00007	" << setw(12) << "OTC	" << setw(25) << "Amino Zinc Tablet	" << setw(12) << "7.00	" << endl;
		cout << "\n\t00008	" << setw(12) << "OTC	" << setw(25) << "Burnex	" << setw(12) << "4.00	" << endl;
		cout << "\n\t00009	" << setw(12) << "OTC	" << setw(25) << "Fabuloss S	" << setw(12) << "3.00	" << endl;
		cout << "\n\t00010	" << setw(12) << "OTC	" << setw(25) << "Royal Propollen	" << setw(12) << "5.00	" << endl;
		Sleep(2000);
	}
void Dispensary::GetMedicine(int t) //getting medicine
{
		if(t==1)
		  cout<<"\n\t\t\tClass Dispensary : Member function - GetMedicine\n";
		cout << "\n\n\t------------ Get Your Medicine ------------\n";
		cout << "\n\n\tEnter Medicine ID		: ";
		cin >> ID;
		system("cls");
		cin.sync();
		switch (ID)
		{
		case 1:
			{
				cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00001	" << setw(12) << "OTC	" << setw(25) << "Probiotics	" << setw(12) << "2.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 2 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
			
		case 2:
			{
					cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00002	" << setw(12) << "OTC	" << setw(25) << "Vitamin C(500mg)	" << setw(12) << "3.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 2 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
		
		case 3:
			{
				cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00003	" << setw(12) << "OTC	" << setw(25) << "Acid Free C(500mg)	" << setw(12) << "1.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 1 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
			
		case 4:
			{
					cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00004	" << setw(12) << "OTC	" << setw(25) << "Women's Multivate	" << setw(12) << "4.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 4 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
		
		case 5:
			{
				cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00005	" << setw(12) << "OTC	" << setw(25) << "Marino Tablet	" << setw(12) << "1.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 1 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(2000);
			break;
			}
			
		case 6:
			{
				cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00006	" << setw(12) << "OTC	" << setw(25) << "Maxi Cal Tablet	" << setw(12) << "5.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 5 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
			
		case 7:
			{
					cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00007	" << setw(12) << "OTC	" << setw(25) << "Amino Zinc Tablet	" << setw(12) << "7.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 7 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
		
		case 8:
			{
				cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00008	" << setw(12) << "OTC	" << setw(25) << "Burnex	" << setw(12) << "4.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 4 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
			
		case 9:
			{
					cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00009	" << setw(12) << "OTC	" << setw(25) << "Fabuloss S	" << setw(12) << "3.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 3 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
		
		case 10:
			{
					cout << "\n\tMedicine ID	" << setw(10) << "Medicine Type	" << setw(20) << "Medicine Name	" << setw(25) << "Medicine Price(Rs)	" << endl;
			cout << "\t==================================================================================" << endl;
			cout << "\n\t00010	" << setw(12) << "OTC	" << setw(25) << "Royal Propollen	" << setw(12) << "5.00	" << endl;
			cout << "\n\tHow many medicine do you want : ";
			cin >> NoOfMedicine;
			cout << "\n\n\t\tThe Amount you need to Pay : " << 5 * NoOfMedicine;
			cout << "\n\n\t\tOrder taken Successfully..!" << endl;
			Sleep(1000);
			break;
			}
		

		default:
			cout << "You entered IDD is incorrect. Please Try Again..!" << endl;
			Sleep(2000);
			break;
		}
			
	}



//main function
int main()
{
	int option;
	int t;
	cout << "\n\t\t\t\t---------------------------------------------------------";
	cout << "\n\t\t\t\t\t       ~ HOSPITAL MANAGEMENT SYSTEM ~       ";
	cout << "\n\t\t\t\t---------------------------------------------------------";
	cout << "\n\n\n\t\t\t\t\t ******** WELCOME TO THE HOSPITAL ABC ********" << endl;
	cout << "\n\n\n\t\t\t\t\t LOGIN SCREEN" << endl;
	cout << "\t\t\t\t\t--------------------------------------------";
	cout << "\n\n\n\n\t\t\t\t\tADMIN LOGIN=> Press 1\n\n\t\t\t\t\tUSER LOGIN=> Press 2 " << endl;
	cout << "\n\n\t\t\t\t\tPress------->>>>  ";
	cin >> option; // take interface that user want
	system("cls");
	cin.sync();
	cout <<"\n\n\t\t\t- OPERATION MODES -\n";
	cout <<"\n\t\t\t1.Education Mode";
	cout <<"\n\t\t\t2.Regular Mode";
	cout<<"\n\n\t\t Enter the mode you want operate :";
	cin>>t;  // take operation modes
	Sleep(500);
	if (option == 1)
	{
		AdminPassword(t); //go to AdminPassword function
	}
	else
	{
		UserMenu(t);  // go to user menu
	}
	
	system("pause");

	return 0;
}  
//end of main function


//function declaration

/* -----------------------------------------
   function name - AdminMenu
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void AdminMenu(int t)	//Admin menu list
{

	int selection,method;
	char pay;
	bool y = 1;
	while (y) // runs until user want to exit
	{
		system("cls");
		if(t==1) // education mode
	      cout<<"\n\t\t\t\t\t\tFunction - adminMenu\n";
		Sleep(1000);
		cin.sync();
		cout << "\n\t\t\t\t---------------------------------------------------------";
		cout << "\n\t\t\t\t\t       ~ HOSPITAL MANAGEMENT SYSTEM ~       ";
		cout << "\n\t\t\t\t---------------------------------------------------------";
		cout << "\n\n\n\t\t\t\t\t ******** WELCOME TO THE HOSPITAL ABC ********" << endl;
		cout << "\n\n\t\t\t\t ADMIN SCREEN....\n\n";
		cout << "\n\t\t\t\t 1.  Doctor Information";
		cout << "\n\t\t\t\t 2.  Staff Information";
		cout << "\n\t\t\t\t 3.  Patient Information";
		cout << "\n\t\t\t\t 4.  Emergency Patient";
		cout << "\n\t\t\t\t 5.  Hospital Details";
		cout << "\n\t\t\t\t 6.  Dispensary";
		cout << "\n\t\t\t\t 7.  Medicine";
		cout << "\n\t\t\t\t 8.  Payment";
		cout << "\n\t\t\t\t 9.  Set Password";
		cout << "\n\t\t\t\t 10. Logout";
		cout << "\n\n\tChoose an option : ";
		cin >> selection;
		system("cls");
		switch (selection)
		{
			case 1:
			{
				updateDocStaff(t,1);
				break;
			}
			case 2:
			{
				updateDocStaff(t,2);
				break;
			}
			case 3:
			{
				updatePatient(t);
				break;
			}
			case 4:
			{
				EmergencyyPatient(t,3);
				break;
			}
			case 5:
			{
				Hospital h1(t); //create object
				h1.HospitalDetails(t);
				break;
			}
			case 6:
			{
				Dispensary d(t); //create object
				d.MedicineList(t);
				d.GetMedicine(t);
				cout << "----------------------------------------------------------" << endl;
				cout << "\n\n\t\tDo you want to pay now ? (y/n) ";
				cin>>pay;
				if(pay=='y'||pay=='Y')
				{
					system("cls");
					Payment P2(t); //create object
					P2.MedicinePayment(t);			
				}
				Sleep(1000);
				struct Stay s; //create structure object
				s.wait(t);
				break;
			}
			case 7:
			{
			    Dispensary d(t); //create object
				d.MedicineList(t);
				struct Stay s; //create structure object
				s.wait(t);
				break;
			}
			case 8:
			{
			    cout<<"\n\n\t\t 1 - Treatment/ Appoinment Payment";
				cout<<"\n\n\t\t 2 - Dispensary/ Medicine Payment";
				cout<<"\n\n\t\tEnter Your Option : ";
				cin>>method;
				Payment P1(t); //create object
				if(method==1)
				    P1.TreatmentPayment(t);
				else
				    P1.MedicinePayment(t);
				break;	
			}
			case 9:
			{
				ChangePassword(t);
				break;
			}
			case 10:
			{
				y = 0;
				cout << "\n\n\n\t\t\tLogout.. Thank you ..!" << endl;
				break;
			}
			default:
			{
				cout << "\n\t\tInvalid Input\n";
				Sleep(500);
				break;
			}
		}
	}
}

/* -----------------------------------------
   function name - UserMenu
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void UserMenu(int t) //user menu list
{
	
	int selection,method,choice;
	char meetup,pay;
	bool y = 1;
	while (y) // runs until user want to exit
	{
		system("cls");
		system("color Fc"); //change color
		cin.sync();
		if(t==1) //education mode
   			cout<<"\n\t\t\t\t\t\tFunction - userMenu\n";
   		Sleep(1000);
		cout << "\n\t\t\t\t---------------------------------------------------------";
		cout << "\n\t\t\t\t\t       ~ HOSPITAL MANAGEMENT SYSTEM ~       ";
		cout << "\n\t\t\t\t---------------------------------------------------------";
		cout << "\n\n\n\t\t\t\t\t ******** WELCOME TO THE HOSPITAL ABC ********" << endl;
		cout << "\n\n\t\t\t\t USER SCREEN....\n";
		cout << "\n\t\t\t\t 1. Patient Appoinments";
		cout << "\n\t\t\t\t 2. TeleMedicine";
		cout << "\n\t\t\t\t 3. Doctor Information";
		cout << "\n\t\t\t\t 4. Hospital Details";
		cout << "\n\t\t\t\t 5. Dispensary";
		cout << "\n\t\t\t\t 6. Medicine";
		cout << "\n\t\t\t\t 7. Payment";
		cout << "\n\t\t\t\t 8. Logout";
		cout << "\n\n\t\tChoose an option : ";
		cin >> selection;
		switch (selection)
		{
			case 1:
			{
				system("cls");
				cout<<"\n\t\t\t .......... Patient Appoinment .......... \n";
				cout<<"\n\t\t Do you want meet the Doctor physically or online (p/o)? "; 
				cin>>meetup;
				if(meetup=='p'||meetup=='P')  // meeting the doctor physically
				{
					system("cls");
					PatientAppoinment pA1(t); //create object
					cout<<"\n\t\t\t .......... Patient Appoinment .......... \n";
					pA1.getDetails(t,1,pA1.AppoinmentNo1,"patients.txt");
				}
				else if(meetup=='o'||meetup=='O')	// meeting the doctor online
				{
					cout<<"\n\n\t You will be directed to Telemedicine Service\n";
					Sleep(500);
					system("cls");
					Telemedicine tM1(t); //create object
					cout<<"\n\n\t\t\t ........... Telemedicine Service ...........\n";
					tM1.getDetails(t,2,tM1.tAppoinmentNo,"telemedicine.txt");
				}
				
				break;
			}
			case 2:
			{
				system("cls");
				Telemedicine tM1(t); //create object
				cout<<"\n\n\t\t\t ........... Telemedicine Service ...........\n";
				tM1.getDetails(t,2,tM1.tAppoinmentNo,"telemedicine.txt");
				break;
			}
			case 3:  
			{
				system("cls");
				UserInfo uObj(t); //create object
				cout<<"\n\n\t\t1.Doctor List";
				cout<<"\n\t\t2.Available Times";
				cout<<"\n\n\tEnter your choice : ";
				cin>>choice;
				if(choice==1)
				{
					system("cls");
					cout << "\n\t\t ---------- Display Doctor List ----------\n";
					uObj.showList(t,"docList.txt");
				}
				    
				else
				{
					system("cls");
					cout << "\n\t\t ---------- Display Doctor Available Times ----------\n";
					uObj.availability(t,"docAvailable.txt");
				}
					
				break;
			}
			case 4:
			{
				system("cls");
				Hospital h1(t); //create object
				h1.HospitalDetails(t);
				break;
	        }
			case 5:
			{
				system("cls");
				Dispensary d(t); //create object
				d.MedicineList(t);
				d.GetMedicine(t);
				cout << "----------------------------------------------------------" << endl;
				cout << "\n\n\t\tDo you want to pay now ? (y/n) ";
				cin>>pay;
				if(pay=='y'||pay=='Y')
				{
					system("cls");
					Payment P2(t); //create object
					P2.MedicinePayment(t);			
				}
				Sleep(1000);
				struct Stay s; //create structure object
				s.wait(t);
				break;
			}
			case 6:
			{
				system("cls");
				Dispensary d(t); //create object
				d.MedicineList(t);
				struct Stay s; //create structure object
				s.wait(t);
				break;
			}
			case 7:
			{
				cout<<"\n\n\t\t 1 - Treatment/ Appoinment Payment";
				cout<<"\n\n\t\t 2 - Dispensary/ Medicine Payment";
				cout<<"\n\n\t\tEnter your option :";
				cin>>method;
				system("cls");
				Payment P1(t); //create object
				if(method==1)
				    P1.TreatmentPayment(t);
				else
				    P1.MedicinePayment(t);
				break;
			}
			case 8:
			{
				y = 0;
				cout << "\n\n\n\t\t\tLogout.. Thank you ..!" << endl;
				break;
			}
			default:
			{
				cout << "\n\t\tInvalid Input\n";
				Sleep(500);
				break;
			}
		}
	}
}

/* -----------------------------------------
   function name - AdminPassword
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void AdminPassword(int t) //getting password for the admin
{
	
	system("cls");
	system("color Fc"); //change color
	if(t==1) //education mode
	  cout<<"\n\t\t\t\t\t\tFunction - adminPassword\n\n";
	Sleep(1000);
	string p1, p2;
	cout << "\n\t--------------------------------------------";
	cout << "\n\t      ~ HOSPITAL MANAGEMENT SYSTEM ~       ";
	cout << "\n\t--------------------------------------------";
	cout << "\n\n\n\n\t\tEnter the Admin Password ";
	cin >> p1;
	ifstream in("password.txt"); //create flie object called in from password file.
	in >> p2; //read password from the file
	if (p1 == p2) //check whether user input password matches to the password in the file
		AdminMenu(t);
	else
	{
		cout << "\n\n\t\t\tIncorrect Password!!!!\n\t\t\tPlease try again\n";
		Sleep(1000);
		AdminPassword(t); //function recursion
	}
	in.close(); //close file
}

/* -----------------------------------------
   function name - ChangePassword
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void ChangePassword(int t)	//change password for the admin
{
	string n;
	system("cls");
	if(t==1) //education mode
	   cout<<"\n\t\t\t\t\t\tFunction - changePassword\n";
	Sleep(1000);
	ofstream out("password.txt"); //"	create stream object called out from password file
	{
		cin.sync();
		cout << "\n\t--------------------------------------------";
		cout << "\n\t      ~ HOSPITAL MANAGEMENT SYSTEM ~       ";
		cout << "\n\t--------------------------------------------";
		cout << "\n\n\n\n\t\tNew Password \n";
		cout<<"\t* Password should not included spaces\n\t* Password can included letters,numbers and symbols";
		cout << "\n\n\n\n\t\tEnter the new Password ";
		cin >> n;
		out << n; //write password to the file
	}
	out.close(); //close file
	cout << "\n\n\t\tYour Password has been saved ";
	Sleep(1000);
}

/* -----------------------------------------
   function name - updatePatient
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void updatePatient(int t)	//Updating patient information by admin
{
	if(t==1) //education mode
		cout<<"\n\t\t\t\t\t\tFunction - updatePatient\n";
	Sleep(1000);
	int option1,option2;
	
		cout<<"\n\n\t\t\t\t ...................... Update Patient Information ......................\n";
	    cout<<"\n\t\t\t 1 - Patient Appoinments \n";
	    cout<<"\t\t\t 2 - Telemedicine Service \n";
	    cout<<"\t\t\t 3 - Emergency Patients \n";
	    cout<<"\t\t\t 4 - Admitted Patients \n";
	    cout<<"\t\t\t 5 - Discharged Patients \n";
	    cout<<"\n\t Enter Your Choice : ";
		cin>>option1;
	    if(option1==1)
	    {
	    	system("cls");
	    	PatientAppoinment pA1(t); //create object
	    	cout<<"\n\n\t\t\t ........... Patient Appoinments ...........\n";
	    	cout<<"\n\n\t\t 1 - Add Appoinment Details\n";
			cout<<"\t\t 2 - Display Appoinment Details\n";
			cout<<"\t\t 3 - Modify Appoinment Details\n";
			cout<<"\t\t 4 - Delete Appoinment Details\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
			if(option2==1)
	        	pA1.getDetails(t,option1,pA1.AppoinmentNo1,"patients.txt");
	        else if(option2==2)
	        	pA1.showDetails(t,option1,pA1.AppoinmentNo1,"patients.txt");
	        else if(option2==3)
	        	pA1.modifyDetails(t,option1,pA1.AppoinmentNo1,"patients.txt","patients2.txt");
	        else if(option2==4)
	        	pA1.deleteDetails(t,option1,pA1.AppoinmentNo1,"patients.txt","patients2.txt","Emptypatient.txt");
	        else
	            cout<<"\n\\t  --- Invalid Input ---\n";  	
		}
		else if(option1==2)
		{
			system("cls");
			Telemedicine tM1(t); //create object
			cout<<"\n\n\t\t\t ........... Telemedicine Service ...........\n";
			cout<<"\n\n\t\t 1 - Add Appoinment Details\n";
			cout<<"\t\t 2 - Display Appoinment Details\n";
			cout<<"\t\t 3 - Modify Appoinment Details\n";
			cout<<"\t\t 4 - Delete Appoinment Details\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
			if(option2==1)
	        	tM1.getDetails(t,option1,tM1.tAppoinmentNo,"telemedicine.txt");
	        else if(option2==2)
	        	tM1.showDetails(t,option1,tM1.tAppoinmentNo,"telemedicine.txt");
	        else if(option2==3)
	        	tM1.modifyDetails(t,option1,tM1.tAppoinmentNo,"telemedicine.txt","telemedicine2.txt");
	        else if(option2==4)
	        	tM1.deleteDetails(t,option1,tM1.tAppoinmentNo,"telemedicine.txt","telemedicine2.txt","Emptytelemedicine.txt");
	        else
	            cout<<"\n\\t  --- Invalid Input ---\n";
			
		}
		else if(option1==3)
		{
			system("cls");
			EmergencyPatient eP1(t); //create object
			EGuardientInfo gI1(t); //create object
			cout<<"\n\n\t\t\t ........... Emergency Patients ...........\n";
			cout<<"\n\n\t\t 1 - Add Emergency Patient Details\n";
			cout<<"\t\t 2 - Display Emergency Patient Details\n";
			cout<<"\t\t 3 - Modify Emergency Patient Details\n";
			cout<<"\t\t 4 - Delete Emergency Patient Details\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
		
			if(option2==1)
	        {
	        	eP1.getDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt");
				gI1.getDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt");
			}
	        else if(option2==2)
	        {
	        	eP1.showDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt");
				gI1.showDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt");
			}
	       else if(option2==3)
	        {
	        	eP1.modifyDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt","emergency2.txt");
				gI1.modifyDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt","Emergency_guardient2.txt");
			}
	        else if(option2==4)
	        {
	        	eP1.deleteDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt","emergency2.txt","DischargEmergency.txt");
				gI1.deleteDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt","Emergency_guardient2.txt","Discharge_Emergency_guardient.txt");
			}
	        else
	            cout<<"\n\\t  --- Invalid Input ---\n";
			
		}
		else if(option1==4)
		{
			system("cls");
			AdmittedPatient aP1(t); //create object
			AGuardientInfo gI1(t); //create object
			cout<<"\n\n\t\t\t ........... Admitted Patients ...........\n";
			cout<<"\n\n\t\t 1 - Add Admitted Patient Details\n";
			cout<<"\t\t 2 - Display Admitted Patient Details\n";
			cout<<"\t\t 3 - Modify Admitted Patient Details\n";
			cout<<"\t\t 4 - Delete Admitted Patient Details\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
			if(option2==1)
	        {
	        	aP1.getDetails(t,option1,aP1.AppoinmentNo3,"admitted.txt");
				gI1.getDetails(t,5,gI1.AppoinmentNo5,"Admitted_guardient.txt");
			}
	        else if(option2==2)
	        {
	        	aP1.showDetails(t,option1,aP1.AppoinmentNo3,"admitted.txt");
				gI1.showDetails(t,5,gI1.AppoinmentNo5,"Admitted_guardient.txt");
			}
	        else if(option2==3)
	        {
	        	aP1.modifyDetails(t,option1,aP1.AppoinmentNo3,"admitted.txt","admitted2.txt");
				gI1.modifyDetails(t,5,gI1.AppoinmentNo5,"Admitted_guardient.txt","Admitted_guardient2.txt");
			}
	        else if(option2==4)
	        {
	        	aP1.deleteDetails(t,option1,aP1.AppoinmentNo3,"admitted.txt","admitted2.txt","Discharge_admitted.txt");
				gI1.deleteDetails(t,5,gI1.AppoinmentNo5,"Admitted_guardient.txt","Admitted_guardient2.txt","Discharge_Admitted_guardient.txt");
			}
	        else
	            cout<<"\n\\t  --- Invalid Input ---\n";	
		}
		else if(option1==5)
		{
			system("cls");
			cout<<"\n\n\t\t\t ........... Discharged Patients ...........\n";
			cout<<"\n\n\t\t 1 - Display Discharged Emergency Patients\n";
			cout<<"\t\t 2 - Display Discharged Emergency Patient Guardients\n";
			cout<<"\t\t 3 - Display Discharged Admitted Patients\n";
			cout<<"\t\t 4 - Display Discharged Admitted Patient Guardiants\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
			if(option2==1)
			{
				EmergencyPatient eP2(t); //create object
				eP2.showDetails(t,3,eP2.AppoinmentNo2,"DischargEmergency.txt");
			}
			else if(option2==2)
			{
				EGuardientInfo gI2(t); //create object
				gI2.showDetails(t,5,gI2.AppoinmentNo4,"Discharge_Emergency_guardient.txt");
			}
			else if(option2==3)
			{
				AdmittedPatient aP2(t); //create object
				aP2.showDetails(t,4,aP2.AppoinmentNo3,"Discharge_admitted.txt");
			}
			else
			{
				AGuardientInfo gI2(t); //create object
				gI2.showDetails(t,5,gI2.AppoinmentNo5,"Discharge_Admitted_guardient.txt");
			}
		}
		else
		  cout<<"\n\\t  --- Invalid Input ---\n";
		 
}

/* -----------------------------------------
   function name - EmergencyyPatient
   intput parameters - int
   return type - void
   -----------------------------------------*/ 
void EmergencyyPatient(int t,int option1)	// adding emergency patient's information
{
	
			int option2;
			system("cls");
			if(t==1) //education mode
	 		  cout<<"\n\t\t\t\t\t\tFunction - emergencyyPatient\n";
			Sleep(1000);
			EmergencyPatient eP1(t); //create object
			EGuardientInfo gI1(t); //create object
			cout<<"\n\n\t\t\t ........... Emergency Patients ...........\n";
			cout<<"\n\n\t\t 1 - Add  Patient Details\n";
			cout<<"\t\t 2 - Display  Patient Details\n";
			cout<<"\t\t 3 - Modify  Patient Details\n";
			cout<<"\t\t 4 - Delete  Patient Details\n";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>option2;
			if(option2==1)
	        {
	        	eP1.getDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt");
				cout<<"\n\n\t\t\t ........... Guardient ...........\n";
				gI1.getDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt");
			}
	        else if(option2==2)
	        {
	        	eP1.showDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt");
				cout<<"\n\n\t\t\t ........... Guardient ...........\n";
				gI1.showDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt");
			}
	       else if(option2==3)
	        {
	        	eP1.modifyDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt","emergency2.txt");
				cout<<"\n\n\t\t\t ........... Guardient ...........\n";
				gI1.modifyDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt","Emergency_guardient2.txt");
			}
	        else if(option2==4)
	        {
	        	eP1.deleteDetails(t,option1,eP1.AppoinmentNo2,"emergency.txt","emergency2.txt","DischargEmergency.txt");
				cout<<"\n\n\t\t\t ........... Guardient ...........\n";
				gI1.deleteDetails(t,5,gI1.AppoinmentNo4,"Emergency_guardient.txt","Emergency_guardient2.txt","Discharge_Emergency_guardient.txt");
			}
	        else
	            cout<<"\n\\t  --- Invalid Input ---\n";
			
		}

/* -----------------------------------------
   function name - updateDocStaff
   intput parameters - int
   return type - void
   -----------------------------------------*/ 		
void updateDocStaff(int t,int option1)	//updating doctor staff (delete,modify,display,add)
{
	if(t==1) //education mode
	   cout<<"\n\t\t\t\t\t\tFunction - updateDocStaff\n";
	Sleep(1000);
	int option2;
	UserInfo u1(t); //create object
	if(option1==1) //doctor information
	{
		DocInfo dObj1(t); //create object
		cout<<"\n\n\t\t\t\t ...................... Doctor Information ......................\n";
		cout<<"\n\n\t\t 1 - Add Doctor Details\n";
		cout<<"\t\t 2 - Display Doctor List\n";
		cout<<"\t\t 3 - Display Doctor Availability\n";
		cout<<"\t\t 4 - Display Doctor Details\n";
		cout<<"\t\t 5 - Modify Doctor Details\n";
		cout<<"\t\t 6 - Delete Doctor Details\n";
		cout<<"\n\n\t Enter Your Choice : ";
		cin>>option2;
		switch(option2)
		{
			case 1:
			{
				dObj1.getDetails(t,"doc.txt","docList.txt","docAvailable.txt");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "\n\t\t ---------- Display Doctor List ----------\n";
				dObj1.showList(t,"docList.txt");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "\n\t\t ---------- Display Doctor Available Times ----------\n";
				dObj1.availability(t,"docAvailable.txt");
				break;
			}
			case 4:
			{
			    dObj1.showDetails(t,"doc.txt");
				break;
			}
			case 5:
			{
				dObj1.modifyDetails(t,"doc.txt","Newdoc.txt");
				break;
			}
			case 6:
			{
				dObj1.deleteDetails(t,"doc.txt","Newdoc.txt");
				break;
			}
			default:
			{
				cout<<"\n\t\t !! Invalid Input ..... \n\t\t Please check again .....\n";
				Sleep(500);
				break;
			}
		}	
	}
	else if(option1==2) //staff information
	{
		StaffInfo sObj1(t); //create object
		cout<<"\n\n\t\t\t\t ...................... Staff Information ......................\n";
		cout<<"\n\n\t\t 1 - Add Staff Details\n";
		cout<<"\t\t 2 - Display Staff List\n";
		cout<<"\t\t 3 - Display Staff Availability\n";
		cout<<"\t\t 4 - Display Staff Details\n";
		cout<<"\t\t 5 - Modify Staff Details\n";
		cout<<"\t\t 6 - Delete Staff Details\n";
		cout<<"\n\n\t Enter Your Choice : ";
		cin>>option2;
		switch(option2)
		{
			case 1:
			{
				sObj1.getDetails(t,"staff.txt","staffList.txt","staffAvailable.txt");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "\n\t\t ---------- Display Staff Member List ----------\n";
				sObj1.showList(t,"staffList.txt");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "\n\t\t ---------- Display Staff Members Available Times ----------\n";
				sObj1.availability(t,"staffAvailable.txt");
				break;
			}
			case 4:
			{
			    sObj1.showDetails(t,"staff.txt");
				break;
			}
			case 5:
			{
				sObj1.modifyDetails(t,"staff.txt","Newstaff.txt");
				break;
			}
			case 6:
			{
				sObj1.deleteDetails(t,"staff.txt","Newstaff.txt");
				break;
			}
			default:
			{
				cout<<"\n\t\t !! Invalid Input ..... \n\t\t Please check again .....\n";
				Sleep(500);
				break;
			}
		}	
	}
	else
	{
		cout<<"\n\t\t !! Invalid Input ..... \n\t\t Please check again .....\n";
		Sleep(500);
	}
		
}

// end of the code

