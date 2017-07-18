// Copyright 2017 Isaac Hsu.

#include "IActionGraphEditor.h"

#include "ActionGraphBlueprintAssetTypeActions.h"
#include "ActionGraphInstance.h"

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
	return UActionGraphInstance::StaticClass();
}

uint32 FActionGraphBlueprintAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE