int X_PIN = A0;
int Y_PIN = A1;
int X_MAX = 825;
int X_MIN = 180;
float X_CEN = 522;
float X_RANG = X_MAX - X_MIN;
int Y_MAX = 830;
int Y_MIN = 190;
float Y_CEN = 510;
float Y_RANG = Y_MAX - Y_MIN;
float X;
float Y;
float ANGLE = 0.00f;
float LENGTH = 0.00f;

void setup() {
  Serial.begin(9600);
}

void loop() {
  X = -((analogRead(X_PIN) - X_CEN) / (X_RANG / 2)); // X -> -1 ~ 1
  
  // simple clear
  if (abs(X) < 0.02) {
    X = 0.00f;
  }
  if (abs(X) > 0.95) {
    X = 1.00f;
  }
  
  Y = (analogRead(Y_PIN) - Y_CEN) / (Y_RANG / 2); // Y -> -1 ~ 1
  
  // simple clear
  if (abs(Y) < 0.02) {
    Y = 0.00f;
  }
  if (abs(Y) > 1.00) {
    Y = 1.00f;
  }

  ANGLE = atan2(X, Y);

  LENGTH = sqrt((X * X) + (Y * Y));
  
  if (LENGTH < 0.02) {
    LENGTH = 0.00f;
  }
  if (LENGTH > 1.00) {
    LENGTH = 1.00f;
  }
  
  //Serial.print(analogRead(X_PIN));
  Serial.print(LENGTH);
  Serial.print(",");
  //Serial.print(analogRead(Y_PIN));
  //Serial.print(analogRead(X_PIN) - X_CEN);
  Serial.print(ANGLE);
  Serial.println();
}
