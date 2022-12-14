#pragma once

class ESceneObjectTool: public ESceneCustomOTool
{
	typedef ESceneCustomOTool inherited;
public:
    ESceneObjectTool();
    ~ESceneObjectTool() override;
	// definition
    LPCSTR			ClassName				() override{return "scene_object";}


    void		Clear					() override;
    // IO

    bool   		LoadStream            		(IReader&) override;
    bool   		LoadLTX            		(CInifile&) override;
    bool		LoadSelection      		(IReader&) override;

    CCustomObject* CreateObject			(LPVOID data, LPCSTR name) override;
};