#include <iostream>
#include <string>
using namespace std;

int ID = 2001;

class Staff
{
private:
    int staffId;
    string fullName;
    string team;
    char level;
    double salary;
    bool active = true;

public:
    inline static int staffCount;

    Staff()
    {
        staffId = ID++;
        staffCount++;
    }

    void setName(const string& n)
    {
        if (!n.size())
        {
            cout << "Name cannot be empty" << endl;
            return;
        }

        fullName = n;
    }

    void setDepartment(const string& d)
    {
        if (d == "Engineering" || d == "HR" ||
            d == "Finance" || d == "Operations")
        {
            team = d;
        }
        else
        {
            cout << "ERROR: '" << d
                 << "' is not a registered department." << endl;
        }
    }

    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            level = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    void setSalary(double s)
    {
        if (s <= 10000 || s >= 500000)
        {
            cout << "Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."
                 << endl;
            return;
        }

        salary = s;
    }

    void deactivate()
    {
        active = false;
    }

    int getId() const
    {
        return staffId;
    }

    string getName() const
    {
        return fullName;
    }

    string getDepartment() const
    {
        return team;
    }

    char getGrade() const
    {
        return level;
    }

    double getSalary() const
    {
        return salary;
    }

    bool getStatus() const
    {
        return active;
    }

    void acceptDetails()
    {
        string input;

        cout << "Enter Name: " << endl;
        getline(cin >> ws, input);
        setName(input);

        cout << endl;
        cout << "Enter Department: " << endl;
        getline(cin, input);
        setDepartment(input);

        cout << endl;
        cout << "Enter Grade: " << endl;
        getline(cin, input);
        setGrade(input[0]);

        cout << endl;
        cout << "Enter Basic Salary: " << endl;
        getline(cin, input);
        setSalary(stod(input));
    }

    static int getStaffCount()
    {
        return staffCount;
    }

    double calculateAllowance() const
    {
        if (level == 'A')
            return salary * 0.40;

        else if (level == 'B')
            return salary * 0.30;

        else if (level == 'C')
            return salary * 0.20;

        else
            return salary * 0.10;
    }

    double calculateGross() const
    {
        return salary + calculateAllowance();
    }

    double calculateTax() const
    {
        double gross = calculateGross();

        if (gross <= 50000)
            return 0;

        else if (gross <= 100000)
            return (gross - 50000) * 0.10;

        else
            return 5000 + (gross - 100000) * 0.20;
    }

    double calculateNet() const
    {
        return calculateGross() - calculateTax();
    }

    void printSalarySlip() const
    {
        cout << "============================================" << endl;
        cout << "EMPLOYEE PAYSLIP — AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "EMP ID: " << staffId << endl;
        cout << "Name: " << fullName << endl;
        cout << "Department: " << team << endl;
        cout << "Grade: " << level << endl;
        cout << "Status: " << (active ? "Active" : "Inactive") << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary: " << salary << endl;
        cout << "Allowances: " << calculateAllowance() << endl;
        cout << "Gross Salary: " << calculateGross() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction: " << calculateTax() << endl;
        cout << "Net Salary: " << calculateNet() << endl;

        cout << "--------------------------------------------" << endl;
    }
};

int main()
{
    Staff s1;
    Staff* s2 = new Staff();
    Staff* s3 = new Staff();

    s1.acceptDetails();
    s2->acceptDetails();
    s3->acceptDetails();

    s1.printSalarySlip();
    s2->printSalarySlip();
    s3->printSalarySlip();

    s3->deactivate();

    if (!s3->getStatus())
        cout << s3->getName()
             << " is no longer active. Payroll skipped." << endl;

    cout << "Total Employees: "
         << Staff::getStaffCount() << endl;

    delete s2;
    delete s3;

    return 0;
}