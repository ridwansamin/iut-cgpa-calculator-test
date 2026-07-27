#include <stdio.h>
#include "termResult.h"

double getGradePoint(double marks)
{
    if (marks >= 80.0) return 4.00;
    if (marks >= 75.0) return 3.75;
    if (marks >= 70.0) return 3.50;
    if (marks >= 65.0) return 3.25;
    if (marks >= 60.0) return 3.00;
    if (marks >= 55.0) return 2.75;
    if (marks >= 50.0) return 2.50;
    if (marks >= 45.0) return 2.25;
    if (marks >= 40.0) return 2.00;
    return 0.00;
}

const char* getLetterGrade(double marks)
{
    if (marks >= 80.0) return "A+";
    if (marks >= 75.0) return "A";
    if (marks >= 70.0) return "A-";
    if (marks >= 65.0) return "B+";
    if (marks >= 60.0) return "B";
    if (marks >= 55.0) return "B-";
    if (marks >= 50.0) return "C+";
    if (marks >= 45.0) return "C";
    if (marks >= 40.0) return "D";
    return "F";
}

TermResult createTermResult(void)
{
    TermResult term;
    term.count = 0;
    term.totalCredits = 0.0;
    term.gpa = 0.0;
    return term;
}

void addCourseResult(TermResult *term, CourseResult result)
{
    if (term->count < 100)
    {
        term->results[term->count++] = result;
    }
}

double calculateGPA(TermResult *term)
{
    double totalPoints = 0.0;
    term->totalCredits = 0.0;

    for (int i = 0; i < term->count; i++)
    {
        double credit = term->results[i].course->credit;
        double gradePoint = getGradePoint(term->results[i].marks);
        totalPoints += gradePoint * credit;
        term->totalCredits += credit;
    }

    if (term->totalCredits > 0)
    {
        term->gpa = totalPoints / term->totalCredits;
    }
    else
    {
        term->gpa = 0.0;
    }

    return term->gpa;
}

void viewTermResult(TermResult term)
{
    printf("\n================ TERM RESULT ================\n");
    for (int i = 0; i < term.count; i++)
    {
        Course *c = term.results[i].course;
        double m = term.results[i].marks;
        printf("%-8s %-30s | Credit: %.1f | Marks: %5.2f | Grade: %-2s (%.2f)\n",
               c->code, c->name, c->credit, m, getLetterGrade(m), getGradePoint(m));
    }
    printf("---------------------------------------------\n");
    printf("Total Credits: %.1f\n", term.totalCredits);
    printf("Term GPA:      %.2f\n", term.gpa);
    printf("=============================================\n");
}
