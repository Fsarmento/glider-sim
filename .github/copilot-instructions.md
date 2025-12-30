# Copilot instructions for contributors 🤖

**Purpose:** Help AI coding agents quickly become productive in this repository by surfacing the project's intent, layout, current conventions, and PR expectations.

---

## Quick context & where to start ✅
- Read: `README.md` (project purpose, BOM, Condor 3 compatibility) and `LICENSE.md` (Creative Commons BY-NC-SA 4.0).
- Primary assets: `stl/` (3D parts: `joystick/`, `Rudder/`, `Sliders/`, etc.) and `photos/` (visual verification, banner and build photos).

## Big picture (what this repo *is*) 🔧
- This is a **hardware-first glider cockpit project**: 3D-printable parts (STL), BOM, photos and assembly notes.
- The README mentions a controller using an **ESP32-C3 Supermini** (no firmware source is present in the repo at time of writing).

## Repo layout (key files/folders) 📂
- `README.md` — BOM, project description, target simulator (Condor 3).
- `LICENSE.md` — CC BY-NC-SA 4.0 (non-commercial, share-alike requirements).
- `stl/` — grouped subfolders for each assembly (e.g., `joystick/`, `rudder/`, `controller-box/`).
- `photos/` — images used on the README and for PR visual verification.
- `.github/` — currently only `FUNDING.yml`; add this file here if you need to update agent guidance.

## What I discovered (explicit facts) 📋
- No source firmware or platform config files found (no `platformio.ini`, `.ino`, `main.cpp`, or `CMakeLists.txt`).
- STLs are the canonical deliverables; filenames should be **lowercase**, **no spaces**, and **hyphen-separated** (e.g., `stick-front-plate.stl`, `trim-wheel.stl`).
- BOM references `ESP32-C3 Supermini` (controller); Condor 3 is the target simulator.

## Conventions & guidance for agents (actionable) ⚙️
- When making changes to STLs or assemblies:
  - Update the relevant `stl/<component>/` files and add a short note in `README.md` (or `stl/<component>/README.md`) describing the change and, if applicable, the CAD source or origin.
  - Add photos to `photos/` that demonstrate the physical fit and orientation (small, clear set of images for PRs).
- Filename hygiene: currently inconsistent — prefer **lowercase**, **no spaces**, and **use `-` or `_`** for separation (e.g., `stick-front-plate.stl`), and include a short version suffix if needed (`v1`, `v2`).
- Licensing: Any added files must be compatible with **CC BY-NC-SA 4.0**; add attribution and keep the same license for derivatives.

## If you add firmware or software 🧩
- Put it under a new top-level folder (suggested: `firmware/` or `controller/`) and include a short `README.md` detailing:
  - target board (`ESP32-C3 Supermini`), build system (PlatformIO/ESP-IDF/etc.), and minimal flash/test steps.
  - wiring or pin mapping between STLs (joystick pot/hall sensors) and the controller.
- Include a `platformio.ini` or `CMakeLists.txt` and a reproducible script/command to build & flash.
- Document how the controller integrates with Condor 3 (e.g., USB/HID or serial bridge) — if unknown, add a TODO and attach any test logs or traces.

## PR checklist for contributors ✍️
- Update `README.md` or the BOM table if parts/quantities change.
- Include photos for any physical change (new part, dimension change, test fit).
- Add a short changelog entry in the PR description and reference the affected `stl/` path.
- Confirm license compatibility and add attribution where required.

## Tests / CI / automation notes ⚠️
- There are no CI workflows or tests present. For automation, consider simple checks:
  - filename sanitizer (no spaces),
  - presence of `stl/<component>/README.md` when a new STL is added,
  - basic firmware build matrix if firmware is added.

## Helpful examples from the repo 🔍
- `stl/joystick/joystick-gimbal-base.stl` — typical multi-part gimbal naming.
- `stl/controller-box/controller-box-top.stl` — enclosure artifact that should be paired with wiring docs if controller code is added.
- `README.md` BOM entry: `Controller ESP32-C3` — explicitly lists the expected microcontroller.

---

If anything above is unclear or you'd like templates added (firmware template, CI workflow, or filename linter), tell me which and I will iterate. 🙋‍♂️