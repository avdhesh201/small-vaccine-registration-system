/* A HEADER FIILE WHICH STORES THE DETAILS OF THE USERS AND HELP THE PROJECT IN SEARCHING AND MANAGING USERS DATA */
#ifndef CITIZEN_H_
#define CITIZEN_H_
#include <string>
using namespace std;

class User
{
	int citizen_id; // Personal details (data)
	string name;
	string phone_no;
	int age;
	char gender;
	int time_slot;
	string password;
	string vaccine;
	User *next = nullptr;

public:
                          /* Constructor	 */
	User(string nm , string pn ,int cit_id, char sx, int ag,int timeslot,string pswd,string vacc) 
	{
		citizen_id = cit_id;
		name = nm;
		phone_no= pn;
		age = ag;
		gender = sx;
		time_slot=timeslot;
		password = pswd;
		vaccine=vacc;

	}

	bool is_pswd(string pswd);
	string get_details(string pswd);

	friend class Admin;                          // class Admin in "Administration.h" header
	friend class CitizenList;
};

class CitizenList
{
	User *rear;
	User *front;

public:
	CitizenList()   // mananges position of a particular node in the entire queue
	{
		/*Constructor*/
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(User *p);   // object passed here
	User *search(int citizenID);

	friend class Admin;
};


// User implementation

bool User::is_pswd(string pswd)
{
	/* Verifies the citizen's password.Returns true if the password matches. */
	return password == pswd;
}

string User::get_details(string pswd)
{
	/* Returns  citizen's details.Protected by password.*/
	string details;
	if (is_pswd(pswd))
	{
		details += "\n\n\t\t\t CitizenID : ";
		details += to_string(citizen_id);
		details += "\n\n\t\t\t";
		details += " Name : ";
		details += name;
        details += "\n\n\t\t\t";
        details += " Phone Number: ";
        details += phone_no;
		details += "\n\n\t\t\t";
		details += " Age : ";
		details += to_string(age);
		details += "\n\n\t\t\t";
		details += " Gender : ";
		details += gender;
		details += "\n\n\t\t\t";
		details += " time slot: ";
		details += to_string(time_slot);
		details += "\n\n\t\t\t";
		details += " Vaccine : ";
		details += vaccine;
		details += "\n\n\t\t\t";
		return details;
	}
	return "Access Denied.";
}

// CitizenList implementation which  works as queue

User *CitizenList::search(int citizenID) //user data type (characteristics)
{
	/* Returns the pointer to the citizen if found,otherwise returns null.*/
	User *cur = front;
	while (cur != nullptr)
	{
		if (cur->citizen_id == citizenID)
			break;
		cur = cur->next;
	}
	return cur;
}

void CitizenList::enqueue(User *new_citizen)
{
	/* Adds citizen to the queue-list  */
	if (front == nullptr) //First registration
	{
		front = new_citizen;
		rear = new_citizen;
	}
	else
	{
		User *cur = front;
		User *prev = nullptr;


		if (prev == nullptr) // Appending to the head
		{
			new_citizen->next = front;
			front = new_citizen;
		}
		else if (cur == nullptr) //Appending to the rear
		{
			prev->next = new_citizen;
			rear = new_citizen;
		}
		else // Appending in the middle
		{
			prev->next = new_citizen;
			new_citizen->next = cur;
		}
	}
}

// ****************************end of header******************
#endif /* CITIZEN_H_ */
