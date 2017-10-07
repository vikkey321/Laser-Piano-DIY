int note_C = 2;
int note_D = 3;
int note_E = 4;
int note_F = 5;
int note_G = 6;
int note_A = 7;
int note_B = 8;
int note_Ca = 9;

int sound = 10;

int buttonstate_C = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;
int buttonstate_G = 0;
int buttonstate_A = 0;
int buttonstate_B = 0;
int buttonstate_Ca = 0;

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; //freq
int toner = 0;

void setup()
{
  pinMode(note_C, INPUT);
  pinMode(note_D, INPUT);
  pinMode(note_E, INPUT);
  pinMode(note_F, INPUT);
  pinMode(note_G, INPUT);
  pinMode(note_A, INPUT);
  pinMode(note_B, INPUT);
  pinMode(note_Ca, INPUT);

  pinMode(sound, OUTPUT);
}

void loop()
{
  buttonstate_C = digitalRead(note_C);
  buttonstate_D = digitalRead(note_D);
  buttonstate_E = digitalRead(note_E);
  buttonstate_F = digitalRead(note_F);
  buttonstate_G = digitalRead(note_G);
  buttonstate_A = digitalRead(note_A);
  buttonstate_B = digitalRead(note_B);
  buttonstate_Ca = digitalRead(note_Ca);

  if((buttonstate_C == LOW) || (buttonstate_E == LOW) || 
    (buttonstate_G == LOW) || (buttonstate_D == LOW) || 
    (buttonstate_F == LOW) || (buttonstate_A == LOW) || 
    (buttonstate_B == LOW) || (buttonstate_Ca == LOW) )
  { 
    if (buttonstate_C == LOW)
    {
      toner = tones[0];
    } 
    if (buttonstate_D == LOW)
    {
      toner = tones[1];
    }
    if (buttonstate_E == LOW)
    {
      toner = tones[2];
    }
    if (buttonstate_F == LOW)
    {
      toner = tones[3];
    }
    if (buttonstate_G == LOW)
    {
      toner = tones[4];
    }
    if (buttonstate_A == LOW)
    {
      toner = tones[5];
    }
    if (buttonstate_B == LOW)
    {
      toner = tones[6];
    }
    if (buttonstate_Ca == LOW)
    {
      toner = tones[7];
    }

    digitalWrite(sound, LOW);
    delayMicroseconds(toner);
    digitalWrite(sound, HIGH);
    delayMicroseconds(toner);
  }
  else //in case no button is pressed , close the piezo
  {
    digitalWrite(sound, HIGH);
  }

}
