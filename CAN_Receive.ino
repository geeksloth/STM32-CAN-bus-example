#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(10);    // set SPI Chip Select to pin 10

unsigned char len = 0;
unsigned char buf[8];
unsigned int canID;

void setup()
{
  Serial.begin(115200);
  
INITIALIZATION:
    if(CAN_OK == CAN.begin(CAN_500KBPS)){      //setting CAN baud rate to 500Kbps
        Serial.println("CAN bus initialize successful!");
    }else{
        Serial.println("CAN bus init failed!");
        Serial.println("try again in 5 seconds...");
        delay(5000);
        goto INITIALIZATION;
    }
}



void loop()
{
    if(CAN_MSGAVAIL == CAN.checkReceive()){
        CAN.readMsgBuf(&len, buf);    //read data,  len: data length, buf: data buffer
        canID = CAN.getCanId();       //getting the ID of the incoming message

        Serial.print("ID: ");
        Serial.print(canID, HEX);     //printing the ID in its standard form, HEX

        Serial.print("    Length: ");
        Serial.println(len);
        
        for(int i = 0; i<len; i++){    //looping on the incoming data to print them
            Serial.write(buf[i]);     //Serial.write prints the character itself
        }
        Serial.println("\n\t*****************\n");
    }
}
