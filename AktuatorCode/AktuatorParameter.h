
//Uncomment to get Serial Debugging messages
//#define Debug
//#define Debug_Motor

/*
#define A3_used {true,true,true,true}
#define A3_min_angle {0, 0, 0, 0}
#define A3_max_angle {180, 180, 180, 180}
#define A3_min_pot {574, 258, 181, 450}
#define A3_max_pot {846, 830, 855, 963}
#define A3_reversed_output {true, true, true, false}
#define A3_reversed_input {false, false, false, false}
#define A3_goalDeadzone {6,6,6,6}
#define A3_maxSpeed {255,255,255,255}
#define A3_maxAngularSpeed {0,0,0,0}
#define A3_ContinuousMovement {0,0,0,0}
*/

struct AktuatorParameter
{
    const bool used[4];
    const byte min_angle[4];
    const byte max_angle[4];
    const unsigned int min_pot[4];
    const unsigned int max_pot[4];
    const bool reversed_output[4];
    const bool reversed_input[4];
    const byte goalDeadzone[4];
    const byte maxSpeed[4];
    const byte maxAngularSpeed[4];  //kleiner 255
    const byte ContinuousMovement[4];
};

//general stuff:
const long Baudrate = 115200;
