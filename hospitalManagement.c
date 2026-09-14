#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

struct Patient {
    int patientId;
    char name[50];
    int age;
    char gender;
    long long int phoneNumber;
    char address[100];
    char symptoms[50];
    struct Patient *link;
};

struct Doctor {
    int doctorId;
    char name[50];
    int age;
    char gender;
    long long int phoneNumber;
    char specialization[50];
    char department[50];
    bool availabilityStatus;
    char availableTimings[50];
    struct Doctor *link;
};

struct Appointment {
    int patientId;
    struct Appointment *link;
};

struct Emergency {
    int patientId;
    int priority;
    struct Emergency *link;
};

struct PatientHistory {
    int patientId;
    char date[20];
    int doctorId;
    char symptoms[50];
    char diagnosis[50];
    char prescription[50];
    struct PatientHistory *link;
};

struct Patient *root = NULL;
struct Doctor *head = NULL;
struct Appointment *f = NULL;
struct Appointment *r = NULL;
struct Emergency *front = NULL;
struct Emergency *rear = NULL;
struct PatientHistory *root1 = NULL;

void patientRegistration()
{
    struct Patient *temp;
    temp = (struct Patient *)malloc(sizeof(struct Patient));
    printf("Enter the patient's id : ");
    scanf("%d",&temp->patientId);
    getchar();
    printf("Enter the patient's name : ");
    fgets(temp->name, 50, stdin);
    printf("Enter the patient's age : ");
    scanf("%d",&temp->age);
    printf("Enter the patient's gender : ");
    scanf(" %c",&temp->gender);
    printf("Enter the patient's phone number : ");
    scanf("%lld",&temp->phoneNumber);
    getchar();
    printf("Enter the patient's address : ");
    fgets(temp->address, 100, stdin);
    printf("Enter the patient's symptoms : ");
    fgets(temp->symptoms, 50, stdin);
    temp->link = NULL;
    if(root==NULL)
        root = temp;
    else
    {
        struct Patient *p = root;
        while(p->link!=NULL)
            p = p->link;
        
        p->link = temp;
    }
    printf("Patient with Patient id %d has been registered\n",temp->patientId);
}

void doctorRegistration()
{
    struct Doctor *temp;
    temp = (struct Doctor *)malloc(sizeof(struct Doctor));
    printf("Enter the doctors's id : ");
    scanf("%d",&temp->doctorId);
    getchar();
    printf("Enter the doctor's name : ");
    fgets(temp->name, 50, stdin);
    printf("Enter the doctor's age : ");
    scanf("%d",&temp->age);
    printf("Enter the doctor's gender : ");
    scanf(" %c",&temp->gender);
    printf("Enter the doctor's phone number : ");
    scanf("%lld",&temp->phoneNumber);
    getchar();
    printf("Enter the doctor's specialization : ");
    fgets(temp->specialization, 50, stdin);
    printf("Enter the doctor's department : ");
    fgets(temp->department, 50, stdin);
    int status;
    printf("Enter the availability of the doctor (1 - yes) (0 - no) : ");
    scanf("%d",&status);
    temp->availabilityStatus = status;
    getchar();
    printf("Enter the availabe timings of the doctor : ");
    fgets(temp->availableTimings,50,stdin);
    temp->link = NULL;
    if(head==NULL)
        head = temp;
    else
    {
        struct Doctor *p = head;
        while(p->link!=NULL)
            p = p->link;

        p->link = temp;
    }
    printf("Doctor with Doctor id %d has been registered\n",temp->doctorId);
}

void patientDisplay()
{
    struct Patient *temp = root;
    int count = 1;
    if(root == NULL)
        printf("No patients registered\n");
    else
    {
        while(temp!=NULL)
        {   
            printf("Patient %d Details : \n",count);
            printf("patient's ID : %d\n",temp->patientId);
            printf("Patient's Name : %s\n",temp->name);
            printf("Patient's Age : %d\n",temp->age);
            printf("Patient's Gender : %c\n",temp->gender);
            printf("Patient's Phone Number : %lld\n",temp->phoneNumber);
            printf("Patient's Address : %s\n",temp->address);
            printf("Patient's Symptoms : %s\n",temp->symptoms);
            count++;
            temp = temp->link;
        }
    }
}

void doctorDisplay()
{
    struct Doctor *temp = head;
    int count = 1;
    if(head == NULL)
        printf("No doctors registered\n");
    else
    {
        while(temp!=NULL)
        {
            printf("Doctor %d Details : \n",count);
            printf("Doctor's ID : %d\n",temp->doctorId);
            printf("Doctor's Name : %s\n",temp->name);
            printf("Doctor's Age : %d\n",temp->age);
            printf("Doctor's Gender : %c\n",temp->gender);
            printf("Doctor's Phone Number : %lld\n",temp->phoneNumber);
            printf("Doctor's specialization : %s\n",temp->specialization);
            printf("Doctor's department : %s\n",temp->department);
            if (temp->availabilityStatus) 
                printf("Doctor is available\n");
            else
                printf("Doctor is not available\n");
            printf("Doctor's available timings : %s\n",temp->availableTimings);
            count++;
            temp = temp->link;
        }
    }
}

void patientSearch()
{
    int id,flag = 0;
    printf("Enter the patient id to search : ");
    scanf("%d",&id);
    struct Patient *temp = root;
    if(root==NULL)
        printf("No patients available\n");
    else
    {
        while(temp!=NULL)
        {
            if(id==temp->patientId)
            {
                printf("Patient is present with patient id %d\n",temp->patientId);
                flag = 1;
                break;
            }
            temp = temp->link;
        }
        if(flag==0)
            printf("Patient is not found\n");
    }
}

void doctorSearch()
{
    int id,flag = 0;
    printf("Enter the doctor id to search : ");
    scanf("%d",&id);
    struct Doctor *temp = head;
    if(head==NULL)
        printf("No doctors available\n");
    else
    {
        while(temp!=NULL)
        {
            if(id==temp->doctorId)
            {
                printf("Doctor is present with doctor id %d\n",temp->doctorId);
                flag = 1;
                break;
            }
            temp = temp->link;
        }
        if(flag==0)
            printf("Doctor is not found\n");
    }
}

void enqueueAppointment()
{
    struct Appointment *temp;
    temp = (struct Appointment *)malloc(sizeof(struct Appointment));
    printf("Enter the patient's id : ");
    scanf("%d",&temp->patientId);
    temp->link = NULL;
    if(f==NULL && r==NULL)
    {
        f = temp;
        r = temp;
    }
    else
    {
        r->link = temp;
        r = temp;
    }
    printf("Patient with Patient id %d has taken appointment\n",temp->patientId);
}

void dequeueAppointment()
{
    struct Appointment *temp = f;
    if(temp==NULL)
        printf("No patient's in the queue\n");
    else if(f==r)
    {
        struct Appointment *p = f;
        p->link = NULL;
        printf("Patient with Patient id %d has served\n",p->patientId);
        free(p);
        f = NULL;
        r = NULL;
    }
    else
    {
        struct Appointment *p = f;
        f = p->link;
        p->link = NULL;
        printf("Patient with Patient id %d has served\n",p->patientId);
        free(p);
    }
}

void displayAppointments()
{
    struct Appointment *temp = f;
    if(temp==NULL)
        printf("No waiting patient's\n");
    else
    {
        printf("Waiting patients :\n");
        while(temp!=NULL)
        {
            printf("Patient Id : %d\n",temp->patientId);
            temp = temp->link; 
        }
    }
}

int assignPriority(char symptoms[])
{
    if(strstr(symptoms, "heart") != NULL ||
       strstr(symptoms, "chest pain") != NULL ||
       strstr(symptoms, "unconscious") != NULL ||
       strstr(symptoms, "breathing") != NULL)
    {
        return 5;
    }
    else if(strstr(symptoms, "bleeding") != NULL ||
            strstr(symptoms, "stroke") != NULL ||
            strstr(symptoms, "fracture") != NULL)
    {
        return 4;
    }
    else if(strstr(symptoms, "high fever") != NULL ||
            strstr(symptoms, "severe pain") != NULL ||
            strstr(symptoms, "vomiting") != NULL)
    {
        return 3;
    }
    else if(strstr(symptoms, "fever") != NULL ||
            strstr(symptoms, "injury") != NULL)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void enqueueEmergency()
{
    int id;
    struct Patient *p = root;
    printf("Enter the patient's id : ");
    scanf("%d", &id);
    while(p != NULL && p->patientId != id)
        p = p->link;

    if(p == NULL)
    {
        printf("Patient not found\n");
        return;
    }
    struct Emergency *temp;
    temp = (struct Emergency *)malloc(sizeof(struct Emergency));
    temp->patientId = p->patientId;
    temp->priority = assignPriority(p->symptoms);
    temp->link = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    if(temp->priority > front->priority)
    {
        temp->link = front;
        front = temp;
        printf("Patient with Patient id %d has taken emergency appointment\n",temp->patientId);
        return;
    }
    struct Emergency *q = front;
    while(q->link != NULL && q->link->priority >= temp->priority)
        q = q->link;

    temp->link = q->link;
    q->link = temp;
    if(temp->link == NULL)
        rear = temp;
    printf("Patient with Patient id %d has taken emergency appointment\n",temp->patientId);
}

void dequeueEmergency()
{
    struct Emergency *temp = front;
    if(temp==NULL)
        printf("No patient's in the queue\n");
    else if(front==rear)
    {
        struct Emergency *p = front;
        p->link = NULL;
        free(p);
        printf("Patient with Patient id %d has served\n",p->patientId);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct Emergency *p = front;
        front = p->link;
        p->link = NULL;
        printf("Patient with Patient id %d has served\n",p->patientId);
        free(p);
    }
}

void displayEmergency()
{
    struct Emergency *temp = front;
    if(temp==NULL)
        printf("No waiting patient's\n");
    else
    {
        printf("Waiting patients :\n");
        while(temp!=NULL)
        {
            printf("Patient Id : %d\n",temp->patientId);
            printf("Patient priority : %d\n",temp->priority);
            temp = temp->link; 
        }
    }
}

void addPatientHistory()
{
    int id;
    struct Patient *p = root;
    printf("Enter the patient's id : ");
    scanf("%d", &id);
    getchar();
    while(p != NULL && p->patientId != id)
        p = p->link;
    if(p == NULL)
    {
        printf("Patient not found\n");
        return;
    }
    struct PatientHistory *temp;
    temp = (struct PatientHistory *)malloc(sizeof(struct PatientHistory));
    temp->patientId = p->patientId;
    printf("Enter the visit date : ");
    fgets(temp->date, 20, stdin);
    printf("Enter the doctor's id : ");
    scanf("%d", &temp->doctorId);
    getchar();
    printf("Enter the symptoms : ");
    fgets(temp->symptoms, 50, stdin);
    printf("Enter the diagnosis : ");
    fgets(temp->diagnosis, 50, stdin);
    printf("Enter the prescription : ");
    fgets(temp->prescription, 50, stdin);
    temp->link = NULL;
    if(root1 == NULL)
        root1 = temp;
    else
    {
        struct PatientHistory *q = root1;
        while(q->link != NULL)
            q = q->link;

        q->link = temp;
    }
}

void displayPatientHistory()
{
    struct PatientHistory *temp = root1;
    int id,count=1,flag=0;
    printf("Enter the patient id : ");
    scanf("%d",&id);
    while(temp!=NULL)
    {
        if(temp->patientId==id)
        {
            printf("Patient id : %d\n",temp->patientId);
            printf("visit %d\n",count);
            printf("Date : %s\n",temp->date);
            printf("Doctor id : %d\n",temp->doctorId);
            printf("Symptoms : %s\n",temp->symptoms);
            printf("Diagnosis : %s\n",temp->diagnosis);
            printf("Prescription : %s\n",temp->prescription);
            count++;
            flag = 1;
        }
        temp = temp->link;
    }
    if(flag==0)
        printf("No patient history found\n");
}

int main()
{
    int ch;
    do {
        printf("\n====== SMART HOSPITAL MANAGEMENT SYSTEM ======\n");
        printf("1. Patient Registration\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("\n4. Doctor Registration\n");
        printf("5. Display Doctors\n");
        printf("6. Search Doctor\n");
        printf("\n7. Add Normal Appointment\n");
        printf("8. Serve Normal Appointment\n");
        printf("9. Display Normal Queue\n");
        printf("\n10. Add Emergebcy Appointment\n");
        printf("11. Serve Emergency Appointment\n");
        printf("12. Display Emergency Queue\n");
        printf("\n13. Add Patient History\n");
        printf("14. Display Patient History\n");
        printf("15.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            patientRegistration();
            break;
            case 2:
            patientDisplay();
            break;
            case 3:
            patientSearch();
            break;
            case 4:
            doctorRegistration();
            break;
            case 5:
            doctorDisplay();
            break;
            case 6:
            doctorSearch();
            break;
            case 7:
            enqueueAppointment();
            break;
            case 8:
            dequeueAppointment();
            break;
            case 9:
            displayAppointments();
            break;
            case 10:
            enqueueEmergency();
            break;
            case 11:
            dequeueEmergency();
            break;
            case 12:
            displayEmergency();
            break;
            case 13:
            addPatientHistory();
            break;
            case 14:
            displayPatientHistory();
            break;
            case 15:
            return 0;
            default :
            printf("Invalid Choice\n");
        }
    }
    while(ch!=15);
    return 0;
}