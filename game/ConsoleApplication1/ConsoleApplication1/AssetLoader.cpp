#include "stdafx.h"
#include "AssetLoader.h"


AssetLoader * AssetLoader::instance = nullptr;
AssetLoader::AssetLoader()
{
}

void AssetLoader::loadSounds(string soundDataDir, FMOD::System * fmodSys)
{
	string key, soundPath, looping;
	ifstream myFile;
	myFile.open(soundDataDir);
	FMODsys = fmodSys;

	while (myFile >> key >> soundPath >> looping)
	{			
		this->addAssetToQueue(new Sound(key, soundPath, stoi(looping)));
	}
}

void AssetLoader::addAssetToQueue(Asset* asset)
{
	this->assetQueue.push_back(asset);
}

void AssetLoader::loadAssetQueue()
{
	for (auto& asset : assetQueue)
	{
		loadAsset(asset);
	}
}

void AssetLoader::loadAsset(Asset* asset)
{
	Sound* soundAsset = dynamic_cast<Sound*>(asset);
	AnimationData* animAsset = dynamic_cast<AnimationData*>(asset);
	SpriteData* spriteAsset = dynamic_cast<SpriteData*>(asset);

	m_currentAsset = asset->getKey();
	m_assetsLoaded++;

	if (soundAsset)
	{
		addSoundToCache(soundAsset->getKey(), soundAsset->m_soundDir.c_str(), FMODsys, soundAsset->m_isLooping);

	}
	else if (animAsset)
	{
		addAnimationToCache(animAsset->getKey(), animAsset->m_textureDir, animAsset->m_metadataDir.c_str());
	}
	else
	{
		addTextureToCache(spriteAsset->getKey(), spriteAsset->m_textureDir);
	}
}


void AssetLoader::loadTextures(string imgDataDir)
{
	string key, imgPath;
	ifstream myFile;
	myFile.open(imgDataDir);

	while (myFile >> key >> imgPath)
	{
		this->addAssetToQueue(new SpriteData(key, imgPath));
	}
	
}

void AssetLoader::loadAnimations(string animDataDir)
{
	string key, spriteSheet, meta;
	ifstream myFile;
	myFile.open(animDataDir);

	while (myFile >> key >> spriteSheet >> meta)
	{
		this->addAssetToQueue(new AnimationData(key, spriteSheet, meta));
	}
}

AssetLoader * AssetLoader::getInstance()
{
	if (instance == nullptr)
	{
		instance = new AssetLoader;
	}
	return instance;
}

void AssetLoader::addAnimationToCache(string name, string _textureFilePAth, const char * _jsonFilePath)
{
	addToImageCache(name, _textureFilePAth);
	addToMetaCache(name, _jsonFilePath);
}

pair<Texture *, vector<pair <string, vector<sf::IntRect>>>> AssetLoader::findAnimationByKey(string key)
{
	pair<Texture *, vector<pair <string, vector<sf::IntRect>>>> temp;
	temp.first = findTextureByKey(key);
	temp.second = findMetaDateByKey(key);
	return temp;
}

void AssetLoader::addTextureToCache(string name, string _textureFilePath)
{
	sf::Texture * temp = new Texture;

	if (!fileExists(_textureFilePath))
	{
		throw(LoadException("Texture " + name + " could not be loaded from " + _textureFilePath));
	}
	if (!temp->loadFromFile(_textureFilePath))
	{
		
		//printf("error, failed to load image: %f \n", _textureFilePath);
	}
	imageCache[name] = temp;
	std::cout << "Loading Texture : " << name << endl;
}

void AssetLoader::addSoundToCache(string name, const char * _soundFilePath, FMOD::System *FMODsys,bool isLooping)
{
	FMOD::Sound * temp;

	if (!fileExists(_soundFilePath))
	{
		throw(LoadException("Sound " + name + " at " + _soundFilePath + " could not be loaded"));
	}
	if (!isLooping)
	{
		FMODsys->createStream(_soundFilePath, FMOD_3D, 0, &temp);
		soundCache[name] = temp;
	}
	else
	{
		FMODsys->createStream(_soundFilePath, FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &temp);
		soundCache[name] = temp;
	}
}

string AssetLoader::getLoadingAsset()
{
	return m_currentAsset;
}

int AssetLoader::getNumLoaded()
{
	return m_assetsLoaded;
}

int AssetLoader::getNumToLoad()
{
	return assetQueue.size();
}

void AssetLoader::addToImageCache(string name, string _textureFilePath)
{
	sf::Texture * temp = new Texture;
	if (!temp->loadFromFile(_textureFilePath))
	{
		throw(LoadException("Texture " + name + " could not be loaded from " + _textureFilePath));
	}
	imageCache[name] = temp;
}

void AssetLoader::addToMetaCache(string name, const char * _jsonFilePath)
{
	if (!fileExists(_jsonFilePath))
	{
		throw(LoadException("Metadata does not exist for " + name + " at " + _jsonFilePath));
	}

	vector<pair <string, vector<sf::IntRect>>>  animationList;
	FILE* fp = fopen(_jsonFilePath, "rb");
	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document d;
	d.ParseStream(is);
	fclose(fp);
	Value::MemberIterator itrM;
	const Value& V = d;
	for (Value::ConstMemberIterator iter = V.MemberBegin(); iter != V.MemberEnd(); ++iter){
		printf("%s \n", iter->name.GetString());
		pair <string, vector<sf::IntRect>> temp;
		temp.first = iter->name.GetString();
		for (SizeType i = 0; i < d[iter->name.GetString()].Size(); i++){
			temp.second.push_back(sf::IntRect(d[iter->name.GetString()][i]["x"].GetDouble(), d[iter->name.GetString()][i]["y"].GetDouble(), d[iter->name.GetString()][i]["width"].GetDouble(), d[iter->name.GetString()][i]["height"].GetDouble()));
		}
		animationList.push_back(temp);
	}
	metaCache[name] = animationList;

	
}


bool AssetLoader::exists(string key)
{
	auto it = imageCache.find(key);
	if (it != imageCache.end())
	{
		return true;
	}
	return false;
}

void AssetLoader::emptyMap()
{
	imageCache.clear();
}

Texture * AssetLoader::findTextureByKey(string key)
{
	auto it = imageCache.find(key);
	if (it != imageCache.end())
	{
		return it->second;
	}
	else
	{
		cout << " key not in texture map : " << key << endl;
	}
	
}
vector<pair <string, vector<sf::IntRect>>> AssetLoader::findMetaDateByKey(string key)
{
	auto it =  metaCache.find(key);
	if (it !=  metaCache.end())
	{
		return it->second;
	}
	else
	{
		cout << "key not in map, sound key : " << key << endl;
	}
}

FMOD::Sound * AssetLoader::findSoundByKey(string key)
{
	auto it = soundCache.find(key);
	if (it != soundCache.end())
	{
		return it->second;
	}
	else
	{
		cout << "key not in map, sound key : " << key << endl;
	}
}

AssetLoader::~AssetLoader()
{
}


