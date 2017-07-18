// Copyright 2017 Norm Nazaroff.

#include "IActionGraphEditor.h"
#include "IActionGraph.h"
//#include "InputCommandThumbnailRenderer.h"
//#include "InputCommandAssetTypeActions.h"

class FActionGraphEditorModule : public IActionGraphEditorModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_GAME_MODULE(FActionGraphEditorModule, ActionGraphEditor);
DEFINE_LOG_CATEGORY(ActionGraphEditorLog)
#define LOCTEXT_NAMESPACE "ActionGraphEditor"

/*FInputBufferEditorModule::FInputBufferEditorModule()
	: AssetCategoryBit(EAssetTypeCategories::Misc)
{
}*/

void FActionGraphEditorModule::StartupModule()
{
	UE_LOG(ActionGraphEditorLog, Log, TEXT("Action graph editor module loaded."));
	/*UThumbnailManager::Get().RegisterCustomRenderer(UInputCommand::StaticClass(), UInputCommandThumbnailRenderer::StaticClass());

	// Register asset types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Input")), LOCTEXT("InputCategory", "Input"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FInputCommandAssetTypeActions(AssetCategoryBit)));*/
}

void FActionGraphEditorModule::ShutdownModule()
{
	UE_LOG(ActionGraphEditorLog, Log, TEXT("Action graph editor module unloaded."));
	/*if (UObjectInitialized())
	{
		UThumbnailManager::Get().UnregisterCustomRenderer(UInputCommand::StaticClass());
	}

	// Unregister all the asset types that we registered
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();*/
}

/*void FActionGraphEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}*/

#undef LOCTEXT_NAMESPACE
