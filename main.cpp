
/**************************************************
 * HOSPITAL MANAGEMENT SYSTEM
 *************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include"Login.h"



/**************************************************
 * structure for doctor's detail
 *************************************************/
typedef struct
{
    int id, age;
    char name[50], experience[50], qualification[50], specialization[50], availablTime[50];
} doctorDetail;

/**************************************************
 * structure for patient's detail
 *************************************************/
typedef struct
{
    int id, age;
    
    int roomCharge, medCharge, totalCharge;
    char name[50],  contactNo[20], address[50], bloodGroup[50], disease[50], symptom[50], admitDate[50], roomNo[50];
}patientDetail;


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
    void fileHandling(int,char[]);

};


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
};


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
                            d.addDoctorInfo();
                            sleep(0.8);
                            goto label3;
                            break;

                        case 2:
                            system("clear");
                            sleep(0.8);
                            //display doctor's info
                            d.displayDoctorInfo();
                            sleep(0.8);
                            goto label3;
                            break;

                        case 3:
                            system("clear");
                            sleep(0.8);
                            //details of all the doctor's info
                            d.detailOfAllDoctor();
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
                            sleep(0.8);
                            goto label4;
                            break;

                        case 2:
                            system("clear");
                            sleep(0.8);
                            //Display Patient's Information
                            p.displayPatientInfo();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 3:
                            system("clear");
                            sleep(0.8);
                            //Details of All the Patient's Information
                            p.detailOfAllPatients();
                            sleep(0.8);
                            goto label4;
                            break;

                        case 4:
                            system("clear");
                            sleep(0.8);
                            //Generate Patient's Bill
                            p.genPatientBill();
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