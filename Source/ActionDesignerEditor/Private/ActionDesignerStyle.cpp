#include "ActionDesignerEditor.h"
#include "ActionDesignerStyle.h"

//#include "AbleEditorPrivate.h"
#include "Brushes/SlateImageBrush.h"
#include "Brushes/SlateBoxBrush.h"
#include "Misc/Paths.h"
#include "SlateStyle.h"
#include "SlateStyleRegistry.h"
#include "IPluginManager.h"
#include "ClassIconFinder.h"

//#define IMAGE_PLUGIN_BRUSH( RelativePath, ... ) FSlateImageBrush( FActionDesignerStyle::InContent( RelativePath, ".png" ), __VA_ARGS__ )
//#define BOX_PLUGIN_BRUSH( RelativePath, ... ) FSlateBoxBrush( FActionDesignerStyle::InContent( RelativePath, ".png" ), __VA_ARGS__ )

TSharedPtr< FSlateStyleSet > FActionDesignerStyle::ActionEditorStyleInstance = NULL;

void FActionDesignerStyle::Initialize()
{
	// Const icon sizes
	const FVector2D Icon8x8(8.0f, 8.0f);
	const FVector2D Icon12x12(12.0f, 12.0f);
	const FVector2D Icon16x16(16.0f, 16.0f);
	const FVector2D Icon20x20(20.0f, 20.0f);
	const FVector2D Icon40x40(40.0f, 40.0f);

	// Only register once
	if (ActionEditorStyleInstance.IsValid())
	{
		return;
	}

	ActionEditorStyleInstance = MakeShareable(new FSlateStyleSet(FActionDesignerStyle::GetStyleSetName()));
	ActionEditorStyleInstance->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	ActionEditorStyleInstance->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	//StyleSet->Set("ActionEditor.Validate", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/Validate_40"), Icon40x40));

	FSlateStyleRegistry::RegisterSlateStyle(*ActionEditorStyleInstance.Get());
}

FName FActionDesignerStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("FActionDesignerStyle"));
	return StyleSetName;
}

void FActionDesignerStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

void FActionDesignerStyle::Shutdown()
{
	if (ActionEditorStyleInstance.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*ActionEditorStyleInstance.Get());
		ensure(ActionEditorStyleInstance.IsUnique());
		ActionEditorStyleInstance.Reset();
	}
}

const ISlateStyle& FActionDesignerStyle::Get()
{
	return *ActionEditorStyleInstance;
}

//#undef IMAGE_PLUGIN_BRUSH
