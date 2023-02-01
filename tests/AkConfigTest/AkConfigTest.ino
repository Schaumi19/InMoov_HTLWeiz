
bool used;
byte min_angle;
byte max_angle;
unsigned int min_pot;
unsigned int max_pot;
bool reverse_output;
bool reverse_input;
byte continuousMovement = 0;
byte goalDeadzone = 6;

byte maxSpeed = 255;
bool useAngularSpeed = false;

// error Detection Settings
byte errorMinDiff = 2;
byte errorMinAngularSpeed = 20; // °/s
byte errorDiff = 20;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() >= 48)
    {
        if (Serial.read() == '!')
        {
            Serial.println("StartConfig");
            // for (byte i = 0; i < 4; i++)
            //{
            byte firstByte = Serial.read();
            used = firstByte & 1;
            reverse_output = firstByte & 2;
            reverse_input = firstByte & 4;
            useAngularSpeed = firstByte & 8;
            min_angle = Serial.read();
            min_angle += Serial.read() << 8;
            max_angle = Serial.read();
            max_angle = Serial.read() << 8;
            continuousMovement = Serial.read();
            goalDeadzone = Serial.read();
            maxSpeed = Serial.read();
            max_angle = Serial.read();
            errorMinDiff = Serial.read();
            errorMinAngularSpeed = Serial.read();
            errorMinDiff = Serial.read();
            //}

            byte MotorParamBytes[12];
            MotorParamBytes[0] = used * 1;
            MotorParamBytes[0] += reverse_output * 2;
            MotorParamBytes[0] += reverse_input * 4;
            MotorParamBytes[0] += useAngularSpeed * 8;
            MotorParamBytes[1] = min_angle & 255;
            MotorParamBytes[2] = (min_angle >> 8) & 255;
            MotorParamBytes[3] = max_angle & 255;
            MotorParamBytes[4] = (max_angle >> 8) & 255;
            MotorParamBytes[5] = continuousMovement;
            MotorParamBytes[6] = goalDeadzone;
            MotorParamBytes[7] = maxSpeed;
            MotorParamBytes[8] = max_angle;
            MotorParamBytes[9] = errorMinDiff;
            MotorParamBytes[10] = errorMinAngularSpeed;
            MotorParamBytes[11] = errorMinDiff;
            for (int x = 0; x < 12; x++)
            {
                Serial.write(MotorParamBytes[x]);
            }
        }
    }
}