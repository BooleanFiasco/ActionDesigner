#pragma once

#include "IActionGraph.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "ActionInstance.generated.h"

UCLASS(Transient, Blueprintable, HideCategories=UActionInstance, BlueprintType)
class ACTIONGRAPH_API UActionInstance : public UObject
{
	GENERATED_BODY()

public:

};