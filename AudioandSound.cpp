#include "audioandSound.h"
void playOpeningSound()
{
	PlaySound(TEXT("Opening.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void audioUpScore()
{
	PlaySound(TEXT("levelup.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void audioGameOver()
{
	PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void audioNewLevel()
{
	PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void audioBanLaNhat()
{
	PlaySound(TEXT("winning.wav"), NULL, SND_FILENAME | SND_ASYNC);
}