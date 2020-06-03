/*
 * Copyright (C) 2020 Luis Alejandro Bernal Romero (Aztlek)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * This is a program for the MiniQ 2WD robot, it is used to control the robot
 * with the infrared remote control that comes in the kit. But the control that
 * is achieved with this program is much more complete than the example robot
 * program. Some of the additional features are:
 *
 * The turns of the robot are more controllable.
 * Turns can also be done when the robot is moving forward, backward, or stopped.
 * The speed of the robot can be increased and decreased.
 */

#include <IRremote.h>

// Constants for velocity
#define DELTA_V 10
#define MAX_VELOCITY 255

// Ir remote control buttons
#define BACKWARD_BUTTON 0x00fd20df
#define FORDWARD_BUTTON 0x00fd609f
#define POWEOFF_BUTTON 0x00fd00ff
#define VOL_PLUS_BUTTON 0x00fd807f
#define VOL_MINUS_BUTTON 0x00fd906f
#define PLAY_STOP_BUTTOM 0XfdA05f


// Motor constants
#define RIGHT_MOTOR_PIN 6
#define RIGHT_MOTOR_DIRECTION_PIN 7
#define LEFT_MOTOR_PIN 5
#define LEFT_MOTOR_DIRECTION_PIN 12

#define FORW 0//go forward
#define BACK 1//go back

// IR control
#define IR_IN  17//IR receiver pin

IRrecv irrecv(IR_IN);
decode_results results;


int velocity = 0;


void motor_control(int right_motor_dir, int speed_right_motor, int left_motor_dir, int speed_left_motor)
{
  // Right motor
  digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, right_motor_dir);
  analogWrite(RIGHT_MOTOR_PIN, speed_right_motor);
    
  // Left motor
  digitalWrite(LEFT_MOTOR_DIRECTION_PIN, left_motor_dir);
  analogWrite(LEFT_MOTOR_PIN, speed_left_motor);
}

void dump(decode_results *results)
{
  Serial.print("results->value = ");
  Serial.println(results->value);

  switch(results->value) {
    case PLAY_STOP_BUTTOM:
      // STOP
      velocity = 0;
      break;
    case VOL_PLUS_BUTTON:
      // FORWARD
      velocity += DELTA_V;
      if(velocity > MAX_VELOCITY) {
        velocity = MAX_VELOCITY;
      }
      break;
    case VOL_MINUS_BUTTON:
      // BACKWARD
      velocity -= DELTA_V;
      if(velocity < -MAX_VELOCITY) {
        velocity = -MAX_VELOCITY;
      }
      break;
    case BACKWARD_BUTTON:
      // Turn Left
      motor_control(FORW,100,BACK,100);
      delay(50);
      break;
    case FORDWARD_BUTTON:
      // Turn Right
      motor_control(BACK,100,FORW,100);
      delay(50);
      break;
  }

  Serial.print("velocity = ");
  Serial.println(velocity);

  if(velocity == 0) {
        motor_control(FORW, 0, FORW, 0);// stop
  }
  else if(velocity >  0) {
        motor_control(FORW, velocity, FORW, velocity);// forward
  }
  else if(velocity < 0) {
        motor_control(BACK, -velocity, BACK, -velocity);// backward
  }
}

void setup()
{
  // init the motor driver pins
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);

  irrecv.enableIRIn();

  Serial.begin(9600);
  
  motor_control(FORW,0,FORW,0);//run motor
}

void loop()
{
  
   if(irrecv.decode(&results))
   {
      dump(&results);
      irrecv.resume();
   }
}
