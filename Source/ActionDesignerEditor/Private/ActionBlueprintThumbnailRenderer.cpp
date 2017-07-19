// Copyright 2017 Isaac Hsu.

#include "ActionDesignerEditor.h"
#include "ActionBlueprintThumbnailRenderer.h"

UTexture2D* UActionBlueprintThumbnailRenderer::DefaultTexture;

UActionBlueprintThumbnailRenderer::UActionBlueprintThumbnailRenderer()
{
	if (DefaultTexture == nullptr)
	{
		DefaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/ActionDesigner/T_Action"), nullptr, LOAD_None, nullptr);
	}
}

void UActionBlueprintThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget*, FCanvas* Canvas)
{
	/*UInputCommand* InputCommand = Cast<UInputCommand>(Object);
	if (InputCommand == nullptr) return;

	if (InputCommand->Thumbnail)
	{
		DrawTexture(InputCommand->Thumbnail, X, Y, Width, Height, Canvas);
	}
	else*/
	{
		DrawTexture(DefaultTexture, X, Y, Width, Height, Canvas);
	}
}

void UActionBlueprintThumbnailRenderer::DrawTexture(UTexture2D* Texture, int32 X, int32 Y, uint32 Width, uint32 Height, FCanvas* Canvas)
{
	if (Texture)
	{
		Canvas->DrawTile(
			(float)X,
			(float)Y,
			(float)Width,
			(float)Height,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			FLinearColor::White,
			Texture->Resource,
			true);
	}
}

