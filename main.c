#include <stdio.h>
#include "car.h"
#include "car_repair_library.h"
#define MAX_CARS 100
#define MAX_REPAIR_RECORDS 100
#define MAX_CUSTOMERS 100

int main()
{
    // Initialize arrays to store data
    struct Car cars[MAX_CARS];
    struct RepairRecord repairRecords[MAX_REPAIR_RECORDS];
    struct Customer customers[MAX_CUSTOMERS];
    int numCars = 0, numRecords = 0, numCustomers = 0;

    // Load existing data from files (if any)
    // loadDataFromFile(cars, &numCars, repairRecords, &numRecords, customers, &numCustomers);


    displayMenu(cars, &numCars, repairRecords, &numRecords, customers, &numCustomers);

    return 0;
}