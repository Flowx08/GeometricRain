
//====================

//====================
#include "ResourcesManager.hpp"
//#ifdef __APPLE__
//#include "WrapperOSX.h"
//#endif


//////////////////////////////////////////////////////////////
ResourcesManager::ResourcesManager() {}

//////////////////////////////////////////////////////////////
ResourcesManager::~ResourcesManager() {}

//////////////////////////////////////////////////////////////
std::string ResourcesManager::GetResourcePath()
{
	std::string path = "res/";
//#ifdef __APPLE__
//	path = wrResourcePath();
//#endif
	return path;
}

//////////////////////////////////////////////////////////////
void ResourcesManager::LoadTexture(const std::string tablename, const std::string path)
{
	_TexturesTable[tablename].loadFromFile(GetResourcePath() + path);
}

//////////////////////////////////////////////////////////////
sf::Texture& ResourcesManager::GetTexture(const std::string tablename)
{
	return _TexturesTable[tablename];
}

//////////////////////////////////////////////////////////////
void ResourcesManager::LoadFont(const std::string tablename, const std::string path)
{
	_FontTable[tablename].loadFromFile(GetResourcePath() + path);
}

//////////////////////////////////////////////////////////////
sf::Font& ResourcesManager::GetFont(const std::string tablename)
{
	return _FontTable[tablename];
}

//////////////////////////////////////////////////////////////
void ResourcesManager::LoadShader(const std::string tablename, const std::string path,
		const sf::Shader::Type type)
{
	_ShaderTable[tablename].loadFromFile(GetResourcePath() + path, type);
}

//////////////////////////////////////////////////////////////
sf::Shader& ResourcesManager::GetShader(const std::string tablename)
{
	return _ShaderTable[tablename];
}

//////////////////////////////////////////////////////////////
void ResourcesManager::LoadSoundBuffer(const std::string tablename, const std::string path)
{
	_SoundTable[tablename].loadFromFile((GetResourcePath() + path).c_str());
}

//////////////////////////////////////////////////////////////
sf::SoundBuffer& ResourcesManager::GetSoundBuffer(const std::string tablename)
{
	return _SoundTable[tablename];
}

////////////////////////////////////////////////
void ResourcesManager::UnloadAll()
{
	_TexturesTable.clear();
	_FontTable.clear();
	_ShaderTable.clear();
	_SoundTable.clear();
}
