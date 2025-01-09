//Coding for Arduino
//10/02/24
//ENGE 1216
//Professor Chambers




//assigns each button, the strum, and the buzzer to a certain port
const int buttonC = 2;
const int buttonD = 3;
const int buttonE = 4;
const int buttonF = 5;
const int buttonG = 6;
const int buttonA = 7;
const int buttonB = 8;
const int strumPinX = A0;
const int strumPinY = A1;
const int buzzer = 10;




int moveScale = 0;




//each button gets a certain input and also distinguishes input to output material
void setup() {
  Serial.begin(9600);
  
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(buttonD, INPUT_PULLUP);
  pinMode(buttonE, INPUT_PULLUP);
  pinMode(buttonF, INPUT_PULLUP);
  pinMode(buttonG, INPUT_PULLUP);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(strumPinX, INPUT);
  pinMode(strumPinY, INPUT);
}




//creates the function of when pressing strum and button produce that certain sound
void loop() {
  // checks if guitar is strummed and in which direction (determines frequency of note)
  int strumPinValueX = analogRead(strumPinX);
  int strumPinValueY = analogRead(strumPinY);




  bool isStrumDown = (strumPinValueX < 200);
  bool isStrumLeft = (strumPinValueY < 200);
  bool isStrumRight = (strumPinValueY > 700);
  bool isStrumUp = (strumPinValueX > 700);
 
  bool isStrum = (isStrumDown || isStrumUp || isStrumRight || isStrumLeft);
 
  // Creates the frequency range to play each note depending on strum direction. Frequency in notes
  // can be doubled/halved by octave (i.e. C4 * 2 = C5, C5 * 2 = C6, etc)
  int freqC = 131;
  int freqD = 147;
  int freqE = 165;
  int freqF = 175;
  int freqG = 196;
  int freqA = 220;
  int freqB = 247;




  int freqCSharp = 139;
  int freqDSharp = 155;
  int freqFSharp = 185;
  int freqGSharp = 208;
  int freqASharp = 233;
 
  // multiplier for each octave
  int mult = 0;








  if (isStrumDown) {
    mult = 1;
  } else if (isStrumRight) {
    mult = 2;
  } else if (isStrumLeft) {
    mult = 4;
  } else if (isStrumUp) {
    mult = 8;
  }
 
  if (isStrum) {
    freqC = freqC * mult;
    freqD = freqD * mult;
    freqE = freqE * mult;
    freqF = freqF * mult;
    freqG = freqG * mult;
    freqA = freqA * mult;
    freqB = freqB * mult;
    freqCSharp = freqCSharp * mult;
    freqDSharp = freqDSharp * mult;
    freqFSharp = freqFSharp * mult;
    freqGSharp = freqGSharp * mult;
    freqASharp = freqASharp * mult;
  }




  // set notes to button based on shift
  bool tuneUp = (!digitalRead(buttonC) && !digitalRead(buttonB));
  bool tuneDown = (!digitalRead(buttonC) && !digitalRead(buttonA));
  if (tuneUp) {
    moveScale++;
    if (moveScale > 6) {
      moveScale = 0;
    }
    delay(500);
  }
  if (tuneDown) {
    moveScale--;
    if (moveScale < -6) {
      moveScale = 0;
    }
    delay(500);
  }




  // see what button is pressed/what note should be played
  bool isCPressed = !digitalRead(buttonC);
  bool isDPressed = !digitalRead(buttonD);
  bool isEPressed = !digitalRead(buttonE);
  bool isFPressed = !digitalRead(buttonF);
  bool isGPressed = !digitalRead(buttonG);
  bool isAPressed = !digitalRead(buttonA);
  bool isBPressed = !digitalRead(buttonB);
  
  if (moveScale == -1) {
    isCPressed = !digitalRead(buttonD);
    isDPressed = !digitalRead(buttonE);
    isEPressed = !digitalRead(buttonF);
    isFPressed = !digitalRead(buttonG);
    isGPressed = !digitalRead(buttonA);
    isAPressed = !digitalRead(buttonB);
    isBPressed = !digitalRead(buttonC);


    freqA = freqA / 2;
  } else if (moveScale == -2) {
    isCPressed = !digitalRead(buttonE);
    isDPressed = !digitalRead(buttonF);
    isEPressed = !digitalRead(buttonG);
    isFPressed = !digitalRead(buttonA);
    isGPressed = !digitalRead(buttonB);
    isAPressed = !digitalRead(buttonC);
    isBPressed = !digitalRead(buttonD);


    freqA = freqA / 2;
    freqASharp = freqASharp / 2;
    freqB = freqB / 2;
  } else if (moveScale == -3) {
    isCPressed = !digitalRead(buttonF);
    isDPressed = !digitalRead(buttonG);
    isEPressed = !digitalRead(buttonA);
    isFPressed = !digitalRead(buttonB);
    isGPressed = !digitalRead(buttonC);
    isAPressed = !digitalRead(buttonD);
    isBPressed = !digitalRead(buttonE);


    freqG = freqG / 2;
    freqGSharp = freqGSharp / 2;
    freqA = freqA / 2;
    freqASharp = freqASharp / 2;
    freqB = freqB / 2;
  } else if (moveScale == -4) {
    isCPressed = !digitalRead(buttonG);
    isDPressed = !digitalRead(buttonA);
    isEPressed = !digitalRead(buttonB);
    isFPressed = !digitalRead(buttonC);
    isGPressed = !digitalRead(buttonD);
    isAPressed = !digitalRead(buttonE);
    isBPressed = !digitalRead(buttonF);


    freqF = freqF / 2;
    freqFSharp = freqFSharp / 2;
    freqG = freqG / 2;
    freqGSharp = freqGSharp / 2;
    freqA = freqA / 2;
    freqASharp = freqASharp / 2;
    freqB = freqB / 2;
  } else if (moveScale == -5) {
    isCPressed = !digitalRead(buttonA);
    isDPressed = !digitalRead(buttonB);
    isEPressed = !digitalRead(buttonC);
    isFPressed = !digitalRead(buttonD);
    isGPressed = !digitalRead(buttonE);
    isAPressed = !digitalRead(buttonF);
    isBPressed = !digitalRead(buttonG);


    freqE = freqE / 2;
    freqF = freqF / 2;
    freqFSharp = freqFSharp / 2;
    freqG = freqG / 2;
    freqGSharp = freqGSharp / 2;
    freqA = freqA / 2;
    freqASharp = freqASharp / 2;
    freqB = freqB / 2;
  } else if (moveScale == -6) {
    isCPressed = !digitalRead(buttonB);
    isDPressed = !digitalRead(buttonC);
    isEPressed = !digitalRead(buttonD);
    isFPressed = !digitalRead(buttonE);
    isGPressed = !digitalRead(buttonF);
    isAPressed = !digitalRead(buttonG);
    isBPressed = !digitalRead(buttonA);


    freqD = freqD / 2;
    freqDSharp = freqDSharp / 2;
    freqE = freqE / 2;
    freqF = freqF / 2;
    freqFSharp = freqFSharp / 2;
    freqG = freqG / 2;
    freqGSharp = freqGSharp / 2;
    freqA = freqA / 2;
    freqASharp = freqASharp / 2;
    freqB = freqB / 2;
  } else if (moveScale == 6) {
    isCPressed = !digitalRead(buttonD);
    isDPressed = !digitalRead(buttonE);
    isEPressed = !digitalRead(buttonF);
    isFPressed = !digitalRead(buttonG);
    isGPressed = !digitalRead(buttonA);
    isAPressed = !digitalRead(buttonB);
    isBPressed = !digitalRead(buttonC);


    freqC = freqC * 2;
    freqCSharp = freqCSharp * 2;
    freqD = freqD * 2;
    freqDSharp = freqDSharp * 2;
    freqE = freqE * 2;
    freqF = freqF * 2;
    freqFSharp = freqFSharp * 2;
    freqG = freqG * 2;
    freqGSharp = freqGSharp * 2;
    freqA = freqA * 2;
  } else if (moveScale == 5) {
    isCPressed = !digitalRead(buttonE);
    isDPressed = !digitalRead(buttonF);
    isEPressed = !digitalRead(buttonG);
    isFPressed = !digitalRead(buttonA);
    isGPressed = !digitalRead(buttonB);
    isAPressed = !digitalRead(buttonC);
    isBPressed = !digitalRead(buttonD);


    freqC = freqC * 2;
    freqCSharp = freqCSharp * 2;
    freqD = freqD * 2;
    freqDSharp = freqDSharp * 2;
    freqE = freqE * 2;
    freqF = freqF * 2;
    freqFSharp = freqFSharp * 2;
    freqG = freqG * 2;
  } else if (moveScale == 4) {
    isCPressed = !digitalRead(buttonF);
    isDPressed = !digitalRead(buttonG);
    isEPressed = !digitalRead(buttonA);
    isFPressed = !digitalRead(buttonB);
    isGPressed = !digitalRead(buttonC);
    isAPressed = !digitalRead(buttonD);
    isBPressed = !digitalRead(buttonE);


    freqC = freqC * 2;
    freqCSharp = freqCSharp * 2;
    freqD = freqD * 2;
    freqDSharp = freqDSharp * 2;
    freqE = freqE * 2;
    freqF = freqF * 2;
  } else if (moveScale == 3) {
    isCPressed = !digitalRead(buttonG);
    isDPressed = !digitalRead(buttonA);
    isEPressed = !digitalRead(buttonB);
    isFPressed = !digitalRead(buttonC);
    isGPressed = !digitalRead(buttonD);
    isAPressed = !digitalRead(buttonE);
    isBPressed = !digitalRead(buttonF);


    freqC = freqC * 2;
    freqCSharp = freqCSharp * 2;
    freqD = freqD * 2;
    freqDSharp = freqDSharp * 2;
    freqE = freqE * 2;
  } else if (moveScale == 2) {
    isCPressed = !digitalRead(buttonA);
    isDPressed = !digitalRead(buttonB);
    isEPressed = !digitalRead(buttonC);
    isFPressed = !digitalRead(buttonD);
    isGPressed = !digitalRead(buttonE);
    isAPressed = !digitalRead(buttonF);
    isBPressed = !digitalRead(buttonG);


    freqC = freqC * 2;
    freqCSharp = freqCSharp * 2;
    freqD = freqD * 2;
  } else if (moveScale == 1) {
    isCPressed = !digitalRead(buttonB);
    isDPressed = !digitalRead(buttonC);
    isEPressed = !digitalRead(buttonD);
    isFPressed = !digitalRead(buttonE);
    isGPressed = !digitalRead(buttonF);
    isAPressed = !digitalRead(buttonG);
    isBPressed = !digitalRead(buttonA);


    freqC = freqC * 2;
  }




  // final strum code
 
  if (isStrum) {
    if (isCPressed && isDPressed) {
      tone(buzzer, freqCSharp);
    } else if (isDPressed && isEPressed) {
      tone(buzzer, freqDSharp);
    } else if (isFPressed && isGPressed) {
      tone(buzzer, freqFSharp);
    } else if (isGPressed && isAPressed) {
      tone(buzzer, freqGSharp);
    } else if (isAPressed && isBPressed) {
      tone(buzzer, freqASharp);
    } else if (isCPressed) {
      tone(buzzer, freqC);
    } else if (isDPressed) {
      tone(buzzer, freqD);    
    } else if (isEPressed) {
      tone(buzzer, freqE);  
    } else if (isFPressed) {
      tone(buzzer, freqF);  
    } else if (isGPressed) {
      tone(buzzer, freqG);
    } else if (isAPressed) {
      tone(buzzer, freqA);
    } else if (isBPressed) {
      tone(buzzer, freqB);
    } else {
      noTone(buzzer);
    }
 
  } else {
    noTone(buzzer);
  }
}
