#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x20, 16, 2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

// make some custom characters:
  unsigned long startTime = millis();

  int hoursOneWhite = 0;
  int minutesTenWhite = 0;
  int minutesOneWhite = 1;
  int secondsTenWhite = 0;
  int secondsOneWhite = 0;
  
  int hoursOneBlack = 0;
  int minutesTenBlack = 0;
  int minutesOneBlack = 1;
  int secondsTenBlack = 0;
  int secondsOneBlack = 0;

  const int buttonWhitePin = 5;
  const int buttonBlackPin = 6;
  const int reset = 8;
  const int minutesUp = 9;
  const int minutesDown = 10;
  int buttonWhiteState = 0; 
  int buttonBlackState = 0;
  int resetState = 0;
  int buttonWhiteRead = 0;
  int buttonBlackRead = 0;
  int minutesUpRead = 0;
  int minutesDownRead = 0;
  int resetRead = 0;
  int gameTurn = 0;
  int resetTurn = 0;


  int i = 0;
  int k = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  // Make sure backlight is on   
  lcd.backlight();

  // Clears the LCD screen
  lcd.clear();

  // Print a message to the lcd.
  //Setup screen 
  lcd.setCursor(1,0);
  lcd.print("WHITE");
    
  lcd.setCursor(10,0);
  lcd.print("BLACK");
  
  pinMode(buttonWhitePin, INPUT);
  pinMode(buttonBlackPin, INPUT);
  pinMode(reset, INPUT);
  pinMode(minutesUp, INPUT);
  pinMode(minutesDown, INPUT);
  
  lcd.setCursor(1,0);
  lcd.print("WHITE");
    
  lcd.setCursor(10,0);
  lcd.print("BLACK");
    
  lcd.setCursor(7,1);
  lcd.print("||");
  
  lcd.setCursor(1,1);
  lcd.print(":");
    
  lcd.setCursor(4,1);
  lcd.print(":");
    
    
  lcd.setCursor(13,1);
  lcd.print(":");
  
  lcd.setCursor(10,1);
  lcd.print(":");
}

// Print All the custom characters
void loop() {
  
  resetRead = digitalRead(reset);
  Serial.println(resetRead);
    if (resetRead == HIGH){
     resetTurn = 1; 
    }
  
if(resetTurn == 1){
  i = 0;
  hoursOneWhite = 0;
  minutesTenWhite = 0;
  minutesOneWhite = 1;
  secondsTenWhite = 0;
  secondsOneWhite = 0;
  Serial.println("code is working");
  hoursOneBlack = 0;
  minutesTenBlack = 0;
  minutesOneBlack = 1;
  secondsTenBlack = 0;
  secondsOneBlack = 0;
  resetTurn = 0;
    
          lcd.setCursor(1,0);
  lcd.print("WHITE ");
    
  lcd.setCursor(9,0);
  lcd.print(" BLACK");
    
  lcd.setCursor(7,1);
  lcd.print("||");
  
  lcd.setCursor(1,1);
  lcd.print(":");
    
  lcd.setCursor(4,1);
  lcd.print(":");
    
    
  lcd.setCursor(13,1);
  lcd.print(":");
  
  lcd.setCursor(10,1);
  lcd.print(":");
  
  }
  while(i == 0){
    
  buttonWhiteRead = digitalRead(buttonWhitePin);
  buttonBlackRead = digitalRead(buttonBlackPin);
    
    if (buttonWhiteRead == HIGH){
      buttonWhiteState = 1;
        buttonBlackState = 0; 
    }
    
    if (buttonBlackRead == HIGH){
      buttonWhiteState = 0;
        buttonBlackState = 1;
    } 
    
      if (buttonWhiteState == 1){
        gameTurn = 1;
      }
      if(buttonBlackState == 1){
        gameTurn = 0;
      }
    
 
 //white to move
    lcd.setCursor(0,1);
    lcd.print(hoursOneWhite);
    lcd.setCursor(2,1);
    lcd.print(minutesTenWhite);
    lcd.setCursor(3,1);
    lcd.print(minutesOneWhite);
    lcd.setCursor(5, 1);
    lcd.print(secondsTenWhite);
    lcd.setCursor(6,1);
    lcd.print(secondsOneWhite);

    
    
    
 //black to move
  lcd.setCursor(9,1);
  lcd.print(hoursOneBlack);
  lcd.setCursor(11,1);
  lcd.print(minutesTenBlack);
  lcd.setCursor(12,1);
  lcd.print(minutesOneBlack);
  lcd.setCursor(14, 1);
  lcd.print(secondsTenBlack);
  lcd.setCursor(15,1);
  lcd.print(secondsOneBlack);

 
  
  if (gameTurn == 0){
    secondsOneWhite--;
    lcd.setCursor(7,0);
    lcd.print("<-");
  }
  if (gameTurn == 1){
    secondsOneBlack--;
    lcd.setCursor(7,0);
    lcd.print("->");
  }
   
    
  delay(1000);
    
    //rollover white    
    if (secondsOneWhite == -1){
    secondsOneWhite = secondsOneWhite + 10;
    secondsTenWhite--;
  }
  
    if (secondsTenWhite == -1){
    secondsTenWhite = secondsTenWhite + 6;
    minutesOneWhite--;
  }
    
        //rollover black
    if (secondsOneBlack == -1){
    secondsOneBlack = secondsOneBlack + 10;
    secondsTenBlack--;
  }
  
    if (secondsTenBlack == -1){
    secondsTenBlack = secondsTenBlack + 6;
    minutesOneBlack--;
  }
    
      minutesUpRead = digitalRead(minutesUp);
  Serial.println(resetRead);
    if (minutesUpRead == HIGH){
     minutesOneBlack++;
    }
  minutesDownRead = digitalRead(minutesDown);
  Serial.println(minutesDownRead);
    if (minutesDownRead == HIGH){
     minutesOneBlack--; 
    }
    
    //end when clock reaches zero
  if (secondsTenWhite == 0 && secondsOneWhite == 0 && minutesOneWhite == 0) {
    lcd.setCursor(0,0);
    lcd.print("   Black Wins   ");
    lcd.setCursor(0,1);
    lcd.print("White is washed!");
    i++;
    delay(10000);
  }
  if (secondsTenBlack == 0 && secondsOneBlack == 0 && minutesOneBlack == 0) {
    lcd.setCursor(0,0);
    lcd.print("   White Wins   ");
    lcd.setCursor(0,1);
    lcd.print("Black is washed!");
    i++;
    delay(10000);
  }
    //reset during game
      resetRead = digitalRead(reset);
  Serial.println(resetRead);
    if (resetRead == HIGH){
     resetTurn = 1; 
    }
  
if(resetTurn == 1){
  i = 0;
  hoursOneWhite = 0;
  minutesTenWhite = 0;
  minutesOneWhite = 1;
  secondsTenWhite = 0;
  secondsOneWhite = 0;
  Serial.println("code is working");
  hoursOneBlack = 0;
  minutesTenBlack = 0;
  minutesOneBlack = 1;
  secondsTenBlack = 0;
  secondsOneBlack = 0;
  resetTurn = 0;
    
          lcd.setCursor(1,0);
  lcd.print("WHITE ");
    
  lcd.setCursor(9,0);
  lcd.print(" BLACK");
    
  lcd.setCursor(7,1);
  lcd.print("||");
  
  lcd.setCursor(1,1);
  lcd.print(":");
    
  lcd.setCursor(4,1);
  lcd.print(":");
    
    
  lcd.setCursor(13,1);
  lcd.print(":");
  
  lcd.setCursor(10,1);
  lcd.print(":");
  
  }
    
  }
  
  minutesUpRead = digitalRead(minutesUp);
  Serial.println(resetRead);
    if (minutesUpRead == HIGH){
     minutesOneBlack++;
    }
  minutesDownRead = digitalRead(minutesDown);
  Serial.println(minutesDownRead);
    if (minutesDownRead == HIGH){
     minutesOneBlack--; 
    }
}
