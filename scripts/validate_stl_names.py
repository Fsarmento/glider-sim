#!/usr/bin/env python3
"""
Simple check to enforce STL filename conventions for this repo:
- filenames and directory names under `stl/` must be lowercase
- no spaces allowed
- allowed characters: lowercase letters, digits, hyphen (-), underscore (_), dot (for extension)

Exit status: 0 if all good, 1 if violations are found.
"""
import os
import re
import sys

ROOT = "stl"
PATTERN = re.compile(r"^[a-z0-9._-]+$")

if not os.path.isdir(ROOT):
    print("No 'stl' directory found — skipping STL filename check.")
    sys.exit(0)

violations = []
for dirpath, dirnames, filenames in os.walk(ROOT):
    # check directory names in this path
    for d in dirnames:
        if not PATTERN.match(d):
            violations.append(os.path.join(dirpath, d))
    # check file names
    for f in filenames:
        if not PATTERN.match(f):
            violations.append(os.path.join(dirpath, f))

if violations:
    print("ERROR: Found files or directories violating naming convention (must be lowercase, no spaces, use '-' or '_' for separators):")
    for v in violations:
        print(" -", v)
    print("\nFix by renaming files/directories (e.g., 'stick front plate.STL' -> 'stick-front-plate.stl').")
    sys.exit(1)

print("✅ STL filename check passed — all names follow conventions.")
sys.exit(0)
