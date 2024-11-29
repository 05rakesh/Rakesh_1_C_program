#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Patient {
    char name[50];
    int age;
    char gender;
    char symptoms[100];
} Patient;
typedef struct Doctor {
    char name[50];
    char specialization[50];
    int available_slots;
} Doctor;
void addPatient(Patient *patients, int *patientCount) {
    Patient newPatient;
    printf("Enter patient name: ");
    scanf("%s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter patient gender (M/F): ");
    scanf(" %c", &newPatient.gender);
    printf("Enter patient symptoms: ");
    scanf(" %[^\n]", newPatient.symptoms);
    patients[*patientCount] = newPatient;
    (*patientCount)++;
    printf("Patient added successfully!\n");
}
void addDoctor(Doctor *doctors, int *doctorCount) {
    Doctor newDoctor;
    printf("Enter doctor name: ");
    scanf("%s", newDoctor.name);
    printf("Enter doctor specialization: ");
    scanf("%s", newDoctor.specialization);
    printf("Enter number of available slots: ");
    scanf("%d", &newDoctor.available_slots);
    doctors[*doctorCount] = newDoctor;
    (*doctorCount)++;
    printf("Doctor added successfully!\n");
}
void scheduleAppointment(Patient *patients, int patientCount, Doctor *doctors, int doctorCount) {
    int patientIndex, doctorIndex;
    printf("Enter patient name: ");
    char patientName[50];
    scanf("%s", patientName);
    patientIndex = -1;
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].name, patientName) == 0) {
            patientIndex = i;
            break;
        }
    }
    if (patientIndex == -1) {
        printf("Patient not found!\n");
        return;
    }
    printf("Enter doctor specialization: ");
    char specialization[50];
    scanf("%s", specialization);
    doctorIndex = -1;
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].specialization, specialization) == 0 && doctors[i].available_slots > 0) {
            doctorIndex = i;
            break;
        }
    }
    if (doctorIndex == -1) {
        printf("No doctor available with this specialization.\n");
        return;
    }
    printf("Appointment scheduled for %s with %s.\n", patients[patientIndex].name, doctors[doctorIndex].name);
    doctors[doctorIndex].available_slots--;
}
void displayPatients(Patient *patients, int patientCount) {
    if (patientCount == 0) {
        printf("No patient records found.\n");
        return;
    }
    printf("Patient Records:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Patient %d:\n", i + 1);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Gender: %c\n", patients[i].gender);
        printf("Symptoms: %s\n\n", patients[i].symptoms);
    }
}
void displayDoctors(Doctor *doctors, int doctorCount) {
    if (doctorCount == 0) {
        printf("No doctor records found.\n");
        return;
    }
    printf("Doctor Availability:\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("Doctor %d:\n", i + 1);
        printf("Name: %s\n", doctors[i].name);
        printf("Specialization: %s\n", doctors[i].specialization);
        printf("Available Slots: %d\n\n", doctors[i].available_slots);
    }
}

int main() {
    int patientCount = 0;
    int doctorCount = 0;
    Patient *patients = malloc(sizeof(Patient) * 100);
    Doctor *doctors = malloc(sizeof(Doctor) * 100);
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Schedule Appointment\n");
        printf("4. Display Patient Records\n");
        printf("5. Display Doctor Availability\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                addDoctor(doctors, &doctorCount);
                break;
            case 3:
                scheduleAppointment(patients, patientCount, doctors, doctorCount);
                break;
            case 4:
                displayPatients(patients, patientCount);
                break;
            case 5:
                displayDoctors(doctors, doctorCount);
                break;
            case 6:
                printf("Exiting the program...\n");
                free(patients);
                free(doctors);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
