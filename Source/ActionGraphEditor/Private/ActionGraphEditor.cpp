// Copyright 2017 Norm Nazaroff.

#include "IActionGraphEditor.h"
#include "ActionBlueprint.h"
#include "ActionGraphBlueprint.h"
#include "ActionBlueprintThumbnailRenderer.h"
#include "ActionGraphBlueprintThumbnailRenderer.h"
#include "ActionBlueprintAssetTypeActions.h"
#include "ActionGraphBlueprintAssetTypeActions.h"


class FActionGraphEditorModule : public IActionGraphEditorModule
{
public:
	FActionGraphEditorModule();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

	/** All created asset type actions.  Cached here so that we can unregister them during shutdown. */
	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

	EAssetTypeCategories::Type AssetCategoryAction;
	EAssetTypeCategories::Type AssetCategoryActionGraph;

private:

	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);
};

IMPLEMENT_GAME_MODULE(FActionGraphEditorModule, ActionGraphEditor);
DEFINE_LOG_CATEGORY(ActionGraphEditorLog)
#define LOCTEXT_NAMESPACE "ActionGraphEditor"

FActionGraphEditorModule::FActionGraphEditorModule()
	: AssetCategoryAction(EAssetTypeCategories::Misc), AssetCategoryActionGraph(EAssetTypeCategories::Misc)
{
}

void FActionGraphEditorModule::StartupModule()
{
	UE_LOG(ActionGraphEditorLog, Log, TEXT("Action graph editor module loaded."));
	UThumbnailManager::Get().RegisterCustomRenderer(UActionBlueprint::StaticClass(), UActionBlueprintThumbnailRenderer::StaticClass());
	UThumbnailManager::Get().RegisterCustomRenderer(UActionGraphBlueprint::StaticClass(), UActionGraphBlueprintThumbnailRenderer::StaticClass());

	// Register asset types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	AssetCategoryAction = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("ActionDesigner")), LOCTEXT("ActionDesignerCategory", "Action Designer"));
	AssetCategoryActionGraph = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("ActionDesigner")), LOCTEXT("ActionDesignerCategory", "Action Designer"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FActionBlueprintAssetTypeActions(AssetCategoryAction)));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FActionGraphBlueprintAssetTypeActions(AssetCategoryActionGraph)));
}

void FActionGraphEditorModule::ShutdownModule()
{
	UE_LOG(ActionGraphEditorLog, Log, TEXT("Action graph editor module unloaded."));
	if (UObjectInitialized())
	{
		UThumbnailManager::Get().UnregisterCustomRenderer(UActionBlueprint::StaticClass());
		UThumbnailManager::Get().UnregisterCustomRenderer(UActionGraphBlueprint::StaticClass());
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
	CreatedAssetTypeActions.Empty();
}

void FActionGraphEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE
