
//Uncomment to get Serial Debugging messages
//#define Debug
//#define Debug_Motor

#define ACP_B1 3       // change for different boards
                        //3 = Left hand side, 4 = Middle, 5 = Right hand side       different Code:(1 = BoardMotorController, 2 = RGB)

struct AktuatorParameter
{
    bool used[4];
    int min_angle[4];
    int max_angle[4];
    int min_pot[4];
    int max_pot[4];
    bool reversed_output[4];
    bool reversed_input[4];
    int goalDeadzone[4];
    byte maxSpeed[4];
    int maxAngularSpeed[4];
    byte ContinuousMovement[4];
};

AktuatorParameter aktuatorParameters[3]={{{true,true,true,true},{0, 0, 0, 0},{180, 180, 180, 180},{574, 258, 181, 450},{846, 830, 855, 963},{true, true, true, false},{false, false, false, false},{6,6,6,6},{255,255,255,255},{0,0,0,0},{0,0,0,0}},{{true,true,true,true},{0, 0, 0, 0},{180, 180, 180, 180},{574, 258, 181, 450},{846, 830, 855, 963},{true, true, true, false},{false, false, false, false},{6,6,6,6},{255,255,255,255},{0,0,0,0},{0,0,0,0}},{{true,true,true,true},{0, 0, 0, 0},{180, 180, 180, 180},{574, 258, 181, 450},{846, 830, 855, 963},{true, true, true, false},{false, false, false, false},{6,6,6,6},{255,255,255,255},{0,0,0,0},{0,0,0,0}}};
/*
aktuatorParameters[0].used = {true,true,true,true};
aktuatorParameters[0].min_angle = {0, 0, 0, 0};
aktuatorParameters[0].max_angle = {180, 180, 180, 180};
aktuatorParameters[0].min_pot = {574, 258, 181, 450};
aktuatorParameters[0].max_pot = {846, 830, 855, 963};
aktuatorParameters[0].reversed_output = {true, true, true, false};
aktuatorParameters[0].reversed_input = {false, false, false, false};
aktuatorParameters[0].goalDeadzone = {6,6,6,6};
aktuatorParameters[0].maxSpeed = {255,255,255,255};
aktuatorParameters[0].maxAngularSpeed = {0,0,0,0};
aktuatorParameters[0].ContinuousMovement = {0,0,0,0};

aktuatorParameters[1].used[4] = {true,true,false,false};
aktuatorParameters[1].min_angle = {0, 0, 0, 0}; //45-115 screw drive
aktuatorParameters[1].max_angle = {180, 180, 180, 180};
aktuatorParameters[1].min_pot = {384, 271, 0, 0};
aktuatorParameters[1].max_pot = {661, 776, 1000, 1000};
aktuatorParameters[1].reversed_output = {false, false, false, false};
aktuatorParameters[1].reversed_input = {false, false, false, false};
aktuatorParameters[1].goalDeadzone = {6,6,6,6};
aktuatorParameters[1]. maxSpeed = {200,255,255,255};
aktuatorParameters[1].maxAngularSpeed = {200,200,0,0};
aktuatorParameters[1].ContinuousMovement = {0,0,0,0};

aktuatorParameters[2].used = {true,true,true,true};
aktuatorParameters[2].min_angle = {0, 0, 0, 0};
aktuatorParameters[2].max_angle = {180, 180, 180, 180};
aktuatorParameters[2].min_pot = {222, 281, 91, 340};
aktuatorParameters[2].max_pot = {492, 810, 670, 844};
aktuatorParameters[2].reversed_output = {false, true, true, true};
aktuatorParameters[2].reversed_input = {false, false, false, false};
aktuatorParameters[2].goalDeadzone = {6,6,6,6};
aktuatorParameters[2].maxSpeed = {255,255,255,255};
aktuatorParameters[2].maxAngularSpeed = {0,0,0,0};
aktuatorParameters[2].ContinuousMovement = {0,0,0,0};
    
*/

//general stuff:
const long Baudrate = 115200;
#define ACP_B2 3       //0 = not Used (if 1st Byte is 1 or 2), 1 = Hand, 2 = Head, 3 = Actuator (since there is max one per side)
