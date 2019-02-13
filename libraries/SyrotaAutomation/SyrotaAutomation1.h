/*
    SyrotaAutomation1.h - Simple ASCII based home automation protocol v1

    Created by Sergey Syrota, December 29, 2013.
*/

#ifndef SyrotaAutomation_h
#define SyrotaAutomation_h

#include <Arduino.h>

class SyrotaAutomation
{
public:
    SyrotaAutomation(int modePinNum);
    char deviceID[16]; // This device's ID, so that packets are being read that are addressed here
    boolean messageReceived(); // listens to the bus, and gets the message if there is transimission going, returning true. False if nothing is detected.
    void sendResponse(char *raw); // Sends raw response string
    boolean assertCommand(char *command); // compares if command in parameters matches command in buffer
    boolean assertCommandStarts(char *command, char *paramString); // compares if command in buffer starts with what's passed in parameters
    void responseStart(); // Sends response headers
    void responseSendPart(char *raw); // Sends response packet. If response has not been started, it will do that first.
    void responseEnd(); // Finishes response, and waits for all bytes to flush

private:
    char buffer[128]; // Buffer of received messages so far
    int modePin;
    bool responseStarted; // Flag if response has been started or not
    void(*callback)(char*, char*);
};

#endif
