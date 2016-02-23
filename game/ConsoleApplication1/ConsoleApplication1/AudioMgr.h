#pragma once
#pragma comment(lib,"fmodex_vc.lib")
#include "fmod.hpp"
#include "fmod_errors.h"
#include "Vector2D.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

class AudioManager
{
private:

	static AudioManager * m_instance;

	FMOD::Sound * background;
	FMOD::Sound * footstep;
	FMOD::Sound * plasma;
	FMOD::Sound * miss;
	FMOD::Sound * hit;
	FMOD::Sound * zun;
	FMOD::Sound * growl;
	FMOD::Sound * oof;
	
	FMOD_RESULT result;

	FMOD::Channel * channel3D;
	bool playFX;
	AudioManager();
	float volume;
	bool playMusic;
public:
	FMOD::System *FMODsys;
	static AudioManager *  instance();
	void Update();
	void PlayGameSound(std::string _soundName, bool _startPaused, float _volume, Vector2D sourcePos,int loopAmount);
	void toggleFX()
	{
		playFX = !playFX;
	}
	void setVolume(float);
	float getVolume();
	void resetVolume();
	void toggleMusic()
	{
		playMusic = !playMusic;
	}
};

