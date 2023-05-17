import { HTTP } from "@rco3/ttyutil";
import { Roblox } from "./Roblox";
import path from "path";
import { copyFileSync } from "fs-extra";

/** Handles oofs */
export class Oof {
  /**
   * oof url
   */
  static oofURL = 'https://roblox-client-optimizer.simulhost.com/ouch.ogg';
  /**
   * Downloads the oof to a specific file
   */
  static downloadOof(file: string): Promise<void> {
    return HTTP.Download(this.oofURL, file)
  }
  /**
   * Oof path within the roblox installation
   */
  static oofPath = 'content/sounds/ouch.ogg';
  /**
   * Download the oof to a Roblox Installation
   */
  static async Install(roblox: Roblox): Promise<void> {
    let firstOof: string | undefined = undefined;
    for (const oofPath of roblox.Oof) {
      if (!firstOof) {
        firstOof = oofPath
        await Oof.downloadOof(oofPath)
      }
      else copyFileSync(firstOof, oofPath)
    }
  }
}
