#include <iostream>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <windows.h>
#include <thread>

// Tray icon code & clear function was taken from Stackoverflow, thx, your code is now mine!
void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

FILE* filepoint;
errno_t err;
bool fileExists(const std::string& name) {
    if (err = fopen_s(&filepoint,name.c_str(), "r") != 0) {
        return false;
    }else {
        fclose(filepoint);
        return true;
    }
}

bool isConsoleHidden = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LPCWSTR lpszClass = L"__hidden__";

int traySystem() {
    HINSTANCE hInstance = GetModuleHandle(nullptr);

    WNDCLASS wc;
    HWND hWnd;
    MSG msg;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = nullptr;
    wc.hCursor = nullptr;
    wc.hIcon = nullptr;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = lpszClass;
    wc.lpszMenuName = nullptr;
    wc.style = 0;
    RegisterClass(&wc);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        nullptr, nullptr, hInstance, nullptr);

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

char* buf = nullptr;
size_t sz = 0;
std::string rootDir;
std::string robloxRootDir;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
    rootDir = std::string("C:\\RClientOptimizer");

    std::ifstream file(rootDir + "\\settings.lgbt");
    std::string newStr = "";
    std::ofstream settings;

    static NOTIFYICONDATA nid;

    switch (iMsg)
    {
    case WM_CREATE:
        std::memset(&nid, 0, sizeof(nid));
        nid.cbSize = sizeof(nid);
        nid.hWnd = hWnd;
        nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
        nid.uCallbackMessage = WM_APP + 1;
        nid.hIcon = (HICON)LoadImageA(NULL, (rootDir + std::string("\\animegirl.ico")).c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_SHARED);
        memcpy_s(nid.szTip, sizeof(nid.szTip), L"RCO <3\nClick to toggle console", 64);
        memcpy_s(nid.szInfoTitle, sizeof(nid.szInfoTitle), L"Roblox Client Optimizer", 50);
        memcpy_s(nid.szInfo, sizeof(nid.szInfo), L"RCO is running!\nToggle the console via the tray icon!", 110);
        Shell_NotifyIcon(NIM_ADD, &nid);
        return 0;
    case WM_APP + 1:
        switch (lParam)
        {
        case WM_LBUTTONDBLCLK:
            if (isConsoleHidden) {
                ShowWindow(GetConsoleWindow(), SW_SHOW);
                isConsoleHidden = false;
            } else {
                ShowWindow(GetConsoleWindow(), SW_HIDE);
                isConsoleHidden = true;
            }
            newStr = "";
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    if (!(line.find("consoleHidden:") == 0)) {
                        newStr += line + "\n";
                    }
                }
                settings.open(rootDir + "\\settings.lgbt");
                settings << newStr;
                settings.close();

                settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
                if (isConsoleHidden)
                    settings << "consoleHidden:y\n";
                else
                    settings << "consoleHidden:n\n";
                settings.close();
                file.close();
            }
            break;
        case WM_LBUTTONDOWN:
            if (isConsoleHidden) {
                ShowWindow(GetConsoleWindow(), SW_SHOW);
                isConsoleHidden = false;
            }
            else {
                ShowWindow(GetConsoleWindow(), SW_HIDE);
                isConsoleHidden = true;
            }
            newStr = "";
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    if (!(line.find("consoleHidden:") == 0)) {
                        newStr += line + "\n";
                    }
                }
                settings.open(rootDir + "\\settings.lgbt");
                settings << newStr;
                settings.close();

                std::ofstream settings;
                settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
                if (isConsoleHidden)
                    settings << "consoleHidden:y\n";
                else
                    settings << "consoleHidden:n\n";
                settings.close();
                file.close();
            }
            break;
        }
        break;
    case WM_DESTROY:
        Shell_NotifyIcon(NIM_DELETE, &nid);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

char state = NULL;
std::string verString = "";
std::string fflagListStr = "";
void fflagUpdater() {
    // Offline FFlag list will never be updated (Do not update this nul it is a waste of time, it is mostly just for weirdos who dont trust the internet!)
    std::string offlineFflags = "{\"FFlagEnableCaptureMode\": \"true\", \"FFlagFixGraphicsQuality\": \"true\", \"FFlagCommitToGraphicsQualityFix\": \"true\", \"DFIntCrashUploadToBacktracePercentage\": \"0\",  \"FFlagFixTextureCompositorFramebufferManagement2\": \"true\", \"FFlagInitializeBeforeAuthentication2\": \"true\", \"FFlagFlushDeferQueueOnInput\": \"true\", \"FFlagFlushDeferQueueOnRunState\": \"true\", \"DFFlagDataModelFasterTaskProcessing\": \"true\", \"FFlagGenericTexturesMaintainAspectRatio\": \"true\", \"DFFlagHttpNetworkType\": \"true\", \"FFlagMemoryPrioritizationEnabledForTextures\": \"true\", \"FFlagFailedTexturePackShowColor\": \"true\", \"FFlagTextureReductionViaGenericReload\": \"true\", \"FFlagTextureRestorationViaGenericReload\": \"true\", \"DFFlagThrottleDeveloperConsoleEvents\": \"true\", \"FFlagAppealToBootstrapperOnStartup\": \"false\",  \"FFlagFixGraphicsQuality\": \"true\", \"FFlagCommitToGraphicsQualityFix\": \"true\", \"DFFlagUseRoundRobin\": \"true\", \"FFlagUseRoundRobinForClient\": \"true\", \"DFFlagUseSort\": \"true\", \"FFlagUseSortForClient\": \"true\", \"FFlagLeaveStartingCoreScriptsToPlaceLauncher\": \"true\", \"FFlagFinishFetchingAssetsCorrectly\": \"true\", \"FFlagTerrainWaitForAssets\": \"true\", \"FFlagHandleAltEnterFullscreenManually\": \"false\", \"FFlagExecDynInitTests\": \"false\", \"FFlagEnableQuickGameLaunch\": \"true\", \"FFlagEnableLoadingScreenPlaceIconTween\": \"true\", \"DFFlagTweenServiceOnStepped\": \"true\", \"FFlagLoadTheLoadingScreenFaster\": \"true\", \"FFlagLoadTheLoadingScreenEvenFaster\": \"true\", \"FFlagCoreScriptFasterCreate\": \"true\", \"FFlagCoreScriptSyncMultiInstance2\": \"true\", \"DFFlagEnableFlushAfterPurge\": \"true\", \"FFlagCharacterTaskQueueReschedule\": \"true\", \"FFlagAsyncFontLoading2\": \"true\", \"FFlagPreloadAllFonts\": \"true\", \"FFlagPreloadTextureItemsOption4\": \"true\", \"FFlagPreloadMinimalFonts\": \"true\", \"FFlagJoinTime_AllowFullTexturePrioUpdate\": \"true\", \"DFFlagUseConstantBufferViews\": \"true\", \"FFlagBatchAssetApi\": \"true\", \"DFFlagHttpClientOptimizeReqQueuing\": \"true\", \"FFlagRigidBodyLazyUpdating\": \"true\", \"FFlagHumanoidDeferredSyncFunction5\": \"true\", \"FFlagHumanoidParallelUseManager4\": \"true\", \"FFlagHumanoidParallelFasterSetCollision\": \"true\", \"FFlagHumanoidParallelFasterWakeUp\": \"true\", \"FFlagHumanoidParallelSafeCofmUpdate\": \"true\", \"FFlagHumanoidParallelSafeUnseat\": \"true\", \"FFlagEngineTruncationEnabledForIngameSettingsV2\": \"true\", \"FFlagCloudsUseBC4Compression\": \"true\", \"FFlagDualStreamVertexData5\": \"true\", \"FFlagWindowsUseHardwareCursor\": \"true\", \"FFlagEngineHardwareCursorSupport\": \"true\", \"FIntClientCompressionFormatRequestPC\": \"3\", \"FFlagBetterTrackpadScrolling\": \"true\", \"FFlagOptimizeNumUpdateEntityCalls7\": \"true\", \"FFlagGfxWindowAverage\": \"true\", \"FFlagRenderFastConvolutionOutdoor\": \"true\", \"FFlagReduceGuiStateGfxGuiInvalidation\": \"true\", \"FFlagLightCullNoPreRotation\": \"true\", \"FFlagFastGPULightCulling\": \"true\", \"FFlagFastGPULightCulling2\": \"true\", \"FFlagFastGPULightCulling3\": \"true\", \"FFlagFastGPULightCulling4\": \"true\", \"FFlagRenderCacheLocalLightCameras\": \"true\", \"FFlagRenderTC2_FixBakeCacheContent\": \"true\", \"FFlagDontCreatePingJob\": \"true\", \"DFFlagQueueDataPingFromSendData\": \"true\", \"FFlagAnimationClipMemCacheEnabled\": \"true\", \"FFlagRenderGetLastLODErrorFix\": \"true\", \"FFlagRenderAlternativeShadowLod\": \"true\", \"DFFlagUseSIMDCulling\": \"true\",  \"DFFlagExtentsUseSIMDFunctions\": \"true\", \"FFlagVoxelizerMeshPerExtentsScale\": \"true\", \"FFlagOptimizeSkeletonGetBoneIndexByPart\": \"true\", \"FFlagOptimizeFCMeshGeneratorReplaceParentIndices\": \"true\", \"FFlagOptimizeFCMeshGeneratorTransformSource\": \"true\", \"DFFlagAnimatorLodOptOutPhase\": \"true\", \"DFFlagRenderCompositorExperimentEnabled\": \"true\", \"DFIntRenderCompositorExperimentPercent\": \"10000\", \"FFlagRenderHalfresShadowsGlsles\": \"true\", \"FFlagRenderShadowUseLastLOD\": \"true\", \"FFlagBatchGfxGui2\": \"true\", \"FFlagBillboardGuiDistanceStepping2\": \"true\", \"DFFlagReduceTrussSearchDistance2\": \"true\", \"FFlagHttpMinUseGzip\": \"true\", \"DFFlagPlayerConfigurer2866\": \"true\", \"FFlagPlayerConfigurer2759\": \"true\", \"DFFlagPlayerConfigurerRunLMSTest\": \"true\", \"FIntLmsClientRollout2\": \"10000\", \"DFFlagSimOptimizeInterpolationReturnPreviousIfSmallMovement2\": \"true\", \"DFFlagSimIfNoInterp2\": \"true\", \"FFlagForceFSMCPULightCulling\": \"true\", \"FFlagThrottleLightGridUpdate3\": \"true\"}";

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(60000));
        if (state == 'y') {
            system((rootDir + "\\curl.exe -X GET -o \"" + rootDir + "\\rbx.version\" --silent http://setup.roblox.com/version").c_str()); //libcurl didn't want to work because visual studio 2022 is fucking STUPID, this janky solution will have to do... (I could just set this project up in 2019 but I am way too lazy bro)
            struct stat info;
            if (stat((robloxRootDir).c_str(), &info) != 0) {
                clear();
                std::cout << "Roblox is not installed on this computer... | Close this, install Roblox, and then re-run!";
                std::cin.get();
                return;
            }
            
            std::ifstream file(rootDir + "\\rbx.version");
            if (file.is_open()) {
                file.seekg(0, std::ios::end);
                size_t size = file.tellg();
                verString = std::string(size, ' ');
                file.seekg(0);
                file.read(&verString[0], size);

                file.close();
            }
            struct stat info2;
            if (stat((robloxRootDir + "\\" + verString).c_str(), &info2) == 0) {
                if (stat((robloxRootDir + "\\" + verString + "\\ClientSettings").c_str(), &info2) != 0) {
                    _mkdir((robloxRootDir + "\\" + verString + "\\ClientSettings").c_str());
                }
                char useInternet = NULL;
                std::ifstream file(rootDir + "\\settings.lgbt");
                if (file.is_open()) {
                    std::string line;
                    while (std::getline(file, line)) {
                        if (line.find("internet:") == 0) {
                            useInternet = line[line.length() - 1];
                        }
                    }
                    if (useInternet == NULL) {
                        std::ofstream settings;
                        settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
                        settings << "internet:y\n";
                        useInternet = 'y';
                        settings.close();
                    }
                    file.close();
                }
                //system((rootDir + "\\curl.exe -X GET -o \"" + rootDir + "\\flag-version.rco\" -k --silent https://raw.githubusercontent.com/l8x/roblox-client-optimizer/main/flag-version.rco").c_str());
                if (!(fileExists((robloxRootDir + "\\" + verString + "\\ClientSettings" + "\\ClientAppSettings.json").c_str()))) {
                    std::ofstream cap((robloxRootDir + "\\" + verString + "\\ClientSettings" + "\\ClientAppSettings.json").c_str());
                    if (useInternet == 'n')
                        cap << offlineFflags;
                    else {
                        system((rootDir + "\\curl.exe -X GET -o \"" + rootDir + "\\rbx.flags\" -k --silent https://raw.githubusercontent.com/l8x/roblox-client-optimizer/main/ClientAppSettings.json").c_str());
                        std::ifstream file(rootDir + "\\rbx.flags");
                        if (file.is_open()) {
                            file.seekg(0, std::ios::end);
                            size_t size = file.tellg();
                            fflagListStr = std::string(size, ' ');
                            file.seekg(0);
                            file.read(&fflagListStr[0], size);

                            file.close();
                        }
                        cap << fflagListStr;
                    }
                    
                    cap.close();
                }
            }
        }
    }
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    std::thread t1(traySystem);

    rootDir = std::string("C:\\RClientOptimizer");

    if (!(_dupenv_s(&buf, &sz, "localappdata") == 0 && buf != nullptr))
    {
        std::cout << "Error finding LocalAppData folder (NOTE: THIS PROGRAM ONLY WORKS ON WINDOWS) | 0x2\n";
        std::cin.get();
        return 2;
    }

    robloxRootDir = buf + std::string("\\Roblox\\Versions");

    free(buf);

    struct stat info;
    if (stat(rootDir.c_str(), &info) != 0) {
        if (_mkdir(rootDir.c_str()) != 0) {
            std::cout << "Failed to create directory: " + rootDir + "\nError 0x3: Try running again with Administrator privileges\n\nPress enter to close the program.\n";
            std::cin.get();
            return 3;
        }
    }

    if (!(fileExists(rootDir + "\\settings.lgbt"))) {
        std::ofstream settings(rootDir + "\\settings.lgbt");
        settings << "consoleHidden:n\n";
        std::cout << "This appears to be your first time running the Roblox Client Optimizer, lets do some setup!\n\nWould you like RCO to launch on Windows startup? (Recommended as it will keep RCO and the fflag list up to date!)\n";
        std::string input;
        while (input != "Y" && input != "y" && input != "N" && input != "n") {
            std::cout << "(Y/N) | ";
            std::cin >> input;
        }
        if (input == "y" || input == "Y") {
            settings << "autorun:y\n";
            std::wstring progPath = L"C:\\Program Files\\RCO\\RCO.exe";
            HKEY hkey = NULL;
            LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);    
            LONG status = RegSetValueEx(hkey, L"RCO", 0, REG_SZ, (BYTE*)progPath.c_str(), (progPath.size() + 1) * sizeof(wchar_t));
            RegCloseKey(hkey);
        }
        else if (input == "n" || input == "N") {
            settings << "autorun:n\n";
            HKEY hkey = NULL;
            RegOpenKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
            RegDeleteValue(hkey, L"RCO");
            RegCloseKey(hkey);
        }

        input = "";
        std::cout << "Would you like RCO to be allowed to automatically update it's fflag list? (List will always be on the github | Offline list is unmaintained.)\n";
        while (input != "Y" && input != "y" && input != "N" && input != "n") {
            std::cout << "(Y/N) | ";
            std::cin >> input;
        }
        if (input == "y" || input == "Y")
            settings << "internet:y\n";
        else if (input == "n" || input == "N")
            settings << "internet:n\n";
        settings << "enabled:n\n";
        settings.close();
    }
    char conState = NULL;
    std::ifstream file(rootDir + "\\settings.lgbt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("enabled:") == 0) {
                state = line[line.length()-1];
            }
            if (line.find("consoleHidden:") == 0) {
                conState = line[line.length() - 1];
            }
        }
        if (state == NULL) {
            std::ofstream settings;
            settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
            settings << "enabled:n\n";
            settings.close();
        }
        if (conState == NULL) {
            std::ofstream settings;
            settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
            settings << "consoleHidden:n\n";
            settings.close();
        }
        file.close();
    }

    if (conState == 'y')
        isConsoleHidden = true;
    else
        isConsoleHidden = false;

    if (isConsoleHidden) {
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
    else {
        ShowWindow(GetConsoleWindow(), SW_SHOW);
    }

    std::thread t2(fflagUpdater);

    std::string onState;
    std::string notOnState;
    while (true) {
        clear();
        if (state == 'y') {
            onState = "Enabled";
            notOnState = "Disable";
        }
        else {
            onState = "Disabled";
            notOnState = "Enable";
        }

        std::cout << "Roblox Client Optimizer recoded in C++ by Kaid#0001\nfflag list and originally made by nul#3174\n\nThe script is currently: ";
        if (state == 'y') {
            SetConsoleTextAttribute(hConsole, 10);
        }
        else {
            SetConsoleTextAttribute(hConsole, 12);
        }
        std::cout << onState;
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "\n";

        std::string input;
        while (input != "Y" && input != "y" && input != "N" && input != "n") {
            std::cout << "Would you like to " + notOnState + " the script? (Y) [N to reconfigure settings] | ";
            std::cin >> input;
        }
        if (input == "y" || input == "Y") {
            std::ifstream file(rootDir + "\\settings.lgbt");
            std::string newStr = "";
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    if (!(line.find("enabled:") == 0)) {
                        newStr += line + "\n";
                    }
                }
                std::ofstream settings;
                settings.open(rootDir + "\\settings.lgbt");
                settings << newStr;
                settings.close();

                if (state == 'y') {
                    std::ofstream settings;
                    settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
                    settings << "enabled:n\n";
                    state = 'n';
                    settings.close();
                }
                else if (state == 'n') {
                    std::ofstream settings;
                    settings.open(rootDir + "\\settings.lgbt", std::ios_base::app);
                    settings << "enabled:y\n";
                    state = 'y';
                    settings.close();
                }
                
                if (verString != "") {
                    struct stat info2;
                    struct stat info3;
                    if (stat((robloxRootDir + "\\" + verString).c_str(), &info2) == 0) {
                        if (stat((robloxRootDir + "\\" + verString + "\\ClientSettings").c_str(), &info3) == 0) {
                            if (fileExists((robloxRootDir + "\\" + verString + "\\ClientSettings" + "\\ClientAppSettings.json").c_str())) {
                                std::filesystem::remove(robloxRootDir + "\\" + verString + "\\ClientSettings" + "\\ClientAppSettings.json");
                            }
                        }
                    }
                }
                file.close();
            }
        }else {
            clear();
            std::filesystem::remove(rootDir + "\\settings.lgbt");
            if (!(fileExists(rootDir + "\\settings.lgbt"))) {
                std::ofstream settings(rootDir + "\\settings.lgbt");
                settings << "consoleHidden:n\n";
                std::cout << "RCO Settings <3\n\nWould you like RCO to launch on Windows startup? (Recommended as it will keep RCO and the fflag list up to date!)\n";
                std::string input;
                while (input != "Y" && input != "y" && input != "N" && input != "n") {
                    std::cout << "(Y/N) | ";
                    std::cin >> input;
                }
                if (input == "y" || input == "Y") {
                    settings << "autorun:y\n";
                    std::wstring progPath = L"C:\\Program Files\\RCO\\RCO.exe";
                    HKEY hkey = NULL;
                    LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
                    LONG status = RegSetValueEx(hkey, L"RCO", 0, REG_SZ, (BYTE*)progPath.c_str(), (progPath.size() + 1) * sizeof(wchar_t));
                    RegCloseKey(hkey);
                }
                else if (input == "n" || input == "N") {
                    settings << "autorun:n\n";
                    HKEY hkey = NULL;
                    RegOpenKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
                    RegDeleteValue(hkey, L"RCO");
                    RegCloseKey(hkey);
                }

                input = "";
                std::cout << "Would you like RCO to be allowed to automatically update it's fflag list? (List will always be on the github | Offline list is unmaintained.)\n";
                while (input != "Y" && input != "y" && input != "N" && input != "n") {
                    std::cout << "(Y/N) | ";
                    std::cin >> input;
                }
                if (input == "y" || input == "Y")
                    settings << "internet:y\n";
                else if (input == "n" || input == "N")
                    settings << "internet:n\n";
                settings << "enabled:n\n";
                state = 'n';
                settings.close();
            }
        }
    }
    return 0;
}
