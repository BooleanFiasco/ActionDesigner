#pragma once

#include "ActionDesignerEditor.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"
#include "ActionGraph.generated.h"

UCLASS(MinimalAPI)
class UActionGraph : public UEdGraph
{
	GENERATED_BODY()

public:
	// Entry node within the state machine
	//UPROPERTY()
	//class UAnimStateEntryNode* EntryNode;

	// Parent instance node
	//UPROPERTY()
	//class UAnimGraphNode_StateMachineBase* OwnerAnimGraphNode;
};
