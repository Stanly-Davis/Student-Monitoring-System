

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#include <SoftwareSerial.h>

#define RST_PIN 9 //RFID Pins
#define SS_PIN 10

SoftwareSerial mySerial(5,6);  //GSM Pins. GSM Module used is Sim800A 

bool sagar = 0;
bool stanly = 0;

byte readCard[4];
String SagarTag = "1AFA4022";	
String StanlyTag = "432D240";	
String tagID = "";

// Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{

  // Initiating
  SPI.begin(); // SPI bus
  mfrc522.PCD_Init(); // MFRC522
  lcd.begin(16, 2); // LCD screen

  mySerial.begin(9600); //For GSM communication

  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.print("Scan Your Card>>");
}

void loop() 
{
  
  //Wait until new tag is available
  while (getID()) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    
    if (tagID == SagarTag) 
    {
       lcd.print("Sagar id:ec101");
       lcd.setCursor(0, 1);

      if(sagar==0)
      {
        lcd.print("Entry");
        SendMessage("Sagar id:ec101","Entered","AT+CMGS=\"+91XXXXXXXXXX\"\r"); //Replace XXXXXXXXXX with Phone number of receiver
        sagar=1;
      }
      else
      {
         lcd.print("Exit");
         SendMessage("Sagar id:ec101","Exited","AT+CMGS=\"+91XXXXXXXXXX\"\r");
         sagar=0;
      }
      
    }

     else if(tagID == StanlyTag)
    {
    
      lcd.print("Stanly id:ec113");
      lcd.setCursor(0, 1);
      
      if(stanly==0)
      {
        lcd.print("Entry");
        SendMessage("Stanly id:ec113","Entered","AT+CMGS=\"+91XXXXXXXXXX\"\r"); //Replace XXXXXXXXXX with Phone number of receiver
        stanly=1;
      }
      else
      {
         lcd.print("Exit");
         SendMessage("Stanly id:ec113","Exited","AT+CMGS=\"+91XXXXXXXXXX\"\r");
         stanly=0;
      }


    }

    else
    {
       lcd.print("Invlaid ID");
    }

      
    delay(4000);

    lcd.clear();
    lcd.print("Scan Your Card>>");
  }
}

//Read new tag if available
boolean getID() 
{
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  { //If a new PICC placed to RFID reader continue
  return false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  { //Since a PICC placed get Serial and continue
  return false;
  }
  tagID = "";
  for ( uint8_t i = 0; i < 4; i++) 
  { 
  // The MIFARE PICCs that we use have 4 byte UID
  // readCard[i] = mfrc522.uid.uidByte[i];
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
}



void SendMessage(String student,String status,String phone)
{

  mySerial.println("AT+CMGF=1");
  delay(1000);

  mySerial.println(phone);
  delay(1000);

  mySerial.println(student+" "+status+" school");
  delay(100);

  mySerial.println((char)26);
  delay(1000);

}