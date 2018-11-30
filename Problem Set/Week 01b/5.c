5.a
int data[12] = {5, 3, 6, 2, 7, 4, 9, 1, 8};
and assuming that &data[0] == 0x10000, what are the values of the following expressions?

          Titles                               Answers
        data + 4                        0x10000 + 4*4 = 0x10010
        *data + 4                       5 + 4 = 9
        *(data + 4)                     7
        data[4]                         7
        *(data + *(data + 3))           6
        data[data[2]]                   9

5.b
   typedef struct {
      int   studentID;
      int   age;
      char  gender;
      float WAM;
   } PersonT;

   PersonT per1;
   PersonT per2;
   PersonT *ptr;

   ptr = &per1;
   per1.studentID = 3141592;
   ptr->gender = 'M';
   ptr = &per2;
   ptr->studentID = 2718281;
   ptr->gender = 'F';
   per1.age = 25;
   per2.age = 24;
   ptr = &per1;
   per2.WAM = 86.0;
   ptr->WAM = 72.625;
What are the values of the fields in the per1 and per2 record after execution of the above statements?
   per1.studentID = 3141592;
   per1.age = 25;
   per1.gender = 'M';
   per1.WAM = 72.625;

   per2->studentID = 2718281;
   per2->gender = 'F';
   per2.age = 24;
   per2.WAM = 86.0;