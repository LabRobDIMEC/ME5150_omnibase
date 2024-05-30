// Encoder.cpp
#include "Encoder.h"

Encoder::Encoder(int a, int b) : pinA(a), pinB(b), position(0), lastAState(LOW) {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
}

void Encoder::updateA() {
    int currentA = digitalRead(pinA);
    int currentB = digitalRead(pinB);
    unsigned long startTime = micros();
    if (currentA != lastAState) {
        lastAState = currentA;
        if (currentA == currentB) {
            position++;
        } else {
            position--;
        }
    }
}

void Encoder::updateB() {
    int currentA = digitalRead(pinA);
    int currentB = digitalRead(pinB);
    if (currentA != currentB) {
        position++;
    } else {
        position--;
    }
}
