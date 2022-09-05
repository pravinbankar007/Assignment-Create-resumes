#pragma once
#include<iostream>
#include <string>
#include "Name.h"
#include "Address.h"
#include "Student.h"

using namespace std;



    Student::Student(int sr, int reg, string gen, string email, unsigned long long mob, int mrk, string fn,
        string mn, string ln, string ca, string c, string t, string d, int p) {
        srNo = sr;
        regNo = reg;
        gender = gen;
        emailId = email;
        mobileNo = mob;
        marks = mrk;
        studentName.firstName = fn;
        studentName.middleName = mn;
        studentName.lastName = ln;
        studentAddress.currAddress = ca;
        studentAddress.city = c;
        studentAddress.taluka = t;
        studentAddress.district = d;
        studentAddress.pincode = p;

    }



    void Student::displayData()
    {
        cout << "Sr No:" << srNo << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "First name of student: " << studentName.firstName << endl;
        cout << "Middle  name of student:" << studentName.middleName << endl;
        cout << "Last name of student: " << studentName.lastName << endl;
        cout << "Gender :" << gender << endl;
        cout << "EmailId:" << emailId << endl;
        cout << "Mobile no: " << mobileNo << endl;
        cout << "Marks:" << marks << endl;
        cout << "Current Address of student: " << studentAddress.currAddress << endl;
        cout << "City of student: " << studentAddress.city << endl;
        cout << "Taluka of student: " << studentAddress.taluka << endl;
        cout << "District of student: " << studentAddress.district << endl;
        cout << "Pincode of student: " << studentAddress.pincode << endl;
    }

    