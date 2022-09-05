#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include "Name.h"
#include "Address.h"
#include "libxl.h"

using namespace std;
using namespace libxl;

class storedVector
{
public:
    int srNo, regNo, marks, pincode;
    unsigned long long mobileno;
    string firstname, middlename, lastname, gender, emailid, curraddress, city, taluka, district;


    vector<Student> storedStudentData();

    void DisplayStudentData(vector<Student> &vec);

    void WriteStudentData(vector <Student> &vec);
};