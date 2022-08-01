/*HEADER FILE WHICH HOLD ONLY 1 CLASS NAMED AS ADMIN MANAGES THE AGE ELIGIBILITY CRITERIA FOR THE USERS (18) */

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
