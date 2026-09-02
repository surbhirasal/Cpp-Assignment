#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    Patient()
        : patientId(0), name("Unknown"), age(0),
          ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }

    Patient(int id, const string& n)
        : patientId(id), name(n), age(0),
          ward("Emergency"), bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: "
             << name << endl;
    }

    Patient(int id, const string& n, int a,
            const string& w, const string& bg)
        : patientId(id), name(n), age(a),
          ward(w), bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: "
             << name << endl;
    }

    ~Patient()
    {
        cout << "[Destructor] Patient "
             << name << " discharged." << endl;
    }

    void displayRecord() const
    {
        cout << "\nPatient Record:" << endl;
        cout << "ID        : " << patientId << endl;
        cout << "Name      : " << name << endl;
        cout << "Age       : " << age << endl;
        cout << "Ward      : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }

    void transferWard(const string& newWard)
    {
        cout << "Ward Transfer: "
             << name << " -> "
             << newWard << endl;

        ward = newWard;
    }
};

int main()
{
    Patient p1(1001, "Surbhi", 23, "Cardiology", "0+");

    Patient p2(1002, "Raj");

    Patient p3;

    Patient* patients = new Patient[4];

    cout << "\nDynamic Patient Records:" << endl;

    for (int i = 0; i < 4; i++)ve
    {
        patients[i].displayRecord();
    }

    p2.transferWard("ICU");

    delete[] patients;

    return 0;
}

//We use constructor overloading to create patients with default details, emergency details, or complete details. 
//The const bloodGroup is initialized using a constructor initializer list because it cannot be changed later. 
//We use a dynamic array with new to store multiple patients and delete[] to free the memory. 
//The destructor displays a message when each patient object is destroyed, helping us understand the object lifecycle.