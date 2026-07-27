#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "termResult.h"

int testGradePoint()
{
    return (getGradePoint(82.0) == 4.00) && (getGradePoint(35.0) == 0.00);
}

int testGPACalculation()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);

    CourseResult r1 = createCourseResult(&c1, 80.0);
    CourseResult r2 = createCourseResult(&c2, 70.0);

    TermResult term = createTermResult();
    addCourseResult(&term, r1);
    addCourseResult(&term, r2);

    double gpa = calculateGPA(&term);
    return (gpa > 3.82 && gpa < 3.84);
}

int main()
{
    printf("Term result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testGradePoint()) passed++;
    total++;
    if (testGPACalculation()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
