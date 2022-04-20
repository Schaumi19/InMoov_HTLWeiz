
const int ACP_B1 = 5;
const int ACP_B2 = 3;
const long Baudrate = 115200;

const int min[4] = {0, 0, 0, 0};
const int max[4] = {300, 300, 300, 300};
const int min_pot[4] = {0, 0, 0, 0};
const int max_pot[4] = {1000, 1000, 1000, 1000};

const int startDeadzone = 5;
const int driveDeadzone = 5;
const int goalDeadzone = 6;
const int Speed1Zone = 15;
const int Speed2Zone = 30;

const double SpeedModifier[4] = {.1f, .1f, .1f, .1f};

const bool isServo[4] = {false, false, false, false};
const int servoPins[4] = {0, 0, 0, A0};

const bool reversed[4] = {true, false, false, false};
