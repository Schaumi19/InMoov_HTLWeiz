
bool used = 0;
byte min_angle = 252;
byte max_angle = 252;
uint16_t min_pot = 2525;
uint16_t max_pot = 2525;
bool reverse_output = 0;
bool reverse_input = 0;
byte continuousMovement = 252;
byte goalDeadzone = 252;

byte maxSpeed = 252;
bool useAngularSpeed = 0;

// error Detection Settings
byte errorMinDiff = 252;
byte errorMinAngularSpeed = 252; // °/s

void setup()
{
    Serial.begin(115200);
    delay(1000);
    
}

void loop()
{

    if (Serial.available() >= 12)
    {
        //if (Serial.read() == '!')
        {
            //Serial.println("StartConfig");
            // for (byte i = 0; i < 4; i++)
            //{
            
            byte firstByte = Serial.read();
            used = firstByte & 1;
            reverse_output = firstByte & 2;
            reverse_input = firstByte & 4;
            useAngularSpeed = firstByte & 8;
            min_angle = Serial.read();
            max_angle = Serial.read();
            min_pot = Serial.read() << 8;
            //Serial.read();
            min_pot += Serial.read() ;
            max_pot = Serial.read() << 8;
            max_pot += Serial.read() ;
            continuousMovement = Serial.read();
            goalDeadzone = Serial.read();
            maxSpeed = Serial.read();
            errorMinDiff = Serial.read();
            errorMinAngularSpeed = Serial.read();

            //max_angle = 1;
            //min_pot = 453;
            //errorMinDiff = 50;

            byte MotorParamBytes[12];
            MotorParamBytes[0] = used * 1;
            MotorParamBytes[0] += reverse_output * 2;
            MotorParamBytes[0] += reverse_input * 4;
            MotorParamBytes[0] += useAngularSpeed * 8;
            MotorParamBytes[1] = min_angle;
            MotorParamBytes[2] = max_angle;
            MotorParamBytes[3] = min_pot & 255;
            MotorParamBytes[4] = (min_pot >> 8);
            MotorParamBytes[5] = max_pot & 255;
            MotorParamBytes[6] = (max_pot >> 8);
            MotorParamBytes[7] = continuousMovement;
            MotorParamBytes[8] = goalDeadzone;
            MotorParamBytes[9] = maxSpeed;
            MotorParamBytes[10] = errorMinDiff;
            MotorParamBytes[11] = errorMinAngularSpeed;
            for (int x = 0; x < 12; x++)
            {
                Serial.write(MotorParamBytes[x]);
            }
        }
    }
}
