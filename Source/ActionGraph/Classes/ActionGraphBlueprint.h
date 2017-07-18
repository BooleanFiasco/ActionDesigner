#pragma once

#include "IActionGraph.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Misc/Guid.h"
#include "Engine/Blueprint.h"
#include "ActionGraphBlueprint.generated.h"

UCLASS(BlueprintType)
class ACTIONGRAPH_API UActionGraphBlueprint : public UBlueprint
{
	GENERATED_UCLASS_BODY()
};