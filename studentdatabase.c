#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[50];
    int id;
    float grades[5];
    Date enrollment_date;
} Student;

void save_records(Student students[], int count)
{
    FILE *filePtr;
    if((filePtr = fopen("students.txt", "w")) == NULL)
    {
        perror("File couldn't open.");
        exit(EXIT_FAILURE);
    }

    fprintf(filePtr, "%d\n", count);
    for(int i = 0; i < count; i++)
    {
        fprintf(filePtr, "%s,%d,%.2f,%.2f,%.2f,%.2f,%.2f,%d,%d,%d\n",
                students[i].name,
                students[i].id,
                students[i].grades[0], students[i].grades[1], students[i].grades[2],
                students[i].grades[3], students[i].grades[4],
                students[i].enrollment_date.day,
                students[i].enrollment_date.month,
                students[i].enrollment_date.year);
    }
    fclose(filePtr);
}

void load_records(Student students[])
{
    char buffer[1000];
    FILE *filePtr;
    int count;
    if((filePtr = fopen("students.txt", "r")) == NULL)
    {
        perror("File couldn't open.");
        exit(EXIT_FAILURE);
    }

    fscanf(filePtr, "%d", &count);

    for(int i = 0; i < count; i++)
    {
        fscanf(filePtr, "%49[^,],%d,%f,%f,%f,%f,%f,%d,%d,%d",
               students[i].name,
               &students[i].id,
               &students[i].grades[0], &students[i].grades[1], &students[i].grades[2],
               &students[i].grades[3], &students[i].grades[4],
               &students[i].enrollment_date.day,
               &students[i].enrollment_date.month,
               &students[i].enrollment_date.year);
    }
    fclose(filePtr);
}

void sort(Student students[], int size, int selection)
{
   Student temp;

   switch(selection)
   {
       // by name
   case 1:
       for(int i = 0; i < size - 1; i++)
       {
           for(int j = 0; j < size - i - 1; j++)
           {
               if(strcmp(students[j].name, students[j+1].name) > 0)
               {
                   temp = students[j];
                   students[j] = students[j+1];
                   students[j+1] = temp;
               }
           }
       }
       break;

       // by id
   case 2:
       for(int i = 0; i < size - 1; i++)
       {
           for(int j = 0; j < size - i - 1; j++)
           {
               if(students[j].id > students[j+1].id)
               {
                   temp = students[j];
                   students[j] = students[j+1];
                   students[j+1] = temp;
               }
           }
       }
       break;

       // by gpa
   case 3:
       for(int i = 0; i < size - 1; i++)
       {
           for(int j = 0; j < size - i - 1; j++)
           {
               float gpa1 = (students[j].grades[0] + students[j].grades[1] + students[j].grades[2] + students[j].grades[3] + students[j].grades[4]) / 5.0;
               float gpa2 = (students[j+1].grades[0] + students[j+1].grades[1] + students[j+1].grades[2] + students[j+1].grades[3] + students[j+1].grades[4]) / 5.0;

               if(gpa1 > gpa2)
               {
                   temp = students[j];
                   students[j] = students[j+1];
                   students[j+1] = temp;
               }
           }
       }
       break;
   }
}

void statistics(Student students[], int size)
{
   if (size == 0) {
       printf("No students to analyze.\n");
       return;
   }

   float total_gpa = 0;
   float highest_grade = 0;
   float highest_gpa = 0;
   int best_student_index = 0;

   // Calculate each student's GPA and find stats
   for(int i = 0; i < size; i++)
   {
       float student_gpa = (students[i].grades[0] + students[i].grades[1] +
                           students[i].grades[2] + students[i].grades[3] +
                           students[i].grades[4]) / 5.0;

       total_gpa += student_gpa;

       for (int j = 0; j < 4; j++)
       {
           if (students[i].grades[j] > highest_grade) highest_grade = students[i].grades[j];
       }

       if(student_gpa > highest_gpa)
       {
           highest_gpa = student_gpa;
           best_student_index = i;
       }
   }

   float average_gpa = total_gpa / size;

   printf("Class Statistics:\n");
   printf("=================\n");
   printf("Average GPA: %.2f\n", average_gpa);
   printf("Highest Grade: %.2f\n", highest_grade);
   printf("Best Student: %s (ID: %d, GPA: %.2f)\n",
          students[best_student_index].name,
          students[best_student_index].id, highest_gpa);
}

void search(Student students[], int studentID, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (studentID == students[i].id) printf("Student found: %s\n", students[i].name);
    }
    return;
}

int main(void)
{
    Student students[4] = {
        {"Alice Johnson", 12345, {85.5, 92.0, 78.5, 88.0, 91.5}, {15, 2, 2023}},
        {"Bob Smith", 12378, {76.0, 82.5, 79.0, 84.5, 80.0}, {22, 1, 2023}},
        {"Carol Davis", 12401, {95.5, 97.0, 93.5, 96.0, 94.5}, {8, 3, 2023}},
        {"David Wilson", 12289, {68.5, 72.0, 75.5, 70.0, 73.5}, {12, 2, 2023}}
    };

    Student students2[4];

    save_records(students, 4);
    load_records(students2);

    search(students2, 12401, 4);

    sort(students, 4, 1);  // Sort by name
    sort(students, 4, 2);  // Sort by ID
    sort(students, 4, 3);  // Sort by GPA

    statistics(students, 4);

    return (0);
}
