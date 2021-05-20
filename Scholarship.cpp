#include "pch.h"
#include "Scholarship.h"
#include <iostream>
using namespace std;

ScholarShip::ScholarShip()
{
}
int ScholarShip::getId(){
	return this->id;
}
void ScholarShip::setId(int id){
	this->id = id;
}
double ScholarShip::getGPA(){
	return this->gpa;
}
void ScholarShip::setGPA(double gpa){
	this->gpa=gpa;
}
string ScholarShip::getApplicationLink(){
	return this->applicationLink;
}
void ScholarShip::setApplicationLink(string applicationLink){
	this->applicationLink = applicationLink;
}
string ScholarShip::getdueDate(){
	return this->dueDate;
}
void ScholarShip::setDueDate(string dueDate){
	this->dueDate = dueDate;
}
string ScholarShip::getQualification(){
return	this->qualification;
}
void ScholarShip::setQualification(string qualification){
	this->qualification = qualification;
}
string ScholarShip::getName() {
	return this->name;
}
void ScholarShip::setName(string name) {
	this->name = name;
}

double ScholarShip::getAmount() {
	return this->amount;
}
void ScholarShip::setAmount(double amount) {
	this->amount = amount;
}
void ScholarShip::print() {
	cout << id << "," << name << "," << amount << "," << dueDate << "," << qualification << "," << gpa << "," << applicationLink << endl;
}