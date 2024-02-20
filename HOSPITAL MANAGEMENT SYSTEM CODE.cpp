#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Hospital {
private:
    string serialno, Name, Address, BGroup, sex, disease;

public:
    Hospital() : Name(""), Address(""), BGroup(""), sex(" "), disease(" ") {}
    
    void setSerialNo(string s_no) {
        serialno = s_no;
    }

    void setName(string name) {
        Name = name;
    }

    void setAddress(string address) {
        Address = address;
    }

    void setSex(string s) {
        sex = s;
    }

    void setDisease(string d) {
        disease = d;
    }

    void setBGroup(string group) {
        BGroup = group;
    }

    string getSerialNo() {
        return serialno;
    }

    string getName() {
        return Name;
    }

    string getAddress() {
        return Address;
    }

    string getBGroup() {
        return BGroup;
    }

    string getSex() {
        return sex;
    }

    string getDisease() {
        return disease;
    }
};

bool login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
   
   return (username == "govind" && password == "******");
    

}


void admit(Hospital &patient) {
    system("cls");
    string serialno, name, address, group, sex, disease;
    cout << "\tEnter serial number of Patient : ";
    cin >> serialno;
    patient.setSerialNo(serialno);
    cout << "\tEnter Name Of Patient: ";
    cin >> name;
    patient.setName(name);

    cout << "\tEnter Address Of Patient: ";
    cin >> address;
    patient.setAddress(address);

    cout << "\tEnter Blood Group Of Patient: ";
    cin >> group;
    patient.setBGroup(group);

    cout << "\tEnter Sex Of Patient: ";
    cin >> sex;
    patient.setSex(sex);
    cout << "\tEnter Disease Of Patient: ";
    cin >> disease;
    patient.setDisease(disease);

    ofstream outfile("D:/Hospital.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        outfile << "\t" << patient.getSerialNo() << " : " << patient.getName() << " : " << patient.getAddress() << " : " << patient.getBGroup() << " : " << patient.getSex() << " : " << patient.getDisease() << endl;
        cout << "\tPatient Admitted!" << endl;
    }
    outfile.close();
    Sleep(3000);
}

void discharge() {
    system("cls");
    string name;
    cout << "\tEnter Name of Patient: ";
    cin >> name;

    ifstream infile("D:/Hospital.txt");
    ofstream outfile("D:/HospitalTemp.txt");
    if (!infile || !outfile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss;
            ss << line;
            string patientName;
            ss >> patientName;
            if (name == patientName) {
                found = true;
                cout << "\tPatient Discharged!" << endl;
            } else {
                outfile << line << endl;
            }
        }
        if (!found) {
            cout << "\tIncorrect Name!" << endl;
        }
    }
    outfile.close();
    infile.close();
    remove("D:/Hospital.txt");
    rename("D:/HospitalTemp.txt", "D:/Hospital.txt");
    Sleep(3000);
}

int main() {
    if (!login()) {
        cout << "Invalid username or password. Exiting..." << endl;
        return 1;
    }

    Hospital patient;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tHospital Management System" << endl;
        cout << "\t**************************" << endl;
        cout << "\t1. Admit Patient." << endl;
        cout << "\t2. Discharge Patient." << endl;
        cout << "\t3. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            admit(patient);
        } else if (val == 2) {
            discharge();
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
        Sleep(5000);
    }
    
    return 0;
}

