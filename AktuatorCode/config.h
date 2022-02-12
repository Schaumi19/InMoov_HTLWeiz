//Don't use for head

const char FirstPos = 'L';   //R = Right; L = Left; M = Middle
const char SecondPos = 's';  //h = hand; s = shoulder; t = torso;
const long Baudrate = 115200;

const int min = 0;
const int max = 900;
const int min_pot[4] = {100, 300, 0, 0};
const int max_pot[4] = {425, 1000, 0, 0};

const int startDeadzone = 25;
const int driveDeadzone = 25;
const int goalDeadzone = 20;

const double SpeedModifier[4] = {.1f, .1f, .1f, .1f};

const bool schmuf[4] = {false, true, false, false};