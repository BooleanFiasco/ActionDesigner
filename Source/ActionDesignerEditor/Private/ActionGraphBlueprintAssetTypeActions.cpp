// Copyright 2017 Isaac Hsu.

#include "ActionDesignerEditor.h"

#include "ActionGraphBlueprintAssetTypeActions.h"
#include "ActionGraphBlueprint.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

//////////////////////////////////////////////////////////////////////////
// FInputCommandAssetTypeActions

FActionGraphBlueprintAssetTypeActions::FActionGraphBlueprintAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FText FActionGraphBlueprintAssetTypeActions::GetName() const
{
	return LOCTEXT("FActionGraphBlueprintAssetTypeActionsName", "Action Graph");
}

FColor FActionGraphBlueprintAssetTypeActions::GetTypeColor() const
{
	return FColor(196, 129, 115);
}

UClass* FActionGraphBlueprintAssetTypeActions::GetSupportedClass() const
{
	return UActionGraphBlueprint::StaticClass();
}

uint32 FActionGraphBlueprintAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE