#pragma once

#include "Core/Serializer.h"
#include "_generated/serializer/all_serializer.h"
#include "_generated/specialClass/allSpecialClass.h"

#include <filesystem>
#include <sstream>

NS_JYE_BEGIN

class AssetManager
{
public:
	template<typename AssetType>
	static bool LoadAsset(const std::string& asset_url, AssetType& out_asset)
	{
		// read json file to string
		std::filesystem::path asset_path = std::string(asset_url.c_str());
		std::ifstream asset_json_file(asset_path);
		if (!asset_json_file)
		{
			return false;
		}

		std::stringstream buffer;
		buffer << asset_json_file.rdbuf();
		std::string asset_json_text(buffer.str());

		// parse to json object and read to runtime res object
		std::string error;
		auto&& asset_json = Json::parse(asset_json_text, error);
		if (!error.empty())
		{
			return false;
		}

		Serializer ser;
		ser.DeSerializerObject(asset_json, out_asset);
		return true;
	}

	template<typename AssetType>
	static bool SaveAsset(AssetType& out_asset, const std::string& asset_url)
	{
		std::ofstream asset_json_file(asset_url.c_str());
		if (!asset_json_file)
		{
			return false;
		}

		// write to json object and dump to string
		Serializer ser;
		auto&& asset_json = ser.SerializerObject(out_asset);
		std::string&& asset_json_text = asset_json.dump();

		// write to file
		asset_json_file << asset_json_text;
		asset_json_file.flush();

		return true;
	}

};
NS_JYE_END