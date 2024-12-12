// Define the pin connected to the servo
#define SERVO_PIN 14  // Replace with your pin number

// Servo parameters
#define PWM_FREQ 50          // Servo PWM frequency (50 Hz)
#define PWM_CHANNEL 0        // Use channel 0 for PWM
#define PWM_RESOLUTION 16    // PWM resolution (16-bit for finer control)

// Min and max pulse width in microseconds
#define SERVO_MIN_PULSE 500  // 0 degrees
#define SERVO_MAX_PULSE 2500 // 180 degrees

// Helper function to convert angle to duty cycle
int angleToDutyCycle(int angle) {
  int dutyCycle = map(angle, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  // Scale to 16-bit range (65535 = 2^16 - 1)
  return (dutyCycle * 65535) / 20000;
}EE

void setup() {
  // Configure the PWM channel
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  // Attach the PWM channel to the pin
  ledcAttachPin(SERVO_PIN, PWM_CHANNEL);

  Serial.begin(115200);
  Serial.println("Servo initialized. Moving to 0 degrees.");

   while (!Serial) {
    delay(100);
  }
  bool flag = false;

  // Move servo to 0 degrees
  ledcWrite(PWM_CHANNEL, angleToDutyCycle(0));
  delay(1000); 
}

void loop() {
  // Sweep the servo from 0 to 180 degrees
  if (Serial.available() > 0) {
    // Read the incoming data as a string
    bool flag = false;
    String receivedData = Serial.readStringUntil('\n'); // Read until newline character

    // Print the received data to the Serial Monitor
    Serial.print("Received: ");
    Serial.println(receivedData);

    if (receivedData == "1" && !flag){
        for (int angle = 0; angle <= 180; angle++) {
          ledcWrite(PWM_CHANNEL, angleToDutyCycle(angle)); // Set servo position
          delay(8);                                       // Wait for servo to reach position
        }
        flag = true;
      }
    if (receivedData == "2" && !flag){
        for (int angle = 180; angle >= 0; angle--) {
          ledcWrite(PWM_CHANNEL, angleToDutyCycle(angle)); // Set servo position
          delay(8);                                       // Wait for servo to reach position
        }
        flag = true;
      }
  }

}
