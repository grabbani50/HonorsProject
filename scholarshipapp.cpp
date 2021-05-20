// scholarshipapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include <vector>
#include "Scholarship.h"
#include <sstream>

//include the below additional libraries
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

//use the std namespace
using namespace std;
using namespace std;
void findEligibleScholarships(Student *student, vector<ScholarShip *> scholarships) {
	//Filter scholar ships
	vector<ScholarShip*> marchingScholarships;
	for (ScholarShip *scholarship :scholarships)
	{
		if (0==strcmp(scholarship->getQualification().c_str(), student->getQualification().c_str()) && student->getGpa() >= scholarship->getGPA())
		{
			marchingScholarships.push_back(scholarship);
		}
	}
	if (marchingScholarships.size() > 0) {
		int i = 1;
		for (ScholarShip *scholarship : marchingScholarships)
		{
			cout << i <<")"<<scholarship->getName()<<endl;
			i++;
		}
		cout << "Apply the scholarship:" << endl;
		int id;
		cin >> id;
		i = 1;
		for (ScholarShip *scholarship : marchingScholarships)
		{
			if (i== id) {
				cout << "You have applied for:" << endl;
				scholarship->print();
				break;
			}
			i++;
			
		}
		
	}
	else {
		cout << "There is no matching scholarship found"<<endl;
	}
}
//Show we error message
void show_error(unsigned int handletype, const SQLHANDLE& handle) {
	SQLWCHAR sqlstate[1024];
	SQLWCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL)) {
		cout << "Message: ";
		wcout << message;
		cout << endl << "\nSQLSTATE: ";
		wcout << sqlstate;
		cout << endl;
	}
}
/**
  Fetch Data from database
*/
vector<ScholarShip *> fetchData(vector<ScholarShip *> scholarships) {
	#define SQL_RESULT_LEN 1000
	#define SQL_RETURN_CODE_LEN 1000
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
			goto COMPLETED;
		if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			goto COMPLETED;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
			goto COMPLETED;
		switch (SQLDriverConnect(sqlConnHandle,
			NULL,
			(SQLWCHAR*)L"Driver={SQL Server};Data Source=scholarship;Server=DIPAK;Initial Catalog=master;User ID=mysa;Password=Password@123",
			SQL_NTS,retconstring,1024,NULL,SQL_DRIVER_NOPROMPT)) {
		case SQL_SUCCESS:
			cout << "Successfully connected to SQL Server"<<endl;
			break;

		case SQL_SUCCESS_WITH_INFO:
			cout << "Successfully connected to SQL Server" << endl;
			break;

		case SQL_INVALID_HANDLE:
			cout << "Could not connect to SQL Server" << endl;
			show_error(SQL_HANDLE_DBC, sqlConnHandle);
			goto COMPLETED;

		case SQL_ERROR:
			cout << "Could not connect to SQL Server" << endl;
			show_error(SQL_HANDLE_DBC, sqlConnHandle);
			goto COMPLETED;

		default:
			break;
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
			goto COMPLETED;
		if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * from scholarships", SQL_NTS)) {
			cout << "Error querying SQL Server"<<endl;
			show_error(SQL_HANDLE_DBC, sqlConnHandle);
			goto COMPLETED;
		}
		else {
			SQLCHAR sqlId[SQL_RESULT_LEN];
			SQLINTEGER ptrId;

			SQLCHAR sqlName[SQL_RESULT_LEN];
			SQLINTEGER ptrsqlName;
			

			SQLCHAR sqlDuteDate[SQL_RESULT_LEN];
			SQLINTEGER ptrDueDate;


			SQLCHAR sqlAmount[SQL_RESULT_LEN];
			SQLINTEGER ptrAmount;

			SQLCHAR sqlQualification[SQL_RESULT_LEN];
			SQLINTEGER ptrQualification;

			SQLCHAR sqlGpa[SQL_RESULT_LEN];
			SQLINTEGER ptrGpa;

			SQLCHAR sqlApplicationLink[SQL_RESULT_LEN];
			SQLINTEGER ptrApplicationLink;

			while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
				ScholarShip * scholarship = new ScholarShip();
				SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlId, SQL_RESULT_LEN, &ptrId);
				SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlName, SQL_RESULT_LEN, &ptrsqlName);
				SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlDuteDate, SQL_RESULT_LEN, &ptrDueDate);
				SQLGetData(sqlStmtHandle, 4, SQL_CHAR, sqlAmount, SQL_RESULT_LEN, &ptrAmount);
				SQLGetData(sqlStmtHandle, 5, SQL_CHAR, sqlQualification, SQL_RESULT_LEN, &ptrQualification);
				SQLGetData(sqlStmtHandle, 6, SQL_CHAR, sqlGpa, SQL_RESULT_LEN, &ptrGpa);
				SQLGetData(sqlStmtHandle, 7, SQL_CHAR, sqlApplicationLink, SQL_RESULT_LEN, &ptrApplicationLink);
				stringstream ss;
				///Get Id
				string s;
				ss << sqlId;
				ss >> s;
				ss.clear();
				scholarship->setId(stoi(s));
				s = "";
				//Get Name
				ss << sqlName;
				getline(ss, s, '\n');
				scholarship->setName(s);

				ss.clear();
				s = "";

				//Get duedate
				ss << sqlDuteDate;
				ss >> s;
				scholarship->setDueDate(s);
				ss.clear();
				s = "";

				//Get amount
				ss << sqlAmount;
				ss >> s;
				scholarship->setAmount(stod(s));
				ss.clear();
				s = "";

				//Get GPA
				ss << sqlGpa;
				ss >> s;
				scholarship->setGPA(stod(s));
				ss.clear();
				s = "";

				//Get qualification
				ss << sqlQualification;
				ss >> s;

				scholarship->setQualification(s);
				ss.clear();
				s="";
				
				//Get Applicationlink
				ss << sqlApplicationLink;
				ss >> s;
				scholarship->setApplicationLink(s);
				ss.clear();
				scholarships.push_back(scholarship);
			}
		}
	COMPLETED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		SQLDisconnect(sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
		return scholarships;

}
/***
 * Main Mehod of the application
 */
int main(int argc, char const *argv[])
{
	try
	{
		int id = 0;
		cout << "Enter the student:" << endl;
		cin >> id;
		cin.ignore();
		string name;
		cout << "Enter Student Name:" << endl;
		getline(cin, name);
		string userName;
		cout << "Enter the Student UserName:" << endl;
		cin >> userName;
		string password;
		cout << "Enter the Student Password:" << endl;
		cin >> password;
		cin.ignore();
		string qualification;
		cout << "Enter the Student Qualification:" << endl;
		getline(cin, qualification);
		string collage;
		cout << "Enter the Student Collage:" << endl;
		getline(cin, collage);
		string religion;
		cout << "Enter the Student Religion:" << endl;
		cin >> religion;
		cin.ignore();
		string background;
		cout << "Enter the Student Background:" << endl;
		cin >> background;
		double gpa;
		cout << "Enter the Student GPA:" << endl;
		cin >> gpa;
		Student *student = new Student();
		student->setId(id);
		student->setStudentName(name);
		student->setUserName(userName);
		student->setPassword(password);
		student->setReligion(religion);
		student->setBackGround(background);
		student->setGpa(gpa);
		student->setCollage(collage);
		student->setQualification(qualification);
		vector<ScholarShip *> scholarships;
		scholarships = fetchData(scholarships);
		findEligibleScholarships(student, scholarships);

	}
	catch (const std::exception& e)
	{
		cout << "'Exception Occured" << endl;
		return -1;
	}
	
	return 0;
}
