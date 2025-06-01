#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"
#include "car_repair_library.h"


int main() {
    
    struct Car cars[100];
    int numCars = 0;

    struct RepairRecord repairRecords[100];
    int numRecords = 0;

    struct Customer customers[100];
    int numCustomers = 0;

    // addNewCar(cars, &numCars);

    // int targetID;
    // printf("Enter Car ID to search: ");
    // scanf("%d", &targetID);
    // findCarByID(cars, numCars, targetID);

    // char targetLicensePlate[20];
    // printf("Enter License Plate to search: ");
    // scanf("%s", targetLicensePlate);
    // findCarByLicensePlate(cars, numCars, targetLicensePlate);

    // int targetID;
    // printf("Enter Car ID to update: ");
    // scanf("%d", &targetID);
    // updateCarInformation(cars, numCars, targetID);

    // int targetID;
    // printf("Enter Car ID to delete: ");
    // scanf("%d", &targetID);
    // deleteCar(cars, &numCars, targetID);

    // int carID = cars[0].CarID;
    // addNewRepairRecord(repairRecords, &numRecords, carID);

    // int targetCarID;
    // printf("Enter Car ID to find repair records: ");
    // scanf("%d", &targetCarID);
    // findRepairRecordsForCar(repairRecords, numRecords, targetCarID);

    // int targetRecordID;
    // printf("Enter Repair Record ID to delete: ");
    // scanf("%d", &targetRecordID);
    // deleteRepairRecord(repairRecords, &numRecords, targetRecordID);

    // addNewCustomer(customers, &numCustomers);

    // char targetContactNumber[15];
    // printf("Enter Contact Number to search: ");
    // scanf("%s", targetContactNumber);
    // findCustomerByContactNumber(customers, numCustomers, targetContactNumber);

    // int targetID;
    // printf("Enter Customer ID to update: ");
    // scanf("%d", &targetID);
    // updateCustomerInformation(customers, numCustomers, targetID);

    // int targetID;
    // printf("Enter Customer ID to delete: ");
    // scanf("%d", &targetID);
    // deleteCustomer(customers, &numCustomers, targetID);

    // saveDataToFile(cars, numCars, repairRecords, numRecords, customers, numCustomers);

    // loadDataFromFile(cars, &numCars, repairRecords, &numRecords, customers, &numCustomers);

    return 0;
}