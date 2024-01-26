/*******************************************************************************
 * Copyright IBM Corp. and others 1991
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] https://openjdk.org/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0-only WITH Classpath-exception-2.0 OR GPL-2.0-only WITH OpenJDK-assembly-exception-1.0
 *******************************************************************************/

#include "j9protos.h"
#include "vm_api.h"
#if defined(J9VM_OPT_VM_LOCAL_STORAGE)

#include "j9vmls.h"

J9VMLSFunctionTable J9VMLSFunctions = {
	J9VMLSAllocKeys,
	J9VMLSFreeKeys,
	J9VMLSGet,
	J9VMLSSet,
};

#endif /* J9VM_OPT_VM_LOCAL_STORAGE */

J9InternalVMFunctions J9InternalFunctions = {
	NULL /* reserved field reserved0 initialized to zero */,
	NULL /* reserved field reserved1 initialized to zero */,
	NULL /* reserved field reserved2 initialized to zero */,
	DestroyJavaVM,
	AttachCurrentThread,
	DetachCurrentThread,
	GetEnv,
	AttachCurrentThreadAsDaemon,
	addSystemProperty,
	getSystemProperty,
	setSystemProperty,
	findDllLoadInfo,
	internalExceptionDescribe,
	internalFindClassUTF8,
	internalFindClassInModule,
	internalFindClassString,
	hashClassTableAt,
	hashClassTableAtPut,
	hashClassTableDelete,
	hashClassTableReplace,
	monitorTableAt,
	allocateVMThread,
	deallocateVMThread,
	allocateMemorySegment,
	javaThreadProc,
	copyStringToUTF8WithMemAlloc,
	copyStringToJ9UTF8WithMemAlloc,
	internalAcquireVMAccess,
	internalAcquireVMAccessWithMask,
	internalAcquireVMAccessNoMutexWithMask,
	internalReleaseVMAccessSetStatus,
	instanceFieldOffset,
	staticFieldAddress,
	internalFindKnownClass,
	resolveKnownClass,
	computeHashForUTF8,
	getStringUTF8Length,
	acquireExclusiveVMAccess,
	releaseExclusiveVMAccess,
	internalReleaseVMAccess,
	sendInit,
	internalAcquireVMAccessNoMutex,
	internalCreateArrayClass,
	attachSystemDaemonThread,
	internalAcquireVMAccessClearStatus,
#if defined(J9VM_OPT_REFLECT)
	helperMultiANewArray,
#endif /* J9VM_OPT_REFLECT */
	javaLookupMethod,
	javaLookupMethodImpl,
	setCurrentException,
	setCurrentExceptionUTF,
	setCurrentExceptionNLS,
	setCurrentExceptionNLSWithArgs,
	setCurrentExceptionWithCause,
	objectMonitorEnter,
	objectMonitorExit,
	resolveStaticMethodRef,
	resolveStaticSplitMethodRef,
	resolveSpecialMethodRef,
	resolveSpecialSplitMethodRef,
	resolveStaticFieldRef,
	resolveInstanceFieldRef,
	allocateClassLoader,
	internalSendExceptionConstructor,
	instanceOfOrCheckCast,
	internalCreateRAMClassFromROMClass,
	resolveStringRef,
	exitJavaVM,
	internalRunPreInitInstructions,
	resolveClassRef,
	currentVMThread,
	freeMemorySegment,
	jniPopFrame,
	resolveVirtualMethodRef,
	resolveInterfaceMethodRef,
	getVTableOffsetForMethod,
	checkVisibility,
	sendClinit,
	freeStackWalkCaches,
	genericStackDumpIterator,
	exceptionHandlerSearch,
	internalCreateBaseTypePrimitiveAndArrayClasses,
	isExceptionTypeCaughtByHandler,
#if defined(J9VM_IVE_ROM_IMAGE_HELPERS) || (defined(J9VM_OPT_DYNAMIC_LOAD_SUPPORT) && defined(J9VM_OPT_ROM_IMAGE_SUPPORT))
	romImageNewSegment,
#endif /* J9VM_IVE_ROM_IMAGE_HELPERS || (J9VM_OPT_DYNAMIC_LOAD_SUPPORT && J9VM_OPT_ROM_IMAGE_SUPPORT) */
	runCallInMethod,
	catUtfToString4,
	allocateMemorySegmentList,
	allocateMemorySegmentListWithFlags,
	freeMemorySegmentList,
	allocateMemorySegmentInList,
	allocateVirtualMemorySegmentInList,
	allocateMemorySegmentListEntry,
	allocateClassMemorySegment,
#if defined(J9VM_GC_FINALIZATION)
	jniResetStackReferences,
#endif /* J9VM_GC_FINALIZATION */
	freeClassLoader,
	j9jni_createLocalRef,
	j9jni_deleteLocalRef,
	j9jni_createGlobalRef,
	j9jni_deleteGlobalRef,
	javaCheckAsyncMessages,
	getJNIFieldID,
	getJNIMethodID,
	initializeMethodRunAddress,
	growJavaStack,
	freeStacks,
	printThreadInfo,
	initializeAttachedThread,
	initializeMethodRunAddressNoHook,
	sidecarInvokeReflectMethod,
	sidecarInvokeReflectConstructor,
	allocateMemorySegmentListWithSize,
	freeMemorySegmentListEntry,
	acquireExclusiveVMAccessFromExternalThread,
	releaseExclusiveVMAccessFromExternalThread,
#if defined(J9VM_GC_REALTIME)
	requestExclusiveVMAccessMetronome,
	waitForExclusiveVMAccessMetronome,
	releaseExclusiveVMAccessMetronome,
	requestExclusiveVMAccessMetronomeTemp,
	waitForExclusiveVMAccessMetronomeTemp,
#endif /* J9VM_GC_REALTIME */
#if defined(J9VM_GC_JNI_ARRAY_CACHE)
	cleanupVMThreadJniArrayCache,
#endif /* J9VM_GC_JNI_ARRAY_CACHE */
	objectMonitorInflate,
	objectMonitorEnterNonBlocking,
	objectMonitorEnterBlocking,
	fillJITVTableSlot,
	findArgInVMArgs,
	optionValueOperations,
	dumpStackTrace,
	loadJ9DLL,
	setErrorJ9dll,
	runJVMOnLoad,
	checkRomClassForError,
	setExceptionForErroredRomClass,
	jniVersionIsValid,
	allClassesStartDo,
	allClassesNextDo,
	allClassesEndDo,
	allLiveClassesStartDo,
	allLiveClassesNextDo,
	allLiveClassesEndDo,
	allClassLoadersStartDo,
	allClassLoadersNextDo,
	allClassLoadersEndDo,
#if defined(J9VM_OPT_ROM_IMAGE_SUPPORT) || defined(J9VM_IVE_ROM_IMAGE_HELPERS)
	romClassLoadFromCookie,
#endif /* J9VM_OPT_ROM_IMAGE_SUPPORT || J9VM_IVE_ROM_IMAGE_HELPERS */
#if defined(J9VM_GC_DYNAMIC_CLASS_UNLOADING)
	cleanUpClassLoader,
#endif /* J9VM_GC_DYNAMIC_CLASS_UNLOADING */
	iterateStackTrace,
	getNPEMessage,
	internalReleaseVMAccessNoMutex,
	getVMHookInterface,
	internalAttachCurrentThread,
	setHaltFlag,
	returnFromJNI,
	j9stackmap_StackBitsForPC,
	getJITHookInterface,
	haltThreadForInspection,
	resumeThreadForInspection,
	threadCleanup,
	walkStackForExceptionThrow,
	postInitLoadJ9DLL,
	annotationElementIteratorNext,
	annotationElementIteratorStart,
	elementArrayIteratorNext,
	elementArrayIteratorStart,
	getAllAnnotationsFromAnnotationInfo,
	getAnnotationDefaultsForAnnotation,
	getAnnotationDefaultsForNamedAnnotation,
	getAnnotationInfoFromClass,
	getAnnotationsFromAnnotationInfo,
	getAnnotationFromAnnotationInfo,
	getNamedElementFromAnnotation,
	registerNativeLibrary,
	registerBootstrapLibrary,
	startJavaThread,
	createCachedOutOfMemoryError,
	internalTryAcquireVMAccess,
	internalTryAcquireVMAccessWithMask,
	structuredSignalHandler,
	structuredSignalHandlerVM,
	addHiddenInstanceField,
	reportHotField,
	fieldOffsetsStartDo,
	defaultValueWithUnflattenedFlattenables,
	fieldOffsetsNextDo,
	fullTraversalFieldOffsetsStartDo,
	fullTraversalFieldOffsetsNextDo,
	setClassCastException,
	setNegativeArraySizeException,
	compareStrings,
	compareStringToUTF8,
	prepareForExceptionThrow,
	verifyQualifiedName,
	copyStringToUTF8Helper,
	sendCompleteInitialization,
	J9RegisterAsyncEvent,
	J9UnregisterAsyncEvent,
	J9SignalAsyncEvent,
	J9SignalAsyncEventWithoutInterrupt,
	J9CancelAsyncEvent,
	hashClassTableStartDo,
	hashClassTableNextDo,
	hashPkgTableAt,
	hashPkgTableStartDo,
	hashPkgTableNextDo,
	ensureJNIIDTable,
	initializeMethodID,
	objectMonitorDestroy,
	objectMonitorDestroyComplete,
	buildNativeFunctionNames,
	resolveInstanceFieldRefInto,
	resolveInterfaceMethodRefInto,
	resolveSpecialMethodRefInto,
	resolveStaticFieldRefInto,
	resolveStaticMethodRefInto,
	resolveVirtualMethodRefInto,
	findObjectDeadlockedThreads,
	findROMClassFromPC,
	j9localmap_LocalBitsForPC,
	fillInDgRasInterface,
	rasStartDeferredThreads,
	initJVMRI,
	shutdownJVMRI,
	getOwnedObjectMonitors,
#if !defined(J9VM_SIZE_SMALL_CODE)
	fieldIndexTableRemove,
#endif /* J9VM_SIZE_SMALL_CODE */
	getJavaThreadPriority,
	atomicOrIntoConstantPool,
	atomicAndIntoConstantPool,
	setNativeOutOfMemoryError,
	illegalAccessMessage,
	setThreadForkOutOfMemoryError,
	initializeNativeLibrary,
	addStatistic,
	getStatistic,
	setVMThreadNameFromString,
	findJNIMethod,
	getJ9VMVersionString,
	resolveMethodTypeRef,
	sendFromMethodDescriptorString,
	addToBootstrapClassLoaderSearch,
	addToSystemClassLoaderSearch,
	queryLogOptions,
	setLogOptions,
	exitJavaThread,
	cacheObjectMonitorForLookup,
	jniArrayAllocateMemoryFromThread,
	jniArrayFreeMemoryFromThread,
	sendForGenericInvoke,
	jitFillOSRBuffer,
	sendResolveMethodHandle,
	resolveOpenJDKInvokeHandle,
	resolveConstantDynamic,
	resolveInvokeDynamic,
	sendResolveOpenJDKInvokeHandle,
#if JAVA_SPEC_VERSION >= 11
	sendResolveConstantDynamic,
#endif /* JAVA_SPEC_VERSION >= 11 */
	sendResolveInvokeDynamic,
	resolveMethodHandleRef,
	resolveNativeAddress,
	clearHaltFlag,
	setHeapOutOfMemoryError,
	initializeHeapOOMMessage,
	threadAboutToStart,
	mustHaveVMAccess,
#if defined(J9VM_PORT_ZOS_CEEHDLRSUPPORT)
	javaAndCStacksMustBeInSync,
#endif /* J9VM_PORT_ZOS_CEEHDLRSUPPORT */
	findFieldSignatureClass,
	walkBytecodeFrameSlots,
	jniNativeMethodProperties,
	invalidJITReturnAddress,
	internalAllocateClassLoader,
	initializeClass,
	threadParkImpl,
	threadUnparkImpl,
	monitorWaitImpl,
	threadSleepImpl,
	getMonitorForWait,
	jvmPhaseChange,
	prepareClass,
#if defined(J9VM_OPT_METHOD_HANDLE)
	buildMethodTypeFrame,
#endif /* defined(J9VM_OPT_METHOD_HANDLE) */
	fatalRecursiveStackOverflow,
	setIllegalAccessErrorNonPublicInvokeInterface,
	createThreadWithCategory,
	attachThreadWithCategory,
	searchClassForMethod,
#if defined(J9VM_INTERP_ATOMIC_FREE_JNI)
	internalEnterVMFromJNI,
	internalExitVMToJNI,
#endif /* J9VM_INTERP_ATOMIC_FREE_JNI */
	hashModuleNameTableNew,
	hashModulePointerTableNew,
	hashPackageTableNew,
	hashModuleExtraInfoTableNew,
	hashClassLocationTableNew,
	findModuleForPackageUTF8,
	findModuleForPackage,
	findModuleInfoForModule,
	findClassLocationForClass,
	getJimModules,
	initializeClassPath,
	initializeClassPathEntry,
	setBootLoaderModulePatchPaths,
	isAnyClassLoadedFromPackage,
	freeJ9Module,
	acquireSafePointVMAccess,
	releaseSafePointVMAccess,
	setIllegalAccessErrorReceiverNotSameOrSubtypeOfCurrentClass,
	getVMRuntimeState,
	updateVMRuntimeState,
	getVMMinIdleWaitTime,
	j9rasSetServiceLevel,
#if defined(J9VM_INTERP_ATOMIC_FREE_JNI_USES_FLUSH)
	flushProcessWriteBuffers,
#endif /* J9VM_INTERP_ATOMIC_FREE_JNI_USES_FLUSH */
	registerPredefinedHandler,
	registerOSHandler,
	throwNativeOOMError,
	throwNewJavaIoIOException,
#if JAVA_SPEC_VERSION >= 11
	loadAndVerifyNestHost,
	setNestmatesError,
#endif /* JAVA_SPEC_VERSION >= 11 */
	areValueTypesEnabled,
	areFlattenableValueTypesEnabled,
	peekClassHashTable,
#if defined(J9VM_OPT_JITSERVER)
	isJITServerEnabled,
#endif /* J9VM_OPT_JITSERVER */
	createJoinableThreadWithCategory,
	valueTypeCapableAcmp,
	isNameOrSignatureQtype,
	isClassRefQtype,
	isFieldNullRestricted,
	getFlattenableFieldOffset,
	isFlattenableFieldFlattened,
	getFlattenableFieldType,
	getFlattenableFieldSize,
	arrayElementSize,
	getFlattenableField,
	cloneValueType,
	putFlattenableField,
#if JAVA_SPEC_VERSION >= 15
	checkClassBytes,
#endif /* JAVA_SPEC_VERSION >= 15 */
	storeFlattenableArrayElement,
	loadFlattenableArrayElement,
	jniIsInternalClassRef,
	objectIsBeingWaitedOn,
	areValueBasedMonitorChecksEnabled,
	fieldContainsRuntimeAnnotation,
	methodContainsRuntimeAnnotation,
	findFieldExt,
#if defined(J9VM_OPT_CRIU_SUPPORT)
	jvmCheckpointHooks,
	jvmRestoreHooks,
	isCRaCorCRIUSupportEnabled,
	isCRaCorCRIUSupportEnabled_VM,
	isCRIUSupportEnabled,
	enableCRIUSecProvider,
	isCheckpointAllowed,
	isNonPortableRestoreMode,
	isJVMInPortableRestoreMode,
	isDebugOnRestoreEnabled,
	runInternalJVMCheckpointHooks,
	runInternalJVMRestoreHooks,
	runDelayedLockRelatedOperations,
	delayedLockingOperation,
	addInternalJVMClassIterationRestoreHook,
	setCRIUSingleThreadModeJVMCRIUException,
	getRestoreSystemProperites,
	setupJNIFieldIDsAndCRIUAPI,
	criuCheckpointJVMImpl,
#endif /* defined(J9VM_OPT_CRIU_SUPPORT) */
	getClassNameString,
	getDefaultValueSlotAddress,
#if JAVA_SPEC_VERSION >= 16
	createUpcallThunk,
	getArgPointer,
	allocateUpcallThunkMemory,
	doneUpcallThunkGeneration,
	native2InterpJavaUpcall0,
	native2InterpJavaUpcall1,
	native2InterpJavaUpcallJ,
	native2InterpJavaUpcallF,
	native2InterpJavaUpcallD,
	native2InterpJavaUpcallStruct,
#endif /* JAVA_SPEC_VERSION >= 16 */
#if JAVA_SPEC_VERSION >= 19
	copyFieldsFromContinuation,
	freeContinuation,
	recycleContinuation,
	freeTLS,
	walkContinuationStackFrames,
	walkAllStackFrames,
	acquireVThreadInspector,
	releaseVThreadInspector,
#endif /* JAVA_SPEC_VERSION >= 19 */
	checkArgsConsumed,
#if defined(J9VM_ZOS_3164_INTEROPERABILITY) && (JAVA_SPEC_VERSION >= 17)
	invoke31BitJNI_OnXLoad,
#endif /* defined(J9VM_ZOS_3164_INTEROPERABILITY) && (JAVA_SPEC_VERSION >= 17) */
};
