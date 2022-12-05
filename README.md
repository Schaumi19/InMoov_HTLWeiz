# InMoov_HTLWeiz

### Motor Controller Pinout:

<img src="Images/PCB.png" alt="PCB_Image" width="55%%"  align="right"/>

|   Motor   |      Sensor     |     PWM    |    Dir    |           
|-----------|-----------------|------------|-----------|
|     M1    |     S1 -> A0    |     D10    | D12 + D13 |
|     M2    |     S2 -> A1    |     D9     | D11 + D8  |
|     M3    |     S3 -> A2    |     D6     | D5 + D7   |
|     M4    |     S4 -> A6    |     D3     | D4 + D2   |

LED_Pin: A3
I2C_Pins: A4,A5

<img src="Images/schematic.PNG" alt="Arm2_Image" width="55%%"  align="right"/>
<img src="Images/BizepsActuator.PNG" alt="BizepsActuator_Image" width="55%%"  align="right"/>
<img src="Images/Arm1.PNG" alt="Arm1_Image" width="55%%"  align="right"/>
<img src="Images/Arm2.PNG" alt="Arm2_Image" width="55%%"  align="right"/>


### Stuff to do:

#### Software(Andrea):
*
     - [ ] Skeleton tracking
     - [ ] Nuitrack stability
     - [ ] auto cam select
     - [X] Gesture recognition
     - [X] Follow me
     - [X] Speech recognition
     
####	New software-core IO(Thomas):
*	Out:
     - [X] Servo/Actuators
     - [ ] Speech/Sounds
     - [ ] Mobility
     - [X] Connected Actuator Boards
     - [ ] Actuator Angles (Maybe Visu)
*	IN: 
     - [X] Speech
     - [ ] Position
     - [ ] Distance/Angle to Obstacle
     - [X] Distance/Angle to Person
     - [ ] Distance/Angle/Height of Object
     - [ ] Gyro Data for stabilization
*	Pre-Input: (befor progam start)
     - [ ] gestures/Commands
     - [ ] Voice Lines / text to speech
     - [ ] Operation Limits (Virtual Border)


####	Electrical/AktuatorCode(Schaumi):
*
     - [X] Actuator-Boards more 5V Power
     - [X] New Motor Controller PCB
	 - [X] Electrical Error Detection(Pulldowns missing)
	 - [X] Mechanical Error Detection
	 - [X] Poti reverse
	 - [ ] Disable slowspeed upwards
     - [ ] Collision avoidance Lidar or Camera
     - [ ] Floor detection/fall down steps avoidance
     - [ ] Gyro-Sensor (Chest) (tip prevention) [maybe]
     - [X] noise filters for all motors


####	Mechanical(Rauber):
*
     - [ ] Shoulder out-Actuator
     - [X] Omni-wheels
     - [ ] better omni-wheels
     - [X] Arc - Reactor
     - [X] Instalation of Potis
     - [X] Lubrication of Gearboxes
     - [ ] print replacement parts with better materials/spezifications

#### Protocols:
*
     - InMoovACP (Arduino Connect Protocol):
          - 2 Bytes <- Protocol length
          - 1st Byte:
            - 1 = BoardMotorController,
            - 2 = RGB,
            - 3 = Left hand side,
            - 4 = Middle,
            - 5 = Right hand side
          - 2nd Byte:
            - 0 = not Used (if 1st Byte is 1 or 2)
            - 1 = Hand,
            - 2 = Head,
            - 3 = Actuator (since there is max one per side)

*
     - InMoovAATP (Actuator Angle Transfer Protocol):
          - ;
          - Servo/Motor number(0 = All)
          - ,
          - Angle of Servo/Motor

          Example:	;0,90 --> All to 90
			;1,180 --> Ak. 1 to 180
*
     - New backwards compatible InMoovAATP (Actuator Angle Transfer Protocol):
          - ;
	  - AktuatorPlatine Nummer
			- 1 - linke Hand
			- 2 - linke Schulter
			- 3 - rechte Hand
			- 4 - rechte Schulter
			- 5 - Torso
			- 6 - Head
			- 7 - Board
          - Servo/Motor number(0 = All)
          - ,
          - Angle of Servo/Motor

          Example:	;10,90 --> Linke hand All to 90
			;41,180 --> rechte Schulter Ak. 1 to 180

#### Terminal
*
     - serial_arr indexes:
          - 0 -> Board
          - 1 -> RGB
          - 2 -> Left Hand
          - 3 -> Left Actuator
          - 4 -> Head
          - 5 -> Middle Actuator
          - 6 -> Right Hand
          - 7 -> Right Actuator

#### Serial Arduino assignment
*
     - Kopf: 
          - 1 -> Auf/Ab
          - 2 -> Neigen
          - 3 -> NO FUNCTION
          - 4 -> Drehen
          - 5 -> Rechtes Auge
          - 6 -> Linkes Auge

