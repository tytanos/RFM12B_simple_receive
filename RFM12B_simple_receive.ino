#include <JeeLib.h>

typedef struct {
	int lp;
	int bat;
} Payload;
Payload pomiar;

void setup () {
    Serial.begin(57600);
    Serial.println("\n[Simple test receive]");
    rf12_initialize('R', RF12_433MHZ, 210);
     // rf12_control(0xC688); // bitrate =4.789kbps
     rf12_control(0xC691); //bitrate 2.395kbps
     rf12_control(0x9820); // deviation 45kHz
     rf12_control(0x96C1); //BW 67kHz
     rf12_control(0xC0C3); //batttery and uC clock 5MHz


}

void loop () {
    if (rf12_recvDone() && rf12_crc == 0 && rf12_len == sizeof pomiar) {
        memcpy(&pomiar, (byte*) rf12_data, sizeof pomiar);
        Serial.print("REC ");
        Serial.print("LP");
        Serial.print(pomiar.lp);
        Serial.print(" B");
        Serial.print(pomiar.bat);
        Serial.println();
    }
}
