import fs, { existsSync } from "fs-extra";
import path from "path";
import process from "process";
import { Oof } from "./Oof";

/** Handles finding Roblox & whatnot */
export class Roblox {
  /** Roblox Path Getters */
  static RobloxPathGetters: Partial<Record<typeof process.platform, () => (string)>> = {
    darwin: () => process.env.ROBLOX ?? '/Applications/Roblox.app',
    win32: () => {
      const possible = [
        process.env.ROBLOX,
        path.resolve(process.env.LOCALAPPDATA ?? '', 'Roblox'),
        'C:/Program Files (x86)/Roblox',
        path.resolve(process.env.APPDATA ?? '', 'Roblox'),
      ].filter(v => v && existsSync(v) && existsSync(v + '/Versions')) as string[];
      if (possible.length > 1 && !process.env.ROBLOX && !process.env.IGNORE_MULTIPLE_ROBLOX_INSTALLATIONS)
        throw new Error(`Found multiple Roblox installations! Please remove all but one, pass the ROBLOX Environment Variable to set exactly 1 Roblox installation, or IGNORE_MULTIPLE_ROBLOX_INSTALLATIONS to ignore this error.
Installations: ${possible.join(', ')}`)
      if (possible[0])
        return possible[0]
      throw new Error(`Cannot find Roblox! Please symlink ${path.resolve(process.env.LOCALAPPDATA ?? 'C:/Program Files (x86)', 'Roblox', 'Versions')} to your Roblox's Versions Folder!`)
    },
    linux: () => {
      const possible = [
        process.env.ROBLOX, ...([
          '/',
          process.env.HOME,
          process.env.LOCALAPPDATA,
          process.env.APPDATA,
        ].filter(v => v).map(v => path.resolve(v ?? '', 'Roblox')))].filter(v => v && existsSync(v) && existsSync(path.resolve(v, 'Versions'))) as string[];
      if (possible.length > 1 && !process.env.ROBLOX && !process.env.IGNORE_MULTIPLE_ROBLOX_INSTALLATIONS)
        throw new Error(`Found multiple Roblox installations! Please remove all but one, pass the ROBLOX Environment Variable to set exactly 1 Roblox installation, or IGNORE_MULTIPLE_ROBLOX_INSTALLATIONS to ignore this error.
Installations: ${possible.join(', ')}`)
      if (possible[0])
        return possible[0]
      throw new Error(`Cannot find Roblox! Please symlink ${path.resolve(process.env.ROBLOX ?? '/Roblox', 'Versions')} to your Roblox's Versions Folder or set the ROBLOX env variable to the directory containing your Roblox's Versions directory!`)
    }
  }
  /** Gets the Roblox Path for the current autodetected platform */
  static GetRobloxPath = this.RobloxPathGetters[process.platform]
  /**
   * Gets the Roblox Version from the path
   * @param {string} p The path to get the version from
   * @note On MacOS, this will always return `Contents`, as there is no version directory system on MacOS
   */
  static GetRobloxVersionFromPath(p: string) {
    if (process.platform === 'darwin')
      return 'Contents'
    if (!p)
      throw new Error('No Path Specified')
    if (!existsSync(p))
      throw new Error('Path does not exist')
    p = path.resolve(p)
    const versionsDir = p.endsWith('Versions') ? p : path.join(p, 'Versions')
    if (!existsSync(versionsDir))
      throw new Error('Versions directory does not exist')
    const versions = fs.readdirSync(versionsDir)
    if (!versions.length)
      throw new Error('Versions directory is empty')
    const version = versions.find(v => fs.existsSync(path.join(versionsDir, v, 'RobloxPlayerBeta.exe')))
    if (!version)
      throw new Error('No RobloxPlayerBeta.exe found in Versions directory')
    return version
  }
  /**
   * {@link GetRobloxVersionFromPath} but returns the absolute dir path
   */
  static GetRobloxVersionDirFromPath(p: string) {
    return path.resolve(p, process.platform === 'darwin' ? '.' : 'Versions', this.GetRobloxVersionFromPath(p))
  }
  /** Gets Client Settings Path from a version folder */
  static getClientSettings(versionDir: string) {
    switch (process.platform) {
      case 'darwin':
        return path.join(versionDir, 'MacOS', 'ClientSettings', 'ClientAppSettings.json')
      case 'win32':
      case 'linux':
        return path.join(versionDir, 'ClientSettings', 'ClientAppSettings.json')
    }
    if (!process.env.ROBLOXCAS)
      throw new Error('Unsupported Platform - Please pass the environment variable ROBLOXCAS to specify the path to Roblox ClientAppSettings.json relative to ' + versionDir)
    else
      return path.resolve(versionDir, process.env.ROBLOXCAS)
  }
  /** The path to Roblox('s Versions Folder) */
  robloxPath: string = '';
  /** Return value of {@link Roblox.getClientSettings GCS} for this Roblox Instance */
  get ClientAppSettings() {
    return Roblox.getClientSettings(this.robloxPath)
  }
  /** oof path for this client */
  get Oof() {
    return path.resolve(this.robloxPath, Oof.oofPath)
  }
  /** Sets the flags to a JSON object */
  setFlags(flags: Record<string, any>) {
    fs.ensureFileSync(this.ClientAppSettings)
    fs.writeFileSync(this.ClientAppSettings, JSON.stringify(flags))
  }
  /**
   * @param robloxPath The path to Roblox's Versions Folder
   */
  init(robloxPath?: string) {
    if (!robloxPath) {
      const rbx = (Roblox.GetRobloxPath ?? (() => { throw new Error('Must specify Roblox Path or be on supported platform!') }))()
      robloxPath = Roblox.GetRobloxVersionDirFromPath(rbx)
    }
    this.robloxPath = robloxPath
  }
  /**
   * @param robloxPath The path to Roblox's Versions Folder
   */
  constructor(robloxPath?: string) {
    this.init(robloxPath)
  }
}