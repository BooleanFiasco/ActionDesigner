// Copyright 2017 Norm Nazaroff.

#pragma once

#include "Engine.h"
#include "ModuleManager.h"
#include "UnrealEd.h"
#include "IAssetTools.h"
#include "IAssetTypeActions.h"
#include "AssetTypeCategories.h"

DECLARE_LOG_CATEGORY_EXTERN(ActionGraphEditorLog, All, All)

class IActionGraphEditorModule : public IModuleInterface
{
public:

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline IActionGraphEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IActionGraphEditorModule>("ActionGraphEditor");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ActionGraphEditor");
	}
};
