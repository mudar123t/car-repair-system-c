#ifndef CAR_H
#define CAR_H


enum RepairStatus {
    PENDING,
    IN_PROGRESS,
    COMPLETED
};


struct Car {
    int CarID;
    char Model[50];
    char Manufacturer[50];
    int Year;
    char LicensePlate[20];
    int CurrentMileage;
};

struct RepairRecord {
    int RecordID;
    int CarID;
    char Date[30];
    char Technician[70];
    char Description[150];
    float Cost;
    enum RepairStatus Status;
};

struct Customer {
    int CustomerID;
    char FirstName[50];
    char LastName[50];
    char ContactNumber[15];
    char Email[50];
    char Address[150];
};



#endif
