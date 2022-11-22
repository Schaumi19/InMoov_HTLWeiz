
//Uncomment to get Serial Debugging messages
#define Debug
//#define Debug_Serial
//#define Debug_Motor

#define ACP_B1 3       // change for different boards
                        //3 = Left hand side, 4 = Middle, 5 = Right hand side       different Code:(1 = BoardMotorController, 2 = RGB)

#if ACP_B1 == 3
    const bool used[4] = {true,true,true,true};

    const int min_angle[4] = {0, 0, 0, 0};
    const int max_angle[4] = {180, 180, 180, 180};
    const int min_pot[4] = {574, 258, 215, 499};
    const int max_pot[4] = {846, 830, 630, 992};
    const bool reversed_output[4] = {false, true, true, false};
    const bool reversed_input[4] = {false, false, false, false};

    const int goalDeadzone = 6;
    const int SlowSpeedZone[4] = {0,0,0,0};
    const byte SlowSpeed[4] = {200,200,200,200};
    const byte maxSpeed[4] = {255,255,255,255};

    const byte ContinuousMovement[4] = {0,0,0,0};

    //error Detection Settings
    const int errorTime = 600;
    const int errorMinDiff = 2;
    const byte errorDiff = 20;

#elif ACP_B1 == 4
    const bool used[4] = {true,true,false,false};

    const int min_angle[4] = {0, 0, 0, 0}; //45-115 screw drive
    const int max_angle[4] = {180, 180, 180, 180};
    const int min_pot[4] = {384, 271, 0, 0};
    const int max_pot[4] = {661, 776, 1000, 1000};
    const bool reversed_output[4] = {true, true, false, false};
    const bool reversed_input[4] = {false, false, false, false};

    const int goalDeadzone = 6;
    const int SlowSpeedZone[4] = {20,0,0,0};
    const byte SlowSpeed[4] = {100,150,200,200};
    const byte maxSpeed[4] = {200,255,255,255};

    //error Detection Settings
    const int errorTime = 1000;
    const int errorMinDiff = 2;
    const byte errorDiff = 20;

    const byte ContinuousMovement[4] = {0,0,0,0};

#elif ACP_B1 == 5
    const bool used[4] = {false,true,true,true};

    const int min_angle[4] =     {0, 0, 0, 0};
    const int max_angle[4] =     {180, 180, 180, 180};
    const int min_pot[4] = {0, 281, 91, 340};
    const int max_pot[4] = {1000, 810, 670, 844};
    const bool reversed_output[4] = {false, true, true, true};
    const bool reversed_input[4] = {false, false, false, false};

    const int goalDeadzone = 4;
    const int SlowSpeedZone[4] = {0,0,0,0};
    const byte SlowSpeed[4] = {200,200,200,200};
    const byte maxSpeed[4] = {255,255,255,255};

    //error Detection Settings
    const int errorTime = 600;
    const int errorMinDiff = 2;
    const byte errorDiff = 20;

    const byte ContinuousMovement[4] = {0,0,0,0};
    
#endif


//general stuff:
const long Baudrate = 115200;
#define ACP_B2 3       //0 = not Used (if 1st Byte is 1 or 2), 1 = Hand, 2 = Head, 3 = Actuator (since there is max one per side)
