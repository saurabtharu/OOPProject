/**************************************************
 * HOSPITAL MANAGEMENT SYSTEM
 *************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include<Windows.h>
using namespace std;
#include "Login.h"
#include<fstream>
#include<sstream>

/**************************************************
 * structure for doctor's detail
 *************************************************/
typedef struct
{
    int id, age;
    char name[50], experience[50], qualification[50], specialization[50], availablTime[50];
    string fileNameDoc;

} doctorDetail;

/**************************************************
 * structure for patient's detail
 *************************************************/
typedef struct
{
    int id, age;
    
    int roomCharge, medCharge, totalCharge;
    char name[50],  contactNo[20], address[50], bloodGroup[50], disease[50], symptom[50], admitDate[50], roomNo[50];
    string fileNamePat;
} patientDetail;

/**************************************************
 * class for Hospital ( parent class)
 *************************************************/
class Hospital
{
public:

};

/**************************************************
 * class for Doctor ( child class of Hospital)
 *************************************************/
class Doctor : public Hospital
{
public:
    doctorDetail d1[20];
    int docNo;
    int indexOfDoctors;
    void addDoctorInfo();
    void displayDoctorInfo();
    void detailOfAllDoctor();
    void fileHandlingDoc(doctorDetail&);

};


void Doctor::fileHandlingDoc(doctorDetail &d1){

    stringstream ssId,ssName;
    ssId << d1.id;
    ssName << d1.name;
 
    string idStr, nameStr;
    ssId >> idStr;
    ssName >> nameStr;

    d1.fileNameDoc = (idStr + "_" + nameStr + "_doc"+ ".txt").c_str();

    ofstream outStream(d1.fileNameDoc);

    if(outStream)
    {
        
        outStream << "\t\t\t\t\t\t\t\t\tInformation of Docotor " << endl;
        outStream << "\t\t\t\t\t\t\t-" << setfill('-') << setw(52) << "-" << endl;
        outStream << "\t\t\t\t\t\t\t1 >> Doctor's Id                   : " << d1.id << endl;
        outStream << "\t\t\t\t\t\t\t2 >> Doctor's Name                 : " << d1.name << endl;
        outStream << "\t\t\t\t\t\t\t3 >> Doctor's Age                  : " << d1.age << endl;
        outStream << "\t\t\t\t\t\t\t4 >> Doctor's Qualification        : " << d1.qualification << endl;
        outStream << "\t\t\t\t\t\t\t5 >> Doctor's Specilization        : " << d1.specialization << endl;
        outStream << "\t\t\t\t\t\t\t6 >> Doctor's Experience           : " << d1.experience << endl;
        outStream << "\t\t\t\t\t\t\t7 >> Doctor's Time of available    : " << d1.availablTime << endl;
        outStream << "\t\t\t\t\t\t\t-" << setfill('-') << setw(52) << "-" << endl;
        outStream << endl << endl;
    }

    outStream.close();

}
void Doctor::addDoctorInfo()
{
    abc:
    cout << "How many new doctors??  ";
    cin >> docNo;
    cin.ignore();
    cout << endl << endl;

    if (docNo == 0)
    {
        cout << "\t\t\tOOPS!!! You are not allowed to enter the entries for 0 doctor\n";
        cout << "\n\t\t\t\t  Press any key to enter number of doctors again!!"  ;
        cin.get();
        system("cls");
        goto abc;
    }
    else
    {

        cout << "\t\t\tEnter the doctor's information:\n";

        for (int i = 0; i < docNo; i++)
        {
            idLabel:
            cout << "\t\t\tEnter Doctor's ID                                      : ";
            cin >> d1[indexOfDoctors].id;
            for (int a = 0; a < i; a++)
            {
                if (d1[indexOfDoctors].id == d1[a].id)
                {
                    cout << "\t\t\tUser of id " << d1[indexOfDoctors].id << " already exits." << endl;
                    cout << "\t\t\tPlease enter the id again." << endl;
                    goto idLabel;
                }
            }
            cin.ignore();

            cout << "\t\t\tEnter Doctor's name                                    : ";
            cin.getline(d1[indexOfDoctors].name, 40);

            cout << "\t\t\tEnter Doctor's age                                     : ";
            cin >> d1[indexOfDoctors].age;
            cin.ignore();

            cout << "\t\t\tEnter Doctor's Qualification                           : ";
            cin.getline(d1[indexOfDoctors].qualification, 40);
            
            cout << "\t\t\tEnter Doctor's Specialization                          : ";
            cin.getline(d1[indexOfDoctors].specialization, 40);

            cout << "\t\t\tEnter Doctor's experience in year                      : ";
            cin.getline(d1[indexOfDoctors].experience, 40);

            cout << "\t\t\tEnter the available time for doctor (FORMAT: HH-HH)    : ";
            cin >> d1[indexOfDoctors].availablTime;
            indexOfDoctors++;

            cout << endl;
            cout << "\t\t\tThe information of " << i + 1 << " doctor is added into database.\n";
            cout << endl << endl;
            if (docNo > 1)
            {
                cout << "\t\t\tFill the information of doctor " << i + 2 << endl;
            }

        }
        cout << "\t\t\tPress any key to continue . . ." << endl;
        cin.get();
    }
}

void Doctor::displayDoctorInfo()
{
    int inpId;
    int i = 0;

    if (indexOfDoctors == 0)
    {
        cout << "\n\t\t\t\t\t\t\tOOPS!!No record of patient available to display\n";
        cout << "\n\t\t\t\t\t\t\t  Press any key to choose another option . . . ";
        cin.get();
    }
    else
    {
        cout << "\t\t\t\t\tEnter the doctor's id: ";
        cin >> inpId;
        cin.ignore();

        cout << endl << endl << endl;
        int flag = 0;
        for (i = 0; i < indexOfDoctors; i++)
        {
            if (d1[i].id == inpId)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            cout << "\t\t\t\t\t\t\t\t\tInformation of Docotor " << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << "\t\t\t\t\t\t\t1 >> Doctor's Id                   : " << d1[i].id << endl;
            cout << "\t\t\t\t\t\t\t2 >> Doctor's Name                 : " << d1[i].name << endl;
            cout << "\t\t\t\t\t\t\t3 >> Doctor's Age                  : " << d1[i].age << endl;
            cout << "\t\t\t\t\t\t\t4 >> Doctor's Qualification        : " << d1[i].qualification << endl;
            cout << "\t\t\t\t\t\t\t5 >> Doctor's Specilization        : " << d1[i].specialization << endl;
            cout << "\t\t\t\t\t\t\t6 >> Doctor's Experience           : " << d1[i].experience << endl;
            cout << "\t\t\t\t\t\t\t7 >> Doctor's Time of available    : " << d1[i].availablTime << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << endl << endl;
            
            char get;
            cout << "\t\t\t\t\t\t\t:: Do you want to save this information permanently? [Y/n] ";
            cin >> get;
            cin.ignore();
            if (get == 'Y' || get == 'y' || get == '\n')
            {
                fileHandlingDoc(d1[i]);
            }
            cout << "\t\t\t\t\t\t\t:: Doctor's detail is saved into file !!" << endl;

        }
        else
        {
            cout << " \n\n\t\t\t\t\t\t\t    No such ID in database " << endl;
            cout << "\n\t\t\t\t\t\tPress any key To choose another Option . . . ";
            cin.get();
        }
    }

}

void Doctor::detailOfAllDoctor()
{

    if (indexOfDoctors == 0)
    {
        cout << "\n\t\t\t\t\t\t\tOOPS!!No record to display\n";
        cout << "\n\t\t\t\t\t\tPress any key To choose another Option . . . ";
    }
    else
    {

        cout << "\t\t\t\t******************************************************************************\n";
        cout << "\t\t\t\t*                 DETAILS OF ALL THE DOCTORS IN THE HOSPITAL                 *\n";
        cout << "\t\t\t\t******************************************************************************\n";
        cout << "\t\t\t\t* ID\t" << "Name \t\t" << "    Specialization\t\t" << "     Available At    *" << endl;
        cout << "\t\t\t\t*\t\t\t\t\t\t\t (Form(HH) - TO(HH)  *" << endl;
        cout << "\t\t\t\t******************************************************************************\n";

        int i;
        for (i = 0; i < indexOfDoctors; i++)
        {
            cout << "\t\t\t\t" << d1[i].id << "\t" << d1[i].name << "\t\t" << d1[i].specialization << "\t\t\t    " << d1[i].availablTime << endl;
            cout << "\t\t\t\t------------------------------------------------------------------------------\n";
        }
        cout << " \n\t\t\tPress Any Button To choose another Option . . . ";
    }
    cin.get();
    cout << endl;
}

/**************************************************
 * class for Patient  ( child class of Hospital ) 
 *************************************************/
class Patient: public Hospital{
    public:
        patientDetail p1[20];
        int patNo;
        int indexOfPatient;
        void addPatientInfo();
        void displayPatientInfo();
        void detailOfAllPatients();
        void genPatientReport();
        void genPatientBill();
        void fileHandlingPat(patientDetail&);

};


/********************************
 * start of main function
 ********************************/
int main()
{
    int choice1, choice2, choice3, choice4;
    Doctor d;
    Patient p;
    system("mode 650");
	SetConsoleTitleA("HOSPITAL MANAGEMENT SYSTEM");
	system("Color 30");
    system("cls");
	
    askKey();
    // cin.get();
    
    label1:
    system("cls");
    cout << "\t\t\t\t\t\t  ******< HOSPITAL MANAGEMENT SYSTEM >******" << endl;
    cout << "\t\t\t\t\t    =" << setfill('=') << setw(50) << "=" << endl << endl;
    cout << "\t\t\t\t\t\t\t1. MENU" << endl << endl;
    cout << "\t\t\t\t\t\t\t2. EXIT" << endl << endl;

    cout << "\t\t\t\t\t\t    Enter your choice: ";
    cin >> choice1;
    cin.ignore();

    switch (choice1)
    {

        case 1:
            

            label2:
            system("cls");
            cout << "\t\t\t\t\t\t\tWHO ARE YOU??  " << endl;
            cout << "\t\t\t\t\t\t=" << setfill('=') << setw(26) << "=" << endl << endl;
            cout << "\t\t\t\t\t\t\t1. DOCTOR      " << endl << endl;
            cout << "\t\t\t\t\t\t\t2. PATIENT     " << endl << endl;
            cout << "\t\t\t\t\t\t\t3. EXIT        " << endl << endl;

            cout << "\t\t\t\t\t\t    Enter your choice: ";
            cin >> choice2;
            cin.ignore();

            switch (choice2)
            {
                case 1:
                    label3:
                    system("cls");
                    cout << "\t\t\t\t\t\t         *********< DOCTOR'S SYSTEM >*********" << endl;
                    cout << "\t\t\t\t\t\t      =" << setfill('=') << setw(43) << "=" << endl << endl;
                    cout << "\t\t\t\t\t\t\t1. Add new Doctor's Information              " << endl << endl;
                    cout << "\t\t\t\t\t\t\t2. Display Doctor's Information              " << endl << endl;
                    cout << "\t\t\t\t\t\t\t3. Details of All the Doctor's Information   " << endl << endl;
                    cout << "\t\t\t\t\t\t\t4. EXIT                                      " << endl << endl << endl;

                    cout << "\t\t\t\t\t\t    Enter your choice: ";
                    cin >> choice3;
                    cin.ignore();

                    switch (choice3)
                    {

                        case 1:
                            system("cls");
                            sleep(0.8);
                            //new doctor's info
                            // TimeDisplay();
                            d.addDoctorInfo();
                            sleep(0.8);
                            goto label3;
                            break;

                        case 2:
                            system("cls");
                            sleep(0.8);
                            //display doctor's info
                            d.displayDoctorInfo();
                            sleep(0.8);
                            goto label3;
                            break;

                        case 3:
                            system("cls");
                            sleep(0.8);
                            //details of all the doctor's info
                            d.detailOfAllDoctor();
                            sleep(0.8);
                            goto label3;
                            break;

                        case 4:
                            system("cls");
                            sleep(0.8);
                            //EXIT
                            goto label2;
                            break;

                        default:
                            cout << "\t\t\t\tInvalid choice : " << choice3 << endl << endl;
                            sleep(2);
                            goto label3;
                            break;
                    }
                    break;

                case 2:



                    label4:
                    system("cls");
                    cout << "\t\t\t\t\t\t         *********< PATIENT'S SYSTEM >*********" << endl;
                    cout << "\t\t\t\t\t\t    =" << setfill('=') << setw(48) << "=" << endl << endl;
                    cout << "\t\t\t\t\t\t\t1. Add new Patient's Information              " << endl << endl;
                    cout << "\t\t\t\t\t\t\t2. Display Patient's Information              " << endl << endl;
                    cout << "\t\t\t\t\t\t\t3. Details of All the Patient's               " << endl << endl;
                    cout << "\t\t\t\t\t\t\t4. Generate Patient's Bill                    " << endl << endl;
                    cout << "\t\t\t\t\t\t\t5. EXIT                                       " << endl << endl;

                    cout << "\t\t\t\t\t\t    Enter your choice: ";
                    cin >> choice4;
                    cin.ignore();

                    switch (choice4)
                    {

                        case 1:
                            system("cls");
                            sleep(0.8);
                            //Add new Patient's Information
                            p.addPatientInfo();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 2:
                            system("cls");
                            sleep(0.8);
                            //Display Patient's Information
                            p.displayPatientInfo();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 3:
                            system("cls");
                            sleep(0.8);
                            //Details of All the Patient's Information
                            p.detailOfAllPatients();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 4:
                            system("cls");
                            sleep(0.8);
                            //Generate Patient's Bill
                            p.genPatientBill();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 5:
                            system("cls");
                            sleep(0.8);
                            //EXIT
                            goto label2;
                            break;

                        default:
                            cout << "\t\t\t\tInvalid choice : " << choice4 << endl << endl;
                            sleep(2);
                            goto label4;
                            break;
                    }
                    break;
                case 3:
                    //EXIT
                    sleep(0.8);
                    goto label1;
                    break;
                default:
                    cout << "\t\t\t\tInvalid choice: " << choice2 << endl << endl;
                    sleep(2);
                    goto label2;
            }
            break;

        case 2:
            cout << "\t\t\t\t\t**********< THANK YOU FOR WORKING!! >**********" << endl;
            exit(0);
        default:
            cout << "\t\t\t\tInvalid choice: " << choice1 << endl << endl;
            sleep(2);
            goto label1;
            break;
    }
}
