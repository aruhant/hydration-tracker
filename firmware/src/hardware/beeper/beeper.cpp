#include "Beeper.h"

Buzzer Beeper::buzzer = Buzzer();

Buzzer::Melody_t Beeper::melody1{
    .nbNotes = 3,
    .duration = {40, 40, 80},
    .frequency = {D4_NOTE_FREQ, E4_NOTE_FREQ, G4_NOTE_FREQ}};
void Beeper::setup()
{
    buzzer.init(BEEPER_PIN);
}

void Beeper::loop()
{
    buzzer.step();
}

#ifdef TEST_FLAG
Buzzer::Melody_t Beeper::melodyTest{
    .nbNotes = 2,
    .duration = {10, 15},
    .frequency = {D4_NOTE_FREQ, G4_NOTE_FREQ}};

void Beeper::test()
{
    buzzer.setMelody(&melodyTest);
}
#endif
