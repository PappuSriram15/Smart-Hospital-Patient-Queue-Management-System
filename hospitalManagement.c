#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Patient
{
    int patientId;
    char name[50];
    int age;
    char gender;
    long long int phoneNumber;
    char address[100];
    char symptoms[50];
    struct Patient *link;
};

struct Doctor
{
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

struct Appointment
{
    int patientId;
    struct Appointment *link;
};

struct Emergency
{
    int patientId;
    int priority;
    struct Emergency *link;
};

struct PatientHistory
{
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

struct Patient* findPatient(int id)
{
    struct Patient *temp = root;
    while(temp != NULL)
    {
        if(temp->patientId == id)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

struct Doctor* findDoctor(int id)
{
    struct Doctor *temp = head;
    while(temp != NULL)
    {
        if(temp->doctorId == id)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

void patientRegistration()
{
    struct Patient *temp;
    temp = (struct Patient *)malloc(sizeof(struct Patient));
    printf("Enter the patient's id : ");
    scanf("%d",&temp->patientId);
    if(findPatient(temp->patientId) != NULL)
    {
        printf("Patient ID already exists\n");
        free(temp);
        return;
    }
    getchar();
    printf("Enter the patient's name : ");
    fgets(temp->name,50,stdin);
    printf("Enter the patient's age : ");
    scanf("%d",&temp->age);
    printf("Enter the patient's gender : ");
    scanf(" %c",&temp->gender);
    printf("Enter the patient's phone number : ");
    scanf("%lld",&temp->phoneNumber);
    getchar();
    printf("Enter the patient's address : ");
    fgets(temp->address,100,stdin);
    printf("Enter the patient's symptoms : ");
    fgets(temp->symptoms,50,stdin);
    temp->link = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        struct Patient *p = root;
        while(p->link != NULL)
            p = p->link;
        p->link = temp;
    }
    printf("Patient with Patient id %d has been registered\n",temp->patientId);
}

void doctorRegistration()
{
    struct Doctor *temp;
    temp = (struct Doctor *)malloc(sizeof(struct Doctor));
    printf("Enter the doctor's id : ");
    scanf("%d",&temp->doctorId);
    if(findDoctor(temp->doctorId) != NULL)
    {
        printf("Doctor ID already exists\n");
        free(temp);
        return;
    }
    getchar();
    printf("Enter the doctor's name : ");
    fgets(temp->name,50,stdin);
    printf("Enter the doctor's age : ");
    scanf("%d",&temp->age);
    printf("Enter the doctor's gender : ");
    scanf(" %c",&temp->gender);
    printf("Enter the doctor's phone number : ");
    scanf("%lld",&temp->phoneNumber);
    getchar();
    printf("Enter the doctor's specialization : ");
    fgets(temp->specialization,50,stdin);
    printf("Enter the doctor's department : ");
    fgets(temp->department,50,stdin);
    int status;
    printf("Enter the availability of the doctor (1 - yes) (0 - no) : ");
    scanf("%d",&status);
    temp->availabilityStatus = status;
    getchar();
    printf("Enter the available timings of the doctor : ");
    fgets(temp->availableTimings,50,stdin);
    temp->link = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        struct Doctor *p = head;
        while(p->link != NULL)
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
    {
        printf("No patients registered\n");
        return;
    }
    while(temp != NULL)
    {
        printf("\nPatient %d Details :\n",count);
        printf("Patient's ID : %d\n",temp->patientId);
        printf("Patient's Name : %s",temp->name);
        printf("Patient's Age : %d\n",temp->age);
        printf("Patient's Gender : %c\n",temp->gender);
        printf("Patient's Phone Number : %lld\n",temp->phoneNumber);
        printf("Patient's Address : %s",temp->address);
        printf("Patient's Symptoms : %s",temp->symptoms);
        count++;
        temp = temp->link;
    }
}

void doctorDisplay()
{
    struct Doctor *temp = head;
    int count = 1;
    if(head == NULL)
    {
        printf("No doctors registered\n");
        return;
    }
    while(temp != NULL)
    {
        printf("\nDoctor %d Details :\n",count);
        printf("Doctor's ID : %d\n",temp->doctorId);
        printf("Doctor's Name : %s",temp->name);
        printf("Doctor's Age : %d\n",temp->age);
        printf("Doctor's Gender : %c\n",temp->gender);
        printf("Doctor's Phone Number : %lld\n",temp->phoneNumber);
        printf("Doctor's Specialization : %s",temp->specialization);
        printf("Doctor's Department : %s",temp->department);
        if(temp->availabilityStatus)
            printf("Doctor is available\n");
        else
            printf("Doctor is not available\n");
        printf("Doctor's Available Timings : %s",temp->availableTimings);
        count++;
        temp = temp->link;
    }
}

void patientSearch()
{
    int id;
    printf("Enter the patient id to search : ");
    scanf("%d",&id);
    struct Patient *temp = findPatient(id);
    if(temp == NULL)
        printf("Patient is not found\n");
    else
    {
        printf("\nPatient is present\n");
        printf("Patient ID : %d\n",temp->patientId);
        printf("Patient Name : %s",temp->name);
        printf("Patient Age : %d\n",temp->age);
        printf("Patient Gender : %c\n",temp->gender);
        printf("Patient Phone Number : %lld\n",temp->phoneNumber);
        printf("Patient Address : %s",temp->address);
        printf("Patient Symptoms : %s",temp->symptoms);
    }
}

void doctorSearch()
{
    int id;
    printf("Enter the doctor id to search : ");
    scanf("%d",&id);
    struct Doctor *temp = findDoctor(id);
    if(temp == NULL)
        printf("Doctor is not found\n");
    else
    {
        printf("\nDoctor is present\n");
        printf("Doctor ID : %d\n",temp->doctorId);
        printf("Doctor Name : %s",temp->name);
        printf("Doctor Age : %d\n",temp->age);
        printf("Doctor Gender : %c\n",temp->gender);
        printf("Doctor Phone Number : %lld\n",temp->phoneNumber);
        printf("Doctor Specialization : %s",temp->specialization);
        printf("Doctor Department : %s",temp->department);
        if(temp->availabilityStatus)
            printf("Doctor is available\n");
        else
            printf("Doctor is not available\n");
        printf("Doctor's Available Timings : %s",temp->availableTimings);
    }
}

void addPatientHistory(int id)
{
    struct Patient *p = findPatient(id);
    if(p == NULL)
    {
        printf("Patient not found\n");
        return;
    }
    struct PatientHistory *temp;
    temp = (struct PatientHistory *)malloc(sizeof(struct PatientHistory));
    temp->patientId = p->patientId;
    getchar();
    printf("Enter the visit date : ");
    fgets(temp->date,20,stdin);
    printf("Enter the doctor's id : ");
    scanf("%d",&temp->doctorId);
    struct Doctor *d = findDoctor(temp->doctorId);
    if(d == NULL)
    {
        printf("Doctor not found\n");
        free(temp);
        return;
    }
    if(!d->availabilityStatus)
    {
        printf("Doctor is not available\n");
        free(temp);
        return;
    }
    getchar();
    strcpy(temp->symptoms,p->symptoms);
    printf("Enter the diagnosis : ");
    fgets(temp->diagnosis,50,stdin);
    printf("Enter the prescription : ");
    fgets(temp->prescription,50,stdin);
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
    printf("Patient history added successfully\n");
}

void enqueueAppointment()
{
    int id;
    printf("Enter the patient's id : ");
    scanf("%d",&id);
    struct Patient *p = findPatient(id);
    if(p == NULL)
    {
        printf("Patient not found\n");
        return;
    }
    struct Appointment *temp;
    temp = (struct Appointment *)malloc(sizeof(struct Appointment));
    temp->patientId = p->patientId;
    temp->link = NULL;
    if(f == NULL && r == NULL)
    {
        f = temp;
        r = temp;
    }
    else
    {
        r->link = temp;
        r = temp;
    }
    printf("Patient with Patient id %d has taken appointment\n",id);
}

void dequeueAppointment()
{
    if(f == NULL)
    {
        printf("No patient's in the queue\n");
        return;
    }
    int id = f->patientId;
    struct Appointment *p = f;
    if(f == r)
    {
        f = NULL;
        r = NULL;
    }
    else
    {
        f = f->link;
    }
    free(p);
    printf("Patient with Patient id %d has served\n",id);
    addPatientHistory(id);
}

void displayAppointments()
{
    struct Appointment *temp = f;
    if(temp == NULL)
    {
        printf("No waiting patients\n");
        return;
    }
    printf("Waiting patients :\n");
    while(temp != NULL)
    {
        printf("Patient ID : %d\n",temp->patientId);
        temp = temp->link;
    }
}

int predictPriority(struct Patient *p)
{
    int chestPain = strstr(p->symptoms, "chest pain") != NULL;
    int breathingProblem = strstr(p->symptoms, "breathing") != NULL;
    int bleeding = strstr(p->symptoms, "bleeding") != NULL;
    int fever = strstr(p->symptoms, "fever") != NULL;
    int highFever = strstr(p->symptoms, "high fever") != NULL;
    int severePain = strstr(p->symptoms, "severe pain") != NULL;

    char command[500];
    sprintf(command,
        "python AI\\predict.py %d %d %d %d %d %d %d",
        chestPain, breathingProblem, bleeding, fever, highFever, severePain, p->age);

    FILE *pipe = _popen(command, "r");
    if(pipe == NULL)
    {
        printf("AI prediction failed to start\n");
        return 1;
    }

    int priority;
    if(fscanf(pipe, "%d", &priority) != 1)
    {
        printf("Could not read AI priority\n");
        _pclose(pipe);
        return 1;
    }
    _pclose(pipe);
    return priority;
}

void enqueueEmergency()
{
    int id;
    printf("Enter the patient's id : ");
    scanf("%d",&id);
    struct Patient *p = findPatient(id);
    if(p == NULL)
    {
        printf("Patient not found\n");
        return;
    }
    struct Emergency *temp;
    temp = (struct Emergency *)malloc(sizeof(struct Emergency));
    temp->patientId = p->patientId;
    temp->priority = predictPriority(p);
    temp->link = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        printf("Patient with Patient id %d has taken emergency appointment\n",id);
        printf("Priority : %d\n",temp->priority);
        return;
    }
    if(temp->priority > front->priority)
    {
        temp->link = front;
        front = temp;
        printf("Patient with Patient id %d has taken emergency appointment\n",id);
        printf("Priority : %d\n",temp->priority);
        return;
    }
    struct Emergency *q = front;
    while(q->link != NULL && q->link->priority >= temp->priority)
        q = q->link;
    temp->link = q->link;
    q->link = temp;
    if(temp->link == NULL)
        rear = temp;
    printf("Patient with Patient id %d has taken emergency appointment\n",id);
    printf("Priority : %d\n",temp->priority);
}

void dequeueEmergency()
{
    if(front == NULL)
    {
        printf("No patient's in the queue\n");
        return;
    }
    int id = front->patientId;
    struct Emergency *p = front;
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
        front = front->link;
    free(p);
    printf("Patient with Patient id %d has served\n",id);
    addPatientHistory(id);
}

void displayEmergency()
{
    struct Emergency *temp = front;
    if(temp == NULL)
    {
        printf("No waiting patients\n");
        return;
    }
    printf("Waiting patients :\n");
    while(temp != NULL)
    {
        printf("Patient ID : %d\n",temp->patientId);
        printf("Patient Priority : %d\n",temp->priority);
        temp = temp->link;
    }
}

void displayPatientHistory()
{
    struct PatientHistory *temp = root1;
    int id;
    int count = 1;
    int flag = 0;
    printf("Enter the patient id : ");
    scanf("%d",&id);
    while(temp != NULL)
    {
        if(temp->patientId == id)
        {
            printf("\nPatient ID : %d\n",temp->patientId);
            printf("Visit %d\n",count);
            printf("Date : %s",temp->date);
            printf("Doctor ID : %d\n",temp->doctorId);
            printf("Symptoms : %s",temp->symptoms);
            printf("Diagnosis : %s",temp->diagnosis);
            printf("Prescription : %s",temp->prescription);
            count++;
            flag = 1;
        }
        temp = temp->link;
    }
    if(flag == 0)
        printf("No patient history found\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n====== SMART HOSPITAL MANAGEMENT SYSTEM ======\n");
        printf("1. Patient Registration\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Doctor Registration\n");
        printf("5. Display Doctors\n");
        printf("6. Search Doctor\n");
        printf("7. Add Normal Appointment\n");
        printf("8. Serve Normal Appointment\n");
        printf("9. Display Normal Queue\n");
        printf("10. Add Emergency Appointment\n");
        printf("11. Serve Emergency Appointment\n");
        printf("12. Display Emergency Queue\n");
        printf("13. Display Patient History\n");
        printf("14. Exit\n");
        printf("\nEnter the choice : ");
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
                displayPatientHistory();
                break;
            case 14:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    } while(ch != 14);
    return 0;
}