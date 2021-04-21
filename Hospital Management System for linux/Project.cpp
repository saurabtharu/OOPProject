//store time in character variable
// void TimeDisplay()
// {
//     time_t rawtime;
//     struct tm *timeinfo;

//     time(&rawtime);
    
//     timeinfo = localtime(&rawtime);

//     strftime(time101, sizeof(time101), "%d-%m-%Y %H:%M:%S", timeinfo);
// }

/**************************************************
 * 
 *************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <curses.h>
#include<ncurses.h>
using namespace std;
#include "Login.h"
#include<fstream>
#include<sstream>
// #include<os

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
    int indexOfDoctors = 0;
    void addDoctorInfo();
    void displayDoctorInfo();
    void detailOfAllDoctor();
    void fileHandlingDoc(doctorDetail&);
    // void fileHandlingDoc(int, int, char[]);

};

void Doctor::fileHandlingDoc(doctorDetail &d1){

    stringstream ssId,ssName;
    ssId << d1.id;
    ssName << d1.name;
 
    string idStr,
        nameStr;
    ssId >> idStr;
    ssName >> nameStr;

    d1.fileNameDoc = (idStr + "_" + nameStr + "_doc"+ ".txt").c_str();
    // string outputFileName = (idStr + "_" + nameStr + "_doc"+ ".txt").c_str();

    ofstream outStream(d1.fileNameDoc);
    // ofstream outStream(outputFileName);

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
        system("clear");
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
                // fileHandlingDoc(d1[i].id, i, d1[i].name);
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
        int indexOfPatient = 0;
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

    p1.fileNamePat = (idStr + "_" + nameStr + "_pat"+ ".txt").c_str();
    // string outputFileName = (idStr + "_" + nameStr + "_doc"+ ".txt").c_str();

    ofstream outStream(p1.fileNamePat);
    // ofstream outStream(outputFileName);

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
        system("clear");
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
            // cout << "" << time101 << endl;
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
                // fileHandlingPat(d1[i].id, i, d1[i].name);
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

    system("clear");

    askKey();
    // cin.get();
    
    label1:
    system("clear");
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
            system("clear");
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
                    system("clear");
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
                            system("clear");
                            sleep(0.8);
                            //new doctor's info
                            // TimeDisplay();
                            d.addDoctorInfo();
                            // system("clear");
                            sleep(0.8);
                            goto label3;
                            break;

                        case 2:
                            system("clear");
                            sleep(0.8);
                            //display doctor's info
                            d.displayDoctorInfo();
                            // system("clear");
                            sleep(0.8);
                            goto label3;
                            break;

                        case 3:
                            system("clear");
                            sleep(0.8);
                            //details of all the doctor's info
                            d.detailOfAllDoctor();
                            // system("clear");
                            sleep(0.8);
                            goto label3;
                            break;

                        case 4:
                            system("clear");
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
                    system("clear");
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
                            system("clear");
                            sleep(0.8);
                            //Add new Patient's Information
                            p.addPatientInfo();
                            // system("clear");
                            sleep(0.8);
                            goto label4;
                            break;

                        case 2:
                            system("clear");
                            sleep(0.8);
                            //Display Patient's Information
                            p.displayPatientInfo();
                            sleep(0.8);
                            // system("clear");
                            goto label4;
                            break;

                        case 3:
                            system("clear");
                            sleep(0.8);
                            //Details of All the Patient's Information
                            p.detailOfAllPatients();
                            // system("clear");
                            sleep(0.8);
                            goto label4;
                            break;

                        case 4:
                            system("clear");
                            sleep(0.8);
                            //Generate Patient's Bill
                            p.genPatientBill();
                            // system("clear");
                            sleep(0.8);
                            goto label4;
                            break;

                        case 5:
                            system("clear");
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