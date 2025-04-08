//Date class implementation
#include "Date.h"

Date::Date(int m, int d, int y) {
   setNames();
   setMonth(m);
   setDay(d);
   setYear(y);
}

void Date::setNames() {
   names[0] = "January";
   names[1] = "Febraury";
   names[2] = "March";
   names[3] = "April";
   names[4] = "May";
   names[5] = "June";
   names[6] = "July";
   names[7] = "August";
   names[8] = "September";
   names[9] = "October";
   names[10] = "November";
   names[11] = "December";
   daysInMonth[0] = 31;
   daysInMonth[1] = 28;
   daysInMonth[2] = 31;
   daysInMonth[3] = 30;
   daysInMonth[4] = 31;
   daysInMonth[5] = 30;
   daysInMonth[6] = 31;
   daysInMonth[7] = 31;
   daysInMonth[8] = 30;
   daysInMonth[9] = 31;
   daysInMonth[10] = 30;
   daysInMonth[11] = 31;
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12)
        month = m;
    else
        throw IncorrectMonth();
}

void Date::setDay(int d) {
    if (d >= 1 && d <= daysInMonth[month - 1])
        day = d;
    else
        throw IncorrectDay();
}
