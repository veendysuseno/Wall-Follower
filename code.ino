/* Wall Followers
 *  
 * FINISH
 *|   ---|
 *|      |
 *|      |
 *|---   |
 *|      |
 *|      |
 *|   ---|
 *|      |
 *|      |
 *|---   |
 * START
 * 
 * Legend =
 * + START    = Robot starting position
 * + FINISH   = The final goal of the robot
 * + ---      = Front walls or checkpoints
 * +  |       = Side walls or checkpoints
 */

// Motor pin declaration
int M11 = 9;
int M12 = 10;
int M21 = 5;
int M22 = 6;

int distance = 10;          // distance to turn
int checkpoint = 1;         // calculating checkpoints
int timeturnRight = 600;    // time to turn turnRight
int timeturnLeft = 600;     // time to turn turnLeft

void setup() {
  Serial.begin(9600);       // Baud Rate
  
  // Determination of pin mode as output
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
}

void loop() {
  // Trigger pin determination, Echo 
  int cm = sensor_ping(2,7);

  // Condition Determination
  if (cm > distance) { //Kondisi comeForward
    comeForward ();
  }
  else if (cm <= distance && checkpoint == 1) { //checkpoint first
    turnLeft();
    delay(520);
    checkpoint++;
  }
  else if (cm <= distance && checkpoint == 2) { //checkpoint second
    turnRight();
    delay(600);
    checkpoint++;
  }
  else if (cm <= distance && checkpoint == 3) { //checkpoint third
    turnRight();
    delay(600);
    checkpoint++;
  }
  else if (cm <= distance && checkpoint == 4) { //checkpoint fourth
    turnLeft();
    delay(600);
    checkpoint++;
  }
  else if (cm <= distance && checkpoint == 5) { //checkpoint fifth
    turnRight();
    delay(timeturnLeft);
    checkpoint++;
  }
  else if (cm <= distance && checkpoint == 6) { //checkpoint sixth
    turnRight();
    delay(timeturnRight);
    checkpoint++;
  }
}

// Function comeForward
void comeForward (){
  analogWrite(M11, 255);
  analogWrite(M12, 0);
  analogWrite(M21, 255);
  analogWrite(M22, 0);
}

// Function turnRight
void turnRight (){
  analogWrite(M11, 0);
  analogWrite(M12, 255);
  analogWrite(M21, 255);
  analogWrite(M22, 0);
}

// Function turnLeft
void turnLeft (){
  analogWrite(M11, 255);
  analogWrite(M12, 0);
  analogWrite(M21, 0);
  analogWrite(M22, 255);
}

// Function detects with sensors, using Trigger and Echo pins 
int sensor_ping(const int trigPin,const int echoPin) {
  long duration, cm ;
  
  pinMode(trigPin, OUTPUT);     // pinMode trigPin as OUTPUT
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);      // pinMode echoPin as INPUT
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  // Prints output on the serial monitor
  Serial.print(cm);
  Serial.print("cm");

  // Provide distance 1 line down (ENTER)
  Serial.println();
  delay(100);
  return(cm);
}

  // Converts sensor data into seconds
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
