/*
 * Date: 22 March 2017
 * Ross Oliver
 * 
  4x4x4 LED Cube -- Arduino_Uno
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4


  
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A3
  d-A2

if you turn on a row or column of led's, you have to turn them off later. 
 before next pattern has started. 

*/





//initializing and declaring led rows
  int column[]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; // 16 ROWS
  //int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; // ROWS
  
//initializing and declaring led layers
 
  // layer (A0 - A), (A1 - B),(A2 - D),(A3 - C)
  int layer[]={A0, A1, A3, A2}; // LAYERS
  //int layer[4]={A3,A2,A1,A0}; // LAYERS


void setup() {
  //setting up pins from (1,1) through to (4,4) 
  
  for(int i = 0; i< 16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  
  //setting layers to output "A,B,C,D"
  // 1=A, 2=B, 3=C, 4=D
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  
  //seeding random for random pattern
  randomSeed(analogRead(10));
}

void TurnallOn()
{
  ////////////////////////////////////////////////////////////turn all on

  // turn on all Columns
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}

void TurnallOff()
{
  ////////////////////////////////////////////////////////////turn all on

  // turn on all Columns
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0);
  }
}

///////////////////////////////////////////////////////turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
}



void FlashEachLedSeperatly() {
  //////////// turns on every LED starting from the top and works its way to the bottom.
  
  // NOTATION: (X,Y)PIN --> (Associated PIN)
  
  
    TurnallOff();
    int i;
    int j;
    int vector;

    for(j = 3; j>=0;j--) // from top to bottom
    {
      digitalWrite(layer[j], 1); // one layer at a time
      digitalWrite(layer[j+1], 0); // turn off previous layer

        vector = j%2; // checks if the LED layer pos.
        // if top level --> forward dir. next level down direction of LED will switch
        // for next layer direction will switch again
        
        ////////// forward from D(1,1) --> D(4,4)
          for (i=0; i < 16 && vector == 1; i++) // increment though the column LED's
          {
          digitalWrite(column[i], 0); // turns of LED
          delay(200);                 // delay for 0.2 seconds
          digitalWrite(column[i],1); // turns of the prev. LED
          }
    
        ////////// backwards from D(4,4) --> D(1,1)
        for (i=15; i > 0 && vector == 0; i--) // decrement though the column LED's
        {
          digitalWrite(column[i], 0);
          delay(200);
          digitalWrite(column[i], 1);
        } 
    }

    for(j = 0; j<=3;j++) // from bottom to top
    {
      digitalWrite(layer[j], 1); // turn on one layer at a time
      digitalWrite(layer[j-1], 0); // turn off previous layer

        vector = j%2; // checks if the LED layer pos.
        // if top level --> forward dir. next level down direction of LED will switch
        // for next layer direction will switch again
        
        ////////// forward from D(1,1) --> D(4,4)
          for (i=0; i < 16 && vector == 0; i++) 
          {
          digitalWrite(column[i], 0);
          delay(200);
          digitalWrite(column[i],1);
          }
    
        ////////// backwards from D(4,4) --> D(1,1)
        for (i=15; i > 0 && vector == 1; i--)
        {
          digitalWrite(column[i], 0);
          delay(200);
          digitalWrite(column[i], 1);
        } 
    }
}

void SmallSquare()
{
  
  //7 3 4 8
  //int column[]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; // ROWS
  
  //digitalWrite(column[5], 1);
  //digitalWrite(column[9], 1);
  //digitalWrite(column[10], 1);
  //digitalWrite(column[6], 1); 

 TurnallOn();
 int j = 0;
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 1);

 
 while (j <= 15) {
  
 
  if (j != 5 && 7 <= j && j >= 11) 
  {
  digitalWrite(column[j], 1);
  j++;
 }
 else if (j < 15) {
  digitalWrite(column[j], 1);
  j++;
  } 
 }
 j = 0;

}



void Turn_on_one()
{
  TurnallOff();
  
  digitalWrite(column[10], 0);
  digitalWrite(layer[2], 1); 
}

void test_square() {
  
  TurnallOff();
  
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 1); 

  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[10], 0);
}
// 5 6 9 10
  
  /* to make this modulated 
   *  ie
   *  
   *  where x is dependenf on the size of the cube
   *  the pin# will get smaller expanding the size of the cube
   *  8+x adds on antother led (corner one) maybe??
   *  for(7-x ; 8+x; i++
   *      digitalWtite(column[i],0)
   *      
   *   y is dep on size will get larger for every itteration untill size 4   
   *   
   *      
   *   for(2-y ; 3+x; i++
   *      digitalWtite(layer[i],1)
  }*/


//////////////////////////////////////////////////////////////propeller
void propeller()
{
  TurnallOff();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1);
      //a1
      turnColumnsOff();

      for(int j=0; j<16; j=j+5)
      {
        digitalWrite(column[j], 0);
      }
      
      delay(x);
      
      //b1
      turnColumnsOff();

      for (int k=4; k <= 5 && 10 <= k && k <= 11 ; k++)
      {
      digitalWrite(column[k], 0);
      }
      delay(x);
      
      //c1
      turnColumnsOff();

      for (int l=6; l<=9; l++)
      {
      digitalWrite(column[l], 0);
      }
      delay(x);
      
      //d1
      turnColumnsOff();

      for (int m = 3; m <= 12; m = m+3)
      {
      digitalWrite(column[m], 0);
      }
      delay(x);
      
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[13], 0);
      delay(x);
      
      //d3
      turnColumnsOff();

      for(int n=1; n<=10; n=n+5)
      {
      digitalWrite(column[n], 0);
      }
      digitalWrite(column[14], 0);
      delay(x);
    }
  }
  //d4
  turnColumnsOff();

  for (int p=0; p<=15; p=p+5)
  {
  digitalWrite(column[p], 0);
  }
  delay(x);
}

void loop() {
  // main code here, to run repeatedly:
  
  //FlashEachLedSeperatly();
  //SmallSquare();
  //Turn_on_one();
  //test_square();
  propeller();
}
