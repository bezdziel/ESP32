#include "Program.h"

using namespace MicroController;

Program *program;

void setup() {
  program = new Program();

  program->Start();
}

void loop() {
    program->Loop();
}