/*HEADER FILE WHICH HOLD ONLY CLASS NAMED AS ADMIN MANAGES THE AGE ELIGIBILTY CRITERIA FOR THE USERS */

#ifndef ADMIN_H_
#define ADMIN_H_

#include <string>
#include "citizeninfo.h"
using namespace std;

class Admin
{
public:
	static int age_eligibility; // The minimum age eligible for registration

	friend class CitizenList;
};

int Admin::age_eligibility = 18;


#endif
