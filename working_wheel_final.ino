/* Minimum_Source*/
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define frwd1 1485
#define frwd2 666
#define rvrs1 410
#define rvrs2 1434
#define stop1 1024
#define stop2 0
#define turnL 1536
#define turnR 512

Dynamixel Dxl(DXL_BUS_SERIAL1);
int dWheel1 = 1;
int dWheel2 = 2;


int pinInput1 = 10; //front bumper
int pinInput2 = 11; //right bumper
int pinInput3 = 12; // left bumper
//int count = 0;
int val1, val2, val3;


void setup() 
{
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.wheelMode(dWheel1); //wheelMode() for wheel1
  Dxl.wheelMode(dWheel2); //wheelMode() for wheel2
  pinMode(pinInput1, INPUT);
  pinMode(pinInput2, INPUT);
  pinMode(pinInput3, INPUT);

}

void loop() 
{
  val1 = digitalRead(pinInput1);  //front bumper
  val2 = digitalRead(pinInput2);  //right bumper
  val3 = digitalRead(pinInput3);  // left bumper
  
  if (val1 == HIGH)
  {
     //stop when obstacle is hit from in front of robot
     Dxl.goalSpeed(dWheel1, stop1);
     Dxl.goalSpeed(dWheel2, stop2);
     delay(250);
     //back up when obstacle is hit from in front of robot
     Dxl.goalSpeed(dWheel1, rvrs1);
     Dxl.goalSpeed(dWheel2, rvrs2);
     delay(250);  
     //turn 90* after backup
     Dxl.goalSpeed(dWheel1, turnL);
     Dxl.goalSpeed(dWheel2, turnL); 
     delay(300);
     //wait half a second before going forward again
     Dxl.goalSpeed(dWheel1, stop1);
     Dxl.goalSpeed(dWheel2, stop1);
     delay(500);  
  }
  
  else if (val2 == HIGH)
  {
     //stop when obstacle is hit from the right of robot
     //Dxl.goalSpeed(dWheel1, stop1);
     //Dxl.goalSpeed(dWheel2, stop2);
     //delay(250);
     //back up when obstacle is hit from the right of robot
     //Dxl.goalSpeed(dWheel1, rvrs1);
     //Dxl.goalSpeed(dWheel2, rvrs2);
     //delay(525);  
     //turn slight left and keep going
     Dxl.goalSpeed(dWheel1, turnL);
     Dxl.goalSpeed(dWheel2, turnL); 
     delay(70);
  
     //Dxl.goalSpeed(dWheel1, stop1);
     //Dxl.goalSpeed(dWheel2, stop1);
     //delay(1000);  
  }
  
  else if (val3 == HIGH)
  {
     //stop when obstacle is hit from the left of robot
     //Dxl.goalSpeed(dWheel1, stop1);
     //Dxl.goalSpeed(dWheel2, stop2);
     //delay(250);
     //back up when obstacle is hit from the left of robot
     //Dxl.goalSpeed(dWheel1, rvrs1);
     //Dxl.goalSpeed(dWheel2, rvrs2);
     //delay(500);  
     //turn slight right and keep going
     Dxl.goalSpeed(dWheel1, turnR);
     Dxl.goalSpeed(dWheel2, turnR); 
     delay(70);
  
     //Dxl.goalSpeed(dWheel1, stop2);
     //Dxl.goalSpeed(dWheel2, stop2);
     //delay(1000);  
  }

  else 
  {
    Dxl.goalSpeed(dWheel1, frwd1);
    Dxl.goalSpeed(dWheel2, frwd2);
  }

//  delay(100);
}

