// Project Title : IOT Enabled Colorimter for Real-time Concentration and Absorption Analysis
// Name : Boddu Ajay
// College : Rajiv Gandhi University of Knowledge Technologies
// Date : 28-10-2024
//------------------------------------------------------------

#include <Adafruit_LiquidCrystal.h>
// Initialize the LCDs with unique I2C addresses
Adafruit_LiquidCrystal lcd1(0x20); // First LCD for wavelength
Adafruit_LiquidCrystal lcd2(0x21); // Second LCD for absorbance and concentration
void generateWavelength();
// Pin Definitions
const int RGB_redPin = 9;        // Pin for Red LED
const int RGB_greenPin = 10;     // Pin for Green LED
const int RGB_bluePin = 11;      // Pin for Blue LED
const int potentiometerPin = A1; // Pin for the potentiometer
const int LDRPin = A0;           // Pin for the LDR
const int reset = 7;             // Pin for the Reset button
const int zero_analysis_button = 6;  // Pin for the Zero-Analysis button
const int target_analysis_button = 5;  // Pin for the Target-Solution-Analysis button
//Initializing Variables
int wavelength = 0;
float zeroabsorbance = 0;
float zeroconcentration = 0;
float targetabsorbance = 0;
float targetconcentration = 0;
float calibrated_absorbance = 0;
float calibrated_concentration = 0;
bool is_zero_Measuring = false;
bool is_target_Measuring = false;
// Constants for Beer-Lambert Law
const float molarAbsorptivity = 0.1; // Molar absorptivity (L/(mol·cm))
const float pathLength = 1.5;        // Path length in cm (1.5 cm diameter tube)
const float maxAbsorbance = 5.0;     // Set maximum absorbance

void setup() {
    // Initialize the LCDs
    lcd1.begin(16, 2); // Set first LCD size (16x2)
    lcd2.begin(16, 2); // Set second LCD size (16x2)

    // Set RGB LED pins as OUTPUT
    pinMode(RGB_redPin, OUTPUT);
    pinMode(RGB_greenPin, OUTPUT);
    pinMode(RGB_bluePin, OUTPUT);
    pinMode(potentiometerPin, INPUT);
    pinMode(LDRPin, INPUT);
    pinMode(reset, INPUT_PULLUP); // Enable internal pull-up resistor for the reset button
	pinMode(zero_analysis_button,INPUT_PULLUP);
  	pinMode(target_analysis_button, INPUT_PULLUP);
    // Initial display setup for first LCD
    lcd1.setCursor(0, 0);
    lcd1.print("Wavelength: ");

    // Initial display setup for second LCD
    lcd2.setCursor(0, 0);
    lcd2.print("Absorbance: ");
    lcd2.setCursor(0, 1);
    lcd2.print("Conc: "); // Placeholder for concentration

    // Initialize Serial Monitor
    Serial.begin(9600);
}

void loop() {
  if (digitalRead(reset) == LOW) { // Button is pressed
        wavelength = 0; // Reset wavelength
        zeroabsorbance = 0; // Reset Zero Analysis absorbance
        zeroconcentration = 0; // Reset Zero Analysis concentration
        targetabsorbance = 0; //Reset Target Solution Absorbance
		    targetconcentration = 0;  //Reset Target Solution Concentration
        //Clear the LCDs
        lcd1.setCursor(0, 0);
        lcd1.print("Wavelength:       "); 
        lcd2.setCursor(0, 0);
        lcd2.print("Absorbance:       "); 
        lcd2.setCursor(0, 1);
        lcd2.print("Conc:             ");
        analogWrite(RGB_redPin, 0);
        analogWrite(RGB_greenPin, 0);
        analogWrite(RGB_bluePin, 0);
      	delay(500);
      	Serial.println("Reset State");
      	is_zero_Measuring = false;
    	  is_target_Measuring = false;
    }
  	if(digitalRead(zero_analysis_button) == LOW){
        is_zero_Measuring = true;
        delay(200);
    }
 	  if(is_zero_Measuring){
        generateWavelength(); // Gnerates Wavelength based on the readings of Potentiometr
        int ldrValue = analogRead(LDRPin); // Read LDR
        float voltage = ldrValue * (5.0 / 676.0); // Convert LDR value to voltage
        zeroabsorbance = log(5.0 / voltage); // Calculate Zero Analays absorbance
        zeroconcentration = zeroabsorbance / (molarAbsorptivity * pathLength); // Calculate Zero Analysis concentration
        // Display absorbance value on the second LCD
        lcd2.setCursor(12, 0);
        lcd2.print(zeroabsorbance, 2); // Print Zero Analysys absorbance with 2 decimal places
        // Display concentration on the second LCD
        lcd2.setCursor(6, 1); // Move to the right position
        lcd2.print(zeroconcentration, 2); // Print Zero Analysis concentration with 2 decimal places
        lcd2.print(" mg/L"); // Units for Concentration
        // Print absorbance and concentration to the Serial Monitor
        Serial.print("Zero Analysis Absorbance: ");
        Serial.print(zeroabsorbance, 2);
        Serial.print("|| Zero Analysis Concentration: ");
        Serial.print(zeroconcentration, 2);
        Serial.println(" mg/L");
        delay(500); // Small delay for readability 
	  }
  	if(digitalRead(target_analysis_button) == LOW){
        is_target_Measuring = true;
        delay(200);
    }
 	if(is_target_Measuring){
      	// Read the potentiometer value
        generateWavelength();
        // Read LDR value
        int ldrValue = analogRead(LDRPin); // Read LDR
        float voltage = ldrValue * (5.0 / 676.0); // Convert LDR value to voltage
        targetabsorbance = log(5.0 / voltage); // Calculate Targeted solution absorbance
        targetconcentration = targetabsorbance / (molarAbsorptivity * pathLength); // Calculate Targeted Solution concentration
        //Calculation of Calibrated Values for the Targeted Solution
	      calibrated_absorbance = targetabsorbance - zeroabsorbance;
        calibrated_concentration = targetconcentration - zeroconcentration;

        // Display absorbance value on the second LCD
        lcd2.setCursor(12, 0); 
        lcd2.print(calibrated_absorbance, 2); // Print Targted Solution absorbance with 2 decimal places
        // Display concentration on the second LCD
        lcd2.setCursor(6, 1); // Move to the right position
        lcd2.print(calibrated_concentration, 2); // Print Targted Solution concentration with 2 decimal places
        lcd2.print(" mg/L"); // Units for Concentration
		
        // Print absorbance and concentration to the Serial Monitor
        Serial.print("Calibrated Absorbance: ");
        Serial.print(calibrated_absorbance, 2);
        Serial.print("|| Calibrated Concentration: ");
        Serial.print(calibrated_concentration, 2);
        Serial.println(" mg/L");
        delay(500); // Small delay for readability
 	}
}

void generateWavelength(){
      int potValue = analogRead(potentiometerPin); // Read potentiometer
      wavelength = map(potValue, 0, 1023, 380, 780); // Map to wavelength range: 380nm to 780nm
      // Set RGB LED color based on the wavelength
      if (wavelength >= 380 && wavelength <= 440) {
          // Violet to Blue
          analogWrite(RGB_redPin, map(wavelength, 380, 440, 255, 0)); 
          analogWrite(RGB_bluePin, map(wavelength, 380, 440, 0, 255));
          analogWrite(RGB_greenPin, 0); 
      } 
      else if (wavelength > 440 && wavelength <= 490) {
          // Blue to Cyan
          analogWrite(RGB_bluePin, 255); 
          analogWrite(RGB_greenPin, map(wavelength, 440, 490, 0, 255));
          analogWrite(RGB_redPin, 0); 
      } 
      else if (wavelength > 490 && wavelength <= 580) {
          // Cyan to Green
          analogWrite(RGB_greenPin, 255);
          analogWrite(RGB_bluePin, map(wavelength, 490, 580, 255, 0));
          analogWrite(RGB_redPin, 0); 
      } 
      else if (wavelength > 580 && wavelength <= 645) {
          // Green to Yellow
          analogWrite(RGB_redPin, map(wavelength, 580, 645, 0, 255));
          analogWrite(RGB_greenPin, 255); 
          analogWrite(RGB_bluePin, 0); 
      } 
      else if (wavelength > 645 && wavelength <= 780) {
          // Yellow to Red
          analogWrite(RGB_redPin, 255); 
          analogWrite(RGB_greenPin, map(wavelength, 645, 780, 255, 0)); 
          analogWrite(RGB_bluePin, 0); 
      } 
      else {
          // Turn off all LEDs if out of range
          analogWrite(RGB_redPin, 0);
          analogWrite(RGB_greenPin, 0);
          analogWrite(RGB_bluePin, 0);
      }
      // Display the current wavelength on the first LCD
      lcd1.setCursor(11, 0); 
      lcd1.print(wavelength); 
      lcd1.print("nm"); //  Units for Wavelength
      // Print the wavelength to the Serial Monitor
      Serial.print("Wavelength: ");
      Serial.print(wavelength);
      Serial.println(" nm");
}
