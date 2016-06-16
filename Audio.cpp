#include "Audio.h"
Audio::Audio() 
{
	bgMusic;
	bulletSound;

};

bool Audio::LoadAudioMedia()
{
	//success check
	bool successful = true;

	//bg music
	bgMusic = Mix_LoadMUS("resources/Audio/Weretheresistors.mp3");
	if (bgMusic == nullptr) {
		printf("music failed to load! SDL Error: %s\n", Mix_GetError());
		successful = false;
	}
	
	//bullet sound.
	bulletSound = Mix_LoadWAV("resources/Audio/bulletSound.wav");
	if (bulletSound == nullptr) {
		printf("bulletsound failed to load. SDLError: %s\n", Mix_GetError());
		successful = false;
	}


	return successful;
}

//Mix_Music Audio::GetBGMusic() 
//{
//	
//};

Mix_Chunk* Audio::GetShootSound() 
{

	return bulletSound;
};
