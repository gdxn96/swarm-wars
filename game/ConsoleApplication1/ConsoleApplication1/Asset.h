#pragma once
#include <string>
#include <functional>

using namespace std;

struct Asset
{
public:
	Asset(string key) : m_key(key)
	{
		
	}

	virtual string getKey()
	{
		return m_key;
	}
	
protected:
	string m_key;
	
};

struct AnimationData : Asset
{
	AnimationData(string key, string textureDir, string metadataDir) : Asset(key), m_textureDir(textureDir), m_metadataDir(metadataDir)
	{

	}

	string m_textureDir, m_metadataDir;
};

struct SpriteData : Asset
{
	SpriteData(string key, string textureDir) : Asset(key), m_textureDir(textureDir)
	{

	}

	string m_textureDir;
};

struct Sound : Asset
{
	Sound(string key, string soundDir, bool isLooping) : Asset(key), m_soundDir(soundDir), m_isLooping(isLooping)
	{

	}

	string m_soundDir;
	bool m_isLooping;
};


