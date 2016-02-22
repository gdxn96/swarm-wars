#include "stdafx.h"
#include "AudioMgr.h"
#include <iostream>
#include "AssetLoader.h"

AudioManager * AudioManager::m_instance = nullptr;

AudioManager::AudioManager() : playFX(true)
{
	result = FMOD::System_Create(&FMODsys);
	FMODsys->init(100, FMOD_INIT_NORMAL, 0);
}

void AudioManager::Update(Vector2D playerPos, Vector2D playerVel)
{
	FMOD_VECTOR  listenervel = { playerVel.x, 0.0f, playerVel.y };
	FMOD_VECTOR  listenerpos = { playerPos.x, 0.0f, playerPos.y };
	FMODsys->set3DListenerAttributes(0, &listenerpos, &listenervel, 0, 0);
	
	FMOD_VECTOR  pos = { 0, 0, 0 };
	channel3D->set3DAttributes(&pos, 0);
	channel3D->set3DConeOrientation(&listenervel);
	FMODsys->update();
}


AudioManager *  AudioManager::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new AudioManager();
	}
	return m_instance;
}

void AudioManager::PlayGameSound(string _soundName, bool _startPaused, float _volume , Vector2D _sourcePos,int loopAmount)
{

	if (playFX)
	{
		FMOD_VECTOR  sourcePos = { _sourcePos.x, 0.0f, _sourcePos.y };
		FMOD::Channel *channel = channel3D;
		
		FMODsys->playSound(
			FMOD_CHANNEL_FREE, //find a free channel
			AssetLoader::getInstance()->findSoundByKey(_soundName),        //sound to play
			_startPaused,              //start paused
			&channel);
		channel->set3DAttributes(&sourcePos, 0);
		channel->set3DMinMaxDistance(15000, 30000);
		channel->setVolume(_volume);
	}
}

