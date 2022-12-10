class Motor
{
private:
    byte pin_pot;
    byte pin_motorPWM;
    byte pin_motorA;
    byte pin_motorB;

    bool used;
    int min_angle;
    int max_angle;
    int min_pot;
    int max_pot;
    bool reverse_output;
    bool reverse_input;
    int continuousMovement;
    int goalDeadzone;

    //Slowspeed currently not implemented
    int rampUpTime;
    int maxSpeed;

    int angle;
    int goalAngle;
    bool newGoal;
    bool moving;
    int startDiff;
    int startTime;

    //error Detection Settings
    const int errorTime = 600;
    const int errorMinDiff = 2;
    const int errorDiff = 20;

    void readSensorInput();
    void motorControl(byte Speed, bool Direction);
    void angleControl();

public:
    Motor(bool Used, int Min_angle, int Max_angle, int Min_pot, int Max_pot, 
        bool Reverse_output, bool Reverse_input, int ContinuousMovement);
    void SetPins(byte pin_pot, byte pin_motorPWM, byte pin_motorA, byte pin_motorB);
    void Init();
    void SetAngle(int Angle);
    int GetAngle(){return angle;}

    bool Error_Value;
    bool Error_OutOfRange;
    bool Error_Time;
    
    ~Motor();
};  
