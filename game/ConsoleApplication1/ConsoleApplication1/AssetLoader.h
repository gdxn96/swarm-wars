#pragma once
#include "SFML\Graphics.hpp"
#include "rapidjson\document.h"
#include "rapidjson\reader.h"
#include "rapidjson\filereadstream.h"
#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"

using namespace std;
using namespace sf;
using namespace rapidjson;
class AssetLoader
{
public:
	static AssetLoader * getInstance();
	~AssetLoader();
	bool exists(string key);
	void emptyMap();
	void addAnimationToCache(string name, string _textureFilePAth , const char * _jsonFilePath);
	void addTextureToCache(string name, string _textureFilePath);
	void addSoundToCache(string name, const char * _soundFilePath, FMOD::System *FMODsys,bool isLooping);
	pair<Texture *, vector<pair <string, vector<sf::IntRect>>>> findAnimationByKey(string key);
	Texture * findTextureByKey(string key);
	FMOD::Sound * findSoundByKey(string key);
protected:
	vector<pair <string, vector<sf::IntRect>>>  findMetaDateByKey(string key);
	void addToImageCache(string name, string _textureFilePath);
	void addToMetaCache(string name, const char * _jsonFilePath);
	AssetLoader();
	static AssetLoader * instance;
	map<string, Texture *>  imageCache;
	map<string, vector<pair <string, vector<sf::IntRect>>> > metaCache;
	map<string, FMOD::Sound *> soundCache;
};

