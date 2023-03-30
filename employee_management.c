#include <stdio.h>
#include <string.h>
const int current_year = 2022;
struct employee
{
    char name[20];
    char surname[20];
    int age;
    int date, month, year;
    int e_id;
    char dept[20];
    float sal;
    char address[30];
};
void input(struct employee[], int);                     // 1 to input all data
void display(struct employee[], int);                   // fun2 display all data in table
int search_by_id(struct employee[], int, int);          // search an employee using ID //display their data
void search_by_name(struct employee[], int);            // search employee using name //display their data
void asc_by_age(struct employee[], int);                // ascending order of age || form=table
void des_by_seniority(struct employee data[50], int s); // descending order of work experience|| form=table
void desc_by_sal(struct employee[], int);               // descending order of salary || form=table
void sort_by_dept(struct employee[], int);              // display employees in a particular department || number of employees
void update(struct employee[], int);                    // update age,salary,dept,address using their name/id
int main()
{
    struct employee data[50];
    int n, ch, e_id, index;
    char name[20];
    printf("\n------------------ EMPLOYEE MANAGEMENT --------------");
    printf("\nEnter number of employees :");
    scanf("%d", &n);
    input(data, n);
    do
    {

        printf("\n\n\n\n** MENU **\n");
        printf("\n1.Display all the data of Employees.");
        printf("\n2.Search a Record by employee ID.");
        printf("\n3.Search a Record by employee name.");
        printf("\n4.Display names by ascending order of age.");
        printf("\n5.Display names by descending order of salary.");
        printf("\n6.Display employees of a particular department");
        printf("\n7.Display Employees in descending order of Seniority");
        printf("\n8.Update Employee data");
        // printf("\n9.");
        printf("\n0.EXIT");
        printf("\nEnter Your Choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(data, n);
            break;
        case 2: // search by id
            printf("\nEnter an Employee ID to search :");
            scanf("%d", &e_id);
            index = search_by_id(data, n, e_id);
            if (index == -1)
            {
                printf("\n * RECORD NOT FOUND *");
            }
            else
            {
                printf("\n ---- Employee Data ----\n");
                printf("ID : %d\nFull Name : %s %s", data[index].e_id, data[index].name, data[index].surname);
                printf("\nAge : %d\nDepartment : %s", data[index].age, data[index].dept);
                printf("\nSalary : %0.2f\nAddress : %s\n\n\n", data[index].sal, data[index].address);
            }
            break;
        case 3: // search by name
            search_by_name(data, n);

            break;
        case 4: //
            asc_by_age(data, n);
            break;
        case 5:
            desc_by_sal(data, n);
            break;
        case 6:
            sort_by_dept(data, n);
            break;
        case 7:
            des_by_seniority(data, n);
            break;
        case 8:
            update(data, n);
            break;
        }
    } while (ch != 0);
    printf("********************\n");
    printf("**** THANK YOU *****\n");
    printf("*********************");
    return 0;
}

void input(struct employee data[50], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\n** Enter Employee Data %d **", i + 1);
        printf("\nName : ");
        scanf("%s", data[i].name);
        printf("Surname : ");
        scanf("%s", data[i].surname);
        printf("Age : ");
        scanf("%d", &data[i].age);
        printf("Date of Joining(DD-MM-YYYY) :");
        scanf("%d", &data[i].date);
        scanf("%d", &data[i].month);
        scanf("%d", &data[i].year);
        printf("Employee ID : ");
        scanf("%d", &data[i].e_id);
        printf("Department : ");
        scanf("%s", data[i].dept);
        printf("Salary : ");
        scanf("%f", &data[i].sal);
        printf("Address : ");
        scanf("%s", data[i].address);
    }
} // function to input data

void display(struct employee data[50], int s)
{
    struct employee *p;

    int i;
    printf("\n**  EMPLOYEES LIST  **\n");
    printf("|\tID\t|\t\tFull Name\t\t|\tAge\t|\tDepartment\t|\tSalary\t|\tDate of Joining\t|\tAddress\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < s; i++)
    {
        p = &data[i];
        printf("|\t%d\t|\t\t%s %s\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\t%d- %d -%d\t|\t%s\t|\n", p->e_id, p->name, p->surname, p->age, p->dept, p->sal, p->date, p->month, p->year, p->address);
    }
} // function to display all employee data in a table

int search_by_id(struct employee data[50], int s, int id)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (data[i].e_id == id)
        {
            return i;
        }
    }
    return -1;
}

void search_by_name(struct employee data[50], int s)
{
    int m, i;
    char n[20];
    printf("\nEnter employee Name to Search :");
    scanf("%s", n);
    for (i = 0; i < s; i++)
    {
        m = strcmp(n, data[i].name);
        if (m == 0)
        {
            printf("\n ---- Employee Data ----\n");
            printf("ID : %d\nFull Name : %s %s", data[i].e_id, data[i].name, data[i].surname);
            printf("\nAge : %d\nDepartment : %s", data[i].age, data[i].dept);
            printf("\nSalary : %0.2f\nAddress : %s\n\n\n", data[i].sal, data[i].address);
            break;
        }
    }
    if (i == s)
    {
        printf("\n *** RECORD NOT FOUND  ***\n");
    }
}

void asc_by_age(struct employee data[50], int s)
{
    int i, j;
    struct employee temp;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < s - 1; j++)
        {
            if (data[j].age > data[j + 1].age)
            {

                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    printf("\nLIST :\n");
    printf("|\t ID \t|\t\t Name \t\t|\t Age \t|\n");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < s; i++)
    {
        printf("|\t %d \t|\t\t %s \t\t|\t %d \t|\n", data[i].e_id, data[i].name, data[i].age);
    }
}
void des_by_seniority(struct employee data[50], int s)
{
    int years, ArrayOfYears[s];
    for (int m = 0; m < s; m++)
    {
        years = current_year - data[m].year;
        ArrayOfYears[m] = years;
    }
    int i, j, k;
    struct employee temp;
    for (i = 0; i < s - 1; i++)
    {
        k = i;
        for (j = i + 1; j < s; j++)
        {
            if (ArrayOfYears[k] < ArrayOfYears[j])
            {

                temp = data[k];
                data[k] = data[j];
                data[j] = temp;
            }
        }
    }

    printf("|\t ID \t|\t\t Name \t\t|\t Years worked in Organisation \t|\n");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < s; i++)
    {
        int y2 = current_year - data[i].year;
        printf("|\t %d \t|\t\t %s \t\t|\t %d \t|\n", data[i].e_id, data[i].name, y2);
    }
}

void desc_by_sal(struct employee data[50], int s)
{
    int i, j;
    struct employee temp;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < s - 1; j++)
        {
            if (data[j].sal < data[j + 1].sal)
            {

                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    printf("\nLIST :\n");
    printf("|\t ID \t|\t\t Name \t\t|\t Salary \t|\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < s; i++)
    {
        printf("|\t %d \t|\t\t %s \t\t|\t %.2f \t|\n", data[i].e_id, data[i].name, data[i].sal);
    }
    printf("\n\n\n");
}
void sort_by_dept(struct employee data[50], int s)
{
    int n, i, count = 0;
    char c[20];
    printf("Enter Department Name : ");
    scanf("%s", c);
    printf("\nEmployees from department '%s' :\n", c);
    printf("|\tSr.No\t|\tID\t|\tName\t|\n");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < s; i++)
    {
        n = strcmp(c, data[i].dept);

        if (n == 0)
        {
            printf("|\t%d\t|\t%d\t|\t%s\t|\n", count + 1, data[i].e_id, data[i].name);
            count++;
        }
    }
    printf("\n %d Employees are from %s department.\n\n\n", count, c);
}
void update(struct employee data[50], int n)
{
    char name[50];
    int i;
    int field, ID;
    printf("Enter Employee ID:");
    // scanf("%s", name);
    scanf("%d", &ID);
    for (i = 0; i < n; i++)
    {
        int c;
        // c = strcmp(name, data[i].name);
        if (ID == data[i].e_id)
        // if (c == 0)
        {
            printf("Enter field number that has to be updated:");
            printf("\n1. Age\n");
            printf("2. Department\n");
            printf("3. Salary\n");
            printf("4. Address\n");
            scanf("%d", &field);
            switch (field)
            {
            case 1:
                printf("Previous Age=%d\n", data[i].age);
                printf("Enter new age:");
                scanf("%d", &data[i].age);
                printf("Updated Successfully!!!\n");
                printf("Updated age: %d", data[i].age);
                break;

            case 2:
                printf("Previous Department=%s\n", data[i].dept);
                printf("Enter new department:");
                scanf("%s", data[i].dept);
                printf("Updated Successfully!!!\n");
                printf("Updated Department: %s", data[i].dept);
                break;
            case 3:
                printf("Previous Salary=%0.2f\n", data[i].sal);
                printf("Enter new Salary:");
                scanf("%f", &data[i].sal);
                printf("Updated Successfully!!!\n");
                printf("Updated Salary: %0.2f", data[i].sal);
                break;
            case 4:
                printf("Previous Address=%s\n", data[i].address);
                printf("Enter new address:");
                scanf("%s", data[i].address);
                printf("Address Updated Successfully!!!\n");
                printf("Updated address: %s", data[i].address);
                break;
            }
        }
    }
}