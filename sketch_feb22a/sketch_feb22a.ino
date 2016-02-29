// Use this code to test your motor with the Arduino board:
// if you need PWM, just use the PWM outputs on the Arduino
// and instead of digitalWrite, you should use the analogWrite command

byte rx_data = 0; //variable to store receive data
// --------------------------------------------------------------------------- Motors
int motor_left[] = {4, 5};
int motor_right[] = {6, 7};

// --------------------------------------------------------------------------- Setup
void setup() {
  Serial.begin(9600);
  
// Setup motors
  int i;
  for(i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
}

// --------------------------------------------------------------------------- Loop
void loop() {

/*drive_forward();
delay(3000);
motor_stop();
Serial.println("1");*/

/*drive_backward();
delay(1000);
motor_stop();
Serial.println("2");*/

/*turn_left();
delay(1000);
motor_stop();
Serial.println("3"); */

/*turn_right();
delay(1000);
motor_stop();
Serial.println("4");*/

/*motor_stop();
delay(1000);
motor_stop();
Serial.println("5");*/
  if(Serial.available()) // check if UART receive data
  {
    rx_data = Serial.read();  //store data received
    if(rx_data == 'w')  //if the character received is 'w'
    {
      drive_forward();
      Serial.print("Applying electrical fuel");
      Serial.print('\n');
    }
    else if ( rx_data == 's') //if the character received is 's'
    {
      motor_stop();
      Serial.print("Hit the breaks");
      Serial.print('\n');
    }
    else if ( rx_data == 'a') //if the character received is 'a'
    {
      turn_left();
      delay(150);
      motor_stop();
      Serial.print("Making a Left turn");
      Serial.print('\n');
    }
    else if ( rx_data == 'd') //if the character received is 'd'
    {
      turn_right();
      delay(150);
      motor_stop();
      Serial.print("Making a Right turn");
      Serial.print('\n');
    }
    else if ( rx_data == 'v') //if the character received is 'v'
    {
      drive_backward();
      Serial.print("Backing up");
      Serial.print('\n');
    }
  }
}

// --------------------------------------------------------------------------- Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}

void drive_backward(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], HIGH);
}

void turn_left(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], HIGH);
}
