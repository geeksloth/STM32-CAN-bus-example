#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(10);          // set SPI to pin 10

void setup()
{
  Serial.begin(115200);


INITIALIZATION:

    if(CAN_OK == CAN.begin(CAN_500KBPS))      //setting CAN baud rate to 500Kbps
    {
        Serial.println("CAN bus initialize successful!");
    }
    else
    {
        Serial.println("CAN bus initialize failed!");
        Serial.println("Retry in 5 seconds...");
        delay(100);
        goto INITIALIZATION;
    }
}

//loading the data bytes of the message. Up to 8 bytes
unsigned char data[9] = {'G', 'e', 'e', 'k', 'S', 'l', 'o', 't', 'h'};

void loop()
{
    //CAN.sendMsgBuf(msg ID, extended?, #of data bytes, data array);
    CAN.sendMsgBuf(0xF1, 0, 9, data);
    delay(5000);                     
}
