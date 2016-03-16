/*
    SyrotaAutomation1.cpp - Home automation protocol

    Created by Sergey Syrota, Feb 28, 2014.
*/

/*
    @ = 0x02

    Request
    @[to-address]>command-string\n

    Response
    @>response-string\n

    Command/request string is arbitrry, application can call an assert function to check what command was called

    Host computer:
        - SendRequest(to, data)
        - listen to response, until timeout is reached
        - if timeout - error
        - As soon as we encounter \n in the response - finish receiving

    Arduino device:
        - Listen always
        - Start collecting data as soon as 0x02 is enocuntered
        - See if [to-address] matches device address
        - if it does, continue collecting command string
        - Stop collection when \n encountered

*/

#include "SyrotaAutomation1.h"

SyrotaAutomation::SyrotaAutomation(int modePinNum)
{
    // Write down mode PIN number, so that we can switch between send and receive.
    modePin = modePinNum;
    pinMode(modePin, OUTPUT);
    // Default - receive;
    digitalWrite(modePin, LOW);
    // Serial port should be open by this time with needed baud rate
    responseStarted = false;
}

boolean SyrotaAutomation::messageReceived()
{
    // Looking at the next character, and expecting 0x02 as a signal of transmission start. All other characters are ignored.
    if (Serial.available() && Serial.read() == 2) {
        int charsRead; // number of characters read from serial
        // Read device ID first
        charsRead = Serial.readBytesUntil('>', buffer, 128);
        buffer[charsRead] = '\0'; // add null termination to the string
        // If it's not for us, terminate right away
        if (strcmp(buffer, deviceID) != 0) {
            return false;
        }

        charsRead = Serial.readBytesUntil((char)byte(0x0A), buffer, 128);
        buffer[charsRead] = '\0'; // add null termination to the string

        return true;
    } else {
        return false;
    }
}

boolean SyrotaAutomation::assertCommand(char *command) {
    if (strcmp(command, buffer) == 0) {
        return true;
    } else {
        return false;
    }
}

boolean SyrotaAutomation::assertCommandStarts(char *command, char *paramString) {
    if (strncmp(command, buffer, strlen(command)) == 0) {
        strcpy(paramString, buffer+strlen(command));
        return true;
    } else {
        return false;
    }
}

void SyrotaAutomation::sendResponse(char *raw) {
    // starting headers will be sent automatically
    responseSendPart(raw);
    responseEnd();
}

void SyrotaAutomation::responseStart() {
    // Switch to send mode
    digitalWrite(modePin, HIGH);
    delay(1); // This is necessary for all circuitry to react, otherwise no message is sent
    Serial.write((char)byte(0x02));
    Serial.write(">");
    responseStarted = true;
}

void SyrotaAutomation::responseSendPart(char *raw) {
    if (!responseStarted) {
        // If response was not started, go ahead and start it now.
        responseStart();
    } else {
        // If it was started, that most likely means we've sent something. And MAX481 has an issue when you send more than 32 characters, it'll start sending crap. So we need to cycle mode pin.
        Serial.flush();
        digitalWrite(modePin, LOW);
        delay(40); // 40ms delay was found to be OK with sending large strings. 30 exhibit this issue.
        digitalWrite(modePin, HIGH);
        delay(1);
    }
    Serial.write(raw);
}

void SyrotaAutomation::responseEnd() {
    Serial.write((char)byte(0x0A)); // New line
    // Switch back into receive mode after everything is sent
    Serial.flush();
    digitalWrite(modePin, LOW);
    responseStarted = false;
}
