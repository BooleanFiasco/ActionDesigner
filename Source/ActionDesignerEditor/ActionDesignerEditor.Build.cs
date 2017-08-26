// Copyright 2017 Norm Nazaroff.

using UnrealBuildTool;
//using System.IO;

public class ActionDesignerEditor : ModuleRules
{
	public ActionDesignerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
		//var EngineDir = Path.GetFullPath(BuildConfiguration.RelativeEnginePath);

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
				"AssetTools/Private",
				"BlueprintGraph",
				"GraphEditor",
				"Kismet",
				//Path.Combine(EngineDir, @"Source/Developer/AssetTools/Private"),
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
				"EditorStyle",
				"EditorWidgets",
				"Kismet",
				"KismetCompiler",
				"KismetWidgets",
				"MainFrame",
				"Projects",
				"PropertyEditor",
				"RHI",
				"Slate",
				"SlateCore",
				"SourceControl",
				"UnrealEd",
				"WorkspaceMenuStructure",
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
