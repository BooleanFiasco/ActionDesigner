#pragma once

#include "Templates/SharedPointer.h"
#include "UObject/NameTypes.h"

struct FSlateBrush;

/* This class is our Style Set for Able's Ability Editor. */
class FActionDesignerStyle
{
public:
	static void Initialize();

	static void Shutdown();

	/** reloads textures used by slate renderer */
	static void ReloadTextures();

	/** @return The Slate style set for the UMG Style */
	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	//static TSharedRef< class FSlateStyleSet > Create();
	static TSharedPtr< class FSlateStyleSet > ActionEditorStyleInstance;
};
