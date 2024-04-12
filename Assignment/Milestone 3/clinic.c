/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, eligible_record = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            eligible_record = 1;
        }
    }

    if (!eligible_record)
    {
        printf("*** No records found ***\n\n");
    }

    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int option;

    // Printing menu for user
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &option);
        printf("\n");

        if (option == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (option == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (option != 0);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i, structSize = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            structSize++;
        }
    }
    if (max > structSize)
    {
        patient[structSize].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + structSize);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int pNumber, index;
    printf("Enter the patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        menuPatientEdit(patient + index);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int pNumber, index;
    char choice;
    printf("Enter the patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else
        {
            // Assigning patient to safe empty state so that the other function can't access it
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;

    // Sorting the data in the array
    sort(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    int lastDay = 31;
    int i, j;
    struct Date date;

    // Taking the year as input
    printf("Year        : ");
    date.year = inputIntPositive();

    // Taking the month as input
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    // Taking the day as input
    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        lastDay = 30;
    }
    if (date.month == 2)
    {
        lastDay = 28;
    }
    if (date.year % 4 == 0 && date.month == 2)
    {
        lastDay = 29;
    }

    printf("%d)  : ", lastDay);
    date.day = inputIntRange(1, lastDay);
    printf("\n");

    // Sorting the data is the array
    sort(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *app, int maxAppointments, struct Patient *pt, int maxPatients)
{
    // Declaring two temporary structs
    struct Date date;
    struct Time time;

    // Declaring variables
    int lastDay = 31;
    int patientNumber, index, slotNotAvailable = 1;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0)
    {
        while (slotNotAvailable)
        {
            // Taking the year as input
            printf("Year        : ");
            date.year = inputIntPositive();

            // Taking the month as input
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            // Taking the day as input
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11)
            {
                lastDay = 30;
            }
            if (date.month == 2)
            {
                lastDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2)
            {
                lastDay = 29;
            }

            printf("%d)  : ", lastDay);
            date.day = inputIntRange(1, lastDay);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking whether time slot is available
            if (timeSlotAvailable(date, time, app, maxAppointments))
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else
            {
                while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                slotNotAvailable = 0;
            }
        }

        // Assigning the values to the next available slot
        index = nextSlotAvailable(app, maxAppointments);
        app[index].date = date;
        app[index].time = time;
        app[index].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *app, int maxAppointments, struct Patient *pt, int maxPatients)
{
    struct Date date;
    int index, patientNumber, lastDay = 0, aptIndex;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0)
    {
        // Taking the year as input
        printf("Year        : ");
        date.year = inputIntPositive();

        // Taking the month as input
        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        // Taking the day as input
        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            lastDay = 30;
        }
        if (date.month == 2)
        {
            lastDay = 28;
        }
        if (date.year % 4 == 0 && date.month == 2)
        {
            lastDay = 29;
        }
        printf("%d)  : ", lastDay);
        date.day = inputIntRange(1, lastDay);

        aptIndex = validAppointment(patientNumber, date, app, maxAppointments);

        if (aptIndex >= 0)
        {
            printf("\n");

            displayPatientData(&pt[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                app[aptIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int pNumber, index;
    printf("Search by patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
    }

    else
    {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, match = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
        }
    }
    printf("\n");

    if (match == 0)
    {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int nextNum, maxNum = patient[0].patientNumber, i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxNum)
        {
            maxNum = patient[i].patientNumber;
        }
    }

    nextNum = maxNum + 1;
    return nextNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    // Iterate through the array to find the patient number
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    // If anything is not found, -1 is returned
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient *patient)
{
    int i;
    char name[NAME_LEN];

    // Displaying form to take input
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    fgets(name, sizeof(name), stdin);

    // Storing the name in the struct
    for (i = 0; i < strlen(name) - 1; i++)
    {
        patient->name[i] = name[i];
    }

    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone *phone)
{
    int choice, i;
    char inputNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {

    case 1:
        // Storing the description in the struct
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 2:
        // Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 3:
        // Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s", phone->description);
        printf("\n");

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 4:
        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);

        *phone->number = 0;

        break;

    default:
        printf("Error:\n");
        break;
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
