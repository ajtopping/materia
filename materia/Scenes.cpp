#include "Scenes.h"

void content::scene::SetupDefaultScene( rRenderLayer & render_layer_ref )
{
	/*
	entComposition entity_default_diamond;
	mMesh * mDefaultDiamond = mMeshPrimitiveFactory::DefaultDiamond();
	rMesh rDefaultDiamond;
	rDefaultDiamond.SetMesh(*mDefaultDiamond);
	////////rDefaultDiamond.SetShaderProgram(spUniform);
	mTransform transformDefaultDiamond;
	transformDefaultDiamond.scaleX(0.25);
	transformDefaultDiamond.scaleY(0.25);
	util::component::AttachComponent<Renderer *>(entity_default_diamond.get_uuid(), &rDefaultDiamond);
	util::component::AttachComponent<mTransform *>(entity_default_diamond.get_uuid(), &transformDefaultDiamond);

	entComposition entity_ndc_panel;
	mMesh * mNdcPanel = mMeshPrimitiveFactory::NdcPanel();
	rNdcPanel rrNdcPanel = rNdcPanel();
	rrNdcPanel.SetMesh(*mNdcPanel);
	//rrNdcPanel.set_projection_matrix(rProjectionMatrixFactory::WindowOrthoNdc(win));
	mTransform ndcPanelTransform;
	util::component::AttachComponent<Renderer *>(entity_ndc_panel.get_uuid(), &rrNdcPanel);
	util::component::AttachComponent<mTransform *>(entity_ndc_panel.get_uuid(), &ndcPanelTransform);

	entScene defaultScene;
	am_S_Uuid_T<entScene *>::insert(defaultScene.get_uuid(), &defaultScene);
	entComposition defaultCamera;
	rCameraProperties defaultCameraProperties;
	util::component::AttachComponent<rCameraProperties *>(defaultCamera.get_uuid(), &defaultCameraProperties);
	
	defaultScene.addCompositionEntity(entity_ndc_panel);
	defaultScene.addCompositionEntity(entity_default_diamond);
	*/
}