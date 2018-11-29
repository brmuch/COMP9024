enum DAY{
    MON, TUE, WED, THU, FRI, SAT, SUN
};

typedef struct Date{
    enum DAY day;
    int year;
    int month;
    int date;
    int hour;
    int minute;
}Date;

typedef struct Opal{
    int Transction_number;
    Date date;
    char Mode;
    char Details[31];
    int Journey_number;
    char Fare_applied[31];
    float Fare;
    float Discount;
    float Amount;
}Opal;

