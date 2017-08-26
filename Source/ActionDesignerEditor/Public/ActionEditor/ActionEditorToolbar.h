#pragma once

#include "CoreMinimal.h"

class FActionEditorToolbar : public TSharedFromThis<FActionEditorToolbar>
{

public:
	void AddActionEditorModesToolbar(TSharedPtr<class FExtender> Extender, TSharedPtr<class FActionEditor> InActionEditor);

public:
	/**  */
	void FillActionEditorModesToolbar(class FToolBarBuilder& ToolbarBuilder);

	TWeakPtr<class FActionEditor> ActionEditor;
};
