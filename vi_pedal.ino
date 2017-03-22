/* Input for vi via pedal. Rising Edge => i ; Falling edge => ESC */

#define PEDAL 12

enum state { High, Low, DebounceHigh, DebounceLow } enState;
int DebounceCount;

/* Compatibility to plain C-Teensy programming , Start */

#define KEY_SHIFT  KEY_LEFT_SHIFT

void usb_keyboard_press( int character, int special )
{
   if (special != 0 )
   {
      Keyboard.press( special);
      delay( 10 );
   }
   Keyboard.press( character );
   delay( 50 );
   Keyboard.releaseAll();
}

void _delay_ms( int wait )
{
   delay( wait );
}

/* Compatibility to plain C-Teensy programming , End */

void setup()
{
  pinMode( PEDAL,  INPUT_PULLUP );
  Keyboard.begin();
  if( digitalRead ( PEDAL ) )
  {
    enState = High;
  }
  else
  {
    enState = Low;
  }
}



void loop()
{
  int currentPin;
  delay( 20 );
  currentPin =  digitalRead( PEDAL);
  switch (enState)
  {
    case High:
      if ( currentPin == 0 )
      {
        DebounceCount = 5;
        enState = DebounceLow;      
      }
      break;
   case DebounceLow:
     if (currentPin == 1 )
     {
        enState = High;
     }
     else
     {
        DebounceCount--;
        if( DebounceCount == 0 )
        {
           usb_keyboard_press( KEY_I , 0 );
           delay(50);
           enState = Low;
        }
     }
     break;
   case Low:
      if ( currentPin == 1 )
      {
        DebounceCount = 5;
        enState = DebounceHigh;      
      }
      break;
   case DebounceHigh:
     if (currentPin == 0 )
     {
        enState = Low;
     }
     else
     {
        DebounceCount--;
        if( DebounceCount == 0 )
        {
           usb_keyboard_press( KEY_ESC , 0 );
           delay(50);
           enState = High;
        }
     }
     break;
  default:
    break;
  }
}

