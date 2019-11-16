#pragma once
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>

class AnimicProjectStructure //custom file format
{
public:
#pragma region Scene structures
	typedef struct {
		float x;
		float y;
		int zindex;

	}Vector3;

	typedef struct {
		Vector3 coords;
		

	}ProjectVideo;

	typedef struct {
		Vector3 coords;
		const char* imagePath;

	}ProjectImage;

	typedef struct {
		Vector3 coords;
		boolean orientation; //true horizontal, false vertical
		boolean startingSide; //true left, false right;
		unsigned int fontsize;


	}ProjectDialogue;

	typedef struct {
		Vector3 coords;
		std::string audioPath;
		float playbackspeed;

	}ProjectAudio;

	typedef struct {
		std::queue<ProjectVideo> videoList;
		std::queue<ProjectImage> imageList;
		std::queue<ProjectDialogue> dialogueList;
		std::queue<ProjectAudio> audioList[];

	}ProjectScene;

	typedef struct {

	}ProjectTimeline;

	typedef struct {
		std::queue<ProjectScene> sceneList;

	}ProjectSceneManagement;

#pragma endregion Contains all scene related data structures

#pragma region	Asset Structure
	typedef struct {
		std::string videoName;
		std::string videoFormat;
		std::string videoPath;
		unsigned int videoSize; //size in bytes
		unsigned int bitrate;
		
	}AssetVideo;

	typedef struct {
		std::string audioName;
		std::string audioFormat;
		std::string audioPath;
		unsigned int audioSize; //size in bytes
		unsigned int bitrate;

	}AssetAudio;

	typedef struct {
		std::string dialogueName;
		std::string dialogueText;
		bool dialogueOrientation; //true horizontal, false vertical
		bool dialogueStartSide; //true left, false right
		unsigned int dialogueSize; //size in bytes

	}AssetDialogue;

	typedef struct {
		std::string textName;
		std::string textContent;
		unsigned int textSize;

	}AssetText;

	typedef struct {
		//include directory here
		std::queue<AssetVideo> videoAssetList;
		std::queue<AssetAudio> audioAssetList;
		std::queue<AssetDialogue> dialogueAssetList;
		std::queue<AssetText> textAssetList;

	}ProjectAssetManagement;

#pragma endregion	Contains all asset related structures

#pragma region	Overall Structure
	struct projectStructure {		//main project structure
		
		const char* magicHeader = { "Animic_Project" };
		unsigned short majorVersion = 1;
		unsigned short medVersion = 0;
		unsigned short minorVersion = 1;

		//include everything else here
	};
#pragma endregion	Contains all overall program data structures

};

