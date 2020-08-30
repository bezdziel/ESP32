#include "OledDisplay.h"

namespace MicroController
{
    OledDisplay::OledDisplay() {
        display = new Adafruit_SSD1306(AppSettings::ScreenWidth, AppSettings::ScreenHeight,
								AppSettings::OLED_MOSI, AppSettings::OLED_CLK, 
								AppSettings::OLED_DC, AppSettings::OLED_RESET, AppSettings::OLED_CS);
    }

    OledDisplay::~OledDisplay() {
        delete display;
    }

    void OledDisplay::Setup() {
        if(!display->begin(SSD1306_SWITCHCAPVCC)) {
            Serial.println(F("SSD1306 allocation failed"));
            for(;;); // Don't proceed, loop forever
        }

        display->clearDisplay();
        display->setTextSize(1);
        display->setTextColor(SSD1306_WHITE);
        display->setCursor(0, 0);
        display->cp437(true);
    }

    void OledDisplay::Print(string text, int cursorX, int cursorY) {
        ClearLine(cursorX);
        display->setCursor(cursorX, cursorY);
        display->print(text.c_str());
        display->display();
    }

    void OledDisplay::Print(string text) {
        ClearLine();
        display->setCursor(0, currentLine * 8);
        display->print(text.c_str());
        display->display();
    }

    void OledDisplay::Print(string text, int line) {
        ClearLine(line);
        display->setCursor(0, line * 8);
        display->print(text.c_str());
        display->display();
    }

    void OledDisplay::SetLine(int line) {
        currentLine = line;
    }

    void OledDisplay::Clear() {
        display->clearDisplay();
    }

    void OledDisplay::ClearLine(int line) {
        int pixel = line * 8;
        display->setCursor(0, pixel);
        for(int i = 0; i < 8; i++) {
            display->drawLine(0, pixel+i, AppSettings::ScreenWidth, pixel+i, SSD1306_BLACK);
        }
        display->display();
    }

    void OledDisplay::ClearLine() {
        int pixel = currentLine * 8;
        display->setCursor(0, pixel);
        for(int i = 0; i < 8; i++) {
            display->drawLine(0, pixel+i, AppSettings::ScreenWidth, pixel+i, SSD1306_BLACK);
        }
        display->display();
    }
}
