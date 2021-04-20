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


void Patient::fileHandlingPat(patientDetail &p1){

    stringstream ssId,ssName;
    ssId << p1.id;
    ssName << p1.name;

    string idStr, nameStr;
    ssId >> idStr;
    ssName >> nameStr;

//    p1.fileNamePat = (idStr + "_" + nameStr + "_pat"+ ".txt").c_str();
    ofstream outStream((idStr + "_" + nameStr + "_pat"+ ".txt").c_str());
    if(outStream)
    {
        

        outStream << "\t\t\t\t\t\t\t\t\tInformation of Patient " << endl;
        outStream << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
        outStream << "\t\t\t\t\t\t\t01 >> Patient's Id                   : " << p1.id << endl;
        outStream << "\t\t\t\t\t\t\t02 >> Patient's Name                 : " << p1.name << endl;
        outStream << "\t\t\t\t\t\t\t03 >> Patient's Age                  : " << p1.age << endl;
        outStream << "\t\t\t\t\t\t\t04 >> Patient's Contact Number       : " << p1.contactNo << endl;
        outStream << "\t\t\t\t\t\t\t05 >> Patient's Address              : " << p1.address << endl;
        outStream << "\t\t\t\t\t\t\t06 >> Patient's Blood Group          : " << p1.bloodGroup << endl;
        outStream << "\t\t\t\t\t\t\t07 >> Symptoms shown by Patient      : " << p1.symptom << endl;
        outStream << "\t\t\t\t\t\t\t08 >> Patient's Room No              : " << p1.roomNo << endl;
        outStream << "\t\t\t\t\t\t\t09 >> Patient's admit date           : " << p1.admitDate << endl;
        outStream << "\t\t\t\t\t\t\t10 >> Patient's Medical charge       : " << p1.medCharge << endl;
        outStream << "\t\t\t\t\t\t\t11 >> Patient's Room charge          : " << p1.roomCharge << endl;
        outStream << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;

        outStream << endl << endl;
    }

    outStream.close();

}

void Patient::addPatientInfo()
{   
    bcd:
    cout << "\t\t\tHow many new patient??  ";
    cin >> patNo;
    cin.ignore();
    cout << endl << endl;
    if (patNo == 0)
    {
        cout << "\t\t\tOOPS!!! You are not allowed to enter the entries for 0 patient\n";
        cout << "\t\t\t\tPress any key to enter number of patient again!!" ;
        cin.get();
        system("cls");
        goto bcd;
    }
    else{

        cout << "\t\t\tEnter the Patient's information:\n";

        for (int i = 0; i < patNo; i++)
        {

            cout << "\t\t\tEnter Patient's ID                           : ";
            cin >> p1[indexOfPatient].id;
            cin.ignore();

            cout << "\t\t\tEnter Patient's Name                         : ";
            cin.getline(p1[indexOfPatient].name, 40);

            cout << "\t\t\tEnter Patient's Age                          : ";
            cin >> p1[indexOfPatient].age;
            cin.ignore();

            cout << "\t\t\tEnter Patient's Contact Number               : ";
            cin >> p1[indexOfPatient].contactNo;
            cin.ignore();

            cout << "\t\t\tEnter Patient's Address                      : ";
            cin.getline(p1[indexOfPatient].address, 40);

            cout << "\t\t\tEnter Patient's Blood  Group                 : ";
            cin.getline(p1[indexOfPatient].bloodGroup, 10);

                
            cout<<"\t\t\tSymptoms shown by patient                    : ";
            cin.getline(p1[indexOfPatient].symptom, 40);

            cout << "\t\t\tEnter Patient's admit date                   : ";
            cin.getline(p1[indexOfPatient].admitDate, 20);

            cout << "\t\t\tEnter Patient's Room Number                  : ";
            cin >> p1[indexOfPatient].roomNo;

            cout << "\t\t\tEnter Patient's Room charge                  : ";
            cin >> p1[indexOfPatient].roomCharge;

            cout << "\t\t\tEnter Patient's Medical charge               : ";
            cin >> p1[indexOfPatient].medCharge;

            p1[indexOfPatient].totalCharge = p1[indexOfPatient].roomCharge + p1[indexOfPatient].medCharge;
            indexOfPatient++;

            cout << endl;
            cout << "The information of " << i + 1 << " Patient is added into database.\n";
            cout << endl  << endl;
            if (patNo > 1)
            {
                cout << "Fill the information of " << " Patient " << i + 2 << endl;
            }
        }
        cout << "\t\t\t\tPress any key to continue . . ." << endl;
        cin.get();
    }
}

void Patient::displayPatientInfo(){

    int inpId;
    int i = 0;

    if (indexOfPatient == 0)
    {
        cout << "\n\t\t\t\t\t\t\tOOPS!!No record of patient available to display\n";
        cout << "\n\t\t\t\t\t\t\t   Press any key To choose another Option . . . ";
    }
    else
    {
        cout << "\t\t\t\t\tEnter the patient's id: ";
        cin >> inpId;
        cin.ignore();

        cout << endl << endl << endl;
        int flag = 0;
        for (i = 0; i < indexOfPatient; i++)
        {
            if (p1[i].id == inpId)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {

            cout << "\t\t\t\t\t\t\t\t\tInformation of Patient " << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << "\t\t\t\t\t\t\t01 >> Patient's Id                   : " << p1[i].id << endl;
            cout << "\t\t\t\t\t\t\t02 >> Patient's Name                 : " << p1[i].name << endl;
            cout << "\t\t\t\t\t\t\t03 >> Patient's Age                  : " << p1[i].age << endl;
            cout << "\t\t\t\t\t\t\t04 >> Patient's Contact Number       : " << p1[i].contactNo << endl;
            cout << "\t\t\t\t\t\t\t05 >> Patient's Address              : " << p1[i].address << endl;
            cout << "\t\t\t\t\t\t\t06 >> Patient's Blood Group          : " << p1[i].bloodGroup << endl;
            cout << "\t\t\t\t\t\t\t07 >> Symptoms shown by Patient      : " << p1[i].symptom << endl;
            cout << "\t\t\t\t\t\t\t08 >> Patient's Room No              : " << p1[i].roomNo << endl;
            cout << "\t\t\t\t\t\t\t09 >> Patient's admit date           : " << p1[i].admitDate << endl;
            cout << "\t\t\t\t\t\t\t10 >> Patient's Medical charge       : " << p1[i].medCharge << endl;
            cout << "\t\t\t\t\t\t\t11 >> Patient's Room charge          : " << p1[i].roomCharge << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;

            cout << endl << endl;


            char get;
            cout << "\t\t\t\t\t\t\t:: Do you want to save this information permanently? [Y/n] ";
            cin >> get;
            cin.ignore();
            if (get == 'Y' || get == 'y' || get == '\n')
            {
                fileHandlingPat(p1[i]);
            }
            cout << "\t\t\t\t\t\t\t:: Patient's detail is saved into file !!" << endl;

        }

        else
        {
            cout << " \n\n\t\t\t\t\t\t\t    No such ID in database " << endl;
        }
            cout << " \n\t\t\t\t\t\t\tPress any key to choose another option.... ";
    }
    cin.get();
    cout << endl;
}


void Patient::detailOfAllPatients(){

    if (indexOfPatient == 0)
    {
        cout << "\n\t\t\t\t\t\t\tOOPS!!No record to display\n";
        cout << "\n\t\t\t\t\t\tPress any key to choose another option.... ";
    }
    else
    {

        cout << "\t\t\t\t****************************************************************************************************\n";
        cout << "\t\t\t\t*                      DETAILS OF ALL THE PATIENTS IN THE HOSPITAL                                 *\n";
        cout << "\t\t\t\t****************************************************************************************************\n";
        cout << "\t\t\t\t* ID\t" << "Name \t\t" << "       Age\t" << "Blood Group\t" << "    Symptoms    \t" << "      Admit date   *"<< endl;
        cout << "\t\t\t\t****************************************************************************************************\n";

        int i;
        for (i = 0; i < indexOfPatient; i++)
        {
            cout<<"\t\t\t\t " << p1[i].id<< "    " << setfill(' ') << p1[i].name << setw(12) << p1[i].age << setw(12)
            << p1[i].bloodGroup <<setw(23) << p1[i].symptom << setw(26) << p1[i].admitDate << "\t"  <<endl;
            cout << "\t\t\t\t----------------------------------------------------------------------------------------------------\n";
        }
        cout << " \n\t\t\tPress any key to choose another option.... ";
    }
    cin.get();
    cout << endl;
}

void Patient::genPatientBill(){
    
    int inpId;
    int i = 0;

    if (indexOfPatient == 0)
    {
        cout << "\n\t\t\t\t\t\t\tOOPS!!No record of patient available to display\n";
        cout << "\n\t\t\t\t\t\t\t   Press any key To choose another Option.... ";
    }
    else
    {
        cout << "\t\t\t\t\tEnter the patient's id: ";
        cin >> inpId;
        cin.ignore();
        cout << endl << endl << endl;
        
        int flag = 0;
        for (i = 0; i < indexOfPatient; i++)
        {
            if (p1[i].id == inpId)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {

            cout << "\t\t\t\t\t\t\t\t\tBill of Patient "<<p1[i].id << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << "\t\t\t\t\t\t\t >> Patient's Name                 : " << p1[i].name << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << "\t\t\t\t\t\t\t >> Patient's Room charge          : " << p1[i].roomCharge << endl;
            cout << "\t\t\t\t\t\t\t >> Patient's Medical charge       : " << p1[i].medCharge << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;
            cout << "\t\t\t\t\t\t\tTOTAL CHARGE                        : " << p1[i].totalCharge << endl;
            cout << "\t\t\t\t\t\t\t-" << setfill('-') << setw(50) << "-" << endl;

            cout << endl << endl;

        }
        else
        {
            cout << " \n\n\t\t\t\t\t\t\t\t   No such ID in database " << endl;
        }
            cout << " \n\t\t\t\t\t\t\tPress any key To choose another Option.... ";
    }
    cin.get();
}

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
