#include "pch.h"
#include "Student.h"


Student::Student()
{
}
int Student::getId()
{
	return this->id;
}
void Student::setId(int id){
	this->id = id;
}
string Student::getStudentName(){
	return this->studentName;
}
void Student::setStudentName(string name){
	this->studentName = name;
}
double Student::getGpa(){
	return this->gpa;
}
void Student::setGpa(double gpa){
	this->gpa = gpa;
}
string Student::getUserName(){
	return this->username;
}
void Student::setUserName(string username){
	this->username = username;
}
string Student::getPassword(){
	return this->password;
}
void Student::setPassword(string password){
	this->password = password;
}
string Student::getCollage(){
	return this->collage;
}
void Student::setCollage(string collage) {
	this->collage = collage;
}
string Student::getReligion() {
	return this->religion = religion;
}
void Student::setReligion(string religion) {
	this->religion = religion;
}
string Student::getQualification() {
	return this->qualification;
}
void Student::setQualification(string qualification) {
	this->qualification = qualification;
}
string Student::getBackGround() {
	return this->background;
}
void Student::setBackGround(string background) {
	this->background = background;
}
