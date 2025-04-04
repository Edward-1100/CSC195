#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    char initial;
    short age;
    bool isAdult;
    string zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
    const float TAX = 0.1f;


    cout << "Enter first name: ";
    cin >> name;


    cout << "Enter last initial: ";
    cin >> initial;


    while (true) {
        cout << "Enter age: ";
        cin >> age;

        if (age >= 0)
            break;
        cout << "Age Can Not Be Negative. Please Try Again: \n";
    }
    isAdult = (age >= 18);


    while (true) {
        cout << "Enter zipcode: ";
        cin >> zipcode;

        if (zipcode.length() == 5)
            break;
        cout << "Zipcode Must Be 5 Digits. Please Try Again: \n";
    }


    while (true) {
        cout << "Enter wage (Hourly): ";
        cin >> wage;

        if (wage >= 0)
            break;
        cout << "Wage Must Be Positive. Please Try Again: \n";
    }


    while (true) {
        cout << "Enter Days Worked (0-7)? ";
        cin >> daysWorked;

        if (daysWorked >= 0 && daysWorked <= 7)
            break;
        cout << "Days Worked Must Be Between 0 And 7. Please Try Again: \n";
    }


    float totalHours = 0.0f;
    for (int i = 0; i < daysWorked; i++) {

        while (true) {

            cout << "Hours worked on day " << (i + 1) << ": ";
            cin >> hoursWorkedPerDay[i];

            if (hoursWorkedPerDay[i] >= 0)
                break;
            cout << "Hours Must Be Positive. Please Try Again: \n";
        }

        totalHours += hoursWorkedPerDay[i];
    }


    float grossIncome = totalHours * wage;
    float taxAmount = grossIncome * TAX;
    float netIncome = grossIncome - taxAmount;


    cout << "\n--------------------\n";
    cout << "\nPayroll Summary:\n";
    cout << "Name: " << name << " " << initial << ".\n";
    cout << "Age: " << age << " (" << (isAdult ? "Adult" : "Not an adult") << ")\n";
    cout << "Zipcode: " << zipcode << "\n";
    cout << "Hourly Wage: $" << wage << "\n";
    cout << "Total Hours: " << totalHours << "\n";
    cout << "Gross Income: $" << grossIncome << "\n";
    cout << "Tax: $" << taxAmount << "\n";
    cout << "Net Income: $" << netIncome << "\n";


    return 0;
}
