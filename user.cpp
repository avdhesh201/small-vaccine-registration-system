/* CREATED BY AVDHESH KUMAR SINGH :)*/
// THE MAIN FILE FOR INTERFACE
#include <iostream>
#include <string>
#include "citizeninfo.h"
#include "administration.h"
using namespace std;
// Function declarations
void register_vaccine();
void citizen_login();
CitizenList Queuee; // global - The queue-list object which holds all the data of registered citizens define in citizen info
					// object creation
int main()
{
	int choice = -1;
	do
	{
		cout << "\n\t-------------------------------------------------------------" << endl;
		cout << "\t\t      Vaccination Registration System " << endl;
		cout << "\t\t-------------------------------------------" << endl;
		cout << "\n\t\t\t MAIN MENU" << endl; // MAIN MENU
		cout << "\n\t\t\t1. Registeration for vaccine." << endl;
		cout << "\n\t\t\t2. Login as Citizen." << endl;

		cout << "\n\t\t\tEnter 0 to exit." << endl;
		cout << "\n\t\t-------------------------------------------" << endl;
		cout << "\t-------------------------------------------------------------" << endl;
		cout << "\n\t\t\t Enter Your choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			register_vaccine();
			break;
		case 2:
			citizen_login();
			break;
		case 0:
			cout << "\n\t\t\t\tThank you." << endl;
			break;
		default:
			cout << "\n\t\t\tThe entered choice is not valid," << endl;
			cout << "\n\t\t\t please enter a valid option." << endl;
			break;
		}
	} while (choice);

	return 0;
}

void register_vaccine()
{
	string name;
	string phone_no;
	int age, id, time_slot;
	char ch, gender;
	cout << "\n\t\t\t Enter your name: ";
	cin >> name;
	cout << "\n\t\t\t Enter citizen ID: ";
	cin >> id;
	cout << "\n\t\t\t Select Time slot :";
	cout << "\n\t\t\t  1  9-11";
	cout << "\n\t\t\t  2  11-1";
	cout << "\n\t\t\t  3  2-4";
	cout << "\n\t\t\t  4  4-6";
	cout << "\n\t\t\t Choose time slot from above options:";
	cin >> time_slot;
	cout<< "\n\t\t\t Enter Your Phone Number: ";
	cin >> phone_no;
	
	string vaccine;
	cout << "\n\t\t\t Select Vaccine:\n\t\t\t Covishield  \n\t\t\t Covaxine \n\t\t\t Pfizer\n\t\t\t Give proper name of vaccine you want: ";
	cin >> vaccine;

	User *found = Queuee.search(id); // search for alredy exitsing id defined in citizen info
	if (found != nullptr)
	{
		cout << "\n\t\t\tCitizen with this citizen id already registered, KINDLY CHECK YOUR ID  " << endl;
		return;
	}

	// New registration details
	do // Validation
	{
		cout << "\n\t\t\t Enter Gender(m/f):";
		cin >> gender;
		if (gender != 'm' && gender != 'f')
			cout << "\n\t\t\t\tInvalid Input!";
		else
			break;
	} while (true);

	cout << "\n\t\t\t Enter your age: ";
	cin >> age;
	if (Admin::age_eligibility > age)
	{
		cout << "\n\t\t\t\tSorry Cannot Register! You are underage! ";
		return;
	}



	string pswd, pswd2;
	do
	{ // Password validation
		cout << "\n\t\t\t Set your password: ";
		cin >> pswd;
		cout << "\n\t\t\t Confirm Your password: ";
		cin >> pswd2;
		if (pswd != pswd2)
			cout << "\n\t\t\t Password does not match! Set up your password again!";
	} while (pswd != pswd2);

	User *new_citizen = new User(name, phone_no, id, gender, age, time_slot,  pswd, vaccine); //  citizen node Creation
	Queuee.enqueue(new_citizen);
	cout << "\n\t\t\t Registered successfully, please log in to see your details." << endl;
}

void citizen_login()
{
	/*This function is used  for the login of a  user who is already registered */

	int citizenID;
	cout << "\n\t\t\t Enter your User ID :";
	cin >> citizenID;
	User *user = Queuee.search(citizenID); // creation of user node
	if (user == nullptr)				   // User not found id missing
	{
		cout << "\n\t\t\ttSorry, please register first or" << endl;
		cout << "\n\t\t\t\tenter a valid User ID." << endl;
		return;
	}
	else
	{
		int count = 3; // total given Attempts(3) to enter the correct password
		string pswd;
		while (count != 0)
		{
			cout << "\n\t\t\t Enter your password :";
			cin >> pswd;
			if (!user->is_pswd(pswd)) // Checking the password entered by the user
			{
				count--; // Incorrect attempt reduces the count by 1
				cout << "\n\t\tIncorrect password." << endl;
				cout << "\n\t\t" << count << " attempts remaining." << endl;
			}
			else
				break;
		}
		// Display user details
		cout << "\n\t\t\t User details :";
		cout << user->get_details(pswd) << endl;
		cout << "\t------------------------------------------------------------------------------------" << endl;
	}
	cout << "\t****** CREATED BY AVDHESH KUMAR SINGH :)******" << endl;
	cout << "\n\t\t\t\t--------";
}
