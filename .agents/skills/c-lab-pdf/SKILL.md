---
name: c-lab-pdf
description: Guides compiling C lab assignments, capturing monochrome terminal outputs, and generating formatted PDF reports following student submission standards.
---

# C Lab Assignment & PDF Report Generation Skill

Use this skill whenever asked to create, update, or verify PDF reports for C lab assignments in this repository (e.g., LAB1 to LAB8).

## 1. Prerequisites & Dependencies
Python 3 with the following libraries:
- `reportlab`
- `pillow`
- `pygments`

If missing, install via:
```bash
py -3.13 -m pip install reportlab pillow pygments
```

## 2. Report Specifications

### File Naming
- Saved as `LAB<N> - Md Mobid - 2505031.pdf` directly inside the lab folder (e.g. `d:\DS\LAB3\LAB3 - Md Mobid - 2505031.pdf`).

### Question Layout
- Each question **MUST start on a new page** (`PageBreak()`).
- The question description/prompt is rendered at the top of the question in standard Helvetica 11pt font.

### Source Code Section
- Heading: `<u><b>Source Code:</b></u>`
- Code must be **selectable, copy-pasteable text** rendered inside a ReportLab `Table` with `#1E1E1E` dark background.
- Syntax highlighting uses Pygments `CLexer` tokens converted into ReportLab XML font tags (keywords `#569CD6`, types `#569CD6`, functions `#DCDCAA`, strings `#CE9178`, comments `#6A9955`, numbers `#B5CEA8`).
- **Initial Question Comments Stripped**: The top single-line `// WAP...` or multi-line `/* ... */` comment blocks in the C file must be stripped from the source code display so the code begins directly with `#include <stdio.h>`.

### Output Section & Screenshots
- Heading: `<u><b>Output:</b></u>`
- Output screenshots must be **monochrome** (plain white text `#CCCCCC` on `#191919` dark background) using Consolas font (15pt).
- **Exact Code Output Matching**: Never fabricate outputs or add arrows `->` unless printed by `printf`. Terminal output must strictly mirror actual execution.
- **`KeepTogether` Protection**: The `Output:` heading and the output image flowable MUST be wrapped together using ReportLab `KeepTogether([out_heading, out_spacer, out_img])` so the heading is never stranded at the bottom of a previous page without its screenshot.
- If an output screenshot is taller than the page printable height (~670pt), slice it into multiple image chunks.

## 3. Workflow Steps
1. Verify and compile all `.c` programs in the target LAB folder (`gcc -Wall <file>.c -o <file>.exe`).
2. Run test execution with representative inputs and capture terminal stdout.
3. Generate monochrome terminal screenshot PNGs in an `outputs/` subdirectory.
4. Execute the Python generator script to build the PDF document.
5. Verify the generated PDF using `view_file` to ensure proper layout, formatting, and pagination.
