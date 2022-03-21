#include "AudioandSound.h"
void PlayOpeningSound()
{
	PlaySound(TEXT("Opening.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void AudioUpScore()
{
	PlaySound(TEXT("levelup.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void AudioGameOver()
{
	PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void AudioNewLevel()
{
	PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
}