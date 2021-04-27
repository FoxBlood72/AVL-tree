##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AVL_Tree
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/noxium/Documents/C/C
ProjectPath            :=/home/noxium/Documents/C/C/AVL_Tree
IntermediateDirectory  :=../build-$(ConfigurationName)/AVL_Tree
OutDir                 :=../build-$(ConfigurationName)/AVL_Tree
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Noxium
Date                   :=04/27/21
CodeLitePath           :=/home/noxium/.codelite
LinkerName             :=/usr/bin/g++-8
SharedObjectLinkerName :=/usr/bin/g++-8 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-8
CC       := /usr/bin/gcc-8
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/AVL_Tree/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/AVL_Tree/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/AVL_Tree"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/AVL_Tree"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/AVL_Tree/.d:
	@mkdir -p "../build-$(ConfigurationName)/AVL_Tree"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(ObjectSuffix): TreeNode.cpp ../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/AVL_Tree/TreeNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TreeNode.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(DependSuffix): TreeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(DependSuffix) -MM TreeNode.cpp

../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(PreprocessSuffix): TreeNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AVL_Tree/TreeNode.cpp$(PreprocessSuffix) TreeNode.cpp

../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(ObjectSuffix): AVLTree.cpp ../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/AVL_Tree/AVLTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AVLTree.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(DependSuffix): AVLTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(DependSuffix) -MM AVLTree.cpp

../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(PreprocessSuffix): AVLTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AVL_Tree/AVLTree.cpp$(PreprocessSuffix) AVLTree.cpp

../build-$(ConfigurationName)/AVL_Tree/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/AVL_Tree/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/AVL_Tree/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AVL_Tree/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AVL_Tree/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AVL_Tree/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/AVL_Tree/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AVL_Tree/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/AVL_Tree//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


