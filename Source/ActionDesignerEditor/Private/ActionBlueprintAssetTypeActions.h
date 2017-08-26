// Copyright 2017 Isaac Hsu.

#pragma once

#include "Developer/AssetTools/Private/AssetTypeActions/AssetTypeActions_Blueprint.h"

class FActionBlueprintAssetTypeActions : public FAssetTypeActions_Blueprint
{
public:
	FActionBlueprintAssetTypeActions(EAssetTypeCategories::Type InAssetCategory);

	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	// End of IAssetTypeActions interface

	// FAssetTypeActions_Blueprint interface
	virtual UFactory* GetFactoryForBlueprintType(UBlueprint* InBlueprint) const override;

private:
	EAssetTypeCategories::Type MyAssetCategory;
};