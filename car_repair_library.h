
#ifndef CAR_REPAIR_LIBRARY_H
#define CAR_REPAIR_LIBRARY_H

#include "car.h"

//car
void addNewCar(struct Car *cars, int *numCars);
void findCarByID(struct Car *cars, int numCars, int targetID);
void findCarByLicensePlate(struct Car *cars, int numCars, const char *targetLicensePlate);
void updateCarInformation(struct Car *cars, int numCars, int targetID);
void deleteCar(struct Car *cars, int *numCars, int targetID);

//repair record
void addNewRepairRecord(struct RepairRecord *repairRecords, int *numRecords, int carID);
void findRepairRecordsForCar(struct RepairRecord *repairRecords, int numRecords, int targetCarID);
void deleteRepairRecord(struct RepairRecord *repairRecords, int *numRecords, int targetRecordID);

//customer
void addNewCustomer(struct Customer *customers, int *numCustomers);
void findCustomerByContactNumber(struct Customer *customers, int numCustomers, const char *targetContactNumber);
void updateCustomerInformation(struct Customer *customers, int numCustomers, int targetID);
void deleteCustomer(struct Customer *customers, int *numCustomers, int targetID);

//file handeling
void saveDataToFile(const struct Car *cars, int numCars, const struct RepairRecord *repairRecords, int numRecords, const struct Customer *customers, int numCustomers);
void loadDataFromFile(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers);
//interface
void displayMenu(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers);
void carOperations(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers);
void repairRecordOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int numCustomers);
void customerOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int numRecords, struct Customer *customers, int *numCustomers);
void fileOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int numRecords, struct Customer *customers, int numCustomers);


void displayTotalCostForStatus(const struct RepairRecord *repairRecords, int numRecords, enum RepairStatus status);
float calculateAverageRepairCost(const struct RepairRecord *repairRecords, int numRecords);

// Define a function pointer type for the calculateAverageRepairCost function
typedef float (*AverageRepairCostFunction)(const struct RepairRecord *, int);



#endif
