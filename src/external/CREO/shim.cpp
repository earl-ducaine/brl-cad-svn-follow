/* This file is provided as a compilation stub to ensure ongoing build testing
 * of CREO to BRL-CAD conversion source code.  This file does not necessarily
 * reflect the CREO api, its values, or type constructs and any similarity is
 * either coincidental or necessary for compilation.
 */

#include "common.h"
#include "shim.h"

/* Functions */
extern "C" int ProArrayAlloc(int,int,int,void**) {return 0;}
extern "C" int ProArrayFree(void**) {return 0;}
extern "C" int ProArraySizeGet(ProArray,int*) {return 0;}
extern "C" int ProAsmcompMdlGet(ProFeature*,void**) {return 0;}
extern "C" int ProAsmcompMdlNameGet(ProFeature*,int*,wchar_t*) {return 0;}
extern "C" int ProAsmcomppathInit(void*,ProIdTable,int,void**) {return 0;}
extern "C" int ProAsmcomppathTrfGet(void**,bool,ProMatrix) {return 0;}
extern "C" int ProAssemblyIsExploded(void*,bool*) {return 0;}
extern "C" int ProCmdActionAdd(const char*,int(*)(int,int*,void*),int,int(*)(int),bool,bool,int*) {return 0;}
extern "C" int ProDimensionTypeGet(void**,int*) {return 0;}
extern "C" int ProDimensionValueGet(void**,double *) {return 0;}
extern "C" int ProElementFree(void**) {return 0;}
extern "C" int ProElementIdGet(void*,int*) {return 0;}
extern "C" int ProElementValueGet(void*,void**) {return 0;}
extern "C" int ProElemtreeElementVisit(void*,void*,int (*)(void*,void*,void*,void*),int (*)(void*,void*,void*,void*),void*) {return 0;}
extern "C" int ProFeatureDimensionVisit(ProFeature *,int (*)(void* *,int ,void*),int (*)(void**,void*),void*) {return 0;}
extern "C" int ProFeatureElemtreeCreate(ProFeature *,void**) {return 0;}
extern "C" int ProFeatureGeomitemVisit(ProFeature *,int,int (*)(void**,int,void*),int (*)(void**,void*),void*) {return 0;}
extern "C" int ProFeatureInit(void*,int,ProFeature*) {return 0;}
extern "C" int ProFeatureResume(void*,int*,int,void*,int) {return 0;}
extern "C" int ProFeatureStatusGet(ProFeature*,ProFeatStatus *) {return 0;}
extern "C" int ProFeatureSuppress(void*,int*,int,void*,int) {return 0;}
extern "C" int ProFeatureTypeGet(ProFeature*,int*) {return 0;}
extern "C" int ProGeomitemdataGet(void**,void***) {return 0;}
extern "C" int ProLinedataGet(void**,Pro3dPnt,Pro3dPnt) {return 0;}
extern "C" int ProMdlCurrentGet(void**) {return 0;}
extern "C" int ProMdlNameGet(void*,wchar_t*) {return 0;}
extern "C" int ProMdlToModelitem(void*,void**) {return 0;}
extern "C" int ProMdlTypeGet(void*,int*) {return 0;}
extern "C" int ProMdlVerstampGet(void*, void**) {return 0;}
extern "C" int ProMdlnameInit(void*,int,void*) {return 0;}
extern "C" int ProMenubarmenuPushbuttonAdd(const char*,const char*,const char*,const char*,const char*,bool,int,wchar_t*) {return 0;}
extern "C" int ProMessageDisplay(wchar_t *,const char *,const char *) {return 0;}
extern "C" int ProParameterInit(void *,wchar_t *,void *) {return 0;}
extern "C" int ProParameterValueGet(ProParameter *,void *) {return 0;}
extern "C" int ProParameterVisit (void **,	void*,int (*)(ProParameter*,int,void*),void *) {return 0;}
extern "C" int ProParamvalueTypeGet(void **,void *) {return 0;}
extern "C" int ProParamvalueValueGet(void **,int,wchar_t *) {return 0;}
extern "C" int ProPartMaterialNameGet(void*,wchar_t *) {return 0;}
extern "C" int ProPartMaterialdataGet(void*,wchar_t*,ProMaterialProps*) {return 0;}
extern "C" int ProPartTessellate(void*,double,double,bool,ProSurfaceTessellationData**) {return 0;}
extern "C" int ProSolidFeatVisit(void*,int (*)(ProFeature*,int,void*),int (*)(ProFeature*,void*),void*) {return 0;}
extern "C" int ProSolidMassPropertyGet(void*,void*,ProMassProperty*) {return 0;}
extern "C" int ProSolidOutlineGet(void*, Pro3dPnt*) {return 0;}
extern "C" int ProStringarrayFree(char**,int) {return 0;}
extern "C" int ProStringVerstampGet(void*, void**) {return 0;}
extern "C" int ProSurfaceAppearancepropsGet(void**,ProSurfaceAppearanceProps*) {return 0;}
extern "C" int ProUICheckbuttonActivateActionSet(const char*,const char*,void(*)(char*,char*,void*),void*) {return 0;}
extern "C" int ProUICheckbuttonGetState(const char*,const char*,bool*) {return 0;}
extern "C" int ProUIDialogActivate(const char*,int*) {return 0;}
extern "C" int ProUIDialogCreate(const char *,const char *) {return 0;}
extern "C" int ProUIDialogDestroy(const char *) {return 0;}
extern "C" int ProUIInputpanelEditable(char*,const char*) {return 0;}
extern "C" int ProUIInputpanelReadOnly(char*,const char*) {return 0;}
extern "C" int ProUIInputpanelValueGet(const char *,const char *,wchar_t**) {return 0;}
extern "C" int ProUIInputpanelValueSet(const char *,const char *,wchar_t*) {return 0;}
extern "C" int ProUILabelTextSet(const char *,const char *,wchar_t *) {return 0;}
extern "C" int ProUIPushbuttonActivateActionSet(const char *,const char *,void (*)(char*,char *,void*),void*) {return 0;}
extern "C" int ProUIRadiogroupSelectednamesGet(const char*,const char*,int*,char***) {return 0;}
extern "C" int ProUITextareaValueSet(const char *,const char *,wchar_t*) {return 0;}
extern "C" int ProValueDataGet(void*,ProValueData*) {return 0;}
extern "C" int ProVerstampEqual(void*, void*) {return 0;}
extern "C" int ProVerstampStringGet(void*, char**) {return 0;}
extern "C" int ProVerstampStringFree(char**) {return 0;}
extern "C" int ProWcharSizeVerify(size_t,int*) {return 0;}
extern "C" int ProWindowRefresh(int) {return 0;}
extern "C" int ProWstringFree(wchar_t*) {return 0;}
extern "C" void ProAssemblyUnexplode(void*) {}
extern "C" void ProMdlMdlNameGet(void*,int*,wchar_t*) {}
extern "C" void ProMdlMdlnameGet(void*,wchar_t*) {}
extern "C" void ProMdlPrincipalunitsystemGet(void*,void**) {}
extern "C" void ProMessageClear() {}
extern "C" void ProMdlIsSkeleton(void*, bool*) {}
extern "C" void ProPartTessellationFree(ProSurfaceTessellationData**) {}
extern "C" void ProStringToWstring(wchar_t*,const char*) {}
extern "C" void ProUIMessageDialogDisplay(int,const wchar_t *,const wchar_t *,ProUIMessageButton*,int,ProUIMessageButton*) {}
extern "C" void ProUnitConversionGet(void**,ProUnitConversion*,void**) {}
extern "C" void ProUnitInit(void*,const wchar_t *,void**) {}
extern "C" void ProUnitsystemUnitGet(void**,int,void**) {}
extern "C" void ProWstringToString(char*,wchar_t*) {}
extern "C" void* ProMdlToPart(void*v) {return v;}
extern "C" void* ProMdlToSolid(void*v) {return v;}
extern "C" void** PRO_CURVE_DATA(void*) {return NULL;}
