#pragma once
#include <string>
using namespace std;
class Student {
private:
	int id;
	string studentName;
	double gpa;
	string username;
	string password;
	string collage;
	string background;
	string religion;
	string qualification;

public:
	Student();
	int getId();
	void setId(int id);
	string getStudentName();
	void setStudentName(string name);
	double getGpa();
	void setGpa(double gpa);
	string getUserName();
	void setUserName(string username);
	string getPassword();
	void setPassword(string password);
	string getCollage();
	void setCollage(string collage);
	string getReligion();
	void setReligion(string religion);
	string getQualification();
	void setQualification(string qualification);
	string getBackGround();
	void setBackGround(string background);
};

