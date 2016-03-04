#pragma once
#include "SFML\Graphics.hpp"
#include "rapidjson\document.h"
#include "rapidjson\reader.h"
#include "rapidjson\filereadstream.h"
#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include "Asset.h"

using namespace std;
using namespace sf;
using namespace rapidjson;


struct LoadException : public std::exception
{
	std::string s;
	LoadException(std::string ss) : s(ss) { printf(s.c_str()); }
	~LoadException() throw () {} 
	const char* what() const throw() {  return s.c_str(); }
};

inline bool fileExists(const std::string& name) {
	ifstream f(name.c_str());
	if (f.good()) {
		f.close();
		return true;
	}
	else {
		f.close();
		return false;
	}
}

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

	void loadSounds(string soundDataDir, FMOD::System * fmodSys);
	void loadAnimations(string animDataDir);
	void loadTextures(string imgDataDir);
	void addAssetToQueue(Asset* asset);
	void loadAssetQueue();
	void loadAsset(Asset* asset);


	string getLoadingAsset();
	int getNumLoaded();
	int getNumToLoad();
protected:
	vector<pair <string, vector<sf::IntRect>>>  findMetaDateByKey(string key);
	void addToImageCache(string name, string _textureFilePath);
	void addToMetaCache(string name, const char * _jsonFilePath);
	AssetLoader();
	static AssetLoader * instance;
	map<string, Texture *>  imageCache;
	map<string, vector<pair <string, vector<sf::IntRect>>> > metaCache;
	map<string, FMOD::Sound *> soundCache;

	vector<Asset*> assetQueue;

	FMOD::System *FMODsys;

	int m_assetsLoaded;
	string m_currentAsset;
};

