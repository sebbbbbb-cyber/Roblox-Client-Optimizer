# Credits to the original script: https://github.com/KEA12/RobloxFullScreenOptimizer
# Edited by nul#3174 to actually be more useful

# print("THIS .py VERSION OF THE CLIENT OPTIMIZER IS OLD, USE THE .cmd VERSION ON THE GITHUB!!! | https://github.com/L8X/roblox-client-optimizer")

# Import Libraries
import os
import time
import json

# Define Variables
path = f"C:\\Users\\{os.getlogin()}\\AppData\\Local\\Roblox\\Versions"
found = ""
start = time.time()

# Find Roblox Game Directory
for file in os.listdir(path):
    if file.startswith("version-"):
        for exe in os.listdir(f"{path}\\{file}"):
            if "RobloxPlayerBeta.exe" in exe:
                found = f"{path}\\{file}"
                print(f"Found Roblox Game directory: {found}")
                break

# Create ClientSettings Folder
if found:
    try:
        os.makedirs(f"{found}\\ClientSettings")
        found = f"{found}\\ClientSettings"
        print("Created ClientSettings Folder")
    except FileExistsError:
        print("ClientSettings folder already exists")
        found = f"{found}\\ClientSettings"
else:
    print(f"Roblox Game directory not found.")
    print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
    input("Press the Enter key to exit...")
    exit()


# Create ClientAppSettings.json
if found:
    if not os.path.exists(f"{found}\\ClientAppSettings.json"):
        os.path.join(found, "ClientAppSettings.json")
        found = f"{found}\\ClientAppSettings.json"
        print("ClientAppSettings.json created successfully")
    else:
        print("ClientAppSettings.json already exists")
        print(f"Client optimization is already enabled.")
        print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
        input("Press the Enter key to exit...")
        exit()
else:
    print(f"ClientSettings directory not found.")
    print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
    input("Press the Enter key to exit...")
    exit()

# Write to ClientAppSettings.json
if found:
    try:
        with open(found, 'w') as ClientAppSettings:
            data = {"FFlagSimOrderedAutoJointCreation": "true", "FFlagSimFixAutoJointParenting": "true", "DFFlagSimNewMaterialProperties": "true", "DFFlagInWithTheNew": "true", "DFFlagNewRejoinMessage": "true", "FFlagNeverUseJoinBlobRobloxLocaleEvenAsDefault": "true", "FFlagDontDisconnectJointUpdateUnlessNecessary": "true", "DFFlagClientJoinReportGroupControl": "true", "DFFlagEquippedEmotesAddId": "true", "DFFlagEquippedEmotesAddIdClientData": "true", "FFlagFixClientServerScreenOrientation": "true", "FFlagKickClientOnCoreGuiRenderOverflow": "false", "DFFlagReplicatorClientRemoteProfilerDumpRefactor": "true", "FFlagReportDesktopClientOsVersion": "true", "FFlagReportDestroyedInstanceUsageStatsClient5": "true", "FFlagSoundServiceClientFix": "true", "FFlagReportFailuresInClientJoinAll2": "true", "DFFlagReportOSInRakNetHighwaterMark": "true", "DFFlagRakNetUseSlidingWindow4": "true", "DFFlagRakNetOnAckCheckForSendOnly": "true", "DFFlagRakNetFixBwCollapse": "true", "DFFlagRakNetCountUnreliableBytesForStats": "true", "DFFlagRakNetComputeTxBw": "true", "DFFlagRakNetCalculateApplicationFeedback2": "true", "FFlagHSRClusterImprovement": "true", "FFlagVoxelizerMeshPerExtentsScale": "true", "FFlagFastClusterVertexDeclOpts": "true", "FFlagSimUseCSGV3TreeRule2Reduction": "true", "FFlagSimEnableCSGV3Async": "true", "FFlagSimEnableCSGV3": "true", "FFlagSimCSGV3RemoveSuperfluousPlanes": "true", "FFlagSimCSGV3OptimizedFaceUVNormalTransform": "true", "FFlagSimCSGV3NotRemovePlanesInEquivalenceClass": "true", "FFlagSimCSG3RemoveMeshDuringSerialization": "true", "FFlagSimCSG3AsyncWarmv2": "true", "FFlagSimCSG3AsyncWarm": "true", "FFlagSimCSG2RemoveMeshDuringSerialization": "true", "FFlagGraphicsGLTextureReduction": "true", "FFlagCSGMeshDisableWriteHash": "true", "FFlagCSGMeshDisableReadHash": "true", "DFFlagAvoidCSGConvexCopies": "true", "FFlagNewEmotesInGame2": "true", "FFlagRenderTC2_FixSpecularAlpha": "true", "DFFlagRenderTC2_DiscardGeometryData2": "true", "FFlagRenderUseHalfsVulkan": "true", "FFlagGraphicsVulkanVideoMemory3": "true", "FFlagGraphicsGLVideoMemory": "true", "FFlagDynamicallyMoveSoundStorageLocationOnMemoryNotification": "true", "FFlagDeliverLowMemoryWarningsViaPolling": "true", "DFFlagAlwaysPutSoundsOnDiskWhenLowOnMemory": "true", "FFlagTrackGraphicsFeatureLevelWithoutThrottling": "true", "FFlagScreenProtocolEnabled": "true", "DFFlagHttpCacheMissingRedirects": "true", "DFFlagHttpCacheCleanBasedOnMemory": "true", "FFlagTryCacheAndReuseVideoAssets": "true", "FFlagSimCSG3MegaAssetFetcherSkipCached": "true", "FFlagKeyRingInitFile": "true", "DFFlagPointsOverrides": "true", "DFFlagResetChildrenOnNIIProcess2": "true", "FFlagSimSolverCacheForces": "true", "DFFlagFileSystemGetCacheDirectoryLikeAndroid": "true", "FFlagFileSystemGetCacheDirectoryPointerCacheResult": "true", "FFlagSharedStringsDistribute": "true", "FFlagFilteredLocalSimulation3": "true", "DFIntLocalSimZonePercent": "100", "FFlagScreenshotHudApi": "true", "FFlagVoiceAbuseReportsEnabled": "true", "FFlagSubscriptionFailureUX": "true", "FFlagSubscriptionFailureRejoin": "true", "FFlagVCPromptEarlyOut": "true", "FFlagRemoveAssetVersionEndpoint": "true", "FFlagAllowUsernameOverlayInScreenshotHud": "true", "FFlagBubbleChatInexistentAdorneeFix": "true", "FFlagEnableRichTextForBubbleChat": "true", "FFlagVoiceARUnblockingUnmutingEnabled": "true", "FFlagEnableUniversalVoiceToasts": "true", "FFlagSkipRedundantVoiceCheck": "true", "FFlagDeferredBlockStatusChange": "true", "FFlagEnableBetaBadgeLearnMore": "true", "FFlagEnableLuaVoiceChatAnalytics": "true", "FFlagEnableVoiceSources": "true", "FFlagClearVoiceStateOnRejoin": "true", "FFlagEnableSessionCancelationOnBlock": "true", "FFlagClearUserFromRecentVoiceDataOnLeave": "true", "FFlagEnableVoiceChatStorybookFix": "true", "DFFlagAvatarEditorServiceEnabled2": "true", "DFFlagEnableVisibilityService": "true", "DFFlagSimIsAdaptiveOn": "true", "DFFlagSendAllPhysicsPackets": "true", "FFlagVoiceAbuseReportsEnabled_DEV": "true", "FFlagVoiceChannelAddUserDEV": "true", "FFlagVoiceChannelGenerateId": "true", "DFFlagVolumeSettingsUsePower2": "true", "DFFlagVoiceChatAutoTest": "true", "DFFlagVoiceChatFixJoinRetry": "true", "FFlagMuteButtonRaceConditionFix": "true", "FFlagShrinkSpatialVoiceBuffers": "true", "FFlagVoiceChatLockFreeBuffering": "true", "FFlagEnableVoiceChatVoiceUISync": "true", "FFlagVoiceCheckLocalNetworkSet": "true", "DFFlagVoiceChat": "true", "DFFlagVoiceChat2": "true", "DFFlagVoiceChat3": "true", "DFFlagVoiceChat4": "true", "FFlagEnableCaptureMode": "true", "FFlagFixGraphicsQuality": "true", "FFlagCommitToGraphicsQualityFix": "true", "DFIntCrashUploadToBacktracePercentage": "0", "FFlagFixTextureCompositorFramebufferManagement2": "true", "FFlagInitializeBeforeAuthentication2": "true", "FFlagFlushDeferQueueOnInput": "true", "FFlagFlushDeferQueueOnRunState": "true", "DFFlagDataModelFasterTaskProcessing": "true", "FFlagGenericTexturesMaintainAspectRatio": "true", "DFFlagHttpNetworkType": "true", "FFlagMemoryPrioritizationEnabledForTextures": "true", "FFlagFailedTexturePackShowColor": "true", "FFlagTextureReductionViaGenericReload": "true", "FFlagTextureRestorationViaGenericReload": "true", "DFFlagThrottleDeveloperConsoleEvents": "true", "FFlagAppealToBootstrapperOnStartup": "false", "DFFlagUseRoundRobin": "true", "FFlagUseRoundRobinForClient": "true", "DFFlagUseSort": "true", "FFlagUseSortForClient": "true", "FFlagLeaveStartingCoreScriptsToPlaceLauncher": "true", "FFlagFinishFetchingAssetsCorrectly": "true", "FFlagTerrainWaitForAssets": "true", "FFlagHandleAltEnterFullscreenManually": "false", "FFlagExecDynInitTests": "false", "FFlagEnableQuickGameLaunch": "true", "FFlagEnableLoadingScreenPlaceIconTween": "true", "DFFlagTweenServiceOnStepped": "true", "FFlagLoadTheLoadingScreenFaster": "true", "FFlagLoadTheLoadingScreenEvenFaster": "true", "FFlagCoreScriptFasterCreate": "true", "FFlagCoreScriptSyncMultiInstance2": "true", "DFFlagEnableFlushAfterPurge": "true", "FFlagCharacterTaskQueueReschedule": "true", "FFlagAsyncFontLoading2": "true", "FFlagPreloadAllFonts": "true", "FFlagPreloadTextureItemsOption4": "true", "FFlagPreloadMinimalFonts": "true", "FFlagJoinTime_AllowFullTexturePrioUpdate": "true", "DFFlagUseConstantBufferViews": "true", "FFlagBatchAssetApi": "true", "DFFlagHttpClientOptimizeReqQueuing": "true", "FFlagRigidBodyLazyUpdating": "true", "FFlagHumanoidDeferredSyncFunction5": "true", "FFlagHumanoidParallelUseManager4": "true", "FFlagHumanoidParallelFasterSetCollision": "true", "FFlagHumanoidParallelFasterWakeUp": "true", "FFlagHumanoidParallelSafeCofmUpdate": "true", "FFlagHumanoidParallelSafeUnseat": "true", "FFlagEngineTruncationEnabledForIngameSettingsV2": "true", "FFlagCloudsUseBC4Compression": "true", "FFlagDualStreamVertexData5": "true", "FFlagWindowsUseHardwareCursor": "true", "FFlagEngineHardwareCursorSupport": "true", "FIntClientCompressionFormatRequestPC": "3", "FFlagBetterTrackpadScrolling": "true", "FFlagOptimizeNumUpdateEntityCalls7": "true", "FFlagGfxWindowAverage": "true", "FFlagRenderFastConvolutionOutdoor": "true", "FFlagReduceGuiStateGfxGuiInvalidation": "true", "FFlagLightCullNoPreRotation": "true", "FFlagFastGPULightCulling": "true", "FFlagFastGPULightCulling2": "true", "FFlagFastGPULightCulling3": "true", "FFlagFastGPULightCulling4": "true", "FFlagRenderCacheLocalLightCameras": "true", "FFlagRenderTC2_FixBakeCacheContent": "true", "FFlagDontCreatePingJob": "true", "DFFlagQueueDataPingFromSendData": "true", "FFlagAnimationClipMemCacheEnabled": "true", "FFlagRenderGetLastLODErrorFix": "true", "FFlagRenderAlternativeShadowLod": "true", "DFFlagUseSIMDCulling": "true", "DFFlagExtentsUseSIMDFunctions": "true", "FFlagOptimizeSkeletonGetBoneIndexByPart": "true", "FFlagOptimizeFCMeshGeneratorReplaceParentIndices": "true", "FFlagOptimizeFCMeshGeneratorTransformSource": "true", "DFFlagAnimatorLodOptOutPhase": "true", "DFFlagRenderCompositorExperimentEnabled": "true", "DFIntRenderCompositorExperimentPercent": "10000", "FFlagRenderHalfresShadowsGlsles": "true", "FFlagRenderShadowUseLastLOD": "true", "FFlagBatchGfxGui2": "true", "FFlagBillboardGuiDistanceStepping2": "true", "DFFlagReduceTrussSearchDistance2": "true", "FFlagHttpMinUseGzip": "true", "DFFlagPlayerConfigurer2866": "true", "FFlagPlayerConfigurer2759": "true", "DFFlagPlayerConfigurerRunLMSTest": "true", "FIntLmsClientRollout2": "10000", "DFFlagSimOptimizeInterpolationReturnPreviousIfSmallMovement2": "true", "DFFlagSimIfNoInterp2": "true", "FFlagForceFSMCPULightCulling": "true", "FFlagThrottleLightGridUpdate3": "true"}
            json.dump(data, ClientAppSettings)
            print("Optimization flags applied successfully")
    except FileNotFoundError:
        print("ClientAppSettings.json not found. Please retry.")
        print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
        input("Press the Enter key to exit...")
        exit()
    print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
    input("Press the Enter key to exit...")
    exit()
else:
    print(f"ClientSettings directory not found.")
    print(f"\n\nFinished in {round(time.time() - start) + 1}ms.")
    input("Press the Enter key to exit...")
    exit()
