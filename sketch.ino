#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const char* speech[] = {
  "If you see text on this screen,",
  "I'm glad you didn't explode!",
  "Happy Birthday  Ayden!",
  "You've been a critical part",
  "of my life since 6th grade.",
  "Your impact is incredibly",
  "HUGE on my life.",
  "You are a day 1 friend",
  "and made an impact to",
  "everyone you met.",
  "You still talked to me",
  "when I wasn't as good at",
  "socializing, and inspired me",
  "to change myself for the better.",
  "Thanks for always being there.",
  "- Shaun!"
  "If you want to change the text (since this loops)",
  "go to github.com/SpeedSlicer/"
};


const int speechCount = sizeof(speech) / sizeof(speech[0]);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  for (int i = 0; i < speechCount; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);

    
    typeText(speech[i]);

    
    int messageLength = strlen(speech[i]);
    int delayTime = messageLength * 50; 
    delay(delayTime);
  }
}


void typeText(const char* text) {
  int charCount = 0;
  int row = 0;
  
  for (int i = 0; i < strlen(text); i++) {
    
    if (charCount == 16) {
      row++;
      if (row > 1) break; 
      lcd.setCursor(0, row);
    }

    lcd.print(text[i]);
    charCount++;
    delay(100); 
  }
}
