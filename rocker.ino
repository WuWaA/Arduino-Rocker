int X_PIN = A0;
int Y_PIN = A1;
int X_MAX = 825;
int X_MIN = 180;
float X_CEN = 522;
float X_L_RANG = X_MAX - X_CEN;
float X_R_RANG = X_CEN - X_MIN;
int Y_MAX = 830;
int Y_MIN = 190;
float Y_CEN = 510;
float Y_U_RANG = Y_MAX - Y_CEN;
float Y_D_RANG = Y_CEN - Y_MIN;
float X;
float Y;
float ANGLE = 0.00f;
float LENGTH = 0.00f;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // X -> -1 ~ 1
  float X_TMP = -(analogRead(X_PIN) - X_CEN);
  if (X_TMP > 0) {
    X = X_TMP / X_R_RANG;
  }
  else if (X_TMP < 0) {
    X = X_TMP / X_L_RANG;
  }
  else {
    X = 0.00f;
  }
  
  // simple clear
  if (abs(X) < 0.02) {
    X = 0.00f;
  }
  if (abs(X) > 0.98) {
    X = 1.00f;
  }
  
  // Y -> -1 ~ 1
  float Y_TMP = -(analogRead(Y_PIN) - Y_CEN);
  if (Y_TMP > 0) {
    Y = Y_TMP / Y_U_RANG;
  }
  else if (Y_TMP < 0) {
    Y = Y_TMP / Y_D_RANG;
  }
  else {
    Y = 0.00f;
  }
    
  // simple clear
  if (abs(Y) < 0.02) {
    Y = 0.00f;
  }
  if (abs(Y) > 0.98) {
    Y = 1.00f;
  }

  ANGLE = atan2(X, Y);

  LENGTH = sqrt((X * X) + (Y * Y));
  
  if (LENGTH < 0.02) {
    LENGTH = 0.00f;
  }
  if (LENGTH > 0.98) {
    LENGTH = 1.00f;
  }
  
  Serial.print(LENGTH);
  Serial.print(",");
  Serial.print(ANGLE);
  Serial.println();
  delay(30);
}