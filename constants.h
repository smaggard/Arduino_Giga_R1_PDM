#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1
// INPUT and OUTPUT definitions
// INPUTs
const int INPUT1 = 1;
const int INPUT2 = 2;
const int INPUT3 = 3;
const int INPUT4 = 4;
const int INPUT5 = 5;
const int INPUT6 = 6;
const int INPUT7 = 7;
const int INPUT8 = 8;
const int INPUT9 = 9;
const int INPUT10 = 10;
const int INPUT11 = 11;
const int INPUT12 = 12;
const int INPUT13 = 13;
const int INPUT14 = 14;
const int INPUT15 = 15;
const int INPUT16 = 16;
const int inputArray[] = {INPUT1, INPUT2, INPUT3, INPUT4, \
                          INPUT5, INPUT6, INPUT7, INPUT8, \
                          INPUT9, INPUT10, INPUT11, INPUT12, \
                          INPUT13, INPUT14, INPUT15, INPUT16};

// OUTPUTs
const int OUTPUT1 = 22;
const int OUTPUT2 = 23;
const int OUTPUT3 = 24;
const int OUTPUT4 = 25;
const int OUTPUT5 = 26;
const int OUTPUT6 = 27;
const int OUTPUT7 = 28;
const int OUTPUT8 = 29;
const int OUTPUT9 = 30;
const int OUTPUT10 = 31;
const int OUTPUT11 = 32;
const int OUTPUT12 = 33;
const int OUTPUT13 = 34;
const int OUTPUT14 = 35;
const int OUTPUT15 = 36;
const int OUTPUT16 = 37;
const int outputArray[] = {OUTPUT1, OUTPUT2, OUTPUT3, OUTPUT4, \
                           OUTPUT5, OUTPUT6, OUTPUT7, OUTPUT8, \
                           OUTPUT9, OUTPUT10, OUTPUT11, OUTPUT12, \
                           OUTPUT13, OUTPUT14, OUTPUT15, OUTPUT16};

// Sensors
const int SENSOR1 = A0;  // external 1
const int SENSOR2 = A1;  // external 2
const int SENSOR3 = A2;  // external 3
const int SENSOR4 = A3;  // external 4
const int SENSOR5 = A4;  // internal amp
const int SENSOR6 = A5;  // internal temp
const int SENSOR7 = A6;  // future use
const int SENSOR8 = A7;  // future use
const int sensorsArray[] = {SENSOR1, SENSOR2, SENSOR3, SENSOR4, \
                            SENSOR5, SENSOR6, SENSOR7, SENSOR8};

// CAN IDS
const int canIDS[] = {0x1E202001, 0x1E206001, 0x1E20A001, 0x1E20E001, \
                      0x1E212001, 0x1E216001, 0x1E21A001, 0x1E21E001, \ 
                      0x1E202002, 0x1E206002, 0x1E20A002, 0x1E20E002, \ 
                      0x1E212002, 0x1E216002, 0x1E21A002, 0x1E21E002};

const int sensorCanIDS[] = {0x1E202003, 0x1E206003, 0x1E20A003, 0x1E20E003, \
                            0x1E212003, 0x1E216003, 0x1E21A003, 0x1E21E003};

const int incomingCanIDS[] = {0x1E202627, 0x1E212627, 0x1E202628};
#endif
