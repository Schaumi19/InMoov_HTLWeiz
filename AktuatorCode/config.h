
const int ACP_B1 = 4;
const int ACP_B2 = 3;
const long Baudrate = 115200;

const int min[4] = {0, 0, 0, -15};
const int max[4] = {180, 180, 180, 15};
const int min_pot[4] = {0, 0, 0, 50};
const int max_pot[4] = {0, 0, 0, 110};

const int startDeadzone = 25;
const int driveDeadzone = 25;
const int goalDeadzone = 20;

const double SpeedModifier[4] = {.1f, .1f, .1f, .1f};

const bool isServo[4] = {false, false, false, true};
const int servoPins[4] = {0, 0, 0, A0};
