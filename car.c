#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"
#include "car_repair_library.h"
#define CarNumber(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MAX_CARS 100
#define MAX_REPAIR_RECORDS 100
#define MAX_CUSTOMERS 100

// car funcs
void addNewCar(struct Car *cars, int *numCars)
{
    if (*numCars >= 100)
    {
        printf("Error: Maximum number of cars reached.\n");
        return;
    }

    printf("Enter Car Details:\n");

    int index = (*numCars)++;

    cars[index].CarID = index + 1;
    printf("Car Model: ");
    scanf("%[\n]s", cars[index].Model);

    printf("Manufacturer: ");
    scanf("%s", cars[index].Manufacturer);

    printf("Year: ");
    scanf("%d", &cars[index].Year);

    printf("License Plate: ");
    scanf("%s", cars[index].LicensePlate);

    printf("Current Mileage: ");
    scanf("%d", &cars[index].CurrentMileage);

    printf("Car added successfully!\n");
}

void findCarByID(struct Car *cars, int numCars, int targetID)
{
    for (int i = 0; i < numCars; ++i)
    {
        if (cars[i].CarID == targetID)
        {
            printf("Car found!\n");
            printf("CarID: %d\n", cars[i].CarID);
            printf("Model: %s\n", cars[i].Model);
            printf("Manufacturer: %s\n", cars[i].Manufacturer);
            printf("Year: %d\n", cars[i].Year);
            printf("License Plate: %s\n", cars[i].LicensePlate);
            printf("Current Mileage: %d\n", cars[i].CurrentMileage);
            return;
        }
    }

    printf("Car with ID %d not found.\n", targetID);
}

void findCarByLicensePlate(struct Car *cars, int numCars, const char *targetLicensePlate)
{
    for (int i = 0; i < numCars; ++i)
    {
        if (strcmp(cars[i].LicensePlate, targetLicensePlate) == 0)
        {
            printf("Car found!\n");
            printf("CarID: %d\n", cars[i].CarID);
            printf("Model: %s\n", cars[i].Model);
            printf("Manufacturer: %s\n", cars[i].Manufacturer);
            printf("Year: %d\n", cars[i].Year);
            printf("License Plate: %s\n", cars[i].LicensePlate);
            printf("Current Mileage: %d\n", cars[i].CurrentMileage);
            return;
        }
    }

    printf("Car with License Plate %s not found.\n", targetLicensePlate);
}

void updateCarInformation(struct Car *cars, int numCars, int targetID)
{
    for (int i = 0; i < numCars; ++i)
    {
        if (cars[i].CarID == targetID)
        {
            printf("Enter updated information for Car ID %d:\n", targetID);

            printf("Car Model: ");
            scanf("%s", cars[i].Model);

            printf("Manufacturer: ");
            scanf("%s", cars[i].Manufacturer);

            printf("Year: ");
            scanf("%d", &cars[i].Year);

            printf("License Plate: ");
            scanf("%s", cars[i].LicensePlate);

            printf("Current Mileage: ");
            scanf("%d", &cars[i].CurrentMileage);

            printf("Car information updated successfully!\n");
            return;
        }
    }

    printf("Car with ID %d not found.\n", targetID);
}

void deleteCar(struct Car *cars, int *numCars, int targetID)
{
    for (int i = 0; i < *numCars; ++i)
    {
        if (cars[i].CarID == targetID)
        {

            cars[i] = cars[*numCars - 1];

            (*numCars)--;

            printf("Car with ID %d deleted successfully!\n", targetID);
            return;
        }
    }

    printf("Car with ID %d not found.\n", targetID);
}

// repair record funcs

void addNewRepairRecord(struct RepairRecord *repairRecords, int *numRecords, int carID)
{
    if (*numRecords >= 100)
    {
        printf("Error: Maximum number of repair records reached.\n");
        return;
    }

    printf("Enter Repair Record Details:\n");

    int index = (*numRecords)++;

    repairRecords[index].RecordID = index + 1;
    repairRecords[index].CarID = carID;

    printf("Date: ");
    scanf("%s", repairRecords[index].Date);

    printf("Technician: ");
    scanf("%s", repairRecords[index].Technician);

    printf("Description: ");
    scanf("%s", repairRecords[index].Description);

    printf("Cost: ");
    scanf("%f", &repairRecords[index].Cost);

    printf("Choose Repair Status (0: PENDING, 1: IN_PROGRESS, 2: COMPLETED): ");
    int statusChoice;
    scanf("%d", &statusChoice);

    if (statusChoice >= 0 && statusChoice <= 2)
    {
        repairRecords[index].Status = (enum RepairStatus)statusChoice;
        printf("Repair Record added successfully!\n");
    }
    else
    {
        printf("Invalid status choice. Repair Record not added.\n");
        // Decrement numRecords if the status choice is invalid
        (*numRecords)--;
    }
}

void findRepairRecordsForCar(struct RepairRecord *repairRecords, int numRecords, int targetCarID)
{
    printf("Repair Records for Car ID %d:\n", targetCarID);
    printf("%-15s %-15s %-15s %-20s %-10s %-15s\n", "Record ID", "Date", "Technician", "Description", "Cost", "Status");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < numRecords; ++i)
    {
        if (repairRecords[i].CarID == targetCarID)
        {
            printf("%-15d %-15s %-15s %-20s %-10.2f %-15s\n", repairRecords[i].RecordID,
                   repairRecords[i].Date, repairRecords[i].Technician,
                   repairRecords[i].Description, repairRecords[i].Cost,
                   repairRecords[i].Status == PENDING ? "PENDING" : (repairRecords[i].Status == IN_PROGRESS ? "IN_PROGRESS" : "COMPLETED"));
        }
    }

    printf("----------------------------------------------------------------\n");
}

void deleteRepairRecord(struct RepairRecord *repairRecords, int *numRecords, int targetRecordID)
{
    for (int i = 0; i < *numRecords; ++i)
    {
        if (repairRecords[i].RecordID == targetRecordID)
        {
            // Move the last repair record to the position of the deleted record
            repairRecords[i] = repairRecords[*numRecords - 1];

            // Decrement the number of repair records
            (*numRecords)--;

            printf("Repair Record with ID %d deleted successfully!\n", targetRecordID);
            return; // Exit the function after deleting the repair record
        }
    }

    printf("Repair Record with ID %d not found.\n", targetRecordID);
}

// costumer funcs

void addNewCustomer(struct Customer *customers, int *numCustomers)
{
    if (*numCustomers >= 100)
    {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }

    printf("Enter Customer Details:\n");

    // Increment numCustomers and use it as the index for the new customer
    int index = (*numCustomers)++;

    customers[index].CustomerID = index + 1; // Auto-incrementing CustomerID for simplicity

    printf("First Name: ");
    scanf("%s", customers[index].FirstName);

    printf("Last Name: ");
    scanf("%s", customers[index].LastName);

    printf("Contact Number: ");
    scanf("%s", customers[index].ContactNumber);

    printf("Email: ");
    scanf("%s", customers[index].Email);

    printf("Address: ");
    scanf("%s", customers[index].Address);

    printf("Customer added successfully!\n");
}

void findCustomerByContactNumber(struct Customer *customers, int numCustomers, const char *targetContactNumber)
{
    for (int i = 0; i < numCustomers; ++i)
    {
        if (strcmp(customers[i].ContactNumber, targetContactNumber) == 0)
        {
            printf("Customer found!\n");
            printf("Customer ID: %d\n", customers[i].CustomerID);
            printf("First Name: %s\n", customers[i].FirstName);
            printf("Last Name: %s\n", customers[i].LastName);
            printf("Contact Number: %s\n", customers[i].ContactNumber);
            printf("Email: %s\n", customers[i].Email);
            printf("Address: %s\n", customers[i].Address);
            return; // Exit the function if the customer is found
        }
    }

    printf("Customer with contact number %s not found.\n", targetContactNumber);
}

void updateCustomerInformation(struct Customer *customers, int numCustomers, int targetID)
{
    for (int i = 0; i < numCustomers; ++i)
    {
        if (customers[i].CustomerID == targetID)
        {
            printf("Enter updated information for Customer ID %d:\n", targetID);

            printf("First Name: ");
            scanf("%s", customers[i].FirstName);

            printf("Last Name: ");
            scanf("%s", customers[i].LastName);

            printf("Contact Number: ");
            scanf("%s", customers[i].ContactNumber);

            printf("Email: ");
            scanf("%s", customers[i].Email);

            printf("Address: ");
            scanf("%s", customers[i].Address);

            printf("Customer information updated successfully!\n");
            return; // Exit the function after updating the information
        }
    }

    printf("Customer with ID %d not found.\n", targetID);
}

void deleteCustomer(struct Customer *customers, int *numCustomers, int targetID)
{
    for (int i = 0; i < *numCustomers; ++i)
    {
        if (customers[i].CustomerID == targetID)
        {
            // Move the last customer to the position of the deleted customer
            customers[i] = customers[*numCustomers - 1];

            // Decrement the number of customers
            (*numCustomers)--;

            printf("Customer with ID %d deleted successfully!\n", targetID);
            return; // Exit the function after deleting the customer
        }
    }

    printf("Customer with ID %d not found.\n", targetID);
}

// file handling
void saveDataToFile(const struct Car *cars, int numCars, const struct RepairRecord *repairRecords, int numRecords, const struct Customer *customers, int numCustomers)
{
    // Save Cars
    FILE *carFile = fopen("cars.txt", "w");
    if (carFile == NULL)
    {
        printf("Error opening file for writing: cars.txt\n");
        return;
    }

    for (int i = 0; i < numCars; ++i)
    {
        fprintf(carFile, "%d %s %s %d %s %d\n",
                cars[i].CarID, cars[i].Model, cars[i].Manufacturer,
                cars[i].Year, cars[i].LicensePlate, cars[i].CurrentMileage);
    }

    fclose(carFile);

    // Save Repair Records
    FILE *repairFile = fopen("repair_records.txt", "w");
    if (repairFile == NULL)
    {
        printf("Error opening file for writing: repair_records.txt\n");
        return;
    }

    for (int i = 0; i < numRecords; ++i)
    {
        fprintf(repairFile, "%d %d %s %s %s %.2f %d\n",
                repairRecords[i].RecordID, repairRecords[i].CarID,
                repairRecords[i].Date, repairRecords[i].Technician,
                repairRecords[i].Description, repairRecords[i].Cost,
                repairRecords[i].Status);
    }

    fclose(repairFile);

    // Save Customers
    FILE *customerFile = fopen("customers.txt", "w");
    if (customerFile == NULL)
    {
        printf("Error opening file for writing: customers.txt\n");
        return;
    }

    for (int i = 0; i < numCustomers; ++i)
    {
        fprintf(customerFile, "%d %s %s %s %s %s\n",
                customers[i].CustomerID, customers[i].FirstName, customers[i].LastName,
                customers[i].ContactNumber, customers[i].Email, customers[i].Address);
    }

    fclose(customerFile);
}
void loadDataFromFile(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers)
{
    // Load Cars
    FILE *carFile = fopen("cars.txt", "r");
    if (carFile == NULL)
    {
        printf("Error opening file for reading: cars.txt\n");
        perror("fopen");
        return;
    }

    *numCars = 0; // Reset the number of cars
    while (fscanf(carFile, "%d %49s %49s %d %19s %d",
                  &cars[*numCars].CarID, cars[*numCars].Model, cars[*numCars].Manufacturer,
                  &cars[*numCars].Year, cars[*numCars].LicensePlate, &cars[*numCars].CurrentMileage) == 6)
    {
        printf("Loaded Car: ID=%d, Model=%s, Manufacturer=%s, Year=%d, License Plate=%s, Mileage=%d\n",
               cars[*numCars].CarID, cars[*numCars].Model, cars[*numCars].Manufacturer,
               cars[*numCars].Year, cars[*numCars].LicensePlate, cars[*numCars].CurrentMileage);
        (*numCars)++;
    }

    fclose(carFile);

    // Load Repair Records
    FILE *repairFile = fopen("repair_records.txt", "r");
    if (repairFile == NULL)
    {
        printf("Error opening file for reading: repair_records.txt\n");
        perror("fopen");
        return;
    }

    *numRecords = 0; // Reset the number of repair records
    while (fscanf(repairFile, "%d %d %19s %49s %99s %f %d",
                  &repairRecords[*numRecords].RecordID, &repairRecords[*numRecords].CarID,
                  repairRecords[*numRecords].Date, repairRecords[*numRecords].Technician,
                  repairRecords[*numRecords].Description, &repairRecords[*numRecords].Cost,
                  (int *)&repairRecords[*numRecords].Status) == 7)
    {
        printf("Loaded Repair Record: ID=%d, Car ID=%d, Date=%s, Technician=%s, Description=%s, Cost=%.2f, Status=%d\n",
               repairRecords[*numRecords].RecordID, repairRecords[*numRecords].CarID,
               repairRecords[*numRecords].Date, repairRecords[*numRecords].Technician,
               repairRecords[*numRecords].Description, repairRecords[*numRecords].Cost,
               repairRecords[*numRecords].Status);
        (*numRecords)++;
    }

    fclose(repairFile);

    // Load Customers
    FILE *customerFile = fopen("customers.txt", "r");
    if (customerFile == NULL)
    {
        printf("Error opening file for reading: customers.txt\n");
        perror("fopen");
        return;
    }

    *numCustomers = 0; // Reset the number of customers
    while (fscanf(customerFile, "%d %49s %49s %14s %49s %99s",
                  &customers[*numCustomers].CustomerID, customers[*numCustomers].FirstName, customers[*numCustomers].LastName,
                  customers[*numCustomers].ContactNumber, customers[*numCustomers].Email, customers[*numCustomers].Address) == 6)
    {
        printf("Loaded Customer: ID=%d, First Name=%s, Last Name=%s, Contact Number=%s, Email=%s, Address=%s\n",
               customers[*numCustomers].CustomerID, customers[*numCustomers].FirstName, customers[*numCustomers].LastName,
               customers[*numCustomers].ContactNumber, customers[*numCustomers].Email, customers[*numCustomers].Address);
        (*numCustomers)++;
    }

    fclose(customerFile);
}

// interface
void displayMenu(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers)
{
    int choice;

    do
    {
        printf("\n==== Main Menu ====\n");
        printf("1. Car Operations\n");
        printf("2. Repair Record Operations\n");
        printf("3. Customer Operations\n");
        printf("4. Save and Load Data to/from Files\n");
        printf("5. Calculations\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            carOperations(cars, numCars, repairRecords, numRecords, customers, numCustomers);
            break;
        case 2:
            repairRecordOperations(cars, *numCars, repairRecords, numRecords, customers, *numCustomers);
            break;
        case 3:
            customerOperations(cars, *numCars, repairRecords, *numRecords, customers, numCustomers);
            break;
        case 4:
            fileOperations(cars, *numCars, repairRecords, *numRecords, customers, *numCustomers);
            break;
        case 5:
        {   int subChoice;
            do{
            
            printf("\n==== Calculations ====\n");
            printf("1. Calculate Average Repair Cost\n");
            printf("2. Display Total Cost for Repairs with a Specific Status\n");
            printf("3. see total number of cars\n");
            printf("4. Back to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &subChoice);

            switch (subChoice)
            {
            case 1:
            {
                AverageRepairCostFunction averageRepairCostFunction = calculateAverageRepairCost;
                float averageCost = averageRepairCostFunction(repairRecords, *numRecords);
                printf("Average Repair Cost: %.2f\n", averageCost);
                break;
            }
            case 2:
            {
                displayTotalCostForStatus(repairRecords, *numRecords, COMPLETED);
                break;
            }
            case 3:
            {
                int size = CarNumber(cars);
                printf("Number of Cars: %d\n", size);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
            }
            }
            while (subChoice != 4);
            break;
        }
        case 6:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (choice != 6);
}
void carOperations(struct Car *cars, int *numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int *numCustomers)
{
    int carChoice;

    do
    {
        printf("\n==== Car Operations ====\n");
        printf("1. Add a new car\n");
        printf("2. Find a car by ID\n");
        printf("3. Find a car by License Plate\n");
        printf("4. Update car information\n");
        printf("5. Delete a car\n");
        printf("6. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &carChoice);

        switch (carChoice)
        {
        case 1:
            addNewCar(cars, numCars);
            break;
        case 2:
        {
            int targetID;
            printf("Enter Car ID to search: ");
            scanf("%d", &targetID);
            findCarByID(cars, *numCars, targetID);
            break;
        }
        case 3:
        {
            char targetLicensePlate[20];
            printf("Enter License Plate to search: ");
            scanf("%s", targetLicensePlate);
            findCarByLicensePlate(cars, *numCars, targetLicensePlate);
            break;
        }
        case 4:
        {
            int targetID;
            printf("Enter Car ID to update: ");
            scanf("%d", &targetID);
            updateCarInformation(cars, *numCars, targetID);
            break;
        }
        case 5:
        {
            int targetID;
            printf("Enter Car ID to delete: ");
            scanf("%d", &targetID);
            deleteCar(cars, numCars, targetID);
            break;
        }
        case 6:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (carChoice != 6);
}

void repairRecordOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int *numRecords, struct Customer *customers, int numCustomers)
{
    int repairRecordChoice;

    do
    {
        printf("\n==== Repair Record Operations ====\n");
        printf("1. Add a new repair record\n");
        printf("2. Find repair records for a car\n");
        printf("3. Delete a repair record\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &repairRecordChoice);

        switch (repairRecordChoice)
        {
        case 1:
        {
            int carID;
            printf("Enter Car ID for the repair record: ");
            scanf("%d", &carID);
            addNewRepairRecord(repairRecords, numRecords, carID);
            break;
        }
        case 2:
        {
            int targetCarID;
            printf("Enter Car ID to find repair records: ");
            scanf("%d", &targetCarID);
            findRepairRecordsForCar(repairRecords, *numRecords, targetCarID);
            break;
        }
        case 3:
        {
            int targetRecordID;
            printf("Enter Repair Record ID to delete: ");
            scanf("%d", &targetRecordID);
            deleteRepairRecord(repairRecords, numRecords, targetRecordID);
            break;
        }
        case 4:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (repairRecordChoice != 4);
}

void customerOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int numRecords, struct Customer *customers, int *numCustomers)
{
    int customerChoice;

    do
    {
        printf("\n==== Customer Operations ====\n");
        printf("1. Add a new customer\n");
        printf("2. Find a customer by contact number\n");
        printf("3. Update customer information\n");
        printf("4. Delete a customer\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &customerChoice);

        switch (customerChoice)
        {
        case 1:
            addNewCustomer(customers, numCustomers);
            break;
        case 2:
        {
            char targetContactNumber[15];
            printf("Enter Contact Number to search: ");
            scanf("%s", targetContactNumber);
            findCustomerByContactNumber(customers, *numCustomers, targetContactNumber);
            break;
        }
        case 3:
        {
            int targetID;
            printf("Enter Customer ID to update: ");
            scanf("%d", &targetID);
            updateCustomerInformation(customers, *numCustomers, targetID);
            break;
        }
        case 4:
        {
            int targetID;
            printf("Enter Customer ID to delete: ");
            scanf("%d", &targetID);
            deleteCustomer(customers, numCustomers, targetID);
            break;
        }
        case 5:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (customerChoice != 5);
}

void fileOperations(struct Car *cars, int numCars, struct RepairRecord *repairRecords, int numRecords, struct Customer *customers, int numCustomers)
{
    int fileChoice;

    do
    {
        printf("\n==== File Operations ====\n");
        printf("1. Save Data to Files\n");
        printf("2. Load Data from Files\n");
        printf("3. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &fileChoice);

        switch (fileChoice)
        {
        case 1:
            saveDataToFile(cars, numCars, repairRecords, numRecords, customers, numCustomers);
            break;
        case 2:
            loadDataFromFile(cars, &numCars, repairRecords, &numRecords, customers, &numCustomers);
            break;
        case 3:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (fileChoice != 3);
}

void displayTotalCostForStatus(const struct RepairRecord *repairRecords, int numRecords, enum RepairStatus status)
{
    float totalCost = 0.0;

    for (int i = 0; i < numRecords; ++i)
    {
        if (repairRecords[i].Status == status)
        {
            totalCost += repairRecords[i].Cost;
        }
    }

    printf("Total Cost of Completed Repair Records: %.2f\n", totalCost);
}

// Function to calculate the average cost for all repairs
float calculateAverageRepairCost(const struct RepairRecord *repairRecords, int numRecords) {
    // Check if there are no repair records
    if (numRecords == 0) {
        printf("No repair records available.\n");
        return 0.0;  // Returning 0.0 for no repair records; you can choose a different approach based on your needs
    }

    // Calculate the total repair cost
    float totalCost = 0.0;
    for (int i = 0; i < numRecords; ++i) {
        totalCost += repairRecords[i].Cost;
    }

    // Calculate the average repair cost
    float averageCost = totalCost / numRecords;

    return averageCost;
}

