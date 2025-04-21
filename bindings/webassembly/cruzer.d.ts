declare module "@octue/version-cruzer" {
  export type VersionChangeType = "major" | "minor" | "patch" | null;

  export type CompatibilityType =
    | "compatible"
    | "incompatible"
    | "skip"
    | "unknown";

  export interface Trace {
    compatibility: CompatibilityType;
    left: string | null;
    right: string | null;
  }

  export interface VersionResult {
    version: VersionChangeType;
    traces: Trace[];
  }

  /**
   * Compare two version structures and determine the type of version change.
   *
   * @param from - The original version object or JSON string.
   * @param to - The target version object or JSON string.
   * @returns A promise that resolves to the version comparison result.
   */
  export function version(
    from: string | object,
    to: string | object
  ): Promise<VersionResult>;
}
