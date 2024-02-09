//==============================================================================
/**
 * @file	field_zoom.h
 * @brief	フィールドのカメラワーク、簡易ズーム
 * @author	kagaya
 * @data	05.07.13
 */
//==============================================================================
#ifndef FIELD_ZOOM_H_FILE
#define FIELD_ZOOM_H_FILE

#include "fieldsys.h"

//==============================================================================
//	define
//==============================================================================

//==============================================================================
//	typedef
//==============================================================================
//--------------------------------------------------------------
///	ZOOMTYPE
//--------------------------------------------------------------
typedef enum
{
	ZOOMTYPE_NON = 0,	///<何も無し
	ZOOMTYPE_ZOOM,		///<ズーム処理を行う
	ZOOMTYPE_BACK,		///<初期のカメラ位置へ指定フレームで戻す。距離の指定は無視
	
	ZOOMTYPE_MAX,		///<最大
}ZOOMTYPE;

//==============================================================================
//	外部参照
//==============================================================================
extern TCB_PTR FieldZoom_Init( FIELDSYS_WORK *fsys, u32 heap_id );
extern BOOL FieldZoom_EndCheck( TCB_PTR tcb );
extern void FieldZoom_Delete( TCB_PTR tcb );
extern void FieldZoom_TypeChange(
		TCB_PTR tcb, ZOOMTYPE type, fx32 target_dist, u32 target_frame );

#endif //FIELD_ZOOM_H_FILE
