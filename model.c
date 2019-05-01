//
// Created by Xufeng Weng on 2019-04-20.
//


#include "model.h"
#include <stdio.h>
#include <string.h>

Employee employees[DB_CAPACITY];
int number_of_records = 0;

//Print the Database
void print_db() {
    int i;
    printf("NAME                              SALARY             ID\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0;i < number_of_records; ++i) {
        printf("%-14s", employees[i].first_name);
        printf("%-19s", employees[i].last_name);
        printf("%7d", employees[i].salary);
        printf("%15d\n", employees[i].six_digit_ID);
    }
    printf("---------------------------------------------------------------\n");
    printf(" Number of Employees (%d)\n", number_of_records);
}

//Lookup employee by ID
void lookup_by_id(int id) {
    int low = 0, high = number_of_records;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (employees[mid].six_digit_ID > id) {
            high = mid;
        } else if (employees[mid].six_digit_ID < id) {
            low = mid + 1;
        } else {
            printf("NAME                              SALARY             ID\n");
            printf("---------------------------------------------------------------\n");
            printf("%-14s", employees[mid].first_name);
            printf("%-19s", employees[mid].last_name);
            printf("%7d", employees[mid].salary);
            printf("%15d\n", employees[mid].six_digit_ID);
            printf("---------------------------------------------------------------\n");
            break;
        }
    }

    if (low >= high) {
        printf("Employee with id %d not found in DB\n", id);
    }
}

int get_offset_by_id(int id) {
    int low = 0, high = number_of_records;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (employees[mid].six_digit_ID > id) {
            high = mid;
        } else if (employees[mid].six_digit_ID < id) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//Lookup employee by last name
void lookup_by_last_name(const char* last_name) {
    int found = 0;
    int i;
    for (i = 0;i < number_of_records; ++i) {
        if (strcmp(last_name, employees[i].last_name) == 0) {
            printf("NAME                              SALARY             ID\n");
            printf("---------------------------------------------------------------\n");
            printf("%-14s", employees[i].first_name);
            printf("%-19s", employees[i].last_name);
            printf("%7d", employees[i].salary);
            printf("%15d\n", employees[i].six_digit_ID);
            printf("---------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with last name %s not found in DB\n", last_name);
    }
}

void match_last_name(const char* last_name) {
    int found = 0;
    int i;
    printf("NAME                              SALARY             ID\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0;i < number_of_records; ++i) {
        if (strcmp(last_name, employees[i].last_name) == 0) {
            printf("%-14s", employees[i].first_name);
            printf("%-19s", employees[i].last_name);
            printf("%7d", employees[i].salary);
            printf("%15d\n", employees[i].six_digit_ID);
            found = 1;
        }
    }
    printf("---------------------------------------------------------------\n");
    if (!found) {
        printf("Employee with last name %s not found in DB\n", last_name);
    }
}

//Add an Employee
void auto_add_empty(int six_digit_ID, const char* first_name,
               const char* last_name, int salary) {
    int i;
    if (number_of_records < DB_CAPACITY) {
        for (i = number_of_records - 1;i >= 0; --i) {
            if (employees[i].six_digit_ID > six_digit_ID) {
                employees[i + 1] = employees[i];
            } else {
                employees[i + 1].six_digit_ID = six_digit_ID;
                strcpy(employees[i + 1].first_name, first_name);
                strcpy(employees[i + 1].last_name, last_name);
                employees[i + 1].salary = salary;
                break;
            }
        }
        if (i == -1) {
            employees[0].six_digit_ID = six_digit_ID;
            strcpy(employees[0].first_name, first_name);
            strcpy(employees[0].last_name, last_name);
            employees[0].salary = salary;
        }
        ++number_of_records;
    }
}

//Add an Employee
void add_empty(const char* first_name,
                    const char* last_name, int salary) {
    int six_digit_ID = 0;
    int i;
    for (i = 0;i < number_of_records; ++i) {
        if (employees[i].six_digit_ID > six_digit_ID) {
            six_digit_ID = employees[i].six_digit_ID;
        }
    }
    six_digit_ID += 1;
    if (number_of_records < DB_CAPACITY) {
        employees[number_of_records].six_digit_ID = six_digit_ID;
        strcpy(employees[number_of_records].first_name, first_name);
        strcpy(employees[number_of_records].last_name, last_name);
        employees[number_of_records].salary = salary;
        ++number_of_records;
    }
}

//remove employee
void remove_employee(int position) {
    int i;
    for (i = position + 1;i < number_of_records; ++i) {
        employees[i - 1] = employees[i];
    }
    --number_of_records;
}

void topk_salary(int k) {
    if (k <= 0) {
        return ;
    }
    Employee tmp_employees[DB_CAPACITY];
    int i, j;
    Employee tmp;
    for (i = 0;i < number_of_records; ++i) {
        tmp_employees[i] = employees[i];
    }
    for (i = 1;i < number_of_records; ++i) {
        tmp = tmp_employees[i];
        for (j = i - 1;j >= 0 && tmp_employees[j].salary < tmp.salary; --j) {
            tmp_employees[j + 1] = tmp_employees[j];
        }
        tmp_employees[j + 1] = tmp;
    }
    printf("%d employees with the highest salaries:\n", k);
    printf("NAME                              SALARY             ID\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0;i < k; ++i) {
        printf("%-14s", tmp_employees[i].first_name);
        printf("%-19s", tmp_employees[i].last_name);
        printf("%7d", tmp_employees[i].salary);
        printf("%15d\n", tmp_employees[i].six_digit_ID);
    }
    printf("---------------------------------------------------------------\n");
}
