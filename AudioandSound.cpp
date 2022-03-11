#include "AudioandSound.h"
void PlayOpenningSound()
{
	PlaySound(TEXT("test audio c++.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cin.ignore();
}