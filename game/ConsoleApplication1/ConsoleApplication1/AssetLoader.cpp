#include "stdafx.h"
#include "AssetLoader.h"


AssetLoader * AssetLoader::instance = nullptr;
AssetLoader::AssetLoader()
{
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
	if (!temp->loadFromFile(_textureFilePath))
	{
		printf("error, failed to load image: %f \n", _textureFilePath);
	}
	imageCache[name] = temp;
	std::cout << "Loading Texture : " << name << endl;
}

void AssetLoader::addSoundToCache(string name, const char * _soundFilePath, FMOD::System *FMODsys,bool isLooping)
{
	FMOD::Sound * temp;
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

void AssetLoader::addToImageCache(string name, string _textureFilePath)
{
	sf::Texture * temp = new Texture;
	if (!temp->loadFromFile(_textureFilePath))
	{
		printf("error, failed to load image: %f \n", _textureFilePath);
	}
	imageCache[name] = temp;
}

void AssetLoader::addToMetaCache(string name, const char * _jsonFilePath)
{
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
	metaCache[name] =  animationList ;
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
		printf("error finding value, not in the map");
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
		printf("error finding value, not in the map, meta error");
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
		printf("error finding value, not in the map, sound error");
	}
}

AssetLoader::~AssetLoader()
{
}


