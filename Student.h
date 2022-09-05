#pragma once

#include "Name.h"
#include "Address.h"

using namespace std;

class Student
{
public:
    int srNo;
    int regNo;
    string gender;
    string emailId;
    unsigned long long mobileNo;
    int marks;
    Name studentName;
    Address studentAddress;


    Student(int sr, int reg, string gen, string email, unsigned long long mob, int mrk, string fn, string mn, string ln, string ca, string c, string t, string d, int p);


    void displayData();
};