#ifndef HC_SR04_H
#define HC_SR04_H

// --------------------------- prot�tipos das fun��es do sensor ----------------------

void gpioConfig();
void timerConfig();
int StartReading();
void SystickDelayUs(int n);
void SystickDelayMs(int n);

// --------------------------- fim dos prot�tipos das fun��es do sensor ----------------------

#endif