#pragma once

#include <Adafruit_SSD1306.h>
#include "Settings/AppSettings.h"

namespace MicroController
{
	class OledDisplay
	{
	public:
		OledDisplay();
		~OledDisplay();
		void Setup();
		void Print(string text);
		void Print(string text, int cursorX, int cursorY);
		void Print(string text, int);
		void SetLine(int line);
		void ClearLine(int line);
		void ClearLine();
		void Clear();
	private:
		int currentLine = 0;
		Adafruit_SSD1306 *display;
	};
}
