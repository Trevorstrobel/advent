#pragma once
#include <SDL_mixer.h>
#include <iostream>


class Audio {
	
public:
	Audio();

	bool LoadAudioMedia();
	//Mix_Music GetBGMusic();
	Mix_Chunk* GetShootSound();
	
	Mix_Music *bgMusic;
	Mix_Chunk *bulletSound;


private:

	
};