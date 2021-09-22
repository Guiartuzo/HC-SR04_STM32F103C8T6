#ifndef HC_SR04_H
#define HC_SR04_H

// --------------------------- protótipos das funções do sensor ----------------------

void gpioConfig();
void timerConfig();
int StartReading();
void SystickDelayUs(int n);
void SystickDelayMs(int n);

// --------------------------- fim dos protótipos das funções do sensor ----------------------

#endif