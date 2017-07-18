// Copyright 2017 Norm Nazaroff.

using UnrealBuildTool;

public class ActionGraphEditor : ModuleRules
{
	public ActionGraphEditor(ReadOnlyTargetRules Target) : base(Target)
    {
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"ActionGraph/Public",
				"ActionGraphEditor/Public",
			}
		);				
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
				"ActionGraph/Private",
				"ActionGraphEditor/Private",
				"AssetTools/Public",
			})
		;			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"ActionGraph",
			}
		);			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"InputCore",
				"UnrealEd",
				"AssetTools",
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
