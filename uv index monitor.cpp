#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);
int UVOUT = A0;         // Output from the sensor
int REF_3V3 = A1;        //  Analog pin connected to the 3.3V reference voltage.
const int LED_PIN = 10;   
const int BUZZER_PIN = 9; 
const int FADE_DELAY = 10;    // Delay between brightness changes (ms)
const int SKIN_TYPE_OPTIONS = 3;
const String skinTypeOptions[SKIN_TYPE_OPTIONS] = {"D", "N", "O"}; // D>>Dry / N>>Normal / O >>Oily 
const int SENSITIVITY_OPTIONS = 3;
const String sensitivityOptions[SENSITIVITY_OPTIONS] = {"H", "M", "L"}; // H>> High /M>>Medium / L>>Low  
// Variables to store the last UV intensity reading
float lastUVIntensity = 0.0;
bool readingStopped = false;   

int selectedSkinTypeIndex = -1;   // Initialize to an invalid index

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
  pinMode(LED_PIN, OUTPUT); // Initialize LED pin as output
  pinMode(BUZZER_PIN, OUTPUT); // Initialize buzzer pin as output
  Serial.println("ML8511 example");
}

void loop() {
  if (!readingStopped)  // continue in reading until i write s at serial  
  {
    // Read UV intensity only if reading is not stopped
    int uvLevel = averageAnalogRead(UVOUT);   // reads the analog value from the UV sensor connected to pin UVOUT
    // It calls the averageAnalogRead() function to get a stable reading.
    int refLevel = averageAnalogRead(REF_3V3); //This line reads the analog value from the reference voltage pin REF_3V3
    float outputVoltage = 3.3 / refLevel * uvLevel; //This line calculates the output voltage from the UV sensor using the formula Vout = (Vin / Vref) * 
    lastUVIntensity = mapfloat(outputVoltage, 0.99, 2.8, 0.0, 15.0); // Convert the voltage to a UV intensity level
   //the output voltage to a UV intensity level in the range of 0.0 to 15.0 mW/cm^2 using the mapfloat() function.
    Serial.print("UV Intensity (mW/cm^2): ");
    Serial.println(lastUVIntensity);

    // Update LED brightness based on UV intensity
    updateLedBrightness(lastUVIntensity);
     
    
    if (lastUVIntensity >= 0.16) //Buzzer active only at that case 
    {
      activateBuzzer();
    } else {
      deactivateBuzzer();
    }

    lcd.clear();
    lcd.print("UV Intensity:");
    lcd.setCursor(0, 1);
    lcd.print(lastUVIntensity);
    lcd.print(" mW/cm^2");

    delay(200);
  }

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read until newline
    input.trim(); // Remove leading and trailing whitespace
    if (input.equalsIgnoreCase("s")) {
      Serial.println("Displaying skin type options...");
      readingStopped = true;
      displaySkinTypeOptions(); // Display skin type options
    }
  }
}

void displaySkinTypeOptions() {
  lcd.clear(); // Clear LCD
  lcd.print("SEL Skin Type:");
  lcd.setCursor(0, 1);
  for (int i = 0; i < SKIN_TYPE_OPTIONS; i++) {
    lcd.print(i + 1); // Print option number
    lcd.print(".");
    lcd.print(skinTypeOptions[i]);
    if (i < SKIN_TYPE_OPTIONS - 1) {
      lcd.print(" / "); // Separator between options
    }
  }

  int choice = waitForValidInput(1, SKIN_TYPE_OPTIONS);  // Wait for valid input within the range

  selectedSkinTypeIndex = choice - 1; // Store the selected skin type index
  Serial.println("Displaying sensitivity options...");
  delay(200); // Delay to avoid reading the same input again
  displaySensitivityOptions(); // Display sensitivity options
}

void displaySensitivityOptions() {
  lcd.clear(); // Clear LCD
  lcd.print("SEL Sensitivity:");
  lcd.setCursor(0, 1);
  for (int i = 0; i < SENSITIVITY_OPTIONS; i++) {
    lcd.print(i + 1); // Print option number
    lcd.print(".");
    lcd.print(sensitivityOptions[i]);
    if (i < SENSITIVITY_OPTIONS - 1) 
    {
      lcd.print(" / "); // Separator between options
    }
  }

  int choice = waitForValidInput(1, SENSITIVITY_OPTIONS); // Wait for valid input within the range
  lcd.clear();
  lcd.print("Selected Sensitivity:");
  lcd.setCursor(0, 1);
  lcd.print(sensitivityOptions[choice - 1]);

  // Calculate sunscreen frequency
  int sunscreenFrequency = calculateSunscreenFrequency(lastUVIntensity, selectedSkinTypeIndex, choice - 1);
  lcd.clear();
  lcd.print("Sunscreen Freq:");
  lcd.setCursor(0, 1);
  lcd.print(sunscreenFrequency+1);
  lcd.print(" times/day");

  delay(2000); // Display for 2 seconds before returning to main loop
}

int averageAnalogRead(int pinToRead) {
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;

  for (int x = 0; x < numberOfReadings; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return (runningValue);
} //takes an analog pin as input (pinToRead). It reads the analog value from the specified pin 8 times (numberOfReadings) and calculates the average
// It's to obtain stable readings from analog sensors by reducing noise.

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Waits for valid input within the specified range and returns the choice
int waitForValidInput(int minVal, int maxVal) {
  while (true) {
    while (!Serial.available()) {
      delay(100);
    }
    String input = Serial.readStringUntil('\n'); // Read user input until newline
    input.trim(); // Remove leading and trailing whitespace
    int choice = input.toInt(); // Convert input to integer
    if (choice >= minVal && choice <= maxVal) { // Validate the choice
      return choice;
    } else {
      lcd.clear();
      lcd.print("Invalid Choice");
      delay(2000);              // Display "Invalid Choice" for 2 seconds
      lcd.clear();
      // Redisplay options
      if (minVal == 1 && maxVal == SKIN_TYPE_OPTIONS) {
        displaySkinTypeOptions();
      } else {
        displaySensitivityOptions();
      }
    }
  }
}

// Calculates the frequency of sunscreen application based on UV intensity, skin type, and sensitivity
int calculateSunscreenFrequency(float uvIntensity, int skinTypeIndex, int sensitivityIndex) {
  // Define factors based on skin type and sensitivity
  float skinFactor = 1.0; // Default factor
  if (skinTypeIndex == 0) { // Dry skin
    skinFactor = 1.5;
  } else if (skinTypeIndex == 2) { // Oily skin
    skinFactor = 0.5;
  }

  float sensitivityFactor = 1.0; // Default factor
  if (sensitivityIndex == 0) { // High sensitivity
    sensitivityFactor = 1.5;
  } else if (sensitivityIndex == 2) { // Low sensitivity
    sensitivityFactor = 0.5;
  }

  // Calculate the frequency based on UV intensity and factors
  float frequency = uvIntensity * skinFactor * sensitivityFactor;

  // Round the frequency to the nearest integer
  int roundedFrequency = int(frequency + 0.5);

  return roundedFrequency;
}

// Update LED brightness based on UV intensity
void updateLedBrightness(float uvIntensity) {
  // Map UV intensity to LED brightness (PWM duty cycle)
  int brightness = map(uvIntensity, 0, 15, 20, 255);
  analogWrite(LED_PIN, brightness); // Set LED brightness
}

// Activate buzzer
void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer
}

// Deactivate buzzer
void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
}