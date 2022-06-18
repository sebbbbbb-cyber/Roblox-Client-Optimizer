@echo off & cls
rem Roblox Client Optimizer recoded in Batch by Kaid#0001

rem Original idea of automatic fflag adding from this git https://github.com/KEA12/RobloxFullScreenOptimizer
rem fflag list by nul#3174

set fflagList={"FFlagEnableCaptureMode": "true", "FFlagFixGraphicsQuality": "true", "FFlagCommitToGraphicsQualityFix": "true", "DFIntCrashUploadToBacktracePercentage": "0",  "FFlagFixTextureCompositorFramebufferManagement2": "true", "FFlagInitializeBeforeAuthentication2": "true", "FFlagFlushDeferQueueOnInput": "true", "FFlagFlushDeferQueueOnRunState": "true", "DFFlagDataModelFasterTaskProcessing": "true", "FFlagGenericTexturesMaintainAspectRatio": "true", "DFFlagHttpNetworkType": "true", "FFlagMemoryPrioritizationEnabledForTextures": "true", "FFlagFailedTexturePackShowColor": "true", "FFlagTextureReductionViaGenericReload": "true", "FFlagTextureRestorationViaGenericReload": "true", "DFFlagThrottleDeveloperConsoleEvents": "true", "FFlagAppealToBootstrapperOnStartup": "false",  "FFlagFixGraphicsQuality": "true", "FFlagCommitToGraphicsQualityFix": "true", "DFFlagUseRoundRobin": "true", "FFlagUseRoundRobinForClient": "true", "DFFlagUseSort": "true", "FFlagUseSortForClient": "true", "FFlagLeaveStartingCoreScriptsToPlaceLauncher": "true", "FFlagFinishFetchingAssetsCorrectly": "true", "FFlagTerrainWaitForAssets": "true", "FFlagHandleAltEnterFullscreenManually": "false", "FFlagExecDynInitTests": "false", "FFlagEnableQuickGameLaunch": "true", "FFlagEnableLoadingScreenPlaceIconTween": "true", "DFFlagTweenServiceOnStepped": "true", "FFlagLoadTheLoadingScreenFaster": "true", "FFlagLoadTheLoadingScreenEvenFaster": "true", "FFlagCoreScriptFasterCreate": "true", "FFlagCoreScriptSyncMultiInstance2": "true", "DFFlagEnableFlushAfterPurge": "true", "FFlagCharacterTaskQueueReschedule": "true", "FFlagAsyncFontLoading2": "true", "FFlagPreloadAllFonts": "true", "FFlagPreloadTextureItemsOption4": "true", "FFlagPreloadMinimalFonts": "true", "FFlagJoinTime_AllowFullTexturePrioUpdate": "true", "DFFlagUseConstantBufferViews": "true", "FFlagBatchAssetApi": "true", "DFFlagHttpClientOptimizeReqQueuing": "true", "FFlagRigidBodyLazyUpdating": "true", "FFlagHumanoidDeferredSyncFunction5": "true", "FFlagHumanoidParallelUseManager4": "true", "FFlagHumanoidParallelFasterSetCollision": "true", "FFlagHumanoidParallelFasterWakeUp": "true", "FFlagHumanoidParallelSafeCofmUpdate": "true", "FFlagHumanoidParallelSafeUnseat": "true", "FFlagEngineTruncationEnabledForIngameSettingsV2": "true", "FFlagCloudsUseBC4Compression": "true", "FFlagDualStreamVertexData5": "true", "FFlagWindowsUseHardwareCursor": "true", "FFlagEngineHardwareCursorSupport": "true", "FIntClientCompressionFormatRequestPC": "3", "FFlagBetterTrackpadScrolling": "true", "FFlagOptimizeNumUpdateEntityCalls7": "true", "FFlagGfxWindowAverage": "true", "FFlagRenderFastConvolutionOutdoor": "true", "FFlagReduceGuiStateGfxGuiInvalidation": "true", "FFlagLightCullNoPreRotation": "true", "FFlagFastGPULightCulling": "true", "FFlagFastGPULightCulling2": "true", "FFlagFastGPULightCulling3": "true", "FFlagFastGPULightCulling4": "true", "FFlagRenderCacheLocalLightCameras": "true", "FFlagRenderTC2_FixBakeCacheContent": "true", "FFlagDontCreatePingJob": "true", "DFFlagQueueDataPingFromSendData": "true", "FFlagAnimationClipMemCacheEnabled": "true", "FFlagRenderGetLastLODErrorFix": "true", "FFlagRenderAlternativeShadowLod": "true", "DFFlagUseSIMDCulling": "true",  "DFFlagExtentsUseSIMDFunctions": "true", "FFlagVoxelizerMeshPerExtentsScale": "true", "FFlagOptimizeSkeletonGetBoneIndexByPart": "true", "FFlagOptimizeFCMeshGeneratorReplaceParentIndices": "true", "FFlagOptimizeFCMeshGeneratorTransformSource": "true", "DFFlagAnimatorLodOptOutPhase": "true", "DFFlagRenderCompositorExperimentEnabled": "true", "DFIntRenderCompositorExperimentPercent": "10000", "FFlagRenderHalfresShadowsGlsles": "true", "FFlagRenderShadowUseLastLOD": "true", "FFlagBatchGfxGui2": "true", "FFlagBillboardGuiDistanceStepping2": "true", "DFFlagReduceTrussSearchDistance2": "true", "FFlagHttpMinUseGzip": "true", "DFFlagPlayerConfigurer2866": "true", "FFlagPlayerConfigurer2759": "true", "DFFlagPlayerConfigurerRunLMSTest": "true", "FIntLmsClientRollout2": "10000", "DFFlagSimOptimizeInterpolationReturnPreviousIfSmallMovement2": "true", "DFFlagSimIfNoInterp2": "true", "FFlagForceFSMCPULightCulling": "true", "FFlagThrottleLightGridUpdate3": "true"}

title Kaid ^& Nul's Roblox Client Optimizer
echo Roblox Client Optimizer recoded in Batch by Kaid#0001
echo fflag list and originally made by nul#3174
echo.
echo Continue if you would like to automatically add the fflag list!
pause

cls

echo Roblox Client Optimizer recoded in Batch by Kaid#0001
echo fflag list and originally made by nul#3174
echo.

echo Searching for Roblox...
if not exist "%localappdata%\Roblox" echo Umm it seems you dont have Roblox installed... run it first. (Error: 0x1) & pause & exit
if not exist "%localappdata%\Roblox\Versions" echo Umm it seems you dont have Roblox installed... run it first. (Error: 0x2) & pause & exit
set robloxfolder=nul
for /D %%G in ("%localappdata%\Roblox\Versions\*") do if exist "%%G\RobloxPlayerBeta.exe" set robloxfolder=%%G

if %robloxfolder% == nul echo Could not find RobloxPlayerBeta.exe, try re-running roblox. (Error: 0x3) & pause & exit
echo Roblox found in ^| %robloxfolder% & echo.

echo Searching for ClientSettings folder
if exist "%robloxfolder%\ClientSettings" echo Successfully found ClientSettings folder! & echo.
if not exist "%robloxfolder%\ClientSettings" echo ClientSettings folder not found, creating one. & mkdir "%robloxfolder%\ClientSettings" & echo Successfully created ClientSettings folder! & echo.

if exist "%robloxfolder%\ClientSettings\ClientAppSettings.json" cls & color 06 & echo WARNING ^| Found existing ClientAppSettings.json file. & echo. & echo Would you like to continue anyways^? & echo (IT WILL BE OVERWRITTEN) & echo. & echo (if you do NOT wish to continue, CLOSE this window!) & pause & color 07 & cls & del "%robloxfolder%\ClientSettings\ClientAppSettings.json" & echo Deleted ClientAppSettings.json & echo.

echo Writing fflags to ClientAppSettings.json
echo %fflagList% > "%robloxfolder%\ClientSettings\ClientAppSettings.json"
echo Successfully wrote fflags to ClientAppSettings.json
echo.
echo Kaid ^& Nul's client optimizer has completed ^<3 ^| (NOTE: YOU WILL NEED TO RE-RUN THIS EVERY TIME YOU UPDATE ROBLOX!)
echo.
echo Continuing will close the program!
pause
