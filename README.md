# Roblox-Client-Optimizer

RCO automatically tweaks FFlags to optimize your Roblox client.
The flags we edit are contained in our [GitHub Repository](https://github.com/L8X/Roblox-Client-Optimizer/blob/main/ClientAppSettings.json).

Why don't you give it a try?

[Click here to download RCO!](https://roblox-client-optimizer.simulhost.com/download)

# RCO's most popular features:

- Unlocks FPS (For most people)
- Optimizes Caching
- Optimizes Graphics
- Optimizes Textures
- Increases user privacy
- Disables Crashpad / Backtrace crash metrics
- Disables a large portion of client telemetry
- Disables AbuseReportScreenshot
- Enables font and texture item preloading
- Enables memory prioritization and performance control
- Enables FULL graphics quality options (21 instead of 10!)
- Enables QuickGameLaunch
- Enables ParallelHumanoidManager
- Enables BatchAssetApi

# Why use RCO and not manually install flags?
1. Manually installing our flag file is time consuming, as when Roblox updates, you must remember to reinstall the flag file manually all over again, RCO will handle the installation automatically.
2. If a major bug is found within the flag file, we have no way of notifying you to update it, therefore we implemented an automatic update process to fix this issue.

# Will RCO slow down my PC?
No, RCO is very light-weight and only checks for updates to our flag file and for updates to itself, additionally, we use a CDN powered by Cloudflare and Fastly to optimize the bandwidth usage and file size of any flag file or RCO related downloads the program makes.

# Does RCO collect/store user data?
1. No, RCO itself does not collect ANY data, telemetry or analytics from our users, the only possible data transferred due to your use of RCO is the IP address of your device which is obviously required to connect to the internet and therefore update RCO and it's flag file, however our CDN providers have an agreement with us called a Data Processing Addendum, which restricts them from using your data (which is just your IP address) outside of delivering the files to you that RCO requests.
2. RCO does not collect any personally identifiable information whatsoever, nor do our CDN providers.

# GDPR / CCPA / COPPA Disclosure
We are NOT a data handler or processor, for any queries relating to data transmitted via the network traffic of RCO (keep in mind your IP address is disclosed to every website you visit), please contact Cloudflare, Fastly and Microsoft directly.

# What about Byfron?
RCO remains operational regardless of Roblox's new anticheat measures (known as Hyperion / Byfron) as we do not inject a DLL nor do we modify live client memory.

# Will I get banned for using this?
No, RCO's operations are fully compliant with the Roblox Terms of Service, as we use a method that Roblox themselves intentionally added to the client to modify flags.

# Issues? 
1. RCO itself *ONLY* works on Windows, though it should also work on custom Windows mods. (Only tested on 10) (Semi support for 11)
2. For Linux support, use https://github.com/vinegarhq/vinegar
3. For Mac support, use https://github.com/L8X/Roblox-Client-Optimizer-Mac
4. If your antivirus detected any of our files as malware, read: https://github.com/L8X/Roblox-Client-Optimizer/issues/40

# Disclaimer
Posting time wasting issues and pull requests may result in your account being blocked from the repository. 
Please ensure all contributions are meaningful and correct.
