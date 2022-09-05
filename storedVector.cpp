#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "libxl.h"
#include "Student.h"
#include "Name.h"
#include "Address.h"
#include "storedVector.h"

using namespace libxl;
using namespace std;

vector<Student> storedVector::storedStudentData()
{
    vector <Student> vec;
    {
        Book *book = xlCreateXMLBook();

        if (book->load(L"D:\\assignment2\\students info xlsx file\\studentsInfo.xlsx"))
        {
            Sheet *sheet = book->getSheet(0);

            if (sheet)
            {
                for (int row = sheet->firstRow(); row < sheet->lastRow() - 2; ++row)
                {

                    for (int col = sheet->firstCol(); col < sheet->lastCol() - 1; ++col)
                    {
                        CellType cellType = sheet->cellType(row, col);

                        if (sheet->isFormula(row, col))
                        {
                            const wchar_t *s = sheet->readFormula(row, col);
                            std::wcout << (s ? s : L"null") << " [formula]";
                        }
                        else
                        {
                            switch (col)
                            {
                            case 0:
                            {
                                srNo = sheet->readNum(row, col);
                                break;
                            }

                            case 1:
                            {
                                regNo = sheet->readNum(row, col);
                                break;
                            }

                            case 2:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String str
                                string str(ws.begin(), ws.end());
                                firstname = str;
                                break;
                            }

                            case 3:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String str
                                string str(ws.begin(), ws.end());
                                middlename = str;
                                break;
                            }

                            case 4:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String str
                                string str(ws.begin(), ws.end());
                                lastname = str;
                                break;
                            }

                            case 5:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String str
                                string str(ws.begin(), ws.end());
                                gender = str;
                                break;
                            }

                            case 6:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String str
                                string str(ws.begin(), ws.end());
                                emailid = str;
                                break;
                            }

                            case 7:
                            {
                                mobileno = sheet->readNum(row, col);
                                break;
                            }

                            case 8:
                            {
                                marks = sheet->readNum(row, col);
                                break;
                            }

                            case 9:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String
                                string str(ws.begin(), ws.end());
                                curraddress = str;
                                break;
                            }

                            case 10:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String
                                string str(ws.begin(), ws.end());
                                city = str;
                                break;
                            }

                            case 11:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String
                                string str(ws.begin(), ws.end());
                                taluka = str;
                                break;
                            }

                            case 12:
                            {
                                const wchar_t *s = sheet->readStr(row, col);
                                wstring ws(s);
                                // your new String
                                string str(ws.begin(), ws.end());
                                district = str;
                                break;
                            }

                            case 13:
                            {
                                pincode = sheet->readNum(row, col);
                                break;
                            }
                            }
                        }
                        std::wcout << std::endl;
                    }

                    Student student(srNo, regNo, gender, emailid, mobileno, marks, firstname, middlename, lastname, curraddress, city, taluka, district, pincode);
                    vec.push_back(student);
                }
            }
        }

        book->release();

        return vec;
    }
}





void storedVector::DisplayStudentData(vector<Student> &vec)
{
    // Displaying the all students data
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i].displayData();
        cout << " " << endl;
    }
    cout << " " << endl;
}

void storedVector::WriteStudentData(vector <Student> &vec)
{
    // Performing write operation
    cout << "Performing write operation" << endl;
    for (int i = 1; i < vec.size(); i++)
    {

        ofstream out; // declaring an object of the type ofstream

        out.open(vec[i].studentName.firstName + " " + vec[i].studentName.lastName + " Resume" + ".doc");

        // writing into the file
        out << "\t\t\t\t\tRESUME\t\t\t\t\t" << endl;
        out << " " << endl;
        out << "-------------------------------------------------------------------------" << endl;
        out << " " << endl;
        out << "First Name: " << vec[i].studentName.firstName << "   ";
        out << "Middle Name: " << vec[i].studentName.middleName << "   ";
        out << "Last Name: " << vec[i].studentName.lastName << endl;
        out << " " << endl;
        out << "Serial No: " << vec[i].srNo << endl;
        out << " " << endl;
        out << "Registration No: " << vec[i].regNo << endl;
        out << " " << endl;
        out << "Email Id: " << vec[i].emailId << endl;
        out << " " << endl;
        out << "Contact No: " << vec[i].mobileNo << endl;
        out << " " << endl;
        out << "Marks: " << vec[i].marks << " %" << endl;
        out << " " << endl;
        out << "Current Address: " << vec[i].studentAddress.currAddress << ",\n";
        out << "\t\t\t" << "City- " << vec[i].studentAddress.city << ",\n";
        out << "\t\t\t" << "Taluka- " << vec[i].studentAddress.taluka << ",\n";
        out << "\t\t\t" << "District- " << vec[i].studentAddress.district << ",\n";
        out << "\t\t\t" << "Pincode- " << vec[i].studentAddress.pincode << endl;

        out.close();
    }

    cout << "Write operation completed \n"
         << "All " << vec.size() - 1 << " Resumes are created successfully " << endl;
}
