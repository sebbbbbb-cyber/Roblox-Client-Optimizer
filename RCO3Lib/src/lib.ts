import { Defaultable } from "./Defaultable";
import RCO3Flags from "./Flags";
import { Oof } from './Oof'
import { Roblox } from "./Roblox";

export class RCO3 {
  /** Defaultable */
  static Defaultable = Defaultable;
  /** Flag Fetching & whatnot */
  static Flags = RCO3Flags;
  /** Oof SFX */
  static Oof = Oof;
  /** Roblox Instance - Just create one & pass it around - Contains all known Roblox installations */
  static Roblox = Roblox;
}
