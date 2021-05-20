#pragma once

/**
 * Class holds the details of the
 */
#include <string>
using namespace std;
class ScholarShip
{
private:
	int id;
	double amount;
	string name;
	string applicationLink;
	string dueDate;
	string qualification;
	double gpa;
public:
	ScholarShip();
	int getId();
	void setId(int id);
	double getGPA();
	void setGPA(double gpa);
	string getApplicationLink();
	void setApplicationLink(string applicationLink);
	string getdueDate();
	void setDueDate(string dueDate);
	string getQualification();
	void setQualification(string qualification);
	string getName();
	void setName(string name);
	double getAmount();
	void setAmount(double amount);
	void print();

};