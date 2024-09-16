//FA2023_EvaluateDriverLicenseComputerTest_Mahto.cpp 
#include <iostream> 
#include<string>
#include<iomanip>
#include <time.h>
#include <sstream>
#include<array>
using namespace std;

void info(string& ss, string& L_name, string& F_name, string& address) {
   
    //Reading information from keyboard for info
    cout << "Enter your SS number" << endl;
    getline(cin, ss);
    cout << "Enter your Last name" << endl;
    getline(cin, L_name);
    cout << "Enter your first name" << endl;
    getline(cin, F_name);  
    cout << "Enter your address" << endl;
    getline(cin, address);  
}

string number() {
    string licenseNumber;
    stringstream ss;
    int rand4_digits; // to hold the random number 4 digits
    srand(time(0)); //to get different random each time

    for (int i = 0; i < 2; i++)
    {
        rand4_digits = 1000 + rand() % 1000; //generate random 4 digits
        ss << rand4_digits; 
        
    }
    licenseNumber = ss.str();
    return licenseNumber;
}

string final(int result) {
    //To determine if the user passed or failed the exam
    string outcome;
    if (result >= 20) {
        outcome = "PASSED";
    }
    else {
        outcome = "FAILED";
    }
    return outcome;
}

int main()
{
    //To keep the loop going if the user wants to take exam again
    char decision;
    do {
        //declaring variables
        char answers[25];
        char wrong[25];
        int wrongcount = 0;
        char key[] = { 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D',  'D', 'D', 'A', 'A', 'A',  'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'D', 'A'};
        string ss, L_name, F_name, address, L_number, grade;
        int result = 0;
        info(ss, L_name, F_name, address);
        L_number = number();
        char currentDate[10];
        _strdate_s(currentDate);
        for (int i = 0; i < 25; ) {//To enter answers from user one question at a time
            char ans;
            cout << "Enter Answer for Question no."<<i+1<<endl; 
            cin >> ans;
            if (ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D') {//To make sure valid answer is only stored
                answers[i] = ans;
                i++;
            }
            else {

                cout << "Invalid Input Please enter A , B , C or D " << endl;
            }
        }
        
        
        //To check the score the user in exam
        for (int i = 0; i < 25; i++) {
            if (key[i] == answers[i]) {
                result = result + 1;
            }
            else {
                wrong[wrongcount++] = i;

            }
        }
        grade = final(result);
        
        //Displaying all the required lines of code
        cout << "FA2023_EvaluateDriverLicenseComputerTest_Mahto.cpp" << endl;
        cout << "DRIVER TEST RESULT - ABHASH MAHTO" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << setw(25) << left << "Driver's name:" <<setw(28)<<right<< L_name << ", " << F_name << endl;
        cout << setw(25) << left << "SS Number:"<< setw(34) << right<< ss << endl;
        cout << setw(25) << left << "Address:" << setw(34) << right << address << endl;
        cout << setw(25) << left << "Driver's License:" << setw(34) << right << L_number << endl;
        cout << setw(25) << left << "Test Date :" << setw(34) << right << currentDate << endl;
        cout << setw(25) << left << "Result:" << setw(34) << right << grade << endl;
        cout << setw(25) << left << "Missed Questions:"; 
        cout << setw(25) << right << " ";
        for (int i = 0; i < wrongcount; i++) {
            cout << wrong[i] + 1;
            if (i < wrongcount - 1) {//To make sure there is no"," after the last value
                cout << ", ";
            }
        }
        cout << " " << endl;
        cout << "Press Y if you want to redo" << endl;     
        cin >> decision;//To repeat the loop     
        cin.ignore();//Helps remove all the input buffer
    } while (decision == 'Y');
        system("pause"); //This will pause the output to read
    return 0;
}
