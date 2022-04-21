
#define Debug
//#define Debug_Serial
//#define Debug_Motor

#define ACP_B1 3       // change for different boards
                        //1 = BoardMotorController, 2 = RGB,3 = Left hand side, 4 = Middle, 5 = Right hand side

#if ACP_B1 == 3
    const bool isServo[4] = {false, false, false, false}; //Some Controllers use real Servos

    const int min[4] = {0, 0, 0, 0};
    const int max[4] = {180, 180, 180, 180};
    const int min_pot[4] = {0, 145, 215, 30};
    const int max_pot[4] = {1000, 755, 630, 490};

    const int startDeadzone = 5;
    const int driveDeadzone = 5;
    const int goalDeadzone = 6;
    const int Speed1Zone = 0;
    const int Speed2Zone = 0;

    const bool reversed[4] = {false, true, true, true};
#elif ACP_B1 == 4
    const bool isServo[4] = {false, false, false, false}; //Some Controllers use real Servos

    const int min[4] = {0, 0, 0, 0}; //45-115 screw drive
    const int max[4] = {180, 180, 180, 180};
    const int min_pot[4] = {0, 0, 0, 0};
    const int max_pot[4] = {1000, 1000, 1000, 1000};

    const int startDeadzone = 5;
    const int driveDeadzone = 5;
    const int goalDeadzone = 6;
    const int Speed1Zone = 15;
    const int Speed2Zone = 30;

    const bool reversed[4] = {false, false, false, true};
#elif ACP_B1 == 5
    const bool isServo[4] = {false, false, false, false}; //Some Controllers use real Servos

    const int min[4] = {0, 0, 0, 0};
    const int max[4] = {180, 180, 180, 180};
    const int min_pot[4] = {0, 0, 0, 0};
    const int max_pot[4] = {1000, 1000, 1000, 1000};

    const int startDeadzone = 5;
    const int driveDeadzone = 5;
    const int goalDeadzone = 6;
    const int Speed1Zone = 15;
    const int Speed2Zone = 30;

    const bool reversed[4] = {false, false, false, true};
#endif


//general stuff:
const long Baudrate = 115200;
#define ACP_B2 3       //0 = not Used (if 1st Byte is 1 or 2), 1 = Hand, 2 = Head, 3 = Actuator (since there is max one per side)