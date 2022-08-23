#ifndef _TASK1_H_
#define _TASK1_H_

void task1();


    
    
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT
    };
    static Task1States task1State = Task1States::INIT;

    static uint32_t lasTime = 0;

   

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
   

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        
        pinMode(ledRed, OUTPUT);
       
        lasTime = millis();
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
        uint8_t btn1State = digitalRead(button1Pin);
        uint8_t btn2State = digitalRead(button2Pin);
        
        uint32_t currentTime = millis();

        // Evento 1:
        if ((currentTime - lasTime) >= INTERVAL){
        {
            lasTime = currentTime;
            printf("btn1: %d,btn2: %d, btn3: %d, btn4: %d\n", btn1State, btn2State, btn3State, btn4State);
        }

        // Evento 2
        if (btn1State == LOW){
            digitalWrite(ledRed, HIGH);}
        // Evento 3
        if (btn2State == LOW){            
            digitalWrite(ledGreen, HIGH);}
        // Evento 4
        if (btn3State == LOW){
            digitalWrite(ledBlue, HIGH);}
       

        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}


#endif