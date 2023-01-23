
//Uncomment to get Serial Debugging messages
//#define Debug
//#define Debug_Motor


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

#define A4_used {true,true,false,false}
#define A4_min_angle {0, 0, 0, 0}
#define A4_max_angle {180, 180, 180, 180}
#define A4_min_pot {384, 271, 0, 0}
#define A4_max_pot {661, 776, 1000, 1000}
#define A4_reversed_output {false, false, false, false}
#define A4_reversed_input {false, false, false, false}
#define A4_goalDeadzone {6,6,6,6}
#define A4_maxSpeed {200,255,255,255}
#define A4_maxAngularSpeed {200,200,0,0}
#define A4_ContinuousMovement {0,0,0,0}

#define A5_used {true,true,true,true}
#define A5_min_angle {0, 0, 0, 0}
#define A5_max_angle {180, 180, 180, 180}
#define A5_min_pot {222, 281, 91, 340}
#define A5_max_pot {492, 810, 670, 844}
#define A5_reversed_output {false, true, true, true}
#define A5_reversed_input {false, false, false, false}
#define A5_goalDeadzone {6,6,6,6}
#define A5_maxSpeed {255,255,255,255}
#define A5_maxAngularSpeed {0,0,0,0}
#define A5_ContinuousMovement {0,0,0,0}

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

const AktuatorParameter aktuatorParameters[3]={
    {A3_used,A3_min_angle,A3_max_angle,A3_min_pot,A3_max_pot,A3_reversed_output,A3_reversed_input,A3_goalDeadzone,A3_maxSpeed,A3_maxAngularSpeed,A3_ContinuousMovement},
    {A4_used,A4_min_angle,A4_max_angle,A4_min_pot,A4_max_pot,A4_reversed_output,A4_reversed_input,A4_goalDeadzone,A4_maxSpeed,A4_maxAngularSpeed,A4_ContinuousMovement},
    {A5_used,A5_min_angle,A5_max_angle,A5_min_pot,A5_max_pot,A5_reversed_output,A5_reversed_input,A5_goalDeadzone,A5_maxSpeed,A5_maxAngularSpeed,A5_ContinuousMovement}
    };

//general stuff:
const long Baudrate = 115200;
