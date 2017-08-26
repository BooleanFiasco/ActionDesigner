#pragma once

#include "ActionDesignerStyle.h"

#include "Runtime/Slate/Public/Framework/Commands/Commands.h"

class FActionEditorCommands : public TCommands<FActionEditorCommands>
{
public:
	FActionEditorCommands()
		: TCommands<FActionEditorCommands>(
				TEXT("ActionEditor"), // Context name for fast lookup
				NSLOCTEXT("Contexts", "ActionEditor", "Action Editor"), // Localized context name for displaying
				NAME_None, // Parent
				FEditorStyle::GetStyleSetName() // Icon Style Set
			)
	{
	}

	// TCommand<> interface
	virtual void RegisterCommands() override;
	// End of TCommand<> interface

public:
	TSharedPtr<FUICommandInfo> Validate;
};

/*class FAblAbilityEditorViewportCommands : public TCommands<FAblAbilityEditorViewportCommands>
{
public:
	FAblAbilityEditorViewportCommands()
		: TCommands<FAblAbilityEditorViewportCommands>(
			TEXT("AblAbilityEditorViewport"), // Context name for fast lookup
			NSLOCTEXT("Contexts", "AblAbilityEditorViewport", "Ability Editor Viewport"), // Localized context name for displaying
			NAME_None, // Parent
			FActionDesignerStyle::Get()->GetStyleSetName() // Icon Style Set
			)
	{

	}

	// TCommand<> interface
	virtual void RegisterCommands() override;
	// End of TCommand<> interface

public:
	TSharedPtr<FUICommandInfo> m_CameraFollow;
};*/