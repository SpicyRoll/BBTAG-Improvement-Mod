#include "update_check.h"

#include "url_downloader.h"

#include "Core/logger.h"
#include "Core/info.h"
#include "WindowManager/WindowManager.h"

#include <regex>

std::string newVersionNum = "";

std::string GetNewVersionNum()
{
	if (newVersionNum != "")
		return newVersionNum;
	else
		return "";
}

void CheckUpdate()
{
	std::wstring wUrl = MOD_LINK_FORUM;
	std::string data = DownloadUrl(wUrl);

	if (strcmp(data.c_str(), "") == 0)
	{
		WindowManager::AddLog("[error] Update check failed. No data downloaded.\n");
		LOG(2, "Update check failed.No data downloaded.\n");
		return;
	}

	data = data.substr(0, 950).c_str();

	//fits on: <title>[BBTAG IMPROVEMENT MOD] (v1.03
	//and captures: v1.03
	std::regex r("<title>.+(v\\d\.\\d\\d)");
	std::smatch m;
	std::regex_search(data, m, r);

	if (m[1].str() == "")
	{
		WindowManager::AddLog("[error] Update check failed. Regex no match.\n");
		return;
	}

	if (strcmp(m[1].str().c_str(), MOD_VERSION_NUM) != 0)
	{
		newVersionNum = m[1].str();
		LOG(2, "New version found: %s\n", newVersionNum.c_str());
		WindowManager::AddLog("[system] Update available: BBTAG Improvement Mod %s has been released!\n", newVersionNum.c_str());
		WindowManager::IsUpdateAvailable = true;
	}
	else
	{
		WindowManager::AddLog("[system] BBTAG Improvement Mod is up-to-date\n");
	}
}