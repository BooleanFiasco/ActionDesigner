// Copyright 2017 Norm Nazaroff.

using UnrealBuildTool;

public class ActionDesignerEditor : ModuleRules
{
	public ActionDesignerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"ActionDesigner/Public",
				"ActionDesignerEditor/Public",
			}
		);				
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
				"ActionDesigner/Private",
				"ActionDesignerEditor/Private",
				"AssetTools/Public",
			})
		;			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"ActionDesigner",
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
				"GraphEditor",
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
