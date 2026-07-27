#ifndef TERM_RESULT_H
#define TERM_RESULT_H

#include "courseResult.h"

typedef struct TermResult
{
    CourseResult results[100];
    int count;
    double totalCredits;
    double gpa;
} TermResult;

double getGradePoint(double marks);
const char* getLetterGrade(double marks);
TermResult createTermResult(void);
void addCourseResult(TermResult *term, CourseResult result);
double calculateGPA(TermResult *term);
void viewTermResult(TermResult term);

#endif
