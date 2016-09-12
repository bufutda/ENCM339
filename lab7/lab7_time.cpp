/* * * * * * * * * * * * * * * * * * * * * * * *
 * Title: lab7_time.cpp                        *
 * Name: Mitchell Sawatzky                     *
 * UCID: 10146721                              *
 * Class: ENCM 339-T01/B02                     *
 * * * * * * * * * * * * * * * * * * * * * * * */
#include "lab7_time.h"

Time::Time(): hour(0), minute(0), second(0) { }
Time::Time(int sec) {
    this->set_time(sec);
}
int Time::get_hour() const {
    return hour;
}
int Time::get_minute() const {
    return minute;
}
int Time::get_second() const {
    return second;
}
void Time::set_time(int n) {
    Time local = sec_to_hms(n);
    this->hour = local.get_hour();
    this->minute = local.get_minute();
    this->second = local.get_second();
    return;
}
void Time::increment_by_n(int n) {
    if (n <= 0)
        return;
    this->set_time(n + this->Time_to_sec());
    return;
}
void Time::decrement_by_n(int n) {
    if (n <= 0)
        return;
    int cTime = this->Time_to_sec() - n;
    this->set_time(cTime < 0 ? 0 : cTime);
    return;
}
Time Time::add(Time other_time) {
    Time local(other_time.Time_to_sec() + this->Time_to_sec());
    return local;
}
int Time::Time_to_sec() {
    return hour * 3600 + minute * 60 + second;
}
Time Time::sec_to_hms(int n) {
    Time local;
    if (n <= 0)
        return local;
    local.hour = n / 3600;
    local.minute = (n % 3600) / 60;
    local.second = n % 3600 % 60;
    return local;
}
