/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
   from
	RePlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
 */
static char __buildInfo[] = "RePlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "rePlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static sqInt allocateByteArrayAndSetRcvrExtraPtrFrom(sqInt anExtraPtr);
static sqInt allocateByteArrayAndSetRcvrPCREPtrFromPCRE(sqInt aPCREPtr);
static sqInt allocateStringAndSetRcvrErrorStrFromCStr(const char *aCStrBuffer);
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
static void loadRcvrFromStackAt(sqInt stackInteger);
static sqInt msg(char *s);
EXPORT(void) primLastAlloc(void);
EXPORT(void) primNetMemory(void);
EXPORT(void) primNumAllocs(void);
EXPORT(void) primNumFrees(void);
EXPORT(void) primPCRECompile(void);
EXPORT(void) primPCREExec(void);
EXPORT(void) primPCREExecfromto(void);
EXPORT(void) primPCRENumSubPatterns(void);
static sqInt rcvrCompileFlags(void);
static void rcvrErrorOffsetFrom(sqInt anInteger);
static void rcvrErrorStrFrom(sqInt aString);
static sqInt rcvrExtraPtr(void);
static void rcvrExtraPtrFrom(sqInt aByteArrayOrNilObject);
static sqInt rcvrMatchFlags(void);
static int * rcvrMatchSpacePtr(void);
static sqInt rcvrMatchSpaceSize(void);
static char * rcvrPatternStrPtr(void);
static void rcvrPCREBufferFrom(sqInt aByteArray);
static sqInt rcvrPCREBufferPtr(void);
static void rePluginFree(void *  aPointer);
static void * rePluginMalloc(size_t  anInteger);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static void sqAssert(sqInt aBool);


/*** Variables ***/
static sqInt compileFlags;
static sqInt errorOffset;
static sqInt errorStr;
static const char *  errorStrBuffer;
static sqInt extraPtr;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static int lastAlloc = 0;
static sqInt matchFlags;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"RePlugin VMMaker-oscog.40 (i)"
#else
	"RePlugin VMMaker-oscog.40 (e)"
#endif
;
static int netMemory = 0;
static int numAllocs = 0;
static int numFrees = 0;
static sqInt patternStr;
static const char *  patternStrPtr;
static sqInt pcrePtr;
static sqInt rcvr;


static sqInt
allocateByteArrayAndSetRcvrExtraPtrFrom(sqInt anExtraPtr)
{
	void *extraByteArrayPtr;
	sqInt extraObject;

	if (anExtraPtr) {

		/* Allocate a Smalltalk ByteArray -- lastAlloc contains the length */

		extraObject = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(real_pcre_extra));
		/* begin loadRcvrFromStackAt: */
		rcvr = interpreterProxy->stackObjectValue(0);
		extraByteArrayPtr = interpreterProxy->arrayValueOf(extraObject);
		memcpy(extraByteArrayPtr, (void *) anExtraPtr, sizeof(real_pcre_extra));
	}
	else {
		extraObject = interpreterProxy->nilObject();
	}
	/* begin rcvrExtraPtrFrom: */
	interpreterProxy->storePointerofObjectwithValue(3, rcvr, extraObject);
	;
	return extraObject;
}

static sqInt
allocateByteArrayAndSetRcvrPCREPtrFromPCRE(sqInt aPCREPtr)
{
	void *patByteArrayPtr;
	sqInt patObject;


	/* Allocate a Smalltalk ByteArray -- lastAlloc contains the length */

	patObject = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), lastAlloc);
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(0);
	patByteArrayPtr = interpreterProxy->arrayValueOf(patObject);
	memcpy(patByteArrayPtr, (void *) aPCREPtr, lastAlloc);
	/* begin rcvrPCREBufferFrom: */
	interpreterProxy->storePointerofObjectwithValue(2, rcvr, patObject);
	;
	return patObject;
}

static sqInt
allocateStringAndSetRcvrErrorStrFromCStr(const char *aCStrBuffer)
{
	sqInt errorStrObj;
	void *errorStrObjPtr;
	sqInt length;


	/* Allocate errorStrObj */

	length = strlen(aCStrBuffer);
	errorStrObj = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), length);
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(0);
	errorStrObjPtr = interpreterProxy->arrayValueOf(errorStrObj);
	memcpy(errorStrObjPtr,aCStrBuffer,length);
	;
	;
	/* begin rcvrErrorStrFrom: */
	interpreterProxy->storePointerofObjectwithValue(4, rcvr, errorStrObj);
	return errorStrObj;
}


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

static sqInt
halt(void)
{
	;
	return 0;
}

static void
loadRcvrFromStackAt(sqInt stackInteger)
{
	rcvr = interpreterProxy->stackObjectValue(stackInteger);
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(void)
primLastAlloc(void)
{
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(lastAlloc);
}

EXPORT(void)
primNetMemory(void)
{
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(netMemory);
}

EXPORT(void)
primNumAllocs(void)
{
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(numAllocs);
}

EXPORT(void)
primNumFrees(void)
{
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(numFrees);
}


/*	<rcvr primPCRECompile>, where rcvr is an object with instance variables:
	
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Compile the regular expression in patternStr, and if the compilation is
	successful, attempt to optimize the compiled expression. Store the results
	in <pcrePtr> and <extratr>, or fill errorStr with a meaningful errorString
	and errorOffset with an indicator where the error was found, applying
	compileFlags throughout. Answer nil with a clean compile (regardless of
	whether an optimization is possible, and answer with the string otherwise.
 */

EXPORT(void)
primPCRECompile(void)
{
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(0);
	/* begin rcvrPatternStrPtr */
	patternStrPtr = ((char *) (((char *) (interpreterProxy->fetchArrayofObject(0, rcvr)))));
	compileFlags = interpreterProxy->fetchIntegerofObject(1, rcvr);
	if (interpreterProxy->failed()) {
		return;
	}
	pcrePtr = (int) pcre_compile(patternStrPtr, compileFlags, 
					&errorStrBuffer, &errorOffset, NULL);
	if (pcrePtr) {
		allocateByteArrayAndSetRcvrPCREPtrFromPCRE(pcrePtr);
		extraPtr = (int) pcre_study((pcre *)pcrePtr, compileFlags, &errorStrBuffer);
		allocateByteArrayAndSetRcvrExtraPtrFrom(extraPtr);
		rePluginFree(((void *) pcrePtr));
		if (extraPtr) {
			rePluginFree(((void *) extraPtr));
		}
		if (interpreterProxy->failed()) {
			return;
		}
		interpreterProxy->popthenPush(1, interpreterProxy->nilObject());
	}
	else {
		errorStr = allocateStringAndSetRcvrErrorStrFromCStr(errorStrBuffer);
		/* begin rcvrErrorOffsetFrom: */
		interpreterProxy->storeIntegerofObjectwithValue(5, rcvr, errorOffset);
		if (interpreterProxy->failed()) {
			return;
		}
		interpreterProxy->popthenPush(1, errorStr);
	}
}


/*	<rcvr primPCREExec: searchObject>, where rcvr is an object with instance
	variables: 
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Apply the regular expression (stored in <pcrePtr> and <extratr>, generated
	from calls to primPCRECompile), to smalltalk String searchObject using
	<matchOptions>. If there is no match, answer nil. Otherwise answer a
	ByteArray of offsets representing the results of the match.
 */

EXPORT(void)
primPCREExec(void)
{
	sqInt length;
	int *matchSpacePtr;
	sqInt matchSpaceSize;
	sqInt result;
	char *searchBuffer;
	sqInt searchObject;


	/* Load Parameters */

	searchObject = interpreterProxy->stackObjectValue(0);
	searchBuffer = interpreterProxy->arrayValueOf(searchObject);
	length = interpreterProxy->byteSizeOf(searchObject);
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(1);
	pcrePtr = ((int) (interpreterProxy->fetchArrayofObject(2, rcvr)));
	extraPtr = rcvrExtraPtr();
	matchFlags = interpreterProxy->fetchIntegerofObject(6, rcvr);
	/* begin rcvrMatchSpacePtr */
	matchSpacePtr = ((int *) (interpreterProxy->fetchArrayofObject(7, rcvr)));
	matchSpaceSize = ((sqInt) (interpreterProxy->byteSizeOf(interpreterProxy->fetchPointerofObject(7, rcvr))) >> 2);
	if (interpreterProxy->failed()) {
		return;
	}
	result = pcre_exec((pcre *)pcrePtr, (pcre_extra *)extraPtr, 
				searchBuffer, length, 0, matchFlags, matchSpacePtr, matchSpaceSize);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(result);
	;
	;
	;
	;
}


/*	<rcvr primPCREExec: searchObject> from: fromInteger to: toInteger>, where
	rcvr is an object with instance variables:
	
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Apply the regular expression (stored in <pcrePtr> and <extratr>, generated
	from calls to primPCRECompile), to smalltalk String searchObject using
	<matchOptions>, beginning at offset <fromInteger> and continuing until
	offset <toInteger>. If there is no match, answer nil. Otherwise answer a
	ByteArray of offsets representing the results of the match.
 */

EXPORT(void)
primPCREExecfromto(void)
{
	sqInt fromInteger;
	sqInt length;
	int *matchSpacePtr;
	sqInt matchSpaceSize;
	sqInt result;
	char *searchBuffer;
	sqInt searchObject;
	sqInt toInteger;


	/* Load Parameters */

	toInteger = interpreterProxy->stackIntegerValue(0);
	fromInteger = interpreterProxy->stackIntegerValue(1);
	searchObject = interpreterProxy->stackObjectValue(2);
	searchBuffer = interpreterProxy->arrayValueOf(searchObject);
	length = interpreterProxy->byteSizeOf(searchObject);
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(3);
	interpreterProxy->success(1 <= fromInteger);
	interpreterProxy->success(toInteger <= length);

	/* Smalltalk offsets are 1-based */

	fromInteger -= 1;
	interpreterProxy->success(fromInteger <= toInteger);
	length = toInteger - fromInteger;

	/* Load Instance Variables */

	searchBuffer += fromInteger;
	pcrePtr = ((int) (interpreterProxy->fetchArrayofObject(2, rcvr)));
	extraPtr = rcvrExtraPtr();
	matchFlags = interpreterProxy->fetchIntegerofObject(6, rcvr);
	/* begin rcvrMatchSpacePtr */
	matchSpacePtr = ((int *) (interpreterProxy->fetchArrayofObject(7, rcvr)));
	matchSpaceSize = ((sqInt) (interpreterProxy->byteSizeOf(interpreterProxy->fetchPointerofObject(7, rcvr))) >> 2);
	if (interpreterProxy->failed()) {
		return;
	}
	result = pcre_exec((pcre *)pcrePtr, (pcre_extra *)extraPtr, 
				searchBuffer, length, 0, matchFlags, matchSpacePtr, matchSpaceSize);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(result);
	;
	;
	;
	;
}


/*	<rcvr primPCRENumSubPatterns>, where rcvr is an object with instance
	variables: 
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Return the number of subpatterns captured by the compiled pattern.
 */
/*	Load Parameters */

EXPORT(void)
primPCRENumSubPatterns(void)
{
	/* begin loadRcvrFromStackAt: */
	rcvr = interpreterProxy->stackObjectValue(0);
	pcrePtr = ((int) (interpreterProxy->fetchArrayofObject(2, rcvr)));
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(pcre_info((pcre *)pcrePtr, NULL, NULL));
}

static sqInt
rcvrCompileFlags(void)
{
	return interpreterProxy->fetchIntegerofObject(1, rcvr);
}

static void
rcvrErrorOffsetFrom(sqInt anInteger)
{
	interpreterProxy->storeIntegerofObjectwithValue(5, rcvr, anInteger);
}

static void
rcvrErrorStrFrom(sqInt aString)
{
	interpreterProxy->storePointerofObjectwithValue(4, rcvr, aString);
}

static sqInt
rcvrExtraPtr(void)
{
	sqInt extraObj;

	extraObj = interpreterProxy->fetchPointerofObject(3, rcvr);
	if (extraObj == (interpreterProxy->nilObject())) {
		return (int) NULL;
	}
	return ((int) (interpreterProxy->arrayValueOf(extraObj)));
}

static void
rcvrExtraPtrFrom(sqInt aByteArrayOrNilObject)
{
	interpreterProxy->storePointerofObjectwithValue(3, rcvr, aByteArrayOrNilObject);
}

static sqInt
rcvrMatchFlags(void)
{
	return interpreterProxy->fetchIntegerofObject(6, rcvr);
}

static int *
rcvrMatchSpacePtr(void)
{
	return ((int *) (interpreterProxy->fetchArrayofObject(7, rcvr)));
}

static sqInt
rcvrMatchSpaceSize(void)
{
	return ((sqInt) (interpreterProxy->byteSizeOf(interpreterProxy->fetchPointerofObject(7, rcvr))) >> 2);
}

static char *
rcvrPatternStrPtr(void)
{
	return ((char *) (interpreterProxy->fetchArrayofObject(0, rcvr)));
}

static void
rcvrPCREBufferFrom(sqInt aByteArray)
{
	interpreterProxy->storePointerofObjectwithValue(2, rcvr, aByteArray);
}

static sqInt
rcvrPCREBufferPtr(void)
{
	return ((int) (interpreterProxy->fetchArrayofObject(2, rcvr)));
}


/*	Free a block of fixed memory allocated with rePluginMalloc. Instrumented
	version of C free() to facilitate leak analysis from Smalltalk.
	OS-specific variations on malloc/free, such as with MacOS, are handled by
	adding a C macro to the header file redefining malloc/free -- see the
	class comment
 */

static void
rePluginFree(void *  aPointer)
{
	numFrees += 1;
	if (aPointer) {
		free(aPointer);
	}
}


/*	Allocate a block of fixed memory using C calls to malloc(). Instrumented
	to facilitate leak analysis from Smalltalk. Set global lastAlloc to
	anInteger. OS-specific variations on malloc/free, such as with MacOS, are
	handled by adding a C macro to the header file redefining malloc/free --
	see the class comment
 */

static void *
rePluginMalloc(size_t  anInteger)
{
	void *aPointer;

	numAllocs += 1;
	if ((aPointer = malloc(anInteger))) {
		lastAlloc = anInteger;
	}
	return aPointer;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

static void
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* RePlugin_exports[][3] = {
	{"RePlugin", "getModuleName", (void*)getModuleName},
	{"RePlugin", "primLastAlloc", (void*)primLastAlloc},
	{"RePlugin", "primNetMemory", (void*)primNetMemory},
	{"RePlugin", "primNumAllocs", (void*)primNumAllocs},
	{"RePlugin", "primNumFrees", (void*)primNumFrees},
	{"RePlugin", "primPCRECompile", (void*)primPCRECompile},
	{"RePlugin", "primPCREExec", (void*)primPCREExec},
	{"RePlugin", "primPCREExecfromto", (void*)primPCREExecfromto},
	{"RePlugin", "primPCRENumSubPatterns", (void*)primPCRENumSubPatterns},
	{"RePlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */