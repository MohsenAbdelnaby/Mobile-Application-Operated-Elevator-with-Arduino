#include <LiquidCrystal.h>
#include <SPI.h>
#include <Keypad.h>

LiquidCrystal lcd(12 , 11, 5, 4, 3, 2);

int CurentPositionE1 = 1 ;  //initial floor no.
int CurentPositionE2 = 2 ;
int CurentPositionE3 = 5 ;

char keypressed ;


//............................. Keypad initialization ..................................
const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
// D for 1st floor and d small 5th floor capital up and small down

char keymap[numRows][numCols] =
{
  {'1', '2', '3', '4'},
  {'5', 'M', 'I', 'H'},
  {'A', 'B', 'C', 'D'},
  {'a', 'b', 'c', 'd'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {33, 32, 31, 30}; //Rows 0 to 3
byte colPins[numCols] = {34, 35, 36, 37}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

//......................................................................................

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  Serial.println();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print (CurentPositionE1);
  lcd.setCursor(5, 0);
  lcd.print (CurentPositionE2);
  lcd.setCursor(10, 0);
  lcd.print (CurentPositionE3);
}
int x = 0 , y , z, w;
int CurentPosition;
void loop()
{
  keypressed = myKeypad.getKey();

  if (keypressed != NO_KEY)
  {

    if ((keypressed == 'D'))
    {
      CurentPosition = 1;
      x = NearestElevator ( CurentPosition, CurentPositionE1 ,  CurentPositionE2 , CurentPositionE3);
      Serial.println(x);
    }
    else  if ((keypressed == 'A') || (keypressed == 'a')){
      CurentPosition = 2;
      x = NearestElevator ( CurentPosition, CurentPositionE1 ,  CurentPositionE2 , CurentPositionE3);
      Serial.println(x);
      }

    else if ((keypressed == 'B') || (keypressed == 'b')){
      CurentPosition = 3;
      x = NearestElevator ( CurentPosition, CurentPositionE1 ,  CurentPositionE2 , CurentPositionE3);
      Serial.println(x);
      }

    else if ((keypressed == 'C') || (keypressed == 'c')){
      CurentPosition = 4;
      x = NearestElevator ( CurentPosition, CurentPositionE1 ,  CurentPositionE2 , CurentPositionE3);
      Serial.println(x);
      }

    else if (keypressed == 'd')
    {
      CurentPosition = 5;
      x = NearestElevator ( CurentPosition, CurentPositionE1 ,  CurentPositionE2 , CurentPositionE3);
      Serial.println(x);
    }
    
    else {
      if (x==1 || x ==2 || x==3)
      { 
       
    int Previous_stp ;
    Previous_stp = KeyDestination (keypressed, x);
      }

    }    
  }

  //----------------------------------------------------------------------------------------------------------------------/
   if(Serial.available()>0 && (x==1 || x ==2 || x==3) )
  {
    char recivied = Serial.read();
    Serial.println (recivied);
    int Previous_stp ;
    Previous_stp = KeyDestination (recivied, x);
  }


}

int KeyDestination (char key, int x)
{
  if (x == 1)
  {
    z = 0 ;
    w = 0 ;
    switch (key)
    {
      case '1':
        while (CurentPositionE1 > 1)
        {
          switch (CurentPositionE1)
          {
            case 2:
              {
                for (int i = 45; i >= 0 ; i--)
                {
                  delay(20);
                  if (i == 0)
                  { CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  else if (i == 0)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number

                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  else if (i == 90)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  else if (i == 135)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  delay(15);
                }
                break;
              }
          }
        }
        break;
      case '2' :

        while (CurentPositionE1 > 2)
        {
          switch (CurentPositionE1)
          {
            case 3:
              {
                for (int i = 90; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  else if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }

                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }
                  if (i == 45)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE1 < 2)
        {
          switch (CurentPositionE1)
          {
            case 1:
              {
                for (int i = 0; i <= 45 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }

        }
        break;

      case '3' :

        while (CurentPositionE1 > 3)
        {
          switch (CurentPositionE1)
          {
            case 4:
              {
                for (int i = 135; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }


                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE1 < 3)
        {
          switch (CurentPositionE1)
          {
            case 1:
              {
                for (int i = 0; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2:
              {
                for (int i = 45; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;

          }
        }
        break;

      case '4' :

        while (CurentPositionE1 > 4)
        {
          switch (CurentPositionE1)
          {
            case 5:
              {
                for (int i = 180; i >= 135 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE1--;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE1 < 4)
        {
          switch (CurentPositionE1)
          {
            case 1:
              {
                for (int i = 0; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;

      case '5' :

        while (CurentPositionE1 < 5)
        {
          switch (CurentPositionE1)
          {
            case 1:
              {
                for (int i = 0; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 4:
              {
                for (int i = 135; i <= 180 ; i++)
                {
                  delay(20);
                  if (i == 180)
                  {
                    CurentPositionE1++;
                    Serial.println("you are on the floor" + CurentPositionE1);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE1);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;
    }
  }

  else if (x == 2)
  {
    z = 5 ;
    w = 0 ;
    switch (key)
    {
      case '1':
        while (CurentPositionE2 > 1)
        {
          switch (CurentPositionE2)
          {
            case 2:
              {
                for (int i = 45; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 0)
                  { CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  else if (i == 0)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number

                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  else if (i == 90)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  else if (i == 135)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  delay(15);
                }
                break;
              }
          }
        }
        break;
      case '2' :

        while (CurentPositionE2 > 2)
        {
          switch (CurentPositionE2)
          {
            case 3:
              {
                for (int i = 90; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  else if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }

                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }
                  if (i == 45)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE2 < 2)
        {
          switch (CurentPositionE2)
          {
            case 1:
              {
                for (int i = 0; i <= 45 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }

        }
        break;

      case '3' :

        while (CurentPositionE2 > 3)
        {
          switch (CurentPositionE2)
          {
            case 4:
              {
                for (int i = 135; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }


                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE2 < 3)
        {
          switch (CurentPositionE2)
          {
            case 1:
              {
                for (int i = 0; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2:
              {
                for (int i = 45; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;

          }
        }
        break;

      case '4' :

        while (CurentPositionE2 > 4)
        {
          switch (CurentPositionE2)
          {
            case 5:
              {
                for (int i = 180; i >= 135 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE2--;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE2 < 4)
        {
          switch (CurentPositionE2)
          {
            case 1:
              {
                for (int i = 0; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;

      case '5' :

        while (CurentPositionE2 < 5)
        {
          switch (CurentPositionE2)
          {
            case 1:
              {
                for (int i = 0; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 4:
              {
                for (int i = 135; i <= 180 ; i++)
                {
                  delay(20);
                  if (i == 180)
                  {
                    CurentPositionE2++;
                    Serial.println("you are on the floor" + CurentPositionE2);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE2);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;
    }
  }
  else if (x == 3)
  {
    z = 10 ;
    w = 0 ;
    switch (key)
    {
      case '1':
        while (CurentPositionE3 > 1)
        {
          switch (CurentPositionE3)
          {
            case 2:
              {
                for (int i = 45; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 0)
                  { CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  else if (i == 0)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number

                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  else if (i == 90)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  else if (i == 135)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 0 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  delay(15);
                }
                break;
              }
          }
        }
        break;
      case '2' :

        while (CurentPositionE3 > 2)
        {
          switch (CurentPositionE3)
          {
            case 3:
              {
                for (int i = 90; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 4:
              {
                for (int i = 135; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  else if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }

                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 45 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }
                  if (i == 45)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE3 < 2)
        {
          switch (CurentPositionE3)
          {
            case 1:
              {
                for (int i = 0; i <= 45 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }

        }
        break;

      case '3' :

        while (CurentPositionE3 > 3)
        {
          switch (CurentPositionE3)
          {
            case 4:
              {
                for (int i = 135; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }


                  else
                  {
                    //do nothing
                  }
                  delay(15);
                }
                break;
              }
            case 5:
              {
                for (int i = 180; i >= 90 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE3 < 3)
        {
          switch (CurentPositionE3)
          {
            case 1:
              {
                for (int i = 0; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2:
              {
                for (int i = 45; i <= 90 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;

          }
        }
        break;

      case '4' :

        while (CurentPositionE3 > 4)
        {
          switch (CurentPositionE3)
          {
            case 5:
              {
                for (int i = 180; i >= 135 ; i--)
                {
                  //ser.write(i);
                  delay(20);

                  if (i == 135)
                  {
                    CurentPositionE3--;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3); // the floor number
                  }

                  delay(15);
                }
                break;
              }
          }
          break;
        }
        while (CurentPositionE3 < 4)
        {
          switch (CurentPositionE3)
          {
            case 1:
              {
                for (int i = 0; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 135 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;

      case '5' :

        while (CurentPositionE3 < 5)
        {
          switch (CurentPositionE3)
          {
            case 1:
              {
                for (int i = 0; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 45)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }

            case 2 :
              {
                for (int i = 45; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 90)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 3:
              {
                for (int i = 90; i <= 180 ; i++)
                {
                  //ser.write(i);
                  delay(20);
                  if (i == 135)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  if (i == 180)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
            case 4:
              {
                for (int i = 135; i <= 180 ; i++)
                {
                  delay(20);
                  if (i == 180)
                  {
                    CurentPositionE3++;
                    Serial.println("you are on the floor" + CurentPositionE3);
                    lcd.setCursor(z, w);
                    lcd.print(CurentPositionE3);// the floor number
                  }
                  delay(15);
                }
                break;
              }
              break;
          }
        }
        break;
    }

  }
  else {//do nothing
  }



}

int NearestElevator(char CurentPosition, int CurentPositionE1  , int CurentPositionE2 , int CurentPositionE3 ) //  CurrentPosition: based on floor num and up/down button from user
// el mfrod 3ndi 3 variables l kol elevator :  CurentPositionE1 CurentPositionE2 CurentPositionE3
{

  int  E1 = abs(CurentPosition - CurentPositionE1);
  int  E2 = abs(CurentPosition - CurentPositionE2);
  int  E3 = abs(CurentPosition - CurentPositionE3);

  if ((E1 < E2) && (E1 < E3))
  {
    Serial.print("Elevator 1 is the nearest ");
    y = 1 ;
    while (E1 != 0)
    {
      E1--;
      if (CurentPosition > CurentPositionE1)
      {
        CurentPositionE1++;
        lcd.setCursor(0, 0);
        lcd.print(CurentPositionE1);
      }
      else {
        CurentPositionE1--;
        lcd.setCursor(0, 0);
        lcd.print(CurentPositionE1);
      }
    }
  }
  else if (E2 < E3)
  {
    Serial.print("Elevator 2 is the nearest ");
    y = 2 ;
    while (E2 != 0)
    {
      E2--;
      if (CurentPosition > CurentPositionE2)
      {
        CurentPositionE2++;
        lcd.setCursor(5, 0);
        lcd.print(CurentPositionE2);
      }
      else {
        CurentPositionE2--;
        lcd.setCursor(5, 0);
        lcd.print(CurentPositionE2);
      }
    }
  }

  else
  {
    Serial.print("Elevator 3 is the nearest") ;
    y = 3;
    while (E3 != 0)
    {
      E3--;
      if (CurentPosition > CurentPositionE3)
      {
        CurentPositionE3++;
        lcd.setCursor(10, 0);
        lcd.print(CurentPositionE3);
      }
      else {
        CurentPositionE3--;
        lcd.setCursor(10, 0);
        lcd.print(CurentPositionE3);
      }
    }

  }

  return y ;
}
