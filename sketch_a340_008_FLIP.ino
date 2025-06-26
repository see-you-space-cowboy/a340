void setup() {
  Serial.begin(9600);

  // Set output pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  static int last_analog_value = -1;
  int analog_value = analogRead(A0);
  float voltage = analog_value * (5.0 / 1023.0);

  Serial.print("ADC reading: ");
  Serial.print(analog_value);
  Serial.print(" Analog voltage: ");
  Serial.println(voltage);

  delay(1);  // Optional; increase if needed

  int difference = last_analog_value - analog_value;

  if (abs(difference) > 10) {
    last_analog_value = analog_value;

    // Logic for pin 2
    bool state2 = false;
    if (analog_value < 103) {
      state2 = true;
    } else if (analog_value < 205) {
      state2 = true;
    } else if (analog_value < 350) {
      state2 = true;
    } else if (analog_value < 511) {
      state2 = false;
    } else {
      state2 = false;
    }

    // Logic for pin 3
    bool state3 = false;
    if (analog_value < 103) {
      state3 = true;
    } else if (analog_value < 205) {
      state3 = false;
    } else if (analog_value < 350) {
      state3 = false;
    } else if (analog_value < 511) {
      state3 = false;
    } else {
      state3 = true;
    }

    // Logic for pin 4
    bool state4 = false;
    if (analog_value < 103) {
      state4 = true;
    } else if (analog_value < 205) {
      state4 = false;
    } else if (analog_value < 350) {
      state4 = true;
    } else if (analog_value < 511) {
      state4 = false;
    } else {
      state4 = true;
    }

    // Output to pins
    digitalWrite(2, state2);
    digitalWrite(3, state3);
    digitalWrite(4, state4);
  }
}
