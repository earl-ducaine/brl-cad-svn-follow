/*
 * itclDecls.h --
 *
 *	Declarations of functions in the platform independent public Itcl API.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: $Id$
 */

#ifndef _ITCLDECLS
#define _ITCLDECLS

/*
 * WARNING: This file is automatically generated by the tools/genStubs.tcl
 * script.  Any modifications to the function declarations below should be made
 * in the itcl/generic/tcl.decls script.
 */

/* !BEGIN!: Do not edit below this line. */

/*
 * Exported function declarations:
 */

#ifndef Itcl_Init_TCL_DECLARED
#define Itcl_Init_TCL_DECLARED
/* 0 */
TCL_EXTERN(int)		Itcl_Init _ANSI_ARGS_((Tcl_Interp * interp));
#endif
#ifndef Itcl_SafeInit_TCL_DECLARED
#define Itcl_SafeInit_TCL_DECLARED
/* 1 */
TCL_EXTERN(int)		Itcl_SafeInit _ANSI_ARGS_((Tcl_Interp * interp));
#endif
#ifndef Itcl_RegisterC_TCL_DECLARED
#define Itcl_RegisterC_TCL_DECLARED
/* 2 */
TCL_EXTERN(int)		Itcl_RegisterC _ANSI_ARGS_((Tcl_Interp * interp,
				CONST char * name, Tcl_CmdProc * proc,
				ClientData clientData,
				Tcl_CmdDeleteProc * deleteProc));
#endif
#ifndef Itcl_RegisterObjC_TCL_DECLARED
#define Itcl_RegisterObjC_TCL_DECLARED
/* 3 */
TCL_EXTERN(int)		Itcl_RegisterObjC _ANSI_ARGS_((Tcl_Interp * interp,
				CONST char * name, Tcl_ObjCmdProc * proc,
				ClientData clientData,
				Tcl_CmdDeleteProc * deleteProc));
#endif
#ifndef Itcl_FindC_TCL_DECLARED
#define Itcl_FindC_TCL_DECLARED
/* 4 */
TCL_EXTERN(int)		Itcl_FindC _ANSI_ARGS_((Tcl_Interp * interp,
				CONST char * name, Tcl_CmdProc ** argProcPtr,
				Tcl_ObjCmdProc ** objProcPtr,
				ClientData * cDataPtr));
#endif
#ifndef Itcl_InitStack_TCL_DECLARED
#define Itcl_InitStack_TCL_DECLARED
/* 5 */
TCL_EXTERN(void)	Itcl_InitStack _ANSI_ARGS_((Itcl_Stack * stack));
#endif
#ifndef Itcl_DeleteStack_TCL_DECLARED
#define Itcl_DeleteStack_TCL_DECLARED
/* 6 */
TCL_EXTERN(void)	Itcl_DeleteStack _ANSI_ARGS_((Itcl_Stack * stack));
#endif
#ifndef Itcl_PushStack_TCL_DECLARED
#define Itcl_PushStack_TCL_DECLARED
/* 7 */
TCL_EXTERN(void)	Itcl_PushStack _ANSI_ARGS_((ClientData cdata,
				Itcl_Stack * stack));
#endif
#ifndef Itcl_PopStack_TCL_DECLARED
#define Itcl_PopStack_TCL_DECLARED
/* 8 */
TCL_EXTERN(ClientData)	Itcl_PopStack _ANSI_ARGS_((Itcl_Stack * stack));
#endif
#ifndef Itcl_PeekStack_TCL_DECLARED
#define Itcl_PeekStack_TCL_DECLARED
/* 9 */
TCL_EXTERN(ClientData)	Itcl_PeekStack _ANSI_ARGS_((Itcl_Stack * stack));
#endif
#ifndef Itcl_GetStackValue_TCL_DECLARED
#define Itcl_GetStackValue_TCL_DECLARED
/* 10 */
TCL_EXTERN(ClientData)	Itcl_GetStackValue _ANSI_ARGS_((Itcl_Stack * stack,
				int pos));
#endif
#ifndef Itcl_InitList_TCL_DECLARED
#define Itcl_InitList_TCL_DECLARED
/* 11 */
TCL_EXTERN(void)	Itcl_InitList _ANSI_ARGS_((Itcl_List * listPtr));
#endif
#ifndef Itcl_DeleteList_TCL_DECLARED
#define Itcl_DeleteList_TCL_DECLARED
/* 12 */
TCL_EXTERN(void)	Itcl_DeleteList _ANSI_ARGS_((Itcl_List * listPtr));
#endif
#ifndef Itcl_CreateListElem_TCL_DECLARED
#define Itcl_CreateListElem_TCL_DECLARED
/* 13 */
TCL_EXTERN(Itcl_ListElem*) Itcl_CreateListElem _ANSI_ARGS_((
				Itcl_List * listPtr));
#endif
#ifndef Itcl_DeleteListElem_TCL_DECLARED
#define Itcl_DeleteListElem_TCL_DECLARED
/* 14 */
TCL_EXTERN(Itcl_ListElem*) Itcl_DeleteListElem _ANSI_ARGS_((
				Itcl_ListElem * elemPtr));
#endif
#ifndef Itcl_InsertList_TCL_DECLARED
#define Itcl_InsertList_TCL_DECLARED
/* 15 */
TCL_EXTERN(Itcl_ListElem*) Itcl_InsertList _ANSI_ARGS_((Itcl_List * listPtr,
				ClientData val));
#endif
#ifndef Itcl_InsertListElem_TCL_DECLARED
#define Itcl_InsertListElem_TCL_DECLARED
/* 16 */
TCL_EXTERN(Itcl_ListElem*) Itcl_InsertListElem _ANSI_ARGS_((
				Itcl_ListElem * pos, ClientData val));
#endif
#ifndef Itcl_AppendList_TCL_DECLARED
#define Itcl_AppendList_TCL_DECLARED
/* 17 */
TCL_EXTERN(Itcl_ListElem*) Itcl_AppendList _ANSI_ARGS_((Itcl_List * listPtr,
				ClientData val));
#endif
#ifndef Itcl_AppendListElem_TCL_DECLARED
#define Itcl_AppendListElem_TCL_DECLARED
/* 18 */
TCL_EXTERN(Itcl_ListElem*) Itcl_AppendListElem _ANSI_ARGS_((
				Itcl_ListElem * pos, ClientData val));
#endif
#ifndef Itcl_SetListValue_TCL_DECLARED
#define Itcl_SetListValue_TCL_DECLARED
/* 19 */
TCL_EXTERN(void)	Itcl_SetListValue _ANSI_ARGS_((
				Itcl_ListElem * elemPtr, ClientData val));
#endif
#ifndef Itcl_EventuallyFree_TCL_DECLARED
#define Itcl_EventuallyFree_TCL_DECLARED
/* 20 */
TCL_EXTERN(void)	Itcl_EventuallyFree _ANSI_ARGS_((ClientData cdata,
				Tcl_FreeProc * fproc));
#endif
#ifndef Itcl_PreserveData_TCL_DECLARED
#define Itcl_PreserveData_TCL_DECLARED
/* 21 */
TCL_EXTERN(void)	Itcl_PreserveData _ANSI_ARGS_((ClientData cdata));
#endif
#ifndef Itcl_ReleaseData_TCL_DECLARED
#define Itcl_ReleaseData_TCL_DECLARED
/* 22 */
TCL_EXTERN(void)	Itcl_ReleaseData _ANSI_ARGS_((ClientData cdata));
#endif
#ifndef Itcl_SaveInterpState_TCL_DECLARED
#define Itcl_SaveInterpState_TCL_DECLARED
/* 23 */
TCL_EXTERN(Itcl_InterpState) Itcl_SaveInterpState _ANSI_ARGS_((
				Tcl_Interp* interp, int status));
#endif
#ifndef Itcl_RestoreInterpState_TCL_DECLARED
#define Itcl_RestoreInterpState_TCL_DECLARED
/* 24 */
TCL_EXTERN(int)		Itcl_RestoreInterpState _ANSI_ARGS_((
				Tcl_Interp* interp, Itcl_InterpState state));
#endif
#ifndef Itcl_DiscardInterpState_TCL_DECLARED
#define Itcl_DiscardInterpState_TCL_DECLARED
/* 25 */
TCL_EXTERN(void)	Itcl_DiscardInterpState _ANSI_ARGS_((
				Itcl_InterpState state));
#endif

typedef struct ItclStubHooks {
    struct ItclIntStubs *itclIntStubs;
} ItclStubHooks;

typedef struct ItclStubs {
    int magic;
    struct ItclStubHooks *hooks;

    int (*itcl_Init) _ANSI_ARGS_((Tcl_Interp * interp)); /* 0 */
    int (*itcl_SafeInit) _ANSI_ARGS_((Tcl_Interp * interp)); /* 1 */
    int (*itcl_RegisterC) _ANSI_ARGS_((Tcl_Interp * interp, CONST char * name, Tcl_CmdProc * proc, ClientData clientData, Tcl_CmdDeleteProc * deleteProc)); /* 2 */
    int (*itcl_RegisterObjC) _ANSI_ARGS_((Tcl_Interp * interp, CONST char * name, Tcl_ObjCmdProc * proc, ClientData clientData, Tcl_CmdDeleteProc * deleteProc)); /* 3 */
    int (*itcl_FindC) _ANSI_ARGS_((Tcl_Interp * interp, CONST char * name, Tcl_CmdProc ** argProcPtr, Tcl_ObjCmdProc ** objProcPtr, ClientData * cDataPtr)); /* 4 */
    void (*itcl_InitStack) _ANSI_ARGS_((Itcl_Stack * stack)); /* 5 */
    void (*itcl_DeleteStack) _ANSI_ARGS_((Itcl_Stack * stack)); /* 6 */
    void (*itcl_PushStack) _ANSI_ARGS_((ClientData cdata, Itcl_Stack * stack)); /* 7 */
    ClientData (*itcl_PopStack) _ANSI_ARGS_((Itcl_Stack * stack)); /* 8 */
    ClientData (*itcl_PeekStack) _ANSI_ARGS_((Itcl_Stack * stack)); /* 9 */
    ClientData (*itcl_GetStackValue) _ANSI_ARGS_((Itcl_Stack * stack, int pos)); /* 10 */
    void (*itcl_InitList) _ANSI_ARGS_((Itcl_List * listPtr)); /* 11 */
    void (*itcl_DeleteList) _ANSI_ARGS_((Itcl_List * listPtr)); /* 12 */
    Itcl_ListElem* (*itcl_CreateListElem) _ANSI_ARGS_((Itcl_List * listPtr)); /* 13 */
    Itcl_ListElem* (*itcl_DeleteListElem) _ANSI_ARGS_((Itcl_ListElem * elemPtr)); /* 14 */
    Itcl_ListElem* (*itcl_InsertList) _ANSI_ARGS_((Itcl_List * listPtr, ClientData val)); /* 15 */
    Itcl_ListElem* (*itcl_InsertListElem) _ANSI_ARGS_((Itcl_ListElem * pos, ClientData val)); /* 16 */
    Itcl_ListElem* (*itcl_AppendList) _ANSI_ARGS_((Itcl_List * listPtr, ClientData val)); /* 17 */
    Itcl_ListElem* (*itcl_AppendListElem) _ANSI_ARGS_((Itcl_ListElem * pos, ClientData val)); /* 18 */
    void (*itcl_SetListValue) _ANSI_ARGS_((Itcl_ListElem * elemPtr, ClientData val)); /* 19 */
    void (*itcl_EventuallyFree) _ANSI_ARGS_((ClientData cdata, Tcl_FreeProc * fproc)); /* 20 */
    void (*itcl_PreserveData) _ANSI_ARGS_((ClientData cdata)); /* 21 */
    void (*itcl_ReleaseData) _ANSI_ARGS_((ClientData cdata)); /* 22 */
    Itcl_InterpState (*itcl_SaveInterpState) _ANSI_ARGS_((Tcl_Interp* interp, int status)); /* 23 */
    int (*itcl_RestoreInterpState) _ANSI_ARGS_((Tcl_Interp* interp, Itcl_InterpState state)); /* 24 */
    void (*itcl_DiscardInterpState) _ANSI_ARGS_((Itcl_InterpState state)); /* 25 */
} ItclStubs;

TCL_EXTERNC ItclStubs *itclStubsPtr;

#if defined(USE_ITCL_STUBS) && !defined(USE_ITCL_STUB_PROCS)

/*
 * Inline function declarations:
 */

#ifndef Itcl_Init
#define Itcl_Init \
	(itclStubsPtr->itcl_Init) /* 0 */
#endif
#ifndef Itcl_SafeInit
#define Itcl_SafeInit \
	(itclStubsPtr->itcl_SafeInit) /* 1 */
#endif
#ifndef Itcl_RegisterC
#define Itcl_RegisterC \
	(itclStubsPtr->itcl_RegisterC) /* 2 */
#endif
#ifndef Itcl_RegisterObjC
#define Itcl_RegisterObjC \
	(itclStubsPtr->itcl_RegisterObjC) /* 3 */
#endif
#ifndef Itcl_FindC
#define Itcl_FindC \
	(itclStubsPtr->itcl_FindC) /* 4 */
#endif
#ifndef Itcl_InitStack
#define Itcl_InitStack \
	(itclStubsPtr->itcl_InitStack) /* 5 */
#endif
#ifndef Itcl_DeleteStack
#define Itcl_DeleteStack \
	(itclStubsPtr->itcl_DeleteStack) /* 6 */
#endif
#ifndef Itcl_PushStack
#define Itcl_PushStack \
	(itclStubsPtr->itcl_PushStack) /* 7 */
#endif
#ifndef Itcl_PopStack
#define Itcl_PopStack \
	(itclStubsPtr->itcl_PopStack) /* 8 */
#endif
#ifndef Itcl_PeekStack
#define Itcl_PeekStack \
	(itclStubsPtr->itcl_PeekStack) /* 9 */
#endif
#ifndef Itcl_GetStackValue
#define Itcl_GetStackValue \
	(itclStubsPtr->itcl_GetStackValue) /* 10 */
#endif
#ifndef Itcl_InitList
#define Itcl_InitList \
	(itclStubsPtr->itcl_InitList) /* 11 */
#endif
#ifndef Itcl_DeleteList
#define Itcl_DeleteList \
	(itclStubsPtr->itcl_DeleteList) /* 12 */
#endif
#ifndef Itcl_CreateListElem
#define Itcl_CreateListElem \
	(itclStubsPtr->itcl_CreateListElem) /* 13 */
#endif
#ifndef Itcl_DeleteListElem
#define Itcl_DeleteListElem \
	(itclStubsPtr->itcl_DeleteListElem) /* 14 */
#endif
#ifndef Itcl_InsertList
#define Itcl_InsertList \
	(itclStubsPtr->itcl_InsertList) /* 15 */
#endif
#ifndef Itcl_InsertListElem
#define Itcl_InsertListElem \
	(itclStubsPtr->itcl_InsertListElem) /* 16 */
#endif
#ifndef Itcl_AppendList
#define Itcl_AppendList \
	(itclStubsPtr->itcl_AppendList) /* 17 */
#endif
#ifndef Itcl_AppendListElem
#define Itcl_AppendListElem \
	(itclStubsPtr->itcl_AppendListElem) /* 18 */
#endif
#ifndef Itcl_SetListValue
#define Itcl_SetListValue \
	(itclStubsPtr->itcl_SetListValue) /* 19 */
#endif
#ifndef Itcl_EventuallyFree
#define Itcl_EventuallyFree \
	(itclStubsPtr->itcl_EventuallyFree) /* 20 */
#endif
#ifndef Itcl_PreserveData
#define Itcl_PreserveData \
	(itclStubsPtr->itcl_PreserveData) /* 21 */
#endif
#ifndef Itcl_ReleaseData
#define Itcl_ReleaseData \
	(itclStubsPtr->itcl_ReleaseData) /* 22 */
#endif
#ifndef Itcl_SaveInterpState
#define Itcl_SaveInterpState \
	(itclStubsPtr->itcl_SaveInterpState) /* 23 */
#endif
#ifndef Itcl_RestoreInterpState
#define Itcl_RestoreInterpState \
	(itclStubsPtr->itcl_RestoreInterpState) /* 24 */
#endif
#ifndef Itcl_DiscardInterpState
#define Itcl_DiscardInterpState \
	(itclStubsPtr->itcl_DiscardInterpState) /* 25 */
#endif

#endif /* defined(USE_ITCL_STUBS) && !defined(USE_ITCL_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#endif /* _ITCLDECLS */


/*
 * Local Variables:
 * mode: C
 * tab-width: 8
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 * ex: shiftwidth=4 tabstop=8
 */
