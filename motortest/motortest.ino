#define ENCA 18
#define ENCB 19
int pos = 0;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
  
  // Set the ENCA and ENCB pins as input
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  
  // Attach an interrupt to ENCA to call the readEncoder function on a rising edge
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
}

void loop() {
  // Continuously print the 'pos' value to the serial monitor
  Serial.println(pos);
}

void readEncoder() {
  // Read the current state of ENCB
  int b = digitalRead(ENCB);
  
  // Update the 'pos' value based on the state of ENCB
  if (b > 0) {
    pos++;
  } else {
    pos--;
  }
}
