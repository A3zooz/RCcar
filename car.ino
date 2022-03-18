
//declaration of motors

#define right_motor_speed = 3;
#define right_motor_backward = 4;
#define right_motor_forward = 5;

#define left_motor_speed = 6;
#define left_motor_backward = 7;
#define left_motor_forward = 8;

int Speed = 100 ;         
int low_speed = Speed/2;     


void forward()
{
  //move both motors FORWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}

void backward()
{
  //move both motors BACKWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward,HIGH);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward, HIGH);
}

void right()
{
  //move car RIGHT
        analogWrite (right_motor_speed,   0   );
        digitalWrite(right_motor_forward,  HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}

void left ()
{
   //move car LEFT
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,    0   );
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward,  LOW);
}

void forward_left()
{
     //move the right motor with the full speed

        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);

      //move the right motor with a lower speed

        analogWrite(left_motor_speed,low_speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}


void forward_right ()
{
        //move the right motor with a low speed

      analogWrite (right_motor_speed,low_speed);
      digitalWrite(right_motor_forward,   HIGH);
      digitalWrite(right_motor_backward,   LOW);

     //move the right motor with the full speed
     
      analogWrite(left_motor_speed,      Speed);
      digitalWrite(left_motor_forward,    HIGH); 
      digitalWrite(left_motor_backward,    LOW);
}

void backward_left()
{
     //move the right motor with the full speed

        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward,HIGH);

      //move the right motor with a lower speed

        analogWrite(left_motor_speed,low_speed);
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward, HIGH);
}

void backward_right()
{
       //move the right motor with the full speed

        analogWrite (right_motor_speed,low_speed);
        digitalWrite(right_motor_forward,    LOW);
        digitalWrite(right_motor_backward,  HIGH);

        //move the right motor with a lower speed

        analogWrite(left_motor_speed,      Speed);
        digitalWrite(left_motor_forward,     LOW);        
        digitalWrite(left_motor_backward,   HIGH);
}

void Stop()
{
        analogWrite (right_motor_speed,     0   ); 
        analogWrite(left_motor_speed,     0     );
} 


#define echo = 12;
#define trig = 13 ;
int t , d ;

void setup() {
pinMode (echo , INPUT);
pinMode (trig , OUTPUT);

  Serial.begin(9600);
  
  pinMode(right_motor_speed, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);

  pinMode(left_motor_speed, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_forward, OUTPUT);

}

void loop() {
digitalWrite(trig,LOW);
delay(100);
digitalWrite(trig,HIGH);
delay(100);
digitalWrite(trig,LOW);
t = pulseIn (echo,1);
d = (t/2)/29.1;
Serial.println(d);
   
  if(d > 50)
  {forward();}
  if (d <50 && d >0)
  {
    Stop();
    delay(50);
    backward();
    delay(500);
    right();
    delay(1500);
  }
  
}
