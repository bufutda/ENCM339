/* * * * * * * * * * * * * * * * * * * * * * * *
 * Title: lab7_time.h                          *
 * Name: Mitchell Sawatzky                     *
 * UCID: 10146721                              *
 * Class: ENCM 339-T01/B02                     *
 * * * * * * * * * * * * * * * * * * * * * * * */
 #ifndef lab7_exe_C_Time
 #define lab7_exe_C_Time

class Time {
public:
    Time ();
    Time (int sec);

    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void set_time(int n);
    void increment_by_n(int n);
    void decrement_by_n(int n);
    Time add(Time other_time);
private:
    int hour;
    int minute;
    int second;

    int Time_to_sec();
    Time sec_to_hms(int n);
};

 #endif
