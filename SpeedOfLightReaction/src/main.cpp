#include <Arduino.h>
#include <LiquidCrystal.h>

// Base variables
int greenLED = 12;
int blueLED = 3;

int arrayLED[] = {greenLED, blueLED};

int button1 = 13;
int button2 = 2;

int buzzer = 11;

int score = 0;

bool gameActive = true;

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

// Function declarations
void end();
void waitForRestart();
void buzzerCountdown();

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(A0));

  lcd.begin(16, 2);
  lcd.print("Score: 0");

  buzzerCountdown();
  
}

void loop() {
  if (!gameActive) return;

  bool correctButton = true;

  // Random LED index
  int randomLED = random(0, sizeof(arrayLED) / sizeof(arrayLED[0]));

  // Light random LED accompanied by a beep
  delay(150);
  digitalWrite(arrayLED[randomLED], HIGH); 

  // Tracks time since start
  unsigned long startTime = millis();

  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  

  // Logic Loop
  while (correctButton){
    unsigned long currentTime = millis();

    // Timeout Check
    if (currentTime - startTime > 1000){
      digitalWrite(arrayLED[0], LOW);
      digitalWrite(arrayLED[1], LOW);
      // Reset the score on LCD
      lcd.setCursor(0, 0);
      lcd.print("Score: ");
      lcd.setCursor(7, 0);
      lcd.print("     ");
      lcd.setCursor(7, 0);
      lcd.print(score);
      end();
      correctButton = false;
    }
    
    // Logic to detect if wrong button is pressed
    if (digitalRead(button1) == 0 && digitalRead(arrayLED[0]) == LOW){
      digitalWrite(arrayLED[1], LOW);
      // Reset the score on LCD
      lcd.setCursor(0, 0);
      lcd.print("Score: ");
      lcd.setCursor(7, 0);
      lcd.print("     ");
      lcd.setCursor(7, 0);
      lcd.print(score);
      end();
      correctButton = false;
    } 
    else if (digitalRead(button2) == 0 && digitalRead(arrayLED[1]) == LOW){
      digitalWrite(arrayLED[0], LOW);
      // Reset the score on LCD
      lcd.setCursor(0, 0);
      lcd.print("Score: ");
      lcd.setCursor(7, 0);
      lcd.print("     ");
      lcd.setCursor(7, 0);
      lcd.print(score);
      end();
      correctButton = false;
    }
    // Logic if the right button is pressed
    else if ((digitalRead(button1) == 0 && digitalRead(arrayLED[0]) == HIGH) || (digitalRead(button2) == 0 && digitalRead(arrayLED[1]) == HIGH)){
      score++;
      // Write score to LCD
      lcd.setCursor(0, 0);
      lcd.print("Score: ");
      lcd.setCursor(7, 0);
      lcd.print(score);

      if (digitalRead(arrayLED[0]) == HIGH){
        digitalWrite(arrayLED[0], LOW);
        break;
      } 
      else {
        digitalWrite(arrayLED[1], LOW);
        break;
      }
    }
  }
}
// Called when player fails
void end(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Game Over!");
  lcd.setCursor(0,1);
  lcd.print("Final Score: ");
  lcd.setCursor(13, 1);
  lcd.print(score);
  delay(8000);

  waitForRestart();

}

void waitForRestart(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press to restart");

  score = 0;

  // Wait until either button is pressed
  while (digitalRead(button1) == HIGH && digitalRead(button2) == HIGH){
    // Do nothing, just wait
  }

  delay(300);
  lcd.clear();
  lcd.print("Score: 0");

  buzzerCountdown();
  gameActive = true;
}

void buzzerCountdown(){
  // Buzzer countdown
  for (int countdown=0; countdown<=2; countdown++){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(900);
  }
}