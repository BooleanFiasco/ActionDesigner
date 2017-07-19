// Copyright 2017 Norm Nazaroff.

#include "ActionDesignerEditor.h"
#include "ActionBlueprint.h"
#include "ActionGraphBlueprint.h"
#include "ActionBlueprintThumbnailRenderer.h"
#include "ActionGraphBlueprintThumbnailRenderer.h"
#include "ActionBlueprintAssetTypeActions.h"
#include "ActionGraphBlueprintAssetTypeActions.h"
#include "ActionInstance.h"


class FActionDesignerEditorModule : public IActionDesignerEditorModule
{
public:
	FActionDesignerEditorModule();

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

IMPLEMENT_GAME_MODULE(FActionDesignerEditorModule, ActionDesignerEditor);
DEFINE_LOG_CATEGORY(ActionDesignerEditorLog)
#define LOCTEXT_NAMESPACE "ActionDesignerEditor"

FActionDesignerEditorModule::FActionDesignerEditorModule()
	: AssetCategoryAction(EAssetTypeCategories::Misc), AssetCategoryActionGraph(EAssetTypeCategories::Misc)
{
}

void FActionDesignerEditorModule::StartupModule()
{
	UE_LOG(ActionDesignerEditorLog, Log, TEXT("Action designer editor module loaded."));
	UThumbnailManager::Get().RegisterCustomRenderer(UActionBlueprint::StaticClass(), UActionBlueprintThumbnailRenderer::StaticClass());
	UThumbnailManager::Get().RegisterCustomRenderer(UActionGraphBlueprint::StaticClass(), UActionGraphBlueprintThumbnailRenderer::StaticClass());

	// Register asset types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	AssetCategoryAction = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("ActionDesigner")), LOCTEXT("ActionDesignerCategory", "Action Designer"));
	AssetCategoryActionGraph = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("ActionDesigner")), LOCTEXT("ActionDesignerCategory", "Action Designer"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FActionBlueprintAssetTypeActions(AssetCategoryAction)));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FActionGraphBlueprintAssetTypeActions(AssetCategoryActionGraph)));
}

void FActionDesignerEditorModule::ShutdownModule()
{
	UE_LOG(ActionDesignerEditorLog, Log, TEXT("Action designer editor module unloaded."));
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

void FActionDesignerEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE
