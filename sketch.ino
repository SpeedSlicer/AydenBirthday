#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const char* speech[] = {
  "If you see text ",
  "on this screen,",
  "I'm glad you    ",
  "didn't explode! ",
  "Happy Birthday ",
  "Ayden!         ",
  "You've been a  ",
  "critical part  ",
  "of my life since",
  " 6th grade.    ",
  "Your impact is ",
  "incredibly HUGE",
  "on my life.    ",
  "You are a day 1",
  "friend and made",
  "an impact to   ",
  "everyone you met",
  ".              ",
  "You still talked",
  "to me when I   ",
  "wasn't as good ",
  "at socializing,",
  "and inspired me",
  "to change myself",
  "for the better.",
  "Thanks for     ",
  "always being   ",
  "there.         ",
  "- Shaun!       ",
  "               ",
  "If you want to ",
  "change the text",
  "(since this    ",
  "loops) go to   ",
  "github.com/    ",
  "SpeedSlicer/   ",
  "AydenBirthday  "
};

const int speechCount = sizeof(speech) / sizeof(speech[0]);

byte balloon[8] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B00100,
  B00100,
  B00000,
  B00000
};

byte cakeBase[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B11111,
  B00000,
  B00000
};

byte cakeFlame1[8] = {
  B00100,
  B01110,
  B00100,
  B00000,
  B01110,
  B11111,
  B11111,
  B00000
};

byte cakeFlame2[8] = {
  B00000,
  B00100,
  B01110,
  B00100,
  B01110,
  B11111,
  B11111,
  B00000
};


void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, balloon);
  lcd.createChar(1, cakeFlame1);
  lcd.createChar(2, cakeFlame2);
  lcd.createChar(3, cakeBase);
  lcd.clear();
}

void loop() {
  for (int i = 0; i < speechCount; i += 2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(speech[i]);
    if (i + 1 < speechCount) {
      lcd.setCursor(0, 1);
      lcd.print(speech[i + 1]);
    }
    delay(2000);
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.setCursor(14, 0);
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("HAPPY BIRTHDAY");



  while (true) {

    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.setCursor(7, 1);
    lcd.write(byte(1));
    lcd.setCursor(15, 1);
    lcd.write(byte(0));
    delay(500);


    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.setCursor(7, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(0));
    delay(500);
  }
}
