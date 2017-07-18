#pragma once

#include "IActionGraph.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "ActionGraphInstance.generated.h"

UCLASS(Transient, Blueprintable, HideCategories=UActionGraphInstance, BlueprintType)
class ACTIONGRAPH_API UActionGraphInstance : public UObject
{
	GENERATED_BODY()

public:

};